#ifndef GRAPHICSTORYSCENE_H
#define GRAPHICSTORYSCENE_H

#include<QGraphicsScene>
#include<QGraphicsSceneMouseEvent>
#include<iostream>
#include"graphicstoryitem.h"
#include"storybase.h"
#include"storysplit.h"
#include"story.h"
#include<QGraphicsItem>
#include"graphiceventitem.h"
#include"graphicobservationpointitem.h"
#include"Utilities.h"
#include"itfdocument.h"
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
		void set_right_for_childs(GraphicStoryItem * _story_moving,qreal _movement);

		void set_doc(ItfDocument  * _currentDoc);

		int  positionY;
	protected:
		void mousePressEvent(QGraphicsSceneMouseEvent *e);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
	signals:
		void itemInserted(GraphicStoryItem *item);
	private:
		ItfDocument * currentDoc;
		GraphicEventItem * my_item;
		GraphicStoryItem * my_second_item;
		GraphicStoryItem * my_selected_story;
		GraphicEventItem * my_selected_event;
		GraphicObservationPointItem * my_selected_obsPoint;
		qreal max_width;
		//int  positionY;
	private slots:
		void add_split_story(QString _label,StoryBase * _story);
		void add_root_story(QString _label,StoryBase * _story);
		void add_event(Event *e);
		void changedSelection();



};


#endif // GRAPHICSTORYSCENE_H
