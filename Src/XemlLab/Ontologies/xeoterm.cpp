#include "xeoterm.h"
#include "Utilities.h"
using namespace Xeml::Utilities;
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{

			XeoTerm::XeoTerm() : readonlySupervisedObject(supervisedObject)
			{
				this->supervisedObject=(*new list<BasicTerm*>());
				this->prototype=NULL;
				this->contextCollection=new map<QString, VariableContextSpec*>();
			}
			XeoTerm::XeoTerm(QString _termId,
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
			XeoTerm::~XeoTerm(void){

			}

			int                                                XeoTerm::contextCount(){
				int cpt=0;
				for(std::map<QString, VariableContextSpec*>::iterator it=this->contextCollection->begin();it!=this->contextCollection->end();++it)
				{
					cpt++;
				}
				return cpt;
			}
			std::map<QString, VariableContextSpec*>      * XeoTerm::get_contextCollection(){
				return this->contextCollection;
			}
			void                                               XeoTerm::set_contextCollection(std::map<QString, VariableContextSpec*> * _contextCollection){
				this->contextCollection=_contextCollection;
			}
			int                                                XeoTerm::get_recomLevel(){
				if(this->contains("RecommendationLevel"))
				{
					return this->get_termAttributesByKey("RecommendationLevel")->get_value().toInt();
				}
				else
				{
					return 0;
				}
			}
			void                                               XeoTerm::set_recomLevel(int _recomLevel){
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
			QString                                        XeoTerm::get_groupPath(){
				return this->groupPath;
			}
			void                                               XeoTerm::set_groupPath(QString _groupPath){
				this->groupPath=_groupPath;
			}
			QString                                        XeoTerm::get_nameSpace(){
				return this->nameSpace;
			}
			void                                               XeoTerm::set_nameSpace(QString _nameSpace){
				this->nameSpace=_nameSpace;
			}
			QString                                        XeoTerm::get_name(){
				return this->name;
			}
			void                                               XeoTerm::set_name(QString _name){
				this->name=_name;
			}
			QUrl                                               XeoTerm::get_url(){
				return this->uri;
			}
			void                                               XeoTerm::set_url(QUrl _uri){
				this->uri=_uri;
			}

			//region ItfontologyTerm
			QString                                            XeoTerm::get_termId(){
				return this->termId;
			}
			std::list<BasicTerm*>                              XeoTerm::get_supervisedObject(){
				return this->supervisedObject;
			}
			BasicTerm                                        * XeoTerm::get_prototype(){
				if(this->prototype==NULL){
					this->prototype=emit_DefaultObject(false);
				}
				return this->prototype;
			}
			QString                                            XeoTerm::get_definition(){
				return this->definition;
			}
			void                                               XeoTerm::set_definition(QString _definition){
				this->definition=_definition;
			}
			bool                                               XeoTerm::contains(QString _id){
				std::map<QString,TermAttribute*>::const_iterator trouve=this->termattributecollection.find(_id);
				if (trouve==this->termattributecollection.end()){
					return false;
				}
				else{
					return true;
				}
			}
			bool                                               XeoTerm::contain(QString _context){
				std::map<QString, VariableContextSpec*>::const_iterator trouve=this->contextCollection->find(_context);

				if (trouve==this->contextCollection->end()){
					return false;
				}
				else{
					return true;
				}
			}
			void                                               XeoTerm::display_attributes(){
				for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
				{
					std::cerr << it->first.toStdString() << std::endl;
				}
			}
			TermAttribute                                    * XeoTerm::get_termAttributesByKey(QString _key){
				for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
				{
					if(it->first==_key){
						return it->second;
					}
				}
				return NULL;
			}
			void                                               XeoTerm::add_termAttribute(TermAttribute * _tA){
				this->termattributecollection[_tA->get_name()]=_tA;
			}
			void                                               XeoTerm::remove_termAttribute(QString _name){
				for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
				{
					if(it->first==_name){
						this->termattributecollection.erase(it);
					}
				}
			}
			std::map<QString,TermAttribute*>                   XeoTerm::get_termAttributeCollection(){
				return this->termattributecollection;
			}
			BasicTerm                                        * XeoTerm::emit_DefaultObject(bool supervised){
				DynamicTerm * p= new DynamicTerm(this->termId);
				p->set_name(this->name);
				p->set_namespacealias(this->nameSpaceAlias);
				p->set_namespace(this->nameSpace);
				for(std::map<QString, VariableContextSpec*>::iterator it=this->contextCollection->begin();it!=this->contextCollection->end();++it){
					if(this->hasDefaultCycle((*it).second->get_name())){
						p->get_dynamicvaluecollection()->push_back(make_pair(this->defaultCycle((*it).second->get_name()),this->defaultCycle((*it).second->get_name())->get_timepoint()));
						//(*p->get_dynamicvaluecollection())[this->defaultCycle((*it).second->get_name())]=this->defaultCycle((*it).second->get_name())->get_timepoint();
					}
				}
				if(supervised)
				{
					supervise(p);
				}
				return p;
			}
			void                                               XeoTerm::supervise(BasicTerm *t){
				Q_UNUSED(t);
			}
			void                                               XeoTerm::reject_supervision(BasicTerm *t){
				Q_UNUSED(t);
			}
			void                                               XeoTerm::validate_SupervisedProperties(){

			}
			void                                               XeoTerm::push_SupervisedProperties(){

			}
			//end region

			//region itfVariableOntologyTerm
			bool                                               XeoTerm::hasDefaultValue(QString _context){

				if (this->contain(_context)){

					return !((*this->contextCollection)[_context]->get_defValue().isEmpty());// || this->contextCollection[_context]->get_defValue()==NULL
				}
				else
				{
					throw exception();
				}
			}
			bool                                               XeoTerm::hasDefaultUnit(QString _context){
				if (this->contain(_context))
				{

					VariableContextSpec * pcs = (*this->contextCollection)[_context];
					return pcs->get_unitSet()->get_defUnit() != NULL;
				}
				else
				{
					std::cerr <<"exception thrown" << std::endl;
					throw exception();
				}
			}
			QString                                        XeoTerm::defaultUnitName(QString _context){
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
			QString                                        XeoTerm::defaultUnitSymbol(QString _context){
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
			VariableDataTypes                                  XeoTerm::getDataTypes(QString _context){
				if (this->contain(_context))
				{
					return (*this->contextCollection)[_context]->get_typeDefine()->get_baseType();
				}
				else
				{
					throw exception();
				}
			}
			std::vector<std::pair<QString,QString> > * XeoTerm::listUnits(QString _context){
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
			std::vector<std::pair<QString,QString> > * XeoTerm::getEnums(QString _context){
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

			//check for Min and Max , ?????
			ValueBase                                        * XeoTerm::defaultValue(QString _context){
				return this->defaultdynamicValue(_context,QDateTime::fromString("01.00:00:00","dd.hh:mm:ss"));
			}
			//end region


			//region ItfDynamicOntologyTerm
			bool                                               XeoTerm::hasDefaultCycle(QString _context){
				if (this->contain(_context)){
					return (*this->contextCollection)[_context]->get_defCycle() != NULL;
				}
				else
				{
					throw exception();
				}
			}
			Cycle                                            * XeoTerm::defaultCycle(QString _context){
				return defaultCycle(_context,QDateTime::fromString("01.00:00:00","dd.hh:mm:ss"));
			}
			DynamicValue                                     * XeoTerm::defaultdynamicValue(QString _context, QDateTime _time){
				if(contain(_context)){
					VariableContextSpec * pcs = (*this->contextCollection)[_context];
					DynamicValue * v = new DynamicValue();
					v->set_context(_context);
					QString tmp=pcs->get_defValue();
					if((!tmp.isEmpty())||(!tmp.size()==0)){
						v->set_value(pcs->get_defValue());
					}
					else
					{
						if(this->hasDefaultCycle(_context))
						{
							v->set_value(static_cast<DynamicValue*>(this->defaultCycle(_context)->get_cycleValues()->front().first)->get_value());
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
									v->set_value("");
									break;

							}
						}
					}
					if(pcs->get_unitSet()->get_defUnit()!=NULL)
					{
						v->set_unit(pcs->get_unitSet()->get_defUnit()->get_symbol());
					}
					v->set_timepoint(_time);
					return v;
				}
				else{
					return NULL;
				}



			}
			Cycle                                            * XeoTerm::defaultCycle(QString _context, QDateTime _time){
				if(contain(_context)){
					VariableContextSpec * pcs = (*this->contextCollection)[_context];
					if(pcs->get_defCycle()!=NULL){
						Cycle * v = new Cycle();
						v->set_context(_context);
						for(std::list<std::pair<QDateTime, QString> >::iterator it = pcs->get_defCycle()->get_vals()->begin();it!=pcs->get_defCycle()->get_vals()->end();++it)
						{
							std::pair<DynamicValueBase*,QDateTime> p =std::make_pair(new DynamicValue(it->first,it->second),_time);
							v->add_cycleValue(p);
						}
						if(pcs->get_unitSet()->get_defUnit()!=NULL)
						{
							v->set_unit(pcs->get_unitSet()->get_defUnit()->get_symbol());
						}
						v->set_timepoint(_time);
						return v;
					}
					else
						return NULL;
				}
				else{
					return NULL;
				}
			}

			//end region
		}
	}
}
