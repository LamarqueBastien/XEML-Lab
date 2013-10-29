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
#include<QApplication>
#include<QHBoxLayout>
#include<map>
#include<QUrl>
#include<QEventLoop>
#include<QTimer>
#include<QDomDocument>
#include<QtXml>
#include"mainwindow.h"
#include"story.h"
#include<QRegExp>
#include"xemlannotableobject.h"
#include"storybase.h"
#include"taggedannotation.h"
#include"xemldocument.h"
#include"individual.h"
#include"individualspool.h"
#include"filemanager.h"
#include<QDir>


#define HOME = "/Users/benjamindartigues/Qt5.0.1/Root/";

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


int main(int argc, char *argv[])
{
	QApplication                                             a(argc, argv);
	a.setStyle(QStyleFactory::create("Fusion"));
	//QStringList  list=QStyleFactory::keys();
	//for(int i=0;i<list.size();i++){
	//	std::cerr << list.at(i).toStdString() << std::endl;
	//}
	QString toto = QApplication::applicationDirPath();
	std::cerr << "dir path = " << toto.toStdString() << std::endl;

	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(QPixmap(":/Images/XemlLogo.png"));///Users/benjamindartigues/XemlLab/XemlDesigner
	splash->show();
	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
	splash->showMessage(QObject::tr("Setting up the main window..."), topRight, Qt::black);

	MainWindow                                                           w;

	splash->showMessage(QObject::tr("loading resources..."), topRight, Qt::black);

	MainWindow::loadResources();
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



	splash->showMessage(QObject::tr("building ontologies..."), topRight, Qt::black);

	// set up differents views in the main window
	w.set_up_onto_tree();
	w.set_up_storytree();
	w.set_up_germplasm();

	splash->finish(&w);

	delete splash;

	w.show();
	//QDateTime startDate(QDate(2012, 7, 6), QTime(8, 30, 0));
	//QDateTime endDate(QDate(2012, 7, 7), QTime(8, 30, 0));
	//std::cerr << "Days from startDate to endDate: " << startDate.daysTo(endDate) << std::endl;
	/*
	time_t startdate=time(NULL);
	struct tm * timeinfo;
	char buffer [80];
	QString date;
	time ( &startdate );
	timeinfo = localtime ( &startdate );
	strftime(buffer,80,"%Y-%m-%dT%H:%M:%S",timeinfo);
	//m_stream.write(buffer, 19);
	for(int i=0;i<19;i++){
		date+=buffer[i];
		std::cerr << buffer[i]<< std::endl;
	}
	std::cerr << date.toStdString()<< std::endl;
	*/
	//a.setAttribute(Qt::AA_DontShowIconsInMenus,false);

	//while(a.){


		//std::cerr << "timer" << std::endl;
		//if (timer.remainingTime() < 1000){
			//timer.start(10000);
			//std::cerr << "timer" << std::endl;

		//}
		//	std::cerr << "timer" << std::endl;
		//}
		//connect(timer,SIGNAL(),a,SLOT());
	//a.startTimer(10000000000000);

	return a.exec();
	//}


}

