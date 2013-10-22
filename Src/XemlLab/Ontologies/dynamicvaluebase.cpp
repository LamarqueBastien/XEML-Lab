#include "dynamicvaluebase.h"
namespace Xeml {

	namespace Document{

		DynamicValueBase::DynamicValueBase()
		{
		}
		DynamicValueBase::~DynamicValueBase(void)
		{
		}
		QString DynamicValueBase::get_label(){
			return this->label;
		}

		QString DynamicValueBase::get_context(){
			return this->context;
		}

		QString DynamicValueBase::get_unit(){
			return this->unit;
		}

		void DynamicValueBase::set_label(QString _label){
			this->label=_label;
		}

		void DynamicValueBase::set_context(QString _context){
			this->context=_context;
		}

		void DynamicValueBase::set_unit(QString _unit){
			this->unit=_unit;
		}
		bool DynamicValueBase::get_is_cycle(){
			return this->isCycle;
		}

		void DynamicValueBase::set_is_cycle(bool _iscycle){
			this->isCycle=_iscycle;
		}
	}
}
