#include "aboutexperiment.h"

AboutExperiment::AboutExperiment(ItfDocument * _xeml_doc, QWidget * parent)
	:QDialog(parent)
{
	this->listWidget =new QListWidget;
	this->tabWidget=new QTabWidget;

	listWidget->addItem(tr("Experiment info"));
	listWidget->addItem(tr("Experimenter info"));

	this->cancelButton = new QPushButton("Cancel");
	this->okButton = new QPushButton("OK");
	this->cancelButton->setCursor(Qt::PointingHandCursor);
	this->okButton->setCursor(Qt::PointingHandCursor);

	this->stackLayout= new QStackedLayout;

	expdialog = new ExperimentDialog(_xeml_doc);
	expdialog->initialize();

	stackLayout->addWidget( expdialog);

	experdialog = new ExperimenterDialog(_xeml_doc);
	experdialog->initialize();
	stackLayout->addWidget(experdialog);
	this->tabWidget->addTab(expdialog,"Experiment details");
	this->tabWidget->addTab(experdialog,"Experimenter details");
	connect(this->experdialog,SIGNAL(mon_signal(QString,QString,QString,QString)),this,SLOT(experimenter_set_up(QString,QString,QString,QString)));
	//connect(this->listWidget,SIGNAL(currentRowChanged(int)),stackLayout,SLOT(setCurrentIndex(int)));
	//connect(this,SIGNAL(finished(int)),this->experdialog,SLOT(OkClicked()));
	//QVBoxLayout * leftLayout = new QVBoxLayout;
	//leftLayout->addWidget(listWidget);
	//QVBoxLayout * rightLayout = new QVBoxLayout;
	//rightLayout->addLayout(stackLayout);
	QHBoxLayout * topLayout = new QHBoxLayout;
	//mainLayout->addLayout(leftLayout);
	//mainLayout->addLayout(rightLayout);
	topLayout->addWidget(tabWidget);
	QHBoxLayout * bottomLayout=new QHBoxLayout;
	bottomLayout->addWidget(cancelButton);
	bottomLayout->addWidget(okButton);
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QVBoxLayout * mainLayout=new QVBoxLayout;
	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(bottomLayout);
	this->setLayout(mainLayout);

	listWidget->setCurrentRow(0);
}


void AboutExperiment::experimenter_set_up(QString _firstnametext,QString _lastnametext,QString _organisationtext,QString _emailtext){
	//regler les differents attributs de ce term
	//envoyer le term regle en parametre de set_up_finished(ItfOntologyTerm * _term)
	//ce signal sera recu par storyview dans la fonction set_up_parameter()
	emit experimenter_set_up_finished(_firstnametext,_lastnametext,_organisationtext,_emailtext);
}

