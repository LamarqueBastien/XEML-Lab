#include "observationintropage.h"

ObservationIntroPage::ObservationIntroPage(QWidget *parent)
: QWizardPage(parent)
{

	topLabel = new QLabel(tr("This wizard will help you define sampling strategy for specific genotype "));
	topLabel->setWordWrap(true);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(topLabel);
	setLayout(layout);
}
/*
int ObservationIntroPage::nextId() const
{
	std::cerr << "Next id" << std::endl;
	return ObservationWizard::Page_Intro;
}
*/

