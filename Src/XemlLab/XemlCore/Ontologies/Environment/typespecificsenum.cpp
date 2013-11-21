#include "typespecificsenum.h"
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{

			Enum::Enum() : TypeSpecifics()
			{
			}
			Enum::Enum(double _value){
				this->set_numberVal(_value);
			}

			Enum::Enum(QString _value){
				this->set_textVal(_value);
			}

			Enum::Enum(time_t _value){
				this->set_dateVal(_value);
			}

			Enum::Enum(bool _value){
				this->set_booleanVal(_value);
			}
			Enum::~Enum(void){

			}

			double Enum::get_numberVal(){
				return this->numberVal;
			}

			void Enum::set_numberVal(double _numberVal){
				this->numberVal=_numberVal;
			}

			time_t Enum::get_dateVal(){
				return this->dateVal;
			}

			void Enum::set_dateVal(time_t _dateVal){
				this->dateVal=_dateVal;
			}

			QString Enum::get_textVal(){
				return this->textVal;
			}

			void Enum::set_textVal(QString _textVal){
				this->textVal=_textVal;
			}

			bool Enum::get_booleanVal(){
				return this->booleanVal;
			}

			void Enum::set_booleanVal(bool _booleanVal){
				this->booleanVal=_booleanVal;
			}

			//see if we need to add the function Match?? probably
		}
	}
}
