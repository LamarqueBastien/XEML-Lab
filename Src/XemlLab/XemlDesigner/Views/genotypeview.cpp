#include "genotypeview.h"

GenotypeView::GenotypeView(QWidget *parent) :
	QWidget(parent)
{
	this->addGenotype=new QPushButton("add");
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
	this->addGenotype->setCursor(Qt::PointingHandCursor);
	this->removeGenotype=new QPushButton("remove");
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
			);
	this->removeGenotype->setCursor(Qt::PointingHandCursor);
	this->gpp= new GermPlasmPanel;
	connect(this->addGenotype,SIGNAL(clicked()),this,SLOT(add_genotype()));
	connect(this->removeGenotype,SIGNAL(clicked()),this,SLOT(remove_genotype()));

	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(this->gpp);
	QHBoxLayout * bottomLayout=new QHBoxLayout;
	bottomLayout->addStretch();
	bottomLayout->addWidget(removeGenotype);
	bottomLayout->addWidget(this->addGenotype);
	layout->addLayout(bottomLayout);
	setLayout(layout);
	this->setStyleSheet(
					"background-color: rgb(255,255,255);"
					"border-radius: 10px;"
				);




}
void GenotypeView::clean_view(){
	this->gpp->clean_model();
}
void GenotypeView::remove_genotype(){

		this->gpp->remove_row();


}

void GenotypeView::add_genotype(){
	this->new_genotype =new GenotypeDialog;
	connect(this->new_genotype,SIGNAL(genotype_added(IndividualsPool*, QString,QString,QString)),this,SLOT(genotype_to_add(IndividualsPool*,QString,QString,QString)));
	new_genotype->show();

}
void GenotypeView::refresh_view(ItfDocument * _xemldoc){
	//std::cerr << "refresh view" << std::endl;
	this->gpp->clean_model();
	this->gpp->initialize(_xemldoc);
	this->show();
}

void GenotypeView::genotype_to_add(IndividualsPool* _pool,QString _idtext,QString _freetext,QString _taxontext){
	//std::cerr << "new genotypes : " << _idtext.toStdString() << std::endl;

	emit this->on_new_genotype(_pool,_idtext,_freetext,_taxontext);
}

void GenotypeView::initialize(ItfDocument * _xemlDoc){
	this->currentDoc=_xemlDoc;



	this->gpp->initialize(_xemlDoc);
}
