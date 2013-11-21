#include "variablecontextspec.h"
namespace Xeml{

    namespace Document{

        namespace EnvironmentalOntology{
            VariableContextSpec::VariableContextSpec()
            {
				this->typeDefine = new TypeSpecification();
				this->unitSet=NULL;
            }
			VariableContextSpec::~VariableContextSpec(void)
			{

			}

			TypeSpecification                * VariableContextSpec::get_typeDefine()
			{
                return this->typeDefine;
            }
			void                               VariableContextSpec::set_typeDefine(TypeSpecification * _typedefine){
                this->typeDefine=_typedefine;
            }
			QString                        VariableContextSpec::get_defValue(){
                return this->defValue;
            }
			void                               VariableContextSpec::set_def_value(QString _defValue){
                this->defValue=_defValue;
            }
			DefaultCycle                     * VariableContextSpec::get_defCycle(){
                return this->defCycle;
            }
			void                               VariableContextSpec::set_defCycle(DefaultCycle * _defCycle){
                this->defCycle=_defCycle;
            }
			QString                        VariableContextSpec::get_name(){
                return this->name;
            }
			void                               VariableContextSpec::set_name(QString _name){
                this->name=_name;
            }
			std::map<QString, QString> VariableContextSpec::get_valueLabels(){
                return this->valueLabels;
            }
			void                               VariableContextSpec::set_valueLabels(std::map<QString, QString> _valueLabels){
                this->valueLabels=_valueLabels;
            }
			QString                        VariableContextSpec::get_description(){
                return this->description;
            }
			void                               VariableContextSpec::set_description(QString _description){
                this->description=_description;
            }
			UnitSet                          * VariableContextSpec::get_unitSet(){
                return this->unitSet;
            }
			void                               VariableContextSpec::set_unitSet(UnitSet * _unitSet){
                this->unitSet=_unitSet;
            }
        }
    }
}
