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
		GraphicStoryItem     * get_selected_story();
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
		void dropEvent(QDropEvent *event);
		void dragEnterEvent(QDragEnterEvent *event);
		void dragMoveEvent(QDragMoveEvent *event);

	signals:

		void event2edit();
		void obsPoint2edit();
		void event2removed();
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
		ItfDocument * currentDoc;

		GraphicEventItem * my_item;
		GraphicStoryItem * my_second_item;
		GraphicStoryItem * my_selected_story;
		GraphicEventItem * my_selected_event;
		GraphicObservationPointItem * my_selected_obsPoint;
		qreal max_width;
		int zoomFactor;
		//int  positionY;
	private slots:

		void remove_obsPoint();
		void remove_event();
		void edit_event();
		void add_split_story(QString _label,StoryBase * _story);
		void add_root_story(QString _label,StoryBase * _story);
		void add_event(Event *e);
		void add_Obs_point(ObservationPoint * _op);
		//void changedSelection();
		void details_story();
		void display_plot_parameters();



};


#endif // GRAPHICSTORYSCENE_H
