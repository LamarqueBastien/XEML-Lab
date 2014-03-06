#include "genotypedialog.h"

GenotypeDialog::GenotypeDialog(QWidget * parent)
: QDialog(parent)
{

	pool=new IndividualsPool();

	this->EditMode=false;




	this->list_id_label=new QStringList;
	this->id_label=new QLabel("Id");
	this->idEdit= new QLineEdit;
	this->idEdit->setEnabled(false);
	this->id_label->setBuddy(idEdit);
	annotation_id= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->species_label=new QLabel("Species");
	this->speciesEdit= new QLineEdit;
	this->species_label->setBuddy(speciesEdit);
	annotation_species= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->taxon_label=new QLabel("NCBI Taxonomy ID");
	this->taxonEdit= new QLineEdit;
	this->taxon_label->setBuddy(taxonEdit);

	this->accession_label=new QLabel("Accession");
	this->accessionEdit= new QLineEdit;
	this->accession_label->setBuddy(accessionEdit);
	annotation_accession= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->mutant_label=new QLabel("Mutant");
	this->mutantEdit= new QLineEdit;
	this->mutant_label->setBuddy(mutantEdit);
	annotation_mutant= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->transgenic_label=new QLabel("Transgenic Modification");
	this->transgenicEdit= new QLineEdit;
	this->transgenic_label->setBuddy(transgenicEdit);
	annotation_transgenic= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->free_annot_label=new QLabel("Free Annotation");
	this->free_annotEdit= new QTextEdit;
	this->free_annot_label->setBuddy(free_annotEdit);




	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));
	this->cancelButton->setCursor(Qt::PointingHandCursor);

	//individuals handlers region
	this->addIndividuals=new QPushButton("Add individuals");


	//connect(this->import_from_files,SIGNAL())
	this->individuals_count_label=new QLabel("population :");
	this->individuals_countEdit= new QLineEdit;
	this->individuals_countEdit->setEnabled(false);
	this->individuals_count_label->setBuddy(individuals_countEdit);




	connect(annotation_id,SIGNAL(clicked()),this,SLOT(add_tag_id()));
	connect(annotation_species,SIGNAL(clicked()),this,SLOT(add_tag_species()));
	connect(annotation_accession,SIGNAL(clicked()),this,SLOT(add_tag_accession()));
	connect(annotation_mutant,SIGNAL(clicked()),this,SLOT(add_tag_mutant()));
	connect(annotation_transgenic,SIGNAL(clicked()),this,SLOT(add_tag_transgenic()));


	//connect(individuals_countEdit,SIGNAL(textChanged(QString)),this,SLOT(enabledOkButton(QString)));
	connect(addIndividuals,SIGNAL(clicked()),this,SLOT(on_add_individuals_clicked()));
	connect(speciesEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(speciesEdit,SIGNAL(textChanged(const QString &)),this,SLOT(add_species_label(const QString &)));
	connect(mutantEdit,SIGNAL(textChanged(QString)),this,SLOT(add_mutant_label(QString)));
	connect(accessionEdit,SIGNAL(textChanged(QString)),this,SLOT(add_accession_label(QString)));
	connect(transgenicEdit,SIGNAL(textChanged(QString)),this,SLOT(add_transgenic_label(QString)));

	//connecter
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(id_label);
	topleftLayout->addWidget(idEdit);
	topleftLayout->addWidget(annotation_id);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(species_label);
	topleftLayout2->addWidget(speciesEdit);
	topleftLayout2->addWidget(annotation_species);
	QHBoxLayout * topleftLayout3 = new QHBoxLayout;
	topleftLayout3->addWidget(taxon_label);
	topleftLayout3->addWidget(taxonEdit);
	QHBoxLayout * topleftLayout4 = new QHBoxLayout;
	topleftLayout4->addWidget(accession_label);
	topleftLayout4->addWidget(accessionEdit);
	topleftLayout4->addWidget(annotation_accession);
	QHBoxLayout * topleftLayout5 = new QHBoxLayout;
	topleftLayout5->addWidget(mutant_label);
	topleftLayout5->addWidget(mutantEdit);
	topleftLayout5->addWidget(annotation_mutant);
	QHBoxLayout * topleftLayout6 = new QHBoxLayout;
	topleftLayout6->addWidget(transgenic_label);
	topleftLayout6->addWidget(transgenicEdit);
	topleftLayout6->addWidget(annotation_transgenic);
	QHBoxLayout * topleftLayout7 = new QHBoxLayout;
	topleftLayout7->addWidget(free_annot_label);
	topleftLayout7->addWidget(free_annotEdit);

	/*QGridLayout * individualsGrid=new QGridLayout;
	individualsGrid->addWidget(this->addIndividuals,0,0);
	individualsGrid->addWidget(this->import_from_files,0,1);
	individualsGrid->addWidget(this->individuals_count_label,2,0);
	individualsGrid->addWidget(this->individuals_countEdit,2,1);
	individualsGrid->addWidget(this->browseButton,1,1);
	individualsGrid->addWidget(this->number_individuals,1,0);
	*/

	table[0]="";
	table[1]="";
	table[2]="";
	table[3]="";

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);
	leftLayout->addLayout(topleftLayout2);
	leftLayout->addLayout(topleftLayout3);
	leftLayout->addLayout(topleftLayout4);
	leftLayout->addLayout(topleftLayout5);
	leftLayout->addLayout(topleftLayout6);
	leftLayout->addLayout(topleftLayout7);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);

	rightLayout->addWidget(addIndividuals);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
	setWindowTitle(tr("Germplasm EditForm"));
	setFixedHeight((sizeHint().height()));
	setFixedWidth((sizeHint().width()));

}

void  GenotypeDialog::on_add_individuals_clicked(){


		IndividualWizard * iw=new IndividualWizard(pool);
		iw->show();

}










GenotypeDialog::GenotypeDialog(ItfDocument * _xemldoc,IndividualsPool * _pool,QWidget * parent)
: QDialog(parent)
{

	this->current_doc=_xemldoc;
	pool=_pool;
	this->EditMode=true;
	QString poolId,species,accession,mutant,transgen,freetext,taxonId;

	QStringList tmplist=pool->get_germplasm().split(".");
	poolId=	_pool->get_germplasm();

	//problem si l'utilisateur n'a pas rentré 4 nom séparé par un point
	species=tmplist.at(0);
	accession=tmplist.at(1);
	mutant=tmplist.at(2);
	transgen=tmplist.at(3);
	for (std::map<TaggedAnnotation*,QString>::iterator it=pool->get_taggedannotation()->begin();it!=pool->get_taggedannotation()->end();++it){
		if(static_cast<TaggedAnnotation*>((*it).first)->getTag()=="FreeText"){
			freetext=static_cast<TaggedAnnotation*>((*it).first)->getAnnotation();
		}
		else if(static_cast<TaggedAnnotation*>((*it).first)->getTag()=="NcbiTaxonomyId"){
			taxonId=static_cast<TaggedAnnotation*>((*it).first)->getAnnotation();
		}
	}





	this->list_id_label=new QStringList;
	this->id_label=new QLabel("Id");
	this->idEdit= new QLineEdit;
	this->idEdit->setText(poolId);
	this->idEdit->setEnabled(false);
	this->id_label->setBuddy(idEdit);
	annotation_id= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->species_label=new QLabel("Species");
	this->speciesEdit= new QLineEdit;
	this->speciesEdit->setText(species);
	table[0]=species;
	this->species_label->setBuddy(speciesEdit);
	annotation_species= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->taxon_label=new QLabel("NCBI Taxonomy ID");
	this->taxonEdit= new QLineEdit;
	this->taxonEdit->setText(taxonId);

	this->taxon_label->setBuddy(taxonEdit);

	this->accession_label=new QLabel("Accession");
	this->accessionEdit= new QLineEdit;
	this->accessionEdit->setText(accession);
	table[1]=accession;
	this->accession_label->setBuddy(accessionEdit);
	annotation_accession= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->mutant_label=new QLabel("Mutant");
	this->mutantEdit= new QLineEdit;
	this->mutantEdit->setText(mutant);
	table[2]=mutant;

	this->mutant_label->setBuddy(mutantEdit);
	annotation_mutant= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->transgenic_label=new QLabel("Transgenic Modification");
	this->transgenicEdit= new QLineEdit;
	this->transgenicEdit->setText(transgen);
	table[3]=transgen;
	this->transgenic_label->setBuddy(transgenicEdit);
	annotation_transgenic= new QPushButton(QIcon(":/Images/annotation.png"),"");

	this->free_annot_label=new QLabel("Free Annotation");
	this->free_annotEdit= new QTextEdit;
	this->free_annotEdit->setText(freetext);
	this->free_annot_label->setBuddy(free_annotEdit);
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->okButton->setDefault(true);
	this->okButton->setEnabled(true);
	this->cancelButton = new QPushButton(tr("Cancel"));
	this->cancelButton->setCursor(Qt::PointingHandCursor);

	//signals/Slots region

	connect(annotation_id,SIGNAL(clicked()),this,SLOT(add_tag_id()));
	connect(annotation_species,SIGNAL(clicked()),this,SLOT(add_tag_species()));
	connect(annotation_accession,SIGNAL(clicked()),this,SLOT(add_tag_accession()));
	connect(annotation_mutant,SIGNAL(clicked()),this,SLOT(add_tag_mutant()));
	connect(annotation_transgenic,SIGNAL(clicked()),this,SLOT(add_tag_transgenic()));

	connect(speciesEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(speciesEdit,SIGNAL(textChanged(const QString &)),this,SLOT(add_species_label(const QString &)));
	connect(mutantEdit,SIGNAL(textChanged(QString)),this,SLOT(add_mutant_label(QString)));
	connect(accessionEdit,SIGNAL(textChanged(QString)),this,SLOT(add_accession_label(QString)));
	connect(transgenicEdit,SIGNAL(textChanged(QString)),this,SLOT(add_transgenic_label(QString)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));


	//layouts region

	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(id_label);
	topleftLayout->addWidget(idEdit);
	topleftLayout->addWidget(annotation_id);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(species_label);
	topleftLayout2->addWidget(speciesEdit);
	topleftLayout2->addWidget(annotation_species);
	QHBoxLayout * topleftLayout3 = new QHBoxLayout;
	topleftLayout3->addWidget(taxon_label);
	topleftLayout3->addWidget(taxonEdit);
	QHBoxLayout * topleftLayout4 = new QHBoxLayout;
	topleftLayout4->addWidget(accession_label);
	topleftLayout4->addWidget(accessionEdit);
	topleftLayout4->addWidget(annotation_accession);
	QHBoxLayout * topleftLayout5 = new QHBoxLayout;
	topleftLayout5->addWidget(mutant_label);
	topleftLayout5->addWidget(mutantEdit);
	topleftLayout5->addWidget(annotation_mutant);
	QHBoxLayout * topleftLayout6 = new QHBoxLayout;
	topleftLayout6->addWidget(transgenic_label);
	topleftLayout6->addWidget(transgenicEdit);
	topleftLayout6->addWidget(annotation_transgenic);
	QHBoxLayout * topleftLayout7 = new QHBoxLayout;
	topleftLayout7->addWidget(free_annot_label);
	topleftLayout7->addWidget(free_annotEdit);



	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);
	leftLayout->addLayout(topleftLayout2);
	leftLayout->addLayout(topleftLayout3);
	leftLayout->addLayout(topleftLayout4);
	leftLayout->addLayout(topleftLayout5);
	leftLayout->addLayout(topleftLayout6);
	leftLayout->addLayout(topleftLayout7);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
	setWindowTitle(tr("Germplasm EditForm"));
	setFixedHeight((sizeHint().height()));

}
void GenotypeDialog::add_tag_id(){

	this->annot_dialog=new AnnotationDialog("Id");
	connect(this->annot_dialog,SIGNAL(send_annotation_tag(QString,QString)),this,SLOT(add_tagged_annotation(QString,QString)));
	this->annot_dialog->exec();
}
void GenotypeDialog::add_tag_species(){

	this->annot_dialog=new AnnotationDialog("Species");
	connect(this->annot_dialog,SIGNAL(send_annotation_tag(QString,QString)),this,SLOT(add_tagged_annotation(QString,QString)));
	this->annot_dialog->exec();
}
void GenotypeDialog::add_tag_accession(){
	this->annot_dialog=new AnnotationDialog("Accession");
	connect(this->annot_dialog,SIGNAL(send_annotation_tag(QString,QString)),this,SLOT(add_tagged_annotation(QString,QString)));
	this->annot_dialog->exec();

}
void GenotypeDialog::add_tag_mutant(){
	this->annot_dialog=new AnnotationDialog("Mutant");
	connect(this->annot_dialog,SIGNAL(send_annotation_tag(QString,QString)),this,SLOT(add_tagged_annotation(QString,QString)));
	this->annot_dialog->exec();

}

void GenotypeDialog::add_tag_transgenic(){
	this->annot_dialog=new AnnotationDialog("Transgenic");
	connect(this->annot_dialog,SIGNAL(send_annotation_tag(QString,QString)),this,SLOT(add_tagged_annotation(QString,QString)));
	this->annot_dialog->exec();

}
void GenotypeDialog::add_tagged_annotation(QString _tag,QString _annot){
	pool->add_tagged_annotation(new TaggedAnnotation(_tag,_annot));

}


void GenotypeDialog::add_species_label(const QString &text){
	table[0]=text;
	QString textId;
	//list_id_label->push_back(text);

	for(int i = 0;i<4;i++){
		if(i==0){
			textId+=table[i];
		}
		else{
			if(table[i]==""){
				table[i]="_";
			}
			if(table[i]=="_" && i==3){
				textId+="";
			}
			else{
				textId+="."+table[i];
			}

		}
	}
	this->idEdit->setText(textId);
}
void GenotypeDialog::add_mutant_label(const QString &text){
	table[2]=text;
	QString textId;

	for(int i = 0;i<4;i++){
		if(i==0){
			textId+=table[i];
		}
		else{
			if(table[i]==""){
				table[i]="_";
			}
			if(table[i]=="_" && i==3){
				textId+="";
			}
			else{
				textId+="."+table[i];
			}

		}
	}
	this->idEdit->setText(textId);
}
void GenotypeDialog::add_accession_label(const QString &text){
	table[1]=text;
	//list_id_label->push_back(text);
	QString textId;

	for(int i = 0;i<4;i++){
		if(i==0){
			textId+=table[i];
		}
		else{
			if(table[i]==""){
				table[i]="_";
			}
			if(table[i]=="_" && i==3){
				textId+="";
			}
			else{
				textId+="."+table[i];
			}

		}
	}
	this->idEdit->setText(textId);
}
void GenotypeDialog::add_transgenic_label(const QString &text){
	table[3]=text;
	QString textId;
	for(int i = 0;i<4;i++){
		if(i==0){
			textId+=table[i];
		}
		else{
			if(table[i]==""){
				table[i]="_";
			}
			if(table[i]=="_" && i==3){
				textId+="";
			}
			else{
				textId+="."+table[i];
			}

		}
	}
	this->idEdit->setText(textId);
}

void GenotypeDialog::enabledOkButton(const QString &text){
	this->okButton->setEnabled(true);

}
void GenotypeDialog::OkClicked(){



	//pool->set_ns("none");

	QString idtext= idEdit->text();
	QString freetext = this->free_annotEdit->toPlainText();
	QString taxontext = this->taxonEdit->text();
	pool->set_germplasm(idtext);
	//pool->add_Individual();
	if((!freetext.isEmpty())&&(!freetext.isNull())){
		pool->add_tagged_annotation(new TaggedAnnotation("FreeText",freetext));
	}
	if((!taxontext.isEmpty())&&(!taxontext.isNull())){
		pool->add_tagged_annotation(new TaggedAnnotation("NcbiTaxonomyId",taxontext));
	}
	if (EditMode){
		emit this->genotype_edited(current_doc);
	}
	else{
		emit this->genotype_added(pool);
	}

	this->close();


}
