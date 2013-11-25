#ifndef XEMLDOCUMENT_H
#define XEMLDOCUMENT_H
#include <iostream>
#include<ctime>
#include <list>
#include<string>
#include<map>
#include<QString>
#include<QTextStream>
#include<QFile>
#include<QMessageBox>
#include<QPushButton>
#include<QApplication>
#include<QXmlReader>
#include<QtXml>
#include<QTreeWidget>
#include<QMessageBox>
#include<QIODevice>
#include<QUuid>
//#include<tree.h>
#include"CoreObjects/experimentheader.h"
#include"CoreObjects/xemlannotableobject.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/taggedannotation.h"
//#include"itfdocument.h"
#include"Interface/itfontologyhandler.h"
#include"CoreObjects/keyword.h"
#include"CoreObjects/story.h"
#include"CoreObjects/storybase.h"
#include"CoreObjects/event.h"
#include"CoreObjects/individual.h"
#include"CoreObjects/individualspool.h"
#include"CoreObjects/observation.h"
#include"CoreObjects/observationpoint.h"
#include"CoreObjects/documentresources.h"
#include"CoreObjects/storynode.h"
#include"CoreObjects/storyboard.h"
#include"CoreObjects/storysplit.h"
#include"CoreObjects/partition.h"
#include"CoreObjects/variableterm.h"
#include"CoreObjects/timespanextension.h"
#include"CoreObjects/ontologyhandlerresources.h"
#include"CoreObjects/Utilities.h"
#include<QDateTime>


//#include "documentresources.h"
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
using Xeml::Document::Contracts::OntologyType;
using namespace Xeml::Utilities;

namespace Xeml {
	namespace Document{

		class XemlDocument : public ItfDocument

		{
			private:

				QDomDocument        doc;
				QString             experiment_name;
				QString             xeml;
				QUuid               Id;
				QDateTime           startDate;
				QDateTime           endDate;
				ExperimentHeader  * experimentheader;
				StoryBoard        * storyBoard;
				DocumentResources * documentResources;
				QString             description;

			public:

				QString             uri;
				QString             xmlNameSpace;
				QString             XemlVersion;
				bool                asTemplate;
				int                 observationPointsCounter;
				int                 partition_counter;
				QString             observationTime;

				//region constructors
				XemlDocument();
				~XemlDocument();
				XemlDocument(QString filename);

				//region properties

				//region ItfDocument
				QUuid               get_id();
				QDateTime           get_startdate();
				QDateTime           get_enddate();
				QString             get_obs_time();
				QString             get_description();
				void                set_description(QString _description);

				void                set_obs_time(QString   _time);
				QString             get_experiment_name();
				QString             get_xemlcode();
				StoryBoard        * get_storyboard();
				ExperimentHeader  * get_experimentheader();
				DocumentResources * get_doc_resources();
				void                set_experiment_name(QString _name);
				void                set_xemlcode(QString _xeml);
				void                set_startdate(QDateTime _t);
				void                set_enddate(QDateTime _t);
				QString             generate_string_xml();



				void                NewId();
				void                Load(QString xemlCode,bool asTemplate);
				void                Save(QString path);
				void                RefreshXeml();
				void                LoadFile(QString path);
				void                DoXmlValidation();
				void                DoXmlValidation(QString xemlCode);


				//region Helper methods
				//TimeSpan          * tryTimeSpanSet(QString tstring);
				QString             put_date_in_string(time_t _startdate);
				QString             put_id_in_Qstring(QUuid _id);
				QString             put_id_in_string(QUuid _id);
				//end region

			private:
				//region Xeml write
				int                 generate_xml(const QString &fileName);
				void                write_header();
				void                write_resources();
				void                write_stories(StoryNode * _node,StoryNode *_parent);
				void                write_substories(QDomElement * _elem,StoryNode * _node);
				void                write_annotation(QDomElement * _elem,XemlAnnotableObject * _xo);
				void                write_individuals(QDomElement * _elem,Story* _story);
				void                write_paramater(QDomElement * _elem,StoryNode *_story);
				void                write_values(QDomElement * _elem,ValueBase * _dvb);
				void                write_observationPoint(QDomElement * _elem,StoryNode * _node);
				void                write_event(QDomElement * _elem,StoryNode * _node);

				//endregion

				//region xeml read
				void                Init(QDomDocument * qdd);
				void                InitRessources(QDomElement  elem);
				void                InitStory(QDomElement  elem,StoryNode * _node,QString _storyname);
				void				InitAnnotations(QDomElement  _elem,XemlAnnotableObject * xo);
				void				InitPools(QDomElement _elem, XemlAnnotableObject * _xo);
				void				InitVariable(QDomElement _elem,bool _isStorysplit,StoryBase * _storyBase);
				void				InitValues(QDomElement _elem,bool _isStorysplit,DynamicTerm * _term,QDateTime _timepoint,StoryBase * _storyBase);
				void				InitEvent(QDomElement _elem,bool _isStorySplit,StoryBase * _storyBase);
				void                InitObserverPoint(QDomElement _elem,bool _isStorySplit, StoryBase * storyBase);
				void				InitPartitions(QDomElement _elem,Observation * _ob);
				void				InitDevelopmentalStage(QDomElement _elem,Observation * _ob);
				//void                InitData(XPathNavigator xpn);
				//void                InitSampleMapping(SidMapping sid, int sampleId, XPathNavigator xpn);
				//void                InitSample(XPathNavigator xPathNavigator, StoryBase storyBase);
				//endregion

				//region purge xeml doc
			public:
				void                purge();
				void                purge_story(StoryNode * _node);
				void                purge_substory(StoryNode * _substory);

			private:
				void                purge_stories(StoryNode * _node);//,StoryNode *_parent);

				void                purge_substories(StoryNode * _node);
				void                purge_individuals(Story * st);
				void                purge_variable(StoryNode *_node);
				void                purge_observationPoint(StoryNode *_node);

				//endregion





		};
	}
}

#endif // XEMLDOCUMENT_H

