#ifndef STORYVIEW_H
#define STORYVIEW_H
#include<QPainter>
#include<QWidget>
#include<QAbstractScrollArea>
#include<QtGui>
#include<QVariant>
#include<QStandardItemModel>
#include<QTreeView>
#include<QTableView>
#include<QStandardItem>
#include<QPushButton>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QHeaderView>
#include"itfdocument.h"
#include"xemldocument.h"
#include"itfontologyterm.h"
#include"storysplitdialog.h"
#include"storydialog.h"
#include"storyitem.h"
#include"storysplit.h"
#include"aboutparameter.h"
#include"aboutexperiment.h"
#include"experimentitem.h"
#include"abstractexperimentitem.h"
#include"aboutstory.h"
#include"itfdocument.h"
#include"timespan.h"
#include"timespanextension.h"
#include"observationwizard.h"
#include"observationpointdialog.h"
#include"observationpointpanel.h"
#include"documentresources.h"
#include"eventdialog.h"
#include"graphicstoryview.h"
#include"graphicstoryscene.h"
using Xeml::Document::Contracts::ItfOntologyTerm;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Utilities;

class StoryView : public QWidget
{
		Q_OBJECT

	private:

		ItfDocument        * currentDoc;
		DocumentResources  * doc_ressources;
		QString              experimentName;
		QTreeView          * storytree;
		GraphicStoryView   * graphicStory;
		QPushButton        * removestory;
		QPushButton        * infoButton;
		QPushButton        * editExperiment;
		QPushButton        * addstorysplit;
		QPushButton        * addstory;
		QPushButton        * addparameter;
		QPushButton        * addobsPoint;
		QPushButton        * addSamples;
		QPushButton        * addEvent;
		QPushButton        * rmEvent;
		QPushButton        * removeObsPoint;
		QPushButton        * removeSample;
		QPushButton        * removeStorySplit;
		QStandardItemModel * my_treestory;
		StorySplitDialog   * splitstorydialog;
		StoryDialog        * storydialog;
		AboutStory         * aboutstory;
		AboutParameter     * aboutParameter;
		AboutExperiment    * aboutexp;
		ObservationWizard  * obsWizard;
		ObservationPointDialog * obsPoint;
		int                  obsPointCount;
		bool                 GraphicMode;
		GraphicStoryScene  * GraphicScene;
		int                  posY_item;
		qreal                width;
		QSlider            * zoomSlider;

	public slots:
		void zoomIn(int level = 1);
		void zoomOut(int level = 1);
	public:

		explicit             StoryView(QWidget *parent = 0);
		int                  count_total_observationsPoint(StoryNode * _parent,int _number);
		void                 createStory(QString _text);
		QStandardItemModel * get_model();
		void                 createExperiment(ItfDocument * _current_xeml,DocumentResources * _doc_ressources);
		void                 build_graphic_story_hierarchy(StoryNode * _node);

		void                 build_story_hierarchy(StoryNode * _node,
												   std::list<StoryNode*> * _processed_nodes,
												   StoryItem * _sti,
												   QString _storyname);
		bool                 contains(StoryNode * _node,
									  std::list<StoryNode*> * _processed_nodes,
									  QString _storyname);
		void                 clean_tree();


	signals:
		void                 refresh_genotype_view(ItfDocument * _xemldoc);
		void                 experimenter_settings(QString _firstnametext,
												   QString _lastnametext,
												   QString _organisationtext,
												   QString _emailtext);
		void                 refresh_story_view(StoryView * storyview);
		void                 on_refresh_genotype_view();
		void                 add_graphic_story(QString _label, StoryBase* _story);
		void                 add_graphic_story_split(QString _label,StoryBase * _split);
	//protected:
		//void mouseMoveEvent(QMouseEvent *_event);
		//void mouseDoubleClickEvent(QMouseEvent * _event);

	private slots:


		void                 setupMatrix();
		void                 set_up_experimenter(QString _firstnametext,
												 QString _lastnametext,
												 QString _organisationtext,
												 QString _emailtext);
		void                 refresh_genotypeView(QModelIndex _elementSelected);
		void                 edit_Experiment();
		void                 clicSelection(QModelIndex _elementSelected);
		void                 newObsPoint();
		void                 newStorySplit();
		void                 newStory();
		void                 removeStory();
		void                 addStorySplit(QString _element_selected,QString _storysplitLabel,QDateTime _datetime);
		void                 add_graphic_split_story(QString _label);

		void                 addStory(QString _storyLabel);
		void                 new_parameter(ItfOntologyTerm * _term);
		void                 add_parameter(StoryNode * story,BasicTerm * _term);
		//void                 add_parameter(StoryItem * _tmp,StoryNode * _story,BasicTerm * _term);
		void                 remove_parameter();
		void                 add_observationPoint();
		void                 remove_obs_point();
		void                 add_genotype(QString _idtext,QString _freetext,QString _taxontext);
		void                 add_samples();
		void                 choose_obsPoint();
		void                 new_event();
		void                 add_event(QString _storyName,QString _label,QDateTime _datetime);
		void                 remove_event();



};

#endif // STORYVIEW_H
