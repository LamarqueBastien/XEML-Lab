#include "parametertreeview.h"

ParameterTreeView::ParameterTreeView(bool _drag_and_drop_mode,DocumentResources * _doc,QWidget *parent) :
	QWidget(parent)
{
	this->doc_ressources=_doc;

	this->mode=false;
	this->drag_and_drop_mode=_drag_and_drop_mode;
	if (drag_and_drop_mode){
		this->draggableParameterTree=new ParameterView;
		//this->draggableParameterTree->setAnimated(true);
		this->draggableParameterTree->setObjectName("VariableTree");
		this->draggableParameterTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
		//this->draggableParameterTree->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
		this->draggableParameterTree->setAcceptDrops(true);
		this->draggableParameterTree->setDragEnabled(true);
		this->draggableParameterTree->header()->setWindowTitle("ontologies");
		//this->draggableParameterTree->header()->setStretchLastSection(true);
		//this->draggableParameterTree->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
		this->draggableParameterTree->setItemsExpandable(true);
		this->draggableParameterTree->setAnimated(true);
		connect(this->draggableParameterTree,SIGNAL(entered(QModelIndex)),this,SLOT(resize_column(QModelIndex)));


	}
	else{
		this->parameterTree=new QTreeView;
		this->parameterTree->setAnimated(true);
		//this->parameterTree->setSelectionMode(QAbstractItemView::MultiSelection);
		this->parameterTree->setObjectName("VariableTree");
		this->parameterTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
		this->setMinimumWidth(850);

	}


	//this->parameterTree->setItemsExpandable(true);
	//this->parameterTree->set
	this->searchLabel=new QLabel("Search term");
	this->search=new QLineEdit;
	this->searchLabel->setBuddy(search);
	connect(this->search,SIGNAL(textChanged(QString)),this,SLOT(search_term(QString)));
	//this->parameterTree->setStyleSheet("QTreeView {background-color: rgb(104,157,113);");


	//this->setStyleSheet("QWidget { background-color: rgb(255,255,255); }");
	//Users/benjamindartigues/GraphicView/Images/XemlLogo.png
	//"background-image: url(/Users/benjamindartigues/Pictures/BlueMetal.png);"
	//this->setStyleSheet(styleSheet());

	this->my_treeparameter= new QStandardItemModel;

	this->parameterInfo = new QPushButton("get definition variable");

	this->addParameter = new QPushButton("add variable");

	this->addOntology = new QPushButton("manage ontology");

	this->parameterInfo->setCursor(Qt::PointingHandCursor);
	this->addParameter->setCursor(Qt::PointingHandCursor);
	this->addOntology->setCursor(Qt::PointingHandCursor);





	QHBoxLayout * searchLayout=new QHBoxLayout;
	searchLayout->addWidget(searchLabel);
	searchLayout->addWidget(search);

	QDialogButtonBox * buttonBox = new QDialogButtonBox(QDialogButtonBox::Help);
	if(drag_and_drop_mode){
		buttonBox->addButton(this->addOntology,QDialogButtonBox::ActionRole);
	}
	else{
		buttonBox->addButton(this->addParameter,QDialogButtonBox::ActionRole);

	}

	connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(show_help()));
	//buttonBox->addButton(this->addParameter,QDialogButtonBox::ActionRole);
	//buttonBox->addButton(this->parameterInfo,QDialogButtonBox::ActionRole);


	QVBoxLayout * layout = new QVBoxLayout;
	layout->addLayout(searchLayout);
	if (drag_and_drop_mode){
		layout->addWidget(this->draggableParameterTree);
		//layout->addWidget(buttonBox);
	}
	else{
		layout->addWidget(this->parameterTree);
		//layout->addWidget(this->addParameter);


	}
	layout->addWidget(buttonBox);
	/*
	layout->addWidget(this->addOntology);
	layout->addWidget(this->addParameter);
	layout->addWidget(this->parameterInfo);
*/
	QString WindowObjectName("OntologyTree");
	this->setObjectName(WindowObjectName);
	this->setAcceptDrops(true);
	setLayout(layout);

	connect(addParameter,SIGNAL(clicked()),this,SLOT(add_parameter()));
	connect(addOntology,SIGNAL(clicked()),this,SLOT(add_ontology()));
	connect(parameterInfo,SIGNAL(clicked()),this,SLOT(showSelection()));

}
void ParameterTreeView::resize_column(QModelIndex _index){
	Q_UNUSED(_index);
	//std::cerr << "resize column" << std::endl;
	this->draggableParameterTree->resizeColumnToContents(0);

}

void ParameterTreeView::show_help(){

	QString HtmlString="";
	if(drag_and_drop_mode){
		HtmlString="<h2>Ontologies helper</h2>"
				   "<h3>add or remove term</h3>"
				   "<ul>"
				   "<li> Search a term in the ontology tree and drag it to the story view (Variables with one or more child cannot be dragged). you nedd to select a story first. </li>"
				   "<li> click on \"remove variable\" in the story view and select the term to remove by clicking on the row number (to select all columns). </li>"
				   "</ul>"
				   "<h3>Manage Ontologies</h3>"
				   "<ul>"
				   "<li> You can select which ontology you want to add to your document by check/uncheck related ontology checkbox. </li>"
				   "<li> click on \"remove observation point\" to remove a observation point. </li>"
				   "</ul>"
				   "<h3>Search a specific term</h3>"
				   "<ul>"
				   "<li> Enter the term you search in the search field to get automatically the right term without searching in all trees. </li>"
				   "</ul>";
	}
	else{
		HtmlString="<h2>Ontologies helper</h2>"
				   "<h3>add or remove term</h3>"
				   "<ul>"
				   "<li> Search a term in the ontology tree and drag it to the story view (Variables with one or more child cannot be dragged). you nedd to select a story first. </li>"
				   "<li> click on \"remove variable\" in the story view and select the term to remove by clicking on the row number (to select all columns). </li>"
				   "</ul>"
				   "<h3>Search a specific term</h3>"
				   "<ul>"
				   "<li> Enter the term you search in the search field to get automatically the right term without searching in all trees. </li>"
				   "</ul>";
	}

	QMessageBox::about(this,"Ontology helper",HtmlString);


}

bool                                       ParameterTreeView::contains(TermNode * _node,std::list<TermNode*> * _processed_nodes,QString _namespace){
	//std::cerr << "entering contains" << std::endl;
	if(_namespace=="XEO_Positioning"){
		for(std::list<TermNode*>::iterator it=_processed_nodes->begin();it!=_processed_nodes->end();++it){
			if((*it)->get_label()==_node->get_label()){
				return true;


			}
		}
		return false;
	}

	else{

		for(std::list<TermNode*>::iterator it=_processed_nodes->begin();it!=_processed_nodes->end();++it){
			if((*it)->get_label()+" ("+(*it)->get_term()->get_termId()+")"==_node->get_label()+" ("+_node->get_term()->get_termId()+")"){
				return true;

			}
		}
		return false;
	}
}
void ParameterTreeView::search_term(QString _term){
	if(drag_and_drop_mode){
		this->draggableParameterTree->expandAll();
		this->draggableParameterTree->keyboardSearch(_term);
	}
	else{
		this->parameterTree->expandAll();
		this->parameterTree->keyboardSearch(_term);
	}


}

void ParameterTreeView::add_ontology(){
	std::cerr << "entering add_ontology()" << std::endl;
	OntologyPanel * onto=new OntologyPanel;
	onto->initialize(this->doc_ressources);
	onto->show();
	connect(onto,SIGNAL(ontologies_to_load(bool,bool,bool)),this,SLOT(send_ontologies(bool,bool,bool)));
}
void ParameterTreeView::send_ontologies(bool _xeoIsChecked,bool _eoIsChecked,bool _envoIsChecked){
	std::cerr << "emit ontology_to_load" << std::endl;
	emit ontology_to_load(_xeoIsChecked,_eoIsChecked,_envoIsChecked);
}
void ParameterTreeView::buildNodeHierarchy(TermNode * node,QString _namespace){
	if(node->get_parent()==NULL){
		this->my_treeparameter->findItems(_namespace,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(new ParameterItem(_namespace,node,node->get_label(),node->get_term(),true));
		for(std::list<AttributeRelation<TermNode*>*>::iterator it=node->get_childs()->begin();it!=node->get_childs()->end();++it){
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




	if(drag_and_drop_mode){
		//this->draggableParameterTree->header()->resizeSections(QHeaderView::ResizeToContents);//->setResizeMode(0, QHeaderView::ResizeToContents);
		//this->parameterTree->header()->setStretchLastSection(false);
		this->my_treeparameter->setHeaderData(0,Qt::Horizontal,"ontologies",Qt::DisplayRole);
		this->draggableParameterTree->setModel(this->my_treeparameter);
		this->draggableParameterTree->setMouseTracking(true);
		//this->draggableParameterTree->header()->setHorizontalScrollMode();
		//this->draggableParameterTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
		this->draggableParameterTree->setIndentation(20);
	}
	else{
		//this->parameterTree->header()->resizeSections(QHeaderView::ResizeToContents);//->setResizeMode(0, QHeaderView::ResizeToContents);
		//this->parameterTree->header()->setStretchLastSection(false);
		this->parameterTree->setModel(this->my_treeparameter);
		this->parameterTree->setMouseTracking(true);
		this->parameterTree->header()->hide();
	}

}

void ParameterTreeView::showSelection()
{
	QItemSelectionModel * selection;
	if(drag_and_drop_mode){
			selection = this->draggableParameterTree->selectionModel();
	}
	else{
			selection = this->parameterTree->selectionModel();
	}

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
	QItemSelectionModel * selection;
	std::cerr << "entering add_parameter (ParameterTreeView)" << std::endl;
	if(drag_and_drop_mode){
			selection = this->draggableParameterTree->selectionModel();
	}
	else{
		///here add multiple selection for new Observation Wizard
			//QModelIndexList  listeSelections = selection->selectedIndexes();

			selection = this->parameterTree->selectionModel();
	}


	QModelIndex indexelementselected= selection->currentIndex();
	if(selection->isSelected(indexelementselected)){
		std::cerr << "is selected (ParameterTreeView)" << std::endl;

		//QVariant elementSelected = this->my_treeparameter->data(indexelementselected);
		ParameterItem * tmp =static_cast<ParameterItem*>(this->my_treeparameter->itemFromIndex(indexelementselected));
		if(tmp!=NULL){
			/*
			if(tmp->isRoot){
				QMessageBox::information(this,"added element","can't add a root term "+ tmp->get_term()->get_prototype()->get_name()+ " to a story");
			}
			else{
			*/
			std::cerr << "emit message on parameterselected (ParameterTreeView) for :" << tmp->get_term()->get_termId().toStdString() << std::endl;
				//modifer le signal pour qu'il envoie une liste de terms.
				/*
				for(std::map<ValueBase*,QString>::iterator it=static_cast<VariableTerm*>(tmp->get_term()->get_prototype())->get_valuecollection()->begin();it!=static_cast<VariableTerm*>(tmp->get_term()->get_prototype())->get_valuecollection()->end();++it){
					//values->append(static_cast<Value*>((*it).first)->get_val());
					if(static_cast<Value*>((*it).first)->get_context()=="Quantity"){
						std::cerr << "Qvalue : " << static_cast<Value*>((*it).first)->get_val().toStdString() << std::endl;
					}
				}
				*/
			emit onParameterselected(tmp->get_term());
			//}
		}
	}
}
