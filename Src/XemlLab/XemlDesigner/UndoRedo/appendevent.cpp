#include "appendevent.h"

AppendEvent::AppendEvent(Event * _e,int _posx,ItfDocument * _current_doc, GraphicStoryScene * _scene,QUndoCommand *parent)
	: QUndoCommand(parent)
{
	this->event=_e;
	//this->initialPosition=
	this->scene=_scene;
	this->current_doc=_current_doc;
	this->scene->add_event(event,_posx);
	this->setText(QObject::tr("Add event %1").arg(event->get_label()));

}
void AppendEvent::undo()
{

	//myGraphicsScene->addItem(myDiagramItem);
	//myGraphicsScene->update();
}

void AppendEvent::redo()
{

}
