#include "aboutstory.h"

AboutStory::AboutStory(ItfDocument * _current_doc, QWidget * parent)
:QDialog(parent)
{

	this->current_doc=_current_doc;
	this->cancelButton = new QPushButton("Cancel");
	this->cancelButton->setCursor(Qt::PointingHandCursor);
	this->okButton = new QPushButton("OK");
	this->okButton->setCursor(Qt::PointingHandCursor);

	this->listWidget =new QListWidget;
	listWidget->addItem(tr("story info"));
	listWidget->addItem(tr("parameter info"));
	listWidget->addItem(tr("Individuals pool info"));
	listWidget->addItem(tr("event info"));
	listWidget->addItem(tr("observation info"));

	this->stackLayout= new QStackedLayout;

	this->storyInfo=new StoryPanel;
	stackLayout->addWidget(storyInfo);

	this->parameterInfo=new ParameterPanel(false);
	stackLayout->addWidget(parameterInfo);

	this->poolInfo=new PoolPanel;
	stackLayout->addWidget(poolInfo);

	this->eventInfo=new EventPanel(false);
	stackLayout->addWidget(eventInfo);

	this->obsInfo = new ObservationPanel;
	stackLayout->addWidget(obsInfo);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addWidget(listWidget);
	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addLayout(stackLayout);
	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	this->setLayout(mainLayout);
	connect(this->listWidget,SIGNAL(currentRowChanged(int)),stackLayout,SLOT(setCurrentIndex(int)));
	listWidget->setCurrentRow(0);
}


void AboutStory::initialize(StoryBase * _currentStory,bool _ISStorySplit){

	

	this->storyInfo->initialize(this->current_doc,_currentStory,_ISStorySplit);
	this->parameterInfo->initialize(_currentStory,_ISStorySplit);
	this->poolInfo->initialize(_currentStory,_ISStorySplit);
	this->eventInfo->initialize(_currentStory,_ISStorySplit);
	this->obsInfo->initialize(_currentStory,_ISStorySplit);
}
