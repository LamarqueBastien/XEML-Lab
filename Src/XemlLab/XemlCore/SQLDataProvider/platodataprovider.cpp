#include "platodataprovider.h"


namespace XemlDataProvider{
	PlatoDataProvider::PlatoDataProvider()
	{
	}
	QImage * PlatoDataProvider::get_logo(){

	}

	void PlatoDataProvider::set_logo(){

	}

	bool PlatoDataProvider::support_auto_mapping(){

	}

	std::vector<QString> * PlatoDataProvider::listForeignKey(){

	}

	std::vector<QString> * PlatoDataProvider::filterKeyValues(QString _key,std::vector<std::pair<QString,QString> > * filter){

	}

	std::vector<SampleIdMapping*> * PlatoDataProvider::automap(QUuid expID, QString expName,std::vector<int> * samples){

	}

	SidLookUpResult PlatoDataProvider::validate(SampleIdMapping *sim){

	}

	ConnectResult PlatoDataProvider::testCredentials(QString _user, QString _password){

	}
	QString  PlatoDataProvider::buildDSN(QString ipserver, QString database, QString LoginName, QString Pass)
	{
		QString dsn;
	#ifdef Q_OS_MACX
		//QString dsn = QString("DRIVER=/usr/local/lib/libtdsodbc.so;SERVER=%1;TDS_VERSION=8pClient;DATABASE=%2;PORT=1433;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
		dsn = QString("DRIVER={/usr/local/lib/libtdsodbc.so};TDS_VERSION=8.0;SERVER="+ipserver+";DATABASE="+database+";PORT=1433;UID="+LoginName+";PWD="+Pass+";");

	#endif

	#ifdef Q_WS_X11
		dsn = QString("DRIVER={FreeTDS};SERVER=%1;TDS_VERSION=8.0;PORT=1433;DATABASE=%2;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
	#endif

	#ifdef Q_WS_WIN
		dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
	#endif
		return dsn;
	}

}
