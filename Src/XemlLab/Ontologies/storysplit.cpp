#include "storysplit.h"
namespace Xeml{
	namespace Document{
		StorySplit::StorySplit()
		{
			this->IsStorySplit=true;
			//this->eventcollection = new std::map<Event*,QDateTime>();
			//this->variablesCollection = new std::vector<std::pair<BasicTerm*,QString> >();
		}
		StorySplit::~StorySplit(void){
			std::cerr << "delete story split" << std::endl;
			/*
			for(std::map<Event*,QDateTime>::iterator it=this->eventcollection->begin();it!=this->eventcollection->end();++it){
				delete (*it).first;
			}
			this->eventcollection->clear();
			delete this->eventcollection;
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->variablesCollection->begin();it!=this->variablesCollection->end();++it){
				delete (*it).first;
			}
			this->variablesCollection->clear();
			delete this->variablesCollection;
			*/
		}

		QString StorySplit::get_label(){
			return this->label;
		}

		void StorySplit::set_label(QString _label){
			this->label=_label;
		}

		QDateTime  StorySplit::get_timepoint(){
			return this->timepoint;
		}

		void StorySplit::set_timepoint(QDateTime _timepoint){
			QDateTime  old = this->timepoint;
			if(this->timepoint != _timepoint){
				MoveValues(old,_timepoint);
				this->timepoint=_timepoint;
			}
		}
		void StorySplit::MoveValues(QDateTime oldVal,QDateTime newVal){
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it = this->variablesCollection->begin();it!= this->variablesCollection->end();++it){
				std::list<DynamicValueBase*> * toRemove = new std::list<DynamicValueBase*>();
				std::vector<pair<DynamicValueBase*,QDateTime> > * tmp_map = static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection();
				for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it2 = tmp_map->begin();it2!=tmp_map->end();++it2){
					if((*it2).first->get_timepoint()==oldVal){
						(*it2).first->set_timepoint(newVal);
					}
					else if((*it2).first->get_timepoint()<newVal){
						toRemove->push_back((*it2).first);
					}
				}
			}
			/*
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=this->observationPointcollection->begin();it!=this->observationPointcollection->end();++it){
				QDateTime tmp =(*it).first->get_timepoint();

				(*it).first->set_timepoint(tmp);
			}
			*/

		}
	}
}
