#include "tableview.h"


TableView::TableView(ItfDocument * _xemlDoc,QTableView *parent)
	:QTableView(parent)
{
	this->xemlDoc=_xemlDoc;


	this->setStyleSheet("QTableView QTableCornerButton::section {background: black;border: 2px outset black;}");
	modelTable = new QStandardItemModel(1,10,this); //1 Rows and 10 Columns
	modelTable->setHorizontalHeaderItem(0, new QStandardItem(QString("Experiment")));
	modelTable->setHorizontalHeaderItem(1, new QStandardItem(QString("SampleId")));
	modelTable->setHorizontalHeaderItem(2, new QStandardItem(QString("Time")));
	modelTable->setHorizontalHeaderItem(3, new QStandardItem(QString("Real Time")));
	modelTable->setHorizontalHeaderItem(4, new QStandardItem(QString("StoryLabel")));
	modelTable->setHorizontalHeaderItem(5, new QStandardItem(QString("Germplasm")));
	modelTable->setHorizontalHeaderItem(6, new QStandardItem(QString("Developmental Stage")));
	modelTable->setHorizontalHeaderItem(7, new QStandardItem(QString("Material")));
	modelTable->setHorizontalHeaderItem(8, new QStandardItem(QString("Individual count")));
	modelTable->setHorizontalHeaderItem(9, new QStandardItem(QString("Individual Id")));

	//model->horizontalHeaderItem(4)
	//this->horizontalHeader()->setSectionResizeMode (QHeaderView::Stretch);
	//this->resizeColumnT-oContents(4);
	//this->view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	this->horizontalHeader()->setStyleSheet("QHeaderView::section {"
												  "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #616161, stop: 0.5 #505050,stop: 0.6 #434343, stop:1 #656565);"
												  "color: white;"
												  "padding-left: 4px;"
												  "border: 1px solid #6c6c6c;"
												  "}");





	//connect(view,SIGNAL(objectNameChanged(QString)),this,SLOT(germplasm_set_label(QString)));

	this->setModel(modelTable);

	/*
	QSortFilterProxyModel proxyModel;
	proxyModel.setSourceModel( modelTable );
	this->setModel( &proxyModel );
	*/

	populate_table();
	modelTable->sort(1,Qt::AscendingOrder);


	//this->sortByColumn(1,Qt::AscendingOrder);
	std::cerr << "end of populate table" << std::endl;





}
void TableView::init(){

}

void  TableView::sample_item_checked(QStandardItem * _item){
	std::cerr << "item :" <<_item->text().toStdString() <<  "state change" << std::endl;
	if (_item->isCheckable()){
		std::cerr << "item is checkable"<< std::endl;
		if(_item->text()=="Sample"){
			//_item->child(0)->isCheckable()
			//for ()
			if(_item->checkState()==Qt::Checked){
				//cocher tous les individus
				if(_item->hasChildren()){
					//for (_item->child())
					for (int i =0;i<_item->rowCount();i++){
						_item->child(i)->setCheckState(Qt::Checked);
					}
				}
			}
			else{
				if(_item->hasChildren()){
					//for (_item->child())
					for (int i =0;i<_item->rowCount();i++){
						_item->child(i)->setCheckState(Qt::Unchecked);
						/*
						if(_item->child(i)->hasChildren()){
							for (int j =0;j<_item->child(i)->rowCount();j++){
								_item->child(i)->child(j)->setCheckState(Qt::Unchecked);

							}
						}
						*/
					}
				}

			}

		}
		else if(_item->text()=="Experiment"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(0);
			}
			else{
				this->hideColumn(0);
			}
		}
		else if(_item->text()=="SampleId"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(1);
			}
			else{
				this->hideColumn(1);
			}
		}
		else if(_item->text()=="Time"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(2);
			}
			else{
				this->hideColumn(2);
			}
		}
		else if(_item->text()=="Real Time"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(3);
			}
			else{
				this->hideColumn(3);
			}
		}
		else if(_item->text()=="StoryLabel"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(4);
			}
			else{
				this->hideColumn(4);
			}
		}
		else if(_item->text()=="Germplasm"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(5);
			}
			else{
				this->hideColumn(5);
			}
		}
		else if(_item->text()=="Developmental Stage"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(6);
			}
			else{
				this->hideColumn(6);
			}
		}
		else if(_item->text()=="Material"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(7);
			}
			else{
				this->hideColumn(7);
			}
		}
		else if(_item->text()=="Individual count"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(8);
			}
			else{
				this->hideColumn(8);
			}
		}
		else if(_item->text()=="Individual Id"){
			if(_item->checkState()==Qt::Checked){
				this->showColumn(9);
			}
			else{
				this->hideColumn(9);
			}
		}
		else{
			if(_item->checkState()==Qt::Checked){

			}
			else{

			}

		}
	}
	else{

	}


}
void  TableView::variable_item_checked(QStandardItem * _selected_item){

	std::cerr << "item :" <<_selected_item->text().toStdString() <<  "state change" << std::endl;
	if(_selected_item->parent()!=NULL){
		std::cerr << "item parent label :" << _selected_item->parent()->text().toStdString() << std::endl;
		if(_selected_item->parent()->parent()!=NULL){
			std::cerr << "item parent label :" << _selected_item->parent()->parent()->text().toStdString() << std::endl;
		}
	}
	/*
	int column=0;
	for (int i=0;i<modelTable->columnCount();i++){
		if(modelTable->horizontalHeaderItem(i)->text()==header){
			column=i;
		}
	}
	*/
}
void  TableView::event_item_checked(QStandardItem * _selected_item){
	std::cerr << "item :" <<_selected_item->text().toStdString() <<  "state change" << std::endl;
}
/*
void add_variable_columns(QStandardItemModel * _variableModel){

}
*/
void TableView::write_variable_value(StoryNode * _node,ItfDocument * _xemlDoc,int _sample_counter,int _counter_term,QString _header,int _column){

	std::cerr << "entering write_variable value for story :" << _node->get_story()->get_label().toStdString() << std::endl;


	bool found=false;
	//for (std::list<StoryNode*>::iterator it =_xemlDoc->get_storyboard()->get_storyBoard()->begin();it!=_xemlDoc->get_storyboard()->get_storyBoard()->end();++it){
	//	StoryNode *_node=static_cast<StoryNode*>((*it));
	for(std::vector<std::pair<BasicTerm*,QString> >::iterator it9=_node->get_story()->get_variablesCollection()->begin();it9!=_node->get_story()->get_variablesCollection()->end();++it9){
		DynamicTerm * term=static_cast<DynamicTerm*>((*it9).first);
		QDateTime current_datetime;
		QDateTime previous_datetime;
		for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it10=term->get_dynamicvaluecollection()->begin();it10!=term->get_dynamicvaluecollection()->end();++it10){

			QString unit="";
			QString context="";
			QString label="";
			ValueBase* value=static_cast<ValueBase*>((*it10).first);
			if (it10==term->get_dynamicvaluecollection()->begin()){
				current_datetime=(*it10).second;


			}
			else{
				previous_datetime=current_datetime;
				current_datetime=(*it10).second;

			}
			if(previous_datetime!=current_datetime){

			}
			qint64 milliseconds_ellapsed=get_seconds_from_date(this->xemlDoc->get_startdate(),(*it10).second);
			QString time=translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed);

			if(!value->get_is_cycle()){

				DynamicValue * v = static_cast<DynamicValue*>(value);
				if(v->get_context()!=""){
					std::cerr << "context :"<< v->get_context().toStdString() << std::endl;
					context=v->get_context();
				}
				if(v->get_unit()!=""){
					unit=v->get_unit();
					//val.setAttribute("Unit",v->get_unit());
				}
				if(v->get_label()!=""){
					label=v->get_label();
					//val.setAttribute("Label",v->get_label());
				}
				if(v->get_is_cyclevalue()){

				}


				QString header;
				if (unit!=""){
					header="Name:-"+term->get_name()+"-("+unit+")\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
				}
				else{
					header="Name:-"+term->get_name()+"-\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
				}
				//if(_counter_term==0){
				std::cerr << " header in this story : "<< header.toStdString() << std::endl;
				if(header==_header){
					std::cerr << "header found :" << header.toStdString() << std::endl;
					QStandardItem * value_term_context_item=new QStandardItem(v->get_value());
					modelTable->setItem(_sample_counter,_column,value_term_context_item);
					found=true;
				}
			}
			else if(value->get_is_cycle()){
				//std::cerr << "entering cycle values" << std::endl;
				//val=this->doc.createElement("xeml:Cycle");
				Cycle * c = static_cast<Cycle*>(value);

				if(c->get_context()!=""){
					context=c->get_context();
				}
				if(c->get_unit()!=""){
					unit=c->get_unit();
					//val.setAttribute("Unit",c->get_unit());
				}
				if(c->get_label()!=""){
					label=c->get_label();
					//val.setAttribute("Label",c->get_label());
				}
				QString header;
				if (unit!=""){
					header="Name:-"+term->get_name()+"-("+unit+")\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
				}
				else{
					header="Name:-"+term->get_name()+"-\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
				}
				//if(_counter_term==0){
				std::cerr << " header in this story : "<< header.toStdString() << std::endl;

				if(header==_header){
					QString value_text;
					for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it=c->get_cycleValues()->begin();it!=c->get_cycleValues()->end();++it){
						//write_values(&val,static_cast<ValueBase*>((*it).first));
						ValueBase* valuecycle=static_cast<ValueBase*>((*it).first);
						std::cerr << "new cycle value" << std::endl;
						if(!valuecycle->get_is_cycle()){
							std::cerr << " cycle value is not a cycle" << std::endl;

							DynamicValue * v = static_cast<DynamicValue*>(valuecycle);
							if(v->get_is_cyclevalue()){
								std::cerr << " cycle value is a cycle value" << std::endl;

								//val.setAttribute("Duration",v->get_timepoint().toString("hh:mm:ss"));
								std::cerr << "cycle value :" << v->get_value().toStdString() <<  std::endl;
								value_text.append(v->get_value());
								value_text.append("/");
							}


						}

					}
					std::cerr << "header for cycle found :" << header.toStdString() << std::endl;
					QStandardItem * value_term_context_item=new QStandardItem(value_text);
					modelTable->setItem(_sample_counter,_column,value_term_context_item);
					found=true;
				}




			}
		}
		_counter_term++;
	}

	//std::cerr << "entering write_variable header" << std::endl;
	//std::cerr << "term name :" << _term->get_name().toStdString() << std::endl;

	//std::cerr << "time :" << time.toStdString() << std::endl;



	//decomposer le header
	std::cerr << "header before split :" << _header.toStdString() << std::endl;
	QStringList header_decompose=_header.split("-");
	QString termname=header_decompose.at(1);
	QString contextname=header_decompose.at(3);
	QString timename=header_decompose.at(5);
	if(!found){
		if(_sample_counter==0){


			//search the term in this story with the same name and the same context and put this value
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it9=_node->get_story()->get_variablesCollection()->begin();it9!=_node->get_story()->get_variablesCollection()->end();++it9){
				DynamicTerm * term=static_cast<DynamicTerm*>((*it9).first);
				QDateTime current_datetime;
				QDateTime previous_datetime;
				for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it10=term->get_dynamicvaluecollection()->begin();it10!=term->get_dynamicvaluecollection()->end();++it10){

					QString unit="";
					QString context="";
					QString label="";
					ValueBase* value=static_cast<ValueBase*>((*it10).first);
					if (it10==term->get_dynamicvaluecollection()->begin()){
						current_datetime=(*it10).second;


					}
					else{
						previous_datetime=current_datetime;
						current_datetime=(*it10).second;

					}
					if(previous_datetime!=current_datetime){

					}
					qint64 milliseconds_ellapsed=get_seconds_from_date(this->xemlDoc->get_startdate(),(*it10).second);
					QString time=translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed);

					if(!value->get_is_cycle()){

						DynamicValue * v = static_cast<DynamicValue*>(value);
						if(v->get_context()!=""){
							std::cerr << "context :"<< v->get_context().toStdString() << std::endl;
							context=v->get_context();
						}
						if(v->get_unit()!=""){
							unit=v->get_unit();
							//val.setAttribute("Unit",v->get_unit());
						}
						if(v->get_label()!=""){
							label=v->get_label();
							//val.setAttribute("Label",v->get_label());
						}
						if(v->get_is_cyclevalue()){
						}


						QString header;
						if (unit!=""){
							header="Name:-"+term->get_name()+"-("+unit+")\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
						}
						else{
							header="Name:-"+term->get_name()+"-\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
						}
						//if(_counter_term==0){
						std::cerr << " header in this story : "<< header.toStdString() << std::endl;
						if(termname==term->get_name() && contextname==context){
							std::cerr << "header found with different timpoint:" << header.toStdString() << std::endl;
							QStandardItem * value_term_context_item=new QStandardItem(v->get_value());
							modelTable->setItem(_sample_counter,_column,value_term_context_item);
							found=true;
						}
					}
					else if(value->get_is_cycle()){
						//std::cerr << "entering cycle values" << std::endl;
						//val=this->doc.createElement("xeml:Cycle");
						Cycle * c = static_cast<Cycle*>(value);

						if(c->get_context()!=""){
							context=c->get_context();
						}
						if(c->get_unit()!=""){
							unit=c->get_unit();
							//val.setAttribute("Unit",c->get_unit());
						}
						if(c->get_label()!=""){
							label=c->get_label();
							//val.setAttribute("Label",c->get_label());
						}
						QString header;
						if (unit!=""){
							header="Name:-"+term->get_name()+"-("+unit+")\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
						}
						else{
							header="Name:-"+term->get_name()+"-\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
						}
						//if(_counter_term==0){
						std::cerr << " header in this story : "<< header.toStdString() << std::endl;

						if(termname==term->get_name() && contextname==context){

							QString value_text;

							for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it=c->get_cycleValues()->begin();it!=c->get_cycleValues()->end();++it){
								//write_values(&val,static_cast<ValueBase*>((*it).first));
								ValueBase* valuecycle=static_cast<ValueBase*>((*it).first);
								std::cerr << "new cycle value" << std::endl;
								if(!valuecycle->get_is_cycle()){
									std::cerr << " cycle value is not a cycle" << std::endl;

									DynamicValue * v = static_cast<DynamicValue*>(valuecycle);
									if(v->get_is_cyclevalue()){
										std::cerr << " cycle value is a cycle value" << std::endl;

										//val.setAttribute("Duration",v->get_timepoint().toString("hh:mm:ss"));
										std::cerr << "cycle value :" << v->get_value().toStdString() <<  std::endl;
										value_text.append(v->get_value());
										value_text.append("/");
									}


								}

							}
							std::cerr << "header for cycle found :" << header.toStdString() << std::endl;
							QStandardItem * value_term_context_item=new QStandardItem(value_text);
							modelTable->setItem(_sample_counter,_column,value_term_context_item);
							found=true;
						}
						for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it=c->get_cycleValues()->begin();it!=c->get_cycleValues()->end();++it){
							//write_values(&val,static_cast<ValueBase*>((*it).first));
						}
						//_elem->appendChild(val);

					}
				}
				_counter_term++;
			}





			/*
			for(int k=_column-1;k>=0;k--){
				if(modelTable->horizontalHeaderItem(k)->text().contains(termname) && modelTable->horizontalHeaderItem(k)->text().contains(contextname)){
					QStandardItem * value_term_context_item=new QStandardItem(modelTable->item(k,_sample_counter)->text());
					modelTable->setItem(_sample_counter,_column,value_term_context_item);
					found=true;
				}
			}
			*/
			if(!found){
				QStandardItem * value_term_context_item=new QStandardItem("NA");
				modelTable->setItem(_sample_counter,_column,value_term_context_item);
			}


		}
		else{


			QStandardItem * value_term_context_item=new QStandardItem(modelTable->item(_sample_counter-1,_column)->text());
			modelTable->setItem(_sample_counter,_column,value_term_context_item);

		}
	}



}
void TableView::write_variable_context(DynamicTerm * _term,ValueBase* _vb,qint64 _milliseconds_ellapsed, int _sample_counter,int _counter_term){
	std::cerr << "entering write_variable header with story_counter = " << _counter_term << std::endl;
	std::cerr << "term name :" << _term->get_name().toStdString() << std::endl;

	QString time=translate_second_in_DD_HH_MM_SS(_milliseconds_ellapsed);
	std::cerr << "time :" << time.toStdString() << std::endl;
	QString unit="";
	QString context="";
	QString label="";
	//QStandardItem * context_item;
	if(!_vb->get_is_cycle()){

		DynamicValue * v = static_cast<DynamicValue*>(_vb);
		if(v->get_context()!=""){


			std::cerr << "context :"<< v->get_context().toStdString() << std::endl;
			context=v->get_context();
			//bool found=false;
			//if(_term_item->hasChildren()){
				//for (int i =0;i<_term_item->rowCount();i++){
					//if(_term_item->child(i)->text()==v->get_context()){
						//QStandardItem * context_item=_term_item->child(i);
						//QStandardItem * time_item=new QStandardItem(time);
						//time_item->setCheckable(true);
						//time_item->setCheckState(Qt::Checked);
						//_term_item->child(i)->appendRow(time_item);
						//found=true;
					//}


				//}


			//}
			//if(!found){
				//context_item=new QStandardItem(v->get_context());
				//context_item->setCheckable(true);
				//context_item->setCheckState(Qt::Checked);
				//_term_item->appendRow(context_item);
				//QStandardItem * time_item=new QStandardItem(time);
				//time_item->setCheckable(true);
				//time_item->setCheckState(Qt::Checked);
				//context_item->appendRow(time_item);

			//}
			//val.setAttribute("Context",v->get_context());





		}
		if(v->get_unit()!=""){
			unit=v->get_unit();
			//val.setAttribute("Unit",v->get_unit());
		}
		if(v->get_label()!=""){
			label=v->get_label();
			//val.setAttribute("Label",v->get_label());
		}
		if(v->get_is_cyclevalue()){
			//tester si cette value fait partie d'un cycle
			//et à ce moment là vérifier si le term est déja ajouté dans la table.




			//std::cerr << "Duration : " << v->get_timepoint().toString("hh:mm:ss").toStdString() << std::endl;
			//val.setAttribute("Duration",v->get_timepoint().toString("hh:mm:ss"));
		}
		QString header;
		if (unit!=""){
			header="Name:-"+_term->get_name()+"-("+unit+")\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
		}
		else{
			header="Name:-"+_term->get_name()+"-\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
		}
		if(_counter_term==0){
			std::cerr << "new header has been added : " << header.toStdString() << std::endl;


			QStandardItem * header_term_context_item=new QStandardItem(header);

			modelTable->setHorizontalHeaderItem(modelTable->columnCount(), header_term_context_item);
		}
		std::cerr << "header : " <<header.toStdString() << std::endl;
		std::cerr << "sample counter : " << _sample_counter << std::endl;
		std::cerr << "value :" << v->get_value().toStdString() << std::endl;

		/*
		QStandardItem * value_term_context_item=new QStandardItem(v->get_value());
		int column=0;
		for (int i=0;i<modelTable->columnCount();i++){
			if(modelTable->horizontalHeaderItem(i)->text()==header){
				column=i;
			}
		}
		//column=modelTable->h->findItems(header,Qt::MatchFixedString | Qt::MatchRecursive).at(0)->column();
		std::cerr << "column number :" << column << std::endl;
		modelTable->setItem(_sample_counter,column,value_term_context_item);
		*/

		//QDomText t = this->doc.createTextNode(v->get_value());
		//val.appendChild(t);
		//_elem->appendChild(val);



	}
	else if(_vb->get_is_cycle()){
		//std::cerr << "entering cycle values" << std::endl;
		//val=this->doc.createElement("xeml:Cycle");
		Cycle * c = static_cast<Cycle*>(_vb);

		if(c->get_context()!=""){


			std::cerr << "context :"<< c->get_context().toStdString() << std::endl;
			context=c->get_context();
			//bool found=false;
			//if(_term_item->hasChildren()){
				//for (int i =0;i<_term_item->rowCount();i++){
					//if(_term_item->child(i)->text()==v->get_context()){
						//QStandardItem * context_item=_term_item->child(i);
						//QStandardItem * time_item=new QStandardItem(time);
						//time_item->setCheckable(true);
						//time_item->setCheckState(Qt::Checked);
						//_term_item->child(i)->appendRow(time_item);
						//found=true;
					//}


				//}


			//}
			//if(!found){
				//context_item=new QStandardItem(v->get_context());
				//context_item->setCheckable(true);
				//context_item->setCheckState(Qt::Checked);
				//_term_item->appendRow(context_item);
				//QStandardItem * time_item=new QStandardItem(time);
				//time_item->setCheckable(true);
				//time_item->setCheckState(Qt::Checked);
				//context_item->appendRow(time_item);

			//}
			//val.setAttribute("Context",v->get_context());





		}
		if(c->get_unit()!=""){
			unit=c->get_unit();
			//val.setAttribute("Unit",v->get_unit());
		}
		if(c->get_label()!=""){
			label=c->get_label();
			//val.setAttribute("Label",v->get_label());
		}
		for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it=c->get_cycleValues()->begin();it!=c->get_cycleValues()->end();++it){
			//write_values(&val,static_cast<ValueBase*>((*it).first));
		}
		QString header;
		if (unit!=""){
			header="Name:-"+_term->get_name()+"-("+unit+")\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
		}
		else{
			header="Name:-"+_term->get_name()+"-\n"+ "Context:-"+context+"-\nTimepoint:-"+time;
		}
		if(_counter_term==0){
			std::cerr << "new header has been added : " << header.toStdString() << std::endl;


			QStandardItem * header_cycle_context_item=new QStandardItem(header);

			modelTable->setHorizontalHeaderItem(modelTable->columnCount(), header_cycle_context_item);
		}
		std::cerr << "header : " <<header.toStdString() << std::endl;
		std::cerr << "sample counter : " << _sample_counter << std::endl;
		//std::cerr << "value :" << c->get_value().toStdString() << std::endl;



		//_elem->appendChild(val);

	}
}
void  TableView::populate_table(){

	int cpt =0;
	int story_counter;
	for (std::list<StoryNode*>::iterator it =this->xemlDoc->get_storyboard()->get_storyBoard()->begin();it!=this->xemlDoc->get_storyboard()->get_storyBoard()->end();++it){
		StoryNode *node=static_cast<StoryNode*>((*it));

		story_counter=0;
		for(std::vector<std::pair<Sample*,int> >::iterator it2=node->get_story()->get_samplesCollection()->begin();it2!=node->get_story()->get_samplesCollection()->end();++it2){
			std::cerr << "new sample number :" << cpt << std::endl;
			Sample * s=static_cast<Sample*>((*it2).first);

			//s->get_partitions()
			QList<int> id_parts;
			int individual_count=0;
			for (std::vector<Partition*>::iterator it3 =s->get_partitions()->begin();it3!=s->get_partitions()->end();++it3){
				individual_count++;
				Partition * tmp_part=static_cast<Partition*>((*it3));
				id_parts.append(tmp_part->get_id());
				for(std::map<BasicTerm*,QString>::iterator it4=static_cast<Partition*>((*it3))->get_materialCollection()->begin();it4!=static_cast<Partition*>((*it3))->get_materialCollection()->end();++it4){
					QString name=static_cast<VariableTerm*>((*it4).first)->get_name();
					modelTable->setItem(cpt,7,new QStandardItem(name));

				}

			}
			modelTable->setItem(cpt,8,new QStandardItem(QString::number(individual_count)));

			//modelTable->setItem(cpt,7,new QStandardItem(s->get_partitions()));

			modelTable->setItem(cpt,1,new QStandardItem(QString::number(s->get_id())));
			modelTable->setItem(cpt,0,new QStandardItem(xemlDoc->get_experiment_name()));
			modelTable->setItem(cpt,4,new QStandardItem(node->get_story()->get_label()));
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it5=node->get_story()->get_obsPointCollection()->begin();it5!=node->get_story()->get_obsPointCollection()->end();++it5){
				ObservationPoint * op=static_cast<ObservationPoint*>((*it5).first);
				qint64 milliseconds_ellapsed=get_seconds_from_date(xemlDoc->get_startdate(),op->get_timepoint());

				modelTable->setItem(cpt,2,new QStandardItem(translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed)));
				modelTable->setItem(cpt,3,new QStandardItem(xemlDoc->get_startdate().toString("yyyy-MM-dd hh:mm:ss")));


				QString tmp_pool="";
				QString ind_ids="";
				for(std::vector<pair<Observation*,QDateTime> >::iterator it6=op->get_observationscollection()->begin();it6!=op->get_observationscollection()->end();++it6){
					Observation *  o=static_cast<Observation*>((*it6).first);
					for(std::map<BasicTerm*,QString>::iterator it7=o->get_stageCollection()->begin();it7!=o->get_stageCollection()->end();++it7){
						modelTable->setItem(cpt,6,new QStandardItem(static_cast<VariableTerm*>((*it7).first)->get_name()));

					}


					for(std::map<Partition*,int>::iterator it8=o->get_partitionCollection()->begin();it8!=o->get_partitionCollection()->end();++it8){
						for (int i =0;i<id_parts.count();i++){
							if (static_cast<Partition*>((*it8).first)->get_id()==id_parts.at(i)){
								tmp_pool=o->get_pool()->get_germplasm();
								//std::cerr << "ind id  : " << o->get_ind()->get_id() << std::endl;
								if(i==(id_parts.count()-1)){
									ind_ids+=QString::number(o->get_ind()->get_id());

								}
								else{
									ind_ids+=QString::number(o->get_ind()->get_id())+"-";

								}

							}
						}
					}
					modelTable->setItem(cpt,5,new QStandardItem(tmp_pool));
					modelTable->setItem(cpt,9,new QStandardItem(ind_ids));







					//if (o->get_partitionCollection()){

					//}
				}

			}
			int counter_term=0;
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it9=node->get_story()->get_variablesCollection()->begin();it9!=node->get_story()->get_variablesCollection()->end();++it9){
				DynamicTerm * term=static_cast<DynamicTerm*>((*it9).first);
				//QStandardItem * term_item=new QStandardItem(term->get_name());
				//term_item->setCheckable(true);
				//term_item->setCheckState(Qt::Checked);
				//variable_item->appendRow(term_item);

				QDateTime current_datetime;
				QDateTime previous_datetime;
				std::cerr << "new term" << std::endl;
				for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it10=term->get_dynamicvaluecollection()->begin();it10!=term->get_dynamicvaluecollection()->end();++it10){

					//std::cerr << "datetime in write param : " << static_cast<QDateTime>((*it2).second).toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;

					if (it10==term->get_dynamicvaluecollection()->begin()){
						current_datetime=(*it10).second;


					}
					else{
						previous_datetime=current_datetime;
						current_datetime=(*it10).second;

					}


					if(previous_datetime!=current_datetime){
						//qint64 milliseconds_ellapsed=get_seconds_from_date(this->xemlDoc->get_startdate(),(*it10).second);
						//write_variable_context(term,static_cast<ValueBase*>((*it10).first),milliseconds_ellapsed,cpt,story_counter);
						//Vs=this->doc.createElement("xeml:ValueSet");
					}
					qint64 milliseconds_ellapsed=get_seconds_from_date(this->xemlDoc->get_startdate(),(*it10).second);

					write_variable_context(term,static_cast<ValueBase*>((*it10).first),milliseconds_ellapsed,cpt,story_counter);
					std::cerr << "out of write variable context" << std::endl;
					//qint64 milliseconds_ellapsed=get_seconds_from_date(this->xemlDoc->get_startdate(),(*it10).second);
					//write_variable_context(term,static_cast<ValueBase*>((*it10).first),milliseconds_ellapsed,cpt);

					//Vs.setAttribute("TimePoint",translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed));
					//var.appendChild(Vs);


				}
				counter_term++;




			}
			story_counter++;

			cpt++;


		}






		/*
		for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it2=node->get_story()->get_obsPointCollection()->begin();it2!=node->get_story()->get_obsPointCollection()->end();++it2){
			ObservationPoint * op=static_cast<ObservationPoint*>((*it2).first);

			for(std::vector<pair<Observation*,QDateTime> >::iterator it3=op->get_observationscollection()->begin();it3!=op->get_observationscollection()->end();++it3){

				modelTable->setItem(cpt,0,new QStandardItem(xemlDoc->get_experiment_name()));
				modelTable->setItem(cpt,4,new QStandardItem(node->get_story()->get_label()));

				Observation *  o=static_cast<Observation*>((*it3).first);

				//modelTable->setItem(cpt,1,new QStandardItem(QString::number(o->get_id())));

				for(std::map<Partition*,int>::iterator it4=o->get_partitionCollection()->begin();it4!=o->get_partitionCollection()->end();++it4){
					Partition * p=static_cast<Partition*>((*it4).first);

					for(std::map<BasicTerm*,QString>::iterator it5=p->get_materialCollection()->begin();it5!=p->get_materialCollection()->end();++it5){
						//(*it4).first->get_namespacealias();
						//(*it4).first->get_termId();
						//(*it4).first->get_name();



					}
					for(std::map<BasicTerm*,QString>::iterator it6=p->get_positionCollection()->begin();it6!=p->get_positionCollection()->end();++it6){
						//(*it5).first->get_namespacealias());
						//(*it5).first->get_termId());
						//(*it5).first->get_name());

						for(std::map<ValueBase*,QString>::iterator it7=static_cast<VariableTerm*>((*it6).first)->get_valuecollection()->begin();it7!=static_cast<VariableTerm*>((*it6).first)->get_valuecollection()->end();++it7 ){

							//static_cast<Value*>((*it6).first)->get_context();
							if(static_cast<Value*>((*it7).first)->get_context()=="Quantity"){
								//static_cast<Value*>((*it6).first)->get_unit();
							}


						}


					}

				}
				cpt++;
			}



		}
		*/


	}
	std::cerr << "out of all stories" << std::endl;

	std::cerr << "all contexts are entered" << std::endl;

	story_counter=0;
	std::vector<Sample*> * tmp_sample=static_cast<std::vector<Sample*>*>(static_cast<XemlDocument*>(this->xemlDoc)->extract_samples());
	QString header;

	for (int i=10;i<modelTable->columnCount();i++){
		//if(modelTable->horizontalHeaderItem(i)->text().contains("Context")){
		//cpt=0;
		cpt =0;
		for (std::list<StoryNode*>::iterator it =xemlDoc->get_storyboard()->get_storyBoard()->begin();it!=xemlDoc->get_storyboard()->get_storyBoard()->end();++it){
			StoryNode *_node=static_cast<StoryNode*>((*it));

			for(std::vector<std::pair<Sample*,int> >::iterator it2=_node->get_story()->get_samplesCollection()->begin();it2!=_node->get_story()->get_samplesCollection()->end();++it2){
				Sample * s=static_cast<Sample*>((*it2).first);
				int counter_term=0;


				header=modelTable->horizontalHeaderItem(i)->text();
				//QStringList header_decompose=header.split("-");
				//QString termname=header_decompose.at(1);
				//QString contextname=header_decompose.at(3);
				//QString timename=header_decompose.at(5);
				//decompose header pour récupérer
				std::cerr << "column : " << i << " row :" << cpt << std::endl;
				write_variable_value(_node,this->xemlDoc,cpt,story_counter,header,i);

				story_counter++;

				cpt++;
			}
		}


	}

}
