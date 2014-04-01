#include "individualspool.h"

namespace Xeml{

	namespace Document{


		IndividualsPool::IndividualsPool()
		{
			this->ns="none";
			this->germplasm="none";
			this->individualscollection=new std::map<Individual*,int>();
		}
		IndividualsPool::~IndividualsPool(void)
		{
			for (std::map<Individual*,int>::iterator it =this->individualscollection->begin();it!=this->individualscollection->end();++it){
				delete (*it).first;
			}
			for (std::map<TaggedAnnotation*,QString>::iterator it=this->TaggedannotationCollection->begin();it!=this->TaggedannotationCollection->end();++it){
				delete (*it).first;
			}
			this->TaggedannotationCollection->clear();
			this->individualscollection->clear();
			std::cerr << "individualpools destroyed" << std::endl;
		}

		void IndividualsPool::add_Individual(Individual * _individual){
			(*this->individualscollection)[_individual]=_individual->get_id();
		}
		void IndividualsPool::remove_Individual(int _individualId){
			std::map<Individual*,int>::iterator it_to_erase;
			for( this->it = this->individualscollection->begin(); this->it != this->individualscollection->end(); this->it++ ) {
				if(this->it->first->get_id()==_individualId){
					delete this->it->first;
					it_to_erase=it;
				}
			}
			this->individualscollection->erase(it_to_erase);



		}

		void IndividualsPool::display_all_individuals(){
			std::cerr << "there is " << this->individualscollection->size() << " individuals" << std::endl;
			for( this->it = this->individualscollection->begin(); this->it != this->individualscollection->end(); this->it++ ) {
				std::cerr << "individual identifier ="<< this->it->first->get_id()<<std::endl;
			}
		}
		int IndividualsPool::count_individuals(){
			int cpt =0;
			for( this->it = this->individualscollection->begin(); this->it != this->individualscollection->end(); this->it++ ) {
				cpt++;
			}
			return cpt;
		}
		std::map<Individual*,int> * IndividualsPool::get_individualscollection(){
			return this->individualscollection;
		}
		std::map<Individual*,int>::iterator IndividualsPool::get_iterator(){
			return this->it;
		}

		QString IndividualsPool::get_ns(){
			return this->ns;
		}
		QString IndividualsPool::get_germplasm(){
			return this->germplasm;
		}
		void									IndividualsPool::set_ns(QString _nameSpace){
			this->ns=_nameSpace;
		}

		void									IndividualsPool::set_germplasm(QString _germplasm){
			this->germplasm=_germplasm;
		}

		std::map<TaggedAnnotation*,QString> * IndividualsPool::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void IndividualsPool::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}
		QString								    IndividualsPool::getFqName(){
			return buildFqName(this->ns,this->germplasm);
		}

		void									IndividualsPool::setFqName(QString _fqName){
			QStringList list = _fqName.split(":");

			if(list.length()!=2){
				std::cerr << "the value has the wrong format" << std::endl;
			}
			else{
				this->ns=list.at(0);
				this->germplasm=list.at(1);
			}

		}

		QString									IndividualsPool::buildFqName(QString _namespace,QString _name){
			if(((_namespace.isEmpty()) || (_namespace.isNull())) || _namespace.toLower() == "none"){
				return _name;
			}
			else{
				return _namespace+":"+_name;
			}
		}
		Individual *                            IndividualsPool::find(int _Id){
			for( this->it = this->individualscollection->begin(); this->it != this->individualscollection->end(); this->it++ ) {
				if(this->it->second==_Id){
					return this->it->first;
				}
			}
			return NULL;

		}
    }
}
