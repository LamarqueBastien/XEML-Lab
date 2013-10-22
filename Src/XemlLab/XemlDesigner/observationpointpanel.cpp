#include "observationpointpanel.h"

ObservationPointPanel::ObservationPointPanel(bool _RemoveMode,QWidget * parent)
:QWidget(parent)
{
	view = new QTableView();
	model = new QStandardItemModel(1,3,this); //2 Rows and 3 Columns
	//model->setHorizontalHeaderItem(0, new QStandardItem(QString("observation Id")));
	//model->setHorizontalHeaderItem(1, new QStandardItem(QString("duration")));
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("Obs Point Id")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("Target time")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("StoryLabel")));
	view->resizeColumnsToContents();

	view->setModel(model);
	QVBoxLayout * mainLayout= new QVBoxLayout;
	mainLayout->addWidget(view);
	if(_RemoveMode){
		this->removeButton=new QPushButton("Remove");
		this->cancelButton=new QPushButton("Cancel");
		mainLayout->addWidget(removeButton);
		mainLayout->addWidget(cancelButton);
		//connect(this->view,SIGNAL())
		connect(this->removeButton,SIGNAL(clicked()),this,SLOT(remove_obsPoint()));
		connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	}
	else{
		connect(this->view,SIGNAL(clicked(QModelIndex)),this,SLOT(display_selected_item(QModelIndex)));
	}
	setLayout(mainLayout);
	setWindowTitle(tr("observation point informations"));


}
void ObservationPointPanel::initialize(StoryNode * _storyNode,bool _isStorySplit,ItfDocument * _doc,DocumentResources * _doc_resources){
	this->storyNode=_storyNode;
	this->storyBoard=_doc->get_storyboard();
	this->doc=_doc;
	this->doc_resources=_doc_resources;
	if(_isStorySplit){

		StorySplit * current=static_cast<StorySplit*>(_storyNode->get_story());
		std::vector<ObservationPoint*> *listObspoint= new std::vector<ObservationPoint*>();
		//std::vector<Observation*> *listobs= new std::vector<Observation*>();
		for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it = current->get_obsPointCollection()->begin();it!=current->get_obsPointCollection()->end();++it){
			listObspoint->push_back((*it).first);
			//for(std::map<Observation*,TimeSpan*>::iterator it2=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->begin();it2!=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->end();++it2){

				//listobs->push_back((*it2).first);
			//}
		}
		//int cpt=0;
		for(size_t i=0;i<listObspoint->size();i++){
			//int intnum=listObspoint->at(0)->count_observations();
			//for(int j=cpt;j<intnum;j++){

				//model->setItem(j,0,new QStandardItem(QString::number(listobs->at(j)->get_id())));
				//model->setItem(j,1,new QStandardItem(listobs->at(j)->get_duration()->get_timespan_Qstr_format()));
				model->setItem(i,0,new QStandardItem(QString::number(listObspoint->at(i)->get_id())));
				QString timepoint=translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->doc->get_startdate(),listObspoint->at(i)->get_timepoint()));
				model->setItem(i,1,new QStandardItem(timepoint));

				//model->setItem(i,1,new QStandardItem(listObspoint->at(i)->get_timepoint().toString("dd.hh:mm:ss")));
				model->setItem(i,2,new QStandardItem(current->get_label()));

				//cpt++;
			//}
		}
	}
	else{
		Story * current=static_cast<Story*>(_storyNode->get_story());

		std::vector<ObservationPoint*> *listObspoint= new std::vector<ObservationPoint*>();
		//std::vector<Observation*> *listobs= new std::vector<Observation*>();
		for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it = current->get_obsPointCollection()->begin();it!=current->get_obsPointCollection()->end();++it){
			listObspoint->push_back((*it).first);
			//for(std::map<Observation*,TimeSpan*>::iterator it2=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->begin();it2!=static_cast<ObservationPoint*>((*it).first)->get_observationscollection()->end();++it2){
			//	listobs->push_back((*it2).first);
			//}
		}
		//int cpt=0;
		std::cerr << "list size  : " << current->get_obsPointCollection()->size() << std::endl;
		for(size_t i=0;i<listObspoint->size();i++){
			//int intnum=listObspoint->at(0)->count_observations();
			//for(int j=cpt;j<intnum;j++){

				//model->setItem(j,0,new QStandardItem(QString::number(listobs->at(j)->get_id())));
				//model->setItem(j,1,new QStandardItem(listobs->at(j)->get_duration()->get_timespan_Qstr_format()));
			model->setItem(i,0,new QStandardItem(QString::number(listObspoint->at(i)->get_id())));
			QString timepoint=translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->doc->get_startdate(),listObspoint->at(i)->get_timepoint()));
			model->setItem(i,1,new QStandardItem(timepoint));
			//model->setItem(i,1,new QStandardItem(listObspoint->at(i)->get_timepoint().toString("dd.hh:mm:ss")));
			model->setItem(i,2,new QStandardItem(current->get_label()));

			//cpt++;
			//}
		}
	}
}
StoryNode * ObservationPointPanel::get_root_story_node(StoryNode * _current){

	if (_current->get_parent()==NULL){
		return _current;
	}
	else{
		return get_root_story_node(_current->get_parent());
	}
}
void ObservationPointPanel::remove_obsPoint(){
	QItemSelectionModel  * selection = this->view->selectionModel();
	QModelIndex indexelementselected= selection->currentIndex();
	std::list<int> * tmplist =new std::list<int>();
	bool Erase=false;
	if(selection->isSelected(indexelementselected)){
		int row_num=this->model->itemFromIndex(indexelementselected)->row();
		//StoryNode * rootStory=get_root_story_node(this->storyNode);
		//ObservationPoint * current_OP = get_obsPoint_byId(this->model->index(row_num,0).data().toInt());
		std::map<IndividualsPool*,QString>::iterator it_to_erase;
		for(std::list<StoryNode*>::iterator it=this->doc->get_storyboard()->get_storyBoard()->begin();it!=this->doc->get_storyboard()->get_storyBoard()->end();++it){
			std::cerr <<"story label" <<  this->storyNode->get_label().toStdString()<< std::endl;
			std::cerr <<"story label" <<  static_cast<StoryNode*>((*it))->get_label().toStdString()<< std::endl;

			if(static_cast<StoryNode*>((*it))->get_label()==this->storyNode->get_label()){
				std::cerr << "before remove obspoint" << std::endl;
				tmplist=static_cast<StoryNode*>((*it))->get_story()->rm_obsPoint(this->model->index(row_num,0).data().toInt());
				std::cerr << "end of remove obspoint"<< std::endl;
			}
			std::cerr <<"story label : " <<  static_cast<StoryNode*>((*it))->get_label().toStdString()<< std::endl;

			if(!tmplist->empty()){
				for (std::map<IndividualsPool*,QString>::iterator it2 =static_cast<Story*>(static_cast<StoryNode*>((*it))->get_story())->get_individualspoolcollection()->begin();it2!=static_cast<Story*>(static_cast<StoryNode*>((*it))->get_story())->get_individualspoolcollection()->end();++it2){
					for(std::list<int>::iterator it3=tmplist->begin();it3!=tmplist->end();++it3){
						std::cerr << "before remove individuals" << std::endl;
						static_cast<IndividualsPool*>(it2->first)->remove_Individual((*it3));
						std::cerr << "end of remove individuals"<< std::endl;
					}

					if(static_cast<IndividualsPool*>(it2->first)->get_individualscollection()->empty()){
						std::cerr << "collection empty"<< std::endl;
						delete it2->first;
						it_to_erase=it2;
						Erase=true;

					}


				}
				if(Erase){
					static_cast<Story*>(static_cast<StoryNode*>((*it))->get_story())->get_individualspoolcollection()->erase(it_to_erase);

				}

			}
			std::cerr <<"story label : " <<  static_cast<StoryNode*>((*it))->get_label().toStdString()<< std::endl;





		}

	}

	this->close();
}


ObservationPoint * ObservationPointPanel::get_obsPoint_byId(int _id){
	for(std::list<StoryNode*>::iterator it =this->storyBoard->get_storyBoard()->begin();it!=this->storyBoard->get_storyBoard()->end();++it){
		if ((*it)->get_story()->get_obsPoint(_id)!=NULL){
			return (*it)->get_story()->get_obsPoint(_id);
		}

	}
	return NULL;
}

void ObservationPointPanel::display_selected_item(QModelIndex _QMI){
	int row_num=this->model->itemFromIndex(_QMI)->row();
	this->model->index(row_num,2).data();
	//int obsId=model->takeItem(row_num,0)->text().toInt();
	//QStandardItem * storyname=model->takeItem(row_num,2);
	StoryNode * rootStory=get_root_story_node(this->storyNode);
	ObservationPoint * current_OP = get_obsPoint_byId(this->model->index(row_num,0).data().toInt());
	//this->storyBoard->fi
	std::cerr << "ob id : " << current_OP->get_id() << std::endl;
	this->obsWizard =new ObservationWizard(rootStory,current_OP,this->doc_resources,this->doc,this);
	this->obsWizard->show();
	//std::cerr << "name : " << this->obsWizard->get_wizard()->field("LabelName").toString().toStdString() << std::endl;
			//std::cerr <<LabelName this->wizard->field("LabelName").toString().toStdString() << std::endl;

	//QMessageBox::information(this,"added element",this->model->index(row_num,2).data().toString());

}
