#include "graphicstoryview.h"

GraphicStoryView::GraphicStoryView(GraphicStoryScene * _currentScene,QGraphicsView * parent)
	:QGraphicsView(parent)
{
	this->setMouseTracking(true);

	this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	this->current_scene=_currentScene;
	connect(this->current_scene,SIGNAL(sceneRectChanged(QRectF)),this,SLOT(updateSceneRect(QRectF)));
	//connect(this->current_scene,SIGNAL(itemInserted(StoryItem*)),this,SLOT(add_story(StoryItem*)));
	this->setScene(this->current_scene);
	//this->setSceneRect(-150,-150,1200,1200);
	connect(this,SIGNAL(story_split_added(QString,StoryBase*)),this->current_scene,SLOT(add_split_story(QString, StoryBase*)));
	connect(this,SIGNAL(story_root_added(QString,StoryBase*)),this->current_scene,SLOT(add_root_story(QString,StoryBase*)));
	connect(this,SIGNAL(event_added(Event*)),this->current_scene,SLOT(add_event(Event*)));
	connect(this,SIGNAL(obsPoint_added(ObservationPoint*)),this->current_scene,SLOT(add_Obs_point(ObservationPoint*)));
	this->setRenderHints(QPainter::Antialiasing);
	this->init=true;

}

void GraphicStoryView::drawBackground(QPainter *p, const QRectF &rect){
	QPixmap pix("://Images/GreenMetal.png");
	//std::cerr << "draw background " << " w : " << this->sceneRect().width()<< " h : "<< this->sceneRect().height()<<std::endl;

	QRectF sceneRect = this->sceneRect();
	QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
	gradient.setColorAt(0, Qt::white);
	gradient.setColorAt(1, Qt::lightGray);
	p->fillRect(rect.intersected(sceneRect), gradient);
	p->setBrush(Qt::NoBrush);
	p->drawRect(sceneRect);
	/*
	if(this->init){
		//std::cerr << "first draw background " << " w : " << this->sceneRect().width()<< " h : "<< this->sceneRect().height()<<std::endl;
		//this->matrix().mapRect(this->sceneRect()).width();
		p->drawPixmap(QRect(-150, -150, this->sceneRect().width(), 600), pix);
		this->init=false;
	}
	else{
		//p->drawPixmap(this->sceneRect(),pix,this->current_scene->sceneRect());

		//p->drawPixmap(QRect(-150, -150, this->matrix().mapRect(this->sceneRect()).width(), this->sceneRect().height()), pix);

		p->drawPixmap(QRect(-150, -150, this->current_scene->sceneRect().width(), this->sceneRect().height()), pix);
		//this->setSceneRect(-150, -150, this->current_scene->sceneRect().width(), this->sceneRect().height());


	}
	*/

	resetCachedContent();


}

void GraphicStoryView::add_split_story(QString _label,StoryBase *_story){
	std::cerr << "entering add story in View" << std::endl;
	emit story_split_added(_label,_story);

}

void GraphicStoryView::add_root_story(QString _label,StoryBase * _story){
	emit story_root_added(_label,_story);
}
void GraphicStoryView::add_event(Event * _e){
	std::cerr << "emit event added in GraphicView " << std::endl;
	emit event_added(_e);
}
void GraphicStoryView::add_obsPoint(ObservationPoint * _op){

	std::cerr << "emit obsPoint added in GraphicView " << std::endl;
	emit obsPoint_added(_op);
}



