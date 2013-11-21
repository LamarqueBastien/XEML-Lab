#ifndef EXPERIMENTERDIALOG_H
#define EXPERIMENTERDIALOG_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<iostream>
#include"Interface/itfdocument.h"
using namespace Xeml::Document;
using namespace std;
class ExperimenterDialog : public QDialog
{
		Q_OBJECT
		private:
			QLabel      * firstnamelabel;
			QLineEdit   * firstnamelabelEdit;
			QLabel      * lastnamelabel;
			QLineEdit   * lastnamelabelEdit;
			QLabel      * organisationlabel;
			QLineEdit   * organisationlabelEdit;
			QLabel      * emaillabel;
			QLineEdit   * emaillabelEdit;
			QPushButton * cancelButton;
			QPushButton * okButton;
			ItfDocument * current_doc;
		public:
			ExperimenterDialog(ItfDocument * _xemlDoc,QWidget *parent = 0);
			void          initialize();
		signals:
			void          mon_signal(QString _firstnametext,
									 QString _lastnametext,
									 QString _organisationtext,
									 QString _emailtext);

		private slots:

			void          OkClicked();
			void          enabledOkButton(const QString &text);


};

#endif // EXPERIMENTERDIALOG_H
