#ifndef PARAMETERPANEL_H
#define PARAMETERPANEL_H
#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"storybase.h"
#include"story.h"
#include"storysplit.h"
#include"dynamicterm.h"
#include"dynamicvalue.h"
#include"dynamicvaluebase.h"
#include"cycle.h"

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
