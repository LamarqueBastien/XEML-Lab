#include "loaderconclusionpage.h"

LoaderConclusionPage::LoaderConclusionPage(QWidget *parent)
	: QWizardPage(parent)
{
	setTitle(tr("Evaluate <i>Super Product One</i>&trade;"));
	setSubTitle(tr("Please fill both fields. Make sure to provide a valid "
					   "email address (e.g., john.smith@example.com)."));

	Filename = new QLabel(tr("F&ilename:"));
	FilenameLineEdit = new QLineEdit;
	Filename->setBuddy(FilenameLineEdit);
	registerField("conclusionFileName*", FilenameLineEdit);
}
int LoaderConclusionPage::nextId() const
{
	return -1;
}
