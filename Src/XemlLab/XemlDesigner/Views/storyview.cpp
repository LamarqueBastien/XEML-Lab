#include "storyview.h"

//Constructor
StoryView::StoryView(QWidget *parent) :
	QWidget(parent)
{

	//deprecated
	this->storytree= new QTreeView;
	//init position in Y for the first story
	this->posY_item=0;

	this->zoomFactor=1;
	/*
	this->zoomFactorSelector=new QComboBox;
	this->zoomFactorSelector->addItem("day slot");
	this->zoomFactorSelector->addItem("12 hours slot");
	this->zoomFactorSelector->addItem("8 hours slot");
	this->zoomFactorSelector->addItem("6 hours slot");
	this->zoomFactorSelector->addItem("4 hours slot");
	this->zoomFactorSelector->addItem("3 hours slot");
	this->zoomFactorSelector->addItem("2 hours slot");
	this->zoomFactorSelector->addItem(" hour slot");
	*/


	this->GraphicScene=new GraphicStoryScene(posY_item);

	this->graphicStory=new GraphicStoryView(this->GraphicScene);
	this->graphicStory->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

	this->my_treestory= new QStandardItemModel;
	this->storytree->setModel(this->my_treestory);
	this->storytree->header()->hide();

	this->GraphicMode=true;


	this->info_view=new XemlObjectInfoView();

	connect(this->info_view,SIGNAL(refresh_view()),this,SLOT(refresh()));

	//info panel for xeml annotable object
	StoryLabelEdit= new QLineEdit;
	//ZoomFactorLabel=new QLabel("Time Step :");
	//ZoomFactorLabel->setBuddy(zoomFactorSelector);
	StoryLabel=new QLabel("Label :");
	StoryLabel->setBuddy(StoryLabelEdit);

	StoryStartTime=new QDateTimeEdit;
	StoryStartTime->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
	StoryStartTime->setDisabled(true);


	StoryStartTimeLabel=new QLabel("Start time :");
	StoryStartTimeLabel->setBuddy(StoryStartTime);


	QString stylesheet("background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
			"border-style: outset;"
			"border-width: 1px;"
			"border-radius: 10px;"
			"border-color: beige;"
			"font: bold 10px;"
			"color:black;"
			"min-width: 8em;"
			"min-height: 0.95em;"
		   " margin: 0 1px 0 1px;"
			"color:rgb(0,0,0);"
			"padding: 6px;");


	remove_variable= new QPushButton(QIcon(":/Images/DeleteHS.png"),"remove variable");
	remove_variable->setToolTip("remove a parameter from the selected story");
	remove_variable->setStyleSheet(stylesheet);



	editExperiment = new QPushButton("experiment details");
	editExperiment->setToolTip("Edit experiment start/end date "
							   "and all details about experimlenter");
	editExperiment->setStyleSheet(stylesheet);


	addstory= new QPushButton(QIcon(":/Images/StoryLogo.png"),"add story");
	addstory->setToolTip("Add a new story "
						 "(story time is equivalent to the experiment time)");
	addstory->setStyleSheet(stylesheet);


	addstorysplit= new QPushButton(QIcon(":/Images/SplitLogo.png"),"add story split");
	addstorysplit->setToolTip("Add a new split to the selected story--"
							  "change story time by left clicking and dragging it "
							  "(one story should be selected )");
	addstorysplit->setStyleSheet(stylesheet);


	addobsPoint= new QPushButton("add observationPoint");
	addobsPoint->setToolTip("Add a new observation point after choose timepoint for it--"
							"populate this observation point by adding samples");
	addobsPoint->setStyleSheet(stylesheet);

	addEvent= new QPushButton(QIcon(":/Images/EventLogo.png"),"add Event");
	addEvent->setToolTip("Add a new event after choose his label");
	addEvent->setStyleSheet(stylesheet);
	rmEvent= new QPushButton(QIcon(":/Images/DeleteHS.png"),"remove Event");
	rmEvent->setStyleSheet(stylesheet);
	addSamples= new QPushButton("add sample");
	addSamples->setStyleSheet(stylesheet);
	removestory=new QPushButton(QIcon(":/Images/DeleteHS.png"),"remove story");
	removestory->setStyleSheet(stylesheet);
	removeObsPoint=new QPushButton(QIcon(":/Images/DeleteHS.png"),"remove observation");
	removeObsPoint->setStyleSheet(stylesheet);
	removeSample=new QPushButton(QIcon(":/Images/DeleteHS.png"),"remove sample");
	removeSample->setStyleSheet(stylesheet);
	removeStorySplit=new QPushButton(QIcon(":/Images/DeleteHS.png"),"remove split");
	removeStorySplit->setStyleSheet(stylesheet);



	this->remove_variable->setCursor(Qt::PointingHandCursor);
	this->editExperiment->setCursor(Qt::PointingHandCursor);
	this->addstory->setCursor(Qt::PointingHandCursor);
	this->addstorysplit->setCursor(Qt::PointingHandCursor);
	this->addobsPoint->setCursor(Qt::PointingHandCursor);
	this->addSamples->setCursor(Qt::PointingHandCursor);
	this->addEvent->setCursor(Qt::PointingHandCursor);
	this->rmEvent->setCursor(Qt::PointingHandCursor);
	this->removestory->setCursor(Qt::PointingHandCursor);
	this->removeObsPoint->setCursor(Qt::PointingHandCursor);
	this->removeSample->setCursor(Qt::PointingHandCursor);
	this->removeStorySplit->setCursor(Qt::PointingHandCursor);

	int size = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
	QSize iconSize(size, size);

	QToolButton *zoomInIcon = new QToolButton;
	zoomInIcon->setAutoRepeat(true);
	zoomInIcon->setAutoRepeatInterval(33);
	zoomInIcon->setAutoRepeatDelay(0);
	zoomInIcon->setIcon(QPixmap("://Images/zoomin.png"));
	zoomInIcon->setIconSize(iconSize);
	QToolButton *zoomOutIcon = new QToolButton;
	zoomOutIcon->setAutoRepeat(true);
	zoomOutIcon->setAutoRepeatInterval(33);
	zoomOutIcon->setAutoRepeatDelay(0);
	zoomOutIcon->setIcon(QPixmap("://Images/zoomout.png"));
	zoomOutIcon->setIconSize(iconSize);
	zoomSlider = new QSlider(Qt::Vertical);
	zoomSlider->setMinimum(0);
	zoomSlider->setMaximum(500);
	zoomSlider->setValue(250);
	zoomSlider->setTickPosition(QSlider::TicksRight);

	QVBoxLayout *zoomSliderLayout = new QVBoxLayout;
	zoomSliderLayout->addWidget(zoomInIcon);
	zoomSliderLayout->addWidget(zoomSlider);
	zoomSliderLayout->addWidget(zoomOutIcon);
	//zoomSliderLayout->addWidget(zoomFactorSelector);

	QVBoxLayout  * layout = new QVBoxLayout;
	QHBoxLayout  * newLayout = new QHBoxLayout;
	QHBoxLayout  * infoLayout = new QHBoxLayout;
	QHBoxLayout  * buttonlayout1 = new QHBoxLayout;
	QHBoxLayout  * buttonlayout2 =new QHBoxLayout;
	//QHBoxLayout  buttonlayout3 =new QHBoxLayout;

	if(GraphicMode){
		newLayout->addLayout(zoomSliderLayout);
		newLayout->addWidget(graphicStory);
		layout->addLayout(newLayout);
	}
	else{
		layout->addWidget(this->storytree);
	}

	//info story line
/*
	infoLayout->addWidget(StoryLabel);
	infoLayout->addWidget(StoryLabelEdit);
	infoLayout->addWidget(StoryStartTimeLabel);
	infoLayout->addWidget(StoryStartTime);

	//infoLayout->addWidget(ZoomFactorLabel);
	//infoLayout->addWidget(zoomFactorSelector);
	infoLayout->addStretch(4);
*/
	infoLayout->addWidget(info_view);
	//first button line
	buttonlayout1->addWidget(editExperiment);
	buttonlayout1->addWidget(addstory);
	//buttonlayout1->addWidget(addstorysplit);
	buttonlayout1->addWidget(addobsPoint);
	buttonlayout1->addWidget(addSamples);
	buttonlayout1->addWidget(addEvent);

	//second buttons line
	buttonlayout2->addWidget(remove_variable);
	buttonlayout2->addWidget(removestory);
	//buttonlayout2->addWidget(removeStorySplit);
	buttonlayout2->addWidget(removeObsPoint);
	buttonlayout2->addWidget(removeSample);
	buttonlayout2->addWidget(rmEvent);
	layout->addLayout(infoLayout);
	layout->addLayout(buttonlayout1);
	layout->addLayout(buttonlayout2);

	setLayout(layout);






	connect(zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
	connect(zoomInIcon, SIGNAL(clicked()), this, SLOT(zoomIn()));
	connect(zoomOutIcon, SIGNAL(clicked()), this, SLOT(zoomOut()));
	//connect(zoomFactorSelector,SIGNAL(currentIndexChanged(QString)),this,SLOT(set_up_zoom_factor(QString)));

	//connect(this,SIGNAL(destroyed())
	connect(this->storytree,SIGNAL(clicked(QModelIndex)),this,SLOT(refresh_genotypeView(QModelIndex)));
	connect(this->storytree,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(clicSelection(QModelIndex)));

	//connect this storyview to the graphic view slots
	connect(this,SIGNAL(add_graphic_story(QString,StoryBase*)),this->graphicStory,SLOT(add_root_story(QString,StoryBase*)));
	connect(this,SIGNAL(add_graphic_story_split(QString,StoryBase*)),this->graphicStory,SLOT(add_split_story(QString,StoryBase*)));
	connect(this,SIGNAL(add_observationPoint(ObservationPoint*)),this->graphicStory,SLOT(add_obsPoint(ObservationPoint *)));

	//connect the graphic scene menu to this story view
	connect(this->GraphicScene,SIGNAL(show_details_story(GraphicStoryItem*)),this,SLOT(details_about_story(GraphicStoryItem*)));
	connect(this->GraphicScene,SIGNAL(obsPoint2removed()),this,SLOT(remove_obs_point()));
	connect(this->GraphicScene,SIGNAL(event2removed()),this,SLOT(remove_event()));
	connect(this->GraphicScene,SIGNAL(event2edit()),this,SLOT(edit_event()));
	connect(this->GraphicScene,SIGNAL(set_details_in_view(StoryBase*)),this,SLOT(set_story_info(StoryBase*)));
	connect(this->GraphicScene,SIGNAL(set_details_in_view(QGraphicsItem*)),this->info_view,SLOT(set_object_info(QGraphicsItem*)));
	connect(this->GraphicScene,SIGNAL(on_displayed_plot_parameter(StoryBase*)),this,SLOT(display_plot(StoryBase*)));


	//connect all the buttons
	connect(StoryLabelEdit,SIGNAL(textEdited(QString)),this,SLOT(reset_StoryName(QString)));
	connect(remove_variable,SIGNAL(clicked()),this,SLOT(remove_parameter()));
	connect(editExperiment,SIGNAL(clicked()),this,SLOT(edit_Experiment()));
	connect(addstorysplit,SIGNAL(clicked()),this,SLOT(newStorySplit()));
	connect(addstory,SIGNAL(clicked()),this,SLOT(newStory()));
	connect(addobsPoint,SIGNAL(clicked()),this,SLOT(add_observationPoint()));
	connect(addSamples,SIGNAL(clicked()),this,SLOT(choose_obsPoint()));
	connect(removestory,SIGNAL(clicked()),this,SLOT(removeStory()));
	connect(removeObsPoint,SIGNAL(clicked()),this,SLOT(remove_obs_point()));
	connect(addEvent,SIGNAL(clicked()),this,SLOT(new_event()));
	connect(rmEvent,SIGNAL(clicked()),this,SLOT(remove_event()));


	//this->setMouseTracking(true);
	//this->setStyleSheet("QWidget { background-color: rgb(204,204,204); }");
	//Users/benjamindartigues/Pictures/BlueMetal.png
	QString fenObjectName("StoryView");
	this->setObjectName(fenObjectName);
	this->setStyleSheet("QWidget#"+fenObjectName +"{ background-color: rgb(225,206,154);}"+"QToolTip { color: #fff; background-color: #000; border: none; }");
	/*
					"border-style: outset;"
					"border-width: 1px;"
					"border-radius: 10px;"
					"border-color: beige;"
					"font: bold 13px;"
					"color:black;"
					"min-width: 9em;"
					"min-height: 0.95em;"
				   " margin: 0 1px 0 1px;"
					"color:rgb(0,0,0);"
					"padding: 15px;"
				);
				*/


}
void StoryView::refresh(){
	std::cerr << "entering in refresh (storyView)" << std::endl;

	//QWidget* viewport = this->viewport();
	//viewport->update();

	this->GraphicScene->update();
	//this->graphicStory->update();
	this->graphicStory->setScene(this->GraphicScene);
	//emit refresh_story_view(this);
	//this->graphicStory->repaint();
	//this->update();
	//this->repaint();
	//this->show();

}

void StoryView::display_plot(StoryBase * _story){
	std::cerr << "entering display plot" << std::endl;


	if (_story->get_variablesCollection()->empty()){
		QMessageBox::information(this,"no parameter","no parameter to plot");

	}
	else{

		this->graphicPlot=new PlotParameterView(_story,this->currentDoc);
		this->graphicPlot->show();
	}

}

void StoryView::reset_StoryName(QString label){
	if(this->GraphicScene->get_selected_story()!=NULL){

		std::cerr << "entering reset story NAme with new label :" <<label.toStdString()<< std::endl;

		StoryNode * node=this->currentDoc->get_storyboard()->findNode(my_selected_story->get_label());
		node->get_story()->set_label(label);
		node->set_label(label);
		//if (node->get_parent()!=NULL){
			//node->get_parent()->set_label(label);
		//}



		if (!node->get_childs()->empty()){
			std::cerr << "node get childs "<< std::endl;
			for (std::list<StoryNode*>::iterator it=node->get_childs()->begin();it!=node->get_childs()->end();++it){
				static_cast<StoryNode*>((*it))->get_parent()->get_story()->set_label(label);
				static_cast<StoryNode*>((*it))->get_parent()->set_label(label);
			}
		}


		emit refresh_story_view(this);
	}
}

void StoryView::set_story_info(StoryBase* story){
	std::cerr << "entering set story info for qstory :" << story->get_label().toStdString() << std::endl;
	my_selected_story=story;
	this->StoryLabelEdit->setText(story->get_label());

	if (story->get_IsStorySplit()){
		this->StoryStartTime->setDateTime(static_cast<StorySplit*>(story)->get_timepoint());
	}
	else{
		this->StoryStartTime->setDateTime(this->currentDoc->get_startdate());
	}
}

void StoryView::set_up_zoom_factor(QString _zoomfactor){
	std::cerr << "entering set up zoom factor" << std::endl;
	if (_zoomfactor=="day slot"){
		this->zoomFactor=1;
	}
	else if(_zoomfactor=="12 hours slot"){
		this->zoomFactor=2;
	}
	else if(_zoomfactor=="8 hours slot"){
		this->zoomFactor=3;
	}
	else if(_zoomfactor=="6 hours slot"){
		this->zoomFactor=4;
	}
	else if(_zoomfactor=="4 hours slot"){
		this->zoomFactor=6;
	}
	else if(_zoomfactor=="3 hours slot"){
		this->zoomFactor=8;
	}
	else if(_zoomfactor=="2 hours slot"){
		this->zoomFactor=12;
	}
	else{
		this->zoomFactor=24;
	}

	//zoomFactor=_zoomfactor.toInt();
	emit refresh_story_view(this);
}

void StoryView::zoomIn(int level)
{
	zoomSlider->setValue(zoomSlider->value() + level);
}

void StoryView::zoomOut(int level)
{
	zoomSlider->setValue(zoomSlider->value() - level);
}
void StoryView::setupMatrix()
{
	qreal scale = qPow(qreal(2), (zoomSlider->value() - 250) / qreal(50));

	QMatrix matrix;
	matrix.scale(scale, scale);
	//matrix.rotate(rotateSlider->value());

	this->graphicStory->setMatrix(matrix);
	//setResetButtonEnabled();
}


void StoryView::refresh_genotypeView(QModelIndex _elementSelected){
	emit on_refresh_genotype_view();
}
/*
void StoryView::mouseDoubleClickEvent(QMouseEvent * _event){
	if(this->rect().contains(_event->pos())){
		QMessageBox::information( this, "Information", " this is the view of your experiment\n"
		"You can add new story and story split\n"
		"Please.", QMessageBox::Ok, 0 );
	}
	else{

	}
}

void StoryView::mouseMoveEvent(QMouseEvent *_event)
{
	if (this->rect().contains(_event->pos())) {
		// Mouse over Widget
		//std::cerr << _event->pos().rx() <<","<<_event->pos().ry() << std::endl;

	}
	else {
		// Mouse out of Widget
	}
}
*/

QStandardItemModel * StoryView::get_model(){
	return this->my_treestory;
}

void  StoryView::add_genotype(IndividualsPool * _pool, QString _idtext,QString _freetext,QString _taxontext){
	if (GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			StoryNode * node=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());
			if (!node->get_isStorySplit()){
				std::cerr << "entering if not storysplit : " << _idtext.toStdString() << std::endl;

				_pool->display_all_tags();
				IndividualsPool * pool = _pool;
				//pool->set_ns("none");
				pool->set_germplasm(_idtext);
				if((!_freetext.isEmpty())&&(!_freetext.isNull())){
					pool->add_tagged_annotation(new TaggedAnnotation("FreeText",_freetext));
				}
				if((!_taxontext.isEmpty())&&(!_taxontext.isNull())){
					pool->add_tagged_annotation(new TaggedAnnotation("NcbiTaxonomyId",_taxontext));
				}

				static_cast<Story*>(node->get_story())->add_individualspool(pool);
				emit this->refresh_genotype_view(this->currentDoc);
			}
			else{
				QMessageBox::information(this,"added element","can't add a pool to a story split");
			}
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
	//std::cerr << "entering add_genotype : " << _idtext.toStdString() << std::endl;
	else{

		QItemSelectionModel  * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){
			//QVariant elementSelected = this->my_treestory->data(indexelementselected);
			AbstractExperimentItem  * tmp = static_cast<AbstractExperimentItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			if(tmp->isRoot()){
				QMessageBox::information(this,"added element","can't add a pool directly to experiment");


			}
			else{
				StoryItem  * exp=static_cast<StoryItem*>(tmp);
				if (!exp->get_isStorySplit()){
					std::cerr << "entering if not storysplit : " << _idtext.toStdString() << std::endl;

					IndividualsPool * pool = new IndividualsPool();
					//pool->set_ns("none");
					pool->set_germplasm(_idtext);
					if((!_freetext.isEmpty())&&(!_freetext.isNull())){
						pool->add_tagged_annotation(new TaggedAnnotation("FreeText",_freetext));
					}
					if((!_taxontext.isEmpty())&&(!_taxontext.isNull())){
						pool->add_tagged_annotation(new TaggedAnnotation("NcbiTaxonomyId",_taxontext));
					}

					static_cast<Story*>(exp->get_story())->add_individualspool(pool);
					emit this->refresh_genotype_view(this->currentDoc);
				}
				else{
					QMessageBox::information(this,"added element","can't add a pool to a story split");
				}

			}
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}


}

//Display details about the current experiment and experimenter
void StoryView::edit_Experiment(){

	this->aboutexp =new AboutExperiment(this->currentDoc);
	connect(this->aboutexp,SIGNAL(experimenter_set_up_finished(QString,QString,QString,QString)),this,SLOT(set_up_experimenter(QString,QString,QString,QString)));

	aboutexp->show();
	/*
	QItemSelectionModel  * selection = this->storytree->selectionModel();
	QModelIndex indexelementselected= selection->currentIndex();
	if(selection->isSelected(indexelementselected)){
		//QVariant elementSelected = this->my_treestory->data(indexelementselected);
		AbstractExperimentItem * tmp = static_cast<AbstractExperimentItem*>(this->my_treestory->itemFromIndex(indexelementselected));
		if(tmp->isRoot()){
			this->aboutexp =new AboutExperiment(this->currentDoc);
			connect(this->aboutexp,SIGNAL(experimenter_set_up_finished(QString,QString,QString,QString)),this,SLOT(set_up_experimenter(QString,QString,QString,QString)));
			aboutexp->show();

		}
		else{
			QMessageBox::information(this,"added element","can't edit a story");

		}
	}
	*/
}
void StoryView::set_up_experimenter(QString _firstnametext,QString _lastnametext,QString _organisationtext,QString _emailtext){



	//static_cast<ExperimentItem*>(this->my_treestory->findItems(this->experimentName,Qt::MatchFixedString | Qt::MatchRecursive)[0])->set_experimenter_details(_firstnametext,_lastnametext,_organisationtext,_emailtext);
	//a modifier pour conserver la trace des infos rentrées
	emit experimenter_settings(_firstnametext,_lastnametext,_organisationtext,_emailtext);
	std::cerr << "before clear" << std::endl;

	this->width=translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),currentDoc->get_enddate()));
	std::cerr << "before clear" << std::endl;
	this->width*=this->zoomFactor;
	std::cerr << "this width  :" << this->width << std::endl;
	this->GraphicScene->set_max_item_width(this->width*zoomFactor);
	std::cerr << "before clear" << std::endl;

	this->GraphicScene->clear();
	this->GraphicScene->positionY=0;
	this->GraphicScene->setSceneRect(-150.0,-150.0,width*zoomFactor+300,600);
	//this->graphicStory->setSceneRect(-150.0,-150.0,width*zoomFactor+300,600);

	for(std::list<StoryNode*>::iterator it=this->currentDoc->get_storyboard()->get_storyBoard()->begin();it!=this->currentDoc->get_storyboard()->get_storyBoard()->end();++it){

		build_graphic_story_hierarchy((*it));


	}
	std::cerr << "before update" << std::endl;
	this->GraphicScene->update();
	this->graphicStory->update();


	this->aboutexp->close();
}

//displays details about the selected story
void StoryView::details_about_story(GraphicStoryItem* _storyselected){
	this->aboutstory=new AboutStory(this->currentDoc);
	this->aboutstory->initialize(_storyselected->get_story(),_storyselected->get_isStorySplit());
	this->aboutstory->setVisible(true);
}

void StoryView::clicSelection(QModelIndex _elementSelected)
{
	QItemSelectionModel  * selection = this->storytree->selectionModel();
	//QModelIndex indexelementselected= selection->currentIndex();
	if(selection->isSelected(_elementSelected)){
		//QVariant elementSelected = this->my_treestory->data(_elementSelected);
		AbstractExperimentItem * tmp =static_cast<AbstractExperimentItem*>(this->my_treestory->itemFromIndex(_elementSelected));
		if(tmp->isRoot()){

			ExperimentItem * exp=static_cast<ExperimentItem*>(tmp);
			QMessageBox::information(this,"exp info","firstname : " + exp->get_experimentHeader()->get_experimenter()->get_firstname()+ "\n" +
													 "lastname : " + exp->get_experimentHeader()->get_experimenter()->get_lastname()+ "\n" +
									 "organisation : " + exp->get_experimentHeader()->get_experimenter()->get_organization() + "\n" +
									 "email : " + exp->get_experimentHeader()->get_experimenter()->get_email());

		}
		else{
			
			StoryItem  * exp=static_cast<StoryItem*>(tmp);
			this->aboutstory=new AboutStory(this->currentDoc);

			this->aboutstory->initialize(exp->get_story(),exp->get_isStorySplit());
			this->aboutstory->setVisible(true);

			//ajouter un signal a aboutStory pour prévenir si changements effectués.

			/*
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it = static_cast<Story*>(exp->get_story())->get_variablesCollection()->begin();it!= static_cast<Story*>(exp->get_story())->get_variablesCollection()->end();++it){
				std::cerr << "term id : " << (*it).second << " termName : "<< static_cast<DynamicTerm*>((*it).first)->get_name().toStdString() <<" term value size: " << static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->size() <<std::endl;
				for(std::map<DynamicValueBase*,TimeSpan*>::iterator it2=static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->begin();it2!=static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->end();++it2){
					std::cerr << "context : " << static_cast<DynamicValue*>((*it2).first)->get_context().toStdString() << std::endl;

					std::cerr << "value : " << static_cast<DynamicValue*>((*it2).first)->get_value().toStdString() << " " <<   static_cast<DynamicValue*>((*it2).first)->get_unit().toStdString()<< std::endl;
				}
			}
			*/

		}
	}
	else{
		QMessageBox::information(this,"added element","no story selected");
	}
}






//for each node without childs (createExperiment), this builds the parent node and adds the child to the parent,
//then it performs recursively (buildnodehierarchy) the same processus until it founds the story node (i.e. node without parent)
//then it return to the function below create experiment();

bool StoryView::contains(StoryNode * _node,std::list<StoryNode*> * _processed_nodes,QString _storyname){

	if(_node!=NULL){
		for(std::list<StoryNode*>::iterator it=_processed_nodes->begin();it!=_processed_nodes->end();++it){
			if((*it)->get_story()->get_label()==_node->get_story()->get_label()&&(*it)->get_mainStoryName()==_storyname){
				return true;

			}
		}
		return false;
	}
	else{
		return false;
	}
}
void StoryView::build_story_hierarchy(StoryNode * _node,std::list<StoryNode*> * _processed_nodes,StoryItem * _tmp_item,QString _storyname){

	_processed_nodes->push_back(_node);
	_tmp_item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	if(_node->get_parent()!=NULL && !contains(_node->get_parent(),_processed_nodes,_storyname)){
		std::cerr << "first if" << std::endl;
		if(this->my_treestory->findItems((_node->get_parent()->get_story()->get_label()),Qt::MatchFixedString | Qt::MatchRecursive,0).size()!=0){ //+"("+_storyname+")"
			std::cerr << "second if" << std::endl;
			this->my_treestory->findItems((_node->get_parent()->get_story()->get_label()),Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);//+"("+_storyname+")"
			std::cerr <<"----------------ajout story " << _node->get_story()->get_label().toStdString() << std::endl;

		}
		else{
			StoryItem * tmp_item1;
			//tmp_item1 = new StoryItem(QString((_node->get_parent()->get_story()->get_label()+"("+_storyname+")").c_str()),_node->get_parent()->get_story(),_node->get_parent()->get_isStorySplit(),false);

			if(_node->get_parent()->get_parent()==NULL){
				tmp_item1 = new StoryItem(_node->get_parent()->get_story()->get_label(),_node->get_parent()->get_story(),_node->get_parent()->get_isStorySplit(),false);
			}
			else{

				tmp_item1 = new StoryItem((_node->get_parent()->get_story()->get_label()),_node->get_parent()->get_story(),_node->get_parent()->get_isStorySplit(),false);   //+"("+_storyname+")"
			}

			tmp_item1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			tmp_item1->appendRow(_tmp_item);
			build_story_hierarchy(_node->get_parent(),_processed_nodes,tmp_item1,_storyname);
		}
	}
	else{

		if(_node->get_parent()!=NULL){
			std::cerr << "else if" << std::endl;
			this->my_treestory->findItems((_node->get_parent()->get_story()->get_label()),Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);//+"("+_storyname+")"
			std::cerr <<"----------------ajout story :" << _node->get_story()->get_label().toStdString() << std::endl;

		}
		else{
			//std::cerr << "else else" << std::endl;
			this->my_treestory->findItems(this->experimentName,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);
			std::cerr <<"----------------ajout story :" << _node->get_story()->get_label().toStdString() << std::endl;

		}
	}

}
void StoryView::build_graphic_story_hierarchy(StoryNode * _node){

	//std::cerr << "entering build graphic story hierarchy :" << std::endl;
	this->GraphicScene->initialize_x_Axis(width,this->zoomFactor);
	Is_timeline_visible=true;
	qreal pos_x;
	qreal offset_x0;
	GraphicObservationPointItem  * tmpobs;
	GraphicEventItem * tmpEvent;

	if(_node->get_parent()==NULL){

		GraphicStoryItem * current_story=new GraphicStoryItem(0,this->currentDoc,width,_node->get_story(),_node->get_story()->get_label(),false,0,this->GraphicScene->positionY,NULL);
		this->GraphicScene->addItem(current_story);
		this->GraphicScene->set_max_item_width(width);
		this->GraphicScene->setSceneRect(QRectF(-150, -150, this->GraphicScene->sceneRect().width(), this->GraphicScene->sceneRect().height()+60));
		this->GraphicScene->positionY+=61;
		qreal y=current_story->get_posy();
		for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=_node->get_story()->get_obsPointCollection()->begin();it!=_node->get_story()->get_obsPointCollection()->end();++it){

			pos_x=translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<ObservationPoint*>((*it).first)->get_timepoint()));
			tmpobs=new GraphicObservationPointItem((*it).first,0,y+20,width,currentDoc->get_startdate(),static_cast<ObservationPoint*>((*it).first)->get_timepoint(), current_story);
			tmpobs->setPos(pos_x*zoomFactor,0);
		}
		for(std::map<Event*,QDateTime>::iterator it=_node->get_story()->get_eventcollection()->begin();it!=_node->get_story()->get_eventcollection()->end();++it){
			pos_x=translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<Event*>((*it).first)->get_timepoint()));
			tmpEvent=new GraphicEventItem((*it).first,0,y+20,width,(*it).first->get_label(),currentDoc->get_startdate(),static_cast<Event*>((*it).first)->get_timepoint(),current_story);
			tmpEvent->setPos(pos_x*zoomFactor,0);
		}
	}
	else{

		qreal x=translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<StorySplit*>(_node->get_story())->get_timepoint()));
		qreal Width=this->width-(x*zoomFactor);
		GraphicStoryItem * parent;
		parent=static_cast<GraphicStoryItem*>(this->GraphicScene->get_item_by_label(_node->get_parent()->get_story()->get_label()));
		qreal width_parent=parent->get_rect().width();
		if (parent!=NULL){

			if(parent->get_isStorySplit()){
				x=translate_second_in_distance(get_seconds_from_date(static_cast<StorySplit*>(parent->get_story())->get_timepoint(),static_cast<StorySplit*>(_node->get_story())->get_timepoint()));

				GraphicStoryItem * tmp =new GraphicStoryItem(width_parent,this->currentDoc,Width,_node->get_story(),_node->get_story()->get_label(),true,0,this->GraphicScene->positionY,parent);
				tmp->setPos(x*zoomFactor,0);
				qreal y=tmp->get_posy();
				offset_x0=this->GraphicScene->get_max_width()-tmp->get_rect().width();

				for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=tmp->get_story()->get_obsPointCollection()->begin();it!=tmp->get_story()->get_obsPointCollection()->end();++it){

					pos_x=translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<ObservationPoint*>((*it).first)->get_timepoint()));
					tmpobs=new GraphicObservationPointItem((*it).first,0,y+20,width,currentDoc->get_startdate(),static_cast<ObservationPoint*>((*it).first)->get_timepoint(),tmp);
					tmpobs->setPos(pos_x*zoomFactor-offset_x0,0);
					tmpobs->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<ObservationPoint*>((*it).first)->get_timepoint())));

				}

				for(std::map<Event*,QDateTime>::iterator it=tmp->get_story()->get_eventcollection()->begin();it!=tmp->get_story()->get_eventcollection()->end();++it){

					pos_x=translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<Event*>((*it).first)->get_timepoint()));
					tmpEvent=new GraphicEventItem((*it).first,0,y+20,width,(*it).first->get_label(),currentDoc->get_startdate(),static_cast<Event*>((*it).first)->get_timepoint(),tmp);
					tmpEvent->setPos(pos_x*zoomFactor-offset_x0,0);
					tmpEvent->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<Event*>((*it).first)->get_timepoint())));

				}
			}
			else{

				GraphicStoryItem * tmp =new GraphicStoryItem(width_parent,this->currentDoc,Width,_node->get_story(),_node->get_story()->get_label(),true,0,this->GraphicScene->positionY,parent);
				tmp->setPos(x*zoomFactor,0);
				qreal y=tmp->get_posy();

				for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=tmp->get_story()->get_obsPointCollection()->begin();it!=tmp->get_story()->get_obsPointCollection()->end();++it){

					pos_x=translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<ObservationPoint*>((*it).first)->get_timepoint()));
					tmpobs=new GraphicObservationPointItem((*it).first,0,y+20,width,currentDoc->get_startdate(),static_cast<ObservationPoint*>((*it).first)->get_timepoint(),tmp);
					tmpobs->setPos((pos_x-x)*zoomFactor,0);
					tmpobs->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<ObservationPoint*>((*it).first)->get_timepoint())));
				}
				for(std::map<Event*,QDateTime>::iterator it=tmp->get_story()->get_eventcollection()->begin();it!=tmp->get_story()->get_eventcollection()->end();++it){

					pos_x=translate_second_in_distance(get_seconds_from_date(currentDoc->get_startdate(),static_cast<Event*>((*it).first)->get_timepoint()));
					tmpEvent=new GraphicEventItem((*it).first,0,y+20,width,(*it).first->get_label(),currentDoc->get_startdate(),static_cast<Event*>((*it).first)->get_timepoint(),tmp);
					tmpEvent->setPos((pos_x-x)*zoomFactor,0);
					tmpEvent->setToolTip(translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->currentDoc->get_startdate(),static_cast<Event*>((*it).first)->get_timepoint())));

				}
			}

		}
		this->GraphicScene->setSceneRect(QRectF(-150, -150, this->GraphicScene->sceneRect().width()+300, this->GraphicScene->sceneRect().height()+60));
		this->GraphicScene->positionY+=61;

	}

}

void StoryView::createExperiment(ItfDocument  * _current_xeml,DocumentResources * _doc_ressources){

	this->experimentName=_current_xeml->get_experiment_name();

	this->currentDoc=_current_xeml;

	this->doc_ressources=_doc_ressources;
	this->GraphicScene->set_doc(currentDoc);
	this->info_view->set_doc(currentDoc);
	//this->width=translate_second_in_distance(get_seconds_from_date(this->currentDoc->get_startdate(),this->currentDoc->get_enddate()));

	//this->GraphicScene->setSceneRect(-150,-150,width+300,600);

	if(GraphicMode){
		this->StoryStartTime->setDateTime(this->currentDoc->get_startdate());
		this->width=translate_second_in_distance(get_seconds_from_date(this->currentDoc->get_startdate(),this->currentDoc->get_enddate()));
		this->width*=zoomFactor;
		this->GraphicScene->setSceneRect(-150,-150,width+300,6000);

		for(std::list<StoryNode*>::iterator it=this->currentDoc->get_storyboard()->get_storyBoard()->begin();it!=this->currentDoc->get_storyboard()->get_storyBoard()->end();++it){
			//std::cerr << "in da loop" << std::endl;
			//std::cerr << "story node get Label :" << static_cast<StoryNode*>((*it))->get_label().toStdString() << std::endl;
			build_graphic_story_hierarchy((*it));


		}

	}
	else{

		ExperimentItem * expItem= new ExperimentItem(this->experimentName,true);
		expItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		this->my_treestory->appendRow(expItem);
		static_cast<ExperimentItem*>(this->my_treestory->findItems(this->experimentName,Qt::MatchFixedString | Qt::MatchRecursive)[0])->set_experimentHeader(_current_xeml->get_experimentheader());
		std::list<StoryNode*> processed_nodes;
		QString storyname;

		for(std::list<StoryNode*>::iterator it=_current_xeml->get_storyboard()->get_storyBoard()->begin();it!=_current_xeml->get_storyboard()->get_storyBoard()->end();++it){

			if((*it)->get_parent()==NULL && _current_xeml->get_storyboard()->get_storyBoard()->size()!=1){
				storyname=(*it)->get_story()->get_label();
				build_story_hierarchy((*it),
									  &processed_nodes,
									  new StoryItem(((*it)->get_story()->get_label()),   //+"("+storyname+")"
													(*it)->get_story(),
													(*it)->get_isStorySplit(),
													false),
									  storyname);
				/*
				StoryItem * template_story=new StoryItem(((*it)->get_story()->get_label()),
														 (*it)->get_story(),
														 (*it)->get_isStorySplit(),
														 false);
				template_story->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
				expItem->appendRow(template_story);
				*/

				//std::cerr <<"----------------ajout story " << (*it)->get_story()->get_label().toStdString() << std::endl;

			}
			if(_current_xeml->get_storyboard()->get_storyBoard()->size()==1){
				StoryItem  *template_story=new StoryItem(((*it)->get_story()->get_label()),
														 (*it)->get_story(),
														 (*it)->get_isStorySplit(),
														 false);
				template_story->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
				expItem->appendRow(template_story);
			}

			if((*it)->get_parent()!=NULL && (*it)->get_childs()->size()==0){

				build_story_hierarchy((*it),
									  &processed_nodes,
									  new StoryItem(((*it)->get_story()->get_label()),     //+"("+storyname+")"
													(*it)->get_story(),
													(*it)->get_isStorySplit(),
													false),
									  storyname);

			}
		}
	}
}
void StoryView::clean_tree(){
	if (GraphicMode){
		this->GraphicScene->clear();
		this->GraphicScene->positionY=0;
		this->Is_timeline_visible=false;
	}
	else{


		my_treestory->clear();
	}
}

//Story and StorySplit slots
void StoryView::newStory(){
	this->storydialog = new StoryDialog;
	this->storydialog->setVisible(true);
	connect(storydialog,SIGNAL(new_story(QString)),this,SLOT(addStory(QString)));
	connect(storydialog,SIGNAL(new_story_split(QString)),this,SLOT(add_graphic_split_story(QString)));

}
void StoryView::addStory(QString _text){

	Story * s=new Story(_text);
	StoryNode * sn = new StoryNode(s,false,_text);
	this->currentDoc->get_storyboard()->add_Node(sn);
	if (!Is_timeline_visible){
		this->GraphicScene->initialize_x_Axis(width,this->zoomFactor);

	}
	if (GraphicMode){
		emit add_graphic_story(_text,s);
	}
	else{
		StoryItem * tmp =new StoryItem(_text,s,false,false);
		tmp->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		this->my_treestory->findItems(this->experimentName,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(tmp);
	}


	//this->graphicStory->add_root_story(_text,s);


	this->storydialog->close();

}
void StoryView::newStorySplit(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			this->storydialog = new StoryDialog;
			this->storydialog->setVisible(true);
			connect(storydialog,SIGNAL(mon_signal(QString)),this,SLOT(add_graphic_split_story(QString)));
		}
		else{
				QMessageBox::information(this,"no selection","no story selected");
			}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){


			QVariant elementSelected = this->my_treestory->data(indexelementselected);
			//std::cerr << elementSelected.toString().toStdString() << std::endl;
			AbstractExperimentItem * tmp =static_cast<AbstractExperimentItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			if(tmp->isRoot()){
				QMessageBox::information(this,"root exception","can't add a storysplit to experiment");
			}
			else{
				this->splitstorydialog = new StorySplitDialog(this->currentDoc,elementSelected);
				connect(this->splitstorydialog,SIGNAL(storysplitset(QString,QString,QDateTime)),this,SLOT(addStorySplit(QString,QString,QDateTime)));
				this->splitstorydialog->setVisible(true);
			}
		}
		else{
				QMessageBox::information(this,"no selection","no story selected");
			}
	}
}
void StoryView::add_graphic_split_story(QString _label){
	std::cerr << " entering slot" << std::endl;
	std::cerr << "selected items" << this->GraphicScene->get_selected_story()->get_label().toStdString() << std::endl;
	std::cerr << "search for parent: " << this->GraphicScene->get_selected_story()->get_label().toStdString() << std::endl;

	if(this->GraphicScene->get_selected_story()!=NULL){
		std::cerr << "search for parent: " << this->GraphicScene->get_selected_story()->get_label().toStdString() << std::endl;
		StoryNode * parent=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());

		if(parent!=NULL){// && parent->get_parent()==NULL
			QString mainname=parent->get_mainStoryName();
			std::cerr << "parent name :" << mainname.toStdString() << std::endl;
			StorySplit * ss = new StorySplit();
			ss->set_label(_label);
			ss->set_timepoint(this->currentDoc->get_startdate());
			StoryNode * sn =new StoryNode(ss,true,mainname);
			//std::cerr << "size before : " << this->currentDoc->get_storyboard()->get_storyBoard()->size() << std::endl;
			this->currentDoc->get_storyboard()->add_Node(sn);
			this->currentDoc->get_storyboard()->findNode_by_Label(this->GraphicScene->get_selected_story()->get_label(),mainname)->addSubStoryNode(sn);
			//std::cerr << "size after : " << this->currentDoc->get_storyboard()->get_storyBoard()->size() << std::endl;
			emit add_graphic_story_split(_label,ss);
		}
	}
	else{
		QMessageBox::information(this,"no selection","no story selected");
	}
	this->GraphicScene->update();
	this->graphicStory->update();
	this->storydialog->close();
}

void StoryView::addStorySplit(QString _element_selected,QString _text,QDateTime _datetime){

	//QItemSelectionModel  selection = this->storytree->selectionModel();
	//QModelIndex indexelementselected= selection->currentIndex();
	//if(selection->isSelected(indexelementselected)){


	//	QVariant elementSelected = this->my_treestory->data(indexelementselected);
	//	AbstractExperimentItem  tmp =static_cast<AbstractExperimentItem*>(this->my_treestory->itemFromIndex(indexelementselected));
	//	if(tmp->isRoot()){
	//		QMessageBox::information(this,"root exception","can't add a splitstory to experiment");
	//	}
	//	else{
			//std::cerr << "in addstorysplit " << _element_selected.toStdString() << std::endl;
			StoryNode * parent=this->currentDoc->get_storyboard()->findNode(_element_selected);
			if(parent==NULL){
				std::cerr << "parent null" << std::endl;
			}
			//std::cerr << "debug2" <<  std::endl;
			QString mainname=parent->get_mainStoryName();
			//std::cerr << "debug" <<mainname.toStdString() <<  std::endl;
			StorySplit * ss = new StorySplit();
			ss->set_label(_text);
			ss->set_timepoint(_datetime);// TimeSpanExtension::tryTimeSpanSet(_text2.toStdString()));
			StoryItem * item =new StoryItem(_text,ss,true,false);
			StoryNode * sn =new StoryNode(ss,true,mainname);
			this->currentDoc->get_storyboard()->add_Node(sn);
			this->currentDoc->get_storyboard()->findNode_by_Label(_element_selected,mainname)->addSubStoryNode(sn);
			item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			this->my_treestory->findItems(_element_selected,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(item);

		//}
	//}
	//else{
	//	QMessageBox::information(this,"no selection","no selected element");
	//}
	this->splitstorydialog->close();

}
void StoryView::removeStory(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			std::cerr << "name : "<< this->GraphicScene->get_selected_story()->get_label().toStdString() << std::endl;
			StoryNode * node=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());


			if(node!=NULL){
				static_cast<XemlDocument*>(this->currentDoc)->purge_story(node);
			}
			/*
			for(std::list<StoryNode*>::iterator it = this->currentDoc->get_storyboard()->get_storyBoard()->begin();it!=this->currentDoc->get_storyboard()->get_storyBoard()->end();++it){
				if(static_cast<StoryNode*>((*it))->get_label()==node->get_story()->get_label()){
					 static_cast<XemlDocument*>(this->currentDoc)->purge_story(node);
				}
			}
			*/
			std::cerr << "before refresh storyview " << std::endl;

			emit refresh_story_view(this);
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){
			//QVariant elementSelected = this->my_treestory->data(indexelementselected);
			AbstractExperimentItem * tmp =static_cast<AbstractExperimentItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			if(tmp->isRoot()){


				QMessageBox::information(this,"exp info","can't select a experiment node");

			}
			else{


				StoryItem * exp=static_cast<StoryItem*>(tmp);
				//if(exp->get_isStorySplit()){

				//}
				//QString(exp->get_story()->get_label().c_str());
				//else{
				for(std::list<StoryNode*>::iterator it = this->currentDoc->get_storyboard()->get_storyBoard()->begin();it!=this->currentDoc->get_storyboard()->get_storyBoard()->end();++it){
					if(static_cast<StoryNode*>((*it))->get_label()==exp->get_story()->get_label()){
						std::cerr << "beginning purge story "<< (*it)->get_label().toStdString() << std::endl;
						static_cast<XemlDocument*>(this->currentDoc)->purge_story((*it));
						//std::cerr << "finishing purge story "<< (*it)->get_label().toStdString() << std::endl;
						//std::cerr << "--------"<< "--" << this->my_treestory->findItems((*it)->get_label(),Qt::MatchFixedString | Qt::MatchRecursive).size() << std::endl;
						//this->my_treestory->findItems((*it)->get_label(),Qt::MatchFixedString | Qt::MatchRecursive)[0]->removeRow(indexelementselected.row());
						//std::cerr << "removing from view "<< (*it)->get_label().toStdString() << std::endl;

					}
				}
				//}
			}
			std::cerr << "signal sent" << std::endl;
			emit refresh_story_view(this);
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}




}

//Function deprecated
void StoryView::createStory(QString _text){
	StoryItem * tmp =new StoryItem(_text,new Story(_text),false,false);
	tmp->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	this->my_treestory->findItems(this->experimentName,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(tmp);
}

//Parameter slots
void StoryView::new_parameter(ItfOntologyTerm * _term){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			StoryNode * parent=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());
			//QString mainname=parent->get_mainStoryName();
			if (_term->get_prototype()->get_namespacealias()=="XEO" || _term->get_prototype()->get_namespacealias()=="XEO_Positioning" ||_term->get_prototype()->get_namespacealias()=="EO" || _term->get_prototype()->get_namespacealias()=="EnvO"){

				this->aboutParameter=new AboutParameter(this->currentDoc,parent);
				std::cerr << "before set Term" << std::endl;

				this->aboutParameter->set_term(_term);
				std::cerr << "before initialize" << std::endl;
				this->aboutParameter->initialize();
				//this->aboutParameter->setVisible(true);
				/*
				 *modifier pour éviter d'ajouter une variable dévelopmental ou structural dans la variablecollection d'une story.
				 *ajouter ces variables aux partitions des points d'observation des stories.
				 *ne pas oublier de vérifier l'encodage, la validité des adresses, la recopie du document Xeml à la suite du doc précedent.
				*/

				connect(this->aboutParameter,SIGNAL(set_up_finished(StoryNode *,BasicTerm*)),this,SLOT(add_parameter(StoryNode *,BasicTerm*)));
				//this->currentDoc->get_storyboard()->findNode_by_Label(elementSelected.toString(),mainname)->get_story()->add_variable(_term->get_prototype());

			}
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){
			QVariant elementSelected = this->my_treestory->data(indexelementselected);
			StoryItem  *tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			if(tmp->isRoot()){
				QMessageBox::information(this,"added element","can't add a term to experiment");
			}
			else{
				StoryNode * parent=this->currentDoc->get_storyboard()->findNode(elementSelected.toString());
				//QString mainname=parent->get_mainStoryName();
				if (_term->get_prototype()->get_namespacealias()=="XEO" || _term->get_prototype()->get_namespacealias()=="XEO_Positioning" ||_term->get_prototype()->get_namespacealias()=="EO" || _term->get_prototype()->get_namespacealias()=="EnvO"){

					this->aboutParameter=new AboutParameter(this->currentDoc,parent);
					std::cerr << "before set Term" << std::endl;

					this->aboutParameter->set_term(_term);
					std::cerr << "before initialize" << std::endl;
					this->aboutParameter->initialize();
					//this->aboutParameter->setVisible(true);
					/*
					 *modifier pour éviter d'ajouter une variable dévelopmental ou structural dans la variablecollection d'une story.
					 *ajouter ces variables aux partitions des points d'observation des stories.
					 *ne pas oublier de vérifier l'encodage, la validité des adresses, la recopie du document Xeml à la suite du doc précedent.
					*/

					connect(this->aboutParameter,SIGNAL(set_up_finished(StoryNode *,BasicTerm*)),this,SLOT(add_parameter(StoryNode *,BasicTerm*)));
					//this->currentDoc->get_storyboard()->findNode_by_Label(elementSelected.toString(),mainname)->get_story()->add_variable(_term->get_prototype());

				}


				else{

				}
			}
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}

}
void StoryView::add_parameter(StoryNode * _story,BasicTerm * _term){
	//ajouter fonction _tmp.contains_term()
	//_tmp->add_term(_term);
	if(!(this->currentDoc->get_storyboard()->findNode_by_Label(_story->get_label(),_story->get_mainStoryName())->get_story()->contain_variable(_term))){
		std::cerr << "story label : " << this->currentDoc->get_storyboard()->findNode_by_Label(_story->get_label(),_story->get_mainStoryName())->get_story()->get_label().toStdString() << std::endl;
		/*
		DynamicTerm * p= new DynamicTerm(_term->get_termId());
		p->set_name(_term->get_prototype()->get_name());
		p->set_namespacealias(_term->get_prototype()->get_namespacealias());
		p->set_namespace(_term->get_prototype()->get_namespace());
		for(std::map<QString, VariableContextSpec*>::iterator it=static_cast<XeoTerm*>(_term)->get_contextCollection()->begin();it!=static_cast<XeoTerm*>(_term)->get_contextCollection()->end();++it){
			if(static_cast<XeoTerm*>(_term)->hasDefaultCycle((*it).second->get_name())){
				p->get_dynamicvaluecollection()->push_back(make_pair(static_cast<XeoTerm*>(_term)->defaultCycle((*it).second->get_name()),static_cast<XeoTerm*>(_term)->defaultCycle((*it).second->get_name())->get_timepoint()));
				//(*p->get_dynamicvaluecollection())[this->defaultCycle((*it).second->get_name())]=this->defaultCycle((*it).second->get_name())->get_timepoint();
			}
		}

		this->currentDoc->get_storyboard()->findNode_by_Label(_story->get_label(),_story->get_mainStoryName())->get_story()->add_variable(p);
		*/
		this->currentDoc->get_storyboard()->findNode_by_Label(_story->get_label(),_story->get_mainStoryName())->get_story()->add_variable(_term);

	}
}
void StoryView::remove_parameter(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());
			ParameterPanel * pp=new ParameterPanel(true);
			pp->initialize(current_storyNode->get_story(),current_storyNode->isStorySplit);
			pp->setVisible(true);
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){
			StoryItem * tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			if(tmp->isRoot()){
				QMessageBox::information(this,"added element","can't remove a observation point from experiment");
			}
			else{
				StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(tmp->get_story()->get_label());
				ParameterPanel * pp=new ParameterPanel(true);
				pp->initialize(tmp->get_story(),current_storyNode->isStorySplit);
				pp->setVisible(true);


				//ObservationPointPanel * opp =new ObservationPointPanel(true);
				//opp->initialize(current_storyNode,current_storyNode->isStorySplit,this->currentDoc,this->doc_ressources);
				//opp->show();
			}
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
}

//Samples slot
void StoryView::add_samples(){
	QItemSelectionModel * selection = this->storytree->selectionModel();
	QModelIndex indexelementselected= selection->currentIndex();
	if(selection->isSelected(indexelementselected)){
		QVariant elementSelected = this->my_treestory->data(indexelementselected);
		StoryItem * tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(indexelementselected));
		if(tmp->isRoot()){
			QMessageBox::information(this,"added element","can't add a sample to experiment");
		}
		else{
			StoryNode * parent=this->currentDoc->get_storyboard()->findNode(elementSelected.toString());
			//QString mainname=parent->get_mainStoryName();
			//this->obsWizard=new ObservationWizard(parent->get_story(),this->currentDoc->get_storyboard());
			/*
			if (_term->get_prototype()->get_namespacealias()=="XEO"){
				tmp->add_term(_term);
				this->aboutParameter=new AboutParameter;
				this->aboutParameter->set_term(_term);
				this->aboutParameter->initialize();
				this->aboutParameter->setVisible(true);

				 //modifier pour éviter d'ajouter une variable dévelopmental ou structural dans la variablecollection d'une story.
				 //ajouter ces variables aux partitions des points d'observation des stories.
				 //ne pas oublier de vérifier l'encodage, la validité des adresses, la recopie du document Xeml à la suite du doc précedent.

				this->currentDoc->get_storyboard()->findNode_by_Label(elementSelected.toString(),mainname)->get_story()->add_variable(_term->get_prototype());
			}
			else{

			}
		*/
		}
	}
	else{
		QMessageBox::information(this,"added element","no story selected");
	}


}
void StoryView::remove_samples(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());
			//std::cerr <<"node name : " << this->currentDoc->get_storyboard()->get_storyBoard()->size() << std::endl;



			//ObservationPointPanel * opp =new ObservationPointPanel(true);
			//opp->initialize(current_storyNode,current_storyNode->isStorySplit,this->currentDoc,this->doc_ressources);
			//opp->show();
			//connect(opp,SIGNAL(on_close_window()),this,SLOT(send_refresh_story_signal()));

			//connect(opp,SIGNAL(destroyed()),this,SIGNAL(refresh_story_view(StoryView*))
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
}


//observationpoint slots
void StoryView::newObsPoint(){

}
void StoryView::choose_obsPoint(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			if (!this->GraphicScene->get_selected_story()->get_story()->get_obsPointCollection()->empty()){
				StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());
				//std::cerr <<"node name : " << this->currentDoc->get_storyboard()->get_storyBoard()->size() << std::endl;
				ObservationPointPanel * opp =new ObservationPointPanel(false);
				//connect(opp,SIGNAL())
				opp->initialize(current_storyNode,current_storyNode->isStorySplit,this->currentDoc,this->doc_ressources);
				opp->setVisible(true);
			}
			else{
				QMessageBox::information(this,"no selection","this story has no observation point to whom add samples, please add one");
			}
		}
		else{
			QMessageBox::information(this,"no selection","no story selected");
		}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){
			//QVariant elementSelected = this->my_treestory->data(indexelementselected);
			StoryItem * tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			std::cerr << "storyLabel : " << tmp->get_story()->get_label().toStdString() << std::endl;
			if(tmp->isRoot()){
				QMessageBox::information(this,"added element","can't choose a observation point from experiment");
			}
			else{
				std::cerr <<"node name : " << tmp->get_story()->get_label().toStdString() << std::endl;
				StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(tmp->get_story()->get_label());
				std::cerr <<"node name : " << this->currentDoc->get_storyboard()->get_storyBoard()->size() << std::endl;
				ObservationPointPanel * opp =new ObservationPointPanel(false);
				//connect(opp,SIGNAL())
				opp->initialize(current_storyNode,current_storyNode->isStorySplit,this->currentDoc,this->doc_ressources);
				opp->setVisible(true);
				//connect(opp,SIGNAL())


			}
		}
		else{
				QMessageBox::information(this,"no selection","no story selected");
			}
	}
}
void StoryView::add_observationPoint(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			StoryNode * node=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());
			//QString mainname=node->get_mainStoryName();
			//StoryNode  MainNode=this->currentDoc->get_storyboard()->findNode(mainname);
			int  obs_count=0;
			//std::cerr << "obs cpt : " << static_cast<XemlDocument*>(this->currentDoc)->observationPointsCounter << std::endl;
			obs_count=static_cast<XemlDocument*>(this->currentDoc)->observationPointsCounter;//  count_total_observationsPoint(MainNode,obs_count);
			//std::cerr << "obs cpt : " << obs_count << std::endl;
			ObservationPoint * obs= new ObservationPoint(this->currentDoc->get_startdate());//QDateTime::fromString(lineEdit->text(),"dd.hh:mm:ss")TimeSpanExtension::tryTimeSpanSet(lineEdit->text().toStdString()));

			static_cast<XemlDocument*>(this->currentDoc)->observationPointsCounter++,
			//_story->add_obsPoint(obs);
			obs->set_id(obs_count+1);
			node->get_story()->add_obsPoint(obs);

			emit add_observationPoint(obs);
			//this->obsPoint = new ObservationPointDialog(node->get_story(),this->currentDoc);
			//this->obsPoint->set_id(obs_count+1);
			//this->obsPoint->setVisible(true);
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){
			QVariant elementSelected = this->my_treestory->data(indexelementselected);
			StoryItem * tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			if(tmp->isRoot()){
				QMessageBox::information(this,"added element","can't add a observation point to experiment");
			}
			else{
				StoryNode * node=this->currentDoc->get_storyboard()->findNode(elementSelected.toString());
				//QString mainname=node->get_mainStoryName();
				//StoryNode  MainNode=this->currentDoc->get_storyboard()->findNode(mainname);
				int  obs_count=0;
				std::cerr << "obs cpt : " << static_cast<XemlDocument*>(this->currentDoc)->observationPointsCounter << std::endl;
				obs_count=static_cast<XemlDocument*>(this->currentDoc)->observationPointsCounter;//  count_total_observationsPoint(MainNode,obs_count);
				std::cerr << "obs cpt : " << obs_count << std::endl;
				this->obsPoint = new ObservationPointDialog(node->get_story(),this->currentDoc);
				this->obsPoint->set_id(obs_count+1);
				this->obsPoint->setVisible(true);
				//connect(this->obsPoint,SIGNAL(mon_signal(ObservationPoint )),this,SLOT(set_obsPoint_id(ObservationPoint )));
				//this->obsWizard=new ObservationWizard(parent->get_story());
				/*
				if (_term->get_prototype()->get_namespacealias()=="XEO"){
					tmp->add_term(_term);
					this->aboutParameter=new AboutParameter;
					this->aboutParameter->set_term(_term);
					this->aboutParameter->initialize();
					this->aboutParameter->setVisible(true);

					 //modifier pour éviter d'ajouter une variable dévelopmental ou structural dans la variablecollection d'une story.
					 //ajouter ces variables aux partitions des points d'observation des stories.
					 //ne pas oublier de vérifier l'encodage, la validité des adresses, la recopie du document Xeml à la suite du doc précedent.

					this->currentDoc->get_storyboard()->findNode_by_Label(elementSelected.toString(),mainname)->get_story()->add_variable(_term->get_prototype());
				}
				else{

				}
			*/
			}
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}

}
void StoryView::send_refresh_story_signal(){
	std::cerr << "entering on remove obspoint or event (StoryView) " << std::endl;
	emit refresh_story_view(this);
}

void StoryView::remove_obs_point(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());
			//std::cerr <<"node name : " << this->currentDoc->get_storyboard()->get_storyBoard()->size() << std::endl;
			ObservationPointPanel * opp =new ObservationPointPanel(true);
			opp->initialize(current_storyNode,current_storyNode->isStorySplit,this->currentDoc,this->doc_ressources);
			opp->show();
			connect(opp,SIGNAL(on_close_window()),this,SLOT(send_refresh_story_signal()));

			//connect(opp,SIGNAL(destroyed()),this,SIGNAL(refresh_story_view(StoryView*))
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){
			//QVariant elementSelected = this->my_treestory->data(indexelementselected);
			StoryItem * tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			//std::cerr << "storyLabel : " << tmp->get_story()->get_label().toStdString() << std::endl;
			if(tmp->isRoot()){
				QMessageBox::information(this,"added element","can't remove a observation point from experiment");
			}
			else{
				std::cerr <<"node name : " << tmp->get_story()->get_label().toStdString() << std::endl;
				StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(tmp->get_story()->get_label());
				std::cerr <<"node name : " << this->currentDoc->get_storyboard()->get_storyBoard()->size() << std::endl;
				ObservationPointPanel * opp =new ObservationPointPanel(true);
				opp->initialize(current_storyNode,current_storyNode->isStorySplit,this->currentDoc,this->doc_ressources);
				opp->show();
			}
		}
		else{
			QMessageBox::information(this,"added element","no story selected");
		}
	}
}
int  StoryView::count_total_observationsPoint(StoryNode * _parent,int  _number){
	for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it = _parent->get_story()->get_obsPointCollection()->begin();it!=_parent->get_story()->get_obsPointCollection()->end();++it){
		_number++;
	}
	std::cerr << "number obs parent : " << _number << std::endl;
	if(!_parent->get_childs()->empty()){
		std::cerr << "parent get childs: " << std::endl;
		for(std::list<StoryNode*>::iterator it2=_parent->get_childs()->begin();it2!=_parent->get_childs()->end();++it2){
			_number=count_total_observationsPoint((*it2),_number);
		}
	}
	return _number;

}

//event slot
void StoryView::new_event(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());
			Event * e =new Event();
			EventDialog * event=new EventDialog(false,e,this->currentDoc,current_storyNode->get_story());
			connect(event,SIGNAL(event_set(Event*)),this->graphicStory,SLOT(add_event(Event*)));
			event->setVisible(true);
		}
		else{
			QMessageBox::information(this,"no selection","no story selected");
		}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){


			//QVariant elementSelected = this->my_treestory->data(indexelementselected);
			//std::cerr << elementSelected.toString().toStdString() << std::endl;
			StoryItem * tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			if(tmp->isRoot()){
				QMessageBox::information(this,"root exception","can't add an event to experiment");
			}
			else{
				Event * e =new Event();
				EventDialog * event=new EventDialog(false,e,this->currentDoc,tmp->get_story());
				//this->splitstorydialog = new StorySplitDialog(elementSelected);

				event->setVisible(true);
			}
		}
		else{
			QMessageBox::information(this,"no selection","no story selected");
		}
	}
}
//function obsolete
void StoryView::add_event(QString _storyName,QString _label,QDateTime _datetime){
	std::cerr << "entering add event" << std::endl;
	StoryNode * parent=this->currentDoc->get_storyboard()->findNode(_storyName);
	if(parent!=NULL){
		std::cerr << "event will be created" << std::endl;

		Event * e=new Event(_datetime);
		e->set_label(_label);

		parent->get_story()->add_event(e);
	}
}

void StoryView::remove_event(){
	if(GraphicMode){
		if(this->GraphicScene->get_selected_story()!=NULL){
			StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());

			EventPanel * eventInfo=new EventPanel(true);
			eventInfo->initialize(this->currentDoc,current_storyNode->get_story(),current_storyNode->get_isStorySplit());
			eventInfo->setVisible(true);
			connect(eventInfo,SIGNAL(on_close_window()),this,SLOT(send_refresh_story_signal()));
		}
		else{
			QMessageBox::information(this,"no selection","no story selected");
		}
	}
	else{
		QItemSelectionModel * selection = this->storytree->selectionModel();
		QModelIndex indexelementselected= selection->currentIndex();
		if(selection->isSelected(indexelementselected)){


			QVariant elementSelected = this->my_treestory->data(indexelementselected);
			//std::cerr << elementSelected.toString().toStdString() << std::endl;
			StoryItem * tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(indexelementselected));
			if(tmp->isRoot()){
				QMessageBox::information(this,"root exception","can't add an event to experiment");
			}
			else{

				EventPanel * eventInfo=new EventPanel(true);
				eventInfo->initialize(this->currentDoc,tmp->get_story(),tmp->get_isStorySplit());
				eventInfo->setVisible(true);
			}
		}
		else{
				QMessageBox::information(this,"no selection","no story selected");
			}
	}


}
void StoryView::edit_event(){
	if(this->GraphicScene->get_selected_event()!=NULL){
		StoryNode * current_storyNode=this->currentDoc->get_storyboard()->findNode(this->GraphicScene->get_selected_story()->get_label());

		Event * event=this->GraphicScene->get_selected_event()->get_event();
		EventDialog * eventdialog=new EventDialog(true,event,this->currentDoc,current_storyNode->get_story());
		connect(eventdialog,SIGNAL(event_edited()),eventdialog,SLOT(close()));
		eventdialog->setVisible(true);



	}

}














/*
void StoryView::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	//painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
	painter.setPen(QPen(Qt::black, 4,Qt::SolidLine, Qt::RoundCap));
	painter.setBrush(QBrush(Qt::cyan, Qt::SolidPattern));
	painter.drawRect(50,80,700,100);

	//painter.drawEllipse(80, 80, 400, 240);

}
*/
