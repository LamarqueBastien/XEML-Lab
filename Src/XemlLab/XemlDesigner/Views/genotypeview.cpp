#include "genotypeview.h"

GenotypeView::GenotypeView(QWidget *parent) :
	QWidget(parent)
{
	this->addGenotype=new QPushButton("add");
	/*
	this->addGenotype->setStyleSheet(
				"background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
				//"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);"
				"border-style: outset;"
				"border-width: 1px;"
				"border-radius: 10px;"
				"border-color: beige;"
				"font: bold 10px;"
				"color:black;"
				"min-width: 10em;"
				"min-height: 0.95em;"
				"margin: 0 1px 0 1px;"
				"color:rgb(0,0,0);"
				"padding: 6px;"
			);
			*/
	this->addGenotype->setCursor(Qt::PointingHandCursor);
	this->removeGenotype=new QPushButton("remove");
	/*
	this->removeGenotype->setStyleSheet(
				"background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
				//"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);"
				"border-style: outset;"
				"border-width: 1px;"
				"border-radius: 10px;"
				"border-color: beige;"
				"font: bold 10px;"
				"color:black;"
				"min-width: 10em;"
				"min-height: 0.95em;"
				"margin: 0 1px 0 1px;"
				"color:rgb(0,0,0);"
				"padding: 6px;"
			);*/
	this->removeGenotype->setCursor(Qt::PointingHandCursor);
	
	this->Edit=new QPushButton("Edit");
	/*
	this->Edit->setStyleSheet(
				"background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
				//"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);"
				"border-style: outset;"
				"border-width: 1px;"
				"border-radius: 10px;"
				"border-color: beige;"
				"font: bold 10px;"
				"color:black;"
				"min-width: 10em;"
				"min-height: 0.95em;"
				"margin: 0 1px 0 1px;"
				"color:rgb(0,0,0);"
				"padding: 6px;"
			);
			*/
	this->Edit->setCursor(Qt::PointingHandCursor);
	
	
	this->gpp= new GermPlasmPanel;
	connect(this->addGenotype,SIGNAL(clicked()),this,SLOT(add_genotype()));
	connect(this->removeGenotype,SIGNAL(clicked()),this,SLOT(remove_genotype()));
	connect( this->Edit,SIGNAL(clicked()),this,SLOT(edit_genotype()));

	QHBoxLayout * layout = new QHBoxLayout;
	layout->addWidget(this->gpp);
	QVBoxLayout * bottomLayout=new QVBoxLayout;
	bottomLayout->addStretch();
	bottomLayout->addWidget(Edit);
	bottomLayout->addWidget(removeGenotype);
	bottomLayout->addWidget(addGenotype);
	layout->addLayout(bottomLayout);
	this->setObjectName("GenotypeView");
	setLayout(layout);
	/*
	this->setStyleSheet(
					"background-color: rgb(255,255,255);"
					"border-radius: 10px;"
				);*/




}
void GenotypeView::clean_view(){
	this->gpp->clean_model();
}
void GenotypeView::edit_genotype(){

	//retrieve all information about the selected pool
	if (this->gpp->get_germplasm()!=""){
		QString germplasm=this->gpp->get_germplasm();
		std::cerr << "germplasm : " << germplasm.toStdString() << std::endl;
		for(std::list<StoryNode*>::iterator it=this->currentDoc->get_storyboard()->get_storyBoard()->begin();it!=this->currentDoc->get_storyboard()->get_storyBoard()->end();++it){
			if((*it)->get_parent()==NULL){

				Story * current= static_cast<Story*>((*it)->get_story());
				//std::map<IndividualsPool*,QString>::iterator it_to_erase;
				if (!current->get_individualspoolcollection()->empty()){
					for(std::map<IndividualsPool*,QString>::iterator it2 = current->get_individualspoolcollection()->begin();it2!=current->get_individualspoolcollection()->end();++it2){

						if ((*it2).first->get_germplasm()==germplasm){
							//it_to_erase=it;
							//delete (*it).first;
							this->new_genotype =new GenotypeDialog(this->currentDoc,(*it2).first);
							this->new_genotype->show();
							connect(this->new_genotype,SIGNAL(genotype_edited(ItfDocument*)),this,SLOT(refresh_view(ItfDocument*)));
							//this->refresh_view();
						}
					}
					//current->get_individualspoolcollection()->erase(it_to_erase);
				}

			}
		}


	}
	else{
		QMessageBox::information(this,"added element","No pool selected clicked on row number");

		//QMessageBox::Information
	}




}
void GenotypeView::remove_genotype(){

		this->gpp->remove_row();


}

void GenotypeView::add_genotype(){
	this->new_genotype =new GenotypeDialog();
	connect(this->new_genotype,SIGNAL(genotype_added(IndividualsPool*)),this,SLOT(genotype_to_add(IndividualsPool*)));
	new_genotype->show();

}
void GenotypeView::refresh_view(ItfDocument * _xemldoc){
	//std::cerr << "refresh view" << std::endl;
	this->gpp->clean_model();
	this->gpp->initialize(_xemldoc);
	this->show();
}

void GenotypeView::genotype_to_add(IndividualsPool* _pool){
	//std::cerr << "new genotypes : " << _idtext.toStdString() << std::endl;

	emit this->on_new_genotype(_pool);
}

void GenotypeView::initialize(ItfDocument * _xemlDoc){
	this->currentDoc=_xemlDoc;



	this->gpp->initialize(_xemlDoc);
}
