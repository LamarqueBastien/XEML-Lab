#ifndef EXPERIMENTDIALOG_H
#define EXPERIMENTDIALOG_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<iostream>
#include<QDateTimeEdit>
#include<QTextEdit>
#include<ctime>
#include<QDialogButtonBox>
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
			QLabel        * firstnamelabel;
			QLineEdit     * firstnamelabelEdit;
			QLabel        * lastnamelabel;
			QLineEdit     * lastnamelabelEdit;
			QLabel        * organisationlabel;
			QLineEdit     * organisationlabelEdit;
			QLabel        * emaillabel;
			QLineEdit     * emaillabelEdit;
			//QLineEdit     * startdateEdit;
			QPushButton   * cancelButton;
			QPushButton   * okButton;
			QDateTimeEdit * startdateEdit;
			QDateTimeEdit * enddateEdit;
			QTextEdit     * descriptionEdit;
			QDialogButtonBox * buttonBox;

			ItfDocument   * current_doc;

		public:
			ExperimentDialog(ItfDocument * _xeml_doc,QWidget *parent = 0);
			void initialize();

		signals:

			void            set_up_finished();

		private slots:

			void            OkClicked();
			void            ResetClicked();
			void            avoid_endTime_reachout(QDateTime _newTime);
			void            avoid_equal_time(QDateTime _newTime);
			void            enabledOkButton(const QString &text);

};

#endif // EXPERIMENTDIALOG_H
