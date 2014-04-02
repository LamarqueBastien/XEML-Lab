#include <QtGui>
#include "storydialog.h"

StoryDialog::StoryDialog(bool nostory,QWidget * parent)
	: QDialog(parent)
{

	this->label = new QLabel(tr("Label :"));
	labelEdit = new QLineEdit;
	this->label->setBuddy(labelEdit);
	this->is_split=new QCheckBox("Split");
	if(nostory){
		this->is_split->setChecked(false);
		this->is_split->setEnabled(false);

	}
	else{
		this->is_split->setChecked(true);
	}


	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Help | QDialogButtonBox::Reset ,Qt::Vertical);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	buttonBox->button(QDialogButtonBox::Ok)->setDefault(true);
	buttonBox->button(QDialogButtonBox::Ok)->setCursor(Qt::PointingHandCursor);
	buttonBox->button(QDialogButtonBox::Help)->setCursor(Qt::PointingHandCursor);
	buttonBox->button(QDialogButtonBox::Reset)->setCursor(Qt::PointingHandCursor);
	connect(buttonBox,SIGNAL(accepted()),this, SLOT(OkClicked()));
	//connect(buttonBox,SIGNAL(rejected()),this,SLOT(close()));
	connect(buttonBox->button(QDialogButtonBox::Reset),SIGNAL(clicked()),this,SLOT(ResetClicked()));
	connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(show_help()));
	connect(labelEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));

	/*
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));

	connect(labelEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));

	*/


	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(label);
	topleftLayout->addWidget(labelEdit);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	//rightLayout->addWidget(this->cancelButton);
	//rightLayout->addWidget(this->okButton);
	rightLayout->addWidget(this->is_split);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addWidget(buttonBox);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
	setWindowTitle(tr("story informations"));
	setFixedHeight((sizeHint().height()));



}
void StoryDialog::show_help(){
	QMessageBox::about(this,"Story helper","choose a name for your story and click on checkbox if you want to add a storysplit.\n");
}
void StoryDialog::enabledOkButton(const QString &text){
	//this->okButton->setEnabled(true);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

}
void StoryDialog::ResetClicked(){
	this->labelEdit->clear();
	this->is_split->setChecked(false);
}
void StoryDialog::OkClicked(){
	QString text= labelEdit->text();
	if(text!=""){
		if (is_split->isChecked()){
			emit this->new_story_split(text);
		}
		else{
			emit this->new_story(text);

		}
	}
	else{
		QMessageBox::information(this,"empty string","you can't create a story without a label");
		//this->close();

	}

}


