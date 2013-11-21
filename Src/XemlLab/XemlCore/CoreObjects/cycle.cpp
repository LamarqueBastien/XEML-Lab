#include "cycle.h"
namespace Xeml{

	namespace Document{
		Cycle::Cycle()
		{
			this->values=new std::vector<std::pair<DynamicValueBase*,QDateTime> >();
			this->isCycle=true;
		}
		Cycle::~Cycle(void){

		}

		QDateTime Cycle::get_timepoint(){
			return this->timepoint;
		}

		void Cycle::set_timepoint(QDateTime _timepoint){
			this->timepoint=_timepoint;
		}
		QDateTime Cycle::get_length(){
			QDateTime ts=QDateTime::fromString("00:00:00","hh:mm:ss");

			std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it;
			for(it=this->values->begin();it!=this->values->end();it++){
				//ts->add(it->second);
			}
			return ts;

		}
		std::vector<std::pair<DynamicValueBase*,QDateTime> > * Cycle::get_cycleValues(){
			return this->values;
		}
		void Cycle::add_cycleValue(std::pair<DynamicValueBase*,QDateTime> p){

			this->values->push_back(p);

		}
		bool Cycle::get_is_cycle(){
			return this->isCycle;
		}

		void Cycle::set_is_cycle(bool _iscycle){
			this->isCycle=_iscycle;
		}
	}
}
