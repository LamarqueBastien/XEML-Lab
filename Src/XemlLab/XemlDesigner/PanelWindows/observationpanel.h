#ifndef OBSERVATIONPANEL_H
#define OBSERVATIONPANEL_H

#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"CoreObjects/storybase.h"
#include"CoreObjects/story.h"
#include"CoreObjects/storysplit.h"
#include"CoreObjects/observationpoint.h"
#include"CoreObjects/observation.h"
using namespace Xeml::Document;

class ObservationPanel : public QWidget
{
		Q_OBJECT
	public:
		ObservationPanel(QWidget * parent=0);
		QTableView         * view;
		QStandardItemModel * model;
		void                 initialize(StoryBase * _story,bool _isStorySplit);
	private slots:
		void display_selected_item(QModelIndex _QMI);
};

#endif // OBSERVATIONPANEL_H
