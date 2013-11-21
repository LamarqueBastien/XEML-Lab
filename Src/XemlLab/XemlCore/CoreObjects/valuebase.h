#ifndef VALUEBASE_H
#define VALUEBASE_H
#include<string>
#include<QString>
namespace Xeml {

	namespace Document{

		class ValueBase
		{
			protected:
				QString         context;
				QString         unit;
				QString         label;
			public:
				ValueBase();
				//ValueBase(QString _context);

				//ValueBase(const ValueBase& vb);
				virtual ~ValueBase();
				virtual QString get_label()=0;
				virtual QString get_context()=0;
				virtual QString get_unit()=0;
				virtual void    set_label(QString _label)=0;
				virtual void    set_context(QString _context)=0;
				virtual void    set_unit(QString _unit)=0;
				virtual bool    get_is_cycle()=0;
				virtual void    set_is_cycle(bool _iscycle)=0;
		};
	}
}

#endif // VALUEBASE_H

