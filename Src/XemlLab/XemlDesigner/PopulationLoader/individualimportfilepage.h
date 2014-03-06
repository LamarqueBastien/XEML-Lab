#ifndef INDIVIDUALIMPORTFILEPAGE_H
#define INDIVIDUALIMPORTFILEPAGE_H
#include<QtWidgets>
#include"individualwizard.h"


class IndividualImportFilePage : public QWizardPage
{
	public:
		IndividualImportFilePage(QWidget *parent = 0);
		int nextId() const;
	private:
		QPushButton * browseButton;
		QSpinBox    * number_individuals;
};

#endif // INDIVIDUALIMPORTFILEPAGE_H
