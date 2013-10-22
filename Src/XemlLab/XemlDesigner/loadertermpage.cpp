#include "loadertermpage.h"

LoaderTermPage::LoaderTermPage(DocumentResources * _xeml_res,QWidget * parent)
	:QWidget(parent)
{
	this->xeml_res=_xeml_res;
	std::cerr << "create term page "<< std::endl;
	this->unitBox=new QComboBox;
	this->def_label =new QLabel("Ontology Term Definition");
	QHBoxLayout * mainlayout=new QHBoxLayout;
	QVBoxLayout * superlayout =new QVBoxLayout;


	QVBoxLayout * leftlayout=new QVBoxLayout;
	QVBoxLayout * rightlayout=new QVBoxLayout;
	mainlayout->addLayout(leftlayout);
	mainlayout->addLayout(rightlayout);

	this->term_label=new QLabel("Ontology Term Search for Header : ");
	leftlayout->addWidget(this->term_label);
	//add the term Header
	this->ontoBox=new QComboBox;
	this->ontoBox->addItem("XEO");
	this->ontoBox->addItem("EO");
	this->ontoBox->addItem("EnvO");
	leftlayout->addWidget(this->ontoBox);

	this->onto_trees=new ParameterTreeView(this->xeml_res);
	QStringList * dev_onto = new QStringList;
	dev_onto->append("XEO");
	this->onto_trees->set_up_Ontologytree(this->xeml_res,dev_onto);
	leftlayout->addWidget(this->onto_trees);

	rightlayout->addWidget(this->def_label);
	this->description=new QTextEdit;
	rightlayout->addWidget(this->description);
	rightlayout->addWidget(this->unitBox);

	this->valueBox=new QComboBox;
	rightlayout->addWidget(this->valueBox);


	connect(this->ontoBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(tree_changed(QString)));
	connect(this->onto_trees,SIGNAL(onParameterselected(ItfOntologyTerm*)),this,SLOT(get_Term(ItfOntologyTerm*)));





	superlayout->addLayout(mainlayout);
	QHBoxLayout * bottomlayout =new QHBoxLayout;
	this->termId=new QLineEdit;
	this->cancelButton = new QPushButton("Cancel");
	this->okButton = new QPushButton("OK");
	this->okButton->setEnabled(false);
	this->removeButton=new QPushButton("remove");
	this->removeButton->setEnabled(false);

	connect(this->okButton,SIGNAL(clicked()),this,SLOT(finished()));
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	connect(this->removeButton,SIGNAL(clicked()),this,SLOT(removed()));
	bottomlayout->addWidget(this->termId);
	bottomlayout->addWidget(this->cancelButton);
	bottomlayout->addWidget(this->okButton);
	bottomlayout->addWidget(this->removeButton);
	//setWindowFlags(Qt::WindowStaysOnTopHint);
	superlayout->addLayout(bottomlayout);
	setLayout(superlayout);
	//setWindowFlags(Qt::WindowStaysOnTopHint);
	setWindowTitle(tr("Term/Header Pairing"));

}
void LoaderTermPage::finished(){
	std::cerr << "emit signal details term" << std::endl;
	emit send_details_term(this->current_term,this->unitBox->currentText());
	this->close();
	this->setEnabled(false);
}
void LoaderTermPage::removed(){
	this->current_term=NULL;
	this->unitBox->clear();
	this->description->clear();
	this->valueBox->clear();
	this->termId->clear();
}

void LoaderTermPage::get_Term(ItfOntologyTerm * _term){
	this->current_term=_term;
	this->termId->setText(_term->get_prototype()->get_termId());
	QString def ="Name : " + _term->get_prototype()->get_name()+"\n"+"Id :" + _term->get_prototype()->get_termId() +"\n"+ "Definition : " + _term->get_definition();
	this->description->setText(def);
	if(_term->get_prototype()->get_namespacealias()=="XEO"){
		for(std::map<QString,VariableContextSpec*>::iterator it =static_cast<XeoTerm*>(_term)->get_contextCollection()->begin();it!=static_cast<XeoTerm*>(_term)->get_contextCollection()->end();++it){

			std::vector<std::pair<QString,QString> > * tmp=static_cast<XeoTerm*>(_term)->listUnits((*it).first);


			if(static_cast<XeoTerm*>(_term)->hasDefaultUnit((*it).first)){

				for(std::vector<std::pair<QString,QString> >::iterator it2 =tmp->begin();it2!=tmp->end();++it2){
					//enume->push_back((*it2).first);
					this->unitBox->addItem((*it2).second);

				}
				this->valueBox->clear();
			}
			else{
				if((*it).first!="ResponseRange"){
					std::vector<QString> * enume =new std::vector<QString>();
					for(std::list<TypeSpecifics*>::iterator it3=(*it).second->get_typeDefine()->get_typeSpecifica()->begin();it3!=(*it).second->get_typeDefine()->get_typeSpecifica()->end();++it3){
						enume->push_back(static_cast<Enum*>((*it3))->get_textVal());
						this->valueBox->addItem(static_cast<Enum*>((*it3))->get_textVal());
						this->unitBox->clear();
					}
				}
			}
		}

	}
	this->okButton->setEnabled(true);
	this->removeButton->setEnabled(true);

}

void LoaderTermPage::tree_changed(QString _namespace){
	std::cerr << "NS : " << _namespace.toStdString() << std::endl;
	QStringList * dev_onto = new QStringList;
	dev_onto->append(_namespace);
	this->onto_trees->clean_tree();
	this->onto_trees->set_up_Ontologytree(this->xeml_res,dev_onto);

}

void LoaderTermPage::initializePage(){


	//this->germplasm =field("GermPlasm").toString();
	//this->germplasmEdit->setText(this->germplasm);
	//QStringList * dev_onto = new QStringList;
	//dev_onto->append("XEO");
	//this->onto_trees->set_up_Ontologytree(this->doc_resources,dev_onto);
	//dev_onto->clear();
	//dev_onto->append("XEO_Positioning");
	//this->posView->set_up_Ontologytree(this->doc_resources,dev_onto);
	//set_up_Ontologytree();
}
