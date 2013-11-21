#include "experimentitem.h"

ExperimentItem::ExperimentItem(const QString & _name,bool _isRoot)
:AbstractExperimentItem(_name){
	this->isroot=_isRoot;
}

ExperimentItem::ExperimentItem(QString _name,QUuid _Id,time_t _startDate,ExperimentHeader * _expHeader,bool _isRoot)
:AbstractExperimentItem(_name){
	this->Id = _Id;
	this->startDate = _startDate;
	this->expheader=_expHeader;
	this->isroot=_isRoot;
}
void ExperimentItem::set_experimenter_details(QString _firstnametext,QString _lastnametext,QString _organisationtext,QString _emailtext){
	this->expheader->get_experimenter()->set_firstname(_firstnametext);
	this->expheader->get_experimenter()->set_lastname(_lastnametext);
	this->expheader->get_experimenter()->set_organization(_organisationtext);
	this->expheader->get_experimenter()->set_email(_emailtext);
}
void ExperimentItem::set_experimentHeader(ExperimentHeader * _expHeader){
	this->expheader=_expHeader;
}
ExperimentHeader * ExperimentItem::get_experimentHeader(){
	return this->expheader;
}

bool ExperimentItem::isRoot(){
	return this->isroot;
}
