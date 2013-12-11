#include "parametertreeview.h"

ParameterTreeView::ParameterTreeView(DocumentResources * _doc,QWidget *parent) :
	QWidget(parent)
{
	this->doc_ressources=_doc;
	QVBoxLayout * layout = new QVBoxLayout;
	this->mode=false;
	this->parameterTree=new QTreeView;
	this->parameterTree->setAnimated(true);
	//this->parameterTree->setItemsExpandable(true);
	//this->parameterTree->set
	this->searchLabel=new QLabel("Search term");
	this->search=new QLineEdit;
	this->searchLabel->setBuddy(search);
	connect(this->search,SIGNAL(textChanged(QString)),this,SLOT(search_term(QString)));
	this->parameterTree->setStyleSheet("QTreeView {background-color: rgb(104,157,113);");

	this->parameterTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	//this->setStyleSheet("QWidget { background-color: rgb(255,255,255); }");
	//Users/benjamindartigues/GraphicView/Images/XemlLogo.png
	//"background-image: url(/Users/benjamindartigues/Pictures/BlueMetal.png);"
	//this->setStyleSheet(styleSheet());

	this->my_treeparameter= new QStandardItemModel;
	//this->parameterTree->setStyleSheet("QTreeView::item {border: 1px solid #d9d9d9;border-top-color: transparent;border-bottom-color: transparent;}");

	//*this->parameterTree->setStyleSheet("QTreeView::item:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e7effd, stop: 1 #cbdaf1);border: 1px solid #bfcde4;}");

	//this->parameterTree->setStyleSheet("background-color: rgb(104,157,113);");

	//*this->parameterTree->setStyleSheet("background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);");

	//this->parameterTree->setStyleSheet("QTreeView::item:selected {border: 1px solid #567dbc;}");

	//this->parameterTree->setStyleSheet("QTreeView::item:selected:active{background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6ea1f1, stop: 1 #567dbc);}");
	//this->parameterTree->setStyleSheet("QTreeView::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6b9be8, stop: 1 #577fbf);}");
	this->parameterInfo = new QPushButton("get definition variable");
	//this->parameterInfo->style()->standardPalette().setColor(QPalette::Normal,QPalette::Background,QColor(Qt::blue));
	//this->parameterInfo->setBackgroundRole(QPalette::Light);
	this->parameterInfo->setStyleSheet("QPushButton {"
				"background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
				"border-style: outset;"
				"border-width: 2px;"
				"border-radius: 10px;"
				"border-color: beige;"
				"font: bold 12px;"
				"color:black;"
				"min-width: 8em;"
				"min-height: 0.75em;"
			   " margin: 0 1px 0 1px;"
				"color:rgb(0,0,0);"
				"padding: 6px;}"
			);//->setStyleSheet("background-color: rgb(255,255,255)");
	this->addParameter = new QPushButton("add variable");
	this->addParameter->setStyleSheet(
				"background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
				"border-style: outset;"
				"border-width: 2px;"
				"border-radius: 10px;"
				"border-color: beige;"
				"font: bold 12px;"
				"color:black;"
				"min-width: 8em;"
				"min-height: 0.75em;"
			   " margin: 0 1px 0 1px;"
				"color:rgb(0,0,0);"
				"padding: 6px;"
			);//->setStyleSheet("background-color: rgb(255,255,255)");
	this->addOntology = new QPushButton("manage ontology");
	//QGraphicsDropShadowEffect * dse = new QGraphicsDropShadowEffect();
	//dse->setBlurRadius(10);
	//addOntology->setGraphicsEffect(dse);
	//this->addOntology->setStyleSheet("background-color: rgb(255,255,255);""border-radius: 15px;");
	addOntology->setStyleSheet(
				 "background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
				 "border-style: outset;"
				 "border-width: 2px;"
				 "border-radius: 10px;"
				 "border-color: beige;"
				 "font: bold 12px;"
				 "color:black;"
				 "min-width: 8em;"
				 "min-height: 0.75em;"
				" margin: 0 1px 0 1px;"
				 "color:rgb(0,0,0);"
				 "padding: 6px;"
			 );
	this->parameterInfo->setCursor(Qt::PointingHandCursor);
	this->addParameter->setCursor(Qt::PointingHandCursor);
	this->addOntology->setCursor(Qt::PointingHandCursor);
	QHBoxLayout * searchLayout=new QHBoxLayout;
	searchLayout->addWidget(searchLabel);
	searchLayout->addWidget(search);
	layout->addLayout(searchLayout);
	layout->addWidget(this->parameterTree);
	layout->addWidget(this->addOntology);
	layout->addWidget(addParameter);
	layout->addWidget(parameterInfo);

	QString WindowObjectName("OntologyTree");
	this->setObjectName(WindowObjectName);
	this->setStyleSheet("QWidget#"+WindowObjectName +"{background-color: rgb(225,206,154);}"+"QToolTip { color: #fff; background-color: #000; border: none; }");
	setLayout(layout);
	//this->setStyleSheet("background-color: rgb(104,157,113);");
					//"background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
					//"background-color: rgb(225,206,154);"
	/*
					"background-color: rgb(104,157,113);"
					"border-style: outset;"
					"border-width: 1px;"
					"border-radius: 10px;"
					"border-color: beige;"
					"font: bold 12px;"
					"color:black;"
					"min-width: 8em;"
					"min-height: 0.95em;"
					"margin: 0 1px 0 1px;"
					"color:rgb(0,0,0);"
					"padding: 15px;"
				);
				*/
	connect(addParameter,SIGNAL(clicked()),this,SLOT(add_parameter()));
	connect(addOntology,SIGNAL(clicked()),this,SLOT(add_ontology()));
	connect(parameterInfo,SIGNAL(clicked()),this,SLOT(showSelection()));

}
//void ParameterTreeView::paintEvent(QPaintEvent *){
	//QStyleOption opt;
	//opt.init(this);
	//QPainter p(this);
	//style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
//}
bool                                       ParameterTreeView::contains(TermNode * _node,std::list<TermNode*> * _processed_nodes,QString _namespace){
	//std::cerr << "entering contains" << std::endl;
	if(_namespace=="XEO_Positioning"){
		for(std::list<TermNode*>::iterator it=_processed_nodes->begin();it!=_processed_nodes->end();++it){
			//std::cerr << "loop turn" << std::endl;
			if((*it)->get_label()==_node->get_label()){
				//std::cerr << "true" << std::endl;
				return true;


			}
		}
		//std::cerr << "false" << std::endl;
		return false;
	}

	else{

		for(std::list<TermNode*>::iterator it=_processed_nodes->begin();it!=_processed_nodes->end();++it){
			if((*it)->get_label()+" ("+(*it)->get_term()->get_termId()+")"==_node->get_label()+" ("+_node->get_term()->get_termId()+")"){
				return true;
				//std::cerr << "true" << std::endl;

			}
		}
		//std::cerr << "false" << std::endl;
		return false;
	}
}
void ParameterTreeView::search_term(QString _term){
	this->parameterTree->expandAll();
	this->parameterTree->keyboardSearch(_term);
	//this->parameterTree->keyboardGrabber();

}

void ParameterTreeView::add_ontology(){
	std::cerr << "entering add_ontology()" << std::endl;
	OntologyPanel * onto=new OntologyPanel;
	//std::cerr << this->doc_ressources->get_xeoHandler()->size()<< std::endl;
	//if(this->doc_ressources->contains("XEO"))
	onto->initialize(this->doc_ressources);
	onto->show();
	connect(onto,SIGNAL(ontologies_to_load(bool,bool,bool)),this,SLOT(send_ontologies(bool,bool,bool)));
}
void ParameterTreeView::send_ontologies(bool _xeoIsChecked,bool _eoIsChecked,bool _envoIsChecked){
	emit ontology_to_load(_xeoIsChecked,_eoIsChecked,_envoIsChecked);
}
void ParameterTreeView::buildNodeHierarchy(TermNode * node,QString _namespace){
	if(node->get_parent()==NULL){
		this->my_treeparameter->findItems(_namespace,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(new ParameterItem(_namespace,node,node->get_label(),node->get_term(),true));
		for(std::list<AttributeRelation<TermNode*>*>::iterator it=node->get_childs()->begin();it!=node->get_childs()->end();++it){
			//if(findNode((*it)->relation,termId)!=NULL){
		//for (std::list<TermNode*>::iterator it = node->get_childs()->begin();it!=node->get_childs()->end();++it){
			buildNodeHierarchy((*it)->relation,node->get_label());
		}
	}

	else{
		this->my_treeparameter->findItems(_namespace,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(new ParameterItem(_namespace,node,node->get_label(),node->get_term(),false));

	}



}

void ParameterTreeView::buildNodeHierarchy(TermNode * node,std::list<TermNode*> * _processed_nodes, ParameterItem * _tmp_item,QString _namespace){


	_processed_nodes->push_back(node);
	_tmp_item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	if(node->get_parent()!=NULL && !contains(node->get_parent(),_processed_nodes,_namespace)){

		if(this->my_treeparameter->findItems(node->get_parent()->get_label(),Qt::MatchFixedString | Qt::MatchRecursive,0).size()!=0)
		{
			this->my_treeparameter->findItems(node->get_parent()->get_label(),Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);

		}
		else
		{


			ParameterItem *tmp_item1=new ParameterItem(_namespace,node->get_parent(),node->get_parent()->get_label(),node->get_parent()->get_term(),true);
			tmp_item1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			tmp_item1->appendRow(_tmp_item);
			buildNodeHierarchy(node->get_parent(),_processed_nodes,tmp_item1,_namespace);
		}
	}
	else{
		if(node->get_parent()!=NULL){
			if(_namespace=="XEO_Positioning"){
				this->my_treeparameter->findItems(node->get_parent()->get_label(),Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);

			}

			else{
				this->my_treeparameter->findItems(node->get_parent()->get_label()+" ("+node->get_parent()->get_term()->get_termId()+")",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);

			}
		}
		else{

			_tmp_item->set_isRoot(true);
			this->my_treeparameter->findItems(_namespace,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);
			_processed_nodes->push_back(node);

		}
	}


}
void ParameterTreeView::build_ontology_tree(std::list<TermNode*> * _my_tree,QString _namespace){
	if(mode){
		for(std::list<TermNode*>::iterator it=_my_tree->begin();it!=_my_tree->end();++it){
			if(_namespace=="XEO_Positioning"){
			}
			if((*it)->get_parent()==NULL){
				buildNodeHierarchy((*it),_namespace);
			}
		}

	}
	else{
		std::list<TermNode*> processed_nodes;

		for(std::list<TermNode*>::iterator it=_my_tree->begin();it!=_my_tree->end();++it){

			if((*it)->get_parent()!=NULL && (*it)->get_childs()->size()==0){
				if(_namespace=="XEO_Positioning"){
				}

				buildNodeHierarchy((*it),&processed_nodes,new ParameterItem(_namespace,(*it),(*it)->get_label(),(*it)->get_term(),false),_namespace);
			}
		}
	}
}
void ParameterTreeView::clean_tree(){
	my_treeparameter->clear();
}
void ParameterTreeView::set_up_Ontologytree(DocumentResources * _doc,QStringList  * _ontologies){

	for(int i = 0;i<_ontologies->size();i++){
		if(_doc->contains(_ontologies->at(i),Xeml::Document::Contracts::Environment)){
			std::list<TermNode*> my_xeotree=(*static_cast<XeoHandler*>((*_doc->get_xeoHandler())[_ontologies->at(i)]->get_handler())->get_listNodes());
			ParameterItem * root_parameter=new ParameterItem(NULL,_ontologies->at(i),true);
			root_parameter->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			my_treeparameter->appendRow(root_parameter);
			build_ontology_tree(&my_xeotree,_ontologies->at(i));
		}
		if(_doc->contains(_ontologies->at(i),Xeml::Document::Contracts::Developmental)){
			std::list<TermNode*> my_devtree=(*static_cast<DevelopmentalOntologyHandler*>((*_doc->get_devHandler())[_ontologies->at(i)]->get_handler())->get_listNodes());
			my_treeparameter->appendRow(new ParameterItem(NULL,_ontologies->at(i),true));
			build_ontology_tree(&my_devtree,_ontologies->at(i));
		}

		if(_doc->contains(_ontologies->at(i),Xeml::Document::Contracts::OrganismStructure)){
			std::list<TermNode*> my_structree=(*static_cast<PlantStructureOntologyHandler*>((*_doc->get_structHandler())[_ontologies->at(i)]->get_handler())->get_listNodes());
			my_treeparameter->appendRow(new ParameterItem(NULL,_ontologies->at(i),true));
			build_ontology_tree(&my_structree,_ontologies->at(i));
		}
		if(_doc->contains(_ontologies->at(i),Xeml::Document::Contracts::Positioning)){
			std::list<TermNode*> my_postree=(*static_cast<PositioningOntologyHandler*>((*_doc->get_posHandler())[_ontologies->at(i)]->get_handler())->get_listNodes());
			my_treeparameter->appendRow(new ParameterItem(NULL,_ontologies->at(i),true));
			build_ontology_tree(&my_postree,_ontologies->at(i));
		}


		if(_doc->contains(_ontologies->at(i),Xeml::Document::Contracts::EO)){
			std::list<TermNode*> my_EOtree=(*static_cast<PEOHandler*>((*_doc->get_EOHandler())[_ontologies->at(i)]->get_handler())->get_listNodes());
			my_treeparameter->appendRow(new ParameterItem(NULL,_ontologies->at(i),true));
			build_ontology_tree(&my_EOtree,_ontologies->at(i));
		}
		if(_doc->contains(_ontologies->at(i),Xeml::Document::Contracts::EnvO)){
			std::list<TermNode*> my_EnvOtree=(*static_cast<EnvOHandler*>((*_doc->get_EnvOHandler())[_ontologies->at(i)]->get_handler())->get_listNodes());
			my_treeparameter->appendRow(new ParameterItem(NULL,_ontologies->at(i),true));
			build_ontology_tree(&my_EnvOtree,_ontologies->at(i));
		}
	}




	this->parameterTree->header()->resizeSections(QHeaderView::ResizeToContents);//->setResizeMode(0, QHeaderView::ResizeToContents);
	//this->parameterTree->header()->setStretchLastSection(false);
	this->parameterTree->setModel(this->my_treeparameter);
	this->parameterTree->setMouseTracking(true);
	this->parameterTree->header()->hide();
}

void ParameterTreeView::showSelection()
{
	QItemSelectionModel * selection = this->parameterTree->selectionModel();
	QModelIndex indexelementselected= selection->currentIndex();
	if(selection->isSelected(indexelementselected)){
		ParameterItem * tmp =static_cast<ParameterItem*>(this->my_treeparameter->itemFromIndex(indexelementselected));
		QVariant elementSelected = this->my_treeparameter->data(indexelementselected);

		/*
		if(tmp->isRoot){
			QMessageBox::information(this,"added element","can't have information , root term");
		}
		else{
		}
		*/
		//if (tmp->column()!=0){
			if (tmp->get_term()->get_definition()!="" || !(tmp->get_term()->get_definition().isEmpty())){
				QMessageBox::information(this,"selected element",tmp->get_term()->get_definition());
			}
			else{
				QMessageBox::information(this,"selected element","No definition");
			}
		//}
	}
	else{
		QMessageBox::information(this,"added element","no parameter selected");
	}
}
void ParameterTreeView::add_parameter()
{
	QItemSelectionModel * selection = this->parameterTree->selectionModel();
	QModelIndex indexelementselected= selection->currentIndex();
	if(selection->isSelected(indexelementselected)){
		QVariant elementSelected = this->my_treeparameter->data(indexelementselected);
		ParameterItem * tmp =static_cast<ParameterItem*>(this->my_treeparameter->itemFromIndex(indexelementselected));
		if(tmp->isRoot){
			QMessageBox::information(this,"added element","can't add a root term "+ tmp->get_term()->get_prototype()->get_name()+ " to a story");
		}
		else{


			emit onParameterselected(tmp->get_term());
		}
	}
}
