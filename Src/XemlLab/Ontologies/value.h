#ifndef VALUE_H
#define VALUE_H
#include<string>
#include<QString>
#include"valuebase.h"
namespace Xeml {

	namespace Document{

		class Value : public ValueBase
		{
			private:

				QString value;
				bool    isCycle;
				//ValueCollection collection;
			public:

				Value();
				Value(QString _value);
				Value(const Value& v);
				~Value();

				QString get_val();
				QString get_label();
				QString get_context();
				QString get_unit();
				void    set_value(QString _value);
				void    set_label(QString _label);
				void    set_context(QString _context);
				void    set_unit(QString _unit);
				bool    get_is_cycle();
				void    set_is_cycle(bool _iscycle);
				double     get_doubleValue();
				void       set_doubleValue(double _value);
				bool       get_booleanValue();
				void       set_booleanValue(bool _value);

		};
	}
}

#endif // VALUE_H

