#include "convertableunit.h"
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{
			ConvertableUnit::ConvertableUnit()
			{
				this->defaultUnit=NULL;
			}
			ConvertableUnit::~ConvertableUnit(void){

			}

			QString ConvertableUnit::get_conversionString(){
				return this->conversionString;
			}

			Unit * ConvertableUnit::get_defaultUnit(){
				return this->defaultUnit;
			}

			void ConvertableUnit::set_conversionString(QString _conversionString){
				this->conversionString=_conversionString;
			}

			void ConvertableUnit::set_defaultUnit(Unit * _defaultUnit){
				this->defaultUnit=_defaultUnit;
			}
			UnitSet::UnitSet(){
				this->convUnits=new list<ConvertableUnit*>();
				this->defUnit=NULL;
			}

			std::list<ConvertableUnit*> * UnitSet::get_convUnits(){
				return this->convUnits;
			}

			Unit * UnitSet::get_defUnit(){
				return this->defUnit;
			}

			void UnitSet::set_defUnit(Unit * _defUnit){
				this->defUnit=_defUnit;
			}

			QString UnitSet::get_name(){
				return this->name;
			}

			void UnitSet::set_name(QString _name){
				this->name=_name;
			}
		}
	}
}
