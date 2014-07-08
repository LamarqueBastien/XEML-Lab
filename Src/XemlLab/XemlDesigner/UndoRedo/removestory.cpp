#include "removestory.h"

RemoveStory::RemoveStory(QUndoCommand *parent)
	: QUndoCommand(parent)
{
}
void RemoveStory::undo()
{
	//myGraphicsScene->addItem(myDiagramItem);
	//myGraphicsScene->update();
}

void RemoveStory::redo()
{

}
