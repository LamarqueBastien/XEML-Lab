#include "observationpoint.h"

namespace Xeml{

	namespace Document{
		ObservationPoint::ObservationPoint()
		{
			this->observationscollection = new std::vector<pair<Observation*,QDateTime> >();
		}
		ObservationPoint::ObservationPoint(QDateTime _timepoint)
		{
			this->timepoint=_timepoint;
			this->observationscollection = new std::vector<pair<Observation*,QDateTime> >();
		}
		ObservationPoint::~ObservationPoint(void){
			std::cerr << "delete observation point" << std::endl;
			for(std::vector<pair<Observation*,QDateTime> >::iterator it =this->observationscollection->begin();it!=this->observationscollection->end();++it){
				delete (*it).first;
			}
			this->observationscollection->clear();
			for (std::map<TaggedAnnotation*,QString>::iterator it=this->TaggedannotationCollection->begin();it!=this->TaggedannotationCollection->end();++it){
				delete (*it).first;
			}
			this->TaggedannotationCollection->clear();
		}

		QDateTime  ObservationPoint::get_timepoint(){
			return this->timepoint;
		}

		void ObservationPoint::set_timepoint(QDateTime  _timepoint){
			this->timepoint=_timepoint;
		}

		void ObservationPoint::add_observation(Observation * _observation){
			this->observationscollection->push_back(make_pair(_observation,_observation->get_duration()));
			//(*this->observationscollection)[_observation]=_observation->get_duration();
		}
		int ObservationPoint::count_observations(){
			int cpt=0;
			for( this->it = this->observationscollection->begin(); this->it != this->observationscollection->end(); this->it++ ) {
				cpt++;

			}
			return cpt;
		}

		void ObservationPoint::display_all_observations(){
			std::cerr << "there is " << this->observationscollection->size() << " observations" << std::endl;
			for( this->it = this->observationscollection->begin(); this->it != this->observationscollection->end(); this->it++ ) {


				std::cerr << "observation duration ="<< static_cast<QDateTime>(this->it->second).toString("hh:mm:ss").toStdString()<<std::endl;

			}
		}

		std::vector<pair<Observation*,QDateTime> > * ObservationPoint::get_observationscollection(){
			return this->observationscollection;
		}

		std::vector<pair<Observation*,QDateTime> >::iterator ObservationPoint::get_iterator(){
			return this->it;
		}

		std::map<TaggedAnnotation*,QString> * ObservationPoint::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void ObservationPoint::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}
		int ObservationPoint::get_id(){

			return this->id;
		}

		void ObservationPoint::set_id(int _id){
			this->id=_id;
		}
	}
}
