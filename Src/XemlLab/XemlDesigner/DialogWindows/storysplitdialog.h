#ifndef STORYSPLITDIALOG_H
#define STORYSPLITDIALOG_H
#include<QtWidgets>
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QDateTimeEdit>
#include<QDateTime>
#include<QLineEdit>
#include<iostream>
#include<QVariant>
#include"CoreObjects/Utilities.h"
#include"Views/Items/storyitem.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"
using namespace Xeml::Document;
using namespace std;
using namespace Xeml::Utilities;

//class QCheckBox;
//class QLabel;
//class QLineEdit;
//class QPushButton;

class StorySplitDialog : public QDialog
{
	Q_OBJECT
	private:
		QLabel      * label;
		ItfDocument * current_doc;
		QLabel      * timepoint;
		QDateTimeEdit * daytimeedit;
		QLineEdit   * lineEdit;
		QLineEdit   * lineEditTimePoint;
		QPushButton * cancelButton;
		QPushButton * okButton;


	public:
		StorySplitDialog(ItfDocument * _xemlDoc, QVariant   _element_selected,QWidget *parent = 0);
		QVariant     element_selected;

	signals:
		void storysplitset(QString _element_selected,QString _text,QDateTime _datetime);

	private slots:
		void OkClicked();
		void enabledOkButton(const QString &text);
		void valid_date_time(QDateTime);


};

#endif // STORYSPLITDIALOG_H
