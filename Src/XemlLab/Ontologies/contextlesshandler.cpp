#include "contextlesshandler.h"

namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace OBO{
				ContextLessHandler::ContextLessHandler()
				{

				}
				ContextLessHandler::~ContextLessHandler(void){

				}

				void ContextLessHandler::buildContexts(std::list<AttributeStore*> * _collection){
					AttributeStore * currentXeoTermWithContext;
					for(std::list<AttributeStore*>::iterator it = _collection->begin();it!=_collection->end();++it){
						if((*it)->isEnvironmentVariableTerm()){
							currentXeoTermWithContext=(*it);
							for(std::map<QString,ItfDynamicOntologyTerm*>::iterator it2=this->terms.begin();it2!=this->terms.end();++it2){
								if(currentXeoTermWithContext->get_id()==(*it2).second->get_termId()){
									XeoTerm * currentXeoTerm = static_cast<XeoTerm*>((*it2).second);

									QString contextName = currentXeoTerm->get_name();

									VariableContextSpec * context = createQuantityContext(contextName);
									(*currentXeoTerm->get_contextCollection())[context->get_name()]=context;
									currentXeoTermWithContext->contextCollection->push_back(context);

									context=createResponseRangeContext(contextName);
									(*currentXeoTerm->get_contextCollection())[context->get_name()]=context;
									currentXeoTermWithContext->contextCollection->push_back(context);

									context=createFreeTextContext();
									(*currentXeoTerm->get_contextCollection())[context->get_name()]=context;
									currentXeoTermWithContext->contextCollection->push_back(context);
								}
							}
						}
					}

				}
				VariableContextSpec * ContextLessHandler::createQuantityContext(QString _contextName){
					VariableContextSpec * context =new VariableContextSpec();
					context->set_unitSet(new UnitSet());
					context->set_typeDefine(new TypeSpecification());
					context->set_name("Quantity");
					context->get_typeDefine()->set_baseType(Xeml::Document::Text);

					TypeSpecifics * ts= new Xeml::Document::EnvironmentalOntology::Enum();
					ts->set_textVal(_contextName);
					context->get_typeDefine()->get_typeSpecifica()->push_back(ts);
					context->set_def_value(_contextName);
					return context;
				}

				VariableContextSpec * ContextLessHandler::createResponseRangeContext(QString _contextName){
					VariableContextSpec * context =new VariableContextSpec();
					context->set_unitSet(new UnitSet());
					context->set_typeDefine(new TypeSpecification());
					context->set_name("ResponseRange");
					context->get_typeDefine()->set_baseType(Xeml::Document::Text);
					for (int i=0;i<=10;i++){
						context->get_typeDefine()->get_typeSpecifica()->push_back(new Xeml::Document::EnvironmentalOntology::Enum(QString::number(i)));
					}
					context->set_def_value("5");
					return context;
				}

				VariableContextSpec * ContextLessHandler::createFreeTextContext(){
					VariableContextSpec * context =new VariableContextSpec();
					context->set_unitSet(new UnitSet());
					context->set_typeDefine(new TypeSpecification());
					context->set_name("FreeText");
					context->get_typeDefine()->set_baseType(Xeml::Document::Text);
					return context;
				}

			}
		}
	}
}
