#include "observationdetailspage.h"

ObservationDetailsPage::ObservationDetailsPage(DocumentResources * _doc_resources,QWidget *parent)

	: QWizardPage(parent)
{
	this->doc_resources =_doc_resources;
	setTitle(tr("Observation"));
	setSubTitle(tr("Specify developmental stage conditions about your samples"));



	my_treeView= new ParameterTreeView(this->doc_resources);
	connect(this->my_treeView,SIGNAL(onParameterselected(ItfOntologyTerm*)),this,SLOT(get_term(ItfOntologyTerm*)));
	germplasmEdit = new QLineEdit;
	germLabel = new QLabel("GermPlasm");

	germLabel->setBuddy(germplasmEdit);
	termEdit = new QLineEdit;
	termLabel = new QLabel("term id");
	nameEdit = new QLineEdit;
	nameLabel = new QLabel("term name");
	termLabel->setBuddy(termEdit);
	destructCheckBox= new QCheckBox("Destructive observation");
	this->durationEdit= new QLineEdit;
	this->timeDurationEdit=new QTimeEdit;
	this->timeDurationEdit->setDisplayFormat("hh:mm:ss");
	durationInd= new QLabel("Duration per individuals");
	durationInd->setBuddy(timeDurationEdit);
	Individuals = new QLabel("Individual pooling") ;
	this->IndBox=new QSpinBox;
	Individuals->setBuddy(this->IndBox);
	QHBoxLayout * mainlayout=new QHBoxLayout;
	mainlayout->addWidget(this->my_treeView);
	QVBoxLayout *layout = new QVBoxLayout;
	QHBoxLayout * bottomLayout = new QHBoxLayout;
	bottomLayout->addWidget(this->germLabel);
	bottomLayout->addWidget(this->germplasmEdit);
	layout->addLayout(bottomLayout);
	layout->addWidget(destructCheckBox);
	layout->addWidget(durationInd);
	layout->addWidget(timeDurationEdit);
	layout->addWidget(Individuals);
	layout->addWidget(this->IndBox);
	layout->addWidget(termLabel);
	layout->addWidget(termEdit);
	layout->addWidget(nameLabel);
	layout->addWidget(nameEdit);
	mainlayout->addLayout(layout);
	setLayout(mainlayout);
	registerField("DevTermId*",this->termEdit);
	registerField("Individuals*",this->IndBox);
	registerField("Duration*",timeDurationEdit);
	registerField("DevName*",nameEdit);

}
void ObservationDetailsPage::initializePage(){
	this->germplasm =field("GermPlasm").toString();
	this->germplasmEdit->setText(this->germplasm);
	QStringList * dev_onto = new QStringList;
	dev_onto->append("PO_Development");
	this->my_treeView->set_up_Ontologytree(this->doc_resources,dev_onto);
}

void ObservationDetailsPage::get_term(ItfOntologyTerm * _term){
	this->termEdit->setText(_term->get_termId());
	this->nameEdit->setText(_term->get_prototype()->get_name());
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


