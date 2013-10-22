#include "xeohandler.h"
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace OBO{
				XeoHandler::XeoHandler()
				{
					this->URI=QString("http://xeml.mpimp-golm.mpg.de/xemlobo");

/*
#if defined(Q_OS_WIN)
									   this->FileLocationPrefix=QString("C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEML/XEO.obo");
#elif defined(Q_OS_MACX)
									   this->FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/XEO.obo");
#else
									   this->FileLocationPrefix=QString("/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEML/XEO.obo");
#endif
*/

					this->FileLocationPrefix=QString("://XEML/XEO.obo");
				}
				XeoHandler::~XeoHandler(void){

				}

				QString            XeoHandler::get_publisher(){
					return "Max Planck Institute of Molecular Plant Physiology, Potsdam/Golm, Germany";

				}

				QString            XeoHandler::get_version(){
					return "1.0.0";
				}

				QString            XeoHandler::get_componentName(){
					return "XEML Environment Ontolgy Handler";
				}

				QString            XeoHandler::get_author(){
					return "Benjamin Dartigues";
				}

				QString            XeoHandler::get_description(){
					return "The XEML framework standard component for the definiton of environments. This component handles the environment ontolgy in OBO file format.";
				}

				QString            XeoHandler::get_uri(){
					return this->URI;
				}
				ItfXemlComponent * XeoHandler::copy(){
					return new XeoHandler();
				}

				void               XeoHandler::displayVectorContent(std::vector<QString> * vec){
					std::vector<QString>::iterator it=vec->begin();
					for(;it!=vec->end();++it){
						std::cerr << (*it).toStdString() << std::endl;
					}
				}

				void               XeoHandler::doTagTypeAnnotation(std::list<AttributeStore*> * _collection){
					std::vector<QString> * environmentTerms= new std::vector<QString>();
					std::vector<QString> * contextTerms = new std::vector<QString>();
					std::vector<QString> * dataTypeTerms = new std::vector<QString>();
					bool altered = true;
					while(altered){
						altered=false;

						for(std::list<AttributeStore*>::iterator it=_collection->begin();it!=_collection->end();++it)
						{
							if((*it)->isTerm() && (*it)->isNoneTerm()){
								if((*it)->contain(Xeml::Document::Ontologies::OBO::is_a)){
									if(std::find(environmentTerms->begin(),environmentTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a))!=environmentTerms->end()){
										if(std::find(environmentTerms->begin(),environmentTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::id))==environmentTerms->end())
										{
											environmentTerms->insert(std::find(environmentTerms->begin(),environmentTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a)),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
											(*it)->headerClass=Xeml::Document::Ontologies::OBO::EnvironmentVariable;
										}
										else
										{
											std::cerr << "Duplicated environment identifier : "<< (*it)->get_value(Xeml::Document::Ontologies::OBO::id).toStdString() <<  " found " << std::endl;
										}
										altered=true;
										continue;
									}
									else{
									}
									if(std::find(contextTerms->begin(),contextTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a))!=contextTerms->end()){

										if(std::find(contextTerms->begin(),contextTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::id))==contextTerms->end())
										{
											contextTerms->insert(std::find(contextTerms->begin(),contextTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a)),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
											(*it)->headerClass=Xeml::Document::Ontologies::OBO::Context;
										}
										else
										{
											std::cerr << "Duplicated environment identifier : "<< (*it)->get_value(Xeml::Document::Ontologies::OBO::id).toStdString() <<  " found " << std::endl;
										}
										altered=true;
										continue;
									}
									else{
									}
									if(std::find(dataTypeTerms->begin(),dataTypeTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a))!=dataTypeTerms->end()){

										if(std::find(dataTypeTerms->begin(),dataTypeTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::id))==dataTypeTerms->end())
										{
											dataTypeTerms->insert(std::find(dataTypeTerms->begin(),dataTypeTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a)),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
											(*it)->headerClass=Xeml::Document::Ontologies::OBO::DataType;
										}
										else
										{
											std::cerr << "Duplicated environment identifier : "<< (*it)->get_value(Xeml::Document::Ontologies::OBO::id).toStdString() <<  " found " << std::endl;
										}
										altered=true;
										continue;
									}
									else{
									}
									if((*it)->headerClass==Xeml::Document::Ontologies::OBO::None){
										(*it)->headerClass=Xeml::Document::Ontologies::OBO::DataType;
										dataTypeTerms->insert(std::find(dataTypeTerms->begin(),dataTypeTerms->end(),(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a)),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
									}



								}
								else
								{
									if(!altered)
										switch((*it)->get_termClass((*it)->get_value(Xeml::Document::Ontologies::OBO::name))){
											case Xeml::Document::Ontologies::OBO::EnvironmentVariable:
											{
												environmentTerms->insert(environmentTerms->begin(),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
												(*it)->headerClass=Xeml::Document::Ontologies::OBO::EnvironmentVariable;
												break;
											}
											case Xeml::Document::Ontologies::OBO::Context :
											{
												contextTerms->insert(contextTerms->begin(),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
												(*it)->headerClass=Xeml::Document::Ontologies::OBO::Context;
												break;
											}
											case Xeml::Document::Ontologies::OBO::DataType :
											{
												dataTypeTerms->insert(dataTypeTerms->begin(),(*it)->get_value(Xeml::Document::Ontologies::OBO::id));
												(*it)->headerClass=Xeml::Document::Ontologies::OBO::DataType;
												break;
											}
											default:
												std::cerr << "expected root element from set 'EnvironmentVariable', 'Context' or 'DataTypes'" << std::endl;

										}
										altered = false;
								}
							}
							else{
								altered = false;
							}
						}
					}
				}
				AttributeStore   * XeoHandler::get_attribute_by_tagvalue(QString _tagValue,std::list<AttributeStore*> * _collection){
					for(std::list<AttributeStore*>::iterator it = _collection->begin();it!=_collection->end();++it){
						if((*it)->contain(Xeml::Document::Ontologies::OBO::id) && (*it)->get_value(Xeml::Document::Ontologies::OBO::id)==_tagValue){
							return (*it);
						}
					}
					return NULL;

				}
				void               XeoHandler::buildContexts(std::list<AttributeStore*>  * _collection){
					//std::cerr << "attribute store not destroy yet (build context)" << std::endl;

					AttributeStore * currentXeoTermWithContext;
					AttributeStore * currentContextAttributeStore;
					std::map<QString,VariableContextSpec*> * contextCollection = new std::map<QString,VariableContextSpec*>();
					/*
					* first run: create all contextes for Environment variables with "has_context" relations
					* iterate the attributelist for all used contexte
					*/

					for(std::list<AttributeStore*>::iterator it = _collection->begin();it!=_collection->end();++it){
						if((*it)->isEnvironmentVariableTerm() && (*it)->contain(Xeml::Document::Ontologies::OBO::has_context)){
							currentXeoTermWithContext = (*it);
							//std::cerr << "the problem is here" << std::endl;
							for(std::vector<std::pair<OboTags,QString> >::iterator it2=currentXeoTermWithContext->get_obo_list()->begin();it2!=currentXeoTermWithContext->get_obo_list()->end();++it2){
								if((*it2).first==Xeml::Document::Ontologies::OBO::has_context){
									if(get_attribute_by_tagvalue((*it2).second,_collection)!=NULL){
										currentContextAttributeStore = get_attribute_by_tagvalue((*it2).second,_collection);
										VariableContextSpec * context= NULL;
										if(contextCollection->find(currentContextAttributeStore->get_id())==contextCollection->end()){
											context = createContext(_collection,currentXeoTermWithContext,(*it2).second,currentContextAttributeStore->get_name());
											//std::cerr << "after create context" << std::endl;

											createContextUnitSet(_collection,context,(*it2).second);
											(*contextCollection)[currentContextAttributeStore->get_id()]=context;
										}
										else{
											context=(*contextCollection)[currentContextAttributeStore->get_id()];
										}
										(*currentXeoTermWithContext->term->get_contextCollection())[currentContextAttributeStore->get_name()]=context;
										currentXeoTermWithContext->contextCollection->push_back(context);

									}

								}
							}
						}
					}
					//std::cerr << "end of builds context" << std::endl;

					/*
					* second run: create all contextes for Environment variables with "has_enum" relations
					*/
					for(std::list<AttributeStore*>::iterator it = _collection->begin();it!=_collection->end();++it){
						if((*it)->isEnvironmentVariableTerm() && (*it)->contain(Xeml::Document::Ontologies::OBO::has_enum)){
							currentXeoTermWithContext = (*it);
							for(std::vector<std::pair<OboTags,QString> >::iterator it2=currentXeoTermWithContext->get_obo_list()->begin();it2!=currentXeoTermWithContext->get_obo_list()->end();++it2){
								if((*it2).first==Xeml::Document::Ontologies::OBO::has_enum){
									if(get_attribute_by_tagvalue((*it2).second,_collection)!=NULL){
										currentContextAttributeStore = get_attribute_by_tagvalue((*it2).second,_collection);
										VariableContextSpec * context= NULL;
										if(contextCollection->find(currentContextAttributeStore->get_id())==contextCollection->end()){
											context = createContext(_collection,currentXeoTermWithContext,(*it2).second,currentContextAttributeStore->get_name());
											createContextEnumeration(_collection,context,(*it2).second);
											(*contextCollection)[currentContextAttributeStore->get_id()]=context;
										}
										else{
											context=(*contextCollection)[currentContextAttributeStore->get_id()];
										}
										(*currentXeoTermWithContext->term->get_contextCollection())[currentContextAttributeStore->get_name()]=context;
										currentXeoTermWithContext->contextCollection->push_back(context);

									}

								}
							}
						}
					}
				}
			}
		}
	}
}
