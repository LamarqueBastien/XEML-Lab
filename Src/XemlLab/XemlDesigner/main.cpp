#include<QApplication>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QObject>
#include<QIODevice>
#include<QtWidgets>
#include<QDialog>
#include<QStyleFactory>
#include<iostream>
#include<sstream>
#include<fstream>
#include<QHBoxLayout>
#include<assert.h>
#include<map>
#include<QUrl>
#include <QtPlugin>
#include<QEventLoop>
#include<QTimer>
#include<QDomDocument>
#include<QtXml>
#include<QtSql>
#include"mainwindow.h"
#include"CoreObjects/story.h"
#include<QRegExp>
#include"CoreObjects/xemlannotableobject.h"
#include"CoreObjects/storybase.h"
#include"CoreObjects/taggedannotation.h"
#include"CoreObjects/xemldocument.h"
#include"CoreObjects/individual.h"
#include"CoreObjects/individualspool.h"
#include"filemanager.h"
#include<QDir>

#define QT_DEBUG_PLUGINS = 1;
//#define HOME = "/Users/benjamindartigues/Qt5.0.1/Root/";

using namespace std;
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;


class Story;
class XemlAnnotableObject;
class StoryBase;
class TaggedAnnotation;
class XemlDocument;
class Individual;
class IndividualsPool;
class FileManager;


//Q_IMPORT_PLUGIN(qsqlodbc)
QString uuidToString(const QVariant &v)
   {
	  // get pointer to raw data
	  QByteArray arr(v.toByteArray());
	  std::cerr << " arr : " << arr.toInt() << std::endl;
	  std::string result(arr.constData(),arr.size());
	  std::cerr << " size : " << result.size() << std::endl;
	  assert(result.size() == 16);
	  const char *ptr = result.data();
	  // extract the GUID-parts from the data
	  uint   data1 = *reinterpret_cast<const uint*>(ptr);
	  std::cerr << " data1 : " << data1 << std::endl;
	  ushort data2 = *reinterpret_cast<const ushort*>(ptr+=sizeof(uint));
	  ushort data3 = *reinterpret_cast<const ushort*>(ptr+=sizeof(ushort));
	  uchar  data4[8] =
	  {
		 *reinterpret_cast<const uchar*>(ptr+=sizeof(ushort)),
		 *reinterpret_cast<const uchar*>(++ptr),
		 *reinterpret_cast<const uchar*>(++ptr),
		 *reinterpret_cast<const uchar*>(++ptr),
		 *reinterpret_cast<const uchar*>(++ptr),
		 *reinterpret_cast<const uchar*>(++ptr),
		 *reinterpret_cast<const uchar*>(++ptr),
		 *reinterpret_cast<const uchar*>(++ptr)
	  };
	  // create a uuid from the extracted parts
	  QUuid uuid(
		 data1,
		 data2,
		 data3,
		 data4[0],
		 data4[1],
		 data4[2],
		 data4[3],
		 data4[4],
		 data4[5],
		 data4[6],
		 data4[7]);
	  // finally return the uuid as a QString
	  return uuid.toString();
   }
int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(Divers);
	// starting point of program
	QApplication                                             a(argc, argv);
	MainWindow                                                           w;


	/************************************************
	 * load the qss file for stylesheet
	*************************************************/
	QFile * style = new QFile("://StyleSheet/style.qss");

		if(!style->open(QIODevice::ReadOnly))
		{
			//QMessageBox::warning(this,"Erreur de chargement du style", "La feuille de style par défaut n'a pas pu être chargée correctement, veuillez relancer le logiciel afin que celle-ci prennent effet.");
		}
		else
		{
			QString StyleSheetDefaut(style->readAll());
			a.setStyleSheet(StyleSheetDefaut);

		}

	/************************************************
	 * retrieve all style available on this OS
	*************************************************/

	//QStringList tmp_list=QStyleFactory::keys();
	//foreach (QString str, tmp_list){
	//	std::cerr << "tmp_list : " << str.toStdString() << std::endl;
	//}

	//for (int i =0;i<tmp_list.size();i++){
	//	std::cerr << "tmp_list : " << tmp_list.at(i).toStdString() << std::endl;
	//}

	/************************************************
	 * test SQL database connection
	*************************************************/




	/******************************************************
	 */
/*


		QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","postgres");
		//147.100.103.188
		db.setHostName("localhost");
		db.setUserName("postgres");
		db.setPassword("");
		db.setPort(5432);
		db.setDatabaseName("postgres");


			//147.100.103.188
			//127.0.0.1

		//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

		//db.setHostName("147.100.103.188");
		//db.setUserName("labdesigner");
		//db.setPassword("glucose");
		//db.setPort(1433);
		//db.setDatabaseName("PlatoDB");*/


/*

	 *QString SQLServerProvider::buildDSN(QString server, QString database, QString username, QString password)
{
#ifdef Q_WS_MACX
	QString dsn = QString("DRIVER=/usr/local/lib/libtdsodbc.so;SERVER=%1;TDS_VERSION=8pClient;DATABASE=%2;PORT=1433;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
#endif

#ifdef Q_WS_X11
	QString dsn = QString("DRIVER={FreeTDS};SERVER=%1;TDS_VERSION=8.0;PORT=1433;DATABASE=%2;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
#endif

#ifdef Q_WS_WIN
	QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
#endif
	return dsn;
}
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", databaseName);
db.setDatabaseName(buildDSN(server, database, username, password));
*/

		QString dir = QDir::homePath();
		std::cerr << "dir home path : " << dir.toStdString() <<  std::endl;
		QDir d;
		QString libdir = d.absolutePath();
		std::cerr << "lib path = "<< libdir.toStdString() << std::endl;
/*
 *#ifdef Q_WS_X11
	QString dir = QDir::homePath();
	QDir d;
	QString libdir = d.absolutePath();

	QFile odbcinst(dir + "/.odbcinst.ini");
	if(!odbcinst.exists())
	{
		odbcinst.open(QIODevice::WriteOnly | QIODevice::Text);
		QTextStream out(&odbcinst);
		out << "[FreeTDS]\n";
		out << "Description = v0.91 with protocol v8.0\n";
		out << "Driver = " + libdir + "/libtdsodbc.so\n";
		out << "Setup = " + libdir + "/libtdsodbc.so\n";
		out << "FileUsage = 1";
		odbcinst.close();
	}
	else
	{
		QList<QString> lines;

		odbcinst.open(QIODevice::ReadOnly | QIODevice::Text);
		QTextStream readfile(&odbcinst);

		int i = 0, lnbr = 0;
		bool found = false;
		while(!readfile.atEnd())
		{
			QString line = readfile.readLine();
			if(line.contains("[FreeTDS]"))
			{
				lnbr = i;
				found = true;
			}
			lines.append(line);
			i++;
		}
		odbcinst.close();

		// append to end
		if(!found)
		{
			// append to the end
			odbcinst.open(QIODevice::Append | QIODevice::Text);
			QTextStream file(&odbcinst);

			file << "\n[FreeTDS]\n";
			file << "Description = v0.91 with protocol v8.0\n";
			file << "Driver = " + libdir + "/libtdsodbc.so\n";
			file << "Setup = " + libdir + "/libtdsodbc.so\n";
			file << "FileUsage = 1";
			odbcinst.close();
		}
		else // update existing entry
		{
			qDebug() << "Found an entry for FreeTDS. Updating driver to " + libdir + "/libtdsodbc.so.";
			qDebug() << lines[lnbr+2];
			qDebug() << lines[lnbr+3];

			lines.replace(lnbr + 2, "Driver = " + libdir + "/libtdsodbc.so");
			lines.replace(lnbr + 3, "Setup = " + libdir + "/libtdsodbc.so");

			QString text;
			for(int j = 0; j < lines.count(); j++)
			{
				text.append(lines[j] + "\n");
			}

			odbcinst.open(QIODevice::WriteOnly | QIODevice::Text);
			QTextStream updatefile(&odbcinst);
			updatefile << text;
			odbcinst.close();
		}

	}
#endif
*/

/*************************************************************************************************/

/*
	//Look for plugins path

	//QStringList paths = QCoreApplication::libraryPaths();
	//for (QStringList::iterator it = paths.begin(); it!=paths.end(); it++) {
	//	std::cerr << "Looking for plugins at path: " << it->toStdString() << std::endl;
	//
*/

		/*
		 *"SELECT Id FROM [PlatoDB].[dbo].[Experiments] WHERE Experiment_Fk='Wheatstem2013'"
		 *"SELECT Id FROM [PlatoDB].[dbo].[Experiments] WHERE Experiment_Fk='FRIM01_Avignon_Temperature1'"
		 *"SELECT Id FROM [PlatoDB].[dbo].[Experiments]"
		 */

		//Comment/Uncomment this part for SQL connection
		/****************************************
		 *
		QStringList tmp2 =QSqlDatabase::drivers();
		foreach (QString str, tmp2){
			std::cerr << "tmp_list : " << str.toStdString() << std::endl;
		}

#if defined(Q_OS_WIN)
		std::cerr << "Une erreur s'est produite. :(" << std::endl;
#elif defined(Q_OS_MACX)
		std::cerr << "MAC OS" << std::endl;
		QString dir = QDir::homePath();
		QDir d;
		QString libdir = d.absolutePath();
		std::cerr << "homepath : " << dir.toStdString() << "absolutepath : "<< libdir.toStdString() << std::endl;
#else
		std::cerr << "Une erreur s'est produite. :(" << std::endl;
#endif

//connection parameters
		QString ipserver,LoginName,database,Pass;
		ipserver="147.100.103.188";
		LoginName="labdesigner";
		database="PlatoDB";
		Pass="glucose";
QSqlDatabase db;

db = QSqlDatabase::addDatabase("QODBC","PlatoDB");

#ifdef Q_OS_MACX
	//QString dsn = QString("DRIVER=/usr/local/lib/libtdsodbc.so;SERVER=%1;TDS_VERSION=8pClient;DATABASE=%2;PORT=1433;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
	//QString dsn = QString("DRIVER={/usr/local/lib/libtdsodbc.so};TDS_VERSION=8.0;SERVER="+ipserver+";DATABASE="+database+";PORT=1433;UID="+LoginName+";PWD="+Pass+";");
	std::cerr << "Mac OS" << std::endl;

	//first way to connect without using dsn but you need to have the libtdsodbc.so installed in the right location
	//db = QSqlDatabase::addDatabase("QODBC","PlatoDB");

	db.setDatabaseName("DRIVER={/usr/local/lib/libtdsodbc.so};TDS_VERSION=8.0;SERVER="+ipserver+";DATABASE="+database+";PORT=1433;UID="+LoginName+";PWD="+Pass+";");

	//second way to connect using dsn  in /home/.odbc.ini files


		//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","PlatoDB");
		//db.setDatabaseName("plato");
		//db.setUserName(LoginName);
		//db.setPassword(Pass);




#endif
#ifdef Q_OS_X11
#endif
#ifdef Q_OS_LINUX
	//db = QSqlDatabase::addDatabase("QODBC","PlatoDB");
	db.setDatabaseName("DRIVER={FreeTDS};TDS_VERSION=8.0;SERVER="+ipserver+";DATABASE="+database+";PORT=1433;UID="+LoginName+";PWD="+Pass+";");

	//QString dsn = QString("DRIVER={FreeTDS};SERVER=%1;TDS_VERSION=8.0;PORT=1433;DATABASE=%2;UID=%3;PWD=%4;").arg(server).arg(database).arg(username).arg(password);
	std::cerr << "X11 OS" << std::endl;

#endif

#ifdef Q_OS_WIN
	db.setDatabaseName("DRIVER={SQL SERVER};Server="+ipserver+";Database="+database+";Port=1433;Uid="+LoginName+";Pwd="+Pass+";");
	std::cerr << "Win OS" << std::endl;

#endif




	//PLATO DB connection



	//db.setDatabaseName("DRIVER={FreeTDSDriver};Server="+ipserver+";Database="+database+";Uid="+LoginName+";Pwd="+Pass+";");

	//First requests test (to integrate in Plato_provider class (MSSQLprovider)

	if(db.open())
	  {
	   qDebug() << "Opened";
	   QStringList list=db.tables();

	   //record=db.record("Parameter");

	   std::cerr << "number of tables : " << list.size() << std::endl;
	   for (int i=0;i<list.count();i++){
		   std::cerr << list.at(i).toStdString() << std::endl;
	   }
	   QSqlQuery query("",db);

	   if(query.exec("SELECT Value,Sample FROM [PlatoDB].[dbo].[FreshWeights] WHERE Experiment_Fk='FRIM01_Avignon_Temperature1'"))
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
			   QString resultString2 = query.value(1).toString();
			   std::cerr << "result: " <<  resultString.toStdString() << " ------ results2: " <<resultString2.toStdString() << std::endl;
			   ///qDebug() << country;
		   }
		   std::cerr << "there is " << results_counter << "element in this table" << std::endl;
	   }
	   else
	   {
		   std::cout << "Une erreur s'est produite. :(" << query.lastError().text().toStdString()<< std::endl;
	   }
	   if(query.exec("SELECT Name,Description FROM [PlatoDB].[dbo].[Protocol]"))
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
			   QString resultString2 = query.value(1).toString();
			   std::cerr << "result: " <<  resultString.toStdString() << " ------ results2: " <<resultString2.toStdString() << std::endl;
			   ///qDebug() << country;
		   }
		   std::cerr << "there is " << results_counter << "element in this table" << std::endl;
	   }
	   else
	   {
		   std::cout << "Une erreur s'est produite. :(" << query.lastError().text().toStdString()<< std::endl;
	   }

	   //recuperer les batches d'une experience : SELECT BatchName_Fk FROM [PlatoDB].[dbo].[BatchCompilation] WHERE Experiment_Fk='FRIM01_Avignon_Temperature1'"
	   //recuperer les unique id de la table material  : SELECT UId FROM [PlatoDB].[dbo].[Material] WHERE Name='TomatoLeavesAdriano' // use QUuid resultString2 = query.value(0).toUuid();
	   //recuperer les samples id : SELECT Experiment_Fk,Sample_Fk,BatchNumber_Fk FROM [PlatoDB].[dbo].[BatchCompilation] WHERE Experiment_Fk='FRIM01_Avignon_Temperature1'
	   //pour récupérer les uid : "SELECT LEFT(CAST(UId as char(64)), 36) AS test FROM [PlatoDB].[dbo].[Experiments]"


	   //QSqlQuery a(db);
	   //a.exec("SELECT UId FROM [PlatoDB].[dbo].[Experiments] WHERE Id='Phenotom'");
	   //a.next();
	   //QSqlQuery b(db);
	   //b.prepare("SELECT UId FROM [PlatoDB].[dbo].[FreshWeights] where [PlatoDB].[dbo].[FreshWeights].UId=:id");
	   //while(a.isValid())
	   //{
		 // b.bindValue(":id",a.value(0));
		  //b.exec();
		  // ERROR: Operand type clash: image is incompatible with uniqueidentifier
		  //a.next();
	   //}

	   /*
	   QSqlQueryModel sqlmodel;
		sqlmodel.setQuery("SELECT UId FROM [PlatoDB].[dbo].[Experiments]");
		QTableView tbl;
		tbl.setModel(&sqlmodel);
		tbl.show();
		*/













		/*
	   #if defined(Q_OS_WIN)
		if(query.exec("SELECT UId FROM [PlatoDB].[dbo].[Experiments]"))
		#else
		if(query.exec("SELECT LEFT(CAST(UId as char(64)), 36),Id FROM [PlatoDB].[dbo].[Experiments]"))
		#endif
	   //if(query.exec("SELECT LEFT(CAST(UId as char(64)), 36) AS test FROM [PlatoDB].[dbo].[Experiments]"))
	   {
		   //if (!query.isActive())
			 //  QMessageBox::warning(w, tr("Database Error"),
				//					query.lastError().text());

		   std::cerr << "La requete a bien été effectué ! :)" << std::endl;
		   int results_counter=0;




		   while (query.next())
		   {
			  // std::cerr << "count : "<< query.record().field(0).name().toStdString() << std::endl;
			  // std::cerr << "count : "<< query.record().value(0).isNull() << std::endl;
			  // results_counter++;

			   //QUuid * test = new QUuid(query.value(0).toUuid());//(QUuid::Microsoft);
				//test->


			   //std::cerr << "count : "<< query.record().count() << std::endl;


			   //QByteArray arr(query.value(0).toByteArray());
			   //std::string result(arr.constData(),arr.size());
			   //assert(result.size() == 16);
			   //const char *ptr = result.data();
					 // extract the GUID-parts from the data
				//std::cerr << "version :" <<  query.value(0).toUuid().version() << std::endl;
			   //std::cerr << "query value : " << query.value(0).canConvert(QMetaType::QByteArray)<< std::endl;
			   //std::cerr << query.value(0).toByteArray().size() << std::endl;

			   //QString test = uuidToString(query.value(0));



				//if (query.value(0).toUuid().isNull()){
				//	std::cerr << "null uid" << std::endl;
				//}
				//else{
				//	std::cerr << "not null uid" << std::endl;
				//}
				std::cerr << "uid : " << query.value(0).toString().toStdString() << std::endl;
				std::cerr << "id : " << query.value(1).toString().toStdString() << std::endl;
				//QString ID=query.value(1).toString();
				//std::cerr << "Uid result : " << test.toStdString() << std::endl;
				//std::cerr << "id result : " << ID.toStdString() << std::endl;

				//QUuid * test =new QUuid();
			   //std::cerr << "test Uuid: " << test->toString().toStdString() << std::endl;


			   //QString Experiment_Fk = query.value(0).toString();
			   //QString Sample_Fk = query.value(1).toString();
			   //QString BatchNumber_Fk = query.value(2).toString();
			   //QString resultString2 = query.value(1).toString();
			   //std::cerr << "result: " <<  Experiment_Fk.toStdString()<<"-"<<Sample_Fk.toStdString()<<"-"<<BatchNumber_Fk.toStdString()<<std::endl;
			   //" ------ results2: " <<resultString2.toStdString() << std::endl;
			   ///qDebug() << country;
		   }
		   std::cerr << "there is " << results_counter << "element in this table" << std::endl;
	   }
	   else
	   {
		   std::cout << "Une erreur s'est produite. :(" << query.lastError().text().toStdString()<< std::endl;
	   }
	   db.close();
	   //db.removeDatabase("PlatoDB");
	   //QSqlDatabase::removeDatabase("PlatoDB");
	}
	else{
		std::cerr << "Error" << db.lastError().text().toStdString() << std::endl;
	   //qDebug() << "Error" << *db*.lastError().text();
	}

	*/

/*********************************************
	//Debug part
*********************************************/

/*
	QString driver_name="QMYSQL";
	if(db.isDriverAvailable(driver_name)){
		std::cerr << "Driver" << driver_name.toStdString() <<  " is available " << std::endl;
	}
	else{
		std::cerr << "Driver "<< driver_name.toStdString() <<  " is not available"<< std::endl;
	}
	//db.setDatabaseName("myodbc5a");
	//db.setDatabaseName("DRIVER={MyODBCa};Server="+ipserver+";Database="+database+";Port=1433;");


	//db.setHostName(ipserver);

	//db.setPort(1433);
	//db.setDatabaseName("myodbc5w");

	//db.setDatabaseName("myodbc5w");



	//ODBC 5.2(a) Driver
	//db.setDatabaseName("DRIVER={FreeTDSDriver};Uid="+LoginName+";Pwd="+Pass+";");

	//db.setDatabaseName("DRIVER={FreeTDSDriver};Server="+ipserver+";Database="+database+";Uid="+LoginName+";Port=1433;Pwd="+Pass+";");
	//db.setUserName(LoginName);
	//db.setPassword(Pass);

	//db.setDatabaseName("smilerMSSQL");*/
/*
	   //QSqlQuery query;

//functional request:


	   //"SELECT Experiment_Fk FROM [PlatoDB].[dbo].[FreshWeights]"
//request to test

	   //SELECT UId FROM [PLatoDB].[dbo].[Experiments]






	//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	//db.setHostName("147.100.103.188");
	//db.setDatabaseName("PlatoDB");
	//147.100.103.188
	//db.setDatabaseName("DRIVER={OpenLink SQL Server Lite Driver v6.0};UID=labdesigner;PWD=glucose;DATABASE=PlatoDB;TDSHOST=147.100.103.188;TDSPORT=1433");

	//it works on windows ://db.setDatabaseName("DRIVER={SQL SERVER}; SERVER=147.100.103.188; DATABASE=PlatoDB");

	//db.setDatabaseName("Driver={MySQL ODBC 5.1 Driver};SERVER=147.100.103.188;DATABASE=PlatoDB;");

	//QString ipserver,LoginName,database,Pass;



	//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");

	//db.setDatabaseName("DRIVER={SQL Server (MSSQLSERVER)};Server=147.100.103.188;Database=PlatoDB;Uid=LabDesigner;Pwd=glucose;");
	//db.setHostName("147.100.103.188");




	//db.setHostName("147.100.103.188");
	//db.setUserName("labdesigner");
	//db.setPassword("glucose");



	//db.setPort(5432);
	//db.setDatabaseName("PlatoDB");

	//PGconn *con = PQconnectdb("host=server user=bart password=simpson dbname=springfield");
	//QPSQLDriver *drv =  new QPSQLDriver(con);
	//QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL"); // devient la nouvelle connexion par défaut
	//QSqlQuery query;
	*/
/*
	QStringList tmp2 =QSqlDatabase::drivers();
	foreach (QString str, tmp2){
		std::cerr << "tmp_list : " << str.toStdString() << std::endl;
	}

	if (db.isValid()){
		std::cerr << "valid connection" << std::endl;
	}
	else{
		std::cerr << "invalid connection" << std::endl;
	}
	QSqlRecord record;
	*/
/*
	if(db.open())
	{
		QStringList list=db.tables();
		//record=db.record("Parameter");

		std::cerr << "number of tables : " << list.size() << std::endl;
		QSqlQuery query("SELECT * FROM PLatoDB.dbo.Unit", db);
			while (query.next())
			{
				QString country = query.value(0).toString();
				qDebug() << country;
			}




		//std::cerr << "Vous êtes maintenant connecté à " << db.hostName().toStdString() << std::endl;

		//QSqlQuery query;
		//query = QSqlQuery (db);


		//if(query.exec("select * from weather"))
		//{
		//	std::cerr <<  "column number  : " <<query.record().count() << std::endl;
		//	for (int i =0;i<query.record().count();i++){
		//		std::cerr << "firts column : " << record.fieldName(i).toStdString() << std::endl;
		//	}
			//std::cerr << query.record().value("city").toStringList()[0].toStdString() << std::endl;
		//}
		//else
		//{
		//	std::cerr << "Une erreur s'est produite. :(" << std::endl << query.lastError().text().toStdString() << std::endl;
		//}


		//QSqlQuery query1("select * from weather");
			// while (query1.next()) {
				 //QString country = query1.value(0).toString();
				 //std::cerr << country.toStdString() << std::endl;
				// std::cout << "column number  : " << query1.record().count() << std::endl;
			 //}


		db.close();

	}
	else
	{
		//qDebug() << db.lastError().databaseText();
		//std::cerr << "dbtext : " << db.lastError().databaseText().toStdString()  <<  std::endl;
		//std::cerr << "drivertext : " << db.lastError().driverText().toStdString() << std::endl;
		//std::cerr << db.lastError().text().toStdString() <<"La connexion a échouée, désolé" << std::endl;
	}
	*/



	/************************************************
	 *display Splashscreen during initialization
	************************************************ */

	QSplashScreen *splash = new QSplashScreen;

	a.setStyle(QStyleFactory::create("Fusion"));
#if defined(Q_OS_WIN)
	splash->setPixmap(QPixmap(":/Images/XemlLogo.png"));
#elif defined(Q_OS_MACX)
	a.setStyle(QStyleFactory::create("Macintosh"));
	splash->setPixmap(QPixmap(":/Images/XemlLogo.png"));
#else

	splash->setPixmap(QPixmap("/home/bdartigues/XEML-Lab/Src/XemlLab/XemlDesigner/Images/XemlLogo.png"));
#endif
	//splash->setPixmap(QPixmap(":/Images/XemlLogo.png"));///Users/benjamindartigues/XemlLab/XemlDesigner

	splash->show();

	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

	splash->showMessage(QObject::tr("Setting up the main window..."), topRight, Qt::black);



	splash->showMessage(QObject::tr("loading resources..."), topRight, Qt::black);

	MainWindow::loadResources();

	splash->showMessage(QObject::tr("building ontologies..."), topRight, Qt::black);

	// set up differents views in the main window
	w.set_up_onto_tree();
	w.set_up_storytree();
	w.set_up_germplasm();

	splash->finish(&w);

	delete splash;

	w.show();
	return a.exec();



}

/*
QDir my_dir(a.applicationDirPath());

//my_dir.;
my_dir.cdUp();
my_dir.cdUp();
my_dir.cdUp();
my_dir.cdUp();
my_dir.cdUp();
std::cerr << "dir path = " << my_dir.path().toStdString()<< std::endl;

std::cerr << "home path : " << QDir::homePath().toStdString()<< std::endl;
my_dir.mkdir("test_directory");
*/

