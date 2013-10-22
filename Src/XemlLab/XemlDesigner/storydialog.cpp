#include <QtGui>
#include "storydialog.h"

StoryDialog::StoryDialog(QWidget * parent)
	: QDialog(parent)
{

	this->label = new QLabel(tr("Label :"));
	labelEdit = new QLineEdit;
	this->label->setBuddy(labelEdit);

	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));

	connect(labelEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));



	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(label);
	topleftLayout->addWidget(labelEdit);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
	setWindowTitle(tr("story informations"));
	setFixedHeight((sizeHint().height()));



}
void StoryDialog::enabledOkButton(const QString &text){
	this->okButton->setEnabled(true);
}
void StoryDialog::OkClicked(){
	QString text= labelEdit->text();
	emit this->mon_signal(text);

}


