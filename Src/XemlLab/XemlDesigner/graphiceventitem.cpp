#include "graphiceventitem.h"

GraphicEventItem::GraphicEventItem(qreal _posx,qreal _posy,qreal _width,QString _label,QGraphicsItem * _parent)
	:QGraphicsItem(_parent)
{
	this->setParentItem(_parent);
	this->width=_width;
	this->parent=_parent;
	this->posx=_posx;
	this->posy=_posy;
	this->eventLabel=_label;

	setFlag(QGraphicsItem::ItemIsSelectable);
	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges);
	setAcceptDrops(true);
	setAcceptHoverEvents(true);
	setAcceptedMouseButtons(Qt::LeftButton);
	this->rect=QRectF(_posx, _posy, 4, 4);
}
void GraphicEventItem::change(){
	prepareGeometryChange();
}
QRectF GraphicEventItem::get_rect(){
	return this->rect;

}
QString GraphicEventItem::get_label(){
	return this->eventLabel;
}
/*
QPainterPath GraphicEventItem::shape() const
{
	QPainterPath path;
	qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();
	QPointF point2=QPointF(posx,parent_y+parent_h/2);
	path.addRect(QRectF(point2-QPointF(4,4),point2+QPointF(4,4)));
	//path.addRect();
	return path;
}
*/
GraphicEventItem::~GraphicEventItem()
{

}
void GraphicEventItem::paint(QPainter * _painter, const QStyleOptionGraphicsItem *option,QWidget *widget){



	Q_UNUSED(widget);
	QBrush selBrush=QBrush(Qt::red,Qt::SolidPattern);
	QPen selPen=QPen(Qt::red);
	_painter->setBrush(selBrush);
	_painter->setPen(selPen);
	qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	//qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
	qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();

	QPointF point2=QPointF(posx,parent_y+parent_h/2);
	_painter->drawRect(QRectF(point2-QPointF(4,4),point2+QPointF(4,4)));
	if(isSelected()){
		QBrush selBrush=QBrush(Qt::yellow,Qt::SolidPattern);
		QPen selPen=QPen(Qt::yellow);
		_painter->setBrush(selBrush);
		_painter->setPen(selPen);


	}
	/*
	if(isSelected()){
		QBrush selBrush=QBrush(Qt::blue,Qt::SolidPattern);
		QPen selPen=QPen(Qt::blue);
		_painter->setBrush(selBrush);
		_painter->setPen(selPen);
		qreal parent_h=static_cast<GraphicEventItem*>(this->parent)->get_rect().height();
		//qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
		qreal parent_y=static_cast<GraphicEventItem*>(this->parent)->get_rect().y();

		QPointF point2=QPointF(posx,parent_y+parent_h/2);
		_painter->drawRect(QRectF(point2-QPointF(2,2),point2+QPointF(2,2)));
	}
	QBrush selBrush=QBrush(Qt::red,Qt::SolidPattern);
	QPen selPen=QPen(Qt::red);
	_painter->setBrush(selBrush);
	_painter->setPen(selPen);
	qreal parent_h=static_cast<GraphicEventItem*>(this->parent)->get_rect().height();
	//qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
	qreal parent_y=static_cast<GraphicEventItem*>(this->parent)->get_rect().y();

	QPointF point2=QPointF(posx,parent_y+parent_h/2);
	_painter->drawRect(QRectF(point2-QPointF(2,2),point2+QPointF(2,2)));
	*/
}
QRectF GraphicEventItem::boundingRect() const{
	//qreal penWidth = 5;
	//this->pen.setWidth(7);

	//return this->rect;

	//std::cerr << " bounding rect " << std::endl;
	//qreal extra = 20 / 2.0 + myHandlerWidth;
	//extra=0;
	//std::cerr << " extra : " << extra << std::endl;
	qreal miny;
	qreal maxy;
	qreal minx;
	qreal maxx;
	GraphicStoryItem * test=static_cast<GraphicStoryItem*>(parent);

	//std::cerr << "rect width :" << rect.width() << std::endl;
	//extra=my_parent_width-rect.width();
	//std::cerr << " extra : " << extra << std::endl;
	minx = rect.width() < 0 ? rect.width() : 0;
	maxx = rect.width() < 0 ? 0 : rect.width() ;
	miny = rect.height() < 0 ? rect.height() : posy;
	maxy = rect.height() < 0 ? 0 : posy+rect.height();



	/*
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect min x :" << minx<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect max x :" << maxx<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect min y :" << miny<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect max y :" << maxy<<std::endl;
	*/
	//QRectF newRect = QRectF(minx,miny,maxx-minx+500,maxy-miny+60).adjusted(-extra, -extra, extra, extra);
	QRectF newRect = QRectF(minx-250,miny,maxx-minx+500,maxy-miny);//.adjusted(-extra, -extra, extra, extra);
	/*
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect adjust min x :" << newRect.left()<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect adjust width :" << newRect.width()<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect adjust min y :" << newRect.top()<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect adjust height :" << newRect.height()<<std::endl;
	*/
	//QRectF newRect = QRectF(minx,miny,maxx,maxy);//.adjusted(-extra, -extra, extra, extra);
	//qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	//qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
	//qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();

	//QPointF point2=QPointF(posx,200);//parent_y+parent_h/2
	//QRectF(point2-QPointF(4,4),point2+QPointF(4,4));
	//return QRectF(point2-QPointF(4,4),point2+QPointF(4,4));
	return newRect;




}
