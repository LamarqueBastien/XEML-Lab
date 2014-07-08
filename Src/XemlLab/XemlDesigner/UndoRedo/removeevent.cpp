#include "removeevent.h"

RemoveEvent::RemoveEvent(QUndoCommand *parent)
	: QUndoCommand(parent)
{
}

void RemoveEvent::undo()
{
	//myGraphicsScene->addItem(myDiagramItem);
	//myGraphicsScene->update();
}

void RemoveEvent::redo()
{

}

