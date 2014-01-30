#include "plantstructureontologyhandler.h"

namespace Xeml {

	namespace Document{

		namespace PlantStructure{
			PlantStructureOntologyHandler::PlantStructureOntologyHandler()
			{
				this->ontologyLoadState=Xeml::Document::Contracts::Unloaded;
				this->Nodes=new list<TermNode*>();
				URI="http://www.plantontology.org/PlantStructure";
				/*
#if defined(Q_OS_WIN)
									   this->FileLocationPrefix=QString("C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEML/PO_Structure.obo");
#elif defined(Q_OS_MACX)
									   this->FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/PO_Structure.obo");
#else
									   this->FileLocationPrefix=QString("/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEML/PO_Structure.obo");
#endif
*/
				this->FileLocationPrefix=QString("://XEML/po_anatomy.obo");

                //FileLocationPrefix="/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/PO_Structure.obo";
			}
			PlantStructureOntologyHandler::~PlantStructureOntologyHandler(){

			}

			std::map<QString,ItfOntologyTerm*> PlantStructureOntologyHandler::get_terms(){
				return this->terms;
			}
			bool PlantStructureOntologyHandler::contain(BasicTerm param){
				std::map<QString,ItfOntologyTerm*>::const_iterator trouve=this->terms.find(param.get_termId());
				if (trouve==this->terms.end()){
					return false;
				}
				else{
					return true;
				}
			}

			ItfOntologyTerm * PlantStructureOntologyHandler::findKey(BasicTerm param){
				for(std::map<QString,ItfOntologyTerm*>::iterator it=this->terms.begin();it!=this->terms.end();it++){

					if(it->first==param.get_termId()){
						return it->second;
					}

				}
				return NULL;
			}

			ItfOntologyTerm * PlantStructureOntologyHandler::findKey(QString termId){
				for(std::map<QString,ItfOntologyTerm*>::iterator it=this->terms.begin();it!=this->terms.end();it++){

					if(it->first==termId){
						return it->second;
					}

				}
				return NULL;
			}
			TermNode*       PlantStructureOntologyHandler::findNode(ItfOntologyTerm *t){

				return findNode(t->get_termId());
			}
			TermNode*       PlantStructureOntologyHandler::findNode_by_id(QString termId){
				for(std::list<TermNode*>::iterator it=this->Nodes->begin();it!=this->Nodes->end();it++){
					if((*it)->get_term()->get_termId()==termId){
						return (*it);
					}
				}
				return NULL;
			}

			TermNode*       PlantStructureOntologyHandler::findNode(QString termId){
				for(std::list<TermNode*>::iterator it=this->Nodes->begin();it!=this->Nodes->end();it++){
					if(findNode((*it),termId)!=NULL){
						return findNode((*it),termId);
					}


				}
				return NULL;

			}
			TermNode*      PlantStructureOntologyHandler::findNode(TermNode * start,QString termId){
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

			std::list<TermNode*> * PlantStructureOntologyHandler::get_listNodes(){
				return this->Nodes;
			}
			QString        PlantStructureOntologyHandler::get_publisher(){
				return "Max Planck Institute of Molecular Plant Physiology, Potsdam/Golm, Germany";

			}

			QString        PlantStructureOntologyHandler::get_version(){
				return "1.0.0";
			}

			QString        PlantStructureOntologyHandler::get_componentName(){
				return "Standard Plant Ontology Handler";
			}

			QString        PlantStructureOntologyHandler::get_author(){
				return "Jan Hannemann";
			}

			QString        PlantStructureOntologyHandler::get_description(){
				return "The XEML framework standard component for the definiton of plant material. This component can handle ontolgies which are formulated in the OBO file format.";
			}

			QString        PlantStructureOntologyHandler::get_uri(){
				return this->URI;
			}
			ItfXemlComponent * PlantStructureOntologyHandler::copy(){
				return new PlantStructureOntologyHandler();
			}

			QString PlantStructureOntologyHandler::get_validation_events(){
				QString tmp="problem";
				return tmp;
			}

			QString                                 PlantStructureOntologyHandler::get_namespace(){
				return this->name_space;
			}
			void        PlantStructureOntologyHandler::set_namespace(QString _namespace){
				this->name_space=_namespace;
			}
			QString                            PlantStructureOntologyHandler::get_namespaceAlias(){
				return this->namespaceAlias;
			}
			void        PlantStructureOntologyHandler::set_namespaceAlias(QString _namespaceAlias){
				this->namespaceAlias=_namespaceAlias;
			}

			bool                               PlantStructureOntologyHandler::get_autoValidation(){
				return this->autovalid;
			}

			void           PlantStructureOntologyHandler::set_autoValidation(bool _autovalidation){
				this->autovalid=_autovalidation;
			}

			QString                          PlantStructureOntologyHandler::get_instanceLocation(){
				return this->instanceLocation;
			}

			void    PlantStructureOntologyHandler::set_instanceLocation(QString _instancelocation){
				if(this->instanceLocation!=_instancelocation){
					this->instanceLocation=_instancelocation;
					this->reloadNeeded=true;
				}
			}
			QString                       PlantStructureOntologyHandler::get_ontologyLoadMessage(){
				return this->ontologyLoadMessage;
			}

			OntologyLoadState               PlantStructureOntologyHandler::get_ontologyLoadState(){
				return this->ontologyLoadState;
			}

			OntologyType                         PlantStructureOntologyHandler::get_ontologyType(){
				return Xeml::Document::Contracts::OrganismStructure;
			}

			void                       PlantStructureOntologyHandler::load(QString _nameSpaceAlias){
				load(_nameSpaceAlias,false);
			}

			void           PlantStructureOntologyHandler::load(QString _nameSpaceAlias, bool force){
				if(this->namespaceAlias!=_nameSpaceAlias){
					this->namespaceAlias=_nameSpaceAlias;
					this->reloadNeeded =true;
				}
				if(this->reloadNeeded || force){
					this->terms.clear();
					try
					{
						std::cerr << "create download manager" << std::endl;
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
			void                                   PlantStructureOntologyHandler::buildHierarchy(){
				std::map<QString,ItfOntologyTerm*>::iterator it=this->terms.begin();
				for (;it!=this->terms.end();++it){
					TermNode * tn = TermNode::createNode(it->second);
					this->Nodes->push_back(tn);
				}

				//std::list<TermNode*> * processedNodes =new std::list<TermNode*>();
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
			void                                    PlantStructureOntologyHandler::reportError(exception _ex){
				this->ontologyLoadState=Xeml::Document::Contracts::LoadFailed;
				this->ontologyLoadMessage =_ex.what();
				std::cerr << "DevelopmentalHandler. End ontology load with exception:"+ ontologyLoadMessage.toStdString();

			}
		}
	}
}
