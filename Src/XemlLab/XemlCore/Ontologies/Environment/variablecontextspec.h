#ifndef VARIABLECONTEXTSPEC_H
#define VARIABLECONTEXTSPEC_H
#include"typespecification.h"
#include"defaultcycle.h"
#include"convertableunit.h"
#include<map>
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{

			class VariableContextSpec
			{
				private:
					TypeSpecification                * typeDefine;
					QString                        defValue;
					DefaultCycle                     * defCycle;
					QString                        name;
					std::map<QString, QString> valueLabels;
					QString                        description;
					UnitSet                          * unitSet;

				public:
					VariableContextSpec();
					~VariableContextSpec();
					TypeSpecification                * get_typeDefine();
					void                               set_typeDefine(TypeSpecification * _typedefine);
					QString                        get_defValue();
					void                               set_def_value(QString _defValue);
					DefaultCycle                     * get_defCycle();
					void                               set_defCycle(DefaultCycle * _defCycle);
					QString                        get_name();
					void                               set_name(QString _name);
					std::map<QString, QString> get_valueLabels();
					void                               set_valueLabels(std::map<QString, QString> _valueLabels);
					QString                        get_description();
					void                               set_description(QString _description);
					UnitSet                          * get_unitSet();
					void                               set_unitSet(UnitSet * _unitSet);
			};
		}
	}
}

#endif // VARIABLECONTEXTSPEC_H
