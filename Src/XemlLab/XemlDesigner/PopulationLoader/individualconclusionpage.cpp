#include "individualconclusionpage.h"

IndividualConclusionPage::IndividualConclusionPage(QWidget *parent)
	:QWizardPage(parent)
{
	topLabel = new QLabel(tr("click to finalize the new pool germplasm "));
	topLabel->setWordWrap(true);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(topLabel);
	setLayout(layout);

}
int IndividualConclusionPage::nextId() const
{
	return -1;
}
