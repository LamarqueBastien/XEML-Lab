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
#include"CoreObjects/storybase.h"
#include"Interface/itfdocument.h"
#include"Views/GraphicStoryView/Items/graphiceventitem.h"
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
		Event       * event;
		GraphicEventItem * graphicEvent;
		bool          Mode;
		int           posX;


	public:
		EventDialog(bool _mode,Event * _event,ItfDocument * _xemldoc,StoryBase * _story,int _posX,QWidget *parent = 0);
		EventDialog(bool _mode,GraphicEventItem * _event,ItfDocument * _xemldoc,StoryBase * _story,QWidget *parent = 0);

		//QVariant     element_selected;

	signals:
		void event_set(Event * _e,int _posX);
		void event_edited();

	private slots:
		void OkClicked();
		void enabledOkButton(const QString &_text);


};

#endif // EVENTDIALOG_H
