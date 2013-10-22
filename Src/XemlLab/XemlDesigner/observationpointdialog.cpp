#include "observationpointdialog.h"


ObservationPointDialog::ObservationPointDialog(StoryBase *_story,ItfDocument * _xeml_doc,QWidget * parent)
	: QDialog(parent)
{
	this->current_doc=_xeml_doc;
	this->label = new QLabel(tr("timepoint :"));
	lineEdit = new QLineEdit;
	//QDateTime init_time=QDateTime::fromString("00.00:00:00","dd.hh:mm:ss");
	this->story=_story;
	if(this->story->get_IsStorySplit()){
		this->daytimeedit=new QDateTimeEdit(static_cast<StorySplit*>(this->story)->get_timepoint());
		this->daytimeedit->setMinimumDateTime(static_cast<StorySplit*>(this->story)->get_timepoint());
		this->daytimeedit->setMaximumDateTime(current_doc->get_enddate());
	}
	else{
		this->daytimeedit=new QDateTimeEdit(current_doc->get_startdate());
		this->daytimeedit->setMinimumDateTime(current_doc->get_startdate());
		this->daytimeedit->setMaximumDateTime(current_doc->get_enddate());

	}
	this->daytimeedit->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
	this->daytimeedit->setCalendarPopup(true);






	this->label->setBuddy(daytimeedit);

	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));
	connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(enabledOkButton(QDateTime)));
	//connect(lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));


	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(label);
	topleftLayout->addWidget(daytimeedit);

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
	setWindowTitle(tr("Observation points informations"));
	setFixedHeight((sizeHint().height()));
}
void ObservationPointDialog::set_id(int _currentid){

	this->id=_currentid;
}

void ObservationPointDialog::enabledOkButton(QDateTime _date){
	this->okButton->setEnabled(true);
}
void ObservationPointDialog::OkClicked(){
	//QString text= lineEdit->text();

	ObservationPoint * obs= new ObservationPoint(this->daytimeedit->dateTime());//QDateTime::fromString(lineEdit->text(),"dd.hh:mm:ss")TimeSpanExtension::tryTimeSpanSet(lineEdit->text().toStdString()));
	static_cast<XemlDocument*>(this->current_doc)->observationPointsCounter++,
	this->story->add_obsPoint(obs);
	obs->set_id(this->id);
	//TimeSpanExtension::tryTimeSpanSet(lineEdit->text().toStdString());
	//emit this->mon_signal(obs,this->story);
	this->close();
}
