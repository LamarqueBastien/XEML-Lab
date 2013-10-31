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
	setWindowFlags(Qt::WindowStaysOnTopHint);


}
std::vector<std::vector<QString> *> * LoaderWizard::get_CSV_data(){
	return csvdata;
}

void LoaderWizard::showHelp()
{
	static QString lastHelpMessage;

	QString message;

	switch (currentId()) {
	case Page_Intro:
		message = tr("The decision you make here will affect which page you "
					 "get to see next.");
		break;
	default:
		message = tr("This help is likely not to be of any help.");
	}

	if (lastHelpMessage == message)
		message = tr("Sorry, I already gave what help I could. "
					 "Maybe you should try asking a human?");


	QMessageBox::information(this, tr("License Wizard Help"), message);
	lastHelpMessage = message;
}
void LoaderWizard::parseCSVfiles(QString _filename){

}


