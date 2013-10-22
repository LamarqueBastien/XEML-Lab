#ifndef EXPERIMENTITEM_H
#define EXPERIMENTITEM_H
#include<ctime>
#include<QStandardItem>
#include"abstractexperimentitem.h"
#include"termattribute.h"
#include"itfontologyterm.h"
#include"basicterm.h"
#include"story.h"
#include"experimentheader.h"
#include"experimenter.h"
#include"QUuid"
#include"timespan.h"
using namespace Xeml::Document;
using Xeml::Document::ExperimentHeader;


class ExperimentItem : public AbstractExperimentItem
{
	private:
		bool               isroot;
		QUuid              Id;
		time_t             startDate;
		ExperimentHeader * expheader;
		TimeSpan         * observationTime;
	public:
		typedef enum
		  {
			NameRole = Qt::UserRole+1,
			PathRole,
			HashRole,
			SizeRole,
			SizeTextRole,
			SubdirRole,
			SubdirTextRole
		  }Roles;
		typedef enum
		  {
		   ExperimentType = QStandardItem::UserType + 1
		  }Type;

		ExperimentItem(const QString & _name,bool _isRoot);
		ExperimentItem(QString _name,QUuid _Id,time_t _startDate,ExperimentHeader * _expHeader,bool _isRoot);
		int                type() const { return ExperimentType; }
		bool               isRoot();
		void               set_experimenter_details(QString _firstnametext,
													QString _lastnametext,
													QString _organisationtext,
													QString _emailtext);
		void               set_experimentHeader(ExperimentHeader * _expHeader);
		ExperimentHeader * get_experimentHeader();



};

#endif // EXPERIMENTITEM_H
