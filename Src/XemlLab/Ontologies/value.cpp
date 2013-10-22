#include "value.h"
#include "Utilities.h"
using namespace Xeml::Utilities;
namespace Xeml {

	namespace Document{
		Value::Value()
		{
			this->isCycle=false;
		}
		Value::~Value(void)
		{}
		Value::Value(QString _value)
		{
			this->isCycle=false;
			this->value=_value;
		}
		Value::Value(const Value& v)
		{
			this->value=v.value;
		}
		QString Value::get_val(){
			return this->value;
		}

		QString Value::get_label(){
			return this->label;
		}

		QString Value::get_context(){
			return this->context;
		}

		QString Value::get_unit(){
			return this->unit;
		}

		void Value::set_value(QString _value){
			this->value=_value;
		}

		void Value::set_label(QString _label){
			this->label=_label;
		}

		void Value::set_context(QString _context){
			this->context=_context;
		}

		void Value::set_unit(QString _unit){
			this->unit=_unit;
		}
		bool Value::get_is_cycle(){
			return this->isCycle;
		}

		void Value::set_is_cycle(bool _iscycle){
			this->isCycle=_iscycle;
		}
		double Value::get_doubleValue(){

			return String_to_double(this->value.toStdString());
		}
		void Value::set_doubleValue(double _value){
			this->value=QString(to_string(_value).c_str());
		}
		bool      Value::get_booleanValue(){
			return to_bool(this->value.toStdString());

		}

		void       Value::set_booleanValue(bool _value){
			this->value=QString(to_string(_value).c_str());
		}

	}
}

