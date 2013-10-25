#include "graphicobservationpointitem.h"

GraphicObservationPointItem::GraphicObservationPointItem(qreal _posx,qreal _posy,qreal _width,QGraphicsItem * _parent)
	:QGraphicsPolygonItem(_parent)
{
	this->setParentItem(_parent);
	this->width=_width;
	this->parent=_parent;
	this->posx=_posx;
	this->posy=_posy;


	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setAcceptDrops(true);
	setAcceptHoverEvents(true);
	setAcceptedMouseButtons(Qt::LeftButton);
	qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();
	this->pol << QPointF(0, parent_y+parent_h/2) << QPointF(-10, (parent_y+parent_h/2)-20) << QPointF(10, (parent_y+parent_h/2)-20)<< QPointF(0, parent_y+parent_h/2);
	setPolygon(this->pol);
}
GraphicObservationPointItem::~GraphicObservationPointItem(){

}

QRectF GraphicObservationPointItem::boundingRect() const{
	return polygon().boundingRect();
}

void GraphicObservationPointItem::paint(QPainter * _painter, const QStyleOptionGraphicsItem *option,QWidget *widget){
	Q_UNUSED(widget);
	QBrush selBrush=QBrush(Qt::red,Qt::SolidPattern);
	QPen selPen=QPen(Qt::red);
	_painter->setBrush(selBrush);
	_painter->setPen(selPen);
	if(parent!=NULL){
		//_painter->drawRect(this->rect);
		_painter->drawPolygon(this->pol);
		if(isSelected()){
			QBrush selBrush=QBrush(Qt::yellow,Qt::SolidPattern);
			QPen selPen=QPen(Qt::yellow);
			_painter->setBrush(selBrush);
			_painter->setPen(selPen);
			_painter->drawPolygon(this->pol);
		}
	}
}

void GraphicObservationPointItem::change(){
	prepareGeometryChange();
}

QPolygonF GraphicObservationPointItem::get_polygon(){
	return this->pol;
}

ObservationPoint * GraphicObservationPointItem::get_obspoint(){

}
