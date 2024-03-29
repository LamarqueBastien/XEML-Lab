#include "ontologypanel.h"

OntologyPanel::OntologyPanel(QWidget * parent)
	:QWidget(parent)
{
	EOcheckbox= new QCheckBox("EO ontology", this);
	XEOcheckbox= new QCheckBox("XEO ontology", this);
	EnvOcheckbox= new QCheckBox("EnvO ontology", this);
	this->okButton=new QPushButton("OK");
	this->cancelButton=new QPushButton("Cancel");
	QVBoxLayout * layout=new QVBoxLayout;
	QHBoxLayout * buttonLayout=new QHBoxLayout;
	buttonLayout->addWidget(this->okButton);
	buttonLayout->addWidget(this->cancelButton);
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	connect(this->okButton,SIGNAL(clicked()),this,SLOT(set_up_end()));
	this->setWindowTitle("Ontology manager");
	layout->addWidget(EOcheckbox);
	layout->addWidget(XEOcheckbox);
	layout->addWidget(EnvOcheckbox);
	layout->addLayout(buttonLayout);
	this->setLayout(layout);


}
void OntologyPanel::initialize(DocumentResources * _doc){
	this->XEOcheckbox->setChecked(false);
	this->EOcheckbox->setChecked(false);
	this->EnvOcheckbox->setChecked(false);
	if(_doc->contains("XEO",Xeml::Document::Contracts::Environment)){
		this->XEOcheckbox->setChecked(true);

	}

	if(_doc->contains("EO",Xeml::Document::Contracts::EO)){
		this->EOcheckbox->setChecked(true);
	}
	if(_doc->contains("EnvO",Xeml::Document::Contracts::EnvO)){
		this->EnvOcheckbox->setChecked(true);
	}
}
void OntologyPanel::set_up_end(){
	if(this->XEOcheckbox->isChecked() ){//&& this->XEOcheckbox->isEnabled()){
		XEO_ischecked=true;
	}
	if(this->EOcheckbox->isChecked() ){//&& this->EOcheckbox->isEnabled()){
		EO_ischecked=true;
	}
	if(this->EnvOcheckbox->isChecked()){//&& this->EnvOcheckbox->isEnabled()){
		EnvO_ischecked=true;
	}
	emit ontologies_to_load(XEO_ischecked,EO_ischecked,EnvO_ischecked);
	this->close();
}


