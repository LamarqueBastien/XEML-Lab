#include "keyword.h"
namespace Xeml {

	namespace Document{
		Keyword::Keyword()
		{
			this->value="new Keyword";
		}
		Keyword::Keyword(QString _value)
		{
			this->value=_value;
		}
		Keyword::~Keyword(void){

		}

		QString Keyword::get_value(){
			return this->value;
		}

		void Keyword::set_value(QString _value){
			this->value=_value;
		}
	}
}
