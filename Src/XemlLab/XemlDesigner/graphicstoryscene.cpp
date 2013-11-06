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
	createActions();
	//createMenus();

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
void GraphicStoryScene::createActions(){
	show_details = new QAction(QIcon(":/Images/new.png"),tr("&Story_details"), this);
	show_details->setShortcut(tr("Ctrl+S"));
	show_details->setStatusTip(tr("Show details about story"));
	display_plot = new QAction(QIcon(":/Images/new.png"),tr("&Story_details"), this);
	display_plot->setShortcut(tr("Ctrl+S"));
	display_plot->setStatusTip(tr("Show details about story"));
	connect(show_details, SIGNAL(triggered()), this, SLOT(details_story()));
	connect(display_plot,SIGNAL(triggered()),this,SLOT(display_plot_parameters()));
}

void GraphicStoryScene::createMenus(){
	contextMenu =new QMenu("Details");
	contextMenu->addAction(show_details);
	contextMenu->addAction(display_plot);
}
void GraphicStoryScene::details_story(){
	emit show_details_story(this->my_selected_story);
}
void GraphicStoryScene::display_plot_parameters(){

}

void GraphicStoryScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

	//std::cerr << "entering mouse press event" << std::endl;

	if (mouseEvent->button() == Qt::LeftButton){

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
					std::cerr << "obs id : "  << this->my_selected_obsPoint->get_obspoint()->get_id() << std::endl;



					break;
			}
		}
		else{
			std::cerr << "empty selection" << std::endl;
		}
		selectedItems().clear();
	}

	else if(mouseEvent->button() == Qt::RightButton){
		QGraphicsItem* item = itemAt(mouseEvent->scenePos(),QTransform());

		if(item!=0){
			switch(item->type()){
				case GraphicStoryItem::Type:
					this->my_selected_story=static_cast<GraphicStoryItem*>(item);
					contextMenu =new QMenu("Details",mouseEvent->widget());
					contextMenu->addAction(show_details);
					contextMenu->exec(mouseEvent->screenPos());

					break;
			}
		}
		else{
			std::cerr << "empty selection" << std::endl;
		}
		selectedItems().clear();
	}



	QGraphicsScene::mousePressEvent(mouseEvent);


}
void GraphicStoryScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
	// event->scenePos() is available
	//QMenu menu(this);
	//menu.addAction(...);
	//menu.addAction(...);
	//contextMenu->show();

	//contextMenu =new QMenu("Details",event->widget());
	//contextMenu->addAction(show_details);
	//contextMenu->exec(event->screenPos());
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
void GraphicStoryScene::set_right_for_childs(QGraphicsItem * child_to_move,qreal _movement){

	std::cerr << "movement : " << _movement << std::endl;
	QGraphicsItem * item;
	GraphicStoryItem * tmp;
	GraphicEventItem * tmp_event;
	GraphicObservationPointItem * tmpobs;
	QPointF topRight;
	QPointF topLeft;
	QPointF center;
	qreal obs_point_center_x;
	QDateTime obstime;

	if (!child_to_move->childItems().empty()){
		std::cerr << "size : " << child_to_move->childItems().size() << std::endl;
		for(int i=0;i<child_to_move->childItems().size();i++){
			std::cerr << "in da loop "<< std::endl;
			item=child_to_move->childItems().at(i);
			switch(item->type()){
				case GraphicStoryItem::Type:
					tmp=static_cast<GraphicStoryItem*>(item);
					std::cerr << "son name : " << tmp->get_label().toStdString() << std::endl;

/*
					static_cast<GraphicStoryItem*>((*it))->change();
					static_cast<GraphicStoryItem*>((*it))->set_right(static_cast<GraphicStoryItem*>((*it))->get_rect().width()-_movement);
					if(!(static_cast<GraphicStoryItem*>((*it))->childItems().empty())){
						set_right_for_childs(static_cast<GraphicStoryItem*>((*it)),_movement);
					}
					*/
					break;
				case GraphicEventItem::Type:
					tmp_event=static_cast<GraphicEventItem*>(item);
					std::cerr << "event son label : " << tmp_event->get_label().toStdString() << std::endl;
					break;

				case GraphicObservationPointItem::Type:


					tmpobs=static_cast<GraphicObservationPointItem*>(item);
					//obs_point_center_x=(tmpobs->boundingRect().topRight().x-tmpobs->boundingRect().topLeft().x)/2;
					topRight=tmpobs->mapToScene(tmpobs->boundingRect().topRight());
					topLeft =tmpobs->mapToScene(tmpobs->boundingRect().topLeft());
					center =tmpobs->mapToScene(tmpobs->boundingRect().center());
					obs_point_center_x=(topRight.x()-topLeft.x())/2;
					obstime=get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(center.x()));
					tmpobs->get_obspoint()->set_timepoint(obstime);
					tmpobs->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmpobs->get_obspoint()->get_timepoint())));

					if(center.x()>=max_width){
						std::cerr <<" cool" << std::endl;
					}
					std::cerr << "obs son  id : " << tmpobs->get_obspoint()->get_id() << std::endl;
					std::cerr << "obs son pos center: " << tmpobs->boundingRect().center().x() << std::endl;
					std::cerr << "obs son pos top left: " << tmpobs->boundingRect().topLeft().x() << std::endl;
					std::cerr << "obs son pos top right: " << tmpobs->boundingRect().topRight().x() << std::endl;
					std::cerr << "obs son pos map to scene :"<< topRight.x() << std::endl;
					//std::cerr << "obs son pos : " << tmpobs->boundingRect().center().x() << std::endl;

					break;
				 default:
					break;
			}
		}
		/*
		for (QList<QGraphicsItem*>::iterator it =child_to_move->childItems().begin();it!=child_to_move->childItems().end();++it){
			std::cerr << "in da loop "<< std::endl;
			switch((*it)->type()){
				case GraphicStoryItem::Type:
					tmp=static_cast<GraphicStoryItem*>((*it));
					std::cerr << "son name : " << tmp->get_label().toStdString() << std::endl;


					static_cast<GraphicStoryItem*>((*it))->change();
					static_cast<GraphicStoryItem*>((*it))->set_right(static_cast<GraphicStoryItem*>((*it))->get_rect().width()-_movement);
					if(!(static_cast<GraphicStoryItem*>((*it))->childItems().empty())){
						set_right_for_childs(static_cast<GraphicStoryItem*>((*it)),_movement);
					}

					break;
				case GraphicEventItem::Type:
					tmp_event=static_cast<GraphicEventItem*>((*it));
					std::cerr << "event son label : " << tmp_event->get_label().toStdString() << std::endl;
					break;

				case GraphicObservationPointItem::Type:
					tmpobs=static_cast<GraphicObservationPointItem*>((*it));
					std::cerr << "obs son  id : " << tmpobs->get_obspoint()->get_id() << std::endl;

					break;
				 default:
					break;
			}


		}
		*/
	}
	//GraphicStoryItem * _story_moving


}

void GraphicStoryScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
	//std::cerr << "entering mousemove event in scene" << std::endl;

	QGraphicsItem        * selected_item;
	GraphicStoryItem        * selected_parent_item;
	GraphicStoryItem     * selected_story;
	GraphicEventItem     * selected_event;
	GraphicObservationPointItem     * selected_obsPoint;

	if ((e->buttons() & Qt::LeftButton)) {

		selected_item = itemAt(e->scenePos(),QTransform());
		bool isSplit;

		//std::cerr << "item position x : " << item_point.x() << std::endl;
		if(selected_item!=0 ){//&& selected_item->isSelected()
			QPointF mouse_point;
			QPointF item_point;
			QPointF item2_point;
			QPointF scene_point;
			QPointF event_item_pos;
			QPointF map_parent_item2Scene;
			qreal shift=0;
			qint64 hours;
			ObservationPoint * tmp=0;
			QDateTime tmptime;

			switch(selected_item->type()){
				case GraphicStoryItem::Type:
					std::cerr << "type storyitem" << std::endl;
					selected_story=my_selected_story;
					isSplit=selected_story->get_isStorySplit();
					if(!isSplit){
						std::cerr << "not split story" << std::endl;
					}
					else{
						selected_story->change();
						//storysplit without childs
						if(my_selected_story->childItems().empty()){
							//####################################################
							//storysplit without childs but with StorySplit parent
							//####################################################
							if(my_selected_story->get_parent()->get_isStorySplit()){
								std::cerr << "story W/o childs and with parent storysplit" << std::endl;

								mouse_point = e->scenePos();
								event_item_pos=e->pos();
								item_point=selected_story->mapFromParent(mouse_point.x(),mouse_point.y());
								scene_point=selected_story->mapFromScene(mouse_point.x(),mouse_point.y());
								item2_point=selected_story->mapToParent(mouse_point.x(),mouse_point.y());
								map_parent_item2Scene=selected_story->get_parent()->mapToScene(selected_story->get_parent()->get_posx(),selected_story->get_parent()->get_posy());

								//if(selected_parent_item->get_isStorySplit()){

								shift=this->max_width-my_selected_story->get_parent()->get_rect().width();
								std::cerr << "shift : " << shift << std::endl;
								//}
								std::cerr << "event item pos x : " << event_item_pos.x() << std::endl;
								std::cerr << "item pos x : " << item_point.x() << std::endl;
								std::cerr << "mouse pos x : " << mouse_point.x() << std::endl;
								std::cerr << "scene pos x : " << scene_point.x() << std::endl;
								std::cerr << "max width : " << max_width << std::endl;
								std::cerr << "map_parent_item2Scene : "<< map_parent_item2Scene.x() << std::endl;
								std::cerr << "story parent width :" <<selected_story->get_parent()->get_rect().width() << std::endl;
								std::cerr << "story width :" <<selected_story->get_rect().width() << std::endl;



								if(mouse_point.x() >=selected_story->get_parent()->get_rect().width()+map_parent_item2Scene.x()){//.1500){

									std::cerr << "mouse point == 1500" << std::endl;
									selected_story->set_right(0);

									selected_story->setPos(selected_story->get_parent()->get_rect().width(),selected_story->pos().y());
									hours=selected_story->get_parent()->get_rect().width()/zoomFactor+map_parent_item2Scene.x()/zoomFactor;
								}
								else if(mouse_point.x() <= map_parent_item2Scene.x()){//selected_story->pos().x()
									//std::cerr << "parent pos x = " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "mouse point == 0 ---" << selected_story->get_parent()->get_rect().width() << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->pos().y() << std::endl;
									std::cerr << "mapToparent : "<< item2_point.x() << std::endl;

									selected_story->set_right(selected_story->get_parent()->get_rect().width());
									selected_story->setPos(0,selected_story->pos().y());//selected_story->pos().x()//selected_story->get_parent()->pos().x()
									hours=0;


								}

								else{
									if(mouse_point.x()>0){

										std::cerr << "new right :" << selected_story->get_rect().width() - mouse_point.x() << std::endl;
										selected_story->set_right(selected_story->get_parent()->get_rect().width() - (mouse_point.x()-map_parent_item2Scene.x()));
										std::cerr << "new and last x :" << item_point.x() << std::endl;

										selected_story->setPos(mouse_point.x()-shift,selected_story->pos().y());//map_parent_item2Scene.x()
										//convertir une distance
										hours=mouse_point.x()/zoomFactor;


										//static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
										//selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
									}
								}
								set_right_for_childs(selected_story,mouse_point.x());
								static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
								selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
							}
							//####################################################
							//storysplit without childs with Story parent (basic case)
							//####################################################

							else{
								std::cerr << "story W/o childs and with parent story" << std::endl;
								mouse_point = e->scenePos();
								item_point=selected_story->mapFromParent(mouse_point.x(),mouse_point.y());
								scene_point=selected_story->mapFromScene(mouse_point.x(),mouse_point.y());

								//std::cerr << "item pos x : " << mouse_point.x() << std::endl;



								std::cerr << "item pos x : " << item_point.x() << std::endl;
								std::cerr << "mouse pos x : " << mouse_point.x() << std::endl;
								std::cerr << "scene pos x : " << scene_point.x() << std::endl;
								std::cerr << "max width : " << max_width << std::endl;
								std::cerr << "story parent width :" <<selected_story->get_parent()->get_rect().width() << std::endl;
								std::cerr << "story width :" <<selected_story->get_rect().width() << std::endl;



								if(mouse_point.x()>=selected_story->get_parent()->get_rect().width()){//.1500){

									std::cerr << "mouse point max" << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->get_parent()->pos().y() << std::endl;
									std::cerr << "pos x : " << selected_story->pos().x() << std::endl;
									std::cerr << "pos y : " << selected_story->pos().y() << std::endl;
									hours=selected_story->get_parent()->get_rect().width()/zoomFactor;
									selected_story->set_right(0);
									selected_story->setPos(selected_story->get_parent()->get_rect().width(),0);
								}
								else if(mouse_point.x()<= selected_story->get_parent()->pos().x()){//selected_story->pos().x()
									std::cerr << "mouse point min" << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->get_parent()->pos().y() << std::endl;
									std::cerr << "pos x : " << selected_story->pos().x() << std::endl;
									std::cerr << "pos y : " << selected_story->pos().y() << std::endl;
									hours=0;
									selected_story->set_right(selected_story->get_parent()->get_rect().width());
									selected_story->setPos(selected_story->get_parent()->pos().x(),0);//selected_story->pos().x()
								}

								else{

									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->get_parent()->pos().y() << std::endl;
									std::cerr << "pos x : " << selected_story->pos().x() << std::endl;
									std::cerr << "pos y : " << selected_story->pos().y() << std::endl;
									std::cerr << "pos y : " << selected_story->get_posy() << std::endl;
									std::cerr << "mouse point y : " << mouse_point.y() << std::endl;


									selected_story->setPos(mouse_point.x(),0);
									selected_story->set_right(selected_story->get_rect().width() - item_point.x());

									//std::cerr << "new and last x :" << item_point.x() << std::endl;

									//selected_story->setPos(mouse_point.x(),selected_story->pos().y());
									//convertir une distance
									hours=mouse_point.x()/zoomFactor;



								}
								static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
								selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
							}
						}
						//StorySplit with childs
						else{
							//####################################################
							//StorySplit with childs and with parent storysplit
							//####################################################

							if(my_selected_story->get_parent()->get_isStorySplit()){
								std::cerr << "story W childs and with parent storysplit" << std::endl;
								mouse_point = e->scenePos();
								item_point=selected_story->mapFromParent(mouse_point.x(),mouse_point.y());
								map_parent_item2Scene=selected_story->get_parent()->mapToScene(selected_story->get_parent()->get_posx(),selected_story->get_parent()->get_posy());


								//std::cerr << "item pos x : " << mouse_point.x() << std::endl;



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
									hours=0;
									selected_story->set_right(selected_story->get_parent()->get_rect().width());
									selected_story->setPos(0,selected_story->pos().y());//selected_story->pos().x()
								}

								else{



									qreal distance_to_move=(selected_story->get_rect().width() - item_point.x())-map_parent_item2Scene.x();

									selected_story->set_right(selected_story->get_rect().width() - item_point.x());
									std::cerr << "new and last x :" << item_point.x() << std::endl;

									selected_story->setPos(mouse_point.x(),selected_story->pos().y());
									set_right_for_childs(my_selected_story, distance_to_move);
									//convertir une distance
									hours=mouse_point.x()/zoomFactor;



								}
								static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
								selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
							}
							//####################################################
							//StorySplit with childs and with parent story
							//####################################################
							else{
								std::cerr << "story W childs and with parent story" << std::endl;
								mouse_point = e->scenePos();
								item_point=selected_story->mapFromParent(mouse_point.x(),mouse_point.y());
								map_parent_item2Scene=selected_story->get_parent()->mapToScene(selected_story->get_parent()->get_posx(),selected_story->get_parent()->get_posy());


								//std::cerr << "item pos x : " << mouse_point.x() << std::endl;



								std::cerr << "item pos x : " << item_point.x() << std::endl;
								//std::cerr << "scene pos x : " << mouse_point.x() << std::endl;
								std::cerr << "mouse pos x : " << mouse_point.x() << std::endl;
								std::cerr << "max width : " << max_width << std::endl;
								std::cerr << "story parent widht :" <<selected_story->get_parent()->get_rect().width() << std::endl;
								std::cerr << "story widht :" <<selected_story->get_rect().width() << std::endl;



								if(mouse_point.x()>=selected_story->get_parent()->get_rect().width()){//.1500){

									std::cerr << "mouse point max" << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->get_parent()->pos().y() << std::endl;
									std::cerr << "pos x : " << selected_story->pos().x() << std::endl;
									std::cerr << "pos y : " << selected_story->pos().y() << std::endl;
									selected_story->set_right(0);
									selected_story->setPos(selected_story->get_parent()->get_rect().width(),selected_story->pos().y());
									hours=selected_story->get_parent()->get_rect().width()/zoomFactor;
								}
								else if(mouse_point.x()<= selected_story->get_parent()->pos().x()){//selected_story->pos().x()
									std::cerr << "mouse point min" << selected_story->get_parent()->get_rect().width() << std::endl;
									std::cerr << "parent x : " << selected_story->get_parent()->pos().x() << std::endl;
									std::cerr << "parent y : " << selected_story->get_parent()->pos().y() << std::endl;
									std::cerr << "pos x : " << selected_story->pos().x() << std::endl;
									std::cerr << "pos y : " << selected_story->pos().y() << std::endl;
									hours=0;
									selected_story->set_right(selected_story->get_parent()->get_rect().width());
									selected_story->setPos( selected_story->get_parent()->pos().x(),selected_story->pos().y());//selected_story->pos().x()
									//set_right_for_childs(selected_story, selected_story->get_parent()->get_rect().width());
									//selected_story->sce
								}

								else{




									//qreal distance_to_move=selected_story->get_rect().width() - (item_point.x()+mouse_point.x());
									qreal distance_to_move=mouse_point.x();
									selected_story->set_right(selected_story->get_rect().width() - item_point.x());

									std::cerr << "new and last x :" << item_point.x() << std::endl;
									std::cerr << "distance to move :" << distance_to_move << std::endl;
									std::cerr << "map parent item :" << map_parent_item2Scene.x() << std::endl;

									selected_story->setPos(mouse_point.x(),selected_story->pos().y());

									set_right_for_childs(my_selected_story, distance_to_move);
									//convertir une distance
									hours=mouse_point.x()/zoomFactor;



								}
								static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
								selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
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

					selected_event->setPos(mouse_point.x(),0);
					hours=mouse_point.x()/zoomFactor;
					selected_event->get_event()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
					selected_event->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),selected_event->get_event()->get_timepoint())));


					break;
				case GraphicObservationPointItem::Type:
					std::cerr << "type obs point item" << std::endl;
					mouse_point = e->scenePos();

					selected_obsPoint=this->my_selected_obsPoint;
					selected_parent_item = static_cast<GraphicStoryItem*>(this->my_selected_obsPoint->get_parent());


					if(selected_parent_item->get_isStorySplit()){

						shift=this->max_width-selected_parent_item->get_rect().width();
						std::cerr << "shift : " << shift << std::endl;
					}
					selected_obsPoint->change();
					selected_obsPoint->setPos(mouse_point.x()-shift,selected_obsPoint->get_posy());



					hours=mouse_point.x()/zoomFactor;
					std::cerr << "mouse point in Mouse event : " << mouse_point.x() << std::endl;
					std::cerr << "translation : " << translate_Distance_in_Msecs(hours)<< std::endl;
					tmp=selected_obsPoint->get_obspoint();

					tmptime=get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours));
					selected_obsPoint->get_obspoint()->set_timepoint(tmptime);

					//selected_obsPoint->get_obspoint()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
					selected_obsPoint->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),selected_obsPoint->get_obspoint()->get_timepoint())));


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
void GraphicStoryScene::initialize_x_Axis(qreal width, int _zoomFactor){
	QGraphicsLineItem * tmp_timeline=new QGraphicsLineItem(0,-10,width,-10);

	this->addItem(tmp_timeline);
	int counter=0;
	int counter_hour=0;
	this->zoomFactor=_zoomFactor;
	QFont serifFont("Times", 14, QFont::Bold);
	QFont serifFont2("Times", 10, QFont::Bold);
	qreal number_of_days=width/(24*zoomFactor);
	int k=0;
	for (int i=0;i<=width;i+=width/number_of_days){
		std::cerr << "range : " << i << std::endl;
		//QGraphicsItemGroup * group=new QGraphicsItemGroup();
		QGraphicsLineItem * tmp_line=new QGraphicsLineItem(i,-10,i,-30);
		this->addItem(tmp_line);
		//group->addToGroup(tmp_line);
		QGraphicsTextItem * tmp_text=new QGraphicsTextItem(QString::number(counter),tmp_timeline);

		tmp_text->setFont(serifFont);
		//group->addToGroup(tmp_text);

		tmp_text->setPos(i-8,-60);
		counter++;
		counter_hour=0;
		k+=width/number_of_days;
		if(i!=width){
			for (int j=i;j<k;j+=(width/number_of_days)/zoomFactor){

				if(counter_hour==0){


				}
				else if(counter_hour==24){
					counter_hour=0;
				}
				else{
					QGraphicsLineItem * tmp_little_line=new QGraphicsLineItem(j,-10,j,-15);
					this->addItem(tmp_little_line);
					QGraphicsTextItem * tmp_little_text=new QGraphicsTextItem(QString::number(counter_hour),tmp_timeline);
					tmp_little_text->setFont(serifFont2);
					tmp_little_text->setPos(j-8,-40);

				}
				counter_hour+=24/zoomFactor;

			}
		}
		//counter_hour=0;
		//this->GraphicScene->addItem(tmp_text);
		//this->GraphicScene->addItem(new QGraphicsLineItem(i,-10,i,-20));
		//this->GraphicScene->addItem(new QGraphicsTextItem(_node->get_label()));
	}
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
	qreal y=my_selected_story->get_posy();
	std::cerr << "position Y : " << y <<  std::endl;
	GraphicEventItem *tmp_item=new GraphicEventItem(e,0,y+20,this->max_width,e->get_label(),my_selected_story);

	//tmp_item->setZValue(100000);
}
void GraphicStoryScene::add_Obs_point(ObservationPoint * _op){
	//ObservationPoint * obs= new ObservationPoint(this->currentDoc->get_startdate());//QDateTime::fromString(lineEdit->text(),"dd.hh:mm:ss")TimeSpanExtension::tryTimeSpanSet(lineEdit->text().toStdString()));
	//static_cast<XemlDocument*>(this->currentDoc)->observationPointsCounter++,
	//_story->add_obsPoint(obs);
	//my_selected_story->get_story()->add_obsPoint(obs);
	//obs->set_id(_id);

	new GraphicObservationPointItem(_op,0,0,this->max_width,my_selected_story);

}




