#include "tableview.h"


TableView::TableView(ItfDocument * _xemlDoc,QTableView *parent)
	:QTableView(parent)
{
	this->xemlDoc=_xemlDoc;


	this->setStyleSheet("QTableView QTableCornerButton::section {background: black;border: 2px outset black;}");
	modelTable = new QStandardItemModel(1,10,this); //1 Rows and 7 Columns
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
	populate_table();





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
}
void  TableView::event_item_checked(QStandardItem * _selected_item){
	std::cerr << "item :" <<_selected_item->text().toStdString() <<  "state change" << std::endl;
}
void  TableView::populate_table(){

	int cpt =0;
	for (std::list<StoryNode*>::iterator it =this->xemlDoc->get_storyboard()->get_storyBoard()->begin();it!=this->xemlDoc->get_storyboard()->get_storyBoard()->end();++it){
		StoryNode *node=static_cast<StoryNode*>((*it));


		for(std::vector<std::pair<Sample*,int> >::iterator it2=node->get_story()->get_samplesCollection()->begin();it2!=node->get_story()->get_samplesCollection()->end();++it2){
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
								//ind_ids+=QString::number(o->get_ind()->get_id());

							}
						}
					}
					modelTable->setItem(cpt,5,new QStandardItem(tmp_pool));
					//modelTable->setItem(cpt,9,new QStandardItem(ind_ids));







					//if (o->get_partitionCollection()){

					//}
				}

			}

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
}
