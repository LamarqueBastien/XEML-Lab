#ifndef OBSERVATIONPOINTDIALOG_H
#define OBSERVATIONPOINTDIALOG_H
#include"CoreObjects/timespanextension.h"
#include"CoreObjects/timespan.h"
using namespace Xeml::Utilities;

#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<QDateTimeEdit>
#include<QDateTime>
#include<QDate>
#include<iostream>
#include"CoreObjects/storybase.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"
using namespace std;
using namespace Xeml::Document;

//class QCheckBox;
//class QLabel;
//class QLineEdit;
//class QPushButton;

class ObservationPointDialog : public QDialog
{
	Q_OBJECT
	private:
		QLabel      * label;
		ItfDocument * current_doc;
		QLineEdit   * lineEdit;
		QDateTimeEdit * daytimeedit;
		QPushButton * cancelButton;
		QPushButton * okButton;
		StoryBase   * story;
		QHBoxLayout * topleftLayout;
		int           id;
	public:
		ObservationPointDialog(StoryBase * _story,ItfDocument * _xeml_doc,QWidget *parent = 0);
		void          set_id(int _currentid);
	signals:
		void          mon_signal(ObservationPoint * _obs);


	private slots:

		void          OkClicked();
		void          enabledOkButton(QDateTime _date);


};


#endif // OBSERVATIONPOINTDIALOG_H
