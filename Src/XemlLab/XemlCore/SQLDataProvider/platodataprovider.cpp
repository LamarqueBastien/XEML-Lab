#include "platodataprovider.h"


namespace XemlDataProvider{

	PlatoDataProvider::PlatoDataProvider()
	{


		myConfig.Database="PlatoDB";
		myConfig.Password="glucose";
		myConfig.ServerIP="147.100.103.188";
		//myConfig.ServerIP="127.0.0.1";
		myConfig.Username="labdesigner";


	}
	QImage * PlatoDataProvider::get_logo(){
		return this->plato_logo;
	}

	void PlatoDataProvider::set_logo(QImage * _logo){
		this->plato_logo=_logo;
	}

	QString PlatoDataProvider::convert_uid_to_platoUID(QUuid xeml_id){
		QString UID=xeml_id.toString();
		UID.remove("{");
		UID.remove("}");
		return UID.toUpper();
	}

	QString PlatoDataProvider::get_experiment_name_by_uid(QUuid _exp_id){

		QString name="";
		QString mtp=convert_uid_to_platoUID(_exp_id);

		if (db.open()){
			QSqlQuery query("",db);

#if defined(Q_OS_WIN)
			if(query.exec("SELECT UId,Id FROM [PlatoDB].[dbo].[Experiments]")){
#else
			if(query.exec("SELECT LEFT(CAST(UId as char(64)), 36),Id FROM [PlatoDB].[dbo].[Experiments]")){
#endif
			//if(query.exec("SELECT Id FROM [PlatoDB].[dbo].[Experiments] ")){
				int results_counter=0;
				while (query.next())
				{
					results_counter++;

					QString Uid=query.value(0).toString();
					name=query.value(1).toString();
					QUuid tmp(Uid);
					if(tmp.toString()==_exp_id.toString()){
						return name;
					}

				}
				return name;
			}
			else{
				std::cerr << "Une erreur s'est produite. :(" << query.lastError().text().toStdString()<< std::endl;
				return name;

			}


		}
		else{
			std::cerr << "Error" << db.lastError().text().toStdString() << std::endl;
			return name;
		}

	}

	bool PlatoDataProvider::search_for_experiment(QString _exp_name){
		if (db.open()){
			QSqlQuery query("",db);
			if(query.exec("SELECT Id FROM [PlatoDB].[dbo].[Experiments]")){
				//int results_counter=0;
				while (query.next())
				{
					QString name=query.value(0).toString();
					if(name==_exp_name){
						return true;
					}


				}
				return false;
			}
			return false;


		}
		return false;
	}


	QString PlatoDataProvider::get_error_message(){
		return this->error_message;
	}

	bool PlatoDataProvider::search_for_experiment(QUuid _exp_id){
		std::cerr << "entering search for experiment" << std::endl;
		QString mtp=convert_uid_to_platoUID(_exp_id);
		db = QSqlDatabase::addDatabase("QODBC","PlatoDB");
		QString dsn=buildDSN(this->myConfig.ServerIP,this->myConfig.Database,this->myConfig.Username,this->myConfig.Password);
		db.setDatabaseName(dsn);
		if (db.open()){
			QSqlQuery query("",db);

#if defined(Q_OS_WIN)
			if(query.exec("SELECT UId FROM [PlatoDB].[dbo].[Experiments]")){
#else
			if(query.exec("SELECT LEFT(CAST(UId as char(64)), 36),Id FROM [PlatoDB].[dbo].[Experiments]")){
#endif
				int results_counter=0;
				while (query.next())
				{
					results_counter++;

					QString Uid=query.value(0).toString();
					QUuid tmp(Uid);

					if(tmp.toString()==_exp_id.toString()){
						std::cerr << "an experiment with the same identifier has been found" << std::endl;
						return true;
					}

				}
				return false;
			}
			else{
				std::cerr << "Une erreur s'est produite. :(" << query.lastError().text().toStdString()<< std::endl;
				error_message=query.lastError().text();
				return false;

			}


		}
		else{
			std::cerr << "Error :" << db.lastError().text().toStdString() << std::endl;
			error_message=db.lastError().text();
			return false;
		}
	}


	bool PlatoDataProvider::support_auto_mapping(){
		return true;
	}

	std::vector<QString> * PlatoDataProvider::get_sample_foreign_key(QString  _experiment_name){
		std::cerr << "entering getsample foreign key" << std::endl;
		std::vector<QString> * samples=new std::vector<QString>();
		//QString uid=convert_uid_to_platoUID(_experiment_id);
		if (db.open()){
			QSqlQuery query("",db);
			if(query.prepare("SELECT Experiment_Fk,Sample_Fk,BatchNumber_Fk FROM [PlatoDB].[dbo].[BatchCompilation] WHERE Experiment_Fk=:experiment_name")){
				query.bindValue(":experiment_name", _experiment_name);
				query.exec();
				while (query.next())
				{
					QString Experiment_Fk = query.value(0).toString();
					QString Sample_Fk = query.value(1).toString();
					QString BatchNumber_Fk = query.value(2).toString();
					QString clustered_key=Experiment_Fk+"-"+Sample_Fk+"-"+BatchNumber_Fk;
					samples->push_back(clustered_key);
					std::cerr << "clustered key : " << clustered_key.toStdString() << std::endl;
				}
			}
			else{

			}


		}
		else{
			std::cerr << "Error" << db.lastError().text().toStdString() << std::endl;

		}
		return samples;
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

	#ifdef Q_OS_WIN
		dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;UID=%3;PWD=%4;").arg(ipserver).arg(database).arg(LoginName).arg(Pass);
	#endif
		return dsn;
	}
	void PlatoDataProvider::BuildConnection(){
		if (testCredentials("labdesigner","glucose")==Xeml::Sampling::Success){

			db = QSqlDatabase::addDatabase("QODBC","PlatoDB");
			QString dsn=buildDSN(this->myConfig.ServerIP,this->myConfig.Database,this->myConfig.Username,this->myConfig.Password);
			db.setDatabaseName(dsn);


		}



	}
//region Itfxemlcomponent
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
