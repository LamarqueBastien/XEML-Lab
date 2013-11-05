#include "graphicobservationpointitem.h"

GraphicObservationPointItem::GraphicObservationPointItem(ObservationPoint * _obsPoint,qreal _posx,qreal _posy,qreal _width,QGraphicsItem * _parent)
	:QGraphicsPolygonItem(_parent)
{
	this->setParentItem(_parent);
	this->width=_width;
	this->parent=_parent;
	this->obsPoint=_obsPoint;
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
	/*
	std::cerr << "top left x :" << polygon().boundingRect().topLeft().x() << std::endl;
	std::cerr << "top right x :" << polygon().boundingRect().topRight().x() << std::endl;
	std::cerr << "top left y :" << polygon().boundingRect().topLeft().y() << std::endl;
	std::cerr << "bottom left y :" << polygon().boundingRect().bottomLeft().y() << std::endl;
	*/
	QRectF newRect = QRectF(polygon().boundingRect().topLeft().x()-30,polygon().boundingRect().topLeft().y(),polygon().boundingRect().topRight().x()+70,polygon().boundingRect().bottomLeft().y()-50);//.adjusted(-extra, -extra, extra, extra);
	//polygon().boundingRect().topLeft().x()-250,
	//return polygon().boundingRect().adjusted(10,10,10,10);
	//

	return newRect;

	//return polygon().boundingRect();
}
qreal GraphicObservationPointItem::get_posx(){
	return this->posx;
}
qreal GraphicObservationPointItem::get_posy(){
	return this->posy;
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
			_painter->drawRect(QRectF(polygon().boundingRect().topLeft().x()-30,polygon().boundingRect().topLeft().y(),polygon().boundingRect().topRight().x()+70,polygon().boundingRect().bottomLeft().y()-50));
			//_painter->drawRect(polygon().boundingRect());
		}
	}

}
QGraphicsItem * GraphicObservationPointItem::get_parent(){
	return this->parent;
}

void GraphicObservationPointItem::change(){
	prepareGeometryChange();
}

QPolygonF GraphicObservationPointItem::get_polygon(){
	return this->pol;
}

ObservationPoint * GraphicObservationPointItem::get_obspoint(){
	return this->obsPoint;
}
