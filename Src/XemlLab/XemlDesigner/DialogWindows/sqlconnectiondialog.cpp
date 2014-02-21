#include "sqlconnectiondialog.h"

SQLConnectionDialog::SQLConnectionDialog(QWidget *parent) :
	QDialog(parent)
{
	this->parameters = new QStringList;

	this->database_label= new QLabel("database");
	this->databaseEdit = new QLineEdit;
	this->database_label->setBuddy(this->databaseEdit);

	this->ipserver_label= new QLabel("hostname");
	this->ipserverEdit = new QLineEdit;
	this->ipserver_label->setBuddy(this->databaseEdit);

	this->userName_label= new QLabel("user name");
	this->userNameEdit = new QLineEdit;
	this->userName_label->setBuddy(this->databaseEdit);

	this->password_label= new QLabel("password");
	this->passwordEdit = new QLineEdit;
	this->password_label->setBuddy(this->databaseEdit);

	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));
	this->cancelButton->setCursor(Qt::PointingHandCursor);

	connect(this->okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
	connect(this->databaseEdit,SIGNAL(textEdited(QString)),this,SLOT(enabledOkButton(QString)));

	QHBoxLayout * databaseLayout = new QHBoxLayout;
	databaseLayout->addWidget(database_label);
	databaseLayout->addWidget(this->databaseEdit);

	QHBoxLayout * ipserverLayout = new QHBoxLayout;
	ipserverLayout->addWidget(ipserver_label);
	ipserverLayout->addWidget(this->ipserverEdit);

	QHBoxLayout * userNameLayout = new QHBoxLayout;
	userNameLayout->addWidget(userName_label);
	userNameLayout->addWidget(this->userNameEdit);

	QHBoxLayout * passwordLayout = new QHBoxLayout;
	passwordLayout->addWidget(password_label);
	passwordLayout->addWidget(this->passwordEdit);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(databaseLayout);
	leftLayout->addLayout(ipserverLayout);
	leftLayout->addLayout(userNameLayout);
	leftLayout->addLayout(passwordLayout);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
	setWindowTitle(tr("SQL connection parameters"));
	setFixedHeight((sizeHint().height()));




}

SQLConnectionDialog::~SQLConnectionDialog(){

}

void          SQLConnectionDialog::OkClicked(){

}

void          SQLConnectionDialog::enabledOkButton(const QString &text){

}
