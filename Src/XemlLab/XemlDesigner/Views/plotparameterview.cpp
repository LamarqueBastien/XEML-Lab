#include "plotparameterview.h"

PlotParameterView::PlotParameterView(StoryBase * _current_story,ItfDocument * _current_doc,QWidget *parent) :
	QWidget(parent)
{
	this->tabWidget=new QTabWidget;
	this->current_doc=_current_doc;
	this->current_story=_current_story;
	setMinimumSize(400,400);

	initialize();
	QVBoxLayout  * layout = new QVBoxLayout;
	layout->addWidget(tabWidget);
	setLayout(layout);

}
void PlotParameterView::initialize(){

	//build using QCustomPlot

	for (std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->current_story->get_variablesCollection()->begin();it!=current_story->get_variablesCollection()->end();++it){

		if((*it).first->get_namespacealias()=="XEO_Positioning"){

		}
		else if((*it).first->get_namespacealias()=="XEO"){
			QCustomPlot * plot = new QCustomPlot();
			tabWidget->addTab(plot,static_cast<DynamicTerm*>((*it).first)->get_name());
			if (current_story->get_IsStorySplit()){
				x_length=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),current_doc->get_enddate()));
			}
			else{
				x_length=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),current_doc->get_enddate()));
			}
			int counter=0;
			int lastposX=0;
			int lastPosY=0;
			QString unit;
			//QVector<double> x(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size()), y(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size()); // initialize with entries 0..100


			QVector<double> x(22), y(22); // initialize with entries 0..100

			for (std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it2= static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->begin();it2!=static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->end();++it2){
				unit=static_cast<DynamicValue*>((*it2).first)->get_unit();
				if (static_cast<DynamicValueBase*>((*it2).first)->get_is_cycle()){

				}
				else{
					if (static_cast<DynamicValue*>((*it2).first)->get_context()=="Quantity"){
						std::cerr << static_cast<DynamicValue*>((*it2).first)->get_value().toStdString() << std::endl;
						std::cerr << translate_second_in_DD_HH_MM_SS(get_seconds_from_date(current_doc->get_startdate(), static_cast<DynamicValue*>((*it2).first)->get_timepoint())).toStdString() << std::endl;


						//for (int i=0; i<static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size(); ++i)
						//{
						/*
						x[counter] = 0; // x goes from -1 to 1
						y[counter] = static_cast<DynamicValue*>((*it2).first)->get_value().toInt();
						counter++;
						*/
						std::cerr << "value y: " << static_cast<DynamicValue*>((*it2).first)->get_value().toInt() << std::endl;
						std::cerr << "value x: " << translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(), static_cast<DynamicValue*>((*it2).first)->get_timepoint())) << std::endl;

						x[counter] = translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(), static_cast<DynamicValue*>((*it2).first)->get_timepoint()));
						y[counter] = static_cast<DynamicValue*>((*it2).first)->get_value().toInt();
						lastposX=x[counter];
						lastPosY=y[counter];
						counter++;


						//}
						// create graph and assign data to it:

					}
				}
			}
			std::cerr << "unit : " << unit.toStdString() << std::endl;
			if (lastposX!=x_length){
				for (int i = lastposX;i<=x_length;i+=24){
					x[counter] = i;
					y[counter] = lastPosY;
					counter++;
				}
			}


			/***********************************
			 * add bar plot representation *****

			plot->xAxis->setLabel("Time (days)");
			plot->yAxis->setLabel(unit);

			// set axes ranges, so we see all data:

			plot->xAxis->setRange(0, x_length);
			plot->xAxis->setTickLength(24);
			plot->yAxis->setRange(0, 100);
			QCPBars *newBars = new QCPBars(plot->xAxis, plot->yAxis);
			plot->addPlottable(newBars);
			newBars->setName("Parameter plot");
			newBars->setData(x, y);
			*/


			//plot representation
			plot->addGraph();
			plot->graph(0)->setData(x, y);
			// give the axes some labels:
			plot->xAxis->setLabel("Time (days)");
			plot->yAxis->setLabel(unit);

			// set axes ranges, so we see all data:
			plot->xAxis->setRange(0, x_length);
			plot->xAxis->setTickLength(24);
			plot->yAxis->setRange(0, 100);

			plot->replot();
		}
	}






//build the plot points.
	/*
	for (std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->current_story->get_variablesCollection()->begin();it!=current_story->get_variablesCollection()->end();++it){
		if((*it).first->get_namespacealias()=="XEO_Positioning"){

		}
		else if((*it).first->get_namespacealias()=="XEO"){
			//static_cast<DynamicTerm*>(*it)->get_dynamicvaluecollection()
			GraphicPlotScene * tmpPlotScene=new GraphicPlotScene;
			QGraphicsView * tmpPlotView=new QGraphicsView(tmpPlotScene);
			tmpPlotView->scale(1,-1);
			tabWidget->addTab(tmpPlotView,static_cast<DynamicTerm*>((*it).first)->get_name());
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
			for (std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it2= static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->begin();it2!=static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->end();++it2){
				if (static_cast<DynamicValueBase*>((*it2).first)->get_is_cycle()){

				}
				else{
					if (static_cast<DynamicValue*>((*it2).first)->get_context()=="Quantity"){
						std::cerr << static_cast<DynamicValue*>((*it2).first)->get_value().toStdString() << std::endl;
						std::cerr << translate_second_in_DD_HH_MM_SS(get_seconds_from_date(current_doc->get_startdate(), static_cast<DynamicValue*>((*it2).first)->get_timepoint())).toStdString() << std::endl;
						QGraphicsPathItem * my_path=new  QGraphicsPathItem();
						QPainterPath path;
						path.lineTo(0,static_cast<DynamicValue*>((*it2).first)->get_value().toInt());
						//here tra,smlate
						path.lineTo(x_length,static_cast<DynamicValue*>((*it2).first)->get_value().toInt());
						//path.quadTo(100,0,100,100);
						//path.quadTo(200,200,200,100);
						my_path->setPath(path);
						tmpPlotScene->addItem(my_path);

					}
				}
			}
			QGraphicsLineItem * tmp_timeline=new QGraphicsLineItem(0,0,x_length,0);
			tmp_timeline->setFlag(QGraphicsItem::ItemIsSelectable,false);
			tmp_timeline->setFlag(QGraphicsItem::ItemIsMovable,false);
			tmp_timeline->setFlag(QGraphicsItem::ItemIsFocusable,false);
			tmp_timeline->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
			tmpPlotScene->addItem(tmp_timeline);
			QGraphicsTextItem * tmp_text=new QGraphicsTextItem("(syad) emit");
			tmp_text->setFlag(QGraphicsItem::ItemIsSelectable,false);
			tmp_text->setFlag(QGraphicsItem::ItemIsMovable,false);
			tmp_text->setFlag(QGraphicsItem::ItemIsFocusable,false);
			tmp_text->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
			tmpPlotScene->addItem(tmp_text);
			//tmp_text->setFont(serifFont);
			//group->addToGroup(tmp_text);

			tmp_text->setPos(x_length+15,0);
			qreal number_of_days=x_length/24;
			for (int i=0;i<=x_length;i+=x_length/number_of_days){
				if(i==0){
					QGraphicsLineItem * tmp_line=new QGraphicsLineItem(i,0,i,200);
					tmp_line->setFlag(QGraphicsItem::ItemIsSelectable,false);
					tmp_line->setFlag(QGraphicsItem::ItemIsMovable,false);
					tmp_line->setFlag(QGraphicsItem::ItemIsFocusable,false);
					tmp_line->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
					tmpPlotScene->addItem(tmp_line);
				}
				else{
					QGraphicsLineItem * tmp_line=new QGraphicsLineItem(i,0,i,10);
					tmp_line->setFlag(QGraphicsItem::ItemIsSelectable,false);
					tmp_line->setFlag(QGraphicsItem::ItemIsMovable,false);
					tmp_line->setFlag(QGraphicsItem::ItemIsFocusable,false);
					tmp_line->setFlag(QGraphicsItem::ItemSendsGeometryChanges,false);
					tmpPlotScene->addItem(tmp_line);
				}
				counter++;
				counter_hour=0;
				k+=x_length/number_of_days;
				if(i!=x_length){
					for (int j=i;j<k;j+=x_length/number_of_days/2){

						if(counter_hour==0){


						}
						else if(counter_hour==24){
							counter_hour=0;
						}
						else{
							QGraphicsLineItem * tmp_little_line=new QGraphicsLineItem(j,0,j,5);
							tmpPlotScene->addItem(tmp_little_line);
							//QGraphicsTextItem * tmp_little_text=new QGraphicsTextItem(QString::number(counter_hour),tmp_timeline);
							//tmp_little_text->setFont(serifFont2);
							//tmp_little_text->setPos(j-8,-40);

						}
						counter_hour+=24/2;

					}
				}
			}
			//layout->addWidget(this->plotView);
		}

	}
	*/

}
