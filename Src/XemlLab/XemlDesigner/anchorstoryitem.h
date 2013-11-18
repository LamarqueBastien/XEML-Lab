#ifndef ANCHORSTORYITEM_H
#define ANCHORSTORYITEM_H
#include<QGraphicsItem>
#include<QPen>
#include<QPainter>
#include<iostream>
class GraphicStoryItem;
using namespace std;

class AnchorStoryItem : public QGraphicsItem
{
	public:
		AnchorStoryItem(qreal _posx,qreal _posy,QGraphicsItem* parent = 0);
		enum { Type = QGraphicsItem::UserType + 4 };
		int type() const{return Type;}
		~AnchorStoryItem();
		void change();
		QGraphicsItem * get_parent();
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

	private:
		QRectF rect;
		QGraphicsItem * parent;
		qreal posx, posy;

};

#endif // ANCHORSTORYITEM_H
