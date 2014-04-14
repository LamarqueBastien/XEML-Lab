#include "experimentdialog.h"

ExperimentDialog::ExperimentDialog(ItfDocument * _xeml_doc,QWidget * parent)
	: QDialog(parent)
{
	this->current_doc=_xeml_doc;
	this->experimentlabel = new QLabel(tr("Label :"));
	this->descriptionLabel =new QLabel(tr("Description :"));
	this->descriptionEdit=new QTextEdit();
	this->descriptionLabel->setBuddy(descriptionEdit);
	this->experimentlabelEdit = new QLineEdit;
	this->experimentlabel->setBuddy(experimentlabelEdit);
	this->experimentstartDate =new QLabel(tr("Start date : "));
	this->experimentEndDate =new QLabel(tr("End date : "));
	this->startdateEdit = new QDateTimeEdit(QDate::currentDate());
	this->experimentstartDate->setBuddy(this->startdateEdit);
	this->startdateEdit->setCalendarPopup(true);
	this->enddateEdit = new QDateTimeEdit(QDate::currentDate());
	this->experimentEndDate->setBuddy(this->enddateEdit);
	this->enddateEdit->setCalendarPopup(true);
	this->startdateEdit->setMinimumDate(QDate::currentDate().addDays(-8650));
	this->startdateEdit->setMaximumDate(QDate::currentDate().addDays(8650));
	this->startdateEdit->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
	this->enddateEdit->setMinimumDate(QDate::currentDate().addDays(-8650));
	this->enddateEdit->setMaximumDate(QDate::currentDate().addDays(8650));
	this->enddateEdit->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
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
	/*
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->cancelButton = new QPushButton(tr("Cancel"));
	this->cancelButton->setCursor(Qt::PointingHandCursor);
	*/
	connect(experimentlabelEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	//connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
	connect(this->startdateEdit,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(avoid_endTime_reachout(QDateTime)));

	connect(this->enddateEdit,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(avoid_equal_time(QDateTime)));

	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(experimentlabel);
	topleftLayout->addWidget(experimentlabelEdit);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(experimentstartDate);
	topleftLayout2->addWidget(startdateEdit);
	topleftLayout2->addWidget(experimentEndDate);
	topleftLayout2->addWidget(enddateEdit);
	QHBoxLayout * topleftLayout3 = new QHBoxLayout;
	topleftLayout3->addWidget(descriptionLabel);
	topleftLayout3->addWidget(descriptionEdit);

	QHBoxLayout * topleftLayout4 = new QHBoxLayout;
	topleftLayout4->addWidget(this->firstnamelabel);
	topleftLayout4->addWidget(firstnamelabelEdit);
	topleftLayout4->addWidget(lastnamelabel);
	topleftLayout4->addWidget(lastnamelabelEdit);
	QHBoxLayout * topleftLayout5 = new QHBoxLayout;
	topleftLayout5->addWidget(organisationlabel);
	topleftLayout5->addWidget(organisationlabelEdit);
	topleftLayout5->addWidget(emaillabel);
	topleftLayout5->addWidget(emaillabelEdit);


	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout2);
	leftLayout->addLayout(topleftLayout);

	leftLayout->addLayout(topleftLayout3);
	leftLayout->addLayout(topleftLayout4);
	leftLayout->addLayout(topleftLayout5);


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
	setWindowTitle(tr("experiment informations"));
	setFixedHeight((sizeHint().height()));



}
void ExperimentDialog::enabledOkButton(const QString &text){
	Q_UNUSED(text)
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	//this->okButton->setEnabled(true);
}

//when Enddate is equal to Startdate, always add a second to enddate.
void ExperimentDialog::avoid_equal_time(QDateTime _newTime){
	if (this->startdateEdit->dateTime()==_newTime){
		this->enddateEdit->setDateTime(_newTime.addSecs(1));
	}
	//else{

	//}
}
//Avoid Enddate be earlier than Startdate
void ExperimentDialog::avoid_endTime_reachout(QDateTime _newTime){
	this->enddateEdit->setMinimumDateTime(_newTime);

}

void ExperimentDialog::initialize(){
	this->descriptionEdit->setPlainText(this->current_doc->get_experimentheader()->get_summary());
	this->experimentlabelEdit->setText(this->current_doc->get_experiment_name());
	this->startdateEdit->setDateTime(this->current_doc->get_startdate());
	this->enddateEdit->setDateTime(this->current_doc->get_enddate());
	this->enddateEdit->setMinimumDateTime(this->current_doc->get_startdate());
	this->firstnamelabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_firstname());
	this->lastnamelabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_lastname());
	this->organisationlabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_organization());
	this->emaillabelEdit->setText(this->current_doc->get_experimentheader()->get_experimenter()->get_email());
	//this->startdateEdit->setMaximumDateTime(this->current_doc->get_enddate());
}
void ExperimentDialog::ResetClicked(){
	this->initialize();
}

void ExperimentDialog::OkClicked(){

	QString text= experimentlabelEdit->text();
	QString description=this->descriptionEdit->toPlainText();

	this->current_doc->set_startdate(this->startdateEdit->dateTime());
	qint64 seconds_ellapsed=get_seconds_from_date(this->startdateEdit->dateTime(),this->enddateEdit->dateTime());
	this->current_doc->set_enddate(get_date(this->current_doc->get_startdate(),seconds_ellapsed));
	this->current_doc->get_experimentheader()->set_summary(description);
	//this->current_doc->set_description(description);
	this->current_doc->set_experiment_name(experimentlabelEdit->text());
	this->current_doc->get_experimentheader()->get_experimenter()->set_email(emaillabelEdit->text());
	this->current_doc->get_experimentheader()->get_experimenter()->set_firstname(firstnamelabelEdit->text());
	this->current_doc->get_experimentheader()->get_experimenter()->set_lastname(lastnamelabelEdit->text());
	this->current_doc->get_experimentheader()->get_experimenter()->set_organization(organisationlabelEdit->text());
	this->setEnabled(false);
	//this->buttonBox->button(QDialogButtonBox::Reset)->setEnabled(true);


	emit this->set_up_finished();
	this->close();
}
