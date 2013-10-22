#ifndef ABOUTEXPERIMENT_H
#define ABOUTEXPERIMENT_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<iostream>
#include<QListWidget>
#include<QStackedLayout>
#include"experimentdialog.h"
#include"experimenterdialog.h"
#include"itfdocument.h"
using namespace Xeml::Document;
class AboutExperiment : public QDialog
{
	Q_OBJECT

	public:

		AboutExperiment(ItfDocument * _xeml_doc,QWidget * parent=0);
		QListWidget        * listWidget;
		QTabWidget         * tabWidget;
		ExperimentDialog   * expdialog;
		ExperimenterDialog * experdialog;
		QStackedLayout     * stackLayout;
		QPushButton        * cancelButton;
		QPushButton        * okButton;

	signals:

		void                 experimenter_set_up_finished(QString _firstnametext,
														  QString _lastnametext,
														  QString _organisationtext,
														  QString _emailtext);

	private slots:

		void                 experimenter_set_up(QString _firstnametext,
												 QString _lastnametext,
												 QString _organisationtext,
												 QString _emailtext);
};

#endif // ABOUTEXPERIMENT_H
