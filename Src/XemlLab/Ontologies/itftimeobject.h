#ifndef ITFTIMEOBJECT_H
#define ITFTIMEOBJECT_H
//#include<ctime>
#include"timespan.h"
#include<QDateTime>

namespace Xeml {

	namespace Document{

		namespace Contracts{

			class ItfTimeObject
			{


				public:
					ItfTimeObject();
					virtual QDateTime  get_timepoint()=0;
					virtual void       set_timepoint(QDateTime  _timepoint)=0;
			};
		}
	}
}
#endif // ITFTIMEOBJECT_H
