#ifndef INDIVIDUALINTROPAGE_H
#define INDIVIDUALINTROPAGE_H
#include<QtWidgets>
//#include<QWizardPage>
//#include<QLabel>
//#include<QRadioButton>
#include"individualwizard.h"

class IndividualIntroPage : public QWizardPage
{
		Q_OBJECT
	public:
		IndividualIntroPage(QWidget *parent = 0);

		int nextId() const;
	private:
		QLabel *topLabel;
		QLabel *bottomLabel;
		QCheckBox   * import_from_files;
};

#endif // INDIVIDUALINTROPAGE_H
