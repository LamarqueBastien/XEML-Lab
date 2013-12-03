#ifndef LOADERSTORYPAGE_H
#define LOADERSTORYPAGE_H
#include<QtWidgets>
#include"Interface/itfdocument.h"
#include<QTreeView>
#include"Views/Items/experimentitem.h"
#include"Views/Items/storyitem.h"
#include"CoreObjects/storynode.h"
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;

class LoaderStoryPage : public QWidget
{
		Q_OBJECT
	public:
		LoaderStoryPage(QStandardItemModel * _model,int _column,int _row,ItfDocument * _doc,QWidget * parent=0);
		void clean_tree();
		void createExperiment(ItfDocument *  _current_xeml);
		void build_story_hierarchy(StoryNode * _node,std::list<StoryNode*> * _processed_nodes,StoryItem * _tmp_item,QString _storyname);
		bool contains(StoryNode * _node,std::list<StoryNode*> * _processed_nodes,QString _storyname);
		bool Tree_is_loaded();
		//void set_up_finished(QString _storyname);



	private:
		bool                 Tree_loaded;
		int                  row;
		int                  column;
		QString              experimentName;
		ItfDocument        * currentDoc;
		QTreeView          * storytree;
		QStandardItemModel * my_treestory;
		QLabel             * storyLabel;
		QLabel             * bottomLabel;
		QPushButton        * okButton;
		QPushButton        * removeButton;
		QLineEdit          * storyChosen;
		StoryNode          * current_storyNode;
	private slots:
		void on_story_selected(QModelIndex _idx);
		void set_up_finished(QString _storyname);
		void closed(bool);
		void removed();
	signals:
		void send_details_story(int _column,int _row,StoryNode * current_storyNode);
};

#endif // LOADERSTORYPAGE_H
