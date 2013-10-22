#include "dynamicvalue.h"
#include "Utilities.h"
using namespace Xeml::Utilities;

namespace Xeml{

	namespace Document{
		DynamicValue::DynamicValue()
			:DynamicValueBase()
		{
			this->isCycle=false;
			//this->timepoint=NULL;
		}
		DynamicValue::DynamicValue(QDateTime _ts, QString _val)
			:DynamicValueBase()
		{
			this->isCycle=false;
			this->timepoint=_ts;
			this->value=_val;
		}
		DynamicValue::~DynamicValue(void){
			std::cerr << "delete dynamic value" << std::endl;
		}

		QString DynamicValue::get_value(){
			return this->value;
		}

		void DynamicValue::set_value(QString _value){
			this->value=_value;
		}

		bool DynamicValue::get_is_cyclevalue(){
			return this->isCycleValue;
		}

		void DynamicValue::set_is_cyclevalue(bool _iscyclevalue){
			this->isCycleValue=_iscyclevalue;
		}
		QDateTime DynamicValue::get_timepoint(){
			return this->timepoint;
		}

		void DynamicValue::set_timepoint(QDateTime _timepoint){
			std::cerr << "duration value in set timepoint:" << _timepoint.toString("hh:mm:ss").toStdString() << std::endl;

			this->timepoint=_timepoint;
		}
		double DynamicValue::get_doubleValue(){

			return String_to_double(this->value.toStdString());
		}
		void DynamicValue::set_doubleValue(double _value){
			this->value=QString(to_string(_value).c_str());
		}
		bool       DynamicValue::get_booleanValue(){
			return to_bool(this->value.toStdString());

		}

		void       DynamicValue::set_booleanValue(bool _value){
			this->value=QString(to_string(_value).c_str());
		}

	}
}
