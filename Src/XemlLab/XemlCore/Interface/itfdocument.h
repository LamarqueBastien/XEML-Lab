#ifndef ITFDOCUMENT_H
#define ITFDOCUMENT_H
#include<string>
#include"CoreObjects/experimentheader.h"

#include"CoreObjects/documentresources.h"
#include"CoreObjects/storyboard.h"

#include<QUuid>
#include<ctime>
#include<QDateTime>
using Xeml::Document::StoryBoard;
using Xeml::Document::DocumentResources;
using namespace Xeml::Document;
namespace Xeml {

	namespace Document{

		namespace Contracts{

			class ItfDocument
			{
				protected:
					//QString name;
					//QString xeml;
					//QUuid         Id;
					//time_t startDate;

					//unique identifier -- to create
					//datetime --to create
					//the observed time span for the experiment --to create
					//DocumentResources documentResources;
					//ExperimentHeader *experimentheader;

				public:

					ItfDocument();
					virtual ~ItfDocument();
					virtual QUuid               get_id()=0;
					virtual QDateTime           get_startdate()=0;
					virtual QDateTime           get_enddate()=0;
					virtual QString             get_obs_time()=0;
					virtual void                set_obs_time(QString _time)=0;
					virtual QString             get_experiment_name()=0;
					virtual QString             get_xemlcode()=0;
					virtual QString             get_description()=0;
					virtual void             set_description(QString _description)=0;
					virtual DocumentResources * get_doc_resources()=0;
					virtual ExperimentHeader  * get_experimentheader()=0;
					virtual StoryBoard        * get_storyboard()=0;
					virtual void                set_startdate(QDateTime _t)=0;
					virtual void                set_enddate(QDateTime _t)=0;
					virtual void                set_experiment_name(QString _name)=0;
					virtual void                set_xemlcode(QString _xeml)=0;
					virtual void                NewId()=0;
					virtual void                Load(QString xemlCode,bool asTemplate)=0;
					virtual void                Save(QString path)=0;
					virtual void                RefreshXeml()=0;
					virtual void                LoadFile(QString path)=0;
					virtual void                DoXmlValidation()=0;
					virtual void                DoXmlValidation(QString xemlCode)=0;
			};
		}
	}
}

#endif // ITFDOCUMENT_H

