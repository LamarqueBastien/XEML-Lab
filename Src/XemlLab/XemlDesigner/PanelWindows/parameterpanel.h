#ifndef PARAMETERPANEL_H
#define PARAMETERPANEL_H
#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"CoreObjects/storybase.h"
#include"CoreObjects/story.h"
#include"CoreObjects/storysplit.h"
#include"CoreObjects/dynamicterm.h"
#include"CoreObjects/dynamicvalue.h"
#include"CoreObjects/dynamicvaluebase.h"
#include"CoreObjects/cycle.h"

using namespace Xeml::Document;


class ParameterPanel : public QWidget
{
		Q_OBJECT
	public:
		ParameterPanel(bool _RemoveMode,QWidget * parent=0);
		QTableView         * view;
		QStandardItemModel * model;
		void                 initialize(StoryBase * _story,bool _isStorySplit);
	private:
		QPushButton * removeButton;
		QPushButton * cancelButton;
		StoryBase * current_story;
	private slots:
		void remove_parameter();

};

#endif // PARAMETERPANEL_H
