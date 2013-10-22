#include "loadervalidationpage.h"

LoaderValidationPage::LoaderValidationPage(QWidget *parent)
	: QWizardPage(parent)
{
	setTitle(tr("Validate integration of new parameter"));
	//setSubTitle(tr("Please fill both fields. Make sure to provide a valid "
				//	   "email address (e.g., john.smith@example.com)."));
	validate = new QPushButton("Validate");
	//Filename = new QLabel(tr("F&ilename:"));
	//FilenameLineEdit = new QLineEdit;
	//Filename->setBuddy(FilenameLineEdit);
	//registerField("validationFileName*", FilenameLineEdit);
}
int LoaderValidationPage::nextId() const
{
	return -1;
}
