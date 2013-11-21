#include "abstractexperimentitem.h"

AbstractExperimentItem::AbstractExperimentItem(const QString & _name)
{
	this->name=_name;
	this->setText(_name);

}
