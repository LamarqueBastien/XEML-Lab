#include "individual.h"

namespace Xeml {

	namespace Document{


		Individual::Individual()
		{
		}
		Individual::Individual(int _id){
			this->id=_id;
		}
		Individual::~Individual(void)
		{
			for (std::map<TaggedAnnotation*,QString>::iterator it=this->TaggedannotationCollection->begin();it!=this->TaggedannotationCollection->end();++it){
				delete (*it).first;
			}
			this->TaggedannotationCollection->clear();
			std::cerr << "Individual destroyed" << std::endl;
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
