#ifndef PLATOINTROPAGE_H
#define PLATOINTROPAGE_H


#include<QtWidgets>
#include"platowizard.h"

class PlatoIntroPage : public QWizardPage
{
		Q_OBJECT
	public:
		PlatoIntroPage(QWidget *parent = 0);
		int nextId() const;
	private:
		QLabel * topLabel;

};

#endif // PLATOINTROPAGE_H
