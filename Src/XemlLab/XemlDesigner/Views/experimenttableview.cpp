#include "experimenttableview.h"

ExperimentTableView::ExperimentTableView(ItfDocument * _xemlDoc,QWidget *parent)
	:QWidget(parent)
{
	this->xemlDoc=_xemlDoc;
	QSplashScreen *splash = new QSplashScreen;
#if defined(Q_OS_WIN)
	splash->setPixmap(QPixmap(":/Images/XemlLogo.png"));
#elif defined(Q_OS_MACX)
	//a.setStyle(QStyleFactory::create("Macintosh"));
	//QPixmap(":/Images/XemlLogo.png")
	//splash->setPixmap(QPixmap(":/Images/XemlLogo.png"));

	QPixmap image(":/Images/XemlLogo.png");
	splash->setMask(QRegion(image.mask()));
	splash->setPixmap(image);
#else

	splash->setPixmap(QPixmap(":/Images/XemlLogo.png"));
	//splash->setPixmap(QPixmap("/home/bdartigues/XEML-Lab/Src/XemlLab/XemlDesigner/Images/XemlLogo.png"));
#endif
	splash->show();
	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
	splash->showMessage(QObject::tr("initialize experiment table..."), topRight, Qt::black);

	init();
	splash->showMessage(QObject::tr("initialize experiment table..."), topRight, Qt::black);

	splash->finish(this);

	delete splash;





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
	this->setMinimumHeight(600);
	this->setMinimumWidth(1060);

	setLayout(mainlayout);

	this->setWindowTitle(tr("Experiment informations"));



}



void ExperimentTableView::init(){

	//put experiment view declaration at the end of the init function and pass treeviews as arguments
	this->experiment_view=new TableView(this->xemlDoc);
	this->sampleView=new QTreeView;
	sampleView->header()->hide();


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

	QStandardItem * story_label=new QStandardItem("StoryLabel");
	story_label->setCheckable(true);
	story_label->setCheckState(Qt::Checked);
	sample_item->appendRow(story_label);

	QStandardItem * germplasm=new QStandardItem("Germplasm");
	germplasm->setCheckable(true);
	germplasm->setCheckState(Qt::Checked);
	sample_item->appendRow(germplasm);

	QStandardItem * dev_stage=new QStandardItem("Developmental Stage");
	dev_stage->setCheckable(true);
	dev_stage->setCheckState(Qt::Checked);
	sample_item->appendRow(dev_stage);

	QStandardItem * material=new QStandardItem("Material");
	material->setCheckable(true);
	material->setCheckState(Qt::Checked);
	sample_item->appendRow(material);

	QStandardItem * individual_count=new QStandardItem("Individual count");
	individual_count->setCheckable(true);
	individual_count->setCheckState(Qt::Checked);
	sample_item->appendRow(individual_count);

	QStandardItem * individual_id=new QStandardItem("Individual Id");
	individual_id->setCheckable(true);
	individual_id->setCheckState(Qt::Checked);
	sample_item->appendRow(individual_id);


	//connect(sampleModel,SIGNAL(itemChanged(QStandardItem*)),experiment_view,SLOT());


	this->sampleView->setModel(sampleModel);
	this->sampleView->expandAll();
	//this->sampleView->expandAll();



	init_variable_tree();
	init_event_tree();

	//this->experiment_view->add_variable_columns(this->variableModel);

}

void ExperimentTableView::write_variable_context(QStandardItem * _term_item,ValueBase* _vb,qint64 _milliseconds_ellapsed){
	QString time=translate_second_in_DD_HH_MM_SS(_milliseconds_ellapsed);

	QStandardItem * context_item;
	if(!_vb->get_is_cycle()){

		DynamicValue * v = static_cast<DynamicValue*>(_vb);
		if(v->get_context()!=""){

			bool found=false;
			if(_term_item->hasChildren()){
				for (int i =0;i<_term_item->rowCount();i++){
					if(_term_item->child(i)->text()==v->get_context()){
						//QStandardItem * context_item=_term_item->child(i);
						QStandardItem * time_item=new QStandardItem(time);
						time_item->setCheckable(true);
						time_item->setCheckState(Qt::Checked);
						_term_item->child(i)->appendRow(time_item);
						found=true;
					}


				}


			}
			if(!found){
				context_item=new QStandardItem(v->get_context());
				context_item->setCheckable(true);
				context_item->setCheckState(Qt::Checked);
				_term_item->appendRow(context_item);
				QStandardItem * time_item=new QStandardItem(time);
				time_item->setCheckable(true);
				time_item->setCheckState(Qt::Checked);
				context_item->appendRow(time_item);

			}
			//val.setAttribute("Context",v->get_context());





		}
		if(v->get_unit()!=""){
			//val.setAttribute("Unit",v->get_unit());
		}
		if(v->get_label()!=""){
			//val.setAttribute("Label",v->get_label());
		}
		if(v->get_is_cyclevalue()){
			//std::cerr << "Duration : " << v->get_timepoint().toString("hh:mm:ss").toStdString() << std::endl;
			//val.setAttribute("Duration",v->get_timepoint().toString("hh:mm:ss"));
		}

		//QDomText t = this->doc.createTextNode(v->get_value());
		//val.appendChild(t);
		//_elem->appendChild(val);



	}
	else if(_vb->get_is_cycle()){
		//std::cerr << "entering cycle values" << std::endl;
		//val=this->doc.createElement("xeml:Cycle");
		Cycle * c = static_cast<Cycle*>(_vb);

		if(c->get_context()!=""){

			bool found=false;
			if(_term_item->hasChildren()){
				for (int i =0;i<_term_item->rowCount();i++){
					if(_term_item->child(i)->text()==c->get_context()){
						//QStandardItem * context_item=_term_item->child(i);
						QStandardItem * time_item=new QStandardItem(time);
						time_item->setCheckable(true);
						time_item->setCheckState(Qt::Checked);
						_term_item->child(i)->appendRow(time_item);
						found=true;
					}


				}


			}
			if(!found){
				context_item=new QStandardItem(c->get_context());
				context_item->setCheckable(true);
				context_item->setCheckState(Qt::Checked);
				_term_item->appendRow(context_item);
				QStandardItem * time_item=new QStandardItem(time);
				time_item->setCheckable(true);
				time_item->setCheckState(Qt::Checked);
				context_item->appendRow(time_item);

			}



			/*
			if(_term_item->hasChildren()){
				for (int i =0;i<_term_item->rowCount();i++){
					if(_term_item->child(i)->text()==c->get_context()){
						context_item=_term_item->child(i);
					}


				}
				if(context_item==NULL){
					context_item=new QStandardItem(c->get_context());
				}
			}
			_term_item->appendRow(context_item);
			QStandardItem * time_item=new QStandardItem(time);
			time_item->setCheckable(true);
			time_item->setCheckState(Qt::Checked);
			context_item->appendRow(time_item);
			*/



			//val.setAttribute("Context",c->get_context());




		}
		if(c->get_unit()!=""){
			//val.setAttribute("Unit",c->get_unit());
		}
		if(c->get_label()!=""){
			//val.setAttribute("Label",c->get_label());
		}
		for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it=c->get_cycleValues()->begin();it!=c->get_cycleValues()->end();++it){
			//write_values(&val,static_cast<ValueBase*>((*it).first));
		}
		//_elem->appendChild(val);

	}
}

void ExperimentTableView::init_variable_tree(){
	this->variableView=new QTreeView;
	variableView->header()->hide();

	this->variableModel = new QStandardItemModel;
	QStandardItem * variable_item=new QStandardItem("Variable");
	variable_item->setCheckable(true);
	variable_item->setCheckState(Qt::Checked);
	variableModel->appendRow(variable_item);
	DynamicTerm * term;
	for (std::list<StoryNode*>::iterator it= this->xemlDoc->get_storyboard()->get_storyBoard()->begin();it!=this->xemlDoc->get_storyboard()->get_storyBoard()->end();++it){
		StoryNode * node=static_cast<StoryNode*>((*it));
		for(std::vector<std::pair<BasicTerm*,QString> >::iterator it2=node->get_story()->get_variablesCollection()->begin();it2!=node->get_story()->get_variablesCollection()->end();++it2){
			term=static_cast<DynamicTerm*>((*it2).first);
			QStandardItem * term_item=new QStandardItem(term->get_name());
			term_item->setCheckable(true);
			term_item->setCheckState(Qt::Checked);
			variable_item->appendRow(term_item);

			QDateTime current_datetime;
			QDateTime previous_datetime;
			for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it3=term->get_dynamicvaluecollection()->begin();it3!=term->get_dynamicvaluecollection()->end();++it3){

				//std::cerr << "datetime in write param : " << static_cast<QDateTime>((*it2).second).toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;

				if (it3==term->get_dynamicvaluecollection()->begin()){
					current_datetime=(*it3).second;

				}
				else{
					previous_datetime=current_datetime;
					current_datetime=(*it3).second;
				}
				if(previous_datetime!=current_datetime){
					//Vs=this->doc.createElement("xeml:ValueSet");
				}

				qint64 milliseconds_ellapsed=get_seconds_from_date(this->xemlDoc->get_startdate(),(*it3).second);
				write_variable_context(term_item,static_cast<ValueBase*>((*it3).first),milliseconds_ellapsed);

				//Vs.setAttribute("TimePoint",translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed));
				//var.appendChild(Vs);

			}


		}
	}

	this->variableView->setModel(variableModel);
	connect(variableModel,SIGNAL(itemChanged(QStandardItem*)),this->experiment_view,SLOT(variable_item_checked(QStandardItem*)));

	// retrieve all variables used in the Xeml Doc.

}

void ExperimentTableView::init_event_tree(){
	this->eventView=new QTreeView;
	this->eventView->header()->hide();

	this->eventModel = new QStandardItemModel;
	QStandardItem * event_item=new QStandardItem("Event");
	event_item->setCheckable(true);
	event_item->setCheckState(Qt::Checked);
	eventModel->appendRow(event_item);
	this->eventView->setModel(eventModel);
	connect(eventModel,SIGNAL(itemChanged(QStandardItem*)),this->experiment_view,SLOT(event_item_checked(QStandardItem*)));


}
