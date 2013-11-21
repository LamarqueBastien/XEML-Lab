#include "story.h"

namespace Xeml {

	namespace Document{
		Story::Story()
		{

			this->individualspoolcollection=new std::map<IndividualsPool*,QString>();
			this->IsStorySplit=false;
		}
		Story::Story(QString _label)
		{
			this->IsStorySplit=false;
			this->label=_label;
			this->individualspoolcollection=new std::map<IndividualsPool*,QString>();

		}
		Story::~Story(void){
			std::cerr << "delete story " << std::endl;
			for(std::map<IndividualsPool*,QString>::iterator it=this->individualspoolcollection->begin();it!=this->individualspoolcollection->end();++it){
				delete (*it).first;
			}
			this->individualspoolcollection->clear();
			delete this->individualspoolcollection;
		}

		QString Story::get_label(){
			return this->label;
		}
		void Story::set_label(QString _label){
			this->label= _label;
		}
		void Story::add_individualspool(IndividualsPool * _individualspool){
			//std::cerr <<" ip fqname : " << _individualspool->getFqName().toStdString() << std::endl;
			(*this->individualspoolcollection)[_individualspool]=_individualspool->getFqName();
		}

		void Story::display_all_individualspools(){
			for( this->iter = this->individualspoolcollection->begin(); this->iter != this->individualspoolcollection->end(); this->iter++ ) {

			}
		}

		std::map<IndividualsPool*,QString> * Story::get_individualspoolcollection(){
			return this->individualspoolcollection;
		}
		IndividualsPool * Story::find(QString _fullname){
			for( this->iter = this->individualspoolcollection->begin(); this->iter != this->individualspoolcollection->end(); this->iter++ ) {
				if(this->iter->second==_fullname){
					return this->iter->first;
				}
			}
			return NULL;

		}


	}
}
