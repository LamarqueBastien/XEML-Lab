#ifndef POOLPANEL_H
#define POOLPANEL_H
#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"storybase.h"
#include"story.h"
#include"storysplit.h"
using namespace Xeml::Document;

class PoolPanel : public QWidget
{
		Q_OBJECT
	public:
		PoolPanel(QWidget * parent=0);
		QTableView         * view;
		QStandardItemModel * model;
		void                 initialize(StoryBase * _story,bool _isStorySplit);
};

#endif // POOLPANEL_H
