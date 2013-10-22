#ifndef LOADERINTROPAGE_H
#define LOADERINTROPAGE_H
#include<QtWidgets>
#include<QWizardPage>
#include<QLabel>
#include<QRadioButton>
#include"loaderwizard.h"
class LoaderIntroPage : public QWizardPage
{
		Q_OBJECT
	public:
		LoaderIntroPage(QWidget *parent = 0);
		int nextId() const;
	private:

		QLabel *topLabel;
		QRadioButton *registerRadioButton;
		QRadioButton *evaluateRadioButton;

};


#endif // LOADERINTROPAGE_H
