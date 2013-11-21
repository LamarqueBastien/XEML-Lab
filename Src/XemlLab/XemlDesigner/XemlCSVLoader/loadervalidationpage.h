#ifndef LOADERVALIDATIONPAGE_H
#define LOADERVALIDATIONPAGE_H
#include<QtWidgets>
#include<QWizardPage>
#include<QLabel>
#include"loaderwizard.h"

class LoaderValidationPage : public QWizardPage
{
		Q_OBJECT
	private:
		QLabel *Filename;
		QLineEdit *FilenameLineEdit;
		QPushButton *validate;
	public:
		LoaderValidationPage(QWidget *parent = 0);
		int nextId() const;
};

#endif // LOADERVALIDATIONPAGE_H
