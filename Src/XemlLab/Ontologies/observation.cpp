#include "observation.h"

namespace Xeml {

	namespace Document{

		Observation::Observation()
		{
			//duration=new QDateTime();
			this->partitions= new std::map<Partition*,int>();
			this->devStage = new std::map<BasicTerm*,QString>();
			this->individual=NULL;
		}
		Observation::~Observation(void)
		{
			std::cerr << "deleting observation" << std::endl;
			for (std::map<Partition*,int>::iterator it=this->partitions->begin();it!=this->partitions->end();++it){
				delete (*it).first;
			}
			this->partitions->clear();
			for (std::map<BasicTerm*,QString>::iterator it=this->devStage->begin();it!=this->devStage->end();++it){
				delete static_cast<VariableTerm*>((*it).first);
			}
			std::cerr << "partition and material deleted" << std::endl;
			this->devStage->clear();
			//if(this->individual!=NULL){
			//	delete this->individual;
			//}
			std::cerr << "observation deleted" << std::endl;

		}

		int Observation::get_id(){
			return this->individual->get_id();
		}

		void Observation::set_id(int _id){
			this->individual->set_id(_id);
		}

		bool Observation::get_individualInfluence(){
			return this->destructive ? true : this->individualInfluence;
		}

		void Observation::set_individualInfluence(bool iI){
			this->individualInfluence=iI;
		}

		bool Observation::get_destructiveinfo(){
			return this->destructive;
		}

		void Observation::set_destructiveinfo(bool info){
			this->destructive=info;
		}

		QDateTime  Observation::get_duration(){
			return this->duration;
		}

		void Observation::set_duration(QDateTime _duration){
			std::cerr << "duration obs in set duration:" << _duration.toString("hh:mm:ss").toStdString() << std::endl;

			this->duration=_duration;
		}
		IndividualsPool*                         Observation::get_pool(){
			return this->individualsPool;
		}

		void                                    Observation::set_pool(IndividualsPool * _ip){
			this->individualsPool=_ip;
		}
		Individual *                            Observation::get_ind(){
			return this->individual;
		}

		void                                    Observation::set_ind(Individual * i){
			this->individual=i;
		}
		bool									Observation::contain_partition(Partition * _p){
			for(std::map<Partition*,int>::iterator it = this->partitions->begin();it!=this->partitions->end();++it){
				if((*it).second==_p->get_id()){
					return true;
				}
			}
			return false;
		}
		bool									Observation::contain_stages(QString _id){
			for(std::map<BasicTerm*,QString>::iterator it = this->devStage->begin();it!=this->devStage->end();++it){
				if((*it).second==_id){
					return true;
				}
			}
			return false;
		}
		std::map<BasicTerm*,QString> *      Observation::get_stageCollection(){
			return this->devStage;
		}

		void									Observation::add_stage(BasicTerm * _term){
			(*this->devStage)[_term]=_term->get_termId();
		}

		std::map<Partition*,int> *				Observation::get_partitionCollection(){
			return this->partitions;
		}

		void									Observation::add_partition(Partition * _p){
			(*this->partitions)[_p]=_p->get_id();
		}

		std::map<TaggedAnnotation*,QString> * Observation::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void Observation::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}
	}
}
