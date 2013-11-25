#include <QtGui>
#include "storysplitdialog.h"


StorySplitDialog::StorySplitDialog(ItfDocument * _xemlDoc, QVariant  _element_selected,QWidget * parent)
	: QDialog(parent)
{
	this->current_doc=_xemlDoc;
	//std::cerr << _element_selected->toString().toStdString() << std::endl;
	this->element_selected=_element_selected,
	//std::cerr << "in constructor (storysplitdialog) " << this->element_selected.toString().toStdString() << std::endl;
	this->label = new QLabel(tr("Label :"));
	this->timepoint =new QLabel(tr("Timepoint :"));
	lineEdit = new QLineEdit;
	this->daytimeedit=new QDateTimeEdit(static_cast<XemlDocument*>(_xemlDoc)->get_startdate());
	this->timepoint->setBuddy(this->daytimeedit);
	//StoryItem tmp=element_selected.value<StoryItem>();
	this->daytimeedit->setMinimumDateTime(static_cast<XemlDocument*>(_xemlDoc)->get_startdate());
	this->daytimeedit->setMaximumDateTime(static_cast<XemlDocument*>(_xemlDoc)->get_enddate());

	connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(valid_date_time(QDateTime)));
	//this->daytimeedit->setDisplayFormat("dd.hh:mm:ss");
	this->lineEditTimePoint = new QLineEdit;
	this->label->setBuddy(lineEdit);
	this->timepoint->setBuddy(lineEditTimePoint);
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));
	//connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(enabledOkButton(QDateTime)));
	connect(lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	//connect(lineEditTimePoint,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));


	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(label);
	topleftLayout->addWidget(lineEdit);
	topleftLayout->addWidget(timepoint);
	topleftLayout->addWidget(this->daytimeedit);

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
	setWindowTitle(tr("story split informations"));
	setFixedHeight((sizeHint().height()));



}
void StorySplitDialog::enabledOkButton(const QString & text){
	Q_UNUSED(text)
	this->okButton->setEnabled(true);
}
void StorySplitDialog::valid_date_time(QDateTime time_split){
	if (time_split > this->current_doc->get_enddate()){
		QMessageBox::information(this,"time exception","can't add a splitstory beyond the end date of experiment");

	}
}

void StorySplitDialog::OkClicked(){

	QString text= lineEdit->text();
	QDateTime _datetime=this->daytimeedit->dateTime();

	/*
	QDateTime date= QDateTime::currentDateTime();
	QDateTime date2=QDateTime::fromString("15-10-2013T13:54:00","dd-MM-yyyyThh:mm:ss");

	qint64 seconde=date.currentMSecsSinceEpoch();
	qint64 seconde2=date2.currentMSecsSinceEpoch();
	QDateTime date3=QDateTime::fromMSecsSinceEpoch(14000);
	std::cerr << "current date : " << date.toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;
	std::cerr << " date2 : " << date2.toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;
	std::cerr << " date3 : " << date3.toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;
	std::cerr << "qint64 second : " << seconde << std::endl;
	std::cerr << "qint64 second2 : " << seconde2 << std::endl;
	qint64 diff=date.secsTo(date2);

	//int days=translate_second_in_DD_HH_MM_SS(diff)->at(0);
	//int hours=translate_second_in_DD_HH_MM_SS(diff)->at(1);
	//int minutes=translate_second_in_DD_HH_MM_SS(diff)->at(2);
	//int seconds=translate_second_in_DD_HH_MM_SS(diff)->at(3);
	std::cerr << "qint64 diff : " << diff << std::endl;
	//std::cerr << "days : " << days << "hours : " << hours << "minutes : " << minutes << "seconds : " << seconds <<  std::endl;


	std::cerr << "conversion inverse" << std::endl;
	qint64 seconde3=translate_DD_HH_MM_SS_in_Msecs("10.00:00:00");
	std::cerr << "seconde3 : " << seconde3 << std::endl;

	std::cerr << "test : " << QDateTime::fromMSecsSinceEpoch(1000).toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;

	QDateTime stdate=QDateTime::fromString("01-01-2013T00:00:00","dd-MM-yyyyThh:mm:ss");
	qint64 timestamp=translate_DD_HH_MM_SS_in_Msecs("12.00:00:00");
	std::cerr << "timestamp : " << timestamp << std::endl;
	QDateTime newdate=get_date(stdate,timestamp);
	std::cerr << "newdate : " << newdate.toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;
	//QString text2=lineEditTimePoint->text();
	//if (this->element_selected==NULL){
	//	std::cerr << "QVariant element selected is null" << std::endl;
	//}
	//std::cerr <<"in OKclicked (storysplitdialog)" << this->element_selected.toString().toStdString() << std::endl;
	*/
	emit this->storysplitset(this->element_selected.toString(),text,_datetime);
}


