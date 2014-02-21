#ifndef SQLCONNECTIONDIALOG_H
#define SQLCONNECTIONDIALOG_H

#include <QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<QTextEdit>
#include<iostream>
#include<QStringList>
#include"Interface/itfdocument.h"
#include"CoreObjects/individualspool.h"
#include"DialogWindows/annotationdialog.h"

class SQLConnectionDialog : public QDialog
{
		Q_OBJECT
	public:
		explicit SQLConnectionDialog(QWidget *parent = 0);
		// ~QSqlConnectionDialog();
	private:
		QLabel      * database_label;
		QLineEdit   * databaseEdit;
		QLabel      * ipserver_label;
		QLineEdit   * ipserverEdit;
		QLabel      * userName_label;
		QLineEdit   * userNameEdit;
		QLabel      * password_label;
		QLineEdit   * passwordEdit;
		QStringList * parameters;
		QPushButton * cancelButton;
		QPushButton * okButton;

	signals:
		void          on_connection_added(QStringList * _parameters);

	private slots:
		void          OkClicked();
		void          enabledOkButton(const QString &text);

};

#endif // SQLCONNECTIONDIALOG_H
