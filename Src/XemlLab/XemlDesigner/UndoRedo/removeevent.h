#ifndef REMOVEEVENT_H
#define REMOVEEVENT_H

#include <QUndoCommand>
#include <QGraphicsScene>
class RemoveEvent : public QUndoCommand
{
	public:
		RemoveEvent( QUndoCommand *parent = 0);
		void undo();
		void redo();
};

#endif // REMOVEEVENT_H
