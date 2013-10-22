#include "envohandler.h"
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace OBO{
				EnvOHandler::EnvOHandler()
				{
					this->URI=QString("http://xeml.mpimp-golm.mpg.de/xemlenvo");
					/*
#if defined(Q_OS_WIN)
									   this->FileLocationPrefix=QString("C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEML/EnvO.obo");
#elif defined(Q_OS_MACX)
									   this->FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/EnvO.obo");
#else
									   this->FileLocationPrefix=QString("/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEML/EnvO.obo");
#endif
*/
					this->FileLocationPrefix=QString("://XEML/EnvO.obo");


                    //this->FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/EnvO.obo");
				}
				EnvOHandler::~EnvOHandler(void){

				}

				QString            EnvOHandler::get_publisher(){
					return "Max Planck Institute of Molecular Plant Physiology, Potsdam/Golm, Germany";

				}

				QString            EnvOHandler::get_version(){
					return "1.0.0";
				}

				QString            EnvOHandler::get_componentName(){
					return "Environment Ontology (EnvO) Handler";
				}

				QString            EnvOHandler::get_author(){
					return "Benjamin Dartigues";
				}

				QString            EnvOHandler::get_description(){
					return "This ontology is intended to support the annotation of the environment of any organism or biological sample.";
				}

				QString            EnvOHandler::get_uri(){
					return this->URI;
				}
				ItfXemlComponent * EnvOHandler::copy(){
					return new EnvOHandler();
				}
				void               EnvOHandler::displayVectorContent(std::vector<QString> * vec){
					std::vector<QString>::iterator it=vec->begin();
					for(;it!=vec->end();++it){
						std::cerr << (*it).toStdString() << std::endl;
					}
				}
				void               EnvOHandler::doTagTypeAnnotation(std::list<AttributeStore*> * _collection){
					//std::cerr << "ENTERING DO TAG TYPE ANNOTATION" << std::endl;

					std::vector<QString> * environmentTerms= new std::vector<QString>();
					bool altered = true;
					while(altered){
						altered=false;
						int cpt=0;
						for(std::list<AttributeStore*>::iterator it=_collection->begin();it!=_collection->end();++it){
							if((*it)->isTerm() && (*it)->isNoneTerm()){

								//std::cerr << "ATT :" << cpt << "IS TERM AND IS NONE TERM" << std::endl;


								if((*it)->contain(Xeml::Document::Ontologies::OBO::is_a)){
									//std::cerr << "ATT :" << cpt << "CONTAIN IS_A ATTRIBUTE" << std::endl;

									if(std::find(environmentTerms->begin(),environmentTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a))!=environmentTerms->end()){

										if(std::find(environmentTerms->begin(),environmentTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::id))==environmentTerms->end()){
											environmentTerms->insert(std::find(environmentTerms->begin(),environmentTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a)),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
											(*it)->headerClass=Xeml::Document::Ontologies::OBO::EnvironmentVariable;
										}
										else
										{
											std::cerr << "Duplicated environment identifier : "<< (*it)->get_value(Xeml::Document::Ontologies::OBO::id).toStdString() <<  " found " << std::endl;
										}
										altered=true;
										//continue;
									}
									else{
										//std::cerr << "ATT :" << cpt << "IS_A ATTRIBUTE NOT FOUND" << std::endl;
									}
								}
								else{
									//std::cerr << "ATT :" << cpt << "NOT CONTAIN IS_A ATTRIBUTE" << std::endl;

									if((*it)->get_value(Xeml::Document::Ontologies::OBO::name)=="environmental feature"){
										//std::cerr << "ATT :" << cpt << "NAME = plant environment ontology" << std::endl;

										//std::cerr << "first environment term id : " << (*it)->get_value(Xeml::Document::Ontologies::OBO::id) << std::endl;
										environmentTerms->insert(environmentTerms->begin(),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
										//std::cerr << "size : " << environmentTerms->size() << std::endl;

										(*it)->headerClass=Xeml::Document::Ontologies::OBO::EnvironmentVariable;
										 altered=true;
									}
								}
								cpt++;
							}

						}
						//std::cerr << "size : "<< environmentTerms->size() << std::endl;

					}
				}
				OntologyType                    EnvOHandler::get_ontologyType(){
					return Xeml::Document::Contracts::EnvO;
				}

				AttributeStore                             * EnvOHandler::get_attribute_by_tagvalue(QString _tagValue,std::list<AttributeStore*> _collection){
					for(std::list<AttributeStore*>::iterator it = _collection.begin();it!=_collection.end();++it){
						if((*it)->contain(Xeml::Document::Ontologies::OBO::id) && (*it)->get_value(Xeml::Document::Ontologies::OBO::id)==_tagValue){
							return (*it);
						}
					}
					return NULL;
				}
			}
		}
	}
}
