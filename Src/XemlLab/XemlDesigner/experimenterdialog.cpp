#include "experimenterdialog.h"

ExperimenterDialog::ExperimenterDialog(ItfDocument * _xemlDoc, QWidget * parent)
	: QDialog(parent)
{
	this->current_doc=_xemlDoc;
	this->firstnamelabel = new QLabel(tr("firstName :"));
	this->firstnamelabelEdit = new QLineEdit;
	this->firstnamelabel->setBuddy(firstnamelabelEdit);
	this->lastnamelabel =new QLabel(tr("LastName : "));
	this->lastnamelabelEdit =new QLineEdit;
	this->lastnamelabel->setBuddy(lastnamelabelEdit);
	this->organisationlabel=new QLabel(tr("Organisation : "));
	this->organisationlabelEdit =new QLineEdit;
	this->organisationlabel->setBuddy(this->organisationlabelEdit);
	this->emaillabel=new QLabel(tr("Email : "));
	this->emaillabelEdit =new QLineEdit;
	this->emaillabel->setBuddy(this->emaillabelEdit);



	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));
	this->cancelButton->setCursor(Qt::PointingHandCursor);

	connect(firstnamelabelEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
	//connect(this,SIGNAL(destroyed()),this,SLOT(OkClicked()));

	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(this->firstnamelabel);
	topleftLayout->addWidget(firstnamelabelEdit);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(lastnamelabel);
	topleftLayout2->addWidget(lastnamelabelEdit);
	QHBoxLayout * topleftLayout3 = new QHBoxLayout;
	topleftLayout->addWidget(organisationlabel);
	topleftLayout->addWidget(organisationlabelEdit);
	QHBoxLayout * topleftLayout4 = new QHBoxLayout;
	topleftLayout2->addWidget(emaillabel);
	topleftLayout2->addWidget(emaillabelEdit);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);
	leftLayout->addLayout(topleftLayout2);
	leftLayout->addLayout(topleftLayout3);
	leftLayout->addLayout(topleftLayout4);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
	setWindowTitle(tr("experimenter informations"));
	setFixedHeight((sizeHint().height()));



}
void ExperimenterDialog::enabledOkButton(const QString &text){
	this->okButton->setEnabled(true);
}
void ExperimenterDialog::initialize(){
	this->firstnamelabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_firstname());
	this->lastnamelabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_lastname());
	this->organisationlabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_organization());
	this->emaillabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_email());
}

void ExperimenterDialog::OkClicked(){
	std::cerr << " test"  <<std::endl;
	QString firstnametext= firstnamelabelEdit->text();
	QString lastnametext= lastnamelabelEdit->text();
	QString organisationtext= organisationlabelEdit->text();
	QString emailtext= emaillabelEdit->text();
	emit this->mon_signal(firstnametext,lastnametext,organisationtext,emailtext);
}
