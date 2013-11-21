#include "experimenter.h"

namespace Xeml {

	namespace Document{

		Experimenter::Experimenter()
		{
		}
		Experimenter::~Experimenter(void)
		{
		}

		Experimenter::Experimenter(QString _firstname,QString _lastname,QString _email,QString _organization){
			this->firstname=_firstname;
			this->lastname=_lastname;
			this->email=_email;
			this->organization=_organization;
		}

		QString Experimenter::get_firstname(){
			return this->firstname;
		}

		QString Experimenter::get_lastname(){
			return this->lastname;
		}

		QString Experimenter::get_email(){
			return this->email;
		}

		QString Experimenter::get_organization(){
			return this->organization;
		}

		void Experimenter::set_firstname(QString _firstname){
			this->firstname=_firstname;
		}

		void Experimenter::set_lastname(QString _lastname){
			this->lastname=_lastname;
		}

		void Experimenter::set_email(QString _email){
			this->email=_email;
		}

		void Experimenter::set_organization(QString _organization){
			this->organization=_organization;
		}
		void Experimenter::clear(){
			this->firstname="";
			this->lastname="";
			this->email="";
			this->organization="";

		}
		bool Experimenter::is_null_or_empty(QString value){
			if(value.isEmpty()||value.isNull()){
				return true;
			}
			else{
				return false;
			}

		}

		bool Experimenter::is_empty(){
			if (is_null_or_empty(this->firstname) && is_null_or_empty(this->lastname)&& is_null_or_empty(this->email)&& is_null_or_empty(this->organization)){
				return true;
			}
			else{
				return false;
			}

		}

	}
}

