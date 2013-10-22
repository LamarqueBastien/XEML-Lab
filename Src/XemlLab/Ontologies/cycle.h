#ifndef CYCLE_H
#define CYCLE_H
#include<QString>
#include<map>
#include<list>
#include<vector>
using std::pair;
using std::make_pair;
#include"dynamicvaluebase.h"
#include"timespan.h"

namespace Xeml{

	namespace Document{

		class Cycle : public DynamicValueBase
		{
			private:
				std::vector<std::pair<DynamicValueBase*,QDateTime> > * values;
				//the sum of the values used in this cycle
				QDateTime                                               length;
				bool                                                   isCycle;
			public:
				Cycle();
				~Cycle();
				QDateTime                                              get_timepoint();
				void                                                   set_timepoint(QDateTime _timepoint);
				QDateTime                                              get_length();
				std::vector<std::pair<DynamicValueBase*,QDateTime> > * get_cycleValues();
				void                                                   add_cycleValue(std::pair<DynamicValueBase*,QDateTime> p);
				bool                                                   get_is_cycle();
				void                                                   set_is_cycle(bool _iscycle);
		};
	}
}

#endif // CYCLE_H
