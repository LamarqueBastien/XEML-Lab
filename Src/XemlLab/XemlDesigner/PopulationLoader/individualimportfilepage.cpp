#include "individualimportfilepage.h"

IndividualImportFilePage::IndividualImportFilePage(QWidget *parent)
: QWizardPage(parent)
{
	this->browseButton=new QPushButton("Browse file");
	this->browseButton->setEnabled(false);
	QVBoxLayout * topLayout=new QVBoxLayout;
	topLayout->addWidget(this->browseButton);
	this->number_individuals=new QSpinBox;
	this->number_individuals->setEnabled(false);
	this->number_individuals->setMinimum(1);
	this->number_individuals->setMaximum(1000);
	this->setLayout(topLayout);
	setWindowTitle("import Individual id from files ");
}
int IndividualImportFilePage::nextId() const
{
	//std::cerr << "Next id" << std::endl;

		return IndividualWizard::Page_Conclusion;

}
