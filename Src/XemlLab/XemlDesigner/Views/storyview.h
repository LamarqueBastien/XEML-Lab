#ifndef STORYVIEW_H
#define STORYVIEW_H
#include<QPainter>
#include<QtWidgets>
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

#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"
#include"Interface/itfontologyterm.h"
#include"DialogWindows/storysplitdialog.h"
#include"DialogWindows/storydialog.h"
#include"Views/Items/storyitem.h"
#include"CoreObjects/storysplit.h"
#include"AboutWindows/aboutparameter.h"
#include"AboutWindows/aboutexperiment.h"
#include"Views/Items/experimentitem.h"
#include"Views/Items/abstractexperimentitem.h"
#include"AboutWindows/aboutstory.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/timespan.h"
#include"CoreObjects/timespanextension.h"
#include"SampleLoader/observationwizard.h"
#include"DialogWindows/observationpointdialog.h"
#include"PanelWindows/observationpointpanel.h"
#include"CoreObjects/documentresources.h"
#include"DialogWindows/eventdialog.h"
#include"Views/GraphicStoryView/graphicstoryview.h"
#include"Views/GraphicStoryView/graphicstoryscene.h"
#include"Views/plotparameterview.h"
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
		PlotParameterView  * graphicPlot;
		GraphicStoryScene  * GraphicScene;
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

		int                  posY_item;
		qreal                width;
		QSlider            * zoomSlider;
		int                  zoomFactor;
		QComboBox          * zoomFactorSelector;
		bool                 Is_timeline_visible;
		QLineEdit          * StoryLabelEdit;
		QLabel             * StoryLabel;
		QDateTimeEdit      * StoryStartTime;
		QLabel             * StoryStartTimeLabel;
		QLabel             * ZoomFactorLabel;


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
		void                 add_observationPoint(ObservationPoint * _op);
	//protected:
		//void mouseMoveEvent(QMouseEvent *_event);
		//void mouseDoubleClickEvent(QMouseEvent * _event);

	private slots:


		void                 display_plot(StoryBase * _story);
		void                 setupMatrix();
		void                 set_up_zoom_factor(QString _zoomfactor);
		void                 set_up_experimenter(QString _firstnametext,
												 QString _lastnametext,
												 QString _organisationtext,
												 QString _emailtext);
		void                 refresh_genotypeView(QModelIndex _elementSelected);
		void                 edit_Experiment();
		void                 clicSelection(QModelIndex _elementSelected);
		void                 details_about_story(GraphicStoryItem* _storyselected);
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
		void                 on_remove_obspoint();
		void                 add_genotype(QString _idtext,QString _freetext,QString _taxontext);
		void                 add_samples();
		void                 choose_obsPoint();
		void                 new_event();
		void                 add_event(QString _storyName,QString _label,QDateTime _datetime);
		void                 remove_event();
		void                 reset_StoryName(QString label);
		void                 set_story_info(StoryBase* story);



};

#endif // STORYVIEW_H
