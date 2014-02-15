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

int main(int argc, char *argv[])
{
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


	/*
	QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","postgres");
	//147.100.103.188
	db.setHostName("localhost");
	db.setUserName("postgres");
	db.setPassword("");
	db.setPort(5432);
	db.setDatabaseName("postgres");
	*/

		//147.100.103.188
		//127.0.0.1

	//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

	//db.setHostName("147.100.103.188");
	//db.setUserName("labdesigner");
	//db.setPassword("glucose");
	//db.setPort(1433);
	//db.setDatabaseName("PlatoDB");

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




	QStringList paths = QCoreApplication::libraryPaths();
	for (QStringList::iterator it = paths.begin(); it!=paths.end(); it++) {
		std::cerr << "Looking for plugins at path: " << it->toStdString() << std::endl;
	}
	QString ipserver,LoginName,database,Pass;
	ipserver="147.100.103.188";
	LoginName="labdesigner";
	database="PlatoDB";
	Pass="glucose";


	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","PlatoDB");
	/*QString driver_name="QMYSQL";
	if(db.isDriverAvailable(driver_name)){
		std::cerr << "Driver" << driver_name.toStdString() <<  " is available " << std::endl;
	}
	else{
		std::cerr << "Driver "<< driver_name.toStdString() <<  " is not available"<< std::endl;
	}*/
	//db.setDatabaseName("myodbc5a");
	//db.setDatabaseName("DRIVER={MyODBCa};Server="+ipserver+";Database="+database+";Port=1433;");


	//db.setHostName(ipserver);

	//db.setPort(1433);
	//db.setDatabaseName("myodbc5w");

	//db.setDatabaseName("myodbc5w");
	db.setDatabaseName("plato");
	db.setUserName(LoginName);
	db.setPassword(Pass);


	//ODBC 5.2(a) Driver
	//db.setDatabaseName("DRIVER={FreeTDSDriver};Uid="+LoginName+";Pwd="+Pass+";");

	//db.setDatabaseName("DRIVER={FreeTDSDriver};Server="+ipserver+";Database="+database+";Uid="+LoginName+";Port=1433;Pwd="+Pass+";");
	//db.setUserName(LoginName);
	//db.setPassword(Pass);

	//db.setDatabaseName("smilerMSSQL");




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
	   //QSqlQuery query;


	   if(query.exec("SELECT Uid FROM PLatoDB.dbo.[Experiments]"))
	   {
		   //if (!query.isActive())
			 //  QMessageBox::warning(w, tr("Database Error"),
				//					query.lastError().text());

		   std::cout << "Le titre a bien été changé ! :)" << std::endl;
		   while (query.next())
		   {
			   QString country = query.value(0).toString();
			   qDebug() << country;
		   }
	   }
	   else
	   {
		   std::cout << "Une erreur s'est produite. :(" << std::endl << query.lastError().text().toStdString()<< std::endl;
	   }




	   db.close();
	   //QSqlDatabase::removeDatabase("PlatoDB");
	}
	else{
		std::cerr << "Error" << db.lastError().text().toStdString() << std::endl;
	   //qDebug() << "Error" << *db*.lastError().text();
	}




	//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	//db.setHostName("147.100.103.188");
	//db.setDatabaseName("PlatoDB");
	//147.100.103.188
	//db.setDatabaseName("DRIVER={OpenLink SQL Server Lite Driver v6.0};UID=labdesigner;PWD=glucose;DATABASE=PlatoDB;TDSHOST=147.100.103.188;TDSPORT=1433");

	//db.setDatabaseName("DRIVER={SQL SERVER}; SERVER=147.100.103.188; DATABASE=PlatoDB");

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
	 * display Splashscreen during initialization
	*************************************************/

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

