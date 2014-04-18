#include "individualwizard.h"
#include"individualintropage.h"
#include"individualimportfilepage.h"
#include"individualconclusionpage.h"

std::vector<std::vector<QString> * > * IndividualWizard::csvdata = new std::vector<std::vector<QString> *>();
int IndividualWizard::individuals_count=0;

IndividualWizard::IndividualWizard(IndividualsPool * _pool, QWidget *parent)
	: QWizard(parent)
{

	this->pool=_pool;
	this->setMinimumHeight(600);
	this->setMinimumWidth(600);

	individualIntroPage=new IndividualIntroPage;
	setPage(Page_Intro, individualIntroPage);

	individualImportFilePage=new IndividualImportFilePage;
	setPage(Page_ImportFile,individualImportFilePage);

	individualCreationPage =new IndividualCreationPage;
	setPage(Page_Creation,individualCreationPage);

	individualConclusionPage=new IndividualConclusionPage;
	setPage(Page_Conclusion,individualConclusionPage);

	setStartId(Page_Intro);
	//setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo.png"));


	setOption(HaveHelpButton, true);
	connect(this, SIGNAL(helpRequested()), this, SLOT(showHelp()));

	setWindowTitle("defines population for specific pool ");

#ifndef Q_OS_MAC
	setWizardStyle(ModernStyle);

#endif
}
void IndividualWizard::showHelp()
{
	static QString lastHelpMessage;

	QString message;

	switch (currentId()) {
	case Page_Intro:
		message = tr("The decision you make here will affect which page you "
					 "get to see next.");
		break;
	case Page_ImportFile:
		message = tr("The decision you make here will affect which page you "
					 "get to see next.");
		break;
	case Page_Creation:
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
std::vector<std::vector<QString> *> * IndividualWizard::get_CSV_data(){
	return csvdata;
}
int IndividualWizard::get_individual_count(){
	return individuals_count;
}
void IndividualWizard::set_individual_count(int _count){
	individuals_count=_count;
}

void IndividualWizard::accept(){
	for (int j =1;j<IndividualWizard::get_CSV_data()->at(0)->size();j++){
		//std::cerr << "vector size" << IndividualWizard::get_CSV_data()->at(0)->size() << std::endl;
		//std::cerr << IndividualWizard::get_CSV_data()->at(0)->at(j).toStdString() << std::endl;
		//this->model->findItems("IndividualsId",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(new QStandardItem(IndividualWizard::get_CSV_data()->at(0)->at(j)));

		//this->model->setItem(j-1,0,new QStandardItem(IndividualWizard::get_CSV_data()->at(0)->at(j)));
		Individual * ind=new Individual(static_cast<QString>(IndividualWizard::get_CSV_data()->at(0)->at(j)).toInt());
		//std::cerr << "ind id :" << ind->get_id() << std::endl;
		pool->add_Individual(ind);


	}
	IndividualWizard::get_CSV_data()->at(0)->clear();
	IndividualWizard::get_CSV_data()->clear();
	QDialog::accept();



}
