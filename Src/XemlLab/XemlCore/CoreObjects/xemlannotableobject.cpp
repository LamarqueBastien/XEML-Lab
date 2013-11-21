#include "xemlannotableobject.h"

namespace Xeml {

	namespace Document{
		XemlAnnotableObject::XemlAnnotableObject()
		{
			this->TaggedannotationCollection=new std::map<TaggedAnnotation*,QString>();

		}
		XemlAnnotableObject::~XemlAnnotableObject(void)
		{

		}

		void XemlAnnotableObject::display_all_tags(){
			for( this->it = this->TaggedannotationCollection->begin(); this->it != this->TaggedannotationCollection->end(); this->it++ ) {

				std::cout <<this->it->first->getTag().toStdString()<<std::endl;
			}
		}
		void XemlAnnotableObject::display_specific_tag(TaggedAnnotation* TA){
			for( this->it = this->TaggedannotationCollection->begin(); this->it != this->TaggedannotationCollection->end(); this->it++ ) {
				if(TA->getTag()==this->it->first->getTag()){

					std::cout <<this->it->first->getTag().toStdString()<<std::endl;
				}
			}
		}
		bool XemlAnnotableObject::contains(TaggedAnnotation* TA){
			for( this->it = this->TaggedannotationCollection->begin(); this->it != this->TaggedannotationCollection->end(); this->it++ ) {
				if(TA->getTag()==this->it->first->getTag() && TA->getAnnotation()==this->it->first->getAnnotation()){

					return true;

				}

			}
			return false;
		}
		bool XemlAnnotableObject::contain(QString _tag){
			for( this->it = this->TaggedannotationCollection->begin(); this->it != this->TaggedannotationCollection->end(); ++(this->it)){
				if(this->it->second == _tag){
					return true;
				}
			}
			return false;
		}
	}
}
