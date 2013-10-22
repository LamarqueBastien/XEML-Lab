#ifndef GRAPHICSTORYITEM_H
#define GRAPHICSTORYITEM_H
#include<QGraphicsItem>
#include<QLinearGradient>
#include<QGraphicsScene>
#include<QGraphicsSceneDragDropEvent>
#include<QMimeData>
#include<QColor>
#include<QPen>
#include<QPainter>
#include<iostream>
#include"storybase.h"
using namespace std;
using namespace Xeml::Document;

//enum { Type = QGraphicsItem::UserType + 1 };
class GraphicStoryItem : public QGraphicsItem
{

	//enum ItemType { TypeStoryItem = QGraphicsItem::UserType + 1,
					//TypePNEdge = QGraphicsItem::UserType + 2 }
	// Enable the use of qgraphicsitem_cast with this item.


	public:
		GraphicStoryItem(qreal _width,StoryBase * _story,bool _IsStorySplit,qreal posx,qreal posy,QGraphicsItem* parent = 0);
		GraphicStoryItem(qreal _width,StoryBase * _story,QString _label,bool _IsStorySplit,qreal posx,qreal posy,QGraphicsItem* parent = 0);
		enum { Type = QGraphicsItem::UserType + 1 };
		int type() const{return Type;}
		~GraphicStoryItem();
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
		QRectF get_rect();
		void change();
		bool get_isStorySplit();
		QString get_label();
		void set_right(qreal width);
		StoryBase * get_story();

		//void mouseMoveEvent();

		//QVariant itemChange(GraphicsItemChange change, const QVariant &value);
		//void dragEnterEvent(QGraphicsSceneDragDropEvent *event);

	protected:

		//void mousePressEvent(QGraphicsSceneMouseEvent *e);
		//void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
		void hoverMoveEvent(QGraphicsSceneHoverEvent *e);
		void hoverLeaveEvent(QGraphicsSceneHoverEvent *e);

	private:

		qreal posx, posy;
		int myHoverPoint;
		int mySelPoint;
		float myHandlerWidth;
		qreal my_parent_width;
		QString storyLabel;
		bool Pressed;
		bool HeatMap;
		bool IsStorySplit;
		QGraphicsItem * parent;
		QLinearGradient * gradient;
		//QPen pen;
		QPainter * painter;
		QRectF rect;
		StoryBase * story;
		qreal width;


};

#endif // GRAPHICSTORYITEM_H
/*
qreal penWidth = 1;
return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
			  20 + penWidth, 20 + penWidth);
painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
*/


