#include "individualcreationpage.h"

IndividualCreationPage::IndividualCreationPage(QWidget *parent)
: QWizardPage(parent)
{
	setWindowTitle("choose the individual number ");


}
int IndividualCreationPage::nextId() const
{
	return IndividualWizard::Page_Conclusion;
}
