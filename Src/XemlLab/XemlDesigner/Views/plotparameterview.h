#ifndef PLOTPARAMETERVIEW_H
#define PLOTPARAMETERVIEW_H
#include<QGraphicsItem>
#include <QWidget>
#include<QTabWidget>
#include<QGraphicsView>
#include<QVBoxLayout>
#include<Views/GraphicStoryView/graphicplotscene.h>
#include"CoreObjects/storybase.h"
#include"Interface/itfdocument.h"

using namespace Xeml::Document;

class PlotParameterView : public QWidget
{
		Q_OBJECT
	public:
		explicit PlotParameterView(StoryBase * _current_story,ItfDocument * _current_doc,QWidget *parent = 0);

		void initialize();
	signals:

	public slots:

	private:
		QGraphicsView * plotView;
		GraphicPlotScene * plotScene;
		ItfDocument * current_doc;
		StoryBase * current_story;
		QTabWidget * tabWidget;
		qreal       x_length;
		qreal       y_length;

};

#endif // PLOTPARAMETERVIEW_H
