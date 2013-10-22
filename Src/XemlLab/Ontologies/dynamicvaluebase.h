#ifndef DYNAMICVALUEBASE_H
#define DYNAMICVALUEBASE_H
#include"valuebase.h"
#include"timespan.h"
#include<QString>
#include<QDateTime>
namespace Xeml {

	namespace Document{

		class DynamicValueBase : public ValueBase
		{
			protected:
				QDateTime         timepoint;


			public:
				DynamicValueBase();
				~DynamicValueBase();
				QString            get_label();
				QString            get_context();
				QString            get_unit();
				void               set_label(QString _label);
				void               set_context(QString _context);
				void               set_unit(QString _unit);
				virtual QDateTime  get_timepoint()=0;
				virtual void       set_timepoint(QDateTime _timepoint)=0;
				bool    get_is_cycle();
				void    set_is_cycle(bool _iscycle);
				bool    isCycle;
		};
	}
}

#endif // DYNAMICVALUEBASE_H
