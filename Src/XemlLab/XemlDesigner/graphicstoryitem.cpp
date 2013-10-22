#include "graphicstoryitem.h"


GraphicStoryItem::GraphicStoryItem(qreal _width,StoryBase * _story,bool _IsStorySplit,qreal _posx,qreal _posy,QGraphicsItem * _parent)
	:QGraphicsItem(_parent)
{

	this->story=_story;
	this->posx=_posx;
	this->posy=posy;
	this->IsStorySplit=_IsStorySplit;
	myHandlerWidth=2.0;
	this->width=_width;
	this->parent=_parent;
	this->setParentItem(_parent);
	this->rect=QRectF(posx, posy, this->width, 60);
	this->setToolTip("test");
	this->storyLabel="root";

	//this->setPos(0,posy);
	setFlag(QGraphicsItem::ItemIsSelectable);
	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges);
	//setMouseTracking(true);
	setAcceptDrops(true);
	setAcceptHoverEvents(true);
	setAcceptedMouseButtons(Qt::LeftButton);


	this->HeatMap=false;
	if(!this->IsStorySplit){
		this->HeatMap=false;
	}
	this->Pressed=false;
	//this->setOpacity(0.4);
	//setAcceptedMouseButtons(true);






}
GraphicStoryItem::GraphicStoryItem(qreal _width,StoryBase * _story,QString _label,bool _IsStorySplit,qreal _posx,qreal _posy,QGraphicsItem * _parent)
	:QGraphicsItem(_parent)
{
	this->story=_story;
	this->posx=_posx;
	this->posy=_posy;
	this->IsStorySplit=_IsStorySplit;
	myHandlerWidth=2.0;
	this->parent=_parent;
	this->width=_width;
	this->setParentItem(_parent);
	//this->setParentItem(_parent);
	this->rect=QRectF(posx, posy, this->width, 60);
	this->storyLabel=_label;

	//this->setPos(0,posy);
	setFlag(QGraphicsItem::ItemIsSelectable);
	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges);
	//setMouseTracking(true);
	setAcceptDrops(true);
	setAcceptHoverEvents(true);
	setAcceptedMouseButtons(Qt::LeftButton);

	this->HeatMap=false;
	if(!this->IsStorySplit){
		this->HeatMap=false;
	}
	this->Pressed=false;
	//this->setOpacity(0.4);
	//setAcceptedMouseButtons(true);






}
void GraphicStoryItem::set_right(qreal width){
	rect.setRight(width);
	//update();
}
StoryBase * GraphicStoryItem::get_story(){
	return this->story;
}

QRectF GraphicStoryItem::get_rect(){
	return this->rect;

}
void GraphicStoryItem::change(){
	prepareGeometryChange();
}
QString GraphicStoryItem::get_label(){
	return this->storyLabel;
}

GraphicStoryItem::~GraphicStoryItem()
{

}

void GraphicStoryItem::paint(QPainter * _painter, const QStyleOptionGraphicsItem *option,QWidget *widget){



	Q_UNUSED(widget);

	//QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
	//if (option->state & QStyle::State_MouseOver)
		//fillColor = fillColor.light(125);
	//const qreal lod = option->levelOfDetailFromTransform(_painter->worldTransform());
	//QRectF tmp_rect=boundingRect();
	//QBrush brush(Qt::blue);
	//QLinearGradient gradient;
	//_painter->setCompositionMode(QPainter::CompositionMode_Multiply);
	QLinearGradient gradient(boundingRect().topLeft(),boundingRect().topRight());
	gradient.setColorAt(0, QColor::fromRgbF(0.2, 0.4, 0.2, 0.5));
	gradient.setColorAt(0.25, QColor::fromRgbF(0.1, 0.2, 0.9, 0.5));
	gradient.setColorAt(0.5, QColor::fromRgbF(0.8, 0.4, 0.2, 0.5));
	gradient.setColorAt(0.75, QColor::fromRgbF(0.8, 0.4, 0.9, 0.5));

	gradient.setColorAt(1, QColor::fromRgbF(0.4, 0.1, 0.6, 0.5));

	QBrush brush(gradient);
	brush.setStyle(Qt::LinearGradientPattern);
	if(Pressed){
		brush.setColor(Qt::green);
	}
	else{
		//_painter->setBrush(brush);

		brush.setColor(Qt::yellow);
	}
	//_painter->fillRect(tmp_rect,brush);
	//_painter->drawRect(tmp_rect);
	_painter->setBrush(brush);
	//_painter->drawRect(QRectF(posx,posy,rect.width(),rect.height()));
	_painter->drawRect(this->rect);



	//std::cerr << "rect width : " << rect.width()/10 << std::endl;

	if(IsStorySplit){
		//draw the connector between the storysplit and its parent story

		qreal parent_h=static_cast<GraphicStoryItem*>(this->parent)->get_rect().height();
		qreal parent_x=static_cast<GraphicStoryItem*>(this->parent)->get_rect().x();
		qreal parent_y=static_cast<GraphicStoryItem*>(this->parent)->get_rect().y();

		QPointF point2=QPointF(posx,parent_y+parent_h/2);//rect.height()-((3*rect.height())/2)+posy);
		QLineF  * tmp_line=new QLineF(posx,parent_y+parent_h/2,posx,posy+parent_h/2);
		_painter->drawRect(QRectF(point2-QPointF(2,2),point2+QPointF(2,2)));
		_painter->drawLine((*tmp_line));




	}
	QBrush selBrush=QBrush(Qt::red,Qt::SolidPattern);
	QPen selPen=QPen(Qt::red);
	QLineF  * red_line=new QLineF(posx,(rect.height()/2)+posy,rect.width(),(rect.height()/2)+posy);
	_painter->drawLine((*red_line));
	qreal j;
	if(!IsStorySplit){
		/*
		for (qreal i=0;i<rect.width();i=i+rect.width()/45){
			QLineF  * tmp_line=new QLineF(i,posy,i,rect.height()+posy);


			if (i==rect.width()){
				//std::cerr << "i equal to width" << std::endl;
				std::cerr << "i : " << i << std::endl;
			}
			else{

				//std::cerr << "i not equal to width" << std::endl;
				//std::cerr << "i : " << i << std::endl;
				for (j=i;j<i+rect.width()/35;j+=(rect.width()/45)/24){
					//std::cerr << "j : " << j << "rect width:" << rect.width()<< std::endl;
					QBrush selBrush=QBrush(Qt::red,Qt::SolidPattern);
					QPen selPen=QPen(Qt::red);
					_painter->setBrush(selBrush);
					_painter->setPen(selPen);
					QLineF * tmp_min_line=new QLineF(j,posy,j,rect.height()+posy);
					//tmp_min_line->
					_painter->drawLine((*tmp_min_line));
				}
			}
			selBrush=QBrush(Qt::black,Qt::SolidPattern);
			selPen=QPen(Qt::black);
			_painter->setBrush(selBrush);
			_painter->setPen(selPen);

			//_painter->drawLine(i,0,i,rect.height());
			_painter->drawLine((*tmp_line));
		}
		*/
	}
	if(isSelected()){
		//this->setSelected(true);



		_painter->setBrush(selBrush);
		_painter->setPen(selPen);

		if(HeatMap){

			for (qreal i=0;i<rect.width();i=i+rect.width()/45){
				QLineF  * tmp_line=new QLineF(i,posy,i,rect.height()+posy);


				if (i==rect.width()){
					//std::cerr << "i equal to width" << std::endl;
					std::cerr << "i : " << i << std::endl;
				}
				else{

					//std::cerr << "i not equal to width" << std::endl;
					//std::cerr << "i : " << i << std::endl;
					for (j=i;j<i+rect.width()/35;j+=(rect.width()/45)/24){
						//std::cerr << "j : " << j << "rect width:" << rect.width()<< std::endl;
						QBrush selBrush=QBrush(Qt::red,Qt::SolidPattern);
						QPen selPen=QPen(Qt::red);
						_painter->setBrush(selBrush);
						_painter->setPen(selPen);
						QLineF * tmp_min_line=new QLineF(j,posy,j,rect.height()+posy);
						//tmp_min_line->
						_painter->drawLine((*tmp_min_line));
					}
				}
				selBrush=QBrush(Qt::black,Qt::SolidPattern);
				selPen=QPen(Qt::black);
				_painter->setBrush(selBrush);
				_painter->setPen(selPen);

				//_painter->drawLine(i,0,i,rect.height());
				_painter->drawLine((*tmp_line));
			}
		}
		QBrush selBrush=QBrush(Qt::red,Qt::SolidPattern);
		QPen selPen=QPen(Qt::red);
		_painter->setBrush(selBrush);
		_painter->setPen(selPen);
		QPointF point=QPointF(posx,(rect.height()/2)+posy);


	   _painter->drawRect(QRectF(point-QPointF(2,2),point+QPointF(2,2)));

	//update();
	}


}
void GraphicStoryItem::hoverMoveEvent(QGraphicsSceneHoverEvent *e) {
	//std::cerr << "x : " << e->pos().rx() << std::endl;
	//std::cerr << "y : " << e->pos().ry() << std::endl;
	update();
	QGraphicsItem::hoverEnterEvent(e);


}
void GraphicStoryItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *e) {
	//this->Pressed=false;
	update();
	QGraphicsItem::hoverLeaveEvent(e);

}
bool GraphicStoryItem::get_isStorySplit(){
	return this->IsStorySplit;
}






































/*
void GraphicStoryItem::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
	//this->setEnabled(true);
	//this->setFocus();
	this->setSelected(true);
	this->Pressed=true;

	if(isSelected()){
		if (e -> buttons() & Qt::LeftButton) {
			//QPointF mouse_point = e -> pos();

			//for(mySelPoint=0;mySelPoint<8;mySelPoint++){
				//if(mySelPoint<3) point=QPointF(rect.width()/2*mySelPoint,0);
				//if(mySelPoint==3) point=QPointF(rect.width(),rect.height()/2);
				//if(mySelPoint>3 && mySelPoint<7) point=QPointF(rect.width()/2*(mySelPoint-4),rect.height());
			//QPointF point=QPointF(0,rect.height()/2);
				//if(hasClickedOn(mouse_point,point)) break;
			//}//for
			//if(mySelPoint==8) mySelPoint=-1;
			//e->accept();
		}
	}
	QGraphicsItem::mousePressEvent(e);
	update();
	//QGraphicsItem::mousePressEvent(event);

}
*/

/*
void GraphicStoryItem::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
	//this->Pressed=false;
	//update();
	//QGraphicsItem::mouseReleaseEvent(event);

	//QList<QGraphicsItem*> childs=this->childItems();
	std::cerr << "entering mousemove event in item" << std::endl;
	if(!IsStorySplit){

	}
	else{

		//std::cerr << "my x : " << e->pos().rx() << std::endl;
		//std::cerr << "my y : " << e->pos().ry() << std::endl;
		if ((e -> buttons() & Qt::LeftButton)) {
			QPointF mouse_point = e -> pos();

				//prepareGeometryChange();
				std::cerr << "e pos x : " << e -> pos().rx() << "e pos y : " << e -> pos().ry() << std::endl;

				//std::cerr << "item pos x : " << pos().x() << "item pos y : " << pos().y() << std::endl;
				setPos(mapToScene(mouse_point).x(),pos().y());
				//std::cerr << "MapToScene mouse point x : " << mapToScene(mouse_point).x() << "item pos y : " << mapToScene(mouse_point).y() << std::endl;
				//qreal w=rect.width() - mouse_point.x();
				//std::cerr << "new width : " << w << std::endl;
				rect.setRight(rect.width() - mouse_point.x());

			//rect.setRight(500);


			if(!childs.empty()){
				for (QList<QGraphicsItem*>::Iterator it =childs.begin();it!=childs.end();++it){
					static_cast<StoryItem*>((*it))->prepareGeometryChange();
					if (!(static_cast<StoryItem*>((*it))->get_rect().width()-mapToScene(mouse_point).x())<0){

					}
					else{
						static_cast<StoryItem*>((*it))->setPos(mapToScene(mouse_point).x(),static_cast<StoryItem*>((*it))->pos().y());
						static_cast<StoryItem*>((*it))->get_rect().setRight(rect.width() - mouse_point.x());
					}
				}
			}






		}
		else{
			QGraphicsItem::mouseMoveEvent(e);
		}
		update();
	}


}

*/






QRectF GraphicStoryItem::boundingRect() const{
	//qreal penWidth = 5;
	//this->pen.setWidth(7);

	//return this->rect;

	//std::cerr << " bounding rect " << std::endl;
	qreal extra = 20 / 2.0 + myHandlerWidth;
	//extra=0;
	//std::cerr << " extra : " << extra << std::endl;
	qreal miny;
	qreal maxy;
	qreal minx;
	qreal maxx;


	//std::cerr << "rect width :" << rect.width() << std::endl;
	//extra=my_parent_width-rect.width();
	//std::cerr << " extra : " << extra << std::endl;
	minx = rect.width() < 0 ? rect.width() : 0;
	maxx = rect.width() < 0 ? 0 : rect.width() ;



	if(IsStorySplit){

		miny = rect.height() < 0 ? rect.height() : posy;
		maxy = rect.height() < 0 ? 0 : posy+rect.height() ;
	}
	else{


		//minx = 0;
		//maxx = 1500;
		//miny = posy;
		//maxy = rect.height();

		miny = rect.height() < 0 ? rect.height() : posy;
		maxy = rect.height() < 0 ? 0 : posy+rect.height() ;
	}


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
	return newRect;




}
/*
if ((change == QGraphicsItem::ItemScenePositionHasChanged || change == QGraphicsItem::ItemTransformHasChanged || change == QGraphicsItem::ItemPositionHasChanged) && scene())
{
//update position in database
}
*/
/*
QVariant GraphicStoryItem::itemChange(GraphicsItemChange change, const QVariant &value){
	if (change == ItemPositionChange && scene()) {
		// value is the new position.
		QPointF newPos = value.toPointF();
		//this->rect = scene()->sceneRect();
		if (!rect.contains(newPos)) {
			// Keep the item inside the scene rect.
			newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
			//newPos.setY(qMin(rect.top(), qMax(newPos.y(), rect.top())));
			newPos.setY(rect.top()/2);

			return newPos;
		}
	}
	update();
	return QGraphicsItem::itemChange(change, value);
}
*/
/*
void GraphicStoryItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
 {
	 event->setAccepted(event->mimeData()->hasFormat("text/plain"));
 }
 */
