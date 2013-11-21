#ifndef DYNAMICVALUE_H
#define DYNAMICVALUE_H
#include<QString>
#include"dynamicvaluebase.h"
#include"timespan.h"
//#include"Utilities.h"
//using namespace Xeml::Utilities;
namespace Xeml{

	namespace Document{

		class DynamicValue : public DynamicValueBase
		{
			private:
				QString    value;
				bool       isCycleValue;
			public:
				DynamicValue();
				~DynamicValue();
				DynamicValue(QDateTime ts, QString val);
				QString    get_value();
				void       set_value(QString _value);
				bool       get_is_cyclevalue();
				void       set_is_cyclevalue(bool _iscyclevalue);
				QDateTime  get_timepoint();
				void       set_timepoint(QDateTime _timepoint);
				double     get_doubleValue();
				void       set_doubleValue(double _value);
				bool       get_booleanValue();
				void       set_booleanValue(bool _value);
		};
	}
}

#endif // DYNAMICVALUE_H
