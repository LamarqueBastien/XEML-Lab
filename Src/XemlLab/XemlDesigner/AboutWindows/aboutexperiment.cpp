#include "aboutexperiment.h"

AboutExperiment::AboutExperiment(ItfDocument * _xeml_doc, QWidget * parent)
	:QDialog(parent)
{

	this->tabWidget=new QTabWidget;
	this->cancelButton = new QPushButton("Cancel");
	this->okButton = new QPushButton("OK");
	this->cancelButton->setCursor(Qt::PointingHandCursor);
	this->okButton->setCursor(Qt::PointingHandCursor);



	expdialog = new ExperimentDialog(_xeml_doc);
	expdialog->initialize();

	this->tabWidget->addTab(expdialog,"Experiment details");
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));


	QHBoxLayout * topLayout = new QHBoxLayout;
	topLayout->addWidget(tabWidget);

	QHBoxLayout * bottomLayout=new QHBoxLayout;
	bottomLayout->addWidget(cancelButton);
	bottomLayout->addWidget(okButton);

	QVBoxLayout * mainLayout=new QVBoxLayout;
	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(bottomLayout);

	this->setLayout(mainLayout);




}


void AboutExperiment::experimenter_set_up(QString _firstnametext,QString _lastnametext,QString _organisationtext,QString _emailtext){

	emit experimenter_set_up_finished(_firstnametext,_lastnametext,_organisationtext,_emailtext);
}

