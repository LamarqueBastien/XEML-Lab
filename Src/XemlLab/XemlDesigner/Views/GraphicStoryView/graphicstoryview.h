#ifndef GRAPHICSTORYVIEW_H
#define GRAPHICSTORYVIEW_H

#include<QGraphicsView>
#include<QMouseEvent>
#include<QLabel>
#include"Views/GraphicStoryView/graphicstoryscene.h"
#include"CoreObjects/storybase.h"
using namespace Xeml::Document;

class GraphicStoryView : public QGraphicsView
{
		Q_OBJECT

	public:
		GraphicStoryView(GraphicStoryScene * _currentScene,QGraphicsView * parent=0);
	protected:
		void wheelEvent(QWheelEvent *event);
		//void drawBackground(QPainter *p, const QRectF &rect);



		//void add_root_story(QString label,StoryBase * _story);
		//void mousePressEvent(QMouseEvent *event);

	private:
		GraphicStoryScene * current_scene;
		qreal width;
		qreal height;
		//QPixmap pix;
		bool init;

	signals:
		void story_split_added(QString _label,StoryBase *_story);
		void story_root_added(QString _label,StoryBase *_story);
		//void event_added(Event* e,int _posX);
		void obsPoint_added(ObservationPoint * _op,int _pos);
		void emit_zoom_in(int _zoomFactor);
		void emit_zoom_out(int _zoomFactor);
	private slots:
		void add_split_story(QString _label,StoryBase *_story);
		void add_root_story(QString _label,StoryBase *_story);
		//void add_event(Event * _e,int _posX);
		void add_obsPoint(ObservationPoint * _op);

		//void resize_Pixmap(QRectF rectScene);
};


#endif // GRAPHICSTORYVIEW_H
