#ifndef UNIT_H
#define UNIT_H
#include<QString>
using namespace std;
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{
			class Unit
			{
				private:
					QString name;
					QString symbol;
				public:
					Unit();
					~Unit();
					QString get_name();
					QString get_symbol();
					void        set_name(QString _name);
					void        set_symbol(QString _symbol);
			};
		}
	}
}
#endif // UNIT_H
