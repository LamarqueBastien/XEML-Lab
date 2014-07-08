#include "graphicstoryscene.h"



GraphicStoryScene::GraphicStoryScene(int  _positionY,QGraphicsScene * parent)
	:QGraphicsScene(parent)
{

	//this->currentDoc=_currentDoc;
	//this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

	setItemIndexMethod(NoIndex);
	this->positionY=_positionY;
	this->my_selected_story=NULL;
	this->my_selected_event=NULL;
	this->my_selected_obsPoint=NULL;
	this->Z_value=1;
	selected_item=NULL;


	//connect(this,SIGNAL(selectionChanged()),this,SLOT(changedSelection()));
	createActions();
	connect(this,SIGNAL(obsPoint2added(ObservationPoint*,int)),this,SLOT(add_Obs_point(ObservationPoint*,int)));
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
	//;
	//this->addItem(my_second_item);
	//this->addItem();
	//this->addItem(my_third_item);

	//connect(this,SIGNAL(sceneRectChanged(QRectF)),my_item,SLOT()
}

/*
void GraphicStoryScene::changedSelection(){
	for (int i=0; i<selectedItems().size(); i++){
		switch(selectedItems().at(i)->type()){

			case GraphicStoryItem::Type:
				std::cerr << "story selected" << std::endl;
				emit set_details_in_view(static_cast<GraphicStoryItem*>(selectedItems().at(i))->get_story());
				//this->my_selected_story=static_cast<GraphicStoryItem*>(item);

				break;
			case GraphicEventItem::Type:
				std::cerr << "event selected" << std::endl;

				//this->my_selected_event=static_cast<GraphicEventItem*>(item);

				break;
			case GraphicObservationPointItem::Type:
				std::cerr << "OP selected" << std::endl;

				//this->my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(item);




				break;
		}

		//std::cerr << "item : " << selectedItems().at(i) << std::endl;
	}
	std::cerr << "selection changed" << std::endl;
}
*/
void                              GraphicStoryScene::set_doc(ItfDocument  * _currentDoc){
	this->currentDoc=_currentDoc;
}
void                              GraphicStoryScene::set_max_item_width(qreal _max_width){
	this->max_width=_max_width;
}
qreal                             GraphicStoryScene::get_max_width(){
	return this->max_width;
}
GraphicStoryItem *                GraphicStoryScene::get_item_by_label(QString _label){
	//std::cerr << "entering get_item_by_label" << std::endl;

	//std::cerr << "label of parent : " << _label.toStdString() << std::endl;
	QList<QGraphicsItem*> item_list=this->items();
	//std::cerr << "items size :" << this->items().size() << std::endl;

	QList<QGraphicsItem*>::iterator it;
	for(it=item_list.begin();it!=item_list.end();++it){
		if ((*it)->type()==GraphicStoryItem::Type){

			//std::cerr << "story label : " << static_cast<GraphicStoryItem*>((*it))->get_label().toStdString() << std::endl;
			if(static_cast<GraphicStoryItem*>((*it))->get_label()==_label){
				return static_cast<GraphicStoryItem*>((*it));
			}
		}
	}
	return NULL;
}
void                              GraphicStoryScene::createActions(){
	show_details = new QAction(QIcon(":/Images/new.png"),tr("&Details"), this);
	show_details->setShortcut(tr("Ctrl+S"));
	show_details->setStatusTip(tr("Show details about story"));
	display_plot = new QAction(QIcon(":/Images/new.png"),tr("&plot environmental variables"), this);
	display_plot->setShortcut(tr("Ctrl+S"));
	display_plot->setStatusTip(tr("Show plot about quantitative parameters values"));
	//display_plot->setEnabled(false);
	removeOP = new QAction(QIcon(":/Images/new.png"),tr("&Remove an Observation"), this);
	removeOP->setShortcut(tr("Ctrl+R"));
	removeOP->setStatusTip(tr("Remove observation Point"));
	removeEvent = new QAction(QIcon(":/Images/new.png"),tr("&Remove"), this);
	removeEvent->setShortcut(tr("Ctrl+R"));
	removeEvent->setStatusTip(tr("Remove event"));
	//editEvent = new QAction(QIcon(":/Images/new.png"),tr("&Edit"), this);
	//editEvent->setShortcut(tr("Ctrl+R"));
	//editEvent->setStatusTip(tr("Edit Event"));
	addSamples = new QAction(QIcon(":/Images/new.png"),tr("&Add samples"), this);
	addSamples->setShortcut(tr("Ctrl+Alt+S"));
	addSamples->setStatusTip(tr("Add Samples"));

	add_story = new QAction(QIcon(":/Images/new.png"),tr("&Add Story"), this);
	add_story->setShortcut(tr("Ctrl+S"));
	add_story->setStatusTip(tr("Add a new story"));

	add_obspoint = new QAction(QIcon(":/Images/new.png"),tr("&Add Observation Point"), this);
	add_obspoint->setShortcut(tr("Ctrl+S"));
	add_obspoint->setStatusTip(tr("Add a new Observation Point"));

	addEvent = new QAction(QIcon(":/Images/new.png"),tr("&Add Event"), this);
	addEvent->setShortcut(tr("Ctrl+S"));
	addEvent->setStatusTip(tr("Add a new Event"));



	connect(show_details, SIGNAL(triggered()), this, SLOT(details_story()));
	connect(display_plot,SIGNAL(triggered()),this,SLOT(display_plot_parameters()));
	connect(removeOP, SIGNAL(triggered()), this, SLOT(remove_obsPoint()));
	connect(removeEvent,SIGNAL(triggered()),this,SLOT(remove_event()));
	//connect(editEvent,SIGNAL(triggered()),this,SLOT(edit_event()));
	connect(addSamples,SIGNAL(triggered()),this,SLOT(add_sample()));
	connect(add_obspoint,SIGNAL(triggered()),this,SLOT(addObspoint()));
	connect(addEvent,SIGNAL(triggered()),this,SLOT(add_event()));

}
/*
void                              GraphicStoryScene::edit_event(){
	emit event2edit();
}
*/
void                              GraphicStoryScene::add_sample(){

	/*
	this->obsWizard =new ObservationWizard(this->storyNode,rootStory,current_OP,this->doc_resources,this->doc);
	this->obsWizard->show();
	this->close();
	*/
	emit sample_to_add();
}
void                              GraphicStoryScene::createMenus(){
	contextMenu =new QMenu("Details");
	contextMenu->addAction(show_details);
	contextMenu->addAction(display_plot);
}
void                              GraphicStoryScene::details_story(){
	emit show_details_story(this->my_selected_story);
}


void                              GraphicStoryScene::display_plot_parameters(){
	emit on_displayed_plot_parameter(my_selected_story->get_story());
}
void                              GraphicStoryScene::dropEvent(QGraphicsSceneDragDropEvent * event){
		//std::cerr << "event_drop" << std::endl;
		QGraphicsItem* item = itemAt(event->scenePos(),QTransform());
		//QGraphicsItem* item = mouseGrabberItem();
		if(item!=0){
			switch(item->type()){
				case GraphicStoryItem::Type:
					//my_selected_story=static_cast<GraphicStoryItem*>(item);
					selected_item=static_cast<GraphicStoryItem*>(item);
		//if (my_selected_story!=NULL){
					if (event->mimeData()->hasText()) {
						const QMimeData *mime = event->mimeData();
						QStringList pieces = mime->text().split(QRegExp("\\s+"),
											  QString::SkipEmptyParts);
						QPoint position = event->pos().toPoint();
						QPoint hotSpot;

						QList<QByteArray> hotSpotPos = mime->data("application/x-hotspot").split(' ');
						if (hotSpotPos.size() == 2) {
							hotSpot.setX(hotSpotPos.first().toInt());
							hotSpot.setY(hotSpotPos.last().toInt());
						}

						foreach (QString piece, pieces) {
							//QMessageBox::information(NULL,"added element",piece);
							emit variable_to_add(piece);

						}

					}
			}

		}
		else{
			QMessageBox::information(NULL,"added element","no story selected");

		}
}
void                              GraphicStoryScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
	//std::cerr << "drag_enter_event" << std::endl;
}
void                              GraphicStoryScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
	//std::cerr << "drag_move_event" << std::endl;
}
void                              GraphicStoryScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent){


/*
	std::cerr << "entering double click" << std::endl;
	QGraphicsItem* item = itemAt(mouseEvent->scenePos(),QTransform());
	//QGraphicsItem* item = mouseGrabberItem();
	if(item!=0){
		switch(item->type()){
			case GraphicStoryItem::Type:
				std::cerr << "entering story item type" << std::endl;

				this->my_selected_story=static_cast<GraphicStoryItem*>(item);
				//this->my_selected_story->add_point_selection();
				this->my_selected_obsPoint=NULL;
				this->my_selected_event=NULL;
				//emit set_details_in_view(static_cast<GraphicStoryItem*>(item)->get_story());
				emit set_details_in_view(item);
				std::cerr << "emit signals" << std::endl;



				break;
			case GraphicEventItem::Type:
				this->my_selected_event=static_cast<GraphicEventItem*>(item);
				this->my_selected_story=NULL;
				this->my_selected_obsPoint=NULL;
				emit set_details_in_view(item);

				break;
			case GraphicObservationPointItem::Type:
				this->my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(item);
				this->my_selected_event=NULL;
				this->my_selected_story=NULL;
				emit set_details_in_view(item);
				break;
		}

	}
	else{

		this->my_selected_story=NULL;
		this->my_selected_obsPoint=NULL;
		this->my_selected_event=NULL;
		emit set_details_in_view(item);
		std::cerr << "empty selection" << std::endl;
	}
	selectedItems().clear();
	QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
*/
}
void                              GraphicStoryScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

	//std::cerr << "entering mouse press event" << std::endl;

	/*
	if (mouseEvent->button() == Qt::LeftButton){

		QGraphicsItem* item = itemAt(mouseEvent->scenePos(),QTransform());
		//QGraphicsItem* item = mouseGrabberItem();
		if(item!=0){
			switch(item->type()){

				case GraphicStoryItem::Type:
					this->my_selected_story=static_cast<GraphicStoryItem*>(item);
					emit set_details_in_view(static_cast<GraphicStoryItem*>(item)->get_story());


					break;
				case GraphicEventItem::Type:
					this->my_selected_event=static_cast<GraphicEventItem*>(item);

					break;
				case GraphicObservationPointItem::Type:
					this->my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(item);




					break;
			}
		}
		else{
			this->my_selected_story=NULL;
			this->my_selected_obsPoint=NULL;
			this->my_selected_event=NULL;
			std::cerr << "empty selection" << std::endl;
		}
		selectedItems().clear();
	}
	*/

	//else if(mouseEvent->button() == Qt::RightButton){
	if(mouseEvent->button() == Qt::RightButton){

		QGraphicsItem* item = itemAt(mouseEvent->scenePos(),QTransform());

		if(item!=0){
			switch(item->type()){
				case GraphicStoryItem::Type:
					this->my_selected_story=static_cast<GraphicStoryItem*>(item);
					//std::cerr << "mouse pos x :" << mouseEvent->scenePos().x() << std::endl;

					contextMenu =new QMenu("Story",mouseEvent->widget());
					contextMenu->addAction(show_details);
					contextMenu->addAction(display_plot);

					contextMenu->addAction(add_story);
					contextMenu->addAction(add_obspoint);
					contextMenu->addAction(addEvent);
					mouse_pos=mouseEvent->scenePos();
					contextMenu->exec(mouseEvent->screenPos());


					break;
				case GraphicObservationPointItem::Type:
					this->my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(item);
					contextMenu =new QMenu("Observation Point",mouseEvent->widget());
					contextMenu->addAction(removeOP);
					contextMenu->addAction(addSamples);
					mouse_pos=mouseEvent->scenePos();
					contextMenu->exec(mouseEvent->screenPos());

					break;
				case GraphicEventItem::Type:
					this->my_selected_event=static_cast<GraphicEventItem*>(item);
					contextMenu =new QMenu("Event",mouseEvent->widget());
					contextMenu->addAction(removeEvent);
					//contextMenu->addAction(editEvent);
					contextMenu->exec(mouseEvent->screenPos());

					break;
			}
		}
		else{
			std::cerr << "empty selection" << std::endl;
		}
		selectedItems().clear();
	}
	if(mouseEvent->button() == Qt::LeftButton){
		QGraphicsItem* item = itemAt(mouseEvent->scenePos(),QTransform());
		//QGraphicsItem* item = mouseGrabberItem();
		if(item!=0){
			switch(item->type()){
				case GraphicStoryItem::Type:
					//std::cerr << "entering story item type" << std::endl;

					this->selected_item=static_cast<GraphicStoryItem*>(item);
					this->my_selected_story=static_cast<GraphicStoryItem*>(item);
					this->my_selected_story->setSelected(true);
					this->Z_value++;
					this->my_selected_story->setZValue(Z_value);
					//this->my_selected_story->add_point_selection();
					this->my_selected_obsPoint=NULL;
					this->my_selected_event=NULL;
					for (int i=0;i<this->items().count();i++){
						if (this->items().at(i)->type()==GraphicStoryItem::Type){
							if(static_cast<GraphicStoryItem*>(this->items().at(i))->get_story()->get_label()==this->my_selected_story->get_story()->get_label() ){

							}
							else{
								this->items().at(i)->setSelected(false);

							}
						}
						else{
							this->items().at(i)->setSelected(false);

						}
					}
					//emit set_details_in_view(static_cast<GraphicStoryItem*>(item)->get_story());
					emit set_details_in_view(item);
					//std::cerr << "emit signals" << std::endl;



					break;
				case GraphicEventItem::Type:
					this->selected_item=static_cast<GraphicEventItem*>(item);

					this->my_selected_event=static_cast<GraphicEventItem*>(item);
					this->Z_value++;
					this->my_selected_event->setZValue(Z_value);
					this->my_selected_story=NULL;
					this->my_selected_obsPoint=NULL;
					for (int i=0;i<this->items().count();i++){
						if (this->items().at(i)->type()==GraphicEventItem::Type){
							if(static_cast<GraphicEventItem*>(this->items().at(i))->get_event()->get_label()==this->my_selected_event->get_event()->get_label() ){

							}
							else{
								this->items().at(i)->setSelected(false);

							}
						}
						else{
							this->items().at(i)->setSelected(false);

						}
					}
					emit set_details_in_view(item);

					break;
				case GraphicObservationPointItem::Type:
					this->selected_item=static_cast<GraphicObservationPointItem*>(item);

					this->Z_value++;
					this->my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(item);
					this->my_selected_obsPoint->setZValue(Z_value);
					this->my_selected_event=NULL;
					this->my_selected_story=NULL;
					for (int i=0;i<this->items().count();i++){
						if (this->items().at(i)->type()==GraphicObservationPointItem::Type){
							if(static_cast<GraphicObservationPointItem*>(this->items().at(i))->get_obspoint()->get_id()==this->my_selected_obsPoint->get_obspoint()->get_id() ){

							}
							else{
								this->items().at(i)->setSelected(false);

							}
						}
						else{
							this->items().at(i)->setSelected(false);

						}
					}
					emit set_details_in_view(item);
					break;
			}

		}
		else{

			this->my_selected_story=NULL;
			this->my_selected_obsPoint=NULL;
			this->my_selected_event=NULL;
			this->selected_item=NULL;
			emit set_details_in_view(item);
			//std::cerr << "empty selection" << std::endl;
		}
		selectedItems().clear();
	}



	QGraphicsScene::mousePressEvent(mouseEvent);


}
void                              GraphicStoryScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
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
void                              GraphicStoryScene::set_selected_story(GraphicStoryItem * _selected_story){
	this->my_selected_story=_selected_story;
}
void                              GraphicStoryScene::set_selected_item(QGraphicsItem * _selected_item){
	this->selected_item=_selected_item;
}
GraphicStoryItem                * GraphicStoryScene::get_selected_story(){
	return this->my_selected_story;
}
GraphicEventItem                * GraphicStoryScene::get_selected_event(){
	return this->my_selected_event;
}
QGraphicsItem                   * GraphicStoryScene::get_selected_item(){
	return this->selected_item;
}
GraphicObservationPointItem     * GraphicStoryScene::get_selected_obsPoint(){
	return this->my_selected_obsPoint;
}
void                              GraphicStoryScene::set_right_for_childs(QGraphicsItem * item,qreal _movement){

	//std::cerr << "entering set right for child" << std::endl;

	QGraphicsItem * child_item;
	GraphicStoryItem * tmp;
	GraphicEventItem * tmp_event;
	GraphicObservationPointItem * tmpobs;
	QPointF topRight;
	QPointF topLeft;
	QPointF center;
	QPointF test;
	QPointF newpos;
	qreal obs_point_center_x;
	QDateTime obstime;
	qreal tmp_size;
	qreal shift;

	QString new_toolTipEvent="";
	if (!item->childItems().empty()){
		//std::cerr << "size : " << item->childItems().size() << std::endl;
		for(int i=0;i<item->childItems().size();i++){
			//std::cerr << "in da loop "<< std::endl;
			child_item=item->childItems().at(i);


			switch(child_item->type()){
				case GraphicStoryItem::Type:
					tmp=static_cast<GraphicStoryItem*>(child_item);
					shift=translate_second_in_distance(get_seconds_from_date(static_cast<StorySplit*>(static_cast<GraphicStoryItem*>(item)->get_story())->get_timepoint(),
																			 static_cast<StorySplit*>(tmp->get_story())->get_timepoint()));

					//std::cerr << "son name : " << tmp->get_label().toStdString() << std::endl;
					tmp_size= tmp->get_rect().width()- _movement;
					//tmp->set_right(tmp_size);
					test=tmp->mapToScene(tmp->mapFromParent(tmp->pos().x(),tmp->pos().y()));
					/*
					std::cerr << "tmp_size----------------= " << tmp_size << std::endl;
					std::cerr << "movement ----------------= " << _movement << std::endl;
					std::cerr << "test x----------------= " << test.x() << std::endl;
					std::cerr << "max_width----------------= " << max_width << std::endl;
					std::cerr << "tmp pos x----------------= " << tmp->pos().x() << std::endl;
					*/
					//std::cerr << "story :" << tmp->get_label().toStdString() <<"test x----------------= " << test.x() << std::endl;


					if(static_cast<GraphicStoryItem*>(item)->get_rect().width()>0){


						if(static_cast<GraphicStoryItem*>(item)->get_rect().width()>shift*zoomFactor){
							tmp->set_right(tmp_size);

						}
						/*
						else if(tmp->get_rect().width()==0){
							//here is the problem when child item width equal to zero
							tmp->setPos(0,0);
							tmp->set_right(0);
						}
						*/
						else{
							tmp->setPos(tmp->pos().x()-_movement,0);

							//tmp->setPos(static_cast<GraphicStoryItem*>(item)->get_rect().width()-_movement,0);
							tmp->set_right(0);
						}
						/*
						if(test.x()==max_width){
							std::cerr << "case 1" << std::endl;
							tmp->setPos(static_cast<GraphicStoryItem*>(item)->get_rect().width()-_movement,0);
							tmp->set_right(0);
						}
						else if (test.x()<max_width){
							std::cerr << "case 2" << std::endl;
							tmp->set_right(tmp_size);
						}
						else{
							tmp->setPos(0,0);
							tmp->set_right(0);
						}
						*/
					}
					else{
						//std::cerr << "case 3" << std::endl;
						tmp->setPos(0,0);
						tmp->set_right(0);
					}

					/*
					if (tmp_size<=0){
						if(tmp->pos().x()>0){
							tmp->setPos(tmp->pos().x()-_movement,0);
						}
						else{
							tmp->setPos(0,0);
						}

						//if (test.x()>=max_width){
							//tmp->setPos(tmp->pos().x()-_movement,0);
						//}
						//else{
							//tmp->setPos(0,0);

						//}

						tmp->set_right(0);
					}
					*/

					static_cast<StorySplit*>(tmp->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(test.x()/zoomFactor)));
					tmp->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<StorySplit*>(tmp->get_story())->get_timepoint())));

					//static_cast<GraphicStoryItem*>((*it))->change();
					//static_cast<GraphicStoryItem*>((*it))->set_right(static_cast<GraphicStoryItem*>((*it))->get_rect().width()-_movement);
					if(!(tmp->childItems().empty())){
					//if(tmp->get_story_child()!=false){
						set_right_for_childs(tmp,_movement);
					}

					break;
				case GraphicEventItem::Type:
					//std::cerr << "event type : "<< std::endl;
					tmp_event=static_cast<GraphicEventItem*>(child_item);
					newpos=tmp_event->mapToScene(tmp_event->mapFromParent(tmp_event->pos().x(),tmp_event->pos().y()));
					shift=max_width-static_cast<GraphicStoryItem*>(item)->get_rect().width();

					if (newpos.x()<this->max_width){
						tmp_event->get_event()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(newpos.x()/zoomFactor)));
						//tmp_event->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmp_event->get_event()->get_timepoint())));
						new_toolTipEvent+=tmp_event->get_event()->get_label();
						new_toolTipEvent+="\n";
						new_toolTipEvent+="-----------\n";
						new_toolTipEvent+=translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmp_event->get_event()->get_timepoint()));
						tmp_event->setToolTip(new_toolTipEvent);
					}
					else{
						if(newpos.x()>=this->max_width){
							//std::cerr << "new pos after limits" << std::endl;
							//std::cerr << "new pos x : " << newpos.x() << std::endl;
							//std::cerr << "shift : " << shift << std::endl;
							tmp_event->setPos((newpos.x()-(shift*zoomFactor))-_movement,0);
							tmp_event->get_event()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(newpos.x()/zoomFactor)));
							//tmp_event->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmp_event->get_event()->get_timepoint())));
							new_toolTipEvent+=tmp_event->get_event()->get_label();
							new_toolTipEvent+="\n";
							new_toolTipEvent+="-----------\n";
							new_toolTipEvent+=translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmp_event->get_event()->get_timepoint()));
							tmp_event->setToolTip(new_toolTipEvent);
						}

					}




					//tmp_event->get_event()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(newpos.x()/zoomFactor)));
					//tmp_event->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmp_event->get_event()->get_timepoint())));
					break;

				case GraphicObservationPointItem::Type:


					//std::cerr << " set pos for obsPoint" << std::endl;
					tmpobs=static_cast<GraphicObservationPointItem*>(child_item);
					newpos=tmpobs->mapToScene(tmpobs->mapFromParent(tmpobs->pos().x(),tmpobs->pos().y()));
					//tmpobs->get_obspoint()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(newpos.x()/zoomFactor)));
					//tmpobs->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmpobs->get_obspoint()->get_timepoint())));
					shift=max_width-static_cast<GraphicStoryItem*>(item)->get_rect().width();
					if (newpos.x()<this->max_width){
						tmpobs->get_obspoint()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(newpos.x()/zoomFactor)));
						tmpobs->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmpobs->get_obspoint()->get_timepoint())));
					}
					else{
						if(newpos.x()>=this->max_width){
							//std::cerr << "new pos after limits" << std::endl;
							//std::cerr << "new pos x : " << newpos.x() << std::endl;
							//std::cerr << "shift : " << shift << std::endl;
							tmpobs->setPos((newpos.x()-(shift*zoomFactor))-_movement,0);
							tmpobs->get_obspoint()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(newpos.x()/zoomFactor)));
							tmpobs->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmpobs->get_obspoint()->get_timepoint())));
						}

					}




					/*
					//obs_point_center_x=(tmpobs->boundingRect().topRight().x-tmpobs->boundingRect().topLeft().x)/2;
					//topRight=tmpobs->mapToScene(tmpobs->boundingRect().topRight());
					//topLeft =tmpobs->mapToScene(tmpobs->boundingRect().topLeft());
					//center =tmpobs->mapToScene(tmpobs->boundingRect().center());
					//obs_point_center_x=(topRight.x()-topLeft.x())/2;
					//obstime=get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(center.x()));
					//tmpobs->get_obspoint()->set_timepoint(obstime);
					//tmpobs->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),tmpobs->get_obspoint()->get_timepoint())));

					if(center.x()>=max_width){
						std::cerr <<" cool" << std::endl;
					}
					*/
					/*
					std::cerr << "obs son  id : " << tmpobs->get_obspoint()->get_id() << std::endl;
					std::cerr << "obs son pos center: " << tmpobs->boundingRect().center().x() << std::endl;
					std::cerr << "obs son pos top left: " << tmpobs->boundingRect().topLeft().x() << std::endl;
					std::cerr << "obs son pos top right: " << tmpobs->boundingRect().topRight().x() << std::endl;
					std::cerr << "obs son pos map to scene :"<< topRight.x() << std::endl;
					//std::cerr << "obs son pos : " << tmpobs->boundingRect().center().x() << std::endl;
					*/
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
void                              GraphicStoryScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
	//std::cerr << "entering mousemove event in scene" << std::endl;

	//QGraphicsItem                   * selected_item;
	GraphicStoryItem                * selected_parent_item;
	GraphicStoryItem                * selected_story;
	GraphicEventItem                * selected_event;
	GraphicObservationPointItem     * selected_obsPoint;

	if ((e->buttons() & Qt::LeftButton)) {

		//selected_item = itemAt(e->scenePos(),QTransform());


		//std::cerr << "item position x : " << item_point.x() << std::endl;
		if(selected_item!=0 ){//&& selected_item->isSelected()

			//QPointF item_point;
			//QPointF item_point2;
			//QPointF item2_point;
			//QPointF scene_point;
			//QPointF event_item_pos;
			//QPointF test;
			//QPointF map_parent_item2Scene;
			QPointF mouse_point;
			//QPointF story_startpoint;
			bool isSplit=false;
			qreal shift=0;
			//qreal selectable_zone=0;
			qint64 hours;
			//ObservationPoint * tmp=0;
			//QDateTime tmptime;
			QString new_toolTipEvent="";

			switch(selected_item->type()){
				case GraphicStoryItem::Type:
					//if (my_selected_story!=NULL){
					//std::cerr << "type storyitem" << std::endl;
					selected_story=static_cast<GraphicStoryItem*>(selected_item);// my_selected_story;
						//my_selected_story->setZValue(100000);
					isSplit=selected_story->get_isStorySplit();
					if(isSplit){
						//if (selected_story->isSelected()){
							mouse_point = e->scenePos();
							//std::cerr << "mouse point y : " << mouse_point.y() << std::endl;
							//if(mouse_point.x()>=0 && mouse_point.y()>=0){
								shift=this->max_width-selected_story->get_parent()->get_rect().width();
								if(mouse_point.x()>=(selected_story->pos().x()+shift)-100 && mouse_point.x()<=(selected_story->pos().x()+shift)+100){
									//std::cerr << "mouse point y : " << mouse_point.y() << std::endl;

									selected_story->change();
									//storysplit without childs

									if ((mouse_point.x()<=selected_story->get_parent()->get_rect().width()+shift)&& (mouse_point.x() >=shift)){

										qreal distance_to_move=mouse_point.x() - (selected_story->pos().x()+shift) ;

										selected_story->set_right(selected_story->get_parent()->get_rect().width() - (mouse_point.x()-shift));

										selected_story->setPos(mouse_point.x()-shift,0);//map_parent_item2Scene.x()

										//if(my_selected_story->get_story_child()==true){
										if(!selected_story->childItems().empty()){

											set_right_for_childs(selected_story, distance_to_move);
										}
										hours=mouse_point.x()/zoomFactor;
										static_cast<StorySplit*>(selected_story->get_story())->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
										selected_story->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),
																															 static_cast<StorySplit*>(selected_story->get_story())->get_timepoint())));
										emit set_details_in_view(selected_item);
										//emit set_details_in_view(selected_story->get_story());
									}
								}
							//}
						//}
					}
					break;
				case GraphicEventItem::Type:
					//std::cerr << "type event item" << std::endl;
					selected_event=static_cast<GraphicEventItem*>(selected_item);
					
					//selected_event=my_selected_event;
					mouse_point = e->scenePos();

					//item_point=selected_story->mapFromParent(QPointF(mouse_point.x(),mouse_point.y()));
					selected_parent_item = static_cast<GraphicStoryItem*>(selected_event->get_parent());
					if(selected_parent_item!=NULL){
						//if(selected_parent_item->get_label()==this->my_selected_story->get_label()){
						if(selected_parent_item->get_isStorySplit()){

							//shift=this->max_width-my_selected_story->get_rect().width();
							shift=this->max_width-selected_parent_item->get_rect().width();


						}

						//std::cerr << "item pos x : " << mouse_point.x() -shift << std::endl;
						//std::cerr << "shift : " << shift << std::endl;


						if ((mouse_point.x()<=selected_parent_item->get_rect().width()+shift)&& (mouse_point.x() >=shift)){

							selected_event->change();
							selected_event->setPos(mouse_point.x()-shift,0);//-shift
							hours=mouse_point.x()/zoomFactor;
							selected_event->get_event()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
							//selected_event->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),selected_event->get_event()->get_timepoint())));
							new_toolTipEvent+=selected_event->get_event()->get_label();
							new_toolTipEvent+="\n";
							new_toolTipEvent+="-----------\n";
							new_toolTipEvent+=translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),selected_event->get_event()->get_timepoint()));
							selected_event->setToolTip(new_toolTipEvent);
							emit set_details_in_view(selected_item);
						}
							//}
					}



					break;
				case GraphicObservationPointItem::Type:
					//std::cerr << "type obs point item" << std::endl;
					selected_obsPoint=static_cast<GraphicObservationPointItem*>(selected_item);

					mouse_point = e->scenePos();

					//if(selected_obsPoint!=NULL){
					//selected_obsPoint=this->my_selected_obsPoint;
					selected_parent_item = static_cast<GraphicStoryItem*>(selected_obsPoint->get_parent());
					//this->my_selected_story=selected_parent_item;
					if(selected_parent_item!=NULL){
						//if(selected_parent_item->get_label()==this->my_selected_story->get_label()){
						if(selected_parent_item->get_isStorySplit()){

							shift=this->max_width-selected_parent_item->get_rect().width();
							//std::cerr << "shift : " << shift << std::endl;
						}
						if ((mouse_point.x()<=selected_parent_item->get_rect().width()+shift)&& (mouse_point.x() >=shift)){
							//std::cerr << "shift : " << shift << std::endl;
							//std::cerr << "mouse point x :" << mouse_point.x() << std::endl;
							selected_obsPoint->change();
							selected_obsPoint->setPos(mouse_point.x()-shift,0);
							//selected_obsPoint->set_posx(mouse_point.x()-shift);
							//std::cerr << "selected_obspoint pos x :" << selected_obsPoint->pos().x() << std::endl;
							hours=mouse_point.x()/zoomFactor;
							selected_obsPoint->get_obspoint()->set_timepoint(get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(hours)));
							selected_obsPoint->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),
																														selected_obsPoint->get_obspoint()->get_timepoint())));
							emit set_details_in_view(selected_item);
						}
							//}
					}
					break;
				default:
					//QGraphicsScene::mouseMoveEvent(e);
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
void                              GraphicStoryScene::initialize_x_Axis(qreal width, int _zoomFactor){
	QGraphicsLineItem * tmp_timeline=new QGraphicsLineItem(0,-10,width,-10);
	tmp_timeline->setFlag(QGraphicsItem::ItemIsSelectable,false);
	tmp_timeline->setFlag(QGraphicsItem::ItemIsMovable,false);
	tmp_timeline->setFlag(QGraphicsItem::ItemIsFocusable,false);
	tmp_timeline->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
	this->addItem(tmp_timeline);
	int counter=0;
	int counter_hour=0;
	this->zoomFactor=_zoomFactor;
	QFont serifFont("Helvetica [Cronyx]", 14, QFont::Bold);
	QFont serifFont2("Times", 10, QFont::Bold);

	qreal number_of_days=width/(24*zoomFactor);
	int k=0;
	for (int i=0;i<=width;i+=width/number_of_days){
		//std::cerr << "range : " << i << std::endl;
		//QGraphicsItemGroup * group=new QGraphicsItemGroup();
		QGraphicsLineItem * tmp_line=new QGraphicsLineItem(i,-10,i,-30);
		tmp_line->setFlag(QGraphicsItem::ItemIsSelectable,false);
		tmp_line->setFlag(QGraphicsItem::ItemIsMovable,false);
		tmp_line->setFlag(QGraphicsItem::ItemIsFocusable,false);
		tmp_line->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
		this->addItem(tmp_line);
		//group->addToGroup(tmp_line);
		QDateTime dateTime= get_date(currentDoc->get_startdate(),translate_Distance_in_Msecs(i/zoomFactor));
		QString time=dateTime.toString("dd-MM-yyyy");// translate_second_in_DD_HH_MM_SS(translate_Distance_in_Msecs(i));
		//std::cerr << "time : " << time.toStdString() << std::endl;
		QGraphicsTextItem * tmp_text=new QGraphicsTextItem(time,tmp_timeline);

		//QGraphicsTextItem * tmp_text=new QGraphicsTextItem(QString::number(counter),tmp_timeline);
		tmp_text->setRotation(-60);





		tmp_text->setFlag(QGraphicsItem::ItemIsSelectable,false);
		tmp_text->setFlag(QGraphicsItem::ItemIsMovable,false);
		tmp_text->setFlag(QGraphicsItem::ItemIsFocusable,false);
		tmp_text->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
		tmp_text->setFont(serifFont);
		//group->addToGroup(tmp_text);

		tmp_text->setPos(i-10,-40);
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
void                              GraphicStoryScene::add_split_story(QString _label,StoryBase * _story){
	//std::cerr << "story added" << std::endl;
	//QGraphicsItem * selected_item;
	//GraphicStoryItem     * selected_story;
	//selected_item = itemAt(e->scenePos(),QTransform());
	//GraphicStoryItem *parent=static_cast<GraphicStoryItem*>(get_item_by_label(_story->get_label()));

	if(my_selected_story!=NULL){
		bool isSplit=my_selected_story->get_isStorySplit();
		//if(!isSplit){
		GraphicStoryItem * splititem=new GraphicStoryItem(my_selected_story->get_rect().width(),this->currentDoc,my_selected_story->get_rect().width(),_story,_label,true,0,positionY,my_selected_story);
		positionY+=61;
		setSceneRect(QRectF(-150, -150, this->sceneRect().width(), this->sceneRect().height()+60));
		emit set_details_in_view(splititem);
		this->my_selected_story=splititem;

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
void                              GraphicStoryScene::add_root_story(QString _label,StoryBase* _story){

	//std::cerr << "entering add root story in scene" << std::endl;
	GraphicStoryItem * new_item=new GraphicStoryItem(0,this->currentDoc,this->max_width,_story,_label,false,0,positionY, NULL);
	this->addItem(new_item);
	positionY+=61;
	setSceneRect(QRectF(-150, -150, this->sceneRect().width(), this->sceneRect().height()+60));
	this->my_selected_story=new_item;
	this->my_selected_event=NULL;
	this->my_selected_obsPoint=NULL;
	emit set_details_in_view(new_item);

}
void GraphicStoryScene::add_event(){

	//std::cerr <<"entering add_event slot " << std::endl;
	QGraphicsItem* item = itemAt(this->mouse_pos,QTransform());

	if(item!=0){
		//std::cerr << "item not null " << this->mouse_pos.x() << std::endl;
		switch(item->type()){
			case GraphicStoryItem::Type:
				//std::cerr << "graphic story item selected" << std::endl;

				this->my_selected_story=static_cast<GraphicStoryItem*>(item);
				GraphicStoryItem * tmp_story=static_cast<GraphicStoryItem*>(item);

				Event * e =new Event();
				EventDialog * event=new EventDialog(false,e,this->currentDoc,tmp_story->get_story(),this->mouse_pos.x());
				connect(event,SIGNAL(event_set(Event*,int)),this,SLOT(add_event(Event*,int)));
				event->setVisible(true);





				//emit event2added(event,this->mouse_pos.x());
				break;

		}
	}
	else{
		//std::cerr << "item null at :" << this->mouse_pos.x() << std::endl;
	}
}

void                              GraphicStoryScene::add_event(Event *e,int _posX){
	//std::cerr << "adding event" << std::endl;
	qreal y=my_selected_story->get_posy();
	//std::cerr << "position Y : " << y <<  std::endl;
	GraphicEventItem *tmp_event;
	//std::cerr << "pos x :" << _posX << std::endl;


	if (my_selected_story->get_isStorySplit()){
		//_posX=translate_second_in_distance(get_seconds_from_date(this->currentDoc->get_startdate(),e->get_timepoint()));
		tmp_event = new GraphicEventItem(e,
										 _posX-(translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<StorySplit*>(my_selected_story->get_story())->get_timepoint()))*zoomFactor),
										 y+20,
										 this->max_width,
										 e->get_label(),
										 currentDoc->get_startdate(),
										 get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(_posX/zoomFactor)),  //-(translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<StorySplit*>(my_selected_story->get_story())->get_timepoint()))*zoomFactor))+(translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<StorySplit*>(my_selected_story->get_story())->get_timepoint()))*zoomFactor))),//static_cast<StorySplit*>(my_selected_story->get_story())->get_timepoint(),
										 my_selected_story);

	}
	else{
		tmp_event = new GraphicEventItem(e,_posX,y+20,this->max_width,e->get_label(),currentDoc->get_startdate(),get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(_posX)), my_selected_story);

	}

	this->my_selected_event=tmp_event;
	this->my_selected_story=NULL;
	this->my_selected_obsPoint=NULL;
	this->selected_item=tmp_event;
	emit set_details_in_view(tmp_event);
	//tmp_item->setZValue(100000);
}
void                              GraphicStoryScene::remove_event(){
	//emit event2removed();
	Event * tmp_event;
	std::map<Event*,QDateTime>::iterator it_to_erase;
	for (std::list<StoryNode*>::iterator it =this->currentDoc->get_storyboard()->get_storyBoard()->begin();it!=this->currentDoc->get_storyboard()->get_storyBoard()->end();++it){
		StoryNode * tmp_node=static_cast<StoryNode*>((*it));
		//tmp_node->get_story()->get_eventcollection();
		for(std::map<Event*,QDateTime>::iterator it2=tmp_node->get_story()->get_eventcollection()->begin();it2!=tmp_node->get_story()->get_eventcollection()->end();++it2){
			if (static_cast<Event*>((*it2).first)->get_label()==this->my_selected_event->get_event()->get_label() && static_cast<Event*>((*it2).first)->get_timepoint()==this->my_selected_event->get_event()->get_timepoint()){
				it_to_erase=it2;
				tmp_event=static_cast<Event*>((*it2).first);

			}
		}
		tmp_node->get_story()->get_eventcollection()->erase(it_to_erase);
		delete tmp_event;

	}

	this->removeItem(this->my_selected_event);
	this->my_selected_event=NULL;
	emit set_details_in_view(this->my_selected_event);

}

void GraphicStoryScene::addObspoint(){

	//std::cerr <<"entering add_obspoint slot " << std::endl;
	QGraphicsItem* item = itemAt(this->mouse_pos,QTransform());

	if(item!=0){
		//std::cerr << "item not null " << this->mouse_pos.x() << std::endl;
		switch(item->type()){
			case GraphicStoryItem::Type:
				//std::cerr << "graphic story item selected" << std::endl;

				this->my_selected_story=static_cast<GraphicStoryItem*>(item);
				GraphicStoryItem * tmp_story=static_cast<GraphicStoryItem*>(item);

				int  obs_count=0;
				obs_count=static_cast<XemlDocument*>(this->currentDoc)->observationPointsCounter;//  count_total_observationsPoint(MainNode,obs_count);

				ObservationPoint * obs= new ObservationPoint(get_date(this->currentDoc->get_startdate(),translate_Distance_in_Msecs(this->mouse_pos.x())));//QDateTime::fromString(lineEdit->text(),"dd.hh:mm:ss")TimeSpanExtension::tryTimeSpanSet(lineEdit->text().toStdString()));

				static_cast<XemlDocument*>(this->currentDoc)->observationPointsCounter++,

				obs->set_id(obs_count+1);
				tmp_story->get_story()->add_obsPoint(obs);


				emit obsPoint2added(obs,this->mouse_pos.x());
				break;

		}
	}
	else{
		//std::cerr << "item null at :" << this->mouse_pos.x() << std::endl;
	}
}
void                              GraphicStoryScene::remove_obsPoint(){

	//emit obsPoint2removed();
	ObservationPoint * tmp_op;
	std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it_to_erase;
	for (std::list<StoryNode*>::iterator it =this->currentDoc->get_storyboard()->get_storyBoard()->begin();it!=this->currentDoc->get_storyboard()->get_storyBoard()->end();++it){
		StoryNode * _node=static_cast<StoryNode*>((*it));
		for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it2=_node->get_story()->get_obsPointCollection()->begin();it2!=_node->get_story()->get_obsPointCollection()->end();++it2){
			if (static_cast<ObservationPoint*>((*it2).first)->get_id()==this->my_selected_obsPoint->get_obspoint()->get_id() && static_cast<ObservationPoint*>((*it2).first)->get_timepoint()==this->my_selected_obsPoint->get_obspoint()->get_timepoint()){
				it_to_erase=it2;
				tmp_op=static_cast<ObservationPoint*>((*it2).first);

			}
		}
		_node->get_story()->get_obsPointCollection()->erase(it_to_erase);
		delete tmp_op;

	}
	this->removeItem(this->my_selected_obsPoint);
	this->my_selected_obsPoint=NULL;
	emit set_details_in_view(this->my_selected_obsPoint);
}

void                              GraphicStoryScene::add_Obs_point(ObservationPoint * _op, int _posX){


	std::cerr << "entering add obs_point" << std::endl;
	qreal y=my_selected_story->get_posy();
	std::cerr << "pos x :" << _posX << std::endl;

	GraphicObservationPointItem  * tmp;
	if (my_selected_story==NULL){
		//std::cerr << "parent story null" << std::endl;
	}
	//get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(_posX));
	if (my_selected_story->get_isStorySplit()){
		_posX=translate_second_in_distance(get_seconds_from_date(this->currentDoc->get_startdate(),_op->get_timepoint()));
		tmp=new GraphicObservationPointItem(_op,
											_posX-(translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<StorySplit*>(my_selected_story->get_story())->get_timepoint()))*zoomFactor),
											y+20,
											this->max_width,
											this->currentDoc->get_startdate(),
											get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(_posX/zoomFactor)), //static_cast<StorySplit*>(my_selected_story->get_story())->get_timepoint(),
											my_selected_story);

	}
	else{
		tmp=new GraphicObservationPointItem(_op,
											_posX,
											y+20,
											this->max_width,
											this->currentDoc->get_startdate(),
											get_date(this->currentDoc->get_startdate(), translate_Distance_in_Msecs(_posX)),
											my_selected_story);
	}
	this->my_selected_obsPoint=tmp;
	this->selected_item=tmp;
	emit set_details_in_view(tmp);
}




