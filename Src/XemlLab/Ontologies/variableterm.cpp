#include "variableterm.h"
namespace Xeml {

	namespace Document{
		VariableTerm::VariableTerm()
		{
			this->valuecollection= new std::map<ValueBase*,QString>();
		}
		VariableTerm::~VariableTerm(void)
		{
			std::cerr << "delete Variable term" << std::endl;
			for(std::map<ValueBase*,QString>::iterator it=this->valuecollection->begin();it!=this->valuecollection->end();++it){
				delete static_cast<Value*>((*it).first);
			}
			this->valuecollection->clear();
			delete this->valuecollection;

		}
		VariableTerm::VariableTerm(QString _termId)
		:BasicTerm(_termId)
		{
			this->valuecollection= new std::map<ValueBase*,QString>();
		}
		std::map<ValueBase*,QString> * VariableTerm::get_valuecollection(){
			return this->valuecollection;
		}

		void VariableTerm::add_value(ValueBase* _value){
			(*this->valuecollection)[_value]=_value->get_context();
		}
	}
}
