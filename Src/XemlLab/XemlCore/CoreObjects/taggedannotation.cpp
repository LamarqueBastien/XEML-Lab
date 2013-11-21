#include "taggedannotation.h"

namespace Xeml {

	namespace Document{
		TaggedAnnotation::TaggedAnnotation() {}

		TaggedAnnotation::~TaggedAnnotation(void)
		{

		}

		QString TaggedAnnotation::getAnnotation() const {
			return this->_annotation;
		}

		void TaggedAnnotation::setAnnotation(QString annotation) {
			this->_annotation = annotation;
		}

		QString TaggedAnnotation::getTag() const {
			return this->_tag;
		}

		void TaggedAnnotation::setTag(QString tag) {
			this->_tag = tag;
		}

		TaggedAnnotation::TaggedAnnotation(QString tag){
			this->_tag=tag;
		}
		TaggedAnnotation::TaggedAnnotation(QString tag, QString anno){

			this->_tag=tag;
			this->_annotation=anno;
		}

	}
}
