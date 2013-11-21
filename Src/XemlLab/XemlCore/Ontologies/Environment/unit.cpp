#include "unit.h"
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{
			Unit::Unit()
			{
			}
			Unit::~Unit(void)
			{
			}
			QString Unit::get_name(){
				return this->name;
			}

			QString Unit::get_symbol(){
				return this->symbol;
			}

			void Unit::set_name(QString _name){
				this->name=_name;
			}

			void Unit::set_symbol(QString _symbol){
				this->symbol=_symbol;
			}
		}
	}
}
