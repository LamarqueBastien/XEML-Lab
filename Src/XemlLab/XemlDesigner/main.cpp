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
	db.setPassword("bD1#popi");
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
	QString driver_name="QMYSQL";
	if(db.isDriverAvailable(driver_name)){
		std::cerr << "Driver" << driver_name.toStdString() <<  " is available " << std::endl;
	}
	else{
		std::cerr << "Driver "<< driver_name.toStdString() <<  " is not available"<< std::endl;
	}
	db.setHostName(ipserver);
	db.setUserName(LoginName);

	db.setPassword("glucose");
	db.setPort(1433);
	db.setDatabaseName("myodbc5a");
	//ODBC 5.2(a) Driver
	//db.setDatabaseName("DRIVER={SQL Server};Server="+ipserver+";Database="+database+";Uid="+LoginName+";Port=1433;Pwd="+Pass+";");


	//db.setDatabaseName("smilerMSSQL");




	if(db.open())
	  {
	   qDebug() << "Opened";
	   //db.close();
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
	if(db.open())
	{
		QStringList list=db.tables();
		//record=db.record("Parameter");

		std::cerr << "number of tables : " << list.size() << std::endl;


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

	MainWindow                                                           w;

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

