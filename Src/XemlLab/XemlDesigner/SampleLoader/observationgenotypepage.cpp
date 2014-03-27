#include "observationgenotypepage.h"

ObservationGenotypePage::ObservationGenotypePage(QStringList * _genList,QWidget *parent)
	: QWizardPage(parent)
{

	//std::cerr << "entering new genotype page" << std::endl;

	setTitle(tr("Class Information"));
	setSubTitle(tr("Select by clicking on genotypes you want to associate with your samples "));

	//this->germPlasm =new QLabel("Germplasm");
	//this->germPlasmEdit =new QLineEdit();
	//this->germPlasm->setBuddy(this->germPlasmEdit);
	this->genModel = new QStringListModel((*_genList));

	this->genView= new QListView;
	genView->setModel(this->genModel);
	genView->setSelectionMode(QAbstractItemView::MultiSelection);


	qRegisterMetaType<QItemSelectionModel*>("QItemSelectionModel*");
	registerField("genViewSelection", this, "selectionModel");

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(this->genView);
	QHBoxLayout * bottomLayout = new QHBoxLayout;
	//bottomLayout->addWidget(this->germPlasm);
	//bottomLayout->addWidget(this->germPlasmEdit);
	layout->addLayout(bottomLayout);
	setLayout(layout);

	//connect(this->genView,SIGNAL(indexesMoved(QModelIndexList)),this,SLOT(validate_list(QModelIndexList)));

	connect(this->genView,SIGNAL(clicked(QModelIndex)),this,SLOT(validate(QModelIndex)));
	//connect(this->genView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(validate(QModelIndex)));
	//registerField("GermPlasm*", this->germPlasmEdit);


}
void ObservationGenotypePage::validate(QModelIndex _QMI){
		//QModelIndexList list=static_cast<QItemSelectionModel*>(field("genViewSelection").value<QItemSelectionModel*>())->selectedRows();
		//QVariant selectedElement = this->genModel->data(_QMI, Qt::DisplayRole);
		//this->germPlasmEdit->setText(selectedElement.toString());
		//QString germ="";
		//for(int i=0;i<list.size();i++){
		//	germ+=list.at(i).data().toString()%"/";
		//}
		//this->germPlasmEdit->setText(germ);

}
void ObservationGenotypePage::validate_list(QModelIndexList _QMIL){

		//QVariant selectedElement = this->genModel->data(_QMI, Qt::DisplayRole);
		//this->germPlasmEdit->setText(selectedElement.toString());
	QString germ="";
	QVariant selectedElement;
	for(int i=0;i<_QMIL.size();i++)
	{

		selectedElement = this->genModel->data(_QMIL.at(i), Qt::DisplayRole);
		germ+=selectedElement.toString();



	}
	//this->germPlasmEdit->setText(selectedElement.toString());
}
