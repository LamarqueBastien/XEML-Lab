#ifndef OBSERVATIONGENOTYPEPAGE_H
#define OBSERVATIONGENOTYPEPAGE_H
#include<QtWidgets>
#include <QWizard>
#include<iostream>
#include"CoreObjects/storynode.h"
#include"CoreObjects/story.h"
#include"CoreObjects/observationpoint.h"
using namespace Xeml::Document;


class ObservationGenotypePage : public QWizardPage
{
		Q_OBJECT
	public:
		ObservationGenotypePage(StoryNode * _root,QWidget *parent = 0);
	private:

		QLabel           * germPlasm;
		QLineEdit        * germPlasmEdit;
		QStringList      * genList;
		QListView        * genView;
		QStringListModel * genModel;
	private slots:
		void validate(QModelIndex _QMI);
};

#endif // OBSERVATIONGENOTYPEPAGE_H