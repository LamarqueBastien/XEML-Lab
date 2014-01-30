#include "obohandler.h"
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace OBO{

				OboHandler::OboHandler()
				{
					this->nodes=new std::list<TermNode*>();
				}
				bool compare_nocase_termnode (TermNode* first, TermNode* second)
				{
					unsigned int i=0;
					while ( (i<first->get_label().toStdString().length()) && (i<second->get_label().toStdString().length()) )
					{
						if (tolower((first->get_label().toStdString())[i])<tolower((second->get_label().toStdString())[i])){

							return true;
						}
						else if (tolower((first->get_label().toStdString())[i])>tolower((second->get_label().toStdString())[i])){
							return false;
						}
						++i;
					}
					if (first->get_label().toStdString().length()<second->get_label().toStdString().length()){

						return true;
					}
					else{
						return false;
					}
				}

				void                            OboHandler::sortNodes(std::list<TermNode*> * _collection){

				}

				void                            OboHandler::build_isa_hierarchy(std::list<AttributeStore*> * _collection){
					for(std::list<AttributeStore*>::iterator it=_collection->begin();it!=_collection->end();++it){
						if((*it)->isEnvironmentVariableTerm() && (*it)->contain(Xeml::Document::Ontologies::OBO::is_a)){
							TermNode * tn =this->findNode_by_id((*it)->get_id());
							TermNode * parent = this->findNode_by_id((*it)->get_value(Xeml::Document::Ontologies::OBO::is_a));
							if(parent != NULL){
								parent->isContainer=true;
								parent->addSubNode(tn,"is_a");
							}
						}
					}


				}

				void                            OboHandler::deleteHeaderNodes(){

				}

				void                            OboHandler::addInheritedContext(std::list<AttributeStore*> * _collection){
					for(std::list<AttributeStore*>::iterator it =_collection->begin();it!= _collection->end();++it){

						if((*it)->term !=NULL){
							//std::cerr << "TERM NOT NULL" << std::endl;
							if((*it)->contain(Xeml::Document::Ontologies::OBO::is_a)){
								//std::cerr << "TERM CONTAIN IS_A ATTRIBUTE" << std::endl;
								if((*it)->isEnvironmentVariableTerm()){
									//std::cerr << "termId" << (*it)->term->get_termId().toStdString() << std::endl;

								}
								else{
									//std::cerr << "NOT ENVIRONMENT VARIABLE" << std::endl;
								}
								addInheritedContext(_collection,(*it)->term,(*it)->get_value(Xeml::Document::Ontologies::OBO::is_a));
							}
						}
					}
				}

				void                            OboHandler::addInheritedContext(std::list<AttributeStore*> * _collection,XeoTerm * _targetXeoTerm,QString _currentId){
					//std::cerr << "entering add inherited context" << std::endl;
					AttributeStore * current;
					if(_targetXeoTerm==NULL){
						//std::cerr << "NULL TERM" << std::endl;
					}
					//std::cerr << "termId" << _targetXeoTerm->get_termId().toStdString() << std::endl;

					for(std::list<AttributeStore*>::iterator it=_collection->begin();it!= _collection->end();++it){
						if((*it)->contain(Xeml::Document::Ontologies::OBO::id)&& (*it)->get_value(Xeml::Document::Ontologies::OBO::id)==_currentId){
							current = (*it);
						}
					}
					for(std::vector<VariableContextSpec*>::iterator it = current->contextCollection->begin();it != current->contextCollection->end();++it){
						if(!_targetXeoTerm->contain((*it)->get_name())){
							(*_targetXeoTerm->get_contextCollection())[(*it)->get_name()]=(*it);

						}
					}
					if(current->contain(Xeml::Document::Ontologies::OBO::is_a)){
						addInheritedContext(_collection,_targetXeoTerm,current->get_value(Xeml::Document::Ontologies::OBO::is_a));
					}


				}

				void                            OboHandler::addEnum(std::list<AttributeStore*> * _collection,VariableContextSpec * _context,QString _instanceId){
					for(std::list<AttributeStore*>::iterator it =_collection->begin();it!= _collection->end();++it){
						if((*it)->contain_header_type(Xeml::Document::Ontologies::OBO::Instance) && (*it)->contain_N_compare(Xeml::Document::Ontologies::OBO::instance_of,_instanceId)){
							TypeSpecifics * ts = new Enum();
							ts->set_textVal((*it)->get_value(Xeml::Document::Ontologies::OBO::name));
							_context->get_typeDefine()->get_typeSpecifica()->push_back(ts);

						}
					}
					if(_context->get_typeDefine()->get_typeSpecifica()->size() > 0){
						_context->get_typeDefine()->get_typeSpecifica()->sort(Xeml::Document::EnvironmentalOntology::TypeSpecifics::compare_nocase_typeSpec);
						TypeSpecifics * tmp_ts=(*_context->get_typeDefine()->get_typeSpecifica()->begin());
						_context->set_def_value(tmp_ts->get_textVal());
					}
				}

				void                            OboHandler::defineContextDataType(std::list<AttributeStore*> * _collection,VariableContextSpec *_context,QString _contextId){
					//std::cerr << "entering define context datatype"  << std::endl;
					AttributeStore * contextAttributeStore;

					for(std::list<AttributeStore*>::iterator it=_collection->begin();it!= _collection->end();++it){
						if((*it)->contain(Xeml::Document::Ontologies::OBO::id)&& (*it)->get_value(Xeml::Document::Ontologies::OBO::id)==_contextId){
							contextAttributeStore = (*it);
							//std::cerr << "entering define attstore"  << std::endl;

						}
					}
					AttributeStore * contextDatatypeParentStore;
					if(contextAttributeStore->contain(Xeml::Document::Ontologies::OBO::has_datatype)){
						for(std::list<AttributeStore*>::iterator it=_collection->begin();it!= _collection->end();++it){
							//std::cerr << "entering define attstore1"  << std::endl;

							if((*it)->contain(Xeml::Document::Ontologies::OBO::id)&&(*it)->get_value(Xeml::Document::Ontologies::OBO::id)==contextAttributeStore->get_value(Xeml::Document::Ontologies::OBO::has_datatype)){
								//std::cerr << "entering define attstore2"  << std::endl;

								contextDatatypeParentStore = (*it);
								//std::cerr << "entering define attstore3"  << std::endl;

								if(contextDatatypeParentStore->get_value(Xeml::Document::Ontologies::OBO::name)=="FreeTextContext"){

								}
								else if(contextDatatypeParentStore->get_value(Xeml::Document::Ontologies::OBO::name)=="Text"){
									_context->get_typeDefine()->set_baseType(Xeml::Document::Text);

								}
								else if(contextDatatypeParentStore->get_value(Xeml::Document::Ontologies::OBO::name)=="Number"){
									_context->get_typeDefine()->set_baseType(Xeml::Document::Number);
								}
								else if(contextDatatypeParentStore->get_value(Xeml::Document::Ontologies::OBO::name)=="Date"){
									_context->get_typeDefine()->set_baseType(Xeml::Document::Date);
								}
								else if (contextDatatypeParentStore->get_value(Xeml::Document::Ontologies::OBO::name)=="Bool"){
									_context->get_typeDefine()->set_baseType(Xeml::Document::Bool);
								}
							}
						}
					}
					//std::cerr << "end of define context data type" << std::endl;

				}

				VariableContextSpec           * OboHandler::createContext(std::list<AttributeStore*> * _collection,AttributeStore * _currentXeoTermWithContext,QString _contextId,QString _contextName){
					//std::cerr << "entering create context"  << std::endl;

					VariableContextSpec * context = new VariableContextSpec();
					context->set_unitSet(new UnitSet());
					context->set_typeDefine(new TypeSpecification());
					context->set_name(_contextName);
					if(_currentXeoTermWithContext->contain(Xeml::Document::Ontologies::OBO::def)){
						context->set_description(_currentXeoTermWithContext->get_value(Xeml::Document::Ontologies::OBO::def));
					}
					AttributeStore * contextAttributeStore;
					for(std::list<AttributeStore*>::iterator it=_collection->begin();it!= _collection->end();++it){
						if((*it)->contain(Xeml::Document::Ontologies::OBO::id)&& (*it)->get_value(Xeml::Document::Ontologies::OBO::id)==_contextId){
							contextAttributeStore = (*it);
						}
					}
					if(contextAttributeStore->contain(Xeml::Document::Ontologies::OBO::has_enum)){
						for(std::list<AttributeStore*>::iterator it=_collection->begin();it!= _collection->end();++it){
							if((*it)->get_value(Xeml::Document::Ontologies::OBO::id)==contextAttributeStore->get_value(Xeml::Document::Ontologies::OBO::has_enum)){
								AttributeStore * enumAttributeStore = (*it);
								addEnum(_collection,context,enumAttributeStore->get_id());
							}
						}
					}
					if(_currentXeoTermWithContext->contain(Xeml::Document::Ontologies::OBO::is_a)){
						AttributeStore * datataype;
						for(std::list<AttributeStore*>::iterator it=_collection->begin();it!= _collection->end();++it){
							if((*it)->get_value(Xeml::Document::Ontologies::OBO::id)==contextAttributeStore->get_value(Xeml::Document::Ontologies::OBO::is_a)){
								datataype = (*it);

							}
						}
						if(datataype->get_name()=="Bool"){
							TypeSpecifics * ts = new Enum();
							ts->set_textVal("true");
							context->get_typeDefine()->get_typeSpecifica()->push_back(ts);

							ts= new Enum();
							ts->set_textVal("false");
							context->get_typeDefine()->get_typeSpecifica()->push_back(ts);
							context->set_def_value("false");


						}
					}

					defineContextDataType(_collection,context,_contextId);
					//std::cerr << "end of create context" << std::endl;
					return context;



				}

				void                            OboHandler::createContextUnitSet(std::list<AttributeStore*> * _collection,VariableContextSpec * _context,QString _contextId){
					//std::cerr << "entering create context Unitset"  << std::endl;
					/*
					if(_collection->empty()){

					}
					else{
						std::cerr << _collection->size() << std::endl;

					}
					*/
					for(std::list<AttributeStore*>::iterator it =_collection->begin();it!= _collection->end();++it){
						//if((*it)==NULL){
							//std::cerr << "pointer null" << std::endl;
						//}
						//std::cerr << static_cast<AttributeStore*>((*it))->get_id().toStdString() << std::endl;
						if((*it)->contain_header_type(Xeml::Document::Ontologies::OBO::Instance) && (*it)->contain_N_compare(Xeml::Document::Ontologies::OBO::instance_of,_contextId)){
							//std::cerr << "before allocation"  << std::endl;

							std::pair<OboTags,QString> * symbol = (*it)->get_pair(Xeml::Document::Ontologies::OBO::has_symbol);
							//std::cerr << "after allocation"  << std::endl;

							if(symbol!=NULL){
								if(_context->get_unitSet()->get_defUnit() == NULL){

									Unit * u  = new Unit();
									u->set_name((*it)->get_value(Xeml::Document::Ontologies::OBO::name));
									u->set_symbol(symbol->second);
									_context->get_unitSet()->set_defUnit(u);
								}
								else
								{
									ConvertableUnit * cu = new ConvertableUnit();
									cu->set_name((*it)->get_value(Xeml::Document::Ontologies::OBO::name));
									cu->set_symbol(symbol->second);
									cu->set_conversionString("n.a.");
									cu->set_defaultUnit(_context->get_unitSet()->get_defUnit());
									_context->get_unitSet()->get_convUnits()->push_back(cu);
								}
							}

						}
					}
					//std::cerr << "end of create context unit set" << std::endl;


				}


				void                            OboHandler::createContextEnumeration(std::list<AttributeStore*> * _collection,VariableContextSpec  * _context,QString _contextId){
					//std::cerr << "entering create context Enum"  << std::endl;

					addEnum(_collection,_context,_contextId);
				}

				std::map<QString,ItfDynamicOntologyTerm*>           OboHandler::get_terms(){
					return this->terms;
				}
				Xeml::Document::Contracts::ItfDynamicOntologyTerm * OboHandler::findKey(Xeml::Document::BasicTerm param){
					return this->findKey(param.get_termId());
				}

				ItfDynamicOntologyTerm *        OboHandler::findKey(QString _termId){
					for(std::map<QString,ItfDynamicOntologyTerm*>::iterator it=this->terms.begin();it!=this->terms.end();++it){
						if(it->first==_termId){
							return it->second;
						}
					}
					return NULL;
				}
				//end region

				//region IhierarchicalView
				TermNode*                       OboHandler::findNode_by_id(QString termId){
					for(std::list<TermNode*>::iterator it=this->nodes->begin();it!=this->nodes->end();it++){
						if((*it)->get_term()->get_termId()==termId){
							return (*it);
						}
					}
					return NULL;
				}
				TermNode*                       OboHandler::findNode(ItfOntologyTerm *t){
					return findNode(t->get_termId());
				}
				TermNode*                       OboHandler::findNode(QString termId){

					for(std::list<TermNode*>::iterator it=this->nodes->begin();it!=this->nodes->end();it++){
						if(findNode((*it),termId)!=NULL){
							return findNode((*it),termId);
						}
					}
					return NULL;
				}
				TermNode*                       OboHandler::findNode(TermNode * start,QString termId){
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
				std::list<TermNode*>          * OboHandler::get_listNodes(){
					return this->nodes;
				}
				QString                         OboHandler::get_validation_events(){

				}

				QString                         OboHandler::get_namespaceAlias(){
					return this->nameSpaceAlias;
				}

				void                            OboHandler::set_namespaceAlias(QString _namespaceAlias){
					this->nameSpaceAlias=_namespaceAlias;
				}

				QString                         OboHandler::get_namespace(){
					return this->nameSpace;
				}

				void                            OboHandler::set_namespace(QString _namespace){
					this->nameSpace=_namespace;
				}

				bool                            OboHandler::get_autoValidation(){
					return this->autovalidation;
				}

				void                            OboHandler::set_autoValidation(bool _autovalidation){
					this->autovalidation=_autovalidation;
				}

				QString                         OboHandler::get_instanceLocation(){
					return this->instanceLocation;
				}

				void                            OboHandler::set_instanceLocation(QString _instancelocation){
					if(this->instanceLocation!=_instancelocation){
						this->instanceLocation=_instancelocation;
						this->reloadNeeded=true;
					}
				}

				OntologyLoadState               OboHandler::get_ontologyLoadState(){

				}

				QString                         OboHandler::get_ontologyLoadMessage(){
					return this->ontologyLoadMessage;
				}

				OntologyType                    OboHandler::get_ontologyType(){
					return Xeml::Document::Contracts::Environment;
				}

				void                            OboHandler::load(QString _nameSpaceAlias){
					this->load(_nameSpaceAlias,false);
				}
				bool                            OboHandler::contain(QString _TermId){
					for(std::map<QString,ItfDynamicOntologyTerm*>::iterator it=this->terms.begin();it!=this->terms.end();++it){
						if((*it).second->get_termId()==_TermId){
							return true;
						}
					}
					return false;
				}

				void                            OboHandler::process_line(const QString &)
				{

				}
				void                            OboHandler::load(QString _nameSpaceAlias, bool _force){
					if(this->nameSpaceAlias!=_nameSpaceAlias){
						this->nameSpaceAlias=_nameSpaceAlias;
						this->reloadNeeded =true;
					}
					if(this->reloadNeeded || _force){
						this->terms.clear();
						try
						{
							std::cerr << "create the download manager " << std::endl;
							downloadManager = new DownloadManager();
							QUrl tmp_url;
							std::list<AttributeStore*> * masterCollection = new std::list<AttributeStore*>();
							tmp_url=downloadManager->retrieve_ontologies_url(this->URI);
							QFile file(FileLocationPrefix);
							if(!file.exists()){
								downloadManager->download_File(tmp_url,FileLocationPrefix);
							}
							else{
								std::cerr << "Do you want to use ontologies from ressources or do you want to load new file"  << std::endl;
							}
							std::cerr << "file downloaded" <<std::endl;
							delete downloadManager;
							if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
								return;
							int lineNumber = 0;
							QTextStream in(&file);
							QString line = in.readLine();
							QStringList termlist;
							while (!line.isNull()) {
								lineNumber++;
								process_line(line);
								termlist.push_back(line);
								if (line.size()==0){

									if((termlist.size()>1) && ((termlist[0]!="format-version: 1.2") || (termlist[0]!="") || (termlist[0]!="format-version: 1.0"))){
										AttributeStore  * att = new AttributeStore(termlist);
										masterCollection->push_back(att);
									}
									else{
										//std::cerr << "attribute not build : " << termlist[0].toStdString() << std::endl;
									}

									termlist.clear();
								}

								line = in.readLine();


							}
							//assign content to headers class such as environment terms, context terms and datatype terms
							//std::cerr << "attribute store not destroy yet" << std::endl;
							doTagTypeAnnotation(masterCollection);
							//std::cerr << "attribute store not destroy yet" << std::endl;


							//copy attribute list into XeoTerms
							for(std::list<AttributeStore*>::iterator it=masterCollection->begin();it!=masterCollection->end();++it)
							{
								if((*it)->isEnvironmentVariableTerm()){
									XeoTerm * xeo = (*it)->get_term(this->nameSpace,this->nameSpaceAlias);
									if((*it)->contain(Xeml::Document::Ontologies::OBO::name)){
										xeo->set_name((*it)->get_value(Xeml::Document::Ontologies::OBO::name));
									}
									if((*it)->contain(Xeml::Document::Ontologies::OBO::def)){
										xeo->set_definition(((*it)->get_value(Xeml::Document::Ontologies::OBO::def)));
									}
									if((*it)->contain(Xeml::Document::Ontologies::OBO::_namespace)){
										xeo->set_nameSpace((*it)->get_value(Xeml::Document::Ontologies::OBO::_namespace));
									}
									if(xeo!= NULL && !contain((*it)->get_value(Xeml::Document::Ontologies::OBO::id))){
										this->terms[xeo->get_termId()]=xeo;

									}

								}
							}
							//std::cerr << "attribute store not destroy yet" << std::endl;

							for(std::map<QString,ItfDynamicOntologyTerm*>::iterator it=this->terms.begin();it!=this->terms.end();++it){
								Xeml::Document::Contracts::TermNode * tn = Xeml::Document::Contracts::TermNode::createNode(it->second);



								this->nodes->push_back(tn);

							}


							this->nodes->sort(compare_nocase_termnode);
							//std::cerr << "attribute store not destroy yet" << std::endl;

							buildContexts(masterCollection);
							//std::cerr << "attribute store not destroy yet" << std::endl;
							//if(this->ontologyType==Xeml::Document::Contracts::Environment){
							build_isa_hierarchy(masterCollection);
							//}
							//if(this->ontologyType==Xeml::Document::Contracts::EO){

							//}

							//std::cerr << "collection size :" << masterCollection->size()<< std::endl;

							addInheritedContext(masterCollection);
							//std::cerr << "collection size :" << masterCollection->size()<< std::endl;

							reloadNeeded =false;
							this->ontologyLoadState=Xeml::Document::Contracts::Loaded;
							for(std::list<AttributeStore*>::iterator it=masterCollection->begin();it!=masterCollection->end();++it){
								delete (*it);
							}
							masterCollection->clear();
							std::cerr<< "master collection clear" <<std::endl;
						}
						catch(exception ex){
							std::cout << "exception found  " << std::endl;
						}
					}
				}
			}
		}
	}
}
