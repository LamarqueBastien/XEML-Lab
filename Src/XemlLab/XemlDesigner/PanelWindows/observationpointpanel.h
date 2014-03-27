#ifndef OBSERVATIONPOINTPANEL_H
#define OBSERVATIONPOINTPANEL_H
#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QStandardItemModel>
#include"CoreObjects/storybase.h"
#include"CoreObjects/storynode.h"
#include"CoreObjects/story.h"
#include"CoreObjects/storysplit.h"
#include"CoreObjects/observationpoint.h"
#include"CoreObjects/observation.h"
#include"SampleLoader/observationwizard.h"
#include"CoreObjects/storyboard.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/documentresources.h"

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
		QDialogButtonBox * buttonBox;
		bool Remove_mode;
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
		void show_help();
	signals:
		void on_close_window();

};

#endif // OBSERVATIONPOINTPANEL_H
