#include "experimentdialog.h"

ExperimentDialog::ExperimentDialog(ItfDocument * _xeml_doc,QWidget * parent)
	: QDialog(parent)
{
	this->current_doc=_xeml_doc;
	this->experimentlabel = new QLabel(tr("experiment Label :"));
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
	this->startdateEdit->setMinimumDate(QDate::currentDate().addDays(-15365));
	this->startdateEdit->setMaximumDate(QDate::currentDate().addDays(15365));
	this->startdateEdit->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
	this->enddateEdit->setMinimumDate(QDate::currentDate().addDays(-15365));
	this->enddateEdit->setMaximumDate(QDate::currentDate().addDays(15365));
	this->enddateEdit->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->cancelButton = new QPushButton(tr("Cancel"));
	this->cancelButton->setCursor(Qt::PointingHandCursor);

	connect(experimentlabelEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));

	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(experimentlabel);
	topleftLayout->addWidget(experimentlabelEdit);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(experimentstartDate);
	topleftLayout2->addWidget(startdateEdit);
	QHBoxLayout * topleftLayout3 = new QHBoxLayout;
	topleftLayout2->addWidget(experimentEndDate);
	topleftLayout2->addWidget(enddateEdit);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);
	leftLayout->addLayout(topleftLayout2);
	leftLayout->addLayout(topleftLayout3);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
	setWindowTitle(tr("experiment informations"));
	setFixedHeight((sizeHint().height()));



}
void ExperimentDialog::enabledOkButton(const QString &text){
	this->okButton->setEnabled(true);
}
void ExperimentDialog::initialize(){
	this->experimentlabelEdit->setText(this->current_doc->get_experiment_name());
	this->startdateEdit->setDateTime(this->current_doc->get_startdate());
	this->enddateEdit->setDateTime(this->current_doc->get_enddate());
	this->enddateEdit->setMinimumDateTime(this->current_doc->get_startdate());
	//this->startdateEdit->setMaximumDateTime(this->current_doc->get_enddate());
}

void ExperimentDialog::OkClicked(){

	QString text= experimentlabelEdit->text();

	this->current_doc->set_startdate(this->startdateEdit->dateTime());
	qint64 seconds_ellapsed=get_seconds_from_date(this->startdateEdit->dateTime(),this->enddateEdit->dateTime());
	this->current_doc->set_enddate(get_date(this->current_doc->get_startdate(),seconds_ellapsed));

	this->current_doc->set_experiment_name(experimentlabelEdit->text());
	this->setEnabled(false);

	emit this->mon_signal(text);
}
