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

	this->setRenderHints(QPainter::Antialiasing);
	this->init=true;

}

void GraphicStoryView::drawBackground(QPainter *p, const QRectF &rect){
	QPixmap pix("://Images/GreenMetal.png");
	//std::cerr << "draw background " << " w : " << this->sceneRect().width()<< " h : "<< this->sceneRect().height()<<std::endl;
	if(this->init){
		//std::cerr << "first draw background " << " w : " << this->sceneRect().width()<< " h : "<< this->sceneRect().height()<<std::endl;
		//this->matrix().mapRect(this->sceneRect()).width();
		p->drawPixmap(QRect(-150, -150, this->sceneRect().width(), 600), pix);
		this->init=false;
	}
	else{
		//p->drawPixmap(this->sceneRect(),pix,this->current_scene->sceneRect());
		/*
		if(this->current_scene->width()>700){

		*/
		//p->drawPixmap(QRect(-150, -150, this->matrix().mapRect(this->sceneRect()).width(), this->sceneRect().height()), pix);

		p->drawPixmap(QRect(-150, -150, this->current_scene->sceneRect().width(), this->sceneRect().height()), pix);
		//this->setSceneRect(-150, -150, this->current_scene->sceneRect().width(), this->sceneRect().height());
		/*}
		else{
			p->drawPixmap(QRect(-150, -150, 800, this->sceneRect().height()), pix);

		}
		*/

	}
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



