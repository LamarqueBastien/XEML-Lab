#include "anchorstoryitem.h"

AnchorStoryItem::AnchorStoryItem(qreal _posx,qreal _posy,QGraphicsItem * _parent)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges);
	setAcceptHoverEvents(true);
	setAcceptedMouseButtons(Qt::LeftButton);
	posx=_posx;
	posy=_posy;
	this->rect=QRectF(posx, posy, 20, 20);
	this->parent=_parent;





}
AnchorStoryItem::~AnchorStoryItem(){

}

void AnchorStoryItem::change(){
	prepareGeometryChange();
}

QGraphicsItem * AnchorStoryItem::get_parent(){
	return this->parent;
}

QRectF AnchorStoryItem::boundingRect() const{
	return this->rect;
}
void AnchorStoryItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget){
	Q_UNUSED(widget);
	Q_UNUSED(option);
	QBrush selBrush=QBrush(Qt::red,Qt::SolidPattern);
	QPen selPen=QPen(Qt::red);
	painter->setBrush(selBrush);
	painter->setPen(selPen);
	if(parent!=NULL){
		painter->drawRect(this->rect);
	}
}
