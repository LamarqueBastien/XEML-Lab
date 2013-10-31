#include "loaderconclusionpage.h"

LoaderConclusionPage::LoaderConclusionPage(QWidget *parent)
	: QWizardPage(parent)
{
	setTitle(tr("Evaluate "));
	setSubTitle(tr("Please fill both fields."));

	Filename = new QLabel(tr("F&ilename:"));
	FilenameLineEdit = new QLineEdit;
	Filename->setBuddy(FilenameLineEdit);
	registerField("conclusionFileName*", FilenameLineEdit);
}
int LoaderConclusionPage::nextId() const
{
	return -1;
}
