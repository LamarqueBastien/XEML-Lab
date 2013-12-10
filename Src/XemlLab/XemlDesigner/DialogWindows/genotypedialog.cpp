#include "genotypedialog.h"

GenotypeDialog::GenotypeDialog(QWidget * parent)
: QDialog(parent)
{

	pool=new IndividualsPool();
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
	//list_id_label->push_back(text);

	this->idEdit->setText(text);
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

	QString idtext= idEdit->text();
	QString freetext = this->free_annotEdit->toPlainText();
	QString taxontext = this->taxonEdit->text();
	emit this->genotype_added(pool,idtext,freetext,taxontext);
	this->close();


}
