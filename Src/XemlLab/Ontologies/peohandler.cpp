#include "peohandler.h"
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace OBO{

				PEOHandler::PEOHandler()
				{
					this->URI=QString("http://xeml.mpimp-golm.mpg.de/xemleo");
					/*
#if defined(Q_OS_WIN)
									   this->FileLocationPrefix=QString("C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEML/EO.obo");
#elif defined(Q_OS_MACX)
									   this->FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/EO.obo");
#else
									   this->FileLocationPrefix=QString("/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEML/EO.obo");
#endif
*/
					this->FileLocationPrefix=QString("://XEML/EO.obo");

                    //this->FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/EO.obo");
				}
				PEOHandler::~PEOHandler(void){

				}

				QString            PEOHandler::get_publisher(){
					return "Max Planck Institute of Molecular Plant Physiology, Potsdam/Golm, Germany";

				}

				QString            PEOHandler::get_version(){
					return "1.0.0";
				}

				QString            PEOHandler::get_componentName(){
					return "Plant Environment Ontology (PEO) Handler";
				}

				QString            PEOHandler::get_author(){
					return "Benjamin Dartigues";
				}

				QString            PEOHandler::get_description(){
					return "It represents a controlled vocabulary to describe different types of supplemental environments that have been reported in the experimental profiles of gene expression and phenotype (mutant and QTL) studies on cereal plants.";
				}

				QString            PEOHandler::get_uri(){
					return this->URI;
				}
				ItfXemlComponent * PEOHandler::copy(){
					return new PEOHandler();
				}
				void               PEOHandler::displayVectorContent(std::vector<QString> * vec){
					std::vector<QString>::iterator it=vec->begin();
					for(;it!=vec->end();++it){
						std::cerr << (*it).toStdString() << std::endl;
					}
				}
				void               PEOHandler::doTagTypeAnnotation(std::list<AttributeStore*> * _collection){
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

									if((*it)->get_value(Xeml::Document::Ontologies::OBO::name)=="plant environment ontology"){
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
				OntologyType                    PEOHandler::get_ontologyType(){
					return Xeml::Document::Contracts::EO;
				}

				AttributeStore                             * PEOHandler::get_attribute_by_tagvalue(QString _tagValue,std::list<AttributeStore*> *_collection){
					for(std::list<AttributeStore*>::iterator it = _collection->begin();it!=_collection->end();++it){
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

