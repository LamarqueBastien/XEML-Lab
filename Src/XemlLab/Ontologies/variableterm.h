#ifndef VARIABLETERM_H
#define VARIABLETERM_H
#include"term.h"
#include"basicterm.h"
#include"valuebase.h"
#include"value.h"
#include<string>
#include<QString>
#include<map>
using Xeml::Document::BasicTerm;

namespace Xeml {

	namespace Document{
		class VariableTerm : public BasicTerm
		{
			private:
				std::map<ValueBase*,QString> * valuecollection;
			public:
				VariableTerm();
				VariableTerm(QString _id);
				~VariableTerm();
				std::map<ValueBase*,QString> * get_valuecollection();
				void                       add_value(ValueBase * _value);

		};
	}
}

#endif // VARIABLETERM_H
