#include "annotationdialog.h"

AnnotationDialog::AnnotationDialog(QWidget * parent)
	: QDialog(parent)
{
	this->tag_label=new QLabel("Tag :");
	this->annotation_label=new QLabel("Annotation :");
	this->tag_edit=new QLineEdit;
	this->annotation_edit=new QTextEdit;
	this->tag_label->setBuddy(tag_edit);
	this->annotation_label->setBuddy(annotation_edit);


	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));


	QHBoxLayout * tag_layout=new QHBoxLayout;
	tag_layout->addWidget(tag_label);
	tag_layout->addWidget(tag_edit);
	QHBoxLayout * annotation_layout=new QHBoxLayout;
	annotation_layout->addWidget(annotation_label);
	annotation_layout->addWidget(annotation_edit);

	connect(this->annotation_edit,SIGNAL(textChanged()),this,SLOT(enabling_ok_button()));
	QHBoxLayout * button_layout=new QHBoxLayout;
	button_layout->addWidget(this->okButton);
	button_layout->addWidget(this->cancelButton);
	connect(this->okButton,SIGNAL(clicked()),this,SLOT(receive_annotation_tag()));
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QVBoxLayout * vLayout=new QVBoxLayout;
	vLayout->addLayout(tag_layout);
	vLayout->addLayout(annotation_layout);
	vLayout->addLayout(button_layout);
	this->setLayout(vLayout);
}
AnnotationDialog::AnnotationDialog(QString _tag,QWidget * parent)
	: QDialog(parent)
{
	this->tag_label=new QLabel("Tag :");
	this->annotation_label=new QLabel("Annotation :");
	this->tag_edit=new QLineEdit;
	this->tag_edit->setText(_tag);
	this->tag_edit->setEnabled(false);
	this->annotation_edit=new QTextEdit;
	this->tag_label->setBuddy(tag_edit);
	this->annotation_label->setBuddy(annotation_edit);


	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));


	QHBoxLayout * tag_layout=new QHBoxLayout;
	tag_layout->addWidget(tag_label);
	tag_layout->addWidget(tag_edit);
	QHBoxLayout * annotation_layout=new QHBoxLayout;
	annotation_layout->addWidget(annotation_label);
	annotation_layout->addWidget(annotation_edit);

	connect(this->annotation_edit,SIGNAL(textChanged()),this,SLOT(enabling_ok_button()));
	QHBoxLayout * button_layout=new QHBoxLayout;
	button_layout->addWidget(this->okButton);
	button_layout->addWidget(this->cancelButton);
	connect(this->okButton,SIGNAL(clicked()),this,SLOT(receive_annotation_tag()));
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QVBoxLayout * vLayout=new QVBoxLayout;
	vLayout->addLayout(tag_layout);
	vLayout->addLayout(annotation_layout);
	vLayout->addLayout(button_layout);
	this->setLayout(vLayout);
}
void AnnotationDialog::enabling_ok_button(){
	this->okButton->setEnabled(true);
}

void AnnotationDialog::receive_annotation_tag(){
	QString annot=annotation_edit->toPlainText();
	QString tag=tag_edit->text();
	emit send_annotation_tag(tag,annot);
	this->close();

}
