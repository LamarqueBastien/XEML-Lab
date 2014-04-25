#include "individualcreationpage.h"

IndividualCreationPage::IndividualCreationPage(QWidget *parent)
: QWizardPage(parent)
{



	//setWindowTitle("choose the individual number ");


}
void IndividualCreationPage::initializePage(){

	setTitle(tr("do you really want to create <i></i> individuals with random Ids?"));

	IndividualWizard::get_CSV_data()->push_back(new std::vector<QString>());

	for (int i=0;i<=IndividualWizard::get_individual_count();i++){
		std::cerr << "in da loop" << std::endl;
		if(i==0){
			IndividualWizard::get_CSV_data()->at(0)->push_back("individuals");

		}
		else{
			IndividualWizard::get_CSV_data()->at(0)->push_back(QString::number(qrand()%1000000000 +1));

		}
	}
}

int IndividualCreationPage::nextId() const
{

	return IndividualWizard::Page_Conclusion;
}
