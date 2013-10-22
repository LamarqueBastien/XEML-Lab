#ifndef STORYSPLIT_H
#define STORYSPLIT_H
#include"storybase.h"
#include"itftimeobject.h"
#include"timespan.h"
#include"dynamicvaluebase.h"
#include"dynamicterm.h"
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
