#ifndef LOADERCONCLUSIONPAGE_H
#define LOADERCONCLUSIONPAGE_H
#include<QtWidgets>
#include<QWizardPage>
#include<QLabel>
#include"loaderwizard.h"



class LoaderConclusionPage : public QWizardPage
{
		Q_OBJECT
	private:
		QLabel *Filename;
		QLineEdit *FilenameLineEdit;
	public:
		LoaderConclusionPage(QWidget *parent = 0);
		int nextId() const;
};

#endif // LOADERCONCLUSIONPAGE_H
