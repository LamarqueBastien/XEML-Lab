#include "timedialog.h"

TimeDialog::TimeDialog(QWidget * parent)
	: QDialog(parent)
{
	this->evaluate_time = new QRadioButton(tr("&Evaluate a time parameter"));
	this->register_term_and_story = new QRadioButton(tr("&Register a term and its corresponding story"));
	this->okButton=new QPushButton("OK");
	this->okButton->setDefault(true);
	this->cancelButton=new QPushButton("Cancel");

	register_term_and_story->setChecked(true);

	connect(this->okButton,SIGNAL(clicked()),this,SLOT(validate()));

	QHBoxLayout * buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(this->cancelButton);
	buttonLayout->addWidget(this->okButton);

	QVBoxLayout * checkButtonLayout=new QVBoxLayout;
	checkButtonLayout->addWidget(evaluate_time);
	checkButtonLayout->addWidget(register_term_and_story);

	QHBoxLayout * mainLayout=new QHBoxLayout;
	mainLayout->addLayout(buttonLayout);
	mainLayout->addLayout(checkButtonLayout);

	setLayout(mainLayout);

}
void TimeDialog::validate(){

	if (this->evaluate_time->isChecked()){
		emit is_time(true);
	}
	else{
		emit is_time(false);
	}
}
