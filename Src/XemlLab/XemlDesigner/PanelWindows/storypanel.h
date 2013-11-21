#ifndef STORYPANEL_H
#define STORYPANEL_H

#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"CoreObjects/storybase.h"
#include"CoreObjects/story.h"
#include"CoreObjects/storysplit.h"
#include"CoreObjects/Utilities.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"
using namespace Xeml::Utilities;
using namespace Xeml::Document;

class StoryPanel : public QWidget
{
		Q_OBJECT
	public:
		StoryPanel(QWidget * parent=0);
		QTableView         * view;
		QStandardItemModel * model;
		void                 initialize(ItfDocument * _current_doc, StoryBase * _story,bool _isStorySplit);

};

#endif // STORYPANEL_H
