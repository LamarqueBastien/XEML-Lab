#include "termattribute.h"
namespace Xeml{

	namespace Document{

		TermAttribute::TermAttribute()
		{
		}

		TermAttribute::TermAttribute(QString _name, QString _val){
			this->name=_name;
			this->value=_val;
		}
		TermAttribute::~TermAttribute(void)
		{
		}

		QString TermAttribute::get_name(){
			return this->name;
		}

		QString TermAttribute::get_value(){
			return this->value;
		}

		QString TermAttribute::get_id(){
			QString tmp;
			tmp+=this->name;
			tmp+=":";
			tmp+=this->value;

			return tmp;
		}

		void TermAttribute::set_name(QString _name){
			this->name=_name;
		}

		void TermAttribute::set_value(QString _value){
			this->value=_value;
		}

		QString TermAttribute::to_string(){
			return this->id;
		}
	}
}
