#ifndef EVENT_H
#define EVENT_H
#include<string>
#include<map>

#include"timespan.h"
#include"xemlannotableobject.h"
#include"itftimeobject.h"
//#include"eventcollection.h"
using namespace Xeml::Document::Contracts;

//class EventCollection;

namespace Xeml {

	namespace Document{

		class Event : public XemlAnnotableObject, public ItfTimeObject
		{
			private:

				QDateTime                                  timepoint;
				QString                                    label;
			public:

				Event();
				~Event();
				Event(QDateTime  _timepoint);
				QString                                    get_label();
				QDateTime                                  get_timepoint();
				void                                       set_label(QString _label);
				void                                       set_timepoint(QDateTime _timepoint);
				std::map<TaggedAnnotation*,QString>  * get_taggedannotation();
				void                                       add_tagged_annotation(TaggedAnnotation *TA);

		};
	}
}

#endif // EVENT_H
