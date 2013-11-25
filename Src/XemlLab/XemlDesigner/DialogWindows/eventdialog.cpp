#include <QtGui>
#include "eventdialog.h"

EventDialog::EventDialog(ItfDocument * _xemldoc,StoryBase * _story,QWidget * parent)
	: QDialog(parent)
{
	this->current_doc=_xemldoc;
	this->current_story=_story;
	this->label = new QLabel(tr("Label :"));
	this->lineEdit = new QLineEdit;
	this->label->setBuddy(lineEdit);
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));


	/*
	//std::cerr << _element_selected->toString().toStdString() << std::endl;
	//this->element_selected=_element_selected,
	//std::cerr << "in constructor (storysplitdialog) " << this->element_selected.toString().toStdString() << std::endl;
	//this->timepoint =new QLabel(tr("Timepoint :"));

	if (current_story->get_IsStorySplit()){
		this->daytimeedit=new QDateTimeEdit(static_cast<StorySplit*>(this->current_story)->get_timepoint());
		this->daytimeedit->setMinimumDateTime(static_cast<StorySplit*>(this->current_story)->get_timepoint());
		this->daytimeedit->setMaximumDateTime(this->current_doc->get_enddate());
	}
	else{
		this->daytimeedit=new QDateTimeEdit(this->current_doc->get_startdate());
		this->daytimeedit->setMinimumDateTime(this->current_doc->get_startdate());
		this->daytimeedit->setMaximumDateTime(this->current_doc->get_enddate());

	}
	this->timepoint->setBuddy(this->daytimeedit);

	//this->daytimeedit->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
	//this->daytimeedit->setCalendarPopup(true);
	//this->lineEditTimePoint = new QLineEdit;
	//this->timepoint->setBuddy(lineEditTimePoint);
	//connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(enabledOkButton(QDateTime)));
	//connect(lineEditTimePoint,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	*/

	connect(lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));


	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(label);
	topleftLayout->addWidget(lineEdit);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);


	setWindowTitle(tr("event informations"));
	setFixedHeight((sizeHint().height()));



}
void EventDialog::enabledOkButton(const QString & text){
	Q_UNUSED(text)
	this->okButton->setEnabled(true);
}
void EventDialog::OkClicked(){

	QString text= lineEdit->text();
	QDateTime _datetime=get_date(this->current_doc->get_startdate(),86400000);  //this->daytimeedit->dateTime();
	Event * e=new Event(_datetime);
	e->set_label(text);

	this->current_story->add_event(e);


	emit event_set(e);
	this->close();
}



