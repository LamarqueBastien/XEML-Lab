#include "experimenttableview.h"

ExperimentTableView::ExperimentTableView(ItfDocument * _xemlDoc,QWidget *parent)
	:QWidget(parent)
{
	this->xemlDoc=_xemlDoc;
	init();





	QHBoxLayout * tablelayout = new QHBoxLayout;
	tablelayout->addWidget(this->experiment_view);

	QHBoxLayout * treelayout = new QHBoxLayout;
	treelayout->addWidget(this->sampleView);
	treelayout->addWidget(this->variableView);
	treelayout->addWidget(this->eventView);
	//mainlayout->addLayout(treelayout);

	QVBoxLayout * mainlayout = new QVBoxLayout;
	mainlayout->addLayout(treelayout);
	mainlayout->addLayout(tablelayout);

	setLayout(mainlayout);

	this->setWindowTitle(tr("Experiment informations"));



}
void ExperimentTableView::init(){

	this->experiment_view=new TableView(this->xemlDoc);
	this->sampleView=new QTreeView;

	sampleModel = new QStandardItemModel;
	connect(sampleModel,SIGNAL(itemChanged(QStandardItem*)),this->experiment_view,SLOT(sample_item_checked(QStandardItem*)));


	QStandardItem * sample_item=new QStandardItem("Sample");
	sample_item->setCheckable(true);
	sample_item->setCheckState(Qt::Checked);
	sampleModel->appendRow(sample_item);
	QStandardItem * experiment=new QStandardItem("Experiment");
	experiment->setCheckable(true);
	experiment->setCheckState(Qt::Checked);
	sample_item->appendRow(experiment);
	QStandardItem * sampleID=new QStandardItem("SampleId");
	sampleID->setCheckable(true);
	sampleID->setCheckState(Qt::Checked);
	sample_item->appendRow(sampleID);
	QStandardItem * time=new QStandardItem("Time");
	time->setCheckable(true);
	time->setCheckState(Qt::Checked);
	sample_item->appendRow(time);
	QStandardItem * real_time=new QStandardItem("Real Time");
	real_time->setCheckable(true);
	real_time->setCheckState(Qt::Checked);
	sample_item->appendRow(real_time);
	QStandardItem * story_label=new QStandardItem("Story Label");
	story_label->setCheckable(true);
	story_label->setCheckState(Qt::Checked);
	sample_item->appendRow(story_label);
	QStandardItem * germplasm=new QStandardItem("GermPlasm");
	germplasm->setCheckable(true);
	germplasm->setCheckState(Qt::Checked);
	sample_item->appendRow(germplasm);
	QStandardItem * dev_stage=new QStandardItem("Developmental stage");
	dev_stage->setCheckable(true);
	dev_stage->setCheckState(Qt::Checked);
	sample_item->appendRow(dev_stage);
	QStandardItem * material=new QStandardItem("Material");
	material->setCheckable(true);
	material->setCheckState(Qt::Checked);
	sample_item->appendRow(material);


	//connect(sampleModel,SIGNAL(itemChanged(QStandardItem*)),experiment_view,SLOT());


	this->sampleView->setModel(sampleModel);
	//this->sampleView->expandAll();



	init_variable_table();
	init_event_table();

}


void ExperimentTableView::init_variable_table(){
	this->variableView=new QTreeView;
	this->variableModel = new QStandardItemModel;
	QStandardItem * variable_item=new QStandardItem("Variable");
	variable_item->setCheckable(true);
	variable_item->setCheckState(Qt::Checked);
	variableModel->appendRow(variable_item);
	this->variableView->setModel(variableModel);
	connect(variableModel,SIGNAL(itemChanged(QStandardItem*)),this->experiment_view,SLOT(variable_item_checked(QStandardItem*)));

	// retrieve all variables used in the Xeml Doc.

}

void ExperimentTableView::init_event_table(){
	this->eventView=new QTreeView;
	this->eventModel = new QStandardItemModel;
	QStandardItem * event_item=new QStandardItem("Event");
	event_item->setCheckable(true);
	event_item->setCheckState(Qt::Checked);
	eventModel->appendRow(event_item);
	this->eventView->setModel(eventModel);
	connect(eventModel,SIGNAL(itemChanged(QStandardItem*)),this->experiment_view,SLOT(event_item_checked(QStandardItem*)));


}
