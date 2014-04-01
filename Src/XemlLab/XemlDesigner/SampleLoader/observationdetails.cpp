#include "observationdetails.h"

ObservationDetails::ObservationDetails(DocumentResources * _doc_resources,StoryNode * _root, std::vector<IndividualsPool*> * _pools, QWidget *parent) :
	QWidget(parent)
{
	this->root_node =_root;
	//this->pools=_pools;
	//setTitle(tr("Observation"));
	this->germplasm= new QLabel("Germplasm Table");
	individuals=0;
	this->doc_resources=_doc_resources;
	this->add_individual=new QPushButton("add individual");
	connect(this->add_individual,SIGNAL(clicked()),this,SLOT(add_ind()));

	destructCheckBox= new QCheckBox("Destructive observation");
	this->pooling=new QCheckBox("pooling");
	this->pooling->setToolTip("pool individuals samples. Need to tick \"use model for all\".");
	this->use_template_for_all=new QCheckBox("use model for all");
	this->use_template_for_all->setToolTip("Describe only one individual as model for others (highly recommended)");
	this->use_template_for_all->setCheckState(Qt::Unchecked);
	connect(this->use_template_for_all,SIGNAL(clicked()),this,SLOT(on_modelCB_clicked()));

	//this->durationEdit= new QLineEdit;
	this->timeDurationEdit=new QTimeEdit;
	this->timeDurationEdit->setDisplayFormat("hh:mm:ss");
	durationInd= new QLabel("Duration per individuals");
	durationInd->setBuddy(timeDurationEdit);

	tree=new QTreeView;
	tree->setContextMenuPolicy(Qt::CustomContextMenu);
	//connect(tree,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(context_menu(QPoint));
	connect(tree,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_item_double_clicked(QModelIndex)));
	model = new QStandardItemModel;
	//my_treeparameter->appendColumn();
	QStandardItem *root_item=new QStandardItem("Observations");
	root_item->setCheckable(true);
	root_item->setCheckState(Qt::Checked);
	connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_item_checked(QStandardItem*)));
	root_item->setEditable(false);
	root_item->setSelectable(false);

	this->germPlasmTable= new QTableView;
	this->germPlasmModel=new QStandardItemModel(1,2,this);
	this->germPlasmModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Germplasm")));
	this->germPlasmModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Individuals #")));
	this->germPlasmTable->setModel(this->germPlasmModel);



	//add individuals pools
	/*
	std::cerr << "number of pool: " << this->pools->size() << std::endl;
	for (int i=0;i < this->pools->size();i++){
		this->germPlasmModel->setItem(i,0,new QStandardItem(static_cast<IndividualsPool*>(this->pools->at(i))->get_germplasm()));
		this->germPlasmModel->setItem(i,1,new QStandardItem(QString::number(static_cast<IndividualsPool*>(this->pools->at(i))->count_individuals())));

	}
	*/



	//root_item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	//QModelIndexList list=static_cast<QItemSelectionModel*>(field("genViewSelection").value<QItemSelectionModel*>())->selectedRows();

	//if (static_cast<Story*>(root_node->get_story())->get_individualspoolcollection())


	model->appendRow(root_item);

	tree->setModel(model);

	QGroupBox *groupBox = new QGroupBox(tr("Options selection"));
	QHBoxLayout * mainlayout=new QHBoxLayout;
	mainlayout->addWidget(tree);
	mainlayout->addSpacing(3);

	QVBoxLayout *layout = new QVBoxLayout;


	QVBoxLayout * boxLayout = new QVBoxLayout;
	boxLayout->addWidget(destructCheckBox);
	boxLayout->addWidget(pooling);
	boxLayout->addWidget(use_template_for_all);
	boxLayout->addStretch(1);
	groupBox->setLayout(boxLayout);

	layout->addWidget(groupBox);
	layout->addWidget(this->germplasm);
	layout->addWidget(this->germPlasmTable);

	//layout->addWidget(trayIcon);
	layout->addStretch(1);


	layout->addWidget(add_individual);

	QHBoxLayout * durationLayout = new QHBoxLayout;
	durationLayout->addWidget(durationInd);
	durationLayout->addStretch(1);
	durationLayout->addWidget(timeDurationEdit);
	layout->addLayout(durationLayout);

	mainlayout->addLayout(layout);
	setLayout(mainlayout);



}
void ObservationDetails::add_individuals_pool(QStandardItem * _root,StoryNode * _rootNode){

}
void ObservationDetails::initialize_table(std::vector<IndividualsPool*> * _pools){
	this->pools=_pools;
	//std::cerr << "pool size in initialize table : " << pools->size() << std::endl;
	for (int i=0;i < this->pools->size();i++){
		individuals=static_cast<IndividualsPool*>(this->pools->at(i))->count_individuals();
		this->germPlasmModel->setItem(i,0,new QStandardItem(static_cast<IndividualsPool*>(this->pools->at(i))->get_germplasm()));
		this->germPlasmModel->setItem(i,1,new QStandardItem(QString::number(static_cast<IndividualsPool*>(this->pools->at(i))->count_individuals())));
		//add_ind();
		int j=0;
		QString gp=static_cast<IndividualsPool*>(this->pools->at(i))->get_germplasm();
		for(std::map<Individual*,int>::iterator it=static_cast<IndividualsPool*>(this->pools->at(i))->get_individualscollection()->begin();it!=static_cast<IndividualsPool*>(this->pools->at(i))->get_individualscollection()->end();++it){


			//std::cerr << "full name before : " << QString::number(static_cast<Individual*>((*it).first)->get_id()).toStdString() << "-" << gp.toStdString() << std::endl;
			//static_cast<Individual*>((*it).first)->set_is_destroyed(true);
			if(!static_cast<Individual*>((*it).first)->is_destroyed()){

				add_ind(static_cast<Individual*>((*it).first)->get_id(),false,i,j,gp);
			}
			else{
				std::cerr << "individuls is already destroyed" << std::endl;
				add_ind(static_cast<Individual*>((*it).first)->get_id(),true,i,j,gp);

			}
			j++;
		}


	}
	//add individuals in the tree

}

QCheckBox * ObservationDetails::get_pooling_check_box(){
	return this->pooling;
}

QCheckBox * ObservationDetails::get_destruct_check_box(){
	return this->destructCheckBox;
}

QCheckBox * ObservationDetails::get_template_check_box(){
	return this->use_template_for_all;
}
QTimeEdit * ObservationDetails::get_time(){
	return this->timeDurationEdit;
}
QTreeView * ObservationDetails::get_tree(){
	return this->tree;
}

QStandardItemModel * ObservationDetails::get_model(){
	return this->model;
}

void ObservationDetails::add_ind(){

	individuals++;
	if(this->model->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive,0).size()!=0)
	{
		QStandardItem * indItem;
		QList<QStandardItem*> test;
		for (int i=0;i < this->pools->size();i++){

			//srand(time(NULL)+1);
			QTime time = QTime::currentTime();
			qsrand((uint)time.msec());
			Individual * ind = new Individual(qrand()%1000000000 +1);

			static_cast<IndividualsPool*>(this->pools->at(i))->add_Individual(ind);
			//individuals_id.push_back(QString::number(1+ rand() % 1000000000));
			this->germPlasmModel->setItem(i,1,new QStandardItem(QString::number(individuals)));
			QString Qs=QString::number(ind->get_id())+"-("+static_cast<IndividualsPool*>(this->pools->at(i))->get_germplasm()+")";

			if (i==0){
				//QString Qs=QString::number(ind->get_id())+static_cast<IndividualsPool*>(this->pools->at(i))->get_germplasm();
				indItem=new QStandardItem(Qs);
				indItem->setCheckable(true);
				indItem->setCheckState(Qt::Checked);
				QStandardItem * dev_stage=new QStandardItem("developmental-stage");
				dev_stage->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
				dev_stage->setToolTip("double clicked to add developmental stage term");

				indItem->appendRow(dev_stage);
				QStandardItem * partition = new QStandardItem("partitions");
				partition->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
				QStandardItem * structure = new QStandardItem("structure");
				structure->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
				structure->setToolTip("double clicked to add material structure term");
				partition->appendRow(structure);
				QStandardItem * position=new QStandardItem("position");
				position->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
				position->setToolTip("double clicked to add positionning term");

				partition->appendRow(position);
				indItem->appendRow(partition);


				this->model->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(indItem);

			}
			else{
				QStandardItem * indItem2=new QStandardItem(Qs);
				indItem2->setCheckable(true);
				indItem2->setCheckState(Qt::Checked);
				//indItem->appendRow(indItem2);
				indItem->insertRow(i-1,indItem2);
				//test.append(indItem2);



			}

			//QStandardItem * inditem=new QStandardItem(QString::number(1+ rand() % 1000000000));
			//QStandardItem * inditem2=new QStandardItem(QString::number(1+ rand() % 1000000000));

			//test.append(inditem);





		}
		indItem->appendColumn(test);


		//ind->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


		this->tree->expandAll();


	}



}
void ObservationDetails::add_ind(int _id,bool _isDestroyed,int _count, int _row,QString _germplasm){

	QString Qs=QString::number(_id)+"-("+_germplasm+")";

	if(this->model->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive,0).size()!=0){

		//std::cerr << "pool number : " << _count << std::endl;
		//std::cerr << "row number : " << _row << std::endl;

		if (_count==0){

			//std::cerr << "full name  :" << Qs.toStdString() << std::endl;

			QStandardItem * ind=new QStandardItem(Qs);
			ind->setCheckable(true);
			ind->setCheckState(Qt::Checked);
			//ind->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			QStandardItem * dev_stage=new QStandardItem("developmental-stage");
			dev_stage->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			dev_stage->setToolTip("double clicked to add developmental stage term");

			ind->appendRow(dev_stage);
			QStandardItem * partition=new QStandardItem("partitions");
			partition->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			QStandardItem * structure=new QStandardItem("structure");
			structure->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			structure->setToolTip("double clicked to add material structure term");
			partition->appendRow(structure);
			QStandardItem * position=new QStandardItem("position");
			position->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			position->setToolTip("double clicked to add positionning term");

			partition->appendRow(position);
			ind->appendRow(partition);
			if(_isDestroyed){
				ind->setEnabled(false);
				dev_stage->setEnabled(false);
				structure->setEnabled(false);
				position->setEnabled(false);
				position->setSelectable(false);
			}
			this->model->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(ind);
			this->tree->expandAll();
			//individuals++;

		}
		else{
			//std::cerr << "full name  :" << Qs.toStdString() << std::endl;

			QStandardItem * indItem2=new QStandardItem(Qs);
			indItem2->setCheckable(true);
			indItem2->setCheckState(Qt::Checked);
			//std::cerr << " item found with id : " << this->model->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive)[0]->child(_row)->text().toStdString() << std::endl;
			this->model->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive)[0]->child(_row)->insertRow(_count-1,indItem2);

		}
	}




}
void ObservationDetails::on_modelCB_clicked(){
	/*
	if(this->use_template_for_all->checkState()==Qt::Unchecked){
		std::cerr << "define for each individuals" << std::endl;
		this->add_individual->setEnabled(true);
		set_model_tree(ObservationDetails::All);

	}
	else{

		this->add_individual->setEnabled(false);
		set_model_tree(ObservationDetails::OneForAll);

		std::cerr << "define for all" << std::endl;
	}
	*/
}
void ObservationDetails::set_model_tree(ModelOrNotModel displayMode){
	if (displayMode== ObservationDetails::OneForAll){

	}
	else{

	}
}

void ObservationDetails::on_item_checked(QStandardItem* _item){
	if (_item->isCheckable()){
		if(_item->text()=="Observations"){
			//_item->child(0)->isCheckable()
			//for ()
			if(_item->checkState()==Qt::Checked){
				//cocher tous les individus
				if(_item->hasChildren()){
					//for (_item->child())
					for (int i =0;i<_item->rowCount();i++){
						_item->child(i)->setCheckState(Qt::Checked);
					}
				}
			}
			else{
				if(_item->hasChildren()){
					//for (_item->child())
					for (int i =0;i<_item->rowCount();i++){
						_item->child(i)->setCheckState(Qt::Unchecked);
						if(_item->child(i)->hasChildren()){
							for (int j =0;j<_item->child(i)->rowCount();j++){
								_item->child(i)->child(j)->setCheckState(Qt::Unchecked);

							}
						}
					}
				}

			}

		}
	}
	else{

	}

}

void ObservationDetails::on_item_double_clicked(QModelIndex index){
	current_index=index;
	QStandardItem * tmp =static_cast<QStandardItem*>(this->model->itemFromIndex(index));
	if(tmp->text()=="structure" && tmp->isEnabled()){
		parameter_tree = new ParameterTreeView(false,this->doc_resources);
		QStringList * struct_onto = new QStringList;
		struct_onto->append("PO_Structure");
		parameter_tree->set_up_Ontologytree(this->doc_resources,struct_onto);
		connect(parameter_tree,SIGNAL(onParameterselected(ItfOntologyTerm*)),SLOT(add_parameter_item(ItfOntologyTerm*)));
		parameter_tree->show();
		//std::cerr << "open devtree and show it" << std::endl;
	}
	else if(tmp->text()=="developmental-stage" && tmp->isEnabled()){
		parameter_tree = new ParameterTreeView(false,this->doc_resources);
		QStringList * dev_onto = new QStringList;
		dev_onto->append("PO_Development");
		parameter_tree->set_up_Ontologytree(this->doc_resources,dev_onto);
		connect(parameter_tree,SIGNAL(onParameterselected(ItfOntologyTerm*)),SLOT(add_parameter_item(ItfOntologyTerm*)));
		parameter_tree->show();
	}
	else if(tmp->text()=="position" && tmp->isEnabled()){
		parameter_tree = new ParameterTreeView(false,this->doc_resources);
		QStringList * dev_onto = new QStringList;
		dev_onto->append("XEO_Positioning");
		parameter_tree->set_up_Ontologytree(this->doc_resources,dev_onto);
		connect(parameter_tree,SIGNAL(onParameterselected(ItfOntologyTerm*)),SLOT(add_parameter_item(ItfOntologyTerm*)));
		parameter_tree->show();

	}
	else{
		std::cerr << "nothing to do" << std::endl;

	}

}
void ObservationDetails::add_parameter_item(ItfOntologyTerm * _term){
	/*
	for(std::map<ValueBase*,QString>::iterator it=static_cast<VariableTerm*>(_term->get_prototype())->get_valuecollection()->begin();it!=static_cast<VariableTerm*>(_term->get_prototype())->get_valuecollection()->end();++it){
		//values->append(static_cast<Value*>((*it).first)->get_val());
		if(static_cast<Value*>((*it).first)->get_context()=="Quantity"){
			std::cerr << "Qvalue : " << static_cast<Value*>((*it).first)->get_val().toStdString() << std::endl;
		}
	}
	*/
	//std::cerr << "entering add parameter in ObservatinoDetail" << std::endl;
	QStandardItem * tmp =static_cast<QStandardItem*>(this->model->itemFromIndex(current_index));
	QString termnode;
	termnode=_term->get_prototype()->get_name()+"-("+_term->get_termId()+")";

	if(tmp->text()=="developmental-stage"){
		//termnode=_term->get_prototype()->get_name()+" ("+_term->get_termId()+" )";
	}
	else if (tmp->text()=="structure"){
		//termnode=_term->get_prototype()->get_name()+" ("+_term->get_termId()+" )";

	}
	else{
		AboutParameter  * aboutParameter=new AboutParameter;
		aboutParameter->set_term(_term);
		connect(aboutParameter,SIGNAL(set_up_finished(ItfOntologyTerm*)),this,SLOT(add_details_about_pos_term(ItfOntologyTerm*)));

		aboutParameter->initialize();
		aboutParameter->setVisible(true);


	}


	QStandardItem * term=new QStandardItem(termnode);
	term->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	tmp->appendRow(term);
	parameter_tree->close();
}
void ObservationDetails::add_details_about_pos_term(ItfOntologyTerm * _term){

	//this->idEdit->setText(_term->get_termId());
	//this->nameEdit->setText(_term->get_prototype()->get_name());
	QStandardItem * tmp =static_cast<QStandardItem*>(this->model->itemFromIndex(current_index));
	//retrieve the position item and look if It has children
	if (tmp->hasChildren()){


		if (!this->model->findItems(_term->get_prototype()->get_name()+" ("+_term->get_termId()+" )",Qt::MatchFixedString | Qt::MatchRecursive)[0]->hasChildren()){

			for(std::map<ValueBase*,QString>::iterator it=static_cast<VariableTerm*>(_term->get_prototype())->get_valuecollection()->begin();it!=static_cast<VariableTerm*>(_term->get_prototype())->get_valuecollection()->end();++it){
				//values->append(static_cast<Value*>((*it).first)->get_val());
				if(static_cast<Value*>((*it).first)->get_context()=="Quantity"){
					//std::cerr << "Qvalue : " << static_cast<Value*>((*it).first)->get_val().toStdString() << std::endl;
					//QStandardItem * tmp =static_cast<QStandardItem*>(this->model->itemFromIndex(current_index));
					QStandardItem * quantity_context=new QStandardItem("Quantity_Context");
					quantity_context->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
					QStandardItem * Qvalue=new QStandardItem("Value:"+static_cast<Value*>((*it).first)->get_val());
					QStandardItem * Qunit=new QStandardItem("Unit:"+static_cast<Value*>((*it).first)->get_unit());
					quantity_context->appendRow(Qvalue);
					quantity_context->appendRow(Qunit);

					this->model->findItems(_term->get_prototype()->get_name()+" ("+_term->get_termId()+" )",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(quantity_context);

					//this->QValueEdit->setText(static_cast<Value*>((*it).first)->get_val());
					//this->UnitEdit->setText(static_cast<Value*>((*it).first)->get_unit());
				}
				else{
					//this->ValueEdit->setText(static_cast<Value*>((*it).first)->get_val());
				}
			}
			//QStandardItem * quantity_context=new QStandardItem("Quantity_Context");
			//partition->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			//QStandardItem * quantity_context=new QStandardItem("Quantity_Context");
			//partition->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			//this->model->findItems(_term->get_prototype()->get_name()+" ("+_term->get_termId()+" )",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow();
		}

	}

	//_term->get_prototype()->get_name()+" ("+_term->get_termId()+" )"
	//QStringList * values =new QStringList;

	/*
	for(std::map<ValueBase*,QString>::iterator it=static_cast<VariableTerm*>(_term->get_prototype())->get_valuecollection()->begin();it!=static_cast<VariableTerm*>(_term->get_prototype())->get_valuecollection()->end();++it){
		//values->append(static_cast<Value*>((*it).first)->get_val());
		if(static_cast<Value*>((*it).first)->get_context()=="Quantity"){
			QStandardItem * tmp =static_cast<QStandardItem*>(this->model->itemFromIndex(current_index));

			//this->QValueEdit->setText(static_cast<Value*>((*it).first)->get_val());
			//this->UnitEdit->setText(static_cast<Value*>((*it).first)->get_unit());
		}
		else{
			//this->ValueEdit->setText(static_cast<Value*>((*it).first)->get_val());
		}
	}
	*/
}


