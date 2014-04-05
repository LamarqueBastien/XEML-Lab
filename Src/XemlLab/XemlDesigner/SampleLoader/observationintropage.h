#ifndef OBSERVATIONINTROPAGE_H
#define OBSERVATIONINTROPAGE_H
#include<QtWidgets>
#include<QWizardPage>
#include<QLabel>
#include<QRadioButton>
#include"observationwizard.h"
class ObservationIntroPage : public QWizardPage
{
		Q_OBJECT
	public:
		ObservationIntroPage(QWidget *parent = 0);
		//int nextId() const;
		QLabel *topLabel;

};

#endif // OBSERVATIONINTROPAGE_H
