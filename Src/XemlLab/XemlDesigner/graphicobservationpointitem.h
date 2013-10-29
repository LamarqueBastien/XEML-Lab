#ifndef GRAPHICOBSERVATIONPOINTITEM_H
#define GRAPHICOBSERVATIONPOINTITEM_H
#include<QGraphicsItem>
#include<QGraphicsSceneDragDropEvent>
#include<QColor>
#include<QPen>
#include<QPainter>
#include<iostream>
#include<QGraphicsPolygonItem>
#include"graphicstoryitem.h"
#include"observationpoint.h"
using namespace std;
using namespace Xeml::Document;

class GraphicObservationPointItem : public QGraphicsPolygonItem
{
	public:
		GraphicObservationPointItem(ObservationPoint * _obsPoint,qreal _posx,qreal _posy,qreal _width,QGraphicsItem * parent);
		enum { Type = QGraphicsItem::UserType + 3 };
		int type() const{return Type;}
		~GraphicObservationPointItem();
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
		void change();
		QPolygonF get_polygon();
		ObservationPoint * get_obspoint();
		qreal get_posx();
		qreal get_posy();

	private:
		ObservationPoint * obsPoint;
		qreal posx, posy;
		QGraphicsItem * parent;
		QPolygonF pol;
		qreal width;
		int obspointId;
		//ObservationPoint * oP;

};

#endif // GRAPHICOBSERVATIONPOINTITEM_H
