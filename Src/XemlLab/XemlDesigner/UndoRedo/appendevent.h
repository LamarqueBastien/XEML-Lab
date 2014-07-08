#ifndef APPENDEVENT_H
#define APPENDEVENT_H
#include <QUndoCommand>
#include <QGraphicsScene>
#include"Views/GraphicStoryView/graphicstoryscene.h"
#include"CoreObjects/event.h"
#include"DialogWindows/eventdialog.h"
#include"Views/GraphicStoryView/Items/graphiceventitem.h"
using namespace Xeml::Document;
class AppendEvent : public QUndoCommand
{
	public:
		AppendEvent(Event * _e,int _posx,ItfDocument * _current_doc, GraphicStoryScene * _scene, QUndoCommand *parent = 0);
		void undo();
		void redo();
	private:
		Event * event;
		GraphicEventItem * eventItem;
		GraphicStoryScene * scene;
		QPointF initialPosition;
		ItfDocument * current_doc;



	signals:

	public slots:
};

#endif // APPENDEVENT_H
