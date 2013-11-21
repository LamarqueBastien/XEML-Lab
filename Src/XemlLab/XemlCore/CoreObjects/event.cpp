#include "event.h"


namespace Xeml {

	namespace Document{

		Event::Event()
		{
		}
		Event::~Event(void)
		{
			for (std::map<TaggedAnnotation*,QString>::iterator it=this->TaggedannotationCollection->begin();it!=this->TaggedannotationCollection->end();++it){
				delete (*it).first;
			}
			this->TaggedannotationCollection->clear();
		}
		Event::Event(QDateTime _timepoint)
		{
			this->timepoint=_timepoint;
		}
		QString Event::get_label(){
			return this->label;
		}

		QDateTime  Event::get_timepoint(){
			return this->timepoint;
		}

		void Event::set_label(QString _label){
			this->label=_label;
		}

		void Event::set_timepoint(QDateTime _timepoint){

			std::cerr << "set timepoint " << std::endl;
			this->timepoint=_timepoint;
			std::cerr << "set timepoint " << std::endl;

		}
		std::map<TaggedAnnotation*,QString> * Event::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void Event::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}
	}
}


