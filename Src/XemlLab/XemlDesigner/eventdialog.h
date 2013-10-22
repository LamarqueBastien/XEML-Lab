#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QDateTimeEdit>
#include<QDateTime>
#include<QLineEdit>
#include<iostream>
#include<QVariant>
#include"storybase.h"
#include"itfdocument.h"
using namespace std;
using namespace Xeml::Document;
//class QCheckBox;
//class QLabel;
//class QLineEdit;
//class QPushButton;

class EventDialog : public QDialog
{
	Q_OBJECT
	private:
		QLabel      * label;
		QLabel      * timepoint;
		QDateTimeEdit * daytimeedit;
		QLineEdit   * lineEdit;
		QLineEdit   * lineEditTimePoint;
		QPushButton * cancelButton;
		QPushButton * okButton;
		StoryBase   * current_story;
		ItfDocument * current_doc;


	public:
		EventDialog(ItfDocument * _xemldoc,StoryBase * _story,QWidget *parent = 0);
		//QVariant     element_selected;

	signals:
		void event_set(Event * e);

	private slots:
		void OkClicked();
		void enabledOkButton(const QString &text);


};

#endif // EVENTDIALOG_H
