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
		QLabel             * ind_label;
		QSpinBox           * ind_box;
		QCheckBox   * import_from_files;
	private slots:
		void on_value_changed(int _value);
};

#endif // INDIVIDUALINTROPAGE_H
