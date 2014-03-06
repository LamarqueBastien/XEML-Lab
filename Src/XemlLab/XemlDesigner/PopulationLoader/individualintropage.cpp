#include "individualintropage.h"

IndividualIntroPage::IndividualIntroPage(QWidget *parent)
: QWizardPage(parent)
{
	topLabel = new QLabel(tr("This wizard will help you define your population for this specific germplasm "));
	topLabel->setWordWrap(true);
	bottomLabel = new QLabel(tr("check the box if you want to import individuals from file else choose the number of individuals you want to use (individual are randomly created)"));
	import_from_files=new QCheckBox("import from tabular file (csv, xls)");
	import_from_files->setCheckState(Qt::Unchecked);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(topLabel);
	layout->addStretch(1);
	layout->addWidget(bottomLabel);
	layout->addWidget(import_from_files);
	setLayout(layout);
	setWindowTitle("defines population for specific pool ");
}
int IndividualIntroPage::nextId() const
{
	//std::cerr << "Next id" << std::endl;
	if (this->import_from_files->isChecked()){
		return IndividualWizard::Page_ImportFile;
	}
	else{
		return IndividualWizard::Page_Creation;
	}

}
