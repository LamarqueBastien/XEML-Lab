#ifndef KEYWORD_H
#define KEYWORD_H
#include<QString>

namespace Xeml {

	namespace Document{

		class Keyword
		{
			private:
				QString value;
			public:
				Keyword();
				Keyword(QString _value);
				~Keyword();
				QString get_value();
				void    set_value(QString _value);
		};
	}
}

#endif // KEYWORD_H
