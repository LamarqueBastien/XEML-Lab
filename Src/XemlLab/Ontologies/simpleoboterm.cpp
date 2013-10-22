#include "simpleoboterm.h"
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			SimpleOboTerm::SimpleOboTerm(): readonlySupervisedObject(supervisedObject)
			{

			}
			SimpleOboTerm::SimpleOboTerm(QString _termId): readonlySupervisedObject(supervisedObject)
			{
				this->termId = _termId;
				this->oboTagValuePair=new list<pair<QString,QString> >();
				this->prototype=NULL;
			}
			SimpleOboTerm::~SimpleOboTerm(void){
				std::cerr << "delete simple oboterm" << std::endl;
				this->oboTagValuePair->clear();
				if(this->prototype!=NULL){
					delete this->prototype;
				}
			}

			std::map<QString,TermAttribute*> SimpleOboTerm::get_termAttributeCollection(){
				return this->termattributecollection;
			}

			QString SimpleOboTerm::get_termId(){
				return this->termId;
			}
			void SimpleOboTerm::set_termId(QString _termId){
				this->termId=_termId;
			}
			TermAttribute* SimpleOboTerm::get_termAttributesByKey(QString _key){
				for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
				{
					if(it->first==_key){
						return it->second;
					}
				}
				return NULL;
			}

			void SimpleOboTerm::display_attributes(){
				for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
				{
					std::cerr << it->first.toStdString() << std::endl;
				}
			}

			bool SimpleOboTerm::contains(QString _id){
				std::map<QString,TermAttribute*>::const_iterator trouve=this->termattributecollection.find(_id);
				if (trouve==this->termattributecollection.end()){
					return false;
				}
				else{
					return true;
				}
			}
			void SimpleOboTerm::add_termAttribute(TermAttribute * _tA){
				this->termattributecollection[_tA->get_name()]=_tA;
			}
			void                                             SimpleOboTerm::remove_termAttribute(QString _name){
				for(std::map<QString,TermAttribute*>::iterator it=this->termattributecollection.begin();it!=this->termattributecollection.end();++it)
				{
					if(it->first==_name){
						this->termattributecollection.erase(it);
					}
				}
			}

			std::list<BasicTerm*> SimpleOboTerm::get_supervisedObject(){
				return this->supervisedObject;
			}

			BasicTerm * SimpleOboTerm::get_prototype(){
				if(this->prototype==NULL){
					this->prototype=emit_DefaultObject(false);
				}
				return this->prototype;
			}

			QString SimpleOboTerm::get_definition(){
				return this->definition;
			}
			void SimpleOboTerm::set_definition(QString _definition){
				this->definition= _definition;
			}

			BasicTerm *  SimpleOboTerm::emit_DefaultObject(bool supervised){
				BasicTerm * m= new BasicTerm(this->termId);
				m->set_name(this->name);
				m->set_namespacealias(this->nameSpaceAlias);
				m->add_tagged_annotation(new TaggedAnnotation("def",this->get_definition()));
				for( this->it = this->oboTagValuePair->begin(); this->it!=this->oboTagValuePair->end(); ++this->it)
				{
					m->add_tagged_annotation(new TaggedAnnotation(it->first,it->second));
				}
				return m;
			}


			void SimpleOboTerm::supervise(BasicTerm *t){
				if(t->get_termId()==this->termId){
					if(!contains(t)){
						this->supervisedObject.push_back(t);
					}
				}
				else{
					throw new std::exception();
				}
			}

			void SimpleOboTerm::reject_supervision(BasicTerm *t){
				if(contains(t)){
					remove(t);
				}
			}

			void SimpleOboTerm::validate_SupervisedProperties(){

			}

			void SimpleOboTerm::push_SupervisedProperties(){

			}
			std::list<std::pair<QString,QString> > * SimpleOboTerm::get_oboTagValuePair(){
				return this->oboTagValuePair;
			}

			QString SimpleOboTerm::get_name(){
				return this->name;
			}

			void SimpleOboTerm::set_name(QString _name)
			{
				this->name=_name;
			}
			QString SimpleOboTerm::get_nameSpace(){
				return this->nameSpace;
			}

			void SimpleOboTerm::set_nameSpace(QString _nameSpace){
				this->nameSpace=_nameSpace;
			}

			QString SimpleOboTerm::get_nameSpaceAlias(){
				return this->nameSpaceAlias;
			}

			void SimpleOboTerm::set_nameSpaceAlias(QString _nameSpaceAlias){
				this->nameSpaceAlias=_nameSpaceAlias;
			}
			void SimpleOboTerm::remove(Xeml::Document::BasicTerm * _t){
				std::list<BasicTerm*>::iterator it =this->supervisedObject.begin();
				for(;it!=this->supervisedObject.end();++it){
					if(_t->get_termId().toStdString()==(*it)->get_termId().toStdString()){
						this->supervisedObject.erase(it);
					}
				}
			}

			bool SimpleOboTerm::contains(Xeml::Document::BasicTerm * _t){
				std::list<BasicTerm*>::iterator it =this->supervisedObject.begin();
				for(;it!=this->supervisedObject.end();++it){
					if(_t->get_termId().toStdString()==(*it)->get_termId().toStdString()){
						return true;
					}

				}
				return false;
			}
		}
	}
}
