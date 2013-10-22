#ifndef TERMATTRIBUTE_H
#define TERMATTRIBUTE_H
#include<QString>

namespace Xeml{

	namespace Document{

		class TermAttribute
		{
			private:
				QString name;
				QString value;
				QString id;
			public:
				TermAttribute();
				TermAttribute( QString _name, QString _val );
				~TermAttribute();
				QString get_name();
				QString get_value();
				QString get_id();
				void    set_name(QString _name);
				void    set_value(QString _value);
				QString to_string();

		};
	}
}

#endif // TERMATTRIBUTE_H
