#include "graphicstoryscene.h"



GraphicStoryScene::GraphicStoryScene(int  _positionY,QGraphicsScene * parent)
	:QGraphicsScene(parent)
{

	//this->currentDoc=_currentDoc;
	setItemIndexMethod(NoIndex);
	this->positionY=_positionY;
	this->my_selected_story=NULL;
	this->my_selected_event=NULL;
	this->my_selected_obsPoint=NULL;
	connect(this,SIGNAL(selectionChanged()),this,SLOT(changedSelection()));

	//positionY+=61;
	//my_second_item=new GraphicStoryItem("split",true,0,positionY,my_item);
	//positionY+=61;
	//this->addItem(my_item);

	//setSceneRect(-150, -150, 1500, 600);


	//connect(my_item,SIGNAL(selected()),this,SLOT(emit_story_selected()));


	//GraphicStoryItem *my_third_item=new GraphicStoryItem("second split",true,0,positionY,my_item);
	//positionY+=61;
	//my_second_item->setParentItem(my_item);
	;
	//this->addItem(my_second_item);
	//this->addItem();
	//this->addItem(my_third_item);

	//connect(this,SIGNAL(sceneRectChanged(QRectF)),my_item,SLOT()
}
void GraphicStoryScene::changedSelection(){
	std::cerr << "selection changed" << std::endl;
}
void GraphicStoryScene::set_doc(ItfDocument  * _currentDoc){
	this->currentDoc=_currentDoc;
}

void GraphicStoryScene::set_max_item_width(qreal _max_width){
	this->max_width=_max_width;
}

GraphicStoryItem * GraphicStoryScene::get_item_by_label(QString _label){
	QList<QGraphicsItem*> item_list=this->items();
	QList<QGraphicsItem*>::iterator it;
	for(it=item_list.begin();it!=item_list.end();++it){
		if(static_cast<GraphicStoryItem*>((*it))->get_label()==_label){
			return static_cast<GraphicStoryItem*>((*it));
		}
	}
	return NULL;
}

void GraphicStoryScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

	//std::cerr << "entering mouse press event" << std::endl;

	if (mouseEvent->button() != Qt::LeftButton)
		return;
	QGraphicsItem* item = itemAt(mouseEvent->scenePos(),QTransform());

	if(item!=0){
		switch(item->type()){
			case GraphicStoryItem::Type:
				this->my_selected_story=static_cast<GraphicStoryItem*>(item);
				std::cerr <<"Zvalue: " << this->my_selected_story->zValue()<< "name : " << this->my_selected_story->get_label().toStdString() << std::endl;

				//this->addItem(my_item);

				break;
			case GraphicEventItem::Type:
				this->my_selected_event=static_cast<GraphicEventItem*>(item);
				std::cerr << "event name : " << this->my_selected_event->get_label().toStdString() << std::endl;



				break;
			case GraphicObservationPointItem::Type:
				this->my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(item);
				//std::cerr << "event name : " << this->my_selected_obsPoint->get_label().toStdString() << std::endl;



				break;
		}
	}
	else{
		std::cerr << "empty selection" << std::endl;
	}
	selectedItems().clear();


	QGraphicsScene::mousePressEvent(mouseEvent);


}
GraphicStoryItem     * GraphicStoryScene::get_selected_story(){
	return this->my_selected_story;
}
GraphicEventItem     * GraphicStoryScene::get_selected_event(){
	return this->my_selected_event;
}
GraphicObservationPointItem     * GraphicStoryScene::get_selected_obsPoint(){
	return this->my_selected_obsPoint;
}
void GraphicStoryScene::set_right_for_childs(GraphicStoryItem * _story_moving,qreal _movement){

	std::cerr << "movement : " << _movement << std::endl;
	for (QList<QGraphicsItem*>::iterator it =_story_moving->childItems().begin();it!=_story_moving->childItems().end();++it){
		std::cerr << "son name : " << static_cast<GraphicStoryItem*>((*it))->get_label().toStdString() << std::endl;
		static_cast<GraphicStoryItem*>((*it))->set_right(_movement);
		//set_right_for_childs(static_cast<GraphicStoryItem*>((*it)),_movement);
	}
	//GraphicStoryItem * _story_moving


}

void GraphicStoryScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
	//std::cerr << "entering mousemove event in scene" << std::endl;

	QGraphicsItem * selected_item;
	GraphicStoryItem     * selected_story;
	GraphicEventItem     * selected_event;

	if ((e->buttons() & Qt::LeftButton)) {

		selected_item = itemAt(e->scenePos(),QTransform());
		bool isSplit;

		//std::cerr << "item position x : " << item_point.x() << std::endl;
		if(selected_item!=0){
			QPointF mouse_point;
			QPointF item_point;
			qint64 hours;
			switch(selected_item->type()){
				case GraphicStoryItem::Type:
					std::cerr << "type storyitem" << std::endl;
					selected_story=my_selected_story;
					isSplit=selected_story->get_isStorySplit();
					if(!isSplit){
						std::cerr << "not split story" << std::endl;
					}
					else{
						//storysplit without childs
						if(my_selected_story->childItems().empty()){
							//storysplit without childs but with StorySPlit parent
							if(my_selected_story->get_parent()->get_isStorySplit()){
								mouse_point = e->scenePos();
								item_point=selected_story->mapFromParent(mouse_point.x(),mouse_point.y());

								//std::cerr << "item pos x : " << mouse_point.x() << std::endl;


								selected_story->change();
								std::cerr << "item pos x : " << item_point.x() << std::endl;
								std::cerr << "scene pos x : " << mouse_point.x() << std::endl;
								std::cerr << "max width : " << max_width << std::endl;
								std::cerr << "story parent width :" <<selected_story->get_parent()->get_rect().width() << std::endl;
								std::cerr << "story width :" <<selected_story->get_rect().width() << std::endl;



								if(mouse_point.x()>=selected_story->get_parent()->get_rect().width()){//.1500){

									std::cerr << "mouse point ==1500" << std::endl;
									selected_story->set_right(0);
									selected_story->setPos(selected_story->get_parent()->get_rect().width(),selected_story->pos().y());
								}
								else if(mouse_point.x()<= selected_story->get_parent()->pos().x()){//selected_story->pos().x()
									std::cerr << "mouse point ==0" << selected_story->get_parent()->get_rect().width() << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->pos().y() << std::endl;

									selected_story->set_right(selected_story->get_parent()->get_rect().width());
									selected_story->setPos(selected_story->get_parent()->pos().x(),selected_story->pos().y());//selected_story->pos().x()
								}

								else{


									selected_story->set_right(selected_story->get_rect().width() - item_point.x());
									std::cerr << "new and last x :" << item_point.x() << std::endl;

									selected_story->setPos(mouse_point.x(),selected_story->pos().y());
									//convertir une distance
									hours=mouse_point.x();


									static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
									selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
								}
							}
							//storysplit without childs with Story parent
							else{
								mouse_point = e->scenePos();
								item_point=selected_story->mapFromParent(mouse_point.x(),mouse_point.y());

								//std::cerr << "item pos x : " << mouse_point.x() << std::endl;


								selected_story->change();
								std::cerr << "item pos x : " << item_point.x() << std::endl;
								std::cerr << "scene pos x : " << mouse_point.x() << std::endl;
								std::cerr << "max width : " << max_width << std::endl;
								std::cerr << "story parent width :" <<selected_story->get_parent()->get_rect().width() << std::endl;
								std::cerr << "story width :" <<selected_story->get_rect().width() << std::endl;



								if(mouse_point.x()>=selected_story->get_parent()->get_rect().width()){//.1500){

									std::cerr << "mouse point ==1500" << std::endl;
									selected_story->set_right(0);
									selected_story->setPos(selected_story->get_parent()->get_rect().width(),selected_story->pos().y());
								}
								else if(mouse_point.x()<= selected_story->get_parent()->pos().x()){//selected_story->pos().x()
									std::cerr << "mouse point ==0" << selected_story->get_parent()->get_rect().width() << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->pos().y() << std::endl;

									selected_story->set_right(selected_story->get_parent()->get_rect().width());
									selected_story->setPos(selected_story->get_parent()->pos().x(),selected_story->pos().y());//selected_story->pos().x()
								}

								else{


									selected_story->set_right(selected_story->get_rect().width() - item_point.x());
									std::cerr << "new and last x :" << item_point.x() << std::endl;

									selected_story->setPos(mouse_point.x(),selected_story->pos().y());
									//convertir une distance
									hours=mouse_point.x();


									static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
									selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
								}
							}
						}
						//StorySplit with childs
						else{
							//StorySplit with childs and with parent storysplit
							if(my_selected_story->get_parent()->get_isStorySplit()){
								mouse_point = e->scenePos();
								item_point=selected_story->mapFromParent(mouse_point.x(),mouse_point.y());

								//std::cerr << "item pos x : " << mouse_point.x() << std::endl;


								selected_story->change();
								std::cerr << "item pos x : " << item_point.x() << std::endl;
								std::cerr << "scene pos x : " << mouse_point.x() << std::endl;
								std::cerr << "max width : " << max_width << std::endl;
								std::cerr << "story parent width :" <<selected_story->get_parent()->get_rect().width() << std::endl;
								std::cerr << "story width :" <<selected_story->get_rect().width() << std::endl;



								if(mouse_point.x()>=selected_story->get_parent()->get_rect().width()){//.1500){

									std::cerr << "mouse point ==1500" << std::endl;
									selected_story->set_right(0);
									selected_story->setPos(selected_story->get_parent()->get_rect().width(),selected_story->pos().y());
								}
								else if(mouse_point.x()<= selected_story->get_parent()->pos().x()){//selected_story->pos().x()
									std::cerr << "mouse point ==0" << selected_story->get_parent()->get_rect().width() << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->pos().y() << std::endl;

									selected_story->set_right(selected_story->get_parent()->get_rect().width());
									selected_story->setPos(selected_story->get_parent()->pos().x(),selected_story->pos().y());//selected_story->pos().x()
								}

								else{


									selected_story->set_right(selected_story->get_rect().width() - item_point.x());
									std::cerr << "new and last x :" << item_point.x() << std::endl;

									selected_story->setPos(mouse_point.x(),selected_story->pos().y());
									//convertir une distance
									hours=mouse_point.x();


									static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
									selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
								}
							}
							//StorySplit with childs and with parent story
							else{
								mouse_point = e->scenePos();
								item_point=selected_story->mapFromParent(mouse_point.x(),mouse_point.y());

								//std::cerr << "item pos x : " << mouse_point.x() << std::endl;


								selected_story->change();
								std::cerr << "item pos x : " << item_point.x() << std::endl;
								std::cerr << "scene pos x : " << mouse_point.x() << std::endl;
								std::cerr << "max width : " << max_width << std::endl;
								std::cerr << "story parent widht :" <<selected_story->get_parent()->get_rect().width() << std::endl;
								std::cerr << "story widht :" <<selected_story->get_rect().width() << std::endl;



								if(mouse_point.x()>=selected_story->get_parent()->get_rect().width()){//.1500){

									std::cerr << "mouse point ==1500" << std::endl;
									selected_story->set_right(0);
									selected_story->setPos(selected_story->get_parent()->get_rect().width(),selected_story->pos().y());
								}
								else if(mouse_point.x()<= selected_story->get_parent()->pos().x()){//selected_story->pos().x()
									std::cerr << "mouse point ==0" << selected_story->get_parent()->get_rect().width() << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->pos().y() << std::endl;

									selected_story->set_right(selected_story->get_parent()->get_rect().width());
									selected_story->setPos( selected_story->get_parent()->pos().x(),selected_story->pos().y());//selected_story->pos().x()
									//selected_story->sce
								}

								else{




									qreal distance_to_move=selected_story->get_rect().width() - item_point.x();
									selected_story->set_right(selected_story->get_rect().width() - item_point.x());

									std::cerr << "new and last x :" << item_point.x() << std::endl;

									selected_story->setPos(mouse_point.x(),selected_story->pos().y());

									//set_right_for_childs(my_selected_story, distance_to_move);
									//convertir une distance
									hours=mouse_point.x();


									static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
									selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
								}
							}
						}



					}
					break;
				case GraphicEventItem::Type:
					std::cerr << "type event item" << std::endl;
					selected_event=my_selected_event;
					mouse_point = e->scenePos();
					//item_point=selected_story->mapFromParent(QPointF(mouse_point.x(),mouse_point.y()));

					std::cerr << "item pos x : " << mouse_point.x() << std::endl;


					selected_event->change();

					selected_event->setPos(mouse_point.x(),selected_event->pos().y());
					hours=mouse_point.x();
					selected_event->get_event()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
					selected_event->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),selected_event->get_event()->get_timepoint())));


					break;
				default:
					QGraphicsScene::mouseMoveEvent(e);
					break;
			}




				//update();
		}
		else{
			std::cerr << "empty selection" << std::endl;
		}

	}

	else{

		//QGraphicsScene::mouseMoveEvent(e);
	}
	//update();


	//StoryItem * selected_story=static_cast<StoryItem*>(selectedItems().first());
	//std::cerr << "selections size : " << selection.size() << std::endl;

	//std::cerr << "selections size : " << selection.size() << std::endl;




	//}




}
/*
void GraphicStoryScene::add_story(QString _label,StoryBase * _story){
	std::cerr << "story added" << std::endl;
	GraphicStoryItem * new_item=new GraphicStoryItem(_label,false,0,positionY, NULL);
	//this->addItem(new_item);
	positionY+=60;
	//this->sceneRect().setHeight(1500+positionY);
	//this->sceneRect().setHeight();
	setSceneRect(QRectF(-150, -150, this->sceneRect().width(), this->sceneRect().height()+60));
	//update();

}
*/
void GraphicStoryScene::add_split_story(QString _label,StoryBase * _story){
	std::cerr << "story added" << std::endl;
	//QGraphicsItem * selected_item;
	//GraphicStoryItem     * selected_story;
	//selected_item = itemAt(e->scenePos(),QTransform());
	//GraphicStoryItem *parent=static_cast<GraphicStoryItem*>(get_item_by_label(_story->get_label()));

	if(my_selected_story!=NULL){
		bool isSplit=my_selected_story->get_isStorySplit();
		//if(!isSplit){
		new GraphicStoryItem(my_selected_story->get_rect().width(),this->currentDoc,my_selected_story->get_rect().width(),_story,_label,true,0,positionY,my_selected_story);
		positionY+=61;
		setSceneRect(QRectF(-150, -150, this->sceneRect().width(), this->sceneRect().height()+60));


		//}
	}
	/*
	//if(!selectedItems().empty()){
		selected_item=selectedItems().first();
		switch(selected_item->type()){
			case StoryItem::Type:
				std::cerr << "type storyitem" << std::endl;
				selected_story=qgraphicsitem_cast<StoryItem*>(selected_item);
				bool isSplit=selected_story->get_isStorySplit();
				if(!isSplit){
					new GraphicStoryItem("second split",true,0,positionY,selected_story);
					positionY+=61;
					setSceneRect(QRectF(-150, -150, this->sceneRect().width(), this->sceneRect().height()+60));


				}
				break;
		}
	}
	*/

	//update();

}
void GraphicStoryScene::add_root_story(QString _label,StoryBase* _story){

	std::cerr << "entering add root story in scene" << std::endl;
	GraphicStoryItem * new_item=new GraphicStoryItem(0,this->currentDoc,this->max_width,_story,_label,false,0,positionY, NULL);
	this->addItem(new_item);
	positionY+=61;
	setSceneRect(QRectF(-150, -150, this->sceneRect().width(), this->sceneRect().height()+60));

}
void GraphicStoryScene::add_event(Event *e){
	std::cerr << "adding event" << std::endl;
	GraphicEventItem *tmp_item=new GraphicEventItem(e,0,positionY,this->max_width,e->get_label(),my_selected_story);
	//tmp_item->setZValue(100000);
}





