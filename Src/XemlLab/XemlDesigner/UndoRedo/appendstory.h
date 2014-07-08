#ifndef APPENDSTORY_H
#define APPENDSTORY_H
#include <QUndoCommand>
#include <QGraphicsScene>
#include <QObject>

class AppendStory : public QUndoCommand
{
	public:
		AppendStory(QGraphicsScene *graphicsScene, QUndoCommand *parent = 0);
		void undo();
		void redo();
	private:


	signals:

	public slots:

};

#endif // APPENDSTORY_H
