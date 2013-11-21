#ifndef STORYSPLIT_H
#define STORYSPLIT_H
#include"CoreObjects/storybase.h"
#include"Interface/itftimeobject.h"
#include"CoreObjects/timespan.h"
#include"CoreObjects/dynamicvaluebase.h"
#include"CoreObjects/dynamicterm.h"
#include<list>
#include<QDateTime>
#include<map>
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document;
namespace Xeml{
	namespace Document{

		class StorySplit : public StoryBase, public ItfTimeObject
		{
			private:

				QDateTime   timepoint;
				void        MoveValues(QDateTime oldVal,QDateTime newVal);

			public:

				StorySplit();
				~StorySplit();
				QString     get_label();
				void        set_label(QString _label);
				QDateTime   get_timepoint();
				void        set_timepoint(QDateTime _timepoint);

		};
	}
}

#endif // STORYSPLIT_H
