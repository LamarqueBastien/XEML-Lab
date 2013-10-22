#include "genotypeitem.h"

GenotypeItem::GenotypeItem(const QString & _text)
{
	this->setText(_text);
	this->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	this->setToolTip(this->text());
}
