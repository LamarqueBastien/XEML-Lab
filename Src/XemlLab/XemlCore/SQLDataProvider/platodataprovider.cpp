#include "platodataprovider.h"


namespace XemlDataProvider{

	PlatoDataProvider::PlatoDataProvider()
	{


		myConfig.Database="PlatoDB";
		myConfig.Password="glucose";
		myConfig.ServerIP="147.100.103.188";
		myConfig.Username="labdesigner";


	}
	QImage * PlatoDataProvider::get_logo(){
		return this->plato_logo;
	}

	void PlatoDataProvider::set_logo(QImage * _logo){
		this->plato_logo=_logo;
	}


	bool PlatoDataProvider::search_for_experiment(QUuid _exp_id, QString _exp_name){
		std::cerr << "entering search for experiment" << std::endl;
		QSqlDatabase db;
		db = QSqlDatabase::addDatabase("QODBC","PlatoDB");
		QString dsn=buildDSN(this->myConfig.ServerIP,this->myConfig.Database,this->myConfig.Username,this->myConfig.Password);
		db.setDatabaseName(dsn);
		if (db.open()){
			QSqlQuery query("",db);

#if defined(Q_OS_WIN)
			if(query.exec("SELECT UId FROM [PlatoDB].[dbo].[Experiments]"))
#else
			if(query.exec("SELECT LEFT(CAST(UId as char(64)), 36),Id FROM [PlatoDB].[dbo].[Experiments]")){
#endif
			//if(query.exec("SELECT Id FROM [PlatoDB].[dbo].[Experiments] ")){
				int results_counter=0;
				while (query.next())
				{
					results_counter++;

					QString Uid=query.value(0).toString();
					QUuid tmp(Uid);
					//QString expName = query.value(0).toString();

					std::cerr << "expid to string: " << _exp_id.toString().toStdString() << std::endl;
					if(tmp.toString()==_exp_id.toString()){
						std::cerr << "an experiment with the same identifier has been found" << std::endl;
						return true;
					}
					//QString resultString2 = query.value(1).toString();
					std::cerr << "Uid: " <<  Uid.toStdString() << std::endl;
					///qDebug() << country;
				}
				return false;
			}
			else{
				std::cerr << "Une erreur s'est produite. :(" << query.lastError().text().toStdString()<< std::endl;
				return false;

			}


		}
		else{
			std::cerr << "Error" << db.lastError().text().toStdString() << std::endl;
			return false;
		}
	}

	bool PlatoDataProvider::support_auto_mapping(){
		return true;
	}

	std::vector<QString> * PlatoDataProvider::get_sample_foreign_key(QString _experiment_name){

	}

	std::vector<QString> * PlatoDataProvider::listForeignKey(){

	}

	std::vector<QString> * PlatoDataProvider::filterKeyValues(QString _key,std::vector<std::pair<QString,QString> > * filter){

	}

	std::vector<SampleIdMapping*> * PlatoDataProvider::automap(QUuid expID, QString expName,std::vector<int> * samples){


		/*
		QSqlQuery query("",db);

		if(query.exec("SELECT Sample FROM [PlatoDB].[dbo].[FreshWeights] WHERE Experiment_Fk='FRIM01_Avignon_Temperature1'"))
		{
			//if (!query.isActive())
			  //  QMessageBox::warning(w, tr("Database Error"),
				 //					query.lastError().text());

			std::cerr << "La requete a bien été effectué ! :)" << std::endl;
			int results_counter=0;
			while (query.next())
			{
				results_counter++;

				QString resultString = query.value(0).toString();
				//QString resultString2 = query.value(1).toString();
				std::cerr << "result: " <<  resultString.toStdString() << std::endl;
				//" ------ results2: " <<resultString2.toStdString() << std::endl;
				///qDebug() << country;
			}
			std::cerr << "there is " << results_counter << "element in this table" << std::endl;
		}
		else
		{
			std::cout << "Une erreur s'est produite. :(" << query.lastError().text().toStdString()<< std::endl;
		}
		*/
	}

	SidLookUpResult PlatoDataProvider::validate(SampleIdMapping *sim){

	}
	ConnectResult PlatoDataProvider::testCredentials(QString _user, QString _password){

		QSqlDatabase db;
		QString dsn=buildDSN(this->myConfig.ServerIP,this->myConfig.Database,this->myConfig.Username,this->myConfig.Password);
		db.setDatabaseName(dsn);
		if(db.open()){
			db.close();
			return Xeml::Sampling::Success;
		}
		else{
			db.close();
			return Xeml::Sampling::Failed;

		}
	}
	QString  PlatoDataProvider::buildDSN(QString ipserver, QString database, QString LoginName, QString Pass)
	{
		QString dsn;
	#ifdef Q_OS_MACX
		dsn = QString("DRIVER={/usr/local/lib/libtdsodbc.so};TDS_VERSION=8.0;SERVER="+ipserver+";DATABASE="+database+";PORT=1433;UID="+LoginName+";PWD="+Pass+";");
	#endif

	#ifdef Q_WS_X11
		dsn = QString("DRIVER={FreeTDS};SERVER=%1;TDS_VERSION=8.0;PORT=1433;DATABASE=%2;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
	#endif

	#ifdef Q_OS_LINUX
		dsn = QString("DRIVER={FreeTDS};TDS_VERSION=8.0;SERVER="+ipserver+";DATABASE="+database+";PORT=1433;UID="+LoginName+";PWD="+Pass+";");
	#endif

	#ifdef Q_WS_WIN
		dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;UID=%3;PWD=%4;").arg(ipserver).arg(database).arg(LoginName).arg(Pass);
	#endif
		return dsn;
	}
	QSqlDatabase PlatoDataProvider::BuildConnection(){
		if (testCredentials("labdesigner","glucose")==Xeml::Sampling::Success){
			QSqlDatabase db;
			db = QSqlDatabase::addDatabase("QODBC","PlatoDB");
			QString dsn=buildDSN(this->myConfig.ServerIP,this->myConfig.Database,this->myConfig.Username,this->myConfig.Password);
			db.setDatabaseName(dsn);
			return db;

		}



	}

	QString                                 PlatoDataProvider::get_publisher(){
		return "INRA Bordeaux, France";

	}

	QString                                PlatoDataProvider::get_version(){
		return "1.1.6.0";
	}

	QString                                 PlatoDataProvider::get_componentName(){
		return "PlatoProvider";
	}

	QString                                 PlatoDataProvider::get_author(){
		return "Benjamin Dartigues";
	}

	QString                                 PlatoDataProvider::get_description(){
		return "A data provider for the highthroughput enzyme platform PLATO based in INRA Bordeaux.";
	}

	QString                                 PlatoDataProvider::get_uri(){
		//which uses?
		return "http://plato.codeplex.com/";
		//"http://147.100.103.188/ClickOnce/PLATO/"
	}

	ItfXemlComponent                      * PlatoDataProvider::copy(){
		return new PlatoDataProvider();
	}


}
