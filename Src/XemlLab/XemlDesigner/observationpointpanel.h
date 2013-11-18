#ifndef OBSERVATIONPOINTPANEL_H
#define OBSERVATIONPOINTPANEL_H
#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"storybase.h"
#include"storynode.h"
#include"story.h"
#include"storysplit.h"
#include"observationpoint.h"
#include"observation.h"
#include"observationwizard.h"
#include"storyboard.h"
#include"itfdocument.h"
#include"documentresources.h"

using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;

class ObservationPointPanel : public QWidget
{
		Q_OBJECT
	private:
		ObservationWizard  * obsWizard;
		StoryNode * storyNode;
		StoryBoard * storyBoard;
		ItfDocument * doc;
		DocumentResources * doc_resources;
		QPushButton * removeButton;
		QPushButton * cancelButton;
	public:
		ObservationPointPanel(bool _RemoveMode,QWidget * parent=0);
		QTableView         * view;
		QStandardItemModel * model;
		StoryNode          * get_root_story_node(StoryNode * _current);
		void                 initialize(StoryNode * _storyNode,bool _isStorySplit,ItfDocument * _doc,DocumentResources * _doc_resources);
		ObservationPoint   * get_obsPoint_byId(int _id);
	private slots:
		void display_selected_item(QModelIndex _QMI);
		void remove_obsPoint();
	signals:
		void on_close_window();
};

#endif // OBSERVATIONPOINTPANEL_H
