#include "individualwizard.h"
#include"individualintropage.h"
#include"individualimportfilepage.h"
#include"individualconclusionpage.h"

std::vector<std::vector<QString> * > * IndividualWizard::csvdata = new std::vector<std::vector<QString> *>();


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
	setWindowTitle("defines population for specific pool ");

}
std::vector<std::vector<QString> *> * IndividualWizard::get_CSV_data(){
	return csvdata;
}
void IndividualWizard::accept(){
	for (int j =1;j<IndividualWizard::get_CSV_data()->at(0)->size();j++){
		//std::cerr << "vector size" << IndividualWizard::get_CSV_data()->at(0)->size() << std::endl;
		//std::cerr << IndividualWizard::get_CSV_data()->at(0)->at(j).toStdString() << std::endl;
		//this->model->findItems("IndividualsId",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(new QStandardItem(IndividualWizard::get_CSV_data()->at(0)->at(j)));

		//this->model->setItem(j-1,0,new QStandardItem(IndividualWizard::get_CSV_data()->at(0)->at(j)));
		Individual * ind=new Individual(static_cast<QString>(IndividualWizard::get_CSV_data()->at(0)->at(j)).toInt());
		pool->add_Individual(ind);


	}
	QDialog::accept();



}
