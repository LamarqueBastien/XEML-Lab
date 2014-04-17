#include "observationdetailspage.h"

ObservationDetailsPage::ObservationDetailsPage(DocumentResources * _doc_resources,StoryNode * _root,QWidget *parent)

	: QWizardPage(parent)
{

	this->root_node=_root;
	observations_tmp= ObservationWizard::get_observations();
	//std::cerr << "obs_tmp size : " << this->observations_tmp->size() << std::endl;
	pools=new std::vector<IndividualsPool*>();


	this->doc_resources =_doc_resources;
	setTitle(tr("Observation"));
	setSubTitle(tr("Specify developmental stage conditions about your samples"));



	//QString numbers_of_partitions_question("How many Part of the plant do you want to observe ?");
	//QString numbers_of_individuals_question("How many individuals are concerned by these observation ?");
	//my_treeView= new ParameterTreeView(false,this->doc_resources);
	//connect(this->my_treeView,SIGNAL(onParameterselected(ItfOntologyTerm*)),this,SLOT(get_term(ItfOntologyTerm*)));




	this->add_observation=new QPushButton("add observation");
	connect(this->add_observation,SIGNAL(clicked()),this,SLOT(add_obs()));


	//germplasm = new QLabel;
	//germLabel = new QLabel("GermPlasm");
	//germLabel->setBuddy(germplasm);

	//termEdit = new QLineEdit;
	//termLabel = new QLabel("term id");
	//termLabel->setBuddy(termEdit);

	//nameEdit = new QLineEdit;
	//nameLabel = new QLabel("term name");


	//destructCheckBox= new QCheckBox("Destructive observation");
	//new_individuals_box=new QCheckBox("new individuals");
	//existing_individuals=new QCheckBox("existing individuals");
	//this->pool=new QCheckBox("pooling");



	//Individuals = new QLabel("Individual") ;
	//this->IndBox=new QSpinBox;
	//Individuals->setBuddy(this->IndBox);


	QHBoxLayout * mainlayout=new QHBoxLayout;
	//mainlayout->addWidget(this->my_treeView);
	QVBoxLayout *layout = new QVBoxLayout;

	//QHBoxLayout * GPLayout = new QHBoxLayout;
	//GPLayout->addWidget(this->germLabel);
	//GPLayout->addStretch(1);
	//GPLayout->addWidget(this->germplasm);
	//layout->addLayout(GPLayout);

	//layout->addWidget(destructCheckBox);
	//layout->addWidget(pool);

	tabs=new QTabWidget();
	obs_counter=1;
	QString testr="observations set"+QString::number(obs_counter);
	//QTreeView * tree=new QTreeView;
	//QStandardItemModel * model = new QStandardItemModel;
	//my_treeparameter->appendColumn();
	//model->appendRow(new QStandardItem("Individuals"));
	//tree->setModel(model);

	//std::cerr << "pool size before :" << this->pools->size() << std::endl;
	ObservationDetails * obspage=new ObservationDetails(this->doc_resources,this->root_node,this->pools,this);
	this->observations_tmp->push_back(obspage);
	tabs->addTab(obspage,testr);
	layout->addWidget(tabs);
	layout->addWidget(add_observation);
	setWindowFlags(Qt::WindowStaysOnTopHint);


/*
	QHBoxLayout * individualLayout = new QHBoxLayout;
	individualLayout->addWidget(Individuals);
	individualLayout->addStretch(1);
	individualLayout->addWidget(this->IndBox);
	layout->addLayout(individualLayout);

	QHBoxLayout * poolLayout = new QHBoxLayout;
	poolLayout->addWidget(new_individuals_box);
	poolLayout->addStretch(1);
	poolLayout->addWidget(existing_individuals);
	layout->addLayout(poolLayout);


	QHBoxLayout * termLayout = new QHBoxLayout;
	termLayout->addWidget(termLabel);
	termLayout->addStretch(1);
	termLayout->addWidget(termEdit);
	layout->addLayout(termLayout);

	QHBoxLayout * nameLayout = new QHBoxLayout;
	nameLayout->addWidget(nameLabel);
	nameLayout->addStretch(1);
	nameLayout->addWidget(nameEdit);
	layout->addLayout(nameLayout);
	*/

	mainlayout->addLayout(layout);
	setLayout(mainlayout);


	//registerField("Destructive*",this->destructCheckBox);
	//registerField("Pooling*",this->pool);
	//registerField("DevTermId*",this->termEdit);
	//registerField("Individuals*",this->IndBox);
	//registerField("Duration*",timeDurationEdit);
	//registerField("DevName*",nameEdit);

}
void ObservationDetailsPage::initializePage(){
	//this->germplasm =field("GermPlasm").toString();
	//this->germplasmEdit->setText(this->germplasm);


	QModelIndexList list=static_cast<QItemSelectionModel*>(field("genViewSelection").value<QItemSelectionModel*>())->selectedRows();
	//QVariant selectedElement = this->genModel->data(_QMI, Qt::DisplayRole);
	//this->germPlasmEdit->setText(selectedElement.toString());
	QString germ="";
	for(int i=0;i<list.size();i++){

		germ+="("%list.at(i).data().toString()%")";
		for (std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->root_node->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->root_node->get_story())->get_individualspoolcollection()->end();++it){
			if (static_cast<IndividualsPool*>((*it).first)->get_germplasm()==list.at(i).data().toString()){
				this->pools->push_back((*it).first);
			}
		}

		//std::cerr << "initialization :" << this->pools->size() << std::endl;

		//pools->push_back(list.at(i).data().toString());
	}

	for (int j=0;j<this->observations_tmp->size();j++){
		//std::cerr << "in da loop j = " << j << std::endl;
		static_cast<ObservationDetails*>(this->observations_tmp->at(j))->initialize_table(this->pools);
	}



	//this->germplasmEdit->setText(germ);
	//QStringList * dev_onto = new QStringList;
	//dev_onto->append("PO_Development");
	//this->my_treeView->set_up_Ontologytree(this->doc_resources,dev_onto);
}
void ObservationDetailsPage::add_obs(){
	obs_counter++;
	//ParameterTreeView * tmp = new ParameterTreeView(false,this->doc_resources);
	//QStringList * dev_onto = new QStringList;
	//dev_onto->append("PO_Development");
	//tmp->set_up_Ontologytree(this->doc_resources,dev_onto);
	QString tmp_string="observations set"+QString::number(obs_counter);
	ObservationDetails * obspage=new ObservationDetails(this->doc_resources,root_node,this->pools,this);
	obspage->initialize_table(pools);
	this->observations_tmp->push_back(obspage);
	this->tabs->addTab(obspage,tmp_string);

}

void ObservationDetailsPage::get_term(ItfOntologyTerm * _term){
	//this->termEdit->setText(_term->get_termId());
	//this->nameEdit->setText(_term->get_prototype()->get_name());
}

/*
bool ObservationDetailsPage::contains(TermNode * _node,std::list<TermNode*> * _processed_nodes,QString _namespace){
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
void ObservationDetailsPage::build_dev_tree(std::list<TermNode*> * _my_tree,QString _namespace){
	std::cerr << "entering build onto tree (parameter tree view)" << std::endl;
	std::list<TermNode*> processed_nodes;

	for(std::list<TermNode*>::iterator it=_my_tree->begin();it!=_my_tree->end();++it){

		if((*it)->get_parent()!=NULL && (*it)->get_childs()->size()==0){

			buildNodeHierarchy((*it),&processed_nodes,new ParameterItem(_namespace,(*it),(*it)->get_label(),(*it)->get_term(),false),_namespace);
		}
	}
}
void ObservationDetailsPage::buildNodeHierarchy(TermNode * node,std::list<TermNode*> * _processed_nodes, ParameterItem * _tmp_item,QString _namespace){
	//std::cerr << "entering build node hierarchy" << std::endl;
	_processed_nodes->push_back(node);
	_tmp_item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	if(node->get_parent()!=NULL && !contains(node->get_parent(),_processed_nodes,_namespace)){
		//std::cerr << "parent not null and parent not contains in processed nodes" << std::endl;
		if(this->my_treeparameter->findItems(node->get_parent()->get_label(),Qt::MatchFixedString | Qt::MatchRecursive,0).size()!=0)
		{
			this->my_treeparameter->findItems(node->get_parent()->get_label(),Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);

		}
		else
		{

			//std::cerr << "else" << std::endl;
			ParameterItem *tmp_item1=new ParameterItem(_namespace,node->get_parent(),node->get_parent()->get_label(),node->get_parent()->get_term(),true);
			tmp_item1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			tmp_item1->appendRow(_tmp_item);
			buildNodeHierarchy(node->get_parent(),_processed_nodes,tmp_item1,_namespace);
		}
	}
	else{
		if(node->get_parent()!=NULL){
			//std::cerr << "second else" << node->get_parent()->get_label().toStdString() << std::endl;
			if(_namespace=="XEO_Positioning"){
				//std::cerr << "xeo pos root" << node->get_parent()->get_label().toStdString() << std::endl;
				this->my_treeparameter->findItems(node->get_parent()->get_label(),Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);

			}
			else{
				this->my_treeparameter->findItems(node->get_parent()->get_label()+" ("+node->get_parent()->get_term()->get_termId()+")",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);

			}
		}
		else{
			//std::cerr << "second else" << std::endl;
			_tmp_item->set_isRoot(true);
			this->my_treeparameter->findItems(_namespace,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);
			_processed_nodes->push_back(node);
		}
	}

}

void ObservationDetailsPage::set_up_Ontologytree(){
	if(this->doc_resources->contains("PO_Development",Xeml::Document::Contracts::Developmental)){
		std::list<TermNode*> my_devtree=(*static_cast<DevelopmentalOntologyHandler*>((*this->doc_resources->get_devHandler())["PO_Development"]->get_handler())->get_listNodes());
		std::cerr << "listnode size : " << my_devtree.size() << std::endl;
		my_treeparameter->appendRow(new ParameterItem(NULL,"PO_Developmental",true));
		build_dev_tree(&my_devtree,"PO_Developmental");
	}
	else{
		std::cerr << " no ontology called PO development" << std::endl;
	}

}
*/


