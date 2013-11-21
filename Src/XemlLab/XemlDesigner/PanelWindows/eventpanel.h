#ifndef EVENTPANEL_H
#define EVENTPANEL_H
#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"CoreObjects/storybase.h"
#include"CoreObjects/story.h"
#include"CoreObjects/storysplit.h"
#include"CoreObjects/event.h"
using namespace Xeml::Document;

class EventPanel : public QWidget
{
		Q_OBJECT
	public:
		EventPanel(bool _RemoveMode,QWidget * parent=0);
		QTableView         * view;
		QStandardItemModel * model;
		void                 initialize(StoryBase * _story,bool _isStorySplit);
		QPushButton * removeButton;
		QPushButton * cancelButton;

	private slots:
		void remove_event();
	private:
		StoryBase * current_story;
};

#endif // EVENTPANEL_H
