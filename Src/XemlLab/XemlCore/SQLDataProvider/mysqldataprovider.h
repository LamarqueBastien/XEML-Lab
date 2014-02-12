#ifndef MYSQLDATAPROVIDER_H
#define MYSQLDATAPROVIDER_H
#include"Interface/itfdataprovider.h"
using namespace Xeml::Sampling::Contracts;

class MySqlDataProvider :public ItfDataProvider
{
	public:
		MySqlDataProvider();
		QImage * get_logo();
		void set_logo();
		bool support_auto_mapping();
		std::vector<QString> * listForeignKey();
		std::vector<QString> * filterKeyValues(QString _key,std::vector<std::pair<QString,QString> > * filter);
		std::vector<SampleIdMapping*> * automap(QUuid expID, QString expName,std::vector<int> * samples);
		SidLookUpResult validate(SampleIdMapping *sim);
		ConnectResult testCredentials(QString _user, QString _password);

};

#endif // MYSQLDATAPROVIDER_H
