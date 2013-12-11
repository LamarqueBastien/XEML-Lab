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
#include<QEventLoop>
#include<QTimer>
#include<QDomDocument>
#include<QtXml>
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
	// starting point of program
	QApplication                                             a(argc, argv);
	a.setStyle(QStyleFactory::create("Windows"));
	QStringList tmp_list=QStyleFactory::keys();
	foreach (QString str, tmp_list){
		std::cerr << "tmp_list : " << str.toStdString() << std::endl;
	}

	//for (int i =0;i<tmp_list.size();i++){
	//	std::cerr << "tmp_list : " << tmp_list.at(i).toStdString() << std::endl;
	//}


	// display Splashscreen during initialization
	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(QPixmap("://Images/XemlLogo.png"));///Users/benjamindartigues/XemlLab/XemlDesigner
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

