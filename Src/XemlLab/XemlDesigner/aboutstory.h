#ifndef ABOUTSTORY_H
#define ABOUTSTORY_H
#include<QDialog>
#include<QLabel>
#include<QListWidget>
#include<QStackedLayout>
#include<QPushButton>
#include"storypanel.h"
#include"parameterpanel.h"
#include"poolpanel.h"
#include"storyitem.h"
#include"eventpanel.h"
#include"observationpanel.h"
using namespace Xeml::Document::Contracts;
class AboutStory : public QDialog
{
	Q_OBJECT
	public:
		AboutStory(QWidget * parent=0);
		QListWidget           * listWidget;
		QStackedLayout        * stackLayout;
		QPushButton           * cancelButton;
		QPushButton           * okButton;
		StoryPanel            * storyInfo;
		ParameterPanel        * parameterInfo;
		PoolPanel             * poolInfo;
		EventPanel            * eventInfo;
		ObservationPanel      * obsInfo;
		void                    initialize(StoryItem * _currentStory);

	signals:

	private slots:

};

#endif // ABOUTSTORY_H
