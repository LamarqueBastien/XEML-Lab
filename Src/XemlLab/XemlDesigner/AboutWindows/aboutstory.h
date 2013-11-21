#ifndef ABOUTSTORY_H
#define ABOUTSTORY_H
#include<QDialog>
#include<QLabel>
#include<QListWidget>
#include<QStackedLayout>
#include<QPushButton>
#include"PanelWindows/storypanel.h"
#include"PanelWindows/parameterpanel.h"
#include"PanelWindows/poolpanel.h"
#include"Views/Items/storyitem.h"
#include"PanelWindows/eventpanel.h"
#include"PanelWindows/observationpanel.h"
#include"CoreObjects/Utilities.h"
using namespace Xeml::Utilities;
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
		void                    initialize(StoryBase * _currentStory,bool _IsStorySplit);

	signals:

	private slots:

};

#endif // ABOUTSTORY_H
