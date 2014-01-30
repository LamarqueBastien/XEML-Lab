#include "sample.h"
namespace Xeml {

	namespace Document{

		Sample::Sample()
		{

			this->partitions=new std::vector<Partition*>();
			this->owning_ObsPoint= new std::vector<ObservationPoint*>();
			this->id=-1;
		}

		// The calculated time point of an sample.
		QDateTime Sample::get_time_point(){
			return this->cached_time;
		}

		void Sample::set_timepoint(QDateTime _cached_time){

		}

		int Sample::get_id(){
			return this->id;
		}

		void Sample::set_id(int _id){
			if (_id!=this->id){
				this->id=_id;
			}
		}

		void Sample::calc_owning_obspoint(){
			this->owning_ObsPoint->clear();
			for (std::vector<Partition*>::iterator it = this->partitions->begin();it!=this->partitions->end();++it){
				Partition * p = static_cast<Partition*>((*it));
				//p->
			}

		}
		std::vector<Partition*> *   Sample::get_partitions(){
			return this->partitions;
		}

		void Sample::add_partition(Partition * _part){
			this->partitions->push_back(_part);
		}
		void Sample::remove_partition(Partition * _part){
			//this->partitions->pop_back(_part);
		}
		void Sample::clear_partition(){

		}
		std::map<TaggedAnnotation*,QString> * Sample::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void Sample::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}
	}
}
