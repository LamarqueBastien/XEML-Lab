#include "graphicobservationpointitem.h"

GraphicObservationPointItem::GraphicObservationPointItem(ObservationPoint * _obsPoint,qreal _posx,qreal _posy,qreal _width,QDateTime _startdate,QGraphicsItem * _parent)
	:QGraphicsItem(_parent)
{
	this->setParentItem(_parent);
	this->width=_width;
	this->parent=_parent;
	this->obsPoint=_obsPoint;
	this->posx=_posx;
	this->posy=_posy;
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemIsFocusable, true);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
	setAcceptDrops(true);
	setAcceptHoverEvents(true);
	setAcceptedMouseButtons(Qt::LeftButton);
	qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();
	//this->pol << QPointF(posx, parent_y+parent_h/2) << QPointF(posx-10, (parent_y+parent_h/2)-20) << QPointF(posx+10, (parent_y+parent_h/2)-20)<< QPointF(posx, parent_y+parent_h/2);

	QPointF point2=QPointF(posx,parent_y+parent_h/2);
	this->rect=QRectF(point2-QPointF(10,10),point2+QPointF(10,10));

	if (static_cast<GraphicStoryItem*>(parent)->get_isStorySplit()){
		this->obsPoint->set_timepoint(static_cast<StorySplit*>(static_cast<GraphicStoryItem*>(parent)->get_story())->get_timepoint());
		this->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(_startdate,this->obsPoint->get_timepoint())));
	}
	else{
		this->obsPoint->set_timepoint(_startdate);
		this->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(_startdate,this->obsPoint->get_timepoint())));

	}
	//this->pol << QPointF(posx, parent_y+parent_h/2) << QPointF(posx-6, (parent_y+parent_h/2)-10) << QPointF(posx-4, (parent_y+parent_h/2)-10) << QPointF(posx-9, (parent_y+parent_h/2)-20) << QPointF(posx, (parent_y+parent_h/2)-20) << QPointF(posx, (parent_y+parent_h/2)-10)<< QPointF(posx-1, (parent_y+parent_h/2)-10)<< QPointF(posx, parent_y+parent_h/2);

	//setPolygon(this->pol);
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
	/*
	std::cerr << "rect.width() :" << rect.width() << std::endl;
	std::cerr << "posx :" << posx << std::endl;
	std::cerr << "posy :" << posy << std::endl;
	*/
	qreal miny;
	qreal maxy;
	qreal minx;
	qreal maxx;
	minx = rect.width() < 0 ? rect.width() : 0;
	maxx = rect.width() < 0 ? 0 : rect.width() ;
	miny = rect.height() < 0 ? rect.height() : posy;
	maxy = rect.height() < 0 ? 0 : posy-rect.height();
	//miny =0;
	/*
	std::cerr << "value minx :" << minx-50 << std::endl;
	std::cerr << "value maxx :" << maxx-minx+50 << std::endl;
	std::cerr << "value miny :" << miny << std::endl;
	std::cerr << "value maxy :" << maxy << std::endl;
	*/
	//qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	qreal parent_y=0;
	if (this->parent!=NULL){
		parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();
	}
	QRectF newRect = QRectF(minx-50,parent_y,maxx-minx+50,60);//.adjusted(-extra, -extra, extra, extra);


	//QRectF newRect = QRectF(polygon().boundingRect().topLeft().x()-30,polygon().boundingRect().topLeft().y(),polygon().boundingRect().topRight().x()+70,polygon().boundingRect().bottomLeft().y()-50);//.adjusted(-extra, -extra, extra, extra);


	//polygon().boundingRect().topLeft().x()-250,
	//return polygon().boundingRect().adjusted(10,10,10,10);
	//
	//return polygon().boundingRect();
	return newRect;
	//return this->rect;

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
		qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
		//qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
		qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();
		//_painter->drawRect(this->rect);
		//_painter->drawPolygon(this->pol);
		QPolygonF pol;
		pol << QPointF(posx, parent_y+parent_h/2) << QPointF(posx-6, (parent_y+parent_h/2)-10) << QPointF(posx-4, (parent_y+parent_h/2)-10) << QPointF(posx-9, (parent_y+parent_h/2)-20) << QPointF(posx, (parent_y+parent_h/2)-20) << QPointF(posx, (parent_y+parent_h/2)-10)<< QPointF(posx-1, (parent_y+parent_h/2)-10)<< QPointF(posx, parent_y+parent_h/2);
		_painter->drawPolygon(pol);
		if(isSelected()){
			QBrush selBrush=QBrush(Qt::yellow,Qt::SolidPattern);
			QPen selPen=QPen(Qt::yellow);
			_painter->setBrush(selBrush);
			_painter->setPen(selPen);
			//_painter->drawPolygon(this->pol);
			//_painter->drawRect(QRectF(polygon().boundingRect().topLeft().x()-30,polygon().boundingRect().topLeft().y(),polygon().boundingRect().topRight().x()+70,polygon().boundingRect().bottomLeft().y()-50));
			//_painter->drawRect(boundingRect());
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
