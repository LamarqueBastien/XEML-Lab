#ifndef OBSERVATIONPANEL_H
#define OBSERVATIONPANEL_H

#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"storybase.h"
#include"story.h"
#include"storysplit.h"
#include"observationpoint.h"
#include"observation.h"
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
