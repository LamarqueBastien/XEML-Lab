#ifndef OBSERVATIONGENOTYPEPAGE_H
#define OBSERVATIONGENOTYPEPAGE_H
#include<QtWidgets>
#include <QWizard>
#include<iostream>
#include"CoreObjects/storynode.h"
#include"CoreObjects/story.h"
#include"CoreObjects/observationpoint.h"
#include<QMetaType>
using namespace Xeml::Document;


Q_DECLARE_METATYPE(QItemSelectionModel*)
class ObservationGenotypePage : public QWizardPage
{
		Q_OBJECT
		Q_PROPERTY(QItemSelectionModel* selectionModel READ selectionModel)

	public:
		ObservationGenotypePage(QStringList * _genList,QWidget *parent = 0);
		QItemSelectionModel * selectionModel(void)
		{
			return genView->selectionModel();
		}
	private:

		QLabel           * germPlasm;
		QLineEdit        * germPlasmEdit;
		QStringList      * genList;
		QListView        * genView;
		QStringListModel * genModel;
	private slots:
		void validate(QModelIndex _QMI);
		void validate_list(QModelIndexList _QMIL);
};

#endif // OBSERVATIONGENOTYPEPAGE_H
