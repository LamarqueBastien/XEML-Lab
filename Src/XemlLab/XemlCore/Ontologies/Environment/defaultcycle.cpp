#include "defaultcycle.h"
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{
			DefaultCycle::DefaultCycle()
			{
				this->vals=new std::list<std::pair<QDateTime, QString> >();
			}
			DefaultCycle::~DefaultCycle(void){

			}

			void DefaultCycle::addValue(QDateTime _duration, QString _val){
				std::pair <QDateTime,QString> kv=std::make_pair (_duration,_val);

				this->vals->push_back(kv);

			}
			std::list<std::pair<QDateTime,QString> > * DefaultCycle::get_vals(){
				return this->vals;
			}

			void DefaultCycle::set_vals(std::list<std::pair<QDateTime,QString> > * _vals){
				this->vals=_vals;
			}

		}
	}
}
