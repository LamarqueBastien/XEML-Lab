#include "uuiddialog.h"

UuidDialog::UuidDialog(QWidget * parent)
	: QDialog(parent)
{
	//add model of guid
	this->label = new QLabel(tr("Unique identifier :"));
	labelEdit = new QLineEdit;
	labelEdit->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{8}-[a-fA-F0-9]{4}-[a-fA-F0-9]{4}-[a-fA-F0-9]{4}-[a-fA-F0-9]{12}"), this));

	this->label->setBuddy(labelEdit);


	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel |QDialogButtonBox::Help | QDialogButtonBox::Reset ,Qt::Horizontal);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	buttonBox->button(QDialogButtonBox::Ok)->setDefault(true);
	buttonBox->button(QDialogButtonBox::Ok)->setCursor(Qt::PointingHandCursor);
	buttonBox->button(QDialogButtonBox::Cancel)->setCursor(Qt::PointingHandCursor);
	buttonBox->button(QDialogButtonBox::Help)->setCursor(Qt::PointingHandCursor);
	buttonBox->button(QDialogButtonBox::Reset)->setCursor(Qt::PointingHandCursor);
	connect(buttonBox,SIGNAL(accepted()),this, SLOT(OkClicked()));
	connect(buttonBox->button(QDialogButtonBox::Reset),SIGNAL(clicked()),this,SLOT(ResetClicked()));
	connect(buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),this,SLOT(close()));
	connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(show_help()));




	//this->okButton =new QPushButton(tr("OK"));
	//this->okButton->setDefault(true);
	//this->okButton->setEnabled(false);
	//this->cancelButton = new QPushButton(tr("Cancel"));

	connect(labelEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enabledOkButton(const QString &)));
	//connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
	//connect(this->cancelButton,SIGNAL(clicked()),this, SLOT(close()));




	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(label);
	topleftLayout->addWidget(labelEdit);

	//QVBoxLayout * leftLayout = new QVBoxLayout;
	//leftLayout->addLayout(topleftLayout);

	//QVBoxLayout * rightLayout = new QVBoxLayout;
	//rightLayout->addWidget(this->cancelButton);
	//rightLayout->addWidget(this->okButton);
	//rightLayout->addStretch();

	QVBoxLayout * mainLayout = new QVBoxLayout;
	mainLayout->addLayout(topleftLayout);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);
	setWindowTitle(tr("Uuid Creation"));
	setFixedHeight((sizeHint().height()));
}
void UuidDialog::show_help(){
	QMessageBox::about(this,"Unique identifier helper","add Globally Unique Identifier (GUID).\nExample : 3F2504E0-4F89-11D3-9A0C-0305E82C3301.");

}
void UuidDialog::enabledOkButton(const QString &text){
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	//"\{[0-9A-F]{8}-[0-9A-F]{4}-[0-9A-F]{4}-[0-9A-F]{4}-[0-9A-F]{12}\}"
}
void UuidDialog::OkClicked(){
	QString text= labelEdit->text();
	emit this->new_uuid(text);
	this->close();
}
void UuidDialog::ResetClicked(){
	this->labelEdit->clear();
}
