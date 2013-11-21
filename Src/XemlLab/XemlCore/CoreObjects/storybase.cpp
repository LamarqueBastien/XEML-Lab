#include "storybase.h"
namespace Xeml {

	namespace Document{

		StoryBase::StoryBase()
		{
			this->eventcollection = new std::map<Event*,QDateTime>();
			this->variablesCollection = new std::vector<std::pair<BasicTerm*,QString> >();
			this->observationPointcollection = new std::vector<std::pair<ObservationPoint*,QDateTime> >();
		}
		StoryBase::~StoryBase(void){

			for (std::map<Event*,QDateTime>::iterator it=this->eventcollection->begin();it!=this->eventcollection->end();++it){
				delete (*it).first;
			}
			this->eventcollection->clear();
			delete this->eventcollection;
			for (std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->variablesCollection->begin();it!=this->variablesCollection->end();++it){
				delete (*it).first;
				//(*it).clear();
			}
			this->variablesCollection->clear();
			delete this->variablesCollection;

			for (std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=this->observationPointcollection->begin();it!=this->observationPointcollection->end();++it){
				delete (*it).first;
				//(*it).clear();
			}
			this->observationPointcollection->clear();
			delete this->observationPointcollection;

			for (std::map<TaggedAnnotation*,QString>::iterator it=this->TaggedannotationCollection->begin();it!=this->TaggedannotationCollection->end();++it){
				delete (*it).first;
			}
			this->TaggedannotationCollection->clear();
		}

		std::map<TaggedAnnotation*,QString>                  * StoryBase::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void                                                   StoryBase::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}

		void                                                   StoryBase::display_all_events(){
			for( this->iter = this->eventcollection->begin(); this->iter != this->eventcollection->end(); this->iter++ ) {

			}
		}
		void                                                   StoryBase::display_specific_timepoint(Event* _event){
			Q_UNUSED(_event);
			for( this->iter = this->eventcollection->begin(); this->iter != this->eventcollection->end(); this->iter++ ) {

			}
		}
		bool                                                   StoryBase::get_IsStorySplit(){
			return this->IsStorySplit;
		}
		void                                                   StoryBase::set_IsStorySplit(bool _IsStorySplit){
			this->IsStorySplit=_IsStorySplit;
		}

		bool                                                   StoryBase::contain_event(Event* event){
			Q_UNUSED(event);
			for (this->iter = this->eventcollection->begin(); this->iter != this->eventcollection->end(); this->iter++ ) {
				//need to compare timepoint
			}
			return true;
		}
		std::map<Event*,QDateTime>                           * StoryBase::get_eventcollection(){
			return this->eventcollection;
		}
		int                                                    StoryBase::count_event(){
			int ret=0;
			for (this->iter = this->eventcollection->begin(); this->iter != this->eventcollection->end(); ++this->iter ) {
				ret++;
			}
			return ret;
		}
		void                                                   StoryBase::add_event(Event * _event){
			(*this->eventcollection)[_event]=_event->get_timepoint();
		}
		void                                                   StoryBase::rm_event(QString _labelEvent){
			std::map<Event*,QDateTime>::iterator it_to_erase;
			for( this->iter = this->eventcollection->begin(); this->iter != this->eventcollection->end(); this->iter++ ) {
				if(iter->first->get_label()==_labelEvent){
					delete iter->first;
					it_to_erase=this->iter;
					this->eventcollection->erase(it_to_erase);
				}
			}
		}

		std::vector<std::pair<BasicTerm*,QString> >          * StoryBase::get_variablesCollection(){
			return this->variablesCollection;
		}
		bool                                                   StoryBase::contain_variable(BasicTerm * t){
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->variablesCollection->begin();it!=this->variablesCollection->end();++it){
				if((*it).second==t->get_termId()){
					return true;

				}
			}
			return false;
		}
		bool                                        StoryBase::contain_quantitative_variable(){

		}

		bool                                                   StoryBase::contain_variableId(QString _termId){
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->variablesCollection->begin();it!=this->variablesCollection->end();++it){
				if((*it).second==_termId){
					return true;

				}
			}
			return false;
		}
		BasicTerm *                                            StoryBase::get_variable(QString _termId){

			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->variablesCollection->begin();it!=this->variablesCollection->end();++it){
				if((*it).second==_termId){
					return (*it).first;

				}
			}
			return NULL;
		}
		void									               StoryBase::add_variable(BasicTerm * t){
			this->variablesCollection->push_back(std::make_pair(t,t->get_termId()));
		}
		void                                                   StoryBase::rm_variable(QString _termId){
			std::vector<std::pair<BasicTerm*,QString> >::iterator it_to_erase;
			for (std::vector<std::pair<BasicTerm*,QString> >::iterator it= this->variablesCollection->begin();it!=this->variablesCollection->end();++it){
				if ((*it).second == _termId){
					delete (*it).first;
					it_to_erase=it;
				}
			}
			this->variablesCollection->erase(it_to_erase);
		}

		int                                                    StoryBase::count_variables(){
			int ret=0;
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->variablesCollection->begin();it!=this->variablesCollection->end();++it){
				ret++;
			}
			return ret;

		}

		std::vector<std::pair<ObservationPoint*,QDateTime> > * StoryBase::get_obsPointCollection(){
			return this->observationPointcollection;
		}
		void                                                   StoryBase::set_obsPointCollection(std::vector<std::pair<ObservationPoint*,QDateTime> > * _opc){
			this->observationPointcollection=_opc;
		}
		ObservationPoint                                     * StoryBase::get_obsPoint(int _id){
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=this->observationPointcollection->begin();it!=this->observationPointcollection->end();++it){
				if((*it).first->get_id()==_id){
					return (*it).first;
				}
			}
			return NULL;
		}
		bool                                                   StoryBase::contain_obsPoint(ObservationPoint * _op){
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=this->observationPointcollection->begin();it!=this->observationPointcollection->end();++it){
				if((*it).second==_op->get_timepoint()){
					return true;
				}
			}
			return false;
		}
		void									               StoryBase::add_obsPoint(ObservationPoint* _op){
			std::pair<ObservationPoint*,QDateTime> tmp = std::make_pair(_op, _op->get_timepoint());
			this->observationPointcollection->push_back(tmp);
		}
		std::list<int>                                       * StoryBase::rm_obsPoint(int _id){
			std::cerr << "id :  " << _id << std::endl;
			std::cerr << "size :" << this->observationPointcollection->size() << std::endl;
			std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it_to_erase;
			std::list<int> * individual_ids=new std::list<int>();
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=this->observationPointcollection->begin();it!=this->observationPointcollection->end();++it){
				std::cerr << "OP will be deleted" << static_cast<ObservationPoint*>((*it).first)->get_timepoint().toString("dd.mm:hh:ss").toStdString() << std::endl;

				if(static_cast<ObservationPoint*>((*it).first)->get_id()==_id){
					std::cerr << "OP deleted" << std::endl;
					for (std::vector<pair<Observation*,QDateTime> >::iterator it2=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->begin();it2!=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->end();++it2){
						individual_ids->push_back(static_cast<Observation*>((*it2).first)->get_ind()->get_id());

					}
					delete (*it).first;
					//delete (*it).second;
					std::cerr << "OP deleted" << std::endl;
					it_to_erase=it;
					//this->observationPointcollection->erase(it);

				}
				std::cerr << "OP erased from vector of size now :" << this->observationPointcollection->size() << std::endl;

			}
			this->observationPointcollection->erase(it_to_erase);
			std::cerr << "OP erased from vector of size now :" << this->observationPointcollection->size() << std::endl;

			std::cerr << "out of rmObsPoint" << std::endl;
			return individual_ids;

		}
		bool                                                              compare_event_timepoint(Event* e1, Event* e2){

			Q_UNUSED(e1);
			Q_UNUSED(e2);
			return false;
		}




	}
}
