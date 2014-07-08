#ifndef GRAPHICSTORYSCENE_H
#define GRAPHICSTORYSCENE_H

#include<QMenu>
#include<QAction>
#include<QGraphicsScene>
#include<QtWidgets/QGraphicsSceneMouseEvent>
#include<iostream>
#include<QGraphicsItem>
#include"Views/GraphicStoryView/Items/graphicstoryitem.h"
#include"CoreObjects/storybase.h"
#include"CoreObjects/storysplit.h"
#include"CoreObjects/story.h"
#include"Views/GraphicStoryView/Items/graphiceventitem.h"
#include"Views/GraphicStoryView/Items/graphicobservationpointitem.h"
#include"CoreObjects/Utilities.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"
#include"DialogWindows/eventdialog.h"



using namespace std;
using namespace Xeml::Document;
using namespace Xeml::Utilities;
class GraphicStoryScene : public QGraphicsScene
{
		Q_OBJECT
	public:
		GraphicStoryScene(int  positionY,QGraphicsScene *parent=0);
		GraphicStoryItem * get_item_by_label(QString _label);
		void set_max_item_width(qreal _max_width);
		QGraphicsItem  * get_selected_item();
		void  set_selected_item(QGraphicsItem * _selected_item);

		GraphicStoryItem     * get_selected_story();
		void set_selected_story(GraphicStoryItem * _selected_story);

		GraphicEventItem     * get_selected_event();
		GraphicObservationPointItem * get_selected_obsPoint();
		void set_right_for_childs(QGraphicsItem * _story_moving,qreal _movement);
		void initialize_x_Axis(qreal width,int _zoomFactor);
		void set_doc(ItfDocument  * _currentDoc);
		qreal get_max_width();
		int  positionY;
		void createMenus();
		void createActions();

	protected:
		void mousePressEvent(QGraphicsSceneMouseEvent *e);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
		void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
		void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent);
		void dropEvent(QGraphicsSceneDragDropEvent *event);
		void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
		void dragMoveEvent(QGraphicsSceneDragDropEvent *event);

	signals:

		void variable_to_add(QString _termId);
		void event2edit();
		void sample_to_add();
		void obsPoint2edit();
		void event2removed();
		void obsPoint2added(ObservationPoint * _op, int _posX);
		void event2added(Event * _event, int _posX);
		void obsPoint2removed();
		void itemInserted(GraphicStoryItem *item);
		void show_details_story(GraphicStoryItem * _storyselected);
		void set_details_in_view(StoryBase * _story);
		void set_details_in_view(QGraphicsItem * _item);

		void on_displayed_plot_parameter(StoryBase * _story);
	private:
		QMenu * contextMenu;
		QAction * show_details;
		QAction * display_plot;
		QAction * removeOP;
		QAction * removeStory;
		QAction * removeEvent;
		QAction * editEvent;
		QAction * addSamples;
		QAction * add_story;
		QAction * add_obspoint;
		QAction * addEvent;
		ItfDocument * currentDoc;
		QPointF mouse_pos;

		GraphicEventItem * my_item;
		GraphicStoryItem * my_second_item;
		GraphicStoryItem * my_selected_story;
		GraphicEventItem * my_selected_event;
		GraphicObservationPointItem * my_selected_obsPoint;
		QGraphicsItem * selected_item;
		qreal max_width;
		int zoomFactor;
		int Z_value;
		//int  positionY;
	public slots:
		void add_event(Event *e,int _posX);
	private slots:

		void add_sample();
		void remove_obsPoint();
		void remove_event();
		//void edit_event();
		void add_split_story(QString _label,StoryBase * _story);
		void add_root_story(QString _label,StoryBase * _story);

		void add_event();
		void add_Obs_point(ObservationPoint * _op, int _posX);
		void addObspoint();
		//void changedSelection();
		void details_story();
		void display_plot_parameters();



};


#endif // GRAPHICSTORYSCENE_H
