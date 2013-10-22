#include "aboutstory.h"

AboutStory::AboutStory(QWidget * parent)
:QDialog(parent)
{

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


void AboutStory::initialize(StoryItem * _currentStory){

	//vérifier les attributs de la story et initialiser en fonction.

	this->storyInfo->initialize(_currentStory->get_story(),_currentStory->get_isStorySplit());
	this->parameterInfo->initialize(_currentStory->get_story(),_currentStory->get_isStorySplit());
	this->poolInfo->initialize(_currentStory->get_story(),_currentStory->get_isStorySplit());
	this->eventInfo->initialize(_currentStory->get_story(),_currentStory->get_isStorySplit());
	this->obsInfo->initialize(_currentStory->get_story(),_currentStory->get_isStorySplit());
}
