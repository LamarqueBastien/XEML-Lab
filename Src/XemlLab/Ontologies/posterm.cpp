#include "posterm.h"
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace Positionning{
				PosTerm::PosTerm() : readonlySupervisedObject(supervisedObject)
				{
					this->supervisedObject=(*new list<BasicTerm*>());
					this->prototype=NULL;
					this->contextCollection=new map<QString, VariableContextSpec*>();
				}
				PosTerm::PosTerm(QString _termId,
								 QString _nameSpace,
								 QString _nameSpaceAlias)
					: readonlySupervisedObject(supervisedObject)
				{
					this->termId=_termId;
					this->nameSpace=_nameSpace;
					this->nameSpaceAlias=_nameSpaceAlias;
					this->supervisedObject=(*new list<BasicTerm*>());
					this->prototype=NULL;
					this->contextCollection=new map<QString, VariableContextSpec*>();
				}
				PosTerm::~PosTerm(void){
					std::cerr << "delete pos term" << std::endl;
				}

				QUrl                                               PosTerm::get_url(){
					return this->uri;
				}


				void                                               PosTerm::set_url(QUrl _uri){
					this->uri=_uri;
				}

				int                                                PosTerm::contextCount(){
					int cpt=0;
					for(std::map<QString, VariableContextSpec*>::iterator it=this->contextCollection->begin();it!=this->contextCollection->end();++it)
					{

						cpt++;
					}
					return cpt;
				}

				std::map<QString, VariableContextSpec*>      * PosTerm::get_contextCollection(){
					return this->contextCollection;
				}

				int                                                PosTerm::get_recomLevel(){
					if(this->contains("RecommendationLevel"))
					{
						return this->get_termAttributesByKey("RecommendationLevel")->get_value().toInt();
					}
					else
					{
						return 0;
					}
				}

				void                                               PosTerm::set_recomLevel(int _recomLevel){
					if(!this->contains("RecommendationLevel"))
					{


						this->add_termAttribute(new TermAttribute(QString("RecommendationLevel"), QString(to_string(_recomLevel).c_str())));
					}
					else
					{
						this->remove_termAttribute("RecommendationLevel");
						this->add_termAttribute(new TermAttribute(QString("RecommendationLevel"), QString(to_string(_recomLevel).c_str())));
					}
				}

				void                                               PosTerm::set_contextCollection(std::map<QString, VariableContextSpec*> * _contextCollection){
					this->contextCollection=_contextCollection;
				}

				QString                                        PosTerm::get_nameSpace(){
					return this->nameSpace;
				}

				void                                               PosTerm::set_nameSpace(QString _nameSpace){
					this->nameSpace=_nameSpace;
				}

				QString                                        PosTerm::get_name(){
					return this->name;
				}

				void                                               PosTerm::set_name(QString _name){
					this->name=_name;
				}

				QString                                        PosTerm::get_groupPath(){
					return this->groupPath;
				}

				void                                               PosTerm::set_groupPath(QString _groupPath){
					this->groupPath=_groupPath;
				}


				//region ItfontologyTerm


				QString                                            PosTerm::get_termId(){
					return this->termId;
				}

				std::list<BasicTerm*>                              PosTerm::get_supervisedObject(){
					return this->supervisedObject;
				}

				BasicTerm                                        * PosTerm::get_prototype(){
					//std::cerr << "entering get_prototype (posterm)" << std::endl;
					if(this->prototype==NULL){
						this->prototype=emit_DefaultObject(false);
					}
					//std::cerr << "prototype label : " << this->prototype->get_name().toStdString() << std::endl;
					return this->prototype;
				}

				QString                                            PosTerm::get_definition(){
					return this->definition;
				}

				void                                               PosTerm::set_definition(QString _definition){
					this->definition=_definition;
				}

				bool                                               PosTerm::contains(QString _id){
					std::map<QString,TermAttribute*>::const_iterator trouve=this->termattributecollection.find(_id);
					if (trouve==this->termattributecollection.end()){
						return false;
					}
					else{
						return true;
					}
				}

				bool                                               PosTerm::contain(QString _context){
					std::map<QString, VariableContextSpec*>::const_iterator trouve=this->contextCollection->find(_context);

					if (trouve==this->contextCollection->end()){
						return false;
					}
					else{
						return true;
					}
				}

				void                                               PosTerm::display_attributes(){
					for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
					{
						std::cerr << it->first.toStdString() << std::endl;
					}
				}

				TermAttribute                                    * PosTerm::get_termAttributesByKey(QString _key){
					for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
					{
						if(it->first==_key){
							return it->second;
						}
					}
					return NULL;
				}

				void                                               PosTerm::add_termAttribute(TermAttribute * _tA){
					this->termattributecollection[_tA->get_name()]=_tA;
				}

				void                                               PosTerm::remove_termAttribute(QString _name){
					for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
					{
						if(it->first==_name){
							this->termattributecollection.erase(it);
						}
					}
				}

				std::map<QString,TermAttribute*>                   PosTerm::get_termAttributeCollection(){
					return this->termattributecollection;
				}

				BasicTerm                                        * PosTerm::emit_DefaultObject(bool supervised){
					//std::cerr << "entering emit default object (posterm)" << std::endl;
					VariableTerm * p= new VariableTerm(this->termId);
					p->set_name(this->name);
					p->set_namespacealias(this->nameSpaceAlias);
					p->set_namespace(this->nameSpace);
					for(std::map<QString, VariableContextSpec*>::iterator it=this->contextCollection->begin();it!=this->contextCollection->end();++it){
						//std::cerr << "entering boucle for (posterm)" << std::endl;
						//std::cerr << "var context unit : "<<this->defaultValue((*it).second->get_name())->get_unit().toStdString() << std::endl;
						//std::cerr << "entering boucle for (posterm)" << std::endl;
						//if(this->hasDefaultCycle((*it).second->get_name())){
						(*p->get_valuecollection())[this->defaultValue((*it).second->get_name())]=(*it).second->get_name();
						//}
					}
					//std::cerr << "outing boucle for (posterm)" << std::endl;

					if(supervised)
					{
						supervise(p);
					}
					return p;
				}

				void                                               PosTerm::supervise(BasicTerm *t){

				}

				void                                               PosTerm::reject_supervision(BasicTerm *t){

				}

				void                                               PosTerm::validate_SupervisedProperties(){

				}

				void                                               PosTerm::push_SupervisedProperties(){

				}

				//end region

				//region itfVariableOntologyTerm

				bool                                               PosTerm::hasDefaultValue(QString _context){
					if (this->contain(_context)){
						return !((*this->contextCollection)[_context]->get_defValue().isEmpty());// || this->contextCollection[_context]->get_defValue()==NULL
					}
					else
					{
						throw exception();
					}
				}

				bool                                               PosTerm::hasDefaultUnit(QString _context){
					//std::cerr << "entering pcs has default unit (posterm): " << std::endl;

					if (this->contain(_context))
					{

						//std::cerr << "entering contain context in has default unit (posterm)" << std::endl;
						//std::cerr << "-context collection size (posterm) : " << this->contextCollection->size() << std::endl;
						VariableContextSpec * pcs = (*this->contextCollection)[_context];
						//std::cerr << "-pcs name (posterm) : " << pcs->get_name() << std::endl;
						//if(pcs->get_unitSet()->get_defUnit() != NULL){
							//std::cerr << "pcs->get_unitSet()->get_defUnit() != NULL" << std::endl;
						//}
						//else{
							//std::cerr << "pcs->get_unitSet()->get_defUnit() == NULL" << std::endl;

						//}
						return pcs->get_unitSet()->get_defUnit() != NULL;
					}
					else
					{
						std::cerr <<"exception thrown" << std::endl;
						throw exception();
					}
				}

				QString                                        PosTerm::defaultUnitName(QString _context){
					if(this->hasDefaultUnit(_context))
					{
						VariableContextSpec * pcs = (*this->contextCollection)[_context];
						return pcs->get_unitSet()->get_defUnit()->get_name();
					}
					else
					{
						return NULL;
					}
				}

				QString                                        PosTerm::defaultUnitSymbol(QString _context){
					if(this->hasDefaultUnit(_context))
					{
						VariableContextSpec * pcs = (*this->contextCollection)[_context];
						return pcs->get_unitSet()->get_defUnit()->get_symbol();
					}
					else
					{
						return NULL;
					}
				}

				VariableDataTypes                                  PosTerm::getDataTypes(QString _context){
					if (this->contain(_context))
					{
						return (*this->contextCollection)[_context]->get_typeDefine()->get_baseType();
					}
					else
					{
						throw exception();
					}
				}

				std::vector<std::pair<QString,QString> > * PosTerm::listUnits(QString _context){
					if (this->contain(_context))
					{
						std::vector<std::pair<QString,QString> > * ret =new std::vector<std::pair<QString,QString> >();
						VariableContextSpec * pcs = (*this->contextCollection)[_context];
						if(pcs!=NULL)
						{
							if(pcs->get_unitSet()->get_defUnit()!=NULL)
							{
								ret->push_back(std::make_pair(pcs->get_unitSet()->get_defUnit()->get_name(),pcs->get_unitSet()->get_defUnit()->get_symbol()));
							}
							for(std::list<ConvertableUnit*>::iterator it=pcs->get_unitSet()->get_convUnits()->begin();it!=pcs->get_unitSet()->get_convUnits()->end();++it)
							{
								ret->push_back(std::make_pair((*it)->get_name(),(*it)->get_symbol()));
							}
						}
						return ret;
					}
					else
					{
						throw exception();
					}
				}

				std::vector<std::pair<QString,QString> > * PosTerm::getEnums(QString _context){
					if (this->contain(_context)){
						std::vector<std::pair<QString,QString> > * ret =new std::vector<std::pair<QString,QString> >();
						VariableContextSpec * pcs = (*this->contextCollection)[_context];
						for(std::list<Enum*>::iterator it=pcs->get_typeDefine()->get_listEnums().begin();it!=pcs->get_typeDefine()->get_listEnums().end();++it){
							ret->push_back(std::make_pair((*it)->get_textVal(),(*it)->get_textVal()));
						}
						return ret;
					}
					else{
						throw exception();
					}
				}

				QStringList                                      * PosTerm::GroupLevels(){
					QStringList  * tmplist= new QStringList();
					if(this->groupPath.count(".")!=0){
						(*tmplist)=this->groupPath.split(".");//,QString::SkipEmptyParts);
					}
					else{
						tmplist->append(this->groupPath);
					}

					return tmplist;
				}

				//ValueBase                                        * PosTerm::defaultValue(QString context){
				//	return this->defaultdynamicValue(_context,new TimeSpan(0,0,0,0));
				//}
				ValueBase                                     * PosTerm::defaultValue(QString _context){
					//std::cerr << "entering default value (posterm)" << std::endl;
					if(contain(_context)){
						//std::cerr << "entering contain context (posterm)" << std::endl;
						VariableContextSpec * pcs = (*this->contextCollection)[_context];
						//std::cerr << "pcs name(posterm): " << pcs->get_name()<< std::endl;
						Value * v = new Value();
						v->set_context(_context);
						QString tmp=pcs->get_defValue();
						if(this->hasDefaultValue(_context))
						{
							//std::cerr << "entering pcs has default value (posterm): " << pcs->get_defValue()<< std::endl;
							v->set_value(pcs->get_defValue());
						}
						else
						{
							switch (pcs->get_typeDefine()->get_baseType())
							{
								case Xeml::Document::Number:
								{
									v->set_doubleValue(0.0);
									break;
								}
								case Xeml::Document::Text:
									{
									v->set_value("");
									break;
								}
								case Xeml::Document::Bool:
								{
									v->set_booleanValue(false);
									break;
								}
								default:
								{
									v->set_value("");
									break;
								}

							}
						}
						//std::cerr << "before pcs has defaultunit (posterm): " << std::endl;

						//if(pcs->get_unitSet()->get_defUnit()!=NULL)
						if(hasDefaultUnit(_context))
						{
							//std::cerr << "has defaultunit true (posterm): " << std::endl;
							v->set_unit(pcs->get_unitSet()->get_defUnit()->get_symbol());
						}
						//v->set_timepoint(new TimeSpan(0,0,0,0));
						return v;
					}

					else{
						return NULL;
					}
				}
			}
		}
	}

}
