#include "loaderwizard.h"

//ajouter spinbox pour
//definir ligne de depart de lecture et numero
//de ligne des headres à prendre en compte



std::vector<std::vector<QString> * > * LoaderWizard::csvdata = new std::vector<std::vector<QString> *>();
LoaderWizard::LoaderWizard(QStandardItemModel * _model,ItfDocument * _doc,DocumentResources * _resources,QWidget *parent)
		: QWizard(parent)
{

	loaderIntroPage=new LoaderIntroPage();
	setPage(Page_Intro, loaderIntroPage);
	loaderDataFilePage=new LoaderDataFilePage();
	setPage(Page_DataFile, loaderDataFilePage);
	loaderParamSettingPage=new LoaderParamSettingPage(_model,_doc,_resources);
	setPage(Page_ParamSet, loaderParamSettingPage);
	loaderValidationPage=new LoaderValidationPage();
	setPage(Page_Validation, loaderValidationPage);


	setStartId(Page_Intro);
#ifndef Q_OS_MAC
	setWizardStyle(ModernStyle);

#endif


	setOption(HaveHelpButton, true);
	//setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo.png"));

	//connect(static_cast<LoaderDataFilePage*>(this->loaderDataFilePage),SIGNAL(data_loaded(std::vector<std::vector<QString> *> *)),static_cast<LoaderParamSettingPage*>(this->loaderParamSettingPage),SLOT(send_data(std::vector<std::vector<QString>*>*)),Qt::DirectConnection);
	connect(this, SIGNAL(helpRequested()), this, SLOT(showHelp()));
	//connect(this,SIGNAL(),this->loaderDataFilePage,SLOT()

	setWindowTitle(tr("Loader extra data Wizard"));
	this->setMinimumWidth(700);
	this->setMinimumHeight(500);
	//setWindowFlags(Qt::WindowStaysOnTopHint);


}
std::vector<std::vector<QString> *> * LoaderWizard::get_CSV_data(){
	return csvdata;
}

void LoaderWizard::showHelp()
{
	static QString lastHelpMessage;

	QString message;
	QString hmtl_message;

	switch (currentId()) {
	case Page_Intro:
		message = tr("The decision you make here will affect which page you "
					 "get to see next.");
		break;
	case Page_DataFile:
		message=tr("<h2>load file helper</h2>"
						"<h3>add or remove story</h3>"
						"<ul>"
						"<li> click on \"add story\" to add a new story for your experiment (check the split box for a storysplit). </li>"
						"<li> click on \"remove story\" to remove a story or a split in your experiment (all substories of the removed story are removed). </li>"
						"</ul>"
						"<h3>add or remove observation point</h3>"
						"<ul>"
						"<li> click on \"add observation point\"to add a new story for your experiment (check the split box for a storysplit). </li>"
						"<li> click on \"remove observation point\" to remove a observation point. </li>"
						"</ul>"
						"<h3>add or remove events</h3>"
						"<ul>"
						"<li> click on add event to add a new event in a story (storm yellow item). </li>"
						"<li> click on remove event to remove a event in a story . </li>"
						"</ul>"
						"<h3>add or remove samples</h3>"
						"<ul>"
						"<li> click on \"add samples\" to add a new set of sample in your experiment (you need to have defined at least one observation point and one germplasm pool). </li>"
						"<li> click on \"remove samples\" to remove a set of samples. </li>"
						"</ul>");
		//message = tr("The decision you make here will affect which page you "
		//			 "get to see next.");
		break;
	case Page_ParamSet:
		message = tr("The decision you make here will affect which page you "
					 "get to see next.");
		break;
	default:
		message = tr("This help is likely not to be of any help.");
		break;
	}

	if (lastHelpMessage == message)
		message = tr("Sorry, I already gave what help I could. "
					 "Maybe you should try asking a human?");


	QMessageBox::information(this, tr("License Wizard Help"), message);
	lastHelpMessage = message;
}
void LoaderWizard::parseCSVfiles(QString _filename){

}


