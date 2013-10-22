#include "observationpanel.h"

ObservationPanel::ObservationPanel(QWidget * parent)
:QWidget(parent)
{
	view = new QTableView();
	model = new QStandardItemModel(2,4,this); //2 Rows and 3 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("observation Id")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("duration")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("Obs Point Id")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QString("Target time")));
	view->resizeColumnsToContents();

	view->setModel(model);
	QHBoxLayout * mainLayout= new QHBoxLayout;
	mainLayout->addWidget(view);
	setLayout(mainLayout);
	setWindowTitle(tr("observation point informations"));

	connect(this->view,SIGNAL(clicked(QModelIndex)),this,SLOT(display_selected_item(QModelIndex)));
}
void ObservationPanel::initialize(StoryBase * _story,bool _isStorySplit){
	if(_isStorySplit){

		StorySplit * current=static_cast<StorySplit*>(_story);
		std::vector<ObservationPoint*> *listObspoint= new std::vector<ObservationPoint*>();
		std::vector<Observation*> *listobs= new std::vector<Observation*>();
		for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it = current->get_obsPointCollection()->begin();it!=current->get_obsPointCollection()->end();++it){
			listObspoint->push_back((*it).first);
			for(std::vector<pair<Observation*,QDateTime> >::iterator it2=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->begin();it2!=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->end();++it2){

				listobs->push_back((*it2).first);
			}
		}
		int cpt=0;
		for(size_t i=0;i<listObspoint->size();i++){
			int intnum=listObspoint->at(0)->count_observations();
			for(int j=cpt;j<intnum;j++){

				model->setItem(j,0,new QStandardItem(QString::number(listobs->at(j)->get_id())));
				model->setItem(j,1,new QStandardItem(listobs->at(j)->get_duration().toString("hh:mm:ss")));
				model->setItem(j,2,new QStandardItem(QString::number(listObspoint->at(i)->get_id())));
				model->setItem(j,3,new QStandardItem(listObspoint->at(i)->get_timepoint().toString("dd.hh:mm:ss")));
				cpt++;
			}
		}
	}
	else{
		Story * current=static_cast<Story*>(_story);

		std::vector<ObservationPoint*> *listObspoint= new std::vector<ObservationPoint*>();
		std::vector<Observation*> *listobs= new std::vector<Observation*>();
		for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it = current->get_obsPointCollection()->begin();it!=current->get_obsPointCollection()->end();++it){
			listObspoint->push_back((*it).first);
			for(std::vector<pair<Observation*,QDateTime> >::iterator it2=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->begin();it2!=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->end();++it2){
				listobs->push_back((*it2).first);
			}
		}
		int cpt=0;
		for(size_t i=0;i<listObspoint->size();i++){
			int intnum=listObspoint->at(0)->count_observations();
			for(int j=cpt;j<intnum;j++){

				model->setItem(j,0,new QStandardItem(QString::number(listobs->at(j)->get_id())));
				model->setItem(j,1,new QStandardItem(listobs->at(j)->get_duration().toString("hh:mm:ss")));
				model->setItem(j,2,new QStandardItem(QString::number(listObspoint->at(i)->get_id())));
				model->setItem(j,3,new QStandardItem(listObspoint->at(i)->get_timepoint().toString("dd.hh:mm:ss")));
				cpt++;
			}
		}
	}
}
void ObservationPanel::display_selected_item(QModelIndex _QMI){
	this->model->itemFromIndex(_QMI)->text();
	QMessageBox::information(this,"added element",this->model->itemFromIndex(_QMI)->text());

}

