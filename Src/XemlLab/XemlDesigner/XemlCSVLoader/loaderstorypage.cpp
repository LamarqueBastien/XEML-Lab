#include "loaderstorypage.h"

LoaderStoryPage::LoaderStoryPage(QStandardItemModel * _model,int _column,int _row,ItfDocument * _doc,QWidget * parent)
:QWidget(parent)
{
	//variables initialization
	this->row=_row;
	this->column=_column;
	this->currentDoc=_doc;
	this->storyLabel=new QLabel("Choose a Story for the following header : ");
	this->bottomLabel= new QLabel("<i>Double click a node to select it</i>");
	this->storytree= new QTreeView;
	this->my_treestory= _model;//new QStandardItemModel;
	this->storyChosen=new QLineEdit;
	this->okButton=new QPushButton("OK");
	this->okButton->setEnabled(false);
	this->removeButton=new QPushButton("remove");
	this->removeButton->setEnabled(false);
	this->storytree->setModel(this->my_treestory);
	this->storytree->header()->hide();
	//createExperiment(this->currentDoc);

	//Layout settings
	QVBoxLayout * mainlayout=new QVBoxLayout;
	mainlayout->addWidget(this->storyLabel);
	mainlayout->addWidget(this->storytree);
	mainlayout->addWidget(this->bottomLabel);
	QHBoxLayout * bottomlayout=new QHBoxLayout;
	bottomlayout->addWidget(this->storyChosen);
	bottomlayout->addWidget(this->okButton);
	bottomlayout->addWidget(this->removeButton);
	mainlayout->addLayout(bottomlayout);
	setLayout(mainlayout);

	//SIGNALS and SLOTS
	connect(this->removeButton,SIGNAL(clicked()),this,SLOT(removed()));
	connect(this->storytree,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_story_selected(QModelIndex)));
	connect(this->storyChosen,SIGNAL(textChanged(QString)),this,SLOT(set_up_finished(QString)));
	connect(this->okButton,SIGNAL(clicked(bool)),this,SLOT(closed(bool)));



	setWindowFlags(Qt::WindowStaysOnTopHint);
	this->setWindowTitle("Story Choice");
}
void LoaderStoryPage::set_up_finished(QString _storyname){
	this->okButton->setEnabled(true);
	this->removeButton->setEnabled(true);
}
void LoaderStoryPage::removed(){
	this->storyChosen->clear();
	this->current_storyNode=NULL;
}
void LoaderStoryPage::on_story_selected(QModelIndex _idx){
	QItemSelectionModel * selection = this->storytree->selectionModel();
	//StoryNode * current_storyNode;
	if(selection->isSelected(_idx)){
		StoryItem * tmp =static_cast<StoryItem*>(this->my_treestory->itemFromIndex(_idx));
		if(tmp->isRoot()){
			QMessageBox::information(this,"added element","can't add a term to experiment");
		}
		else{
			this->current_storyNode=this->currentDoc->get_storyboard()->findNode(tmp->get_story()->get_label());
			this->storyChosen->setText(tmp->get_story()->get_label());
			std::cerr << this->current_storyNode->get_label().toStdString() << std::endl;
		}

	}


}
void LoaderStoryPage::closed(bool){

	emit send_details_story(this->column,this->row,this->current_storyNode);
	this->close();
	this->setEnabled(false);
}

bool LoaderStoryPage::contains(StoryNode * _node,std::list<StoryNode*> * _processed_nodes,QString _storyname){

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
/*
 * for each node without childs, this builds the parent node and adds the child to the parent,
 * then it performs recursively the same processus until it founds the story node (i.e. node without parent)
 *then it return to the function below create experiment();
*/
void LoaderStoryPage::build_story_hierarchy(StoryNode * _node,std::list<StoryNode*> * _processed_nodes,StoryItem * _tmp_item,QString _storyname){

	_processed_nodes->push_back(_node);
	_tmp_item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	if(_node->get_parent()!=NULL && !contains(_node->get_parent(),_processed_nodes,_storyname)){
		std::cerr << "first if" << std::endl;
		if(this->my_treestory->findItems((_node->get_parent()->get_story()->get_label()+"("+_storyname+")"),Qt::MatchFixedString | Qt::MatchRecursive,0).size()!=0){
			std::cerr << "second if" << std::endl;
			this->my_treestory->findItems((_node->get_parent()->get_story()->get_label()+"("+_storyname+")"),Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);
		}
		else{
			StoryItem * tmp_item1;
			//tmp_item1 = new StoryItem(QString((_node->get_parent()->get_story()->get_label()+"("+_storyname+")").c_str()),_node->get_parent()->get_story(),_node->get_parent()->get_isStorySplit(),false);

			if(_node->get_parent()->get_parent()==NULL){
				tmp_item1 = new StoryItem(_node->get_parent()->get_story()->get_label(),_node->get_parent()->get_story(),_node->get_parent()->get_isStorySplit(),false);
			}
			else{

				tmp_item1 = new StoryItem((_node->get_parent()->get_story()->get_label()+"("+_storyname+")"),_node->get_parent()->get_story(),_node->get_parent()->get_isStorySplit(),false);
			}

			tmp_item1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			tmp_item1->appendRow(_tmp_item);
			build_story_hierarchy(_node->get_parent(),_processed_nodes,tmp_item1,_storyname);
		}
	}
	else{

		if(_node->get_parent()!=NULL){
			std::cerr << "else if" << std::endl;
			this->my_treestory->findItems((_node->get_parent()->get_story()->get_label()+"("+_storyname+")"),Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);
		}
		else{
			//std::cerr << "else else" << std::endl;
			this->my_treestory->findItems(this->experimentName,Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(_tmp_item);
		}
	}

}
void LoaderStoryPage::clean_tree(){
	my_treestory->clear();
}
void LoaderStoryPage::createExperiment(ItfDocument *  _current_xeml){
	this->experimentName=_current_xeml->get_experiment_name();
	this->currentDoc=_current_xeml;
	//this->doc_ressources=_doc_ressources;
	ExperimentItem * expItem= new ExperimentItem(this->experimentName,true);
	expItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	this->my_treestory->appendRow(expItem);
	static_cast<ExperimentItem*>(this->my_treestory->findItems(this->experimentName,Qt::MatchFixedString | Qt::MatchRecursive)[0])->set_experimentHeader(_current_xeml->get_experimentheader());
	std::list<StoryNode*> processed_nodes;
	QString storyname;

	for(std::list<StoryNode*>::iterator it=_current_xeml->get_storyboard()->get_storyBoard()->begin();it!=_current_xeml->get_storyboard()->get_storyBoard()->end();++it){

		if((*it)->get_parent()==NULL){
			storyname=(*it)->get_story()->get_label();
			//std::cerr <<"----------------story labem " << (*it)->get_story()->get_label() << std::endl;

		}
		if(_current_xeml->get_storyboard()->get_storyBoard()->size()==1){
			expItem->appendRow(new StoryItem(((*it)->get_story()->get_label()),
														 (*it)->get_story(),
														 (*it)->get_isStorySplit(),
														 false));
		}

		if((*it)->get_parent()!=NULL && (*it)->get_childs()->size()==0){
			build_story_hierarchy((*it),
								  &processed_nodes,
								  new StoryItem(((*it)->get_story()->get_label()+"("+storyname+")"),
												(*it)->get_story(),
												(*it)->get_isStorySplit(),
												false),
								  storyname);

		}
	}
}
