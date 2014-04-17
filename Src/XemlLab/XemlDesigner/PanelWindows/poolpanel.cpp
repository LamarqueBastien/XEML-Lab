#include "poolpanel.h"

PoolPanel::PoolPanel(QWidget * parent)
	:QWidget(parent)
{
	view = new QTableView();
	this->view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	model = new QStandardItemModel(this); //1 Rows and 2 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("individuals Id")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("Pool Id")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("ObservationPoint Id")));
	view->setModel(model);
	QHBoxLayout * mainLayout= new QHBoxLayout;
	mainLayout->addWidget(view);
	setLayout(mainLayout);
	setWindowTitle(tr("story informations"));

}
void PoolPanel::initialize(StoryBase * _story,bool _isStorySplit){


	if(_isStorySplit){
		model->setItem(0,1,new QStandardItem("none (same as parent"));
	}
	else{
		QString fqName;
		Story * current=static_cast<Story*>(_story);
		std::vector<IndividualsPool*> *listpool= new std::vector<IndividualsPool*>();
		std::vector<Individual*> *listind= new std::vector<Individual*>();
		std::vector<TaggedAnnotation*> *listtag= new std::vector<TaggedAnnotation*>();
		int intnum;
		for(std::map<IndividualsPool*,QString>::iterator it = current->get_individualspoolcollection()->begin();it!=current->get_individualspoolcollection()->end();++it){

			listpool->push_back((*it).first);
			for(std::map<Individual*,int>::iterator it2=static_cast<IndividualsPool*>((*it).first)->get_individualscollection()->begin();it2!=static_cast<IndividualsPool*>((*it).first)->get_individualscollection()->end();++it2){

				listind->push_back((*it2).first);
			}

		}

		if(!listpool->empty()){

			intnum=listpool->at(0)->count_individuals();
			fqName=listpool->at(0)->get_germplasm();

			for(std::map<TaggedAnnotation*,QString>::iterator it3 = listpool->at(0)->get_taggedannotation()->begin();it3!=listpool->at(0)->get_taggedannotation()->end();++it3){
				listtag->push_back((*it3).first);
			}
			for(size_t i = 0;i<listtag->size();i++){
				model->setHorizontalHeaderItem(i+1, new QStandardItem(listtag->at(i)->getTag()));
			}
		}
		else{
			intnum =0;
		}
		for(int i=0;i<intnum;i++){

			model->setItem(i,0,new QStandardItem(QString::number(listind->at(i)->get_id())));
			model->setItem(i,1,new QStandardItem(fqName));

			for(size_t j = 0;j<listtag->size();j++){
				model->setItem(i,j+1,new QStandardItem(listtag->at(j)->getAnnotation()));

			}
		}
		for (int i= 0;i<model->rowCount();i++){
			for (int j=0;j<model->columnCount();j++){
				if (model->item(i,j)!=NULL){
					model->item(i,j)->setEditable(false);
				}
			}
		}
	}
}

