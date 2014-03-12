#ifndef INDIVIDUALCONCLUSIONPAGE_H
#define INDIVIDUALCONCLUSIONPAGE_H
#include<QtWidgets>
#include"individualwizard.h"

class IndividualConclusionPage : public QWizardPage
{
		Q_OBJECT
	public:
		IndividualConclusionPage(QWidget *parent=0);
		int nextId() const;
	protected:
		void initializePage();
	private:

		QLabel *topLabel;
		QTableView * table;
		QStandardItemModel * model;
		QModelIndexList * indexlist;
};

#endif // INDIVIDUALCONCLUSIONPAGE_H
