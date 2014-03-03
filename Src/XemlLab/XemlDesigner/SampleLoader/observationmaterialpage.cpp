#include "observationmaterialpage.h"

ObservationMaterialPage::ObservationMaterialPage(DocumentResources * _doc_resources,QWidget *parent)
	: QWizardPage(parent)
{
	this->doc_resources =_doc_resources;
	setTitle(tr("Material"));
	setSubTitle(tr("Specify structural and positioning (e.g.height From ground etc..) conditions used for these samples"));
	this->structEdit= new QLineEdit;
	this->structLabel=new QLabel("Plant Structure");
	this->structLabel->setBuddy(structEdit);
	this->idEdit= new QLineEdit;
	this->idLabel=new QLabel("Id");
	this->nameEdit= new QLineEdit;
	this->nameLabel=new QLabel("Name");
	this->structnameEdit= new QLineEdit;
	this->structnameLabel=new QLabel("Name");
	this->UnitEdit= new QLineEdit;
	this->UnitLabel=new QLabel("Unit");
	this->ValueEdit= new QLineEdit;
	this->ValueLabel=new QLabel("Value");
	this->QValueEdit= new QLineEdit;
	this->QValueLabel=new QLabel("QValue");
	this->idLabel->setBuddy(idEdit);
	this->replica = new QLabel("Replica") ;
	this->repBox=new QSpinBox;
	this->replica->setBuddy(this->repBox);
	this->structView= new ParameterTreeView(false,this->doc_resources);
	connect(this->structView,SIGNAL(onParameterselected(ItfOntologyTerm*)),this,SLOT(get_structTerm(ItfOntologyTerm*)));

	this->posView=new ParameterTreeView(false,this->doc_resources);
	connect(this->posView,SIGNAL(onParameterselected(ItfOntologyTerm*)),this,SLOT(get_posTerm(ItfOntologyTerm*)));


	QHBoxLayout * mainlayout=new QHBoxLayout;

	mainlayout->addWidget(this->structView);


	QHBoxLayout * Qvaluelayout=new QHBoxLayout;
	Qvaluelayout->addWidget(QValueLabel);
	Qvaluelayout->addWidget(QValueEdit);

	QHBoxLayout * structlayout=new QHBoxLayout;
	structlayout->addWidget(structLabel);
	structlayout->addWidget(structEdit);

	QHBoxLayout * structnamelayout=new QHBoxLayout;
	structnamelayout->addWidget(structnameLabel);
	structnamelayout->addWidget(structnameEdit);

	QHBoxLayout * unitlayout=new QHBoxLayout;
	unitlayout->addWidget(UnitLabel);
	unitlayout->addWidget(UnitEdit);

	QHBoxLayout * replayout=new QHBoxLayout;
	replayout->addWidget(replica);
	replayout->addWidget(this->repBox);

	QHBoxLayout * idlayout=new QHBoxLayout;
	idlayout->addWidget(idLabel);
	idlayout->addWidget(idEdit);

	QHBoxLayout * namelayout=new QHBoxLayout;
	idlayout->addWidget(nameLabel);
	idlayout->addWidget(nameEdit);

	QHBoxLayout * valuelayout=new QHBoxLayout;
	valuelayout->addWidget(ValueLabel);
	valuelayout->addWidget(ValueEdit);





	mainlayout->addWidget(this->posView);



	QVBoxLayout * poslayout=new QVBoxLayout;

	poslayout->addLayout(structlayout);
	poslayout->addLayout(structnamelayout);
	poslayout->addLayout(idlayout);
	poslayout->addLayout(namelayout);
	poslayout->addLayout(valuelayout);
	poslayout->addLayout(unitlayout);
	poslayout->addLayout(Qvaluelayout);
	poslayout->addLayout(replayout);


	mainlayout->addLayout(poslayout);



	setLayout(mainlayout);
	registerField("StructTermID*",structEdit);
	registerField("PosTermName*",nameEdit);
	registerField("PosTermId*",idEdit);
	registerField("Replica*",repBox);
	registerField("Unit*",UnitEdit);
	registerField("QValue*",QValueEdit);
	registerField("Value*",ValueEdit);
	registerField("structName*",structnameEdit);





}
void ObservationMaterialPage::get_structTerm(ItfOntologyTerm * _term){
	this->structEdit->setText(_term->get_termId());
	this->structnameEdit->setText(_term->get_prototype()->get_name());
}
void ObservationMaterialPage::get_posTerm(ItfOntologyTerm * _term){
	this->aboutParameter=new AboutParameter;
	this->aboutParameter->set_term(_term);
	connect(this->aboutParameter,SIGNAL(set_up_finished(ItfOntologyTerm*)),this,SLOT(add_details_about_term(ItfOntologyTerm*)));

	this->aboutParameter->initialize();
	this->aboutParameter->setVisible(true);

}
void ObservationMaterialPage::add_details_about_term(ItfOntologyTerm * _term){

	this->idEdit->setText(_term->get_termId());
	this->nameEdit->setText(_term->get_prototype()->get_name());
	QStringList * values =new QStringList;
	for(std::map<ValueBase*,QString>::iterator it=static_cast<VariableTerm*>(_term->get_prototype())->get_valuecollection()->begin();it!=static_cast<VariableTerm*>(_term->get_prototype())->get_valuecollection()->end();++it){
		values->append(static_cast<Value*>((*it).first)->get_val());
		if(static_cast<Value*>((*it).first)->get_context()=="Quantity"){
			this->QValueEdit->setText(static_cast<Value*>((*it).first)->get_val());
			this->UnitEdit->setText(static_cast<Value*>((*it).first)->get_unit());
		}
		else{
			this->ValueEdit->setText(static_cast<Value*>((*it).first)->get_val());
		}
	}
}

void ObservationMaterialPage::initializePage(){
	QStringList * dev_onto = new QStringList;
	dev_onto->append("PO_Structure");
	this->structView->set_up_Ontologytree(this->doc_resources,dev_onto);
	dev_onto->clear();
	dev_onto->append("XEO_Positioning");
	this->posView->set_up_Ontologytree(this->doc_resources,dev_onto);
}
