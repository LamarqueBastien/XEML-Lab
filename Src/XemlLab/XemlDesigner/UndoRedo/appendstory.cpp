#include "appendstory.h"

AppendStory::AppendStory(QGraphicsScene *scene, QUndoCommand *parent)
: QUndoCommand(parent)
{
}
void AppendStory::undo()
{
	//myGraphicsScene->addItem(myDiagramItem);
	//myGraphicsScene->update();
}

void AppendStory::redo()
{

}
