#include "experimentheader.h"
namespace Xeml {

	namespace Document{
		ExperimentHeader::ExperimentHeader()
		{
			this->experimenter=new Experimenter();
			this->keywords=new std::list<Keyword*>();
		}
		ExperimentHeader::~ExperimentHeader(void){

		}

		Experimenter * ExperimentHeader::get_experimenter(){
			return this->experimenter;
		}

		QString ExperimentHeader::get_summary(){
			return this->summary;
		}
		std::list<Keyword*>::iterator ExperimentHeader::get_iterator(){
			return this->iter;
		}
		void ExperimentHeader::add_keyword(Keyword * _keyword){
			this->keywords->push_back(_keyword);
		}

		void ExperimentHeader::set_summary(QString _summary){
			this->summary=_summary;
		}

		std::list<Keyword*> * ExperimentHeader::get_keywords(){
			return this->keywords;
		}
	}
}
