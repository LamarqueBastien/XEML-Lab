#include "plotparameterview.h"

PlotParameterView::PlotParameterView(StoryBase * _current_story,ItfDocument * _current_doc,QWidget *parent) :
	QWidget(parent)
{
	this->tabWidget=new QTabWidget;
	this->current_doc=_current_doc;
	this->current_story=_current_story;
	setMinimumSize(200,200);

	initialize();
	QVBoxLayout  * layout = new QVBoxLayout;
	layout->addWidget(tabWidget);
	setLayout(layout);

}
void PlotParameterView::initialize(){

	//build using QCustomPlot

	qreal x_length_split;
	for (std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->current_story->get_variablesCollection()->begin();it!=current_story->get_variablesCollection()->end();++it){



		if((*it).first->get_namespacealias()=="XEO_Positioning"){

		}
		else if((*it).first->get_namespacealias()=="XEO"){


			std::cerr << " basic term label : " << static_cast<DynamicTerm*>((*it).first)->get_name().toStdString() << std::endl;


			QCustomPlot * plot = new QCustomPlot();

			tabWidget->addTab(plot,static_cast<DynamicTerm*>((*it).first)->get_name());
			x_length=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),current_doc->get_enddate()));
			QVector<double> x(x_length), y(x_length);
			QVector<double> x1, y2;

			x_length_split=x_length;
			if (current_story->get_IsStorySplit()){
				x_length_split=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),static_cast<StorySplit*>(current_story)->get_timepoint()));
			}
			std::cerr << "length story :" << x_length << "length storysplit : " << x_length_split << std::endl;
			//else{
				//x_length=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),current_doc->get_enddate()));
			//}
			int counter=0;
			int lastposX=0;
			int lastPosY=0;
			Cycle * c;

			DynamicValue * dv;
			QDateTime value_target_time;
			QString unit;
			int cycle_division_secs;
			//QVector<double> x(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size()), y(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size()); // initialize with entries 0..100
			bool last_is_cycle=false;
			int quantity_value_number=0;
			int lastvalue;
			int division;
			QVector<bool> is_cycle;
			QVector<std::pair<bool,int> > cycle_division;
			QVector<DynamicValue*> dynamicValues;
			QVector<int> quantitativeValues;
			QVector<int> values;
			QVector<double> cycle_values;
			for (int i=0;i<static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size();i++){
				if (static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_context()=="Quantity"){
					if (static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_is_cycle()){



						Cycle * c=static_cast<Cycle*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first);
						division=24/c->get_cycleValues()->size();
						is_cycle.append(true);
						cycle_division.append(make_pair(true,division));
						last_is_cycle=true;
						for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it3=c->get_cycleValues()->begin();it3!=c->get_cycleValues()->end();++it3){
							double value=static_cast<DynamicValue*>((*it3).first)->get_value().toDouble();
							cycle_values.append(value);
						}

					}
					else{

						division=1;
						cycle_division.append(make_pair(false,division));
						is_cycle.append(false);
						last_is_cycle=false;
						quantitativeValues.append(static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_value().toInt());
						lastvalue=static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_value().toInt();
					}

					//quantity_value_number++;
					//std::cerr << "value :" << static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_value().toInt() << std::endl;


					values.append(translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_timepoint())));
					//dynamicValues.append(static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first));
					//std::cerr << "add value :" << translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_timepoint())) << std::endl;
					//values[i]=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_timepoint()));
				}
			}
			quantitativeValues.append(lastvalue);
			values.append(x_length);
			is_cycle.append(last_is_cycle);
			cycle_division.append(make_pair(last_is_cycle,division));

			 // initialize with entries 0..100
			std::cerr << "QVsize :" << quantitativeValues.size() <<std::endl;

			//QVector<DynamicValue*> quantitativeValues(quantity_value_number+1);//(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size());
			/*
			for (int i=0;i<quantity_value_number+1;i++){
				if (static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_context()=="Quantity"){
					std::cerr << "add value :" << translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_timepoint())) << std::endl;
					//values[i]=translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(),static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first)->get_timepoint()));
					//quantitativeValues[i]=static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(i).first);
				}
			}
			*/

			for (int j=0;j<values.size()-1;j++){
				std::cerr << " j :" << j  << std::endl;
				std::cerr << "first limit : " << values[j] << "second limit :" << values[j+1]<< std::endl;

				double cycle_value;
				for (int k=values[j];k<=values[j+1];k++){
					std::cerr << " j :" << j  << std::endl;

					if (cycle_division.at(j).first==true){
						cycle_value=cycle_values.at(0);
						if ((k % cycle_division.at(j).second)==0){
							cycle_value+=cycle_division.at(j).second;
						}
						x[counter] = k;
						y[counter] = cycle_value;



					}
					else{
						std::cerr << " j :" << j  << std::endl;
						std::cerr << "counter :" << counter << std::endl;
						std::cerr << "k :" << k << std::endl;
						std::cerr << "y :" << quantitativeValues[j] << std::endl;
						//static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(j).first)->get_value().toInt();

						//x1.append(k);
						//y2.append(quantitativeValues[j]);
						x[counter] = k;
						y[counter] = quantitativeValues[j];//static_cast<DynamicValue*>(static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->at(j).first)->get_value().toInt();
						counter++;

					}
				}
			}
			/*
			for (std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it2= static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->begin();it2!=static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->end();++it2){

				unit=static_cast<DynamicValue*>((*it2).first)->get_unit();
				value_target_time=static_cast<DynamicValue*>((*it2).first)->get_timepoint();
				translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(), value_target_time.addSecs(cycle_division_counter)));

				if (static_cast<DynamicValueBase*>((*it2).first)->get_is_cycle()){

					//static_cast<DynamicValueBase*>((*it2).first)->
					if (static_cast<DynamicValue*>((*it2).first)->get_context()=="Quantity"){

						std::cerr <<"value is cycle value" << std::endl;
						std::cerr << "DynamicValue unit : " << static_cast<DynamicValueBase*>((*it2).first)->get_unit().toStdString() << std::endl;


						c = static_cast<Cycle*>(static_cast<DynamicValueBase*>((*it2).first));
						cycle_division_secs=(24/c->get_cycleValues()->size())*3600;
						int cycle_division_counter=0;
						//translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(), c->get_timepoint()));
						//QVector<double> x((x_length/24)*c->get_cycleValues()->size()), y((x_length/24)*c->get_cycleValues()->size());

						for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it3=c->get_cycleValues()->begin();it3!=c->get_cycleValues()->end();++it3){
						//	write_values(&val,static_cast<ValueBase*>((*it).first));
						//}

							std::cerr << "cycle value :" << static_cast<DynamicValue*>((*it3).first)->get_value().toStdString() << std::endl;
							for (int i=counter;i<counter+(24/c->get_cycleValues()->size());i++){
								std::cerr << "counter : " << counter  << std::endl;
								x[counter] = translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(), value_target_time.addSecs(cycle_division_counter)));
								y[counter] = static_cast<DynamicValue*>((*it3).first)->get_value().toInt();

								lastposX=x[counter];
								lastPosY=y[counter];
							//}
								counter++;
							}
							cycle_division_counter+=cycle_division_secs;
						}
						last_is_cycle=true;
					}

				}
				else{

					//QVector<double> x(x_length/24), y(x_length/24);
					if (static_cast<DynamicValue*>((*it2).first)->get_context()=="Quantity"){

						std::cerr <<"value is not a cycle value" << std::endl;




						dv=static_cast<DynamicValue*>((*it2).first);

						//for (int i=0; i<static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size(); ++i)
						//{

						//x[counter] = 0; // x goes from -1 to 1
						//y[counter] = static_cast<DynamicValue*>((*it2).first)->get_value().toInt();
						//counter++;

						std::cerr << "dynamic value value : " << static_cast<DynamicValue*>((*it2).first)->get_value().toStdString() << std::endl;
						std::cerr << "timepoint : "           << translate_second_in_DD_HH_MM_SS(get_seconds_from_date(current_doc->get_startdate(), static_cast<DynamicValue*>((*it2).first)->get_timepoint())).toStdString() << std::endl;
						std::cerr << "value y : "             << static_cast<DynamicValue*>((*it2).first)->get_value().toInt() << std::endl;
						std::cerr << "value x : "             << translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(), static_cast<DynamicValue*>((*it2).first)->get_timepoint())) << std::endl;

						for (int i=0;i<24;i++){
							std::cerr << "counter :" << counter <<  std::endl;
							x[counter] = translate_second_in_distance(get_seconds_from_date(current_doc->get_startdate(), static_cast<DynamicValue*>((*it2).first)->get_timepoint()));
							y[counter] = static_cast<DynamicValue*>((*it2).first)->get_value().toInt();
							lastposX=x[counter];
							lastPosY=y[counter];
							counter++;
							std::cerr << "counter :" << counter <<  std::endl;
						}
						last_is_cycle=false;


						//}
						// create graph and assign data to it:

					}
				}
			}
			std::cerr << "unit : " << unit.toStdString() << std::endl;
			std::cerr << "counter " << counter << std::endl;
			std::cerr << "lastPosX : " << lastposX << std::endl;
			std::cerr << "lastPosY : " << lastPosY << std::endl;
			if (lastposX!=x_length){
				while(counter!=x_length){
					if(last_is_cycle){

						std::cerr << "last value was a cycle value" << std::endl;

							for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it3=c->get_cycleValues()->begin();it3!=c->get_cycleValues()->end();++it3){


								int value=static_cast<DynamicValue*>((*it3).first)->get_value().toInt();
								for (int j=0;j<24/c->get_cycleValues()->size();j++){
									x[counter] = lastposX+1;
									y[counter] = value;
									counter++;
								}
							}
					}
					else{
						std::cerr << "last value wasn't a cycle value" << std::endl;
						for (int i = lastposX;i<=x_length;i+=24){
							std::cerr << "i : " << i << std::endl;
							std::cerr << "counter : " << counter << std::endl;
							x[counter] = i;
							y[counter] = lastPosY;
							counter++;
						}
					}
				}
			}

			*/
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
			plot->xAxis->setTickLength(1);
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
