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


	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Help | QDialogButtonBox::Reset ,Qt::Vertical);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	buttonBox->button(QDialogButtonBox::Ok)->setDefault(true);
	buttonBox->button(QDialogButtonBox::Ok)->setCursor(Qt::PointingHandCursor);
	buttonBox->button(QDialogButtonBox::Help)->setCursor(Qt::PointingHandCursor);
	buttonBox->button(QDialogButtonBox::Reset)->setCursor(Qt::PointingHandCursor);
	connect(buttonBox,SIGNAL(accepted()),this, SLOT(OkClicked()));
	//connect(buttonBox,SIGNAL(rejected()),this,SLOT(close()));
	connect(buttonBox->button(QDialogButtonBox::Reset),SIGNAL(clicked()),this,SLOT(ResetClicked()));
	connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(show_help()));

	/*
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));
	this->cancelButton->setCursor(Qt::PointingHandCursor);
	*/

	connect(firstnamelabelEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	//connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
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

	/*
	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addStretch();
	*/

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	//mainLayout->addLayout(rightLayout);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);
	setWindowTitle(tr("experimenter informations"));
	setFixedHeight((sizeHint().height()));



}
void ExperimenterDialog::show_help(){
	QMessageBox::about(this,"Genotype helper","click add to add a new germplasm for your experiment.\n"
					   "You need to have selected one story in the story View.\n"
					   "Click on remove to remove a genotype, you need to click on the corresponding row number.\n"
					   "Click on edit to modify a genotype, you need to click on the corresponding row number.\n");
}
void ExperimenterDialog::enabledOkButton(const QString &text){
	Q_UNUSED(text)
	//this->okButton->setEnabled(true);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

}
void ExperimenterDialog::initialize(){
	this->firstnamelabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_firstname());
	this->lastnamelabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_lastname());
	this->organisationlabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_organization());
	this->emaillabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_email());
}
void ExperimenterDialog::ResetClicked(){
	this->initialize();
}

void ExperimenterDialog::OkClicked(){

	QString firstnametext= firstnamelabelEdit->text();
	QString lastnametext= lastnamelabelEdit->text();
	QString organisationtext= organisationlabelEdit->text();
	QString emailtext= emaillabelEdit->text();


	emit this->mon_signal(firstnametext,lastnametext,organisationtext,emailtext);
}
