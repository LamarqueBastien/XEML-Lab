#ifndef PLATODATAPROVIDER_H
#define PLATODATAPROVIDER_H
#include<QtSql>
#include"Interface/itfdataprovider.h"
using namespace Xeml::Sampling::Contracts;

namespace XemlDataProvider{


	class PlatoDataProvider : public ItfDataProvider
	{
		struct MyConfig{
				QString ServerIP;
				QString Database;
				QString Password;
				QString Username;

		};

		public:
			PlatoDataProvider();
			//region itfDataprovider

			QImage * get_logo();
			void set_logo(QImage * _logo);

			bool support_auto_mapping();
			std::vector<QString> * listForeignKey();
			QString get_experiment_name_by_uid(QUuid _exp_id);
			QString convert_uid_to_platoUID(QUuid _xeml_id);

			std::vector<QString> * get_sample_foreign_key(QString  _experiment_name);
			bool search_for_experiment(QUuid exp_id);
			bool search_for_experiment(QString _exp_name);

			std::vector<QString> * filterKeyValues(QString _key,std::vector<std::pair<QString,QString> > * filter);
			std::vector<SampleIdMapping*> * automap(QUuid expID, QString expName,std::vector<int> * samples);
			SidLookUpResult validate(SampleIdMapping *sim);
			ConnectResult testCredentials(QString _user, QString _password);
			QString buildDSN(QString server, QString database, QString username, QString password);
			//KeyKeyValueCollection<string,int,object> QueryData(List<SidMapping> samples );
			void BuildConnection();
			QStringList get_available_drivers();

			//end region ItfDataProvider


			//region XemlComponent
			QString            get_publisher();
			QString            get_version();
			QString            get_componentName();
			QString            get_author();
			QString            get_description();
			QString            get_uri();
			ItfXemlComponent * copy();
			//end region XemlComponent

		private:

			MyConfig myConfig;
			QImage * plato_logo;
			QSqlDatabase db;

	};
}

#endif // PLATODATAPROVIDER_H
