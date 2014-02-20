#ifndef PLATODATAPROVIDER_H
#define PLATODATAPROVIDER_H
#include"Interface/itfdataprovider.h"
using namespace Xeml::Sampling::Contracts;

namespace XemlDataProvider{


	class PlatoDataProvider : public ItfDataProvider
	{

		public:
			PlatoDataProvider();
			QImage * get_logo();
			void set_logo();
			bool support_auto_mapping();
			std::vector<QString> * listForeignKey();
			std::vector<QString> * filterKeyValues(QString _key,std::vector<std::pair<QString,QString> > * filter);
			std::vector<SampleIdMapping*> * automap(QUuid expID, QString expName,std::vector<int> * samples);
			SidLookUpResult validate(SampleIdMapping *sim);
			ConnectResult testCredentials(QString _user, QString _password);
			QString buildDSN(QString server, QString database, QString username, QString password);

		private:
			struct MyConfig{
					QString ServerIP;
					QString Database;
					QString Password;
					QString Username;

			};

	};
}

#endif // PLATODATAPROVIDER_H
