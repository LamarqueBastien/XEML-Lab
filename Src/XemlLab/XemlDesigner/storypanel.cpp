#include "storypanel.h"

StoryPanel::StoryPanel(QWidget * parent)
	:QWidget(parent)
{

	model = new QStandardItemModel(2,6,this); //2 Rows and 3 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("Story Name")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("ind number")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("var number")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QString("event number")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QString("starting point")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QString("pool")));

	view = new QTableView();
	view->setModel(model);
	QHBoxLayout * mainLayout= new QHBoxLayout;
	mainLayout->addWidget(view);
	setLayout(mainLayout);
	setWindowTitle(tr("story informations"));
}
void StoryPanel::initialize(StoryBase * _story,bool _isStorySplit){
	model->setItem(0,0,new QStandardItem(_story->get_label()));
	std::vector<IndividualsPool*> *list;
	if(_isStorySplit){

		StorySplit * current=static_cast<StorySplit*>(_story);

		model->setItem(0,1,new QStandardItem("none"));
		model->setItem(0,2,new QStandardItem(QString::number(_story->count_variables())));
		model->setItem(0,3,new QStandardItem(QString::number(_story->count_event())));
		model->setItem(0,4,new QStandardItem(current->get_timepoint().toString("dd.hh:mm:ss")));
	}
	else{
		TimeSpan * startpoint=new TimeSpan(0,0,0,0);
		Story * current=static_cast<Story*>(_story);
		list= new std::vector<IndividualsPool*>();
		for(std::map<IndividualsPool*,QString>::iterator it = current->get_individualspoolcollection()->begin();it!=current->get_individualspoolcollection()->end();++it){
			list->push_back((*it).first);
		}

		int intnum;
		if(!list->empty()){
			intnum=list->at(0)->count_individuals();
		}
		else{
			intnum = 0;
		}

		model->setItem(0,1,new QStandardItem(QString::number(intnum)));
		model->setItem(0,2,new QStandardItem(QString::number(_story->count_variables())));
		model->setItem(0,3,new QStandardItem(QString::number(_story->count_event())));
		model->setItem(0,4,new QStandardItem(startpoint->get_timespan_Qstr_format()));
		model->setItem(0,5,new QStandardItem(QString::number(list->size())));

	}
}
