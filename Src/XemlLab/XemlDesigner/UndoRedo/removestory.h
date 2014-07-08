#ifndef REMOVESTORY_H
#define REMOVESTORY_H

#include <QUndoCommand>
#include <QGraphicsScene>

class RemoveStory : public QUndoCommand
{
	public:
		RemoveStory( QUndoCommand *parent = 0);
		void undo();
		void redo();
};

#endif // REMOVESTORY_H
