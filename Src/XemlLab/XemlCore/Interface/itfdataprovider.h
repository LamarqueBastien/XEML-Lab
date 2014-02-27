#ifndef ITFDATAPROVIDER_H
#define ITFDATAPROVIDER_H

#include"Interface/itfxemlcomponent.h"
#include"CoreObjects/sampleidentification.h"
#include"Manager/connectresult.h"
#include<QImage>
#include<QUuid>

#include<QtSql>

using namespace Xeml::Document;
using namespace Xeml::Sampling;
using namespace Xeml::Document::Contracts;


namespace Xeml {

	namespace Sampling{

		namespace Contracts{


			typedef enum
			{
			Valid,
			UnknownSample,
			unsupportedMapping
			}SidLookUpResult;

			class ItfDataProvider : public ItfXemlComponent
			{
				public:
					ItfDataProvider();
					virtual QImage * get_logo()=0;
					virtual void set_logo(QImage * _logo)=0;
					virtual bool support_auto_mapping()=0;
					virtual std::vector<QString> * listForeignKey()=0;
					virtual std::vector<QString> * filterKeyValues(QString _key,std::vector<std::pair<QString,QString> > * filter)=0;
					virtual std::vector<SampleIdMapping*> * automap(QUuid expID, QString expName,std::vector<int> * samples)=0;
					virtual SidLookUpResult validate(SampleIdMapping *sim)=0;
					virtual ConnectResult testCredentials(QString _user, QString _password)=0;
					virtual QSqlDatabase BuildConnection()=0;
			};

		}
	}
}

#endif // ITFDATAPROVIDER_H
