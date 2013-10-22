#include "germplasmpanel.h"


GermPlasmPanel::GermPlasmPanel(QWidget * parent)
	:QWidget(parent)
{
	view = new QTableView();
	this->view->setStyleSheet("QTableView QTableCornerButton::section {background: black;border: 2px outset black;}");
	model = new QStandardItemModel(1,7,this); //2 Rows and 3 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("pool Id")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("Species")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("Accession")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QString("Mutant")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QString("Transgenic Modification")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QString("Free Annotation")));
	model->setHorizontalHeaderItem(6, new QStandardItem(QString("Storyname")));
	//model->horizontalHeaderItem(4)
	this->view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	this->view->horizontalHeader()->setStyleSheet("QHeaderView::section {"
												  "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #616161, stop: 0.5 #505050,stop: 0.6 #434343, stop:1 #656565);"
												  "color: white;"
												  "padding-left: 4px;"
												  "border: 1px solid #6c6c6c;"
												  "}");
	//this->view->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	//this->view->verticalHeader()->hide();




	view->setModel(model);
	QHBoxLayout * mainLayout= new QHBoxLayout;
	mainLayout->addWidget(view);
	setLayout(mainLayout);
	setWindowTitle(tr("GermPlasm informations"));

}
void GermPlasmPanel::clean_model(){
	this->model->clear();
}

void GermPlasmPanel::initialize(ItfDocument * _xemlDoc){
	//std::cerr << "entering initialize" << std::endl;
	this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("pool Id")));
	this->model->setHorizontalHeaderItem(1, new QStandardItem(QString("Species")));
	this->model->setHorizontalHeaderItem(2, new QStandardItem(QString("Accession")));
	this->model->setHorizontalHeaderItem(3, new QStandardItem(QString("Mutant")));
	this->model->setHorizontalHeaderItem(4, new QStandardItem(QString("Transgenic Modification")));
	this->model->setHorizontalHeaderItem(5, new QStandardItem(QString("Free Annotation")));
	this->model->setHorizontalHeaderItem(6, new QStandardItem(QString("Storyname")));

	int cpt=0;
	//std::cerr << "size of ip : " << std::endl;

	for(std::list<StoryNode*>::iterator it=_xemlDoc->get_storyboard()->get_storyBoard()->begin();it!=_xemlDoc->get_storyboard()->get_storyBoard()->end();++it){
		//std::cerr << "size of ip2 : " << std::endl;
		if((*it)->get_parent()==NULL){
			//std::cerr << "size of ip3 : " << std::endl;
			Story * current= static_cast<Story*>((*it)->get_story());
			//std::cerr << "size of ip : " << current->get_individualspoolcollection()->size() << std::endl;
			for(std::map<IndividualsPool*,QString>::iterator it = current->get_individualspoolcollection()->begin();it!=current->get_individualspoolcollection()->end();++it){
				QStringList tmplist=(*it).first->get_germplasm().split(".");

				if (tmplist.empty()){

					model->setItem(cpt,0,new GenotypeItem((*it).first->get_germplasm()));
					//std::cerr << "germplasm id empty" << std::endl;
				}
				else if(tmplist.size()==1){
					model->setItem(cpt,0,new GenotypeItem((*it).first->get_germplasm()));

				}
				else{

					model->setItem(cpt,0,new GenotypeItem((*it).first->get_germplasm()));
					model->setItem(cpt,1,new GenotypeItem(tmplist.at(0)));
					model->setItem(cpt,2,new GenotypeItem(tmplist.at(1)));
					model->setItem(cpt,6,new GenotypeItem(current->get_label()));

				}
				cpt++;




			}

		}
	}
	//std::cerr << "size of ip : " << std::endl;
	/*
	if(_isStorySplit){
		model->setItem(0,1,new QStandardItem("none (same as parent"));
	}
	else{
		Story * current=static_cast<Story*>(_story);
		std::vector<IndividualsPool*> *listpool= new std::vector<IndividualsPool*>();
		std::vector<Individual*> *listind= new std::vector<Individual*>();
		std::vector<TaggedAnnotation*> *listtag= new std::vector<TaggedAnnotation*>();

		for(std::map<IndividualsPool*,QString>::iterator it = current->get_individualspoolcollection()->begin();it!=current->get_individualspoolcollection()->end();++it){

			listpool->push_back((*it).first);
			for(std::map<Individual*,int>::iterator it2=static_cast<IndividualsPool*>((*it).first)->get_individualscollection()->begin();it2!=static_cast<IndividualsPool*>((*it).first)->get_individualscollection()->end();++it2){

				listind->push_back((*it2).first);
			}
		}
		int intnum;
		if(!listpool->empty()){

			intnum=listpool->at(0)->count_individuals();

			for(std::map<TaggedAnnotation*,QString>::iterator it3 = listpool->at(0)->get_taggedannotation()->begin();it3!=listpool->at(0)->get_taggedannotation()->end();++it3){
				listtag->push_back((*it3).first);
			}
			for(int i = 0;i<listtag->size();i++){
				model->setHorizontalHeaderItem(i+1, new QStandardItem(QString(listtag->at(i)->getTag().c_str())));
			}
		}
		else{
			intnum =0;
		}
		for(int i=0;i<intnum;i++){

			model->setItem(i,0,new QStandardItem(QString::number(listind->at(i)->get_id())));
			for(int j = 0;j<listtag->size();j++){
				model->setItem(i,j+1,new QStandardItem(QString(listtag->at(j)->getAnnotation().c_str())));

			}
		}
	}
	*/
}


