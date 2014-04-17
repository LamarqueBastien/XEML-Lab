#include "eventpanel.h"

EventPanel::EventPanel(bool _RemoveMode,QWidget * parent)
	:QWidget(parent)
{
	view = new QTableView();
	this->view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	model = new QStandardItemModel(this); //2 Rows and 3 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("event name")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("timepoint")));
	view->setModel(model);
	QHBoxLayout * mainLayout= new QHBoxLayout;
	mainLayout->addWidget(view);
	if(_RemoveMode){
		this->removeButton=new QPushButton("Remove");
		this->cancelButton=new QPushButton("Cancel");
		mainLayout->addWidget(removeButton);
		mainLayout->addWidget(cancelButton);
		//connect(this->view,SIGNAL())
		connect(this->removeButton,SIGNAL(clicked()),this,SLOT(remove_event()));
		connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	}
	setLayout(mainLayout);
	setWindowTitle(tr("event informations"));

}
void EventPanel::initialize(ItfDocument * _doc,  StoryBase * _story,bool _isStorySplit){
	int cpt;
	this->current_story=_story;
	if(_isStorySplit){

		StorySplit * current=static_cast<StorySplit*>(_story);
		cpt=0;
		for(std::map<Event*,QDateTime>::iterator it = current->get_eventcollection()->begin();it!=current->get_eventcollection()->end();++it){
			model->setItem(cpt,0,new QStandardItem((*it).first->get_label()));
			model->setItem(cpt,1,new QStandardItem( QString((*it).first->get_timepoint().toString("dd.hh:mm:ss"))));
			cpt++;
		}
	}
	else{
		Story * current=static_cast<Story*>(_story);
		cpt=0;
		for(std::map<Event*,QDateTime>::iterator it = current->get_eventcollection()->begin();it!=current->get_eventcollection()->end();++it){

			model->setItem(cpt,0,new QStandardItem((*it).first->get_label()));
			model->setItem(cpt,1,new QStandardItem(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(_doc->get_startdate(),(*it).first->get_timepoint()))));
			cpt++;
		}
		for (int i= 0;i<model->rowCount();i++){
			for (int j=0;j<model->columnCount();j++){
				if (model->item(i,j)!=NULL){
					model->item(i,j)->setEditable(false);
				}
			}
		}
	}
}
void EventPanel::remove_event(){
	QItemSelectionModel  * selection = this->view->selectionModel();
	QModelIndex indexelementselected= selection->currentIndex();
	std::list<int> * tmplist =new std::list<int>();
	bool Erase=false;
	if(selection->isSelected(indexelementselected)){
		int row_num=this->model->itemFromIndex(indexelementselected)->row();
		std::map<Event*,QDateTime>::iterator it_to_erase;
		this->current_story->rm_event(this->model->index(row_num,0).data().toString());


	}
	this->close();
	emit on_close_window();
}



