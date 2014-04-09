#include "dynamicterm.h"

namespace Xeml {

	namespace Document{

		DynamicTerm::DynamicTerm()
		{
			this->IsMeasuredVariable=false;
		}
		DynamicTerm::~DynamicTerm(void)
		{
			std::cerr << "delete dynamic term" << std::endl;
		}
		DynamicTerm::DynamicTerm(QString _termId)
			:BasicTerm(_termId)
		{
			this->dynamicvaluecollection=new std::vector<pair<DynamicValueBase*,QDateTime> >();
			this->IsMeasuredVariable=false;
		}

		DynamicTerm::DynamicTerm(const DynamicTerm& term)
			:BasicTerm(term)
		{
			//this->set_termId(term.get_termId());
			//this->set_namespace(term.get_namespace());
			//this->set_namespacealias(term.get_namespacealias());
			//this->set_name(term.get_name());
			//this->nameSpacealias=term.nameSpacealias;
			//this->nameSpace=term.nameSpace;
			//this->name=term.name;
			this->IsMeasuredVariable=false;
			this->dynamicvaluecollection=new std::vector<pair<DynamicValueBase*,QDateTime> >();
		}
		void DynamicTerm::set_measured_variable(bool _IsMeasured){
			this->IsMeasuredVariable=_IsMeasured;
		}

		bool  DynamicTerm::get_measured_variable(){
			return this->IsMeasuredVariable;
		}

		std::vector<pair<DynamicValueBase*,QDateTime> > * DynamicTerm::get_dynamicvaluecollection(){
			return this->dynamicvaluecollection;
		}

		void DynamicTerm::add_dynamicvalue(DynamicValueBase* _value){
			this->dynamicvaluecollection->push_back(make_pair(_value,_value->get_timepoint()));
			//(*this->dynamicvaluecollection)[_value]=_value->get_timepoint();
		}
		bool                                  DynamicTerm::contains(QString _context,std::list<QString> * _contextList){
			for(std::list<QString>::iterator it=_contextList->begin();it!=_contextList->end();++it)
			{
				if((*it)==_context){
					return true;
				}
			}
			return false;
		}
		bool                                  DynamicTerm::contain(QString _context,std::list<DynamicValueBase*> * _valueList){
			for(std::list<DynamicValueBase*>::iterator it=_valueList->begin();it!=_valueList->end();++it)
			{
				if((*it)->get_context()==_context){
					return true;
				}
			}
			return false;
		}
		bool                                   DynamicTerm::find(DynamicValueBase  *vb){
			for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it=this->dynamicvaluecollection->begin();it!=this->dynamicvaluecollection->end();++it){
				if((*it).first->get_timepoint()==vb->get_timepoint()&&(*it).first->get_context()==vb->get_context()){
					return true;
				}
			}
			return false;
		}

		std::list<QString> * DynamicTerm::contextList(){
			std::list<QString> * ret = new std::list<QString>();
			for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it =this->dynamicvaluecollection->begin();it!=this->dynamicvaluecollection->end();++it){
				if(!contains(it->first->get_context(),ret)){
					ret->push_back(it->first->get_context());
				}
			}
			return ret;
		}
		std::list<DynamicValueBase*> * DynamicTerm::valueBy(QString _context){
			Q_UNUSED(_context);
			std::list<DynamicValueBase*> * ret = new std::list<DynamicValueBase*>();
			for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it =this->dynamicvaluecollection->begin();it!=this->dynamicvaluecollection->end();++it){
				if(!contain(it->first->get_context(),ret)){
					ret->push_back(it->first);
				}
			}
			return ret;
		}
	}
}
