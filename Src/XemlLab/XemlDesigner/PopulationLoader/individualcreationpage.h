#ifndef INDIVIDUALCREATIONPAGE_H
#define INDIVIDUALCREATIONPAGE_H
#include<QtWidgets>
#include"individualwizard.h"

class IndividualCreationPage : public QWizardPage
{
		Q_OBJECT
	public:
		IndividualCreationPage(QWidget *parent=0);
		int nextId() const;
};

#endif // INDIVIDUALCREATIONPAGE_H
