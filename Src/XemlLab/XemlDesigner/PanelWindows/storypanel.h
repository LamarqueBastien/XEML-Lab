#ifndef STORYPANEL_H
#define STORYPANEL_H

#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"CoreObjects/storybase.h"
#include"CoreObjects/story.h"
#include"CoreObjects/storysplit.h"
using namespace Xeml::Document;

class StoryPanel : public QWidget
{
		Q_OBJECT
	public:
		StoryPanel(QWidget * parent=0);
		QTableView         * view;
		QStandardItemModel * model;
		void                 initialize(StoryBase * _story,bool _isStorySplit);

};

#endif // STORYPANEL_H
