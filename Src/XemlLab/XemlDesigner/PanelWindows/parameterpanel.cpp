#include "parameterpanel.h"

ParameterPanel::ParameterPanel(bool _RemoveMode,QWidget * parent)

	:QWidget(parent)
{
	view = new QTableView();
	this->view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	model = new QStandardItemModel(this); //1 Rows and 2 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("term Id")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("term name")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("term context")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QString("IsCycleValue")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QString("unit")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QString("value")));
	model->setHorizontalHeaderItem(6, new QStandardItem(QString("timepoint")));
	model->setHorizontalHeaderItem(7, new QStandardItem(QString("IsMeasured")));




	view->setModel(model);
	QHBoxLayout * mainLayout= new QHBoxLayout;
	mainLayout->addWidget(view);
	if(_RemoveMode){
		this->removeButton=new QPushButton("Remove");
		this->cancelButton=new QPushButton("Cancel");
		mainLayout->addWidget(removeButton);
		mainLayout->addWidget(cancelButton);
		//connect(this->view,SIGNAL())
		connect(this->removeButton,SIGNAL(clicked()),this,SLOT(remove_parameter()));
		connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	}
	setLayout(mainLayout);
	setWindowTitle(tr("parameters informations"));

}
void ParameterPanel::initialize(StoryBase * _story,bool _isStorySplit){
	int cpt=0;

	this->current_story=_story;
	for(std::vector<std::pair<BasicTerm*,QString> >::iterator it = _story->get_variablesCollection()->begin();it!= _story->get_variablesCollection()->end();++it){
		model->setItem(cpt,0,new QStandardItem((*it).second));
		model->setItem(cpt,1,new QStandardItem(static_cast<DynamicTerm*>((*it).first)->get_name()));
		if(static_cast<DynamicTerm*>((*it).first)->get_measured_variable()){
			model->setItem(cpt,7,new QStandardItem("true"));
		}
		else{
			model->setItem(cpt,7,new QStandardItem("false"));

		}


		for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it2=static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->begin();it2!=static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->end();++it2){

			if(static_cast<DynamicValueBase*>((*it2).first)->get_is_cycle()){
				model->setItem(cpt,2,new QStandardItem(static_cast<DynamicValue*>((*it2).first)->get_context()));
				model->setItem(cpt,3,new QStandardItem("Yes"));
				model->setItem(cpt,4,new QStandardItem(static_cast<DynamicValue*>((*it2).first)->get_unit()));


				for (std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it=static_cast<Cycle*>((*it2).first)->get_cycleValues()->begin();it!=static_cast<Cycle*>((*it2).first)->get_cycleValues()->end();++it){
					model->setItem(cpt,5,new QStandardItem(static_cast<DynamicValue*>((*it).first)->get_value()));
					model->setItem(cpt,6,new QStandardItem(static_cast<DynamicValue*>((*it).first)->get_timepoint().toString("hh:mm:ss")));

					cpt++;
				}
			}
			else{
				model->setItem(cpt,2,new QStandardItem(static_cast<DynamicValue*>((*it2).first)->get_context()));
				model->setItem(cpt,3,new QStandardItem("No"));
				model->setItem(cpt,4,new QStandardItem(static_cast<DynamicValue*>((*it2).first)->get_unit()));
				model->setItem(cpt,5,new QStandardItem(static_cast<DynamicValue*>((*it2).first)->get_value()));

				cpt++;

			}

		}
	}


	for (int i= 0;i<model->rowCount();i++){
		for (int j=0;j<model->columnCount();j++){
			if (model->item(i,j)!=NULL){
				model->item(i,j)->setEditable(false);
			}
			else{
				model->setItem(i,j,new QStandardItem(""));
				model->item(i,j)->setEditable(false);
				model->item(i,j)->setBackground(QBrush(Qt::darkGray));

			}
		}
	}


}
void ParameterPanel::remove_parameter(){
	QItemSelectionModel  * selection = this->view->selectionModel();
	QModelIndex indexelementselected= selection->currentIndex();
	if(selection->isSelected(indexelementselected)){
		int row_num=this->model->itemFromIndex(indexelementselected)->row();
		if(this->model->index(row_num,0).data().toString()!=""){

			if(this->model->index(row_num,7).data().toString()=="false"){
				this->current_story->rm_variable(this->model->index(row_num,0).data().toString(),false);
			}
			else{
				this->current_story->rm_variable(this->model->index(row_num,0).data().toString(),true);

			}

			this->close();
		}
		else{
			QMessageBox::information(this,"added element","You need to click on a termID");

		}
	}

}
