#ifndef CONVERTABLEUNIT_H
#define CONVERTABLEUNIT_H
#include"unit.h"
#include<list>
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{

			class ConvertableUnit : public Unit
			{
				private:
					QString                   conversionString;
					Unit                        * defaultUnit;
				public:
					ConvertableUnit();
					~ConvertableUnit();
					QString                   get_conversionString();
					Unit                        * get_defaultUnit();
					void                          set_conversionString(QString _conversionString);
					void                          set_defaultUnit(Unit * _defaultUnit);
			};
			class UnitSet
			{
				private:
					QString                   name;
					Unit                        * defUnit;
					std::list<ConvertableUnit*> * convUnits;

				public:
					UnitSet();
					std::list<ConvertableUnit*> * get_convUnits();
					Unit                        * get_defUnit();
					void                          set_defUnit(Unit * _defUnit);
					QString                   get_name();
					void                          set_name(QString _name);

			};
		}
	}
}

#endif // CONVERTABLEUNIT_H
