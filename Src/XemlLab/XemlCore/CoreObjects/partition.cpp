#include "partition.h"
namespace Xeml{

	namespace Document{
		Partition::Partition()
		{
			this->materialCollection=new std::map<BasicTerm*,QString>();
			this->positionCollection =new std::map<BasicTerm*,QString>();
		}
		Partition::Partition(Partition & p){
			this->materialCollection=new std::map<BasicTerm*,QString>();
			this->positionCollection =new std::map<BasicTerm*,QString>();
			for(std::map<BasicTerm*,QString>::iterator it = p.get_materialCollection()->begin();it!=p.get_materialCollection()->end();++it){
				(*this->materialCollection)[(*it).first]=(*it).second;
			}
			for(std::map<BasicTerm*,QString>::iterator it = p.get_positionCollection()->begin();it!=p.get_positionCollection()->end();++it){
				(*this->positionCollection)[(*it).first]=(*it).second;
			}
			this->set_id(p.get_id());

		}
		Partition::~Partition(){
			std::cerr << "delete partition" << std::endl;
			for (std::map<BasicTerm*,QString>::iterator it=this->materialCollection->begin();it!=this->materialCollection->end();++it){
				delete static_cast<VariableTerm*>((*it).first);
			}
			std::cerr << "delete material collection" << std::endl;
			this->materialCollection->clear();
			for (std::map<BasicTerm*,QString>::iterator it=this->positionCollection->begin();it!=this->positionCollection->end();++it){
				delete static_cast<VariableTerm*>((*it).first);
			}
			std::cerr << "delete position collection" << std::endl;
			this->positionCollection->clear();
		}

		void Partition::addMaterialTerm(BasicTerm * _term){
			(*this->materialCollection)[_term]=_term->get_termId();
		}

		void Partition::addPositionTerm(BasicTerm * _term){
			(*this->positionCollection)[_term]=_term->get_termId();

		}

		int Partition::get_id(){
			return this->id;
		}

		void Partition::set_id(int _id){
			this->id=_id;
		}

		std::map<BasicTerm*,QString> * Partition::get_materialCollection(){
			return this->materialCollection;
		}

		std::map<BasicTerm*,QString> * Partition::get_positionCollection(){
			return this->positionCollection;
		}
		std::map<TaggedAnnotation*,QString> * Partition::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void Partition::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}
	}
}
