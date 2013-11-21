#include "plotparameterview.h"

PlotParameterView::PlotParameterView(StoryBase * _current_story,ItfDocument * _current_doc,QWidget *parent) :
	QWidget(parent)
{
	this->tabWidget=new QTabWidget;
	this->current_doc=_current_doc;
	this->current_story=_current_story;
	this->plotScene=new GraphicPlotScene;
	this->plotView=new QGraphicsView(plotScene);
	initialize();
	QVBoxLayout  * layout = new QVBoxLayout;
	layout->addWidget(this->plotView);
	setLayout(layout);

}
void PlotParameterView::initialize(){


	int counter=0;
	int counter_hour=0;
	int k=0;
	//build the x and y axis.
	if (current_story->get_IsStorySplit()){
		x_length=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),current_doc->get_enddate()));
	}
	else{
		x_length=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),current_doc->get_enddate()));
	}
	QGraphicsLineItem * tmp_timeline=new QGraphicsLineItem(0,200,x_length,200);
	tmp_timeline->setFlag(QGraphicsItem::ItemIsSelectable,false);
	tmp_timeline->setFlag(QGraphicsItem::ItemIsMovable,false);
	tmp_timeline->setFlag(QGraphicsItem::ItemIsFocusable,false);
	tmp_timeline->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
	this->plotScene->addItem(tmp_timeline);
	qreal number_of_days=x_length/24;
	for (int i=0;i<=x_length;i+=x_length/number_of_days){
		if(i==0){
			QGraphicsLineItem * tmp_line=new QGraphicsLineItem(i,200,i,0);
			tmp_line->setFlag(QGraphicsItem::ItemIsSelectable,false);
			tmp_line->setFlag(QGraphicsItem::ItemIsMovable,false);
			tmp_line->setFlag(QGraphicsItem::ItemIsFocusable,false);
			tmp_line->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
			this->plotScene->addItem(tmp_line);
		}
		else{
			QGraphicsLineItem * tmp_line=new QGraphicsLineItem(i,200,i,180);
			tmp_line->setFlag(QGraphicsItem::ItemIsSelectable,false);
			tmp_line->setFlag(QGraphicsItem::ItemIsMovable,false);
			tmp_line->setFlag(QGraphicsItem::ItemIsFocusable,false);
			tmp_line->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
			this->plotScene->addItem(tmp_line);
		}
		counter++;
		counter_hour=0;
		k+=x_length/number_of_days;
		if(i!=x_length){
			for (int j=i;j<k;j+=x_length/number_of_days/24){

				if(counter_hour==0){


				}
				else if(counter_hour==24){
					counter_hour=0;
				}
				else{
					QGraphicsLineItem * tmp_little_line=new QGraphicsLineItem(j,200,j,195);
					this->plotScene->addItem(tmp_little_line);
					//QGraphicsTextItem * tmp_little_text=new QGraphicsTextItem(QString::number(counter_hour),tmp_timeline);
					//tmp_little_text->setFont(serifFont2);
					//tmp_little_text->setPos(j-8,-40);

				}
				counter_hour+=24/24;

			}
		}
	}






	//build the plot points.
	for (std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->current_story->get_variablesCollection()->begin();it!=current_story->get_variablesCollection()->end();++it){
		if((*it).first->get_namespacealias()=="XEO_Positioning"){

		}
		else if((*it).first->get_namespacealias()=="XEO"){
			//static_cast<DynamicTerm*>(*it)->get_dynamicvaluecollection()
		}

	}

}
