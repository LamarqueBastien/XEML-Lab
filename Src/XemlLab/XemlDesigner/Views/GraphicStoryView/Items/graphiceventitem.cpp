#include "graphiceventitem.h"

GraphicEventItem::GraphicEventItem(Event *e,qreal _posx,qreal _posy,qreal _width,QString _label,QDateTime _startdate,QDateTime _eventdate,QGraphicsItem * _parent)
	:QGraphicsItem(_parent)
{
	this->event=e;
	this->setParentItem(_parent);
	this->width=_width;
	this->parent=_parent;
	this->posx=_posx;
	this->posy=_posy;
	this->eventLabel=_label;


	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsFocusable, true);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
	setAcceptDrops(true);
	setAcceptHoverEvents(true);
	setAcceptedMouseButtons(Qt::LeftButton);
	qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	//qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
	qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();
	QPointF point2=QPointF(posx,parent_y+parent_h/2);
	this->rect=QRectF(point2-QPointF(10,10),point2+QPointF(10,10));
	QString tmp_name="";
	if (static_cast<GraphicStoryItem*>(parent)->get_isStorySplit()){
		this->event->set_timepoint(_eventdate);

		tmp_name+=this->eventLabel;
		tmp_name+="\n";
		tmp_name+="-----------\n";
		tmp_name+=translate_second_in_DD_HH_MM_SS(get_seconds_from_date(_startdate,this->event->get_timepoint()));
		this->setToolTip(tmp_name);
		//this->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(_startdate,this->event->get_timepoint())));
	}
	else{
		this->event->set_timepoint(_eventdate);
		tmp_name+=this->eventLabel;
		tmp_name+="\n";
		tmp_name+="-----------\n";
		tmp_name+=translate_second_in_DD_HH_MM_SS(get_seconds_from_date(_startdate,this->event->get_timepoint()));
		this->setToolTip(tmp_name);
		//this->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(_startdate,this->event->get_timepoint())));


	}
	//this->boundingrect=QRectF(point2-QPointF(10,10),point2+QPointF(10,10));
	//this->rect=QRectF(_posx, _posy, 1000, 1000);
}
void GraphicEventItem::change(){
	prepareGeometryChange();
}
Event * GraphicEventItem::get_event(){
	return this->event;
}
QGraphicsItem * GraphicEventItem::get_parent(){
	return this->parent;
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
	QBrush selBrush=QBrush(Qt::yellow,Qt::SolidPattern);
	QPen selPen=QPen(Qt::yellow);
	_painter->setBrush(selBrush);
	_painter->setPen(selPen);
	if(parent!=NULL){
		qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
		//qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
		qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();

		//QPointF point2=QPointF(posx,parent_y+parent_h/2);
		//QRectF()
		//_painter->drawRect(QRectF(point2-QPointF(4,4),point2+QPointF(4,4)));


		//_painter->drawRect(this->rect);
		//_painter->drawRect(boundingRect());

		QPolygonF pol;
		pol << QPointF(posx, parent_y+parent_h/2) << QPointF(posx-6, (parent_y+parent_h/2)-10) << QPointF(posx-4, (parent_y+parent_h/2)-10) << QPointF(posx-9, (parent_y+parent_h/2)-20) << QPointF(posx, (parent_y+parent_h/2)-20) << QPointF(posx, (parent_y+parent_h/2)-10)<< QPointF(posx-1, (parent_y+parent_h/2)-10)<< QPointF(posx, parent_y+parent_h/2);
		_painter->drawPolygon(pol);
		if(isSelected()){
			QBrush selBrush=QBrush(Qt::yellow,Qt::SolidPattern);
			QPen selPen=QPen(Qt::yellow);
			_painter->setBrush(selBrush);
			_painter->setPen(selPen);


			//_painter->drawRect(boundingRect());
		}
		//_painter->drawRect(this->boundingRect());


	}
	else{

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
	/*
	//qreal penWidth = 5;
	//this->pen.setWidth(7);

	//return this->rect;

	//std::cerr << " bounding rect " << std::endl;
	//qreal extra = 20 / 2.0 + myHandlerWidth;
	//extra=0;
	//std::cerr << " extra : " << extra << std::endl;
	*/
	//qreal miny;
	//qreal maxy;
	qreal minx;
	qreal maxx;
	//GraphicStoryItem * test=static_cast<GraphicStoryItem*>(parent);

	//std::cerr << "rect width :" << rect.width() << std::endl;
	//extra=my_parent_width-rect.width();
	//std::cerr << " posY : " << posy << std::endl;
	minx = rect.width() < 0 ? rect.width() : 0;
	maxx = rect.width() < 0 ? 0 : rect.width() ;
	//miny = rect.height() < 0 ? rect.height() : posy;
	//maxy = rect.height() < 0 ? 0 : posy+rect.height();
	qreal parent_y=0;

	//qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	if (this->parent!=NULL){
		parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();
	}




	/*
	std::cerr << "label : " << this->eventLabel.toStdString() << " bounding rect min x :" << minx<<std::endl;
	std::cerr << "label : " << this->eventLabel.toStdString() << " bounding rect max x :" << maxx<<std::endl;
	std::cerr << "label : " << this->eventLabel.toStdString() << " bounding rect min y :" << miny<<std::endl;
	std::cerr << "label : " << this->eventLabel.toStdString() << " bounding rect max y :" << maxy<<std::endl;
	*/
	//QRectF newRect = QRectF(minx,miny,maxx-minx+500,maxy-miny+60).adjusted(-extra, -extra, extra, extra);
	QRectF newRect = QRectF(minx-50,parent_y,maxx-minx+50,60);//.adjusted(-extra, -extra, extra, extra);
	/*
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect adjust min x :" << newRect.left()<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect adjust width :" << newRect.width()<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect adjust min y :" << newRect.top()<<std::endl;
	std::cerr << "label : " << this->storyLabel.toStdString() << " bounding rect adjust height :" << newRect.height()<<std::endl;

	//QRectF newRect = QRectF(minx,miny,maxx,maxy);//.adjusted(-extra, -extra, extra, extra);
	//qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
	//qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
	//qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();

	//QPointF point2=QPointF(posx,200);//parent_y+parent_h/2
	//QRectF(point2-QPointF(4,4),point2+QPointF(4,4));
	//return QRectF(point2-QPointF(4,4),point2+QPointF(4,4));
	//boundingrect= QRectF(minx-250,miny,maxx-minx+500,maxy-miny);
	*/
	return newRect;




}
