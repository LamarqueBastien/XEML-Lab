#include "developmentalontologyhandler.h"
namespace Xeml {

	namespace Document{



		DevelopmentalOntologyHandler::DevelopmentalOntologyHandler()
		{
			Nodes=new list<TermNode*>();
			URI=QString("http://www.plantontology.org/DevelopmentalStage");
			/*
#if defined(Q_OS_WIN)
									   this->FileLocationPrefix=QString("C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEML/PO_Development.obo");
#elif defined(Q_OS_MACX)
									   this->FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/PO_Development.obo");
#else
									   this->FileLocationPrefix=QString("/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEML/PO_Development.obo");
#endif
*/
			//this->FileLocationPrefix=QString("C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEML/PO_Development.obo");

            //FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/PO_Development.obo");
			this->FileLocationPrefix=QString("://XEML/PO_Development.obo");
		}
		DevelopmentalOntologyHandler::~DevelopmentalOntologyHandler(void){

		}

		std::map<QString,ItfOntologyTerm*>      DevelopmentalOntologyHandler::get_terms(){
			return this->terms;
		}

		bool                                    DevelopmentalOntologyHandler::contain(BasicTerm param){
			std::map<QString,ItfOntologyTerm*>::const_iterator trouve=this->terms.find(param.get_termId());

			if (trouve==this->terms.end()){
				return false;
			}
			else{
				return true;
			}


		}

		ItfOntologyTerm                       * DevelopmentalOntologyHandler::findKey(BasicTerm param){

			for(std::map<QString,ItfOntologyTerm*>::iterator it=this->terms.begin();it!=this->terms.end();it++){

				if(it->first==param.get_termId()){
					return it->second;
				}

			}
			return NULL;
		}

		ItfOntologyTerm                       * DevelopmentalOntologyHandler::findKey(QString termId){
			for(std::map<QString,ItfOntologyTerm*>::iterator it=this->terms.begin();it!=this->terms.end();it++){

				if(it->first==termId){
					return it->second;
				}

			}
			return NULL;
		}

		TermNode                              * DevelopmentalOntologyHandler::findNode(ItfOntologyTerm *t){

			return findNode(t->get_termId());
		}

		TermNode                              * DevelopmentalOntologyHandler::findNode_by_id(QString termId){
			for(std::list<TermNode*>::iterator it=this->Nodes->begin();it!=this->Nodes->end();it++){
				if((*it)->get_term()->get_termId()==termId){
					return (*it);
				}
			}
			return NULL;
		}

		TermNode                              * DevelopmentalOntologyHandler::findNode(QString termId){
			for(std::list<TermNode*>::iterator it=this->Nodes->begin();it!=this->Nodes->end();it++){
				if(findNode((*it),termId)!=NULL){
					return findNode((*it),termId);
				}


			}
			return NULL;

		}

		TermNode                              * DevelopmentalOntologyHandler::findNode(TermNode * start,QString termId){
			TermNode * ret =NULL;
			if(start->get_term()->get_termId()==termId){
				ret=start;
			}
			else{
				for(std::list<AttributeRelation<TermNode*>*>::iterator it=start->get_childs()->begin();it!=start->get_childs()->end();it++){
					if(findNode((*it)->relation,termId)!=NULL){
						ret=findNode((*it)->relation,termId);
					}
				}

			}
			return ret;
		}

		std::list<TermNode*>                  * DevelopmentalOntologyHandler::get_listNodes(){
			return this->Nodes;
		}

		QString                                 DevelopmentalOntologyHandler::get_publisher(){
			return "Max Planck Institute of Molecular Plant Physiology, Potsdam/Golm, Germany";

		}

		QString                                 DevelopmentalOntologyHandler::get_version(){
			return "1.0.0";
		}

		QString                                 DevelopmentalOntologyHandler::get_componentName(){
			return "Standard Developmental Ontology for PO";
		}

		QString                                 DevelopmentalOntologyHandler::get_author(){
			return "Jan Hannemann";
		}

		QString                                 DevelopmentalOntologyHandler::get_description(){
			return "This is a standard handler for the PlantOntology developmental ontology.";
		}

		QString                                 DevelopmentalOntologyHandler::get_uri(){
			return "http://www.plantontology.org/DevelopmentalStage";
		}

		ItfXemlComponent                      * DevelopmentalOntologyHandler::copy(){
			return new DevelopmentalOntologyHandler();
		}

		QString                                 DevelopmentalOntologyHandler::get_validation_events(){
			QString tmp="validation problem";
			return tmp;
		}

		QString                                 DevelopmentalOntologyHandler::get_namespace(){
			return this->name_space;
		}

		void                                    DevelopmentalOntologyHandler::set_namespace(QString _namespace){
			this->name_space=_namespace;
		}

		QString                                 DevelopmentalOntologyHandler::get_namespaceAlias(){
			return this->namespaceAlias;
		}

		void                                    DevelopmentalOntologyHandler::set_namespaceAlias(QString _namespaceAlias){
			this->namespaceAlias=_namespaceAlias;
		}

		bool                                    DevelopmentalOntologyHandler::get_autoValidation(){
			return this->autovalid;
		}

		void                                    DevelopmentalOntologyHandler::set_autoValidation(bool _autovalidation){
			this->autovalid=_autovalidation;
		}

		QString                                 DevelopmentalOntologyHandler::get_instanceLocation(){
			return this->instanceLocation;
		}

		void                                    DevelopmentalOntologyHandler::set_instanceLocation(QString _instancelocation){
			if(this->instanceLocation!=_instancelocation){
				this->instanceLocation=_instancelocation;
				this->reloadNeeded=true;
			}
		}
		QString                                 DevelopmentalOntologyHandler::get_ontologyLoadMessage(){
			return this->ontologyLoadMessage;
		}

		OntologyLoadState                       DevelopmentalOntologyHandler::get_ontologyLoadState(){
			return this->ontologyLoadState;
		}

		OntologyType                            DevelopmentalOntologyHandler::get_ontologyType(){
			return Xeml::Document::Contracts::Developmental;
		}

		void                                    DevelopmentalOntologyHandler::load(QString _nameSpaceAlias){
			load(_nameSpaceAlias,false);
		}

		void                                    DevelopmentalOntologyHandler::load(QString _nameSpaceAlias, bool force){
			if(this->namespaceAlias!=_nameSpaceAlias){
				this->namespaceAlias=_nameSpaceAlias;
				this->reloadNeeded =true;
			}
			if(this->reloadNeeded || force){
				this->terms.clear();
				try
				{
					std::cerr << "create the download manager " << std::endl;
					downloadManager = new DownloadManager();
					QUrl tmp_url;
					tmp_url=downloadManager->retrieve_ontologies_url(this->URI);

					QFile tmpfile(FileLocationPrefix);
					if(!tmpfile.exists()){
						downloadManager->download_File(tmp_url,FileLocationPrefix);
					}
					std::cerr << "file downloaded" <<std::endl;
					oboreader= new OboReader(this);
					oboreader->read(FileLocationPrefix,&(this->terms));
					buildHierarchy();
					//std::cerr << "debug" << std::endl;
					delete this->downloadManager;
					delete this->oboreader;
					this->reloadNeeded = false;
					this->ontologyLoadState = Xeml::Document::Contracts::Loaded;
				}
				catch(exception ex){
					std::cerr << ex.what() << std::endl;
				}
			}
		}

		void                                    DevelopmentalOntologyHandler::buildHierarchy(){
			std::map<QString,ItfOntologyTerm*>::iterator it=this->terms.begin();
			for (;it!=this->terms.end();++it){
				TermNode * tn = TermNode::createNode(it->second);
				this->Nodes->push_back(tn);
			}
			std::string rel="";
			std::string val="";
			for(std::list<TermNode*>::iterator it=this->Nodes->begin();it!=this->Nodes->end();++it)
			{
				if ((*it)->get_term()->contains(QString("is_a")) ||
						(*it)->get_term()->contains(QString("part_of")) ||
						(*it)->get_term()->contains(QString("develops_from")) ||
						(*it)->get_term()->contains(QString("relationship")))
				{
					if((*it)->get_term()->contains("is_a")){
						rel="is_a";

						val=(*it)->get_term()->get_termAttributesByKey(QString(rel.c_str()))->get_value().toStdString();
						QStringList list = QString(val.c_str()).split(" ! ");
						val=list.at(0).toStdString();
						if(this->findNode_by_id(QString(val.c_str()))!=NULL){
							this->findNode_by_id(QString(val.c_str()))->addSubNode((*it),QString(rel.c_str()));
						}

					}
					if((*it)->get_term()->contains("part_of")){
						rel="part_of";

						val=(*it)->get_term()->get_termAttributesByKey(QString(rel.c_str()))->get_value().toStdString();
						QStringList list = QString(val.c_str()).split(" ! ");
						val=list.at(0).toStdString();
						if(this->findNode_by_id(QString(val.c_str()))!=NULL){
							this->findNode_by_id(QString(val.c_str()))->addSubNode((*it),QString(rel.c_str()));
						}

					}
					if((*it)->get_term()->contains("develops_from")){
						rel="develops_from";

						val=(*it)->get_term()->get_termAttributesByKey(QString(rel.c_str()))->get_value().toStdString();
						QStringList list = QString(val.c_str()).split(" ! ");
						val=list.at(0).toStdString();
						if(this->findNode_by_id(QString(val.c_str()))!=NULL){
							this->findNode_by_id(QString(val.c_str()))->addSubNode((*it),QString(rel.c_str()));
						}

					}
					if((*it)->get_term()->contains("relationship")){
						rel="relationship";
						val=(*it)->get_term()->get_termAttributesByKey(QString(rel.c_str()))->get_value().toStdString();
						if(QString(val.c_str()).contains("is_a")){
							rel="is_a";
							QStringList list = QString(val.c_str()).split(" ");
							val=list.at(1).toStdString();

						}
						else if(QString(val.c_str()).contains("part_of")){
							rel="part_of";
							QStringList list = QString(val.c_str()).split(" ");
							val=list.at(1).toStdString();

						}
						else if(QString(val.c_str()).contains("develops_from")){
							rel="develops_from";
							QStringList list = QString(val.c_str()).split(" ");
							val=list.at(1).toStdString();

						}
						if(this->findNode_by_id(QString(val.c_str()))!=NULL){
							this->findNode_by_id(QString(val.c_str()))->addSubNode((*it),QString(rel.c_str()));
						}
					}
				}
			}
		}

		void                                    DevelopmentalOntologyHandler::reportError(exception _ex){
			this->ontologyLoadState=Xeml::Document::Contracts::LoadFailed;
			this->ontologyLoadMessage =_ex.what();
			std::cerr << "DevelopmentalHandler. End ontology load with exception:"+ ontologyLoadMessage.toStdString();
			//ValidationMessage vm = new ValidationMessage(SeverityCode.Error, "Ontology file load failed: '" + ex.Message + "'", this.ComponentName, false);
			//OnValidation(vm);
		}
	}
}
