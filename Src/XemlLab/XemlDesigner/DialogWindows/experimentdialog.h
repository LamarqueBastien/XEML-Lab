#ifndef EXPERIMENTDIALOG_H
#define EXPERIMENTDIALOG_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<iostream>
#include <QDateTimeEdit>
#include<QTextEdit>
#include<ctime>
#include"Interface/itfdocument.h"
using namespace std;
using namespace Xeml::Document;
class ExperimentDialog : public QDialog
{
		Q_OBJECT

		private:
			QLabel        * experimentlabel;
			QLineEdit     * experimentlabelEdit;
			QLabel        * experimentstartDate;
			QLabel        * experimentEndDate;
			QLabel        * descriptionLabel;
			//QLineEdit     * startdateEdit;
			QPushButton   * cancelButton;
			QPushButton   * okButton;
			QDateTimeEdit * startdateEdit;
			QDateTimeEdit * enddateEdit;
			QTextEdit     * descriptionEdit;

			ItfDocument   * current_doc;

		public:
			ExperimentDialog(ItfDocument * _xeml_doc,QWidget *parent = 0);
			void initialize();

		signals:

			void            mon_signal(QString _text);

		private slots:

			void            OkClicked();
			void            enabledOkButton(const QString &text);

};

#endif // EXPERIMENTDIALOG_H
