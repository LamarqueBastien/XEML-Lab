#ifndef GRAPHICEVENTITEM_H
#define GRAPHICEVENTITEM_H
#include<QGraphicsItem>
#include<QGraphicsSceneDragDropEvent>
#include<QColor>
#include<QPen>
#include<QPainter>
#include<iostream>
#include"Views/GraphicStoryView/Items/graphicstoryitem.h"
#include"CoreObjects/event.h"
#include<QPainterPath>
using namespace std;
using namespace Xeml::Document;

class GraphicEventItem : public QGraphicsItem
{
	public:
		GraphicEventItem(Event *e,qreal _posx,qreal _posy,qreal _width,QString _label,QDateTime _startdate,QDateTime _eventdate,QGraphicsItem* parent = 0);
		enum { Type = QGraphicsItem::UserType + 2 };
		int type() const{return Type;}
		~GraphicEventItem();
		QRectF boundingRect() const;
		//QPainterPath shape() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
		QString get_label();
		void change();
		QRectF get_rect();
		Event * get_event();
		QGraphicsItem * get_parent();
		void set_label(QString _label);
	private:
		qreal posx, posy;
		QDateTime document_startDate;
		QGraphicsItem * parent;
		QRectF rect;
		qreal width;
		QString eventLabel;
		Event * event;
		QRectF boundingrect;
};

#endif // GRAPHICEVENTITEM_H
