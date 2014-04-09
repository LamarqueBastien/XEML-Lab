#include "loaderparamsettingpage.h"

LoaderParamSettingPage::LoaderParamSettingPage(QStandardItemModel * _model,ItfDocument * _doc,DocumentResources * _resources,QWidget *parent)
	: QWizardPage(parent)
{

	this->current_doc=_doc;
	this->modeltree=_model;
	this->doc_resources=_resources;
	this->IsInitialized=false;
	setTitle(tr("Header/Term Association"));
	setSubTitle(tr("Please try to find a corresponding term for each header"
					   " in a selection of ontologies."));
	table =new QTableView();
	this->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	this->table->setSelectionMode(QAbstractItemView::MultiSelection);

	model = new QStandardItemModel(1,4,this); //2 Rows and 3 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("term header")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("term ontology")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("term story")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QString("is a time value")));
	table->setModel(model);

	std::cerr << " size vector in param settings : " << LoaderWizard::get_CSV_data()->size() << std::endl;
	//QString data=field("Data").toString();
	//std::cerr << "data : " << data.toStdString() << std::endl;

	//Filename = new QLabel(tr("F&ilename:"));
	//FilenameLineEdit2 = new QLineEdit;
	//Filename->setBuddy(FilenameLineEdit2);
	//registerField("paramFileName*", FilenameLineEdit2);
	QHBoxLayout * layout= new QHBoxLayout;
	//QGridLayout *layout = new QGridLayout;
	layout->addWidget(table);
	setWindowFlags(Qt::WindowStaysOnTopHint);
	setLayout(layout);


}

void LoaderParamSettingPage::send_data(std::vector<std::vector<QString> *> * _vectorData){
	std::cerr << "entering param settings" << std::endl;
	int cpt=0;
	for(std::vector<std::vector<QString> *>::iterator it=_vectorData->begin();it!=_vectorData->end();++it){
		model->setItem(cpt,0,new QStandardItem((*it)->at(0)));
		cpt++;

	}
	//this->nextId();
	//this->setVisible(true);
	//this->setEnabled(true);
}

void LoaderParamSettingPage::initializePage(){
	std::cerr << "entering initializePage" << std::endl;
	this->stories = new std::vector<StoryNode*>();
	//this->stories2 = QVector <StoryNode*> ((indexlist->size())-1);
	//this->stories->resize(indexlist->size()-1);
	this->termHeaderLabel=new std::vector<QString>();


	this->terms=new std::vector<std::pair<ItfOntologyTerm *,QString> >();

	//this->terms->resize(indexlist->size()-1);
	connect(this->table,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_item_selected(QModelIndex)));
	connect(this->table,SIGNAL(doubleClicked(QModelIndex)),this->table,SLOT(edit(QModelIndex)));
	this->indexlist=new QModelIndexList;

	//std::vector<StoryNode*> storytmp (indexlist->size()-1);
	//stories (indexlist->size()-1);
	//for (int i=0;i<indexlist->size();i++){
	//	stories->push_back(NULL);
	//	terms->push_back(make_pair(,""));
	//}
	//terms (indexlist->size()-1);
	(*indexlist)=static_cast<QItemSelectionModel*>(field("headerViewSelection").value<QItemSelectionModel*>())->selectedColumns();
	//this->stories2 = QVector <StoryNode*> (indexlist->size()-1);
	//this->terms2 = QVector <std::pair<ItfOntologyTerm *,QString> > (indexlist->size()-1);

	for (int i=0;i<this->indexlist->size()-1;i++){
		this->stories->push_back(NULL);
		this->terms->push_back(make_pair(static_cast<ItfOntologyTerm *>(NULL),""));
	}
	for (int i=0;i<indexlist->size();i++){

		if (i!=0){

			this->termHeaderLabel->push_back(indexlist->at(i).data().toString());

		}


		std::cerr << indexlist->at(i).data().toString().toStdString() << std::endl;
		this->model->setItem(i,0,new QStandardItem(indexlist->at(i).data().toString()));
		this->model->setItem(i,1,new QStandardItem("-Click to set-"));
		this->model->setItem(i,2,new QStandardItem("-Click to set-"));
		this->model->setItem(i,3,new QStandardItem("No"));

	}
	//std::cerr << " size vector in param settings : " << LoaderWizard::get_CSV_data()->size() << std::endl;
	//std::cerr << " vector : " << LoaderWizard::get_CSV_data()->at(0)->size() << std::endl;
	//for (int i=0;i<LoaderWizard::get_CSV_data()->size();i++){
	//	for (int j=0;j<LoaderWizard::get_CSV_data()->at(i)->size();j++){
	//		std::cerr << LoaderWizard::get_CSV_data()->at(i)->at(j).toStdString() << std::endl;

	//	}
	//}


}
void LoaderParamSettingPage::store_information_term_and_story(int column,int _row,StoryNode * _storynode,ItfOntologyTerm * _term,QString _unit){
	this->model->setItem(_row,1,new QStandardItem(_term->get_prototype()->get_termId()));
	this->model->setItem(_row,2,new QStandardItem(_storynode->get_story()->get_label()));

	//this->stories2[_row]=_storynode;
	//this->terms2[_row]=make_pair(_term,_unit);
	this->stories->at(_row-1)=_storynode;
	//this->stories->push_back(_storynode);
	this->terms->at(_row-1)=make_pair(_term,_unit);
	//this->terms->push_back(make_pair(_term,_unit));


}

void LoaderParamSettingPage::store_information_term(int column,int _row,ItfOntologyTerm * _term,QString _unit){
	//std::cerr << "index==1 "<< "row : " << row<< std::endl;
	this->model->setItem(_row,1,new QStandardItem(_term->get_prototype()->get_termId()));
	//this->terms->at(_row)=make_pair(_term,_unit);


}
void LoaderParamSettingPage::store_information_story(int column,int _row,StoryNode * _storynode){
	Q_UNUSED(column)
	this->model->setItem(_row,2,new QStandardItem(_storynode->get_story()->get_label()));
	//this->stories->at(_row)=_storynode;
}

void LoaderParamSettingPage::store_information_time(int column,int _row,QString _date){
	this->model->setItem(_row,1,new QStandardItem("Is a"));
	this->model->setItem(_row,2,new QStandardItem("date element"));
	this->model->setItem(_row,3,new QStandardItem("Yes"));
	this->time_expression=_date;

}
void LoaderParamSettingPage::set_paramater_type(bool _is_time_parameter){
	this->IsTimeParameter=_is_time_parameter;
}

void LoaderParamSettingPage::on_item_selected(QModelIndex _index){

	this->IsInitialized=true;
	//mettre un switch
	/*
	TimeDialog * timedialog=new TimeDialog();
	connect(timedialog,SIGNAL(is_time(bool)),this,SLOT(set_paramater_type(bool)));
	timedialog->show();
	if (this->IsTimeParameter){
		this->ontologyPage=new LoaderOntologyPage(_index.row(),this->current_doc,this->doc_resources);
		connect(this->ontologyPage,SIGNAL(send_term(int,ItfOntologyTerm*,QString)),this,SLOT(store_information_term(int,ItfOntologyTerm*,QString)));
		connect(this->ontologyPage,SIGNAL(send_story(int,StoryNode*)),this,SLOT(store_information_story(int,StoryNode*)));
		this->ontologyPage->show();

	}
	else{


		this->dateTimePage=new LoaderDateTimePage(_index.row());
		connect(this->dateTimePage,SIGNAL(delimitered_dateTime(int,QString)),this,SLOT(store_information_time(int,QString)));
		this->dateTimePage->show();
	}
	//this->ontologyPage=new LoaderOntologyPage(_index.row(),this->current_doc,this->doc_resources);
	//connect(this->ontologyPage,SIGNAL(send_term(int,ItfOntologyTerm*,QString)),this,SLOT(store_information_term(int,ItfOntologyTerm*,QString)));
	//connect(this->ontologyPage,SIGNAL(send_time(int,QString)),this,SLOT(store_information_time(int,QString)));
	//connect(this->ontologyPage,SIGNAL(send_story(int,StoryNode*)),this,SLOT(store_information_story(int,StoryNode*)));


	//this->ontologyPage->show();
	*/



	if(_index.column()==0){


	}
	else if(_index.column()==1 && _index.row()!=0){


		//std::cerr << "index==1 "<< "row : " << _index.row()<< "--" << this->indexlist->at(_index.row()).data().toString().toStdString() <<  std::endl;
		this->ontologyPage=new LoaderOntologyPage(this->modeltree,_index.column(),_index.row(),this->current_doc,this->doc_resources);
		//connect(this->ontologyPage,SIGNAL(send_term(int,int,ItfOntologyTerm*,QString)),this,SLOT(store_information_term(int,int,ItfOntologyTerm*,QString)));
		//connect(this->ontologyPage,SIGNAL(send_story(int,int,StoryNode*)),this,SLOT(store_information_story(int,int,StoryNode*)));
		connect(this->ontologyPage,SIGNAL(send_term_and_story(int,int,StoryNode*,ItfOntologyTerm*,QString)),this,SLOT(store_information_term_and_story(int,int,StoryNode*,ItfOntologyTerm*,QString)));


		this->ontologyPage->show();
	}
	else if(_index.column()==2 && _index.row()!=0){
		this->ontologyPage=new LoaderOntologyPage(this->modeltree,_index.column(),_index.row(),this->current_doc,this->doc_resources);
		connect(this->ontologyPage,SIGNAL(send_term_and_story(int,int,StoryNode*,ItfOntologyTerm*,QString)),this,SLOT(store_information_term_and_story(int,int,StoryNode*,ItfOntologyTerm*,QString)));
		this->ontologyPage->show();

		//this->storyPage=new LoaderStoryPage(_index.column(),_index.row(),this->current_doc);
		//connect(this->storyPage,SIGNAL(send_details_story(int,int,StoryNode*)),this,SLOT(store_information_story(int,int,StoryNode*)));

		//this->storyPage->show();

	}
	else if(_index.column()==3 && _index.row()==0){
		//passer en arguments du loader datetime page;
		//l"entête de la colonne,la première valeur de date,
		//
		//QString valuetest=LoaderWizard::get_CSV_data()->at(0)->at(1);

		this->dateTimePage=new LoaderDateTimePage(_index.column(),_index.row());
		connect(this->dateTimePage,SIGNAL(delimitered_dateTime(int,int,QString)),this,SLOT(store_information_time(int,int,QString)));
		this->dateTimePage->show();
		//this->termHeaderLabel->push_back(_index.data().toString());
		//std::cerr << "index==1 "<< "row : " << _index.row()<< std::endl;

	}
	else{


	}

}
//const void LoaderParamSettingPage::complete_xeml_doc(std::vector<StoryNode *> * _storynode,QString _date,std::vector<std::pair<ItfOntologyTerm *,QString> > * _terms){



	//for(std::vector<StoryNode*>::iterator it=this->stories.begin();it!=this->stories.end();++it){
	//	static_cast<StoryNode*>(it.first())->get_story()->add_variable();
	//}
//}

int LoaderParamSettingPage::nextId() const
{

	if(this->IsInitialized){
		std::vector<int> * position=new std::vector<int>();
		int counter=0;
		for (int i=0;i<this->terms->size();i++){
			for (int j =1;j<LoaderWizard::get_CSV_data()->size();j++){

				std::cerr << "data label :" << LoaderWizard::get_CSV_data()->at(j)->at(0).toStdString() << std::endl;
				std::cerr << "header label :" << this->termHeaderLabel->at(i).toStdString() << std::endl;
				if (LoaderWizard::get_CSV_data()->at(j)->at(0)==this->termHeaderLabel->at(i)){

					std::cerr << LoaderWizard::get_CSV_data()->at(j)->at(0).toStdString() << "====" << this->termHeaderLabel->at(i).toStdString() << std::endl;
					position->push_back(j);
					std::cerr << "position value :" << position->at(i) << std::endl;
					std::cerr << "j :" << j << std::endl;
				}
			}
		}
		std::cerr << "position size : " << position->size() << std::endl;
		std::cerr << "story size : " << this->stories->size() << std::endl;
		//this->complete_xeml_doc(this->stories,this->time_expression,this->terms);
		//for (unsigned i=0; i<this->stories->size(); i++)
			//std::cerr << static_cast<StoryNode*>(this->stories->at(i))->get_label().toStdString() << std::endl;//=i;
		//static_cast<XemlDocument*>(this->current_doc)->get_storyboard()->
		//QList<QStandardItem*> tmp =new QList<QStandardItem*>();
		//for (int i=0;i<this->indexlist->size();i++){
		//	tmp = model->takeRow(i);
		//	for (int j =0;j<model->columnCount();j++){
		//		std:cerr << tmp.at(j)->text().toStdString() << "," << std::endl;
		//	}
		//	tmp.clear();
		//}
		//std::cerr << " vector : " << LoaderWizard::get_CSV_data()->at(0)->size() << std::endl;

		for (unsigned i=0; i<this->stories->size(); i++){
			//static_cast<XeoTerm*>(this->terms->at(i).first)->get_contextCollection()
			std::cerr << "number of header" << LoaderWizard::get_CSV_data()->size() << std::endl;
			DynamicTerm * newTerm;
			StoryNode * tmp=stories->at(i);
			StoryNode * node=this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName());
			if(node->get_story()->contain_variableId(static_cast<XeoTerm*>(this->terms->at(i).first)->get_termId()) && static_cast<DynamicTerm*>(node->get_story()->get_variable(static_cast<XeoTerm*>(this->terms->at(i).first)->get_termId()))->get_measured_variable()){

				for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=node->get_story()->get_variablesCollection()->begin();it!=node->get_story()->get_variablesCollection()->end();++it){
					if((*it).second==static_cast<XeoTerm*>(this->terms->at(i).first)->get_termId() ){
						newTerm=static_cast<DynamicTerm*>((*it).first);
					}


				}

			}
			else{
				newTerm=new DynamicTerm((*static_cast<DynamicTerm*>(static_cast<XeoTerm*>(this->terms->at(i).first)->get_prototype())));
				newTerm->set_measured_variable(true);
				node->get_story()->add_variable(newTerm);
			}

			//DynamicTerm * tmp_term=static_cast<DynamicTerm*>(static_cast<XeoTerm*>(this->terms->at(i).first)->get_prototype());
			//tmp_term->contextList();
			std::cerr << "number of header" << LoaderWizard::get_CSV_data()->size() << std::endl;

			std::cerr << "number of header" << LoaderWizard::get_CSV_data()->size() << std::endl;
			std::cerr << "CSV vector size : " << LoaderWizard::get_CSV_data()->at(0)->size() << std::endl;
			std::cerr << "CSV vector 1 size : " << LoaderWizard::get_CSV_data()->at(1)->size() << std::endl;
			std::cerr << "CSV vector 2 size : " << LoaderWizard::get_CSV_data()->at(2)->size() << std::endl;


			for (unsigned j=1; j<LoaderWizard::get_CSV_data()->at(0)->size();j++){
				DynamicValue * v = new DynamicValue();
				v->set_is_cyclevalue(false);
				qint64 ellapsed_second_target=this->current_doc->get_startdate().toMSecsSinceEpoch();
				QDateTime tmp_time=QDateTime::fromString(LoaderWizard::get_CSV_data()->at(0)->at(j),this->time_expression);
				/*
				std::cerr << "docdayOfYear = " << this->current_doc->get_startdate().date().dayOfYear() << std::endl;
				std::cerr << "docmonth = " << this->current_doc->get_startdate().date().month() << std::endl;
				std::cerr << "docday = " << this->current_doc->get_startdate().date().day() << std::endl;
				std::cerr << "docyear = " << this->current_doc->get_startdate().date().year() << std::endl;
				*/
				//std::cerr << "tmpmonth = " << tmp_time.date().month() << std::endl;
				//std::cerr << "tmpday = " << tmp_time.date().day() << std::endl;
				//std::cerr << "tmpyear = " << tmp_time.date().year() << std::endl;

				qint64 ellapsed_second_query=tmp_time.toMSecsSinceEpoch();

				qint64 difference=ellapsed_second_query - ellapsed_second_target ;
				std::cerr << "difference " << difference << std::endl;
				/*
				std::cerr << "month = " << QDateTime::fromMSecsSinceEpoch(difference).date().month() << std::endl;
				std::cerr << "day = " << QDateTime::fromMSecsSinceEpoch(difference).date().day() << std::endl;
				std::cerr << "year = " << QDateTime::fromMSecsSinceEpoch(difference).date().year() << std::endl;
				std::cerr << "hour = " << QDateTime::fromMSecsSinceEpoch(difference).time().hour() << std::endl;
				*/
				//QDateTime timepoint=translate_second_in_DD_HH_MM_SS(get_seconds_from_date())
				v->set_timepoint(tmp_time);
				v->set_context("Quantity");
				//v->set_label(tmp_term->get_name());
				//std::cerr << "1----" << this->terms->at(i).second.toStdString()<< std::endl;
				QString tmp_unit=this->terms->at(i).second;
				tmp_unit=tmp_unit.remove(0,1);
				//std::cerr << "2----"  << tmp_unit.toStdString() << std::endl;
				v->set_unit(tmp_unit.remove(tmp_unit.size()-1,1));
				std::cerr << "position at i :" << position->at(i) << std::endl;
				v->set_value(LoaderWizard::get_CSV_data()->at(position->at(i))->at(j));


				newTerm->add_dynamicvalue(v);
				/*
				if(this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName())->get_story()->contain_variable(tmp_term)){
					//tmp_term->add_dynamicvalue(v);

					static_cast<DynamicTerm*>(this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName())->get_story()->get_variable(static_cast<XeoTerm*>(this->terms->at(i).first)->get_termId()))->add_dynamicvalue(v);


					std::cerr << "add value at :" << v->get_timepoint().toString(this->time_expression).toStdString()<< " in term :"<< tmp_term->get_name().toStdString() <<" in story : "<< tmp->get_label().toStdString()  <<std::endl;
					std::cerr <<"size values: " <<static_cast<DynamicTerm*>(this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName())->get_story()->get_variable(static_cast<XeoTerm*>(this->terms->at(i).first)->get_termId()))->get_dynamicvaluecollection()->size() << std::endl;

				}
				else{
					this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName())->get_story()->add_variable(tmp_term);
					static_cast<DynamicTerm*>(this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName())->get_story()->get_variable(static_cast<XeoTerm*>(this->terms->at(i).first)->get_termId()))->add_dynamicvalue(v);

					std::cerr << "add value in new variables at :" << v->get_timepoint().toString(this->time_expression).toStdString()<< " in term :"<< tmp_term->get_name().toStdString() <<" in story : "<< tmp->get_label().toStdString()  <<std::endl;
					std::cerr <<"size values: " <<static_cast<DynamicTerm*>(this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName())->get_story()->get_variable(static_cast<XeoTerm*>(this->terms->at(i).first)->get_termId()))->get_dynamicvaluecollection()->size() << std::endl;


				}
				*/
				//static_cast<DynamicTerm>(static_cast<XeoTerm*>(this->terms->at(i).first)->get_prototype());

			}
			std::cerr <<"size values: " <<static_cast<DynamicTerm*>(this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName())->get_story()->get_variable(static_cast<XeoTerm*>(this->terms->at(i).first)->get_termId()))->get_dynamicvaluecollection()->size() << std::endl;
			//std::cerr << "size :" << tmp_term->get_dynamicvaluecollection()->size() << std::endl;
			/*
			if(!(this->current_doc->get_storyboard()->findNode_by_Label(tmp->get_label(),tmp->get_mainStoryName())->get_story()->contain_variable(tmp_term))){

				std::cerr << "adding terms"<< std::endl;
				tmp->get_story()->add_variable(tmp_term);
			}
			*/


		}
	}


	return LoaderWizard::Page_Validation;
	//return -1;
}
qint64 LoaderParamSettingPage::calculate_time(QDateTime _date){
	qint64 ellapsed_second_target=this->current_doc->get_startdate().toMSecsSinceEpoch();
	qint64 ellapsed_second_query=_date.toMSecsSinceEpoch();
	qint64 difference=ellapsed_second_target -ellapsed_second_query;
	//QDateTime my_final=QDateTime::fromMSecsSinceEpoch(difference);
	return difference;
}
