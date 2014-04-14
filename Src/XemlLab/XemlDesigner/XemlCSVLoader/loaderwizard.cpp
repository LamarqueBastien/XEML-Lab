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
				   "<ol>"
				   "<li>Select the right delimiters for your files.</li>"
				   "<li>Click on \"browse\" or type in edit area the file you want to load.</li>"
				   "<li>Click on \"load\" to load the file. all headers found will be displayed in the table called header selection</li>"
				   "<li>Select by clicking headers you want to keep (you always need to keep a time header) then click on \"continue\"</li>"
				   "</ol>");
		//message = tr("The decision you make here will affect which page you "
		//			 "get to see next.");
		break;
	case Page_ParamSet:
		message = tr("<h2>add term helper</h2>"
					 "<ol>"
					 "<li>double Click on cell in the first or second column in the table.</li>"
					 "<li>Select a appropriate term and story in the opening windows</li>"
					 "</ol>"
					 "<h2>Add time expression helper</h2>"
					 "<ol>"
					 "<li>double Click on cell in the third column in the table.</li>"
					 "<li>Select a appropriate expression for your time values</li>"
					 "</ol>");
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


