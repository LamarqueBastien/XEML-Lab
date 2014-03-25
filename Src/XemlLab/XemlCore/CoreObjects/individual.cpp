#include "individual.h"

namespace Xeml {

	namespace Document{


		Individual::Individual()
		{
			this->IsDestroyed=false;
		}
		Individual::Individual(int _id){
			this->id=_id;
			this->IsDestroyed=false;
		}
		Individual::~Individual(void)
		{
			for (std::map<TaggedAnnotation*,QString>::iterator it=this->TaggedannotationCollection->begin();it!=this->TaggedannotationCollection->end();++it){
				delete (*it).first;
			}
			this->TaggedannotationCollection->clear();
			std::cerr << "Individual destroyed" << std::endl;
		}

		bool Individual::is_destroyed(){
			return this->IsDestroyed;
		}

		void Individual::set_is_destroyed(bool _IsDestroyed){
			this->IsDestroyed=_IsDestroyed;
		}

		int Individual::get_id(){
			return this->id;
		}

		void Individual::set_id(int _id){
			this->id=_id;
		}
		std::map<TaggedAnnotation*,QString> * Individual::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void Individual::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}

	}
}

