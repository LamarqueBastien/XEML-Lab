#include "oboreader.h"

#include "simpleoboterm.h"
#include "itfontologyhandler.h"
#include "itfontologyterm.h"

namespace Mpi {

	namespace Common{

		OboReader::OboReader()
		{
			this->currentStanza=NULL;
			regexStanza=new QRegExp("\\[\\w+\\]");
			regexTerm=new QRegExp("^\\[Term\\]");
			regexTypedef=new QRegExp("\\[Typedef\\]");
			regexTagValPair=new QRegExp(".+:.+");
			(*this->stanzaToString)["Term"]=Mpi::Common::Term;
			(*this->stanzaToString)["Typedef"]= Mpi::Common::TypeDef;
			(*this->stanzaToString)["Unknown"]=Mpi::Common::Unknown;

		}

		OboReader::OboReader(XemlContracts::ItfOntologyHandler * _handler){
			this->handler=_handler;
			this->currentStanza=NULL;
			this->stanzaToString=new std::map<QString,StanzaType>();
			regexStanza=new QRegExp("\\[\\w+\\]");
			regexTerm=new QRegExp("^\\[Term\\]");
			regexTypedef=new QRegExp("\\[Typedef\\]");
			regexTagValPair=new QRegExp(".+:.+");
			if(_handler->get_ontologyType()==Xeml::Document::Contracts::Developmental){
				(*this->stanzaToString)["Term"]=Mpi::Common::Term;
				(*this->stanzaToString)["Typedef"]= Mpi::Common::TypeDef;
				(*this->stanzaToString)["Unknown"]=Mpi::Common::Unknown;
			}
			if(_handler->get_ontologyType()==Xeml::Document::Contracts::OrganismStructure){
				(*this->stanzaToString)["Term"]=Mpi::Common::Term;
				(*this->stanzaToString)["Typedef"]= Mpi::Common::TypeDef;
				(*this->stanzaToString)["Unknown"]=Mpi::Common::Unknown;
			}

		}
		OboReader::~OboReader(void){
			std::cerr << "delete oboreader" << std::endl;
			if(this->currentStanza!=NULL){
				delete this->currentStanza;
			}
		}

		void OboReader::process_line(const QString &)
		{

		}
		void OboReader::read(QString filename,std::map<QString,XemlContracts::ItfOntologyTerm*>* _terms){
			std::list<QString> *filter =NULL;
			QFile file(filename);
			if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
				return;
			int lineNumber = 0;
			bool firstStanzaFound = false;
			QTextStream in(&file);
			QString line = in.readLine();
			while (!line.isNull()) {
				lineNumber++;
				process_line(line);
				line = in.readLine();

				if(checkForNewStanza(line,lineNumber,_terms)){
					firstStanzaFound=true;
				}
				else
				{
					if(firstStanzaFound){
						checkForTagValuePair(filter,lineNumber,line,_terms);
					}
					else{
						checkForTagValuePair(NULL,lineNumber,line,_terms);
					}
				}
			}
		}
		bool OboReader::checkForNewStanza(QString _line,int _lineNumber,std::map<QString,XemlContracts::ItfOntologyTerm*>* _terms){
			if(this->regexStanza->exactMatch(_line))
			{
				QString name;
				QString stanzaType = "Unknown";
				if(this->regexTerm->exactMatch(_line)){
					stanzaType=_line.remove(0,1);
					stanzaType=stanzaType.remove(_line.size()-1,1);
					name=stanzaType;
				}
				if(this->regexTypedef->exactMatch(_line)){
					stanzaType=_line.remove(0,1);
					stanzaType=stanzaType.remove(_line.size()-1,1);
					name=stanzaType;
				}
				OnNewStanza(stanzaType, name, _lineNumber,_terms);
				return true;
			}
			else{
				return false;
			}
		}
		bool OboReader::checkForTagValuePair(std::list<QString> *filter,int _lineNumber, QString _line,std::map<QString,XemlContracts::ItfOntologyTerm*>* _terms)
		{
			if(this->regexTagValPair->exactMatch(_line)){
				QStringList list = _line.split(": ");
				QString str1 = list.at(0);
				QString str2 = list.at(1);
				OnNewTagValuePair(str1, str2, _lineNumber,_terms);
				return true;

			}
			else{
				return false;
			}
		}

		StanzaType OboReader::get_stanzaType(){
			return this->stanzaType;
		}

		void OboReader::set_stanzaType(StanzaType _stanzaType){
			this->stanzaType=_stanzaType;
		}
		void OboReader::OnNewStanza(QString _stanzaType, QString _name, int _lineNumber,std::map<QString,XemlContracts::ItfOntologyTerm*>* _terms){
			this->currentStanza=NULL;
			StanzaType st=get_stanza_from_string(_stanzaType);
			if(this->currentStanza!=NULL){
				std::cerr << "current stanza not null" << std::endl;

			}
			else if(st==Mpi::Common::Term){
				this->currentStanza=new XemlOntologies::SimpleOboTerm("");
				this->currentStanza->set_nameSpaceAlias(this->handler->get_namespaceAlias());
				this->currentStanza->set_nameSpace(this->handler->get_namespace());
			}
			else{
				this->currentStanza=NULL;
			}

		}

		void OboReader::OnNewTagValuePair(QString _attribute, QString _attributeValue, int _lineNumber,std::map<QString,XemlContracts::ItfOntologyTerm*>* _terms){
			if(_attribute=="default-namespace"){
				this->handler->set_namespace(_attributeValue);
			}
			else if(this->currentStanza!=NULL){
				if(_attribute=="id")
				{
					this->currentStanza->set_termId(_attributeValue);

				}
				else if(_attribute=="name")
				{
					this->currentStanza->set_name(_attributeValue);

				}
				else if(_attribute=="def")
				{
					this->currentStanza->set_definition(_attributeValue);

				}
				else if(_attribute=="namespace")
				{
					this->currentStanza->set_nameSpace(_attributeValue);

				}
				else
				{
					this->currentStanza->get_oboTagValuePair()->push_back(make_pair(_attribute,_attributeValue));
					this->currentStanza->add_termAttribute(new TermAttribute(_attribute,_attributeValue));

				}
				(*_terms)[this->currentStanza->get_termId()]=this->currentStanza;
			}
		}
		StanzaType OboReader::get_stanza_from_string(QString stanzaString){
			for(std::map<QString,StanzaType>::iterator it=this->stanzaToString->begin(); it!=this->stanzaToString->end();++it){
				if(it->first==stanzaString){
					return it->second;
				}
			}

		}

	}
}

