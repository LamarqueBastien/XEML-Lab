#ifndef TYPESPECIFICSENUM_H
#define TYPESPECIFICSENUM_H
#include"typespecifics.h"

namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{

			class Enum : public TypeSpecifics
			{
				private:

					double      numberVal;
					time_t      dateVal;
					QString textVal;
					bool        booleanVal;

				public:

					Enum();
					Enum(double _value);
					Enum(QString _value);
					Enum(time_t _value);
					Enum(bool _value);
					~Enum();
					double      get_numberVal();
					void        set_numberVal(double _numberVal);
					time_t      get_dateVal();
					void        set_dateVal(time_t _dateVal);
					QString     get_textVal();
					void        set_textVal(QString _textVal);
					bool        get_booleanVal();
					void        set_booleanVal(bool _booleanVal);
			};
		}
	}
}

#endif // TYPESPECIFICSENUM_H
