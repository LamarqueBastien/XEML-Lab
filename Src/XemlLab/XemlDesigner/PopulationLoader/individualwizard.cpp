#include "individualwizard.h"
#include"individualintropage.h"
#include"individualimportfilepage.h"
#include"individualconclusionpage.h"

IndividualWizard::IndividualWizard(IndividualsPool * _pool, QWidget *parent)
	: QWizard(parent)
{

	this->pool=_pool;
	this->setMinimumHeight(700);
	this->setMinimumWidth(1100);

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
void IndividualWizard::accept(){


}
