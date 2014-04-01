#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>




using Xeml::Document::DocumentResources;


class DocumentResources;
class ItfDocument;


//static members
Xeml::Document::DocumentResources * MainWindow::doc_ressources= new Xeml::Document::DocumentResources();
FileManager * MainWindow::fmg=new FileManager();
//QStandardItemModel * my_model=new QStandardItemModel();


//regions constructors/destructors

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QString toto = QApplication::applicationDirPath();
	//std::cerr << "dir path = " << toto.toStdString() << std::endl;

	fmg->New();
	//std::cerr << QApplication::applicationFilePath().toStdString() << std::endl;

	std::cerr << "document initialised " << std::endl;

	this->setMinimumHeight(600);
	this->setMinimumWidth(1200);
	//this->setStyleSheet("QWidget { background-color: rgb(1,121,111); }");

/*
	this->zoomFactorSelector=new QComboBox;
	ZoomFactorLabel=new QLabel("Time Step :");
	ZoomFactorLabel->setBuddy(zoomFactorSelector);
	this->zoomFactorSelector->addItem("day slot");
	this->zoomFactorSelector->addItem("12 hours slot");
	this->zoomFactorSelector->addItem("8 hours slot");
	this->zoomFactorSelector->addItem("6 hours slot");
	this->zoomFactorSelector->addItem("4 hours slot");
	this->zoomFactorSelector->addItem("3 hours slot");
	this->zoomFactorSelector->addItem("2 hours slot");
	this->zoomFactorSelector->addItem(" hour slot");

	*/
	QMdiArea *zoneCentrale = new QMdiArea;
	//zoneCentrale->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	//zoneCentrale->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	//zoneCentrale->setViewMode(QMdiArea::TabbedView);

	//QTextEdit *zoneTexte3 = new QTextEdit;
	//graphicStoryView=new GraphicStoryView;
	storyView= new StoryView;
	ontologyView= new ParameterTreeView(true,this->fmg->get_current_xeml()->get_doc_resources());
	genotypeView= new GenotypeView;

	XemlCode=static_cast<XemlDocument*>(this->fmg->get_current_xeml())->generate_string_xml();
	//std::cerr << this->fmg->get_current_xeml()->get_doc_resources()->get_xeoHandler()->size() << std::endl;

	this->setWindowTitle("Xeml Interactive Designer 1.0");


	connect(this->ontologyView,SIGNAL(onParameterselected(ItfOntologyTerm*)),this->storyView,SLOT(new_parameter(ItfOntologyTerm*)));
	connect(this->ontologyView,SIGNAL(ontology_to_load(bool,bool,bool)),this,SLOT(add_ontologies(bool,bool,bool)));
	connect(this->storyView,SIGNAL(experimenter_settings(QString,QString,QString,QString)),this,SLOT(set_experimenter(QString,QString,QString,QString)));
	connect(this->genotypeView,SIGNAL(on_new_genotype(IndividualsPool*)),this->storyView,SLOT(add_genotype(IndividualsPool*)));
	connect(this->storyView,SIGNAL(refresh_genotype_view(ItfDocument *)),this->genotypeView,SLOT(refresh_view(ItfDocument *)));
	connect(this->storyView,SIGNAL(refresh_story_view(StoryView*)),this,SLOT(refresh_story_tree(StoryView*)));
	//connect(zoomFactorSelector,SIGNAL(currentIndexChanged(QString)),this->storyView,SLOT(set_up_zoom_factor(QString)));

	timer = new QTimer(this);
	QDir dir(QCoreApplication::applicationFilePath());
	my_dir=dir;
	while (! my_dir.path().endsWith("XEML-Lab")){
		my_dir.cdUp();
	}
	my_dir.mkdir("Files");
	my_dir.mkdir("ISA_exported_files");
	my_dir.cd("Files");
	curFile=my_dir.path()+"/last.xeml";
	this->fmg->get_current_xeml()->Save(curFile);


	//std::cerr << "dir path = " << my_dir.path().toStdString()<< std::endl;
	connect(timer, SIGNAL(timeout()), this, SLOT(auto_save()));
	timer->start(30000000);
	//QTimer::singleShot(10000, this, SLOT(auto_save()));

	QString fen1ObjectName("Ontology");
	QString fen2ObjectName("Story");
	QString fen3ObjectName("Genotype");


	QMdiSubWindow *sousFenetre1 = zoneCentrale->addSubWindow(this->ontologyView);
	sousFenetre1->setWindowFlags(Qt::FramelessWindowHint);
	//sousFenetre1->setWindowOpacity(0.5);
	//connect(sousFenetre1,SIGNAL(destroyed()),this,SLOT()
	//sousFenetre1->
	sousFenetre1->setObjectName(fen1ObjectName);
	//sousFenetre1->setStyleSheet("QWidget#"+fen1ObjectName +"{ background-image: url(://Images/BlueMetal.png);}"); ///Users/benjamindartigues/Pictures/BlueMetal.png
	//sousFenetre1->setWindowTitle("Ontologies Panel");
	//sousFenetre1->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


	QMdiSubWindow *sousFenetre2 = zoneCentrale->addSubWindow(this->storyView);
	//QMdiSubWindow *sousFenetre2 = zoneCentrale->addSubWindow(this->graphicStoryView);


	sousFenetre2->setWindowFlags(Qt::FramelessWindowHint);
	sousFenetre2->setObjectName(fen2ObjectName);
	//sousFenetre2->setStyleSheet("QWidget#"+fen2ObjectName +"{ background-image: url(://Images/BlueMetal.png);}");
	//sousFenetre2->setWindowTitle("Experiment Panel");

	QMdiSubWindow *sousFenetre3 = zoneCentrale->addSubWindow(this->genotypeView);
	//remove the buttons and the title
	sousFenetre3->setWindowFlags(Qt::FramelessWindowHint);
	//set the name for this windows to be connected with css stylesheet
	sousFenetre3->setObjectName(fen3ObjectName);
	//sousFenetre3->setStyleSheet("QWidget#"+fen3ObjectName +"{ background-image: url(://Images/BlueMetal.png);}");
	//sousFenetre3->setWindowTitle("Germplasm Panel");


	rightSplitter = new QSplitter(Qt::Vertical);
	rightSplitter->addWidget(sousFenetre2);
	rightSplitter->addWidget(sousFenetre3);
	rightSplitter->setStretchFactor(0, 10);
	rightSplitter->setStretchFactor(1, 1);
	mainSplitter = new QSplitter(Qt::Horizontal);
	mainSplitter->addWidget(sousFenetre1);
	mainSplitter->addWidget(rightSplitter);
	mainSplitter->setStretchFactor(1, 1);

	setCentralWidget(mainSplitter);
	createActions();
	createMenus();
	createToolBars();
	setCurrentFile(curFile);





		  QAction * minimizeAction = new QAction(tr("Mi&nimize"), this);
		 //connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

		 QAction * maximizeAction = new QAction(tr("Ma&ximize"), this);
		 //connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

			  QAction *  restoreAction = new QAction(tr("&Restore"), this);
			  //connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

			 QAction *  quitAction = new QAction(tr("&Quit"), this);
			  //connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
				QMenu *  trayIconMenu = new QMenu(this);
			  trayIconMenu->addAction(minimizeAction);
			  trayIconMenu->addAction(maximizeAction);
			  trayIconMenu->addAction(restoreAction);
			  trayIconMenu->addSeparator();
			  trayIconMenu->addAction(quitAction);

			  trayIcon = new QSystemTrayIcon(this);
			  trayIcon->setIcon(QIcon("://Images/XemlLogo.png"));
			  trayIcon->setContextMenu(trayIconMenu);
			  //connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::DoubleClick)),)
			  trayIcon->showMessage("Bonjour","Hello, world!");
			  trayIcon->setToolTip("blablahzebrqscs");


			  trayIcon->show();

}


MainWindow::~MainWindow()
{
	delete ui;
}




//function called in the beginning and when new ontologies were added.
//this will load every ontology in the standard xeml document

void    MainWindow::loadResources(){

	doc_ressources=fmg->get_current_xeml()->get_doc_resources();
	if(doc_ressources->contains("XEO",Xeml::Document::Contracts::Environment)){
		//std::cerr << " XEO foundsss" << std::endl;

		(*doc_ressources->get_xeoHandler())["XEO"]->loadOntology();

	}
	if(doc_ressources->contains("PO_Development",Xeml::Document::Contracts::Developmental)){
		(*doc_ressources->get_devHandler())["PO_Development"]->loadOntology();

	}
	if(doc_ressources->contains("PO_Structure",Xeml::Document::Contracts::OrganismStructure)){
		(*doc_ressources->get_structHandler())["PO_Structure"]->loadOntology();

	}
	if(doc_ressources->contains("XEO_Positioning",Xeml::Document::Contracts::Positioning)){
		(*doc_ressources->get_posHandler())["XEO_Positioning"]->loadOntology();

	}
	if(doc_ressources->contains("EO",Xeml::Document::Contracts::EO)){
		(*doc_ressources->get_EOHandler())["EO"]->loadOntology();

	}
	if(doc_ressources->contains("EnvO",Xeml::Document::Contracts::EnvO)){
		(*doc_ressources->get_EnvOHandler())["EnvO"]->loadOntology();

	}

}

//function called when user adds a ontology
// first check if the ontology is not already loaded else
// add to this document resources and load it.

void  MainWindow::add_ontologies(bool _xeoIsChecked,bool _eoIsChecked,bool _envoIsChecked){
	//QFile xml_doc(":/default.xeml");
	std::cerr << "add_ontologies" << std::endl;

	QFile xml_doc(this->curFile);
	QStringList * onto_to_load=new QStringList;
	QStringList * onto_to_remove=new QStringList;
	if(_xeoIsChecked && !(this->fmg->get_current_xeml()->get_doc_resources()->contains("XEO",Xeml::Document::Contracts::Environment))){
		std::cerr << "Xeo is Checked" << std::endl;
		onto_to_load->push_back("XEO");
	}
	if(!(_xeoIsChecked) && (this->fmg->get_current_xeml()->get_doc_resources()->contains("XEO",Xeml::Document::Contracts::Environment))){
		std::cerr << "Xeo is not Checked" << std::endl;
		onto_to_remove->push_back("XEO");
	}
	if(_eoIsChecked && !(this->fmg->get_current_xeml()->get_doc_resources()->contains("EO",Xeml::Document::Contracts::EO))){
		std::cerr << "eo is Checked" << std::endl;

		onto_to_load->push_back("EO");

	}
	if(!(_eoIsChecked) && (this->fmg->get_current_xeml()->get_doc_resources()->contains("EO",Xeml::Document::Contracts::EO))){
		std::cerr << "eo is not Checked" << std::endl;

		onto_to_remove->push_back("EO");

	}
	if(_envoIsChecked && !(this->fmg->get_current_xeml()->get_doc_resources()->contains("EnvO",Xeml::Document::Contracts::EnvO))){
		std::cerr << "envo is Checked" << std::endl;

		onto_to_load->push_back("EnvO");

	}
	if(!(_envoIsChecked) && (this->fmg->get_current_xeml()->get_doc_resources()->contains("EnvO",Xeml::Document::Contracts::EnvO))){
		std::cerr << "envo is not Checked" << std::endl;

		onto_to_remove->push_back("EnvO");

	}
	std::cerr << this->curFile.toStdString() << std::endl;
	QString uri;
	QString location;
	QDomDocument *dom = new QDomDocument("mon_xml");
	if(!xml_doc.open(QIODevice::ReadOnly)) // Si l'on n'arrive pas à ouvrir le fichier XML.
	{
		//QMessageBox::warning(this, "Erreur à l'ouverture du document XML", "Le document XML n'a pas pu être ouvert.");
		std::cerr << "Erreur à l'ouverture du document XML" << std::endl;

	}
	if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
	{
		xml_doc.close();
		//QMessageBox::warning(this, "Erreur à l'ouverture du document XML", "Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
		//return urls;
	}
	QDomElement dom_element = dom->documentElement();
	QDomNode noeud = dom_element.firstChild();

	std::cerr << "checkpoint " << std::endl;

	while(!noeud.isNull())// Tant que le nœud n'est pas vide.
	{
		if(!dom_element.isNull())
		{
			if(noeud.toElement().tagName().toStdString()=="xeml:Resources"){
				QDomElement element = noeud.toElement();
				QDomNodeList QNL=element.childNodes();
				for(int j =0; j < onto_to_load->length();j++){
					for (int i = 0; i < QNL.length(); i++) {
						std::cerr << "ns :" << QNL.item(i).toElement().attributeNode("NS").value().toStdString() << std::endl;
						if(QNL.item(i).toElement().attributeNode("NS").value()==onto_to_load->at(j)){
							uri=QNL.item(i).toElement().attributeNode("HandlerUri").value();
							location=QNL.item(i).toElement().attributeNode("InstanceLocation").value();
							std::cerr << "add :" << location.toStdString()<< std::endl;
							std::cerr << "add :" << uri.toStdString() << std::endl;


							//QString ns=QNL.item(i).toElement().attributeNode("NS").value();
						}

					}
					if (this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_load->at(j),Xeml::Document::Contracts::Developmental)){
						std::cerr << "developmental ontology double entry. Resource was rejected!" << std::endl;
					}
					else if (this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_load->at(j),Xeml::Document::Contracts::Environment)){
						std::cerr << "xeo ontology double entry. Resource was rejected!" << onto_to_load->at(j).toStdString() << std::endl;
					}
					else if (this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_load->at(j),Xeml::Document::Contracts::EnvO)){
						std::cerr << "Envo ontology double entry. Resource was rejected!" << std::endl;
					}
					else if (this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_load->at(j),Xeml::Document::Contracts::EO)){
						std::cerr << "EO ontology double entry. Resource was rejected!" << std::endl;
					}
					if (this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_load->at(j),Xeml::Document::Contracts::Genotype)){
						std::cerr << "developmental ontology double entry. Resource was rejected!" << std::endl;
					}
					else{

						std::cerr << "add :" << onto_to_load->at(j).toStdString() <<"ontology" << std::endl;
						std::cerr << "add :" << location.toStdString() <<"ontology" << std::endl;
						std::cerr << "add :" << uri.toStdString() <<"ontology" << std::endl;

						this->fmg->get_current_xeml()->get_doc_resources()->Add(uri,onto_to_load->at(j),location,false);
						std::cerr << "add " << onto_to_load->at(j).toStdString() <<"ontology" << std::endl;
					}
				}
				for(int j =0; j < onto_to_remove->length();j++){
					for (int i = 0; i < QNL.length(); i++) {
						if(QNL.item(i).toElement().attributeNode("NS").value()==onto_to_remove->at(j)){
							uri=QNL.item(i).toElement().attributeNode("HandlerUri").value();
							location=QNL.item(i).toElement().attributeNode("InstanceLocation").value();


							//QString ns=QNL.item(i).toElement().attributeNode("NS").value();
						}

					}
					//if (!(this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_remove->at(j),Xeml::Document::Contracts::Developmental))){
					//	std::cerr << "developmental ontology missing. Remove was rejected!" << std::endl;
					//}



					//else if (!this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_remove->at(j),Xeml::Document::Contracts::Genotype)){
					//	std::cerr << "genotype ontology missing. Resource was rejected!" << std::endl;
					//}
					//else{
						//for(std::map<QString,OntologyHandlerResources>::iterator it=this->fmg->get_current_xeml()->get_doc_resources()->)
					if(onto_to_remove->at(j)=="XEO"){
						if (!this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_remove->at(j),Xeml::Document::Contracts::Environment)){
							std::cerr << "xeo ontology missing. Resource was rejected!" << onto_to_load->at(j).toStdString() << std::endl;
						}
						else{

							this->fmg->get_current_xeml()->get_doc_resources()->remove(this->fmg->get_current_xeml()->get_doc_resources()->get_handler_by_alias(onto_to_remove->at(j),Xeml::Document::Contracts::Environment));
							std::cerr << "remove " << onto_to_remove->at(j).toStdString() <<"ontology" << std::endl;
						}
					}
					else if(onto_to_remove->at(j)=="EO"){
						if (!this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_remove->at(j),Xeml::Document::Contracts::EO)){
							std::cerr << "EO ontology missing. Resource was rejected!" << std::endl;
						}
						else{
							this->fmg->get_current_xeml()->get_doc_resources()->remove(this->fmg->get_current_xeml()->get_doc_resources()->get_handler_by_alias(onto_to_remove->at(j),Xeml::Document::Contracts::EO));
							std::cerr << "remove " << onto_to_remove->at(j).toStdString() <<"ontology" << std::endl;
						}
					}
					else{
						if (!this->fmg->get_current_xeml()->get_doc_resources()->contains(onto_to_remove->at(j),Xeml::Document::Contracts::EnvO)){
							std::cerr << "Envo ontology missing. Resource was rejected!" << std::endl;
						}
						else{
							this->fmg->get_current_xeml()->get_doc_resources()->remove(this->fmg->get_current_xeml()->get_doc_resources()->get_handler_by_alias(onto_to_remove->at(j),Xeml::Document::Contracts::EnvO));
							std::cerr << "remove " << onto_to_remove->at(j).toStdString() <<"ontology" << std::endl;
						}
					}
				}


			}
			noeud = noeud.toElement().nextSibling();
		}
		else{
			std::cerr << "problem null element" << std::endl;
		}


	}

	xml_doc.close(); //
	this->loadResources();
	this->refresh_onto_tree(this->ontologyView);

	//return current_uml;
}

//initialize this story view by callling the create experiment
//function from story view class.
void    MainWindow::set_up_storytree(){
	//this->storyView->setv
	this->storyView->createExperiment(this->fmg->get_current_xeml(),this->doc_ressources);
}


//initialize the ontology view by calling
// the set-up-ontology-tree fucntion from ontology view
void    MainWindow::set_up_onto_tree(){

	QStringList * ontologies= new QStringList;
	ontologies->append("XEO");
	ontologies->append("EO");
	ontologies->append("EnvO");
	//ontologies->append("XEO_Positioning");
	this->ontologyView->set_up_Ontologytree(this->doc_ressources,ontologies);
}

//initialize the genotype view by calling
// the initialize fucntion from genotype view
void MainWindow::set_up_germplasm(){
	this->genotypeView->initialize(this->fmg->get_current_xeml());
}

//creation of menu, toolbar, etc...
void    MainWindow::generate_isa_files(){
	this->data_exporter=new IsaExporter(this->fmg->get_current_xeml()->get_id(),"test");
	this->data_exporter->write(this->fmg->get_current_xeml(),new QTextStream());

}

void    MainWindow::createActions(){

	newAction = new QAction(QIcon(":/Images/new.png"),tr("&New"), this);
	newAction->setShortcut(tr("Ctrl+F"));
	newAction->setStatusTip(tr("Create a new file"));
	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

	HtmlReportAction=new QAction(QIcon(":/Images/html2.jpg"),tr("&HtmlReport"), this);
	HtmlReportAction->setShortcut(tr("Ctrl+R"));
	HtmlReportAction->setStatusTip(tr("generate Html Report"));
	connect(HtmlReportAction, SIGNAL(triggered()), this, SLOT(generate_html_report()));

	ISAExportAction=new QAction(tr("&Export to ISA files"), this);
	ISAExportAction->setShortcut(tr("Ctrl+Alt+I"));
	ISAExportAction->setStatusTip(tr("generate ISA files"));
	connect(ISAExportAction, SIGNAL(triggered()), this, SLOT(generate_isa_files()));
	ISAExportAction->setEnabled(false);

	/*
	viewModeAction=new QAction(QIcon(":/Images/new.png"),tr("&View Mode"), this);
	viewModeAction->setShortcut(tr("Ctrl+V"));
	viewModeAction->setStatusTip(tr("change view(tree vs graphic)"));
	connect(viewModeAction, SIGNAL(toggled(bool)), this, SLOT());

	*/

	loadCSVAction = new QAction(QIcon(":/Images/csv_text.png"),tr("&Load a csv file"), this);
	loadCSVAction->setShortcut(tr("Ctrl+L"));
	loadCSVAction->setStatusTip(tr("Load a csv file"));
	loadCSVAction->setWhatsThis("this view representing all stories defined by the experimenter");

	connect(loadCSVAction, SIGNAL(triggered()), this, SLOT(loadCSV()));

	newStoryAction = new QAction(tr("&NewStory"), this);
	newStoryAction->setIconVisibleInMenu(true);
	newStoryAction->setShortcut(tr("Ctrl+N"));
	newStoryAction->setStatusTip(tr("Create a new story"));
	connect(newStoryAction, SIGNAL(triggered()), this->storyView, SLOT(newStory()));


	addParameterAction = new QAction(tr("&AddParameter"), this);
	addParameterAction->setShortcut(tr("Ctrl+Alt+P"));
	addParameterAction->setStatusTip(tr("Add parameter to a story"));
	connect(addParameterAction, SIGNAL(triggered()), this->ontologyView, SLOT(add_parameter()));

	openAction = new QAction(QIcon(":/Images/open.png"),tr("&Open"), this);
	openAction->setIconVisibleInMenu(true);
	openAction->setShortcut(tr("Ctrl+O"));
	openAction->setStatusTip(tr("Open a new file"));
	connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

	saveAction = new QAction(QIcon(":/Images/save.png"),tr("&Save"), this);
	saveAction->setShortcut(tr("Ctrl+S"));
	saveAction->setStatusTip(tr("Save this file"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(validate_xml_to_save()));

	exitAction = new QAction(QIcon(":/Images/close.png"),tr("&Exit"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));

	parameterInfoAction = new QAction(tr("&Parameter Info"), this);
	parameterInfoAction->setShortcut(tr("Ctrl+P"));
	parameterInfoAction->setStatusTip(tr("show informations for this parameter"));
	connect(parameterInfoAction, SIGNAL(triggered()), this->ontologyView, SLOT(showSelection()));

	saveAsAction=new QAction(QIcon("://Images/SaveAs.png"),tr("&Save As"), this);
	saveAsAction->setIconVisibleInMenu(true);
	saveAsAction->setShortcut(tr("Ctrl+A"));
	saveAsAction->setStatusTip(tr("Save this file as "));
	connect(saveAsAction,SIGNAL(triggered()),this,SLOT(validate_xml_to_save_as()));

	databaseAction = new QAction(tr("&Database Connection"), this);
	databaseAction->setShortcut(tr("Ctrl+Alt+C"));
	databaseAction->setStatusTip(tr("database connection"));
	connect(databaseAction, SIGNAL(triggered()), this, SLOT(database_connect()));
	databaseAction->setEnabled(false);

	autoMappingAction = new QAction(tr("&AutoMappings"), this);
	autoMappingAction->setShortcut(tr("Ctrl+Alt+A"));
	autoMappingAction->setStatusTip(tr("automaps sample"));
	connect(autoMappingAction, SIGNAL(triggered()), this, SLOT(auto_mapping()));
	autoMappingAction->setEnabled(false);


	UuidAction = new QAction(tr("&Create a new Id"), this);
	UuidAction->setShortcut(tr("Ctrl+I"));
	UuidAction->setStatusTip(tr("create his own unique identifier"));
	connect(UuidAction, SIGNAL(triggered()), this, SLOT(uuid_dialog()));

	editXemlAction = new QAction(tr("&CodeEditor"), this);
	editXemlAction->setShortcut(tr("Ctrl+C"));
	editXemlAction->setStatusTip(tr("Display Xeml document"));
	connect(editXemlAction, SIGNAL(triggered()), this, SLOT(edit_xeml()));


	tableAction = new QAction(tr("&Experiment Table"), this);
	tableAction->setShortcut(tr("Ctrl+Alt+E"));
	tableAction->setStatusTip(tr("Display Xeml table"));
	connect(tableAction, SIGNAL(triggered()), this, SLOT(show_experiment_table()));
/*
	undoAction = undoStack->createUndoAction(this, tr("&Undo"));
	undoAction->setShortcuts(QKeySequence::Undo);

	redoAction = undoStack->createRedoAction(this, tr("&Redo"));
	redoAction->setShortcuts(QKeySequence::Redo);
*/
	aboutQtAction = new QAction(tr("About &Qt"), this);
	aboutQtAction->setStatusTip(tr("Show the Qt library’s About box"));
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

	for (int i = 0; i < MaxRecentFiles; ++i) {
		recentFileActions[i] = new QAction(this);
		recentFileActions[i]->setVisible(false);
		connect(recentFileActions[i], SIGNAL(triggered()),this, SLOT(openRecentFile()));
	}
}
void  MainWindow::show_experiment_table(){
	this->tableView =new ExperimentTableView(this->fmg->get_current_xeml());
	this->tableView->show();
}
//create his own Unique identifier (mostly to map with PLato Id)


void    MainWindow::uuid_dialog(){
	UuidDialog * uuiddialog=new UuidDialog();
	connect(uuiddialog,SIGNAL(new_uuid(QString)),this,SLOT(create_new_Uuid(QString)));
	uuiddialog->show();

}

void    MainWindow::create_new_Uuid(QString _uuid){
	QUuid uuid(_uuid);
	this->fmg->get_current_xeml()->set_id(uuid);
}


//Database connection and mapping part

void    MainWindow::database_connect(){
	SQLConnectionDialog * sql_connection_dialog=new SQLConnectionDialog;
	sql_connection_dialog->show();

}
void    MainWindow::auto_mapping(){
	std::vector<QString> * vec;
	std::vector<std::pair<DataProviderResources*,QString> > *  platoProvidervector = static_cast<XemlDocument*>(this->fmg->get_current_xeml())->get_doc_resources()->get_data_provider();
	for (std::vector<std::pair<DataProviderResources*,QString> >::iterator it =platoProvidervector->begin();it!=platoProvidervector->end();++it){
		std::cerr << "provider name: " << (*it).second.toStdString() << std::endl;
		if ((*it).second.toStdString()=="http://plato.codeplex.com/"){
			PlatoDataProvider * plato_provider= static_cast<PlatoDataProvider*>(static_cast<DataProviderResources*>((*it).first)->get_data_provider());
			std::cerr << "provider author: " <<plato_provider->get_author().toStdString() << std::endl;

			plato_provider->BuildConnection();
			//test if the experiment is present in the database
			QUuid expid("05ADF638-EAE3-41A3-AEC0-7961C21B14FC");
			//plato_provider->convert_uid_to_platoUID(this->fmg->get_current_xeml()->get_id());
			//if(plato_provider->search_for_experiment(this->fmg->get_current_xeml()->get_id())){
			if(plato_provider->search_for_experiment(expid)){

				std::cerr << "found an experiment called :" << plato_provider->get_experiment_name_by_uid(this->fmg->get_current_xeml()->get_id()).toStdString() << std::endl;
				int r = QMessageBox::warning(this, tr("XemlDocument"),
				tr("An experiment has been found called %1.\n"
				   "Do you want to link it with this xeml experiment?").arg(plato_provider->get_experiment_name_by_uid(this->fmg->get_current_xeml()->get_id())),
				QMessageBox::Yes | QMessageBox::Default,
				QMessageBox::No,
				QMessageBox::Cancel | QMessageBox::Escape);
				if (r == QMessageBox::Yes) {
					this->fmg->get_current_xeml()->set_experiment_name(plato_provider->get_experiment_name_by_uid(this->fmg->get_current_xeml()->get_id()));
					vec=plato_provider->get_sample_foreign_key(plato_provider->get_experiment_name_by_uid(expid));

					std::cerr << "sample number :" << vec->size() << std::endl;
				}
				//QString name=plato_provider->get_experiment_name_by_uid(expid);
				//std::cerr << "experiment name : "  << name.toStdString() << std::endl;


			}
			else{
				QMessageBox::information(this,"Dataset search","no experiment was found on "+plato_provider->get_componentName()+" with ID :"+this->fmg->get_current_xeml()->get_id().toString()+ "db error: " +plato_provider->get_error_message());

			}

		}



		//plato_provider->automap()

	}
}
//end region database connection and sample mappings





void    MainWindow::generate_html_report(){
	std::cerr << "entering html generation (MainWindows)" << std::endl;
	HtmlReportView * htmlView=new HtmlReportView();
	htmlView->set_up(static_cast<XemlDocument*>(this->fmg->get_current_xeml()),this->doc_ressources);
	htmlView->generate_report();
	htmlView->show();
}
void MainWindow::createUndoView(){
	undoView = new QUndoView(undoStack);
	undoView->setWindowTitle(tr("Command List"));
	undoView->show();
	undoView->setAttribute(Qt::WA_QuitOnClose, false);
}

void    MainWindow::createMenus() {


	fileMenu = new QMenu("&File", this);
	QMainWindow::menuBar()->addMenu(fileMenu);
	fileMenu->addAction(newAction);
	//fileMenu->addAction(newStoryAction);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addAction(loadCSVAction);
	fileMenu->addAction(ISAExportAction);
	ISAExportAction->setEnabled(false);

	separatorAction = fileMenu->addSeparator();
	for (int i = 0; i < MaxRecentFiles; ++i){
		fileMenu->addAction(recentFileActions[i]);
	}
		//fileMenu->addSeparator();
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	//qt_mac_set_dock_menu(&fileMenu);


	editMenu = QMainWindow::menuBar()->addMenu(tr("&Edit"));
	//editMenu->addAction(cutAction);
	editMenu->addAction(addParameterAction);
	editMenu->addAction(parameterInfoAction);

	toolsMenu = QMainWindow::menuBar()->addMenu(tr("&Tools"));
	toolsMenu->addAction(editXemlAction);
	toolsMenu->addAction(HtmlReportAction);
	toolsMenu->addAction(databaseAction);
	toolsMenu->addAction(UuidAction);
	toolsMenu->addAction(autoMappingAction);
	toolsMenu->addAction(tableAction);
	//toolsMenu->addAction(parameterInfoAction);

}
void    MainWindow::createToolBars() {

	fileToolBar = addToolBar(tr("&File"));
	fileToolBar->addAction(newAction);

	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);
	fileToolBar->addAction(saveAsAction);
	fileToolBar->addAction(exitAction);
	fileToolBar->addAction(loadCSVAction);
	fileToolBar->addAction(HtmlReportAction);
	fileToolBar->addSeparator();
	//fileToolBar->addWidget(ZoomFactorLabel);

	//fileToolBar->addWidget(zoomFactorSelector);


	//editToolBar = addToolBar(tr("&Edit"));
	//editToolBar->addAction(cutAction);
}




//function call everytime the user
//want to create a new document
//or open or save a document
bool    MainWindow::okToContinue() {

	/*
#if defined(Q_OS_WIN)
								   fileName= "C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
#elif defined(Q_OS_MACX)
								   fileName="/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
#else
								   fileName="/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
#endif
*/
	QString fileName;
	fileName="://XEMLStore/Templates/Standard.xeml";

	//QFile file(filePath);
	QFile standard_xeml(fileName);
	//QFile standard_xeml(fileName.toStdString().c_str());
	QString standardxeml=this->fmg->LoadXemlCodeFromFile(&standard_xeml);
	QString currentxeml=static_cast<XemlDocument*>(this->fmg->get_current_xeml())->generate_string_xml();
	//std::cerr << "current xeml : " << currentxeml.toStdString() << std::endl;
	//std::cerr << "standard xeml : " << standardxeml.toStdString() << std::endl;
	if (XemlCode!=currentxeml){
		this->setWindowModified(true);
	}
	if (isWindowModified()) {
		int r = QMessageBox::warning(this, tr("XemlDocument"),
		tr("The document has been modified.\n"
		   "Do you want to save your changes?"),
		QMessageBox::Yes | QMessageBox::Default,
		QMessageBox::No,
		QMessageBox::Cancel | QMessageBox::Escape);
		if (r == QMessageBox::Yes) {
			return validate_xml_to_save();
		}
		else if (r == QMessageBox::Cancel) {
			return false; }
		else{
			return true;
		}

	}
	return true;




}

void    MainWindow::setCurrentFile(const QString &fileName){
	curFile = fileName;
	setWindowModified(false);
	QString shownName = "Untitled";
	if (!curFile.isEmpty()) {
		shownName = strippedName(curFile);
		recentFiles.removeAll(curFile);
		recentFiles.prepend(curFile);
		updateRecentFileActions();
	}
	setWindowTitle(tr("%1[*] - %2").arg(shownName).arg("XemlLab"));
}

QString MainWindow::strippedName(const QString &fullFileName) {
	return QFileInfo(fullFileName).fileName();
}

void    MainWindow::updateRecentFileActions() {
	QMutableStringListIterator i(recentFiles);
	while (i.hasNext()) {
		if (!QFile::exists(i.next())){
			i.remove();
		}
	}
	for (int j = 0; j < MaxRecentFiles; ++j) {
		if (j < recentFiles.count()) {
			QString text = tr("&%1 %2")
							.arg(j + 1)
							.arg(strippedName(recentFiles[j]));
			recentFileActions[j]->setText(text);
			recentFileActions[j]->setData(recentFiles[j]);
			recentFileActions[j]->setVisible(true);
		}
		else {
			recentFileActions[j]->setVisible(false);
		}
	}
	separatorAction->setVisible(!recentFiles.isEmpty());
}
void MainWindow::openRecentFile()
{
	if (okToContinue()) {
		QAction *action = qobject_cast<QAction *>(sender());
		if (action)

				this->curFile=action->data().toString();
				setCurrentFile(this->curFile);
				this->fmg->purgedetailsFromdocument();
				std::cerr  << " file to load :" << this->curFile.toStdString() << std::endl;
				this->fmg->LoadFile(this->curFile,false);
				this->loadResources();
				this->refresh_trees();

			//loadFile(action->data().toString());
} }

bool    MainWindow::loadFile(const QString &fileName){
	return true;
	std::cerr << fileName.toStdString() << std::endl;
}

bool    MainWindow::saveFile(const QString &fileName){
	return true;
	std::cerr << fileName.toStdString() << std::endl;
}

void    MainWindow::refresh_trees(){
	//this->ontologyView->deleteLater();
	//this->storyView->deleteLater();
	this->ontologyView->clean_tree();
	this->storyView->clean_tree();
	this->genotypeView->clean_view();
	this->set_up_onto_tree();
	this->set_up_storytree();
	this->set_up_germplasm();
	this->genotypeView->show();
	this->ontologyView->show();
	this->storyView->show();
}


//private slots

void    MainWindow::loadCSV(){
	this->csvLoader=new LoaderWizard(this->storyView->get_model(), this->fmg->get_current_xeml(),this->doc_ressources);
	this->csvLoader->show();
}

void    MainWindow::newFile(){

	QString fileName;
	/*
#if defined(Q_OS_WIN)
								   fileName= "C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
#elif defined(Q_OS_MACX)
								   fileName="/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
#else
								   fileName="/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
#endif
*/
	fileName="://XEMLStore/Templates/Standard.xeml";
	//QFile standard_xeml(fileName.toStdString().c_str());
	if(okToContinue()){
		//xeml_doc.clear();
		//setCurrentFile("");

		//QString fileName = QFileDialog::getOpenFileName(this,tr("open xeml files"),"\\/",tr("xeml files (*.xml *.xeml)\n"));
		if (!fileName.isEmpty()) {
			std::cerr << "filename in new file : "<< fileName.toStdString() << std::endl;
			this->fmg->purgedetailsFromdocument();
			this->fmg->LoadFile(fileName,true);
			this->loadResources();
			this->refresh_trees();
		}
	}

}


void    MainWindow::refresh_story_tree(StoryView * _storyview){
	std::cerr << "entering refresh story view ( Main window)" << std::endl;
	_storyview->clean_tree();
	this->set_up_storytree();
	_storyview->show();
}
void MainWindow::refresh_story_tree(bool _Mode,StoryView * _storyview){

	_storyview->hide();
	_storyview->show();

	//_storyview->clean_tree();
	//this->set_up_storytree();
	//_storyview->show();
}

void    MainWindow::refresh_onto_tree(ParameterTreeView * _ontoview){
	std::cerr << "entering refresh story view ( Main window)" << std::endl;
	_ontoview->clean_tree();
	this->set_up_onto_tree();
	_ontoview->show();
}

void    MainWindow::open(){
	if(okToContinue()){
		QString fileName = QFileDialog::getOpenFileName(this,tr("open xeml files"),"\\/",tr("xeml files (*.xml *.xeml)\n"));
		if (!fileName.isEmpty()) {
			this->curFile=fileName;
			setCurrentFile(curFile);
			this->fmg->purgedetailsFromdocument();
			this->fmg->LoadFile(fileName,false);
			this->loadResources();
			this->refresh_trees();
		}
	}

}

bool    MainWindow::validate_xml_to_save(){
	std::cerr << " entering validate_xml_to_save " << std::endl;
	ValidationWindow * xmlValid=new ValidationWindow(false,static_cast<XemlDocument*>(this->fmg->get_current_xeml())->generate_string_xml());
	connect(xmlValid,SIGNAL(validated(bool)),this,SLOT(save(bool)));
	//xmlValid->setVisible(false);

	xmlValid->show();
}
bool    MainWindow::validate_xml_to_save_as(){
	ValidationWindow * xmlValid=new ValidationWindow(false,static_cast<XemlDocument*>(this->fmg->get_current_xeml())->generate_string_xml());
	connect(xmlValid,SIGNAL(validated(bool)),this,SLOT(saveAs(bool)));


	xmlValid->show();
}

void    MainWindow::auto_save(){
	//std::cerr << " path to :" << QCoreApplication::applicationFilePath().toStdString() << std::endl;

	//std::cerr << "saving files" << std::endl;
	//my_dir.cd( "Files");
	//std::cerr << "path to :" << my_dir.path().toStdString() << std::endl;
	this->fmg->get_current_xeml()->Save(curFile);
	//this->fmg->get_current_xeml()->Save("/Users/benjamindartigues/Documents/test_last.xeml");
}
bool    MainWindow::saveAs(bool _IsValid){
	std::cerr << " entering save as " << std::endl;

	if (_IsValid){
		std::cerr << "is valid :" << std::endl;
		QString fileName = QFileDialog::getSaveFileName(this,tr("Save Xeml"), ".",tr("Xeml files (*.xeml)"));
		if (fileName.isEmpty()){

			return false;
		}
		else{

			this->fmg->get_current_xeml()->Save(fileName);
			setCurrentFile(fileName);
			//ValidationWindow * xmlValid=new ValidationWindow(fileName);
			//connect(xmlValid,SIGNAL(validated(bool))

			return true;
		}
	}
	else{

		QMessageBox::information(this,"no selection","Document not valid! can't save");

		return false;
	}
}

bool    MainWindow::save(bool _IsValid){


	std::cerr << " entering save " << std::endl;



	if (_IsValid){

		this->fmg->get_current_xeml()->Save(curFile);

		/*
		QString fileName = QFileDialog::getSaveFileName(this,tr("Save Xeml"), ".",tr("Spreadsheet files (*.xeml)"));
		if (fileName.isEmpty()){

			return false;
		}
		else{

			this->fmg->get_current_xeml()->Save(fileName);
			//ValidationWindow * xmlValid=new ValidationWindow(fileName);
			//connect(xmlValid,SIGNAL(validated(bool))

			return true;
		}
		*/
		return true;
	}
	else{

		QMessageBox::information(this,"no selection","Document not valid! can't save");

		return false;
	}
}

void    MainWindow::exit(){
	this->close();
}

void    MainWindow::edit_xeml(){
	//static_cast<XemlDocument*>(this->fmg->get_current_xeml())->generate_string_xml();
	XemlCodeEditor * code_edit= new XemlCodeEditor(static_cast<XemlDocument*>(this->fmg->get_current_xeml())->generate_string_xml());
	code_edit->show();

}

void    MainWindow::cut(){


}

void    MainWindow::set_experimenter(QString _firstnametext,QString _lastnametext,QString _organisationtext,QString _emailtext){
	this->fmg->get_current_xeml()->get_experimentheader()->get_experimenter()->set_firstname(_firstnametext);
	this->fmg->get_current_xeml()->get_experimentheader()->get_experimenter()->set_lastname(_lastnametext);
	this->fmg->get_current_xeml()->get_experimentheader()->get_experimenter()->set_organization(_organisationtext);
	this->fmg->get_current_xeml()->get_experimentheader()->get_experimenter()->set_email(_emailtext);
}

//protected function
void    MainWindow::closeEvent(QCloseEvent *event){
	//event->ignore();
	if(okToContinue()){
		this->fmg->get_current_xeml()->Save("/Users/benjamindartigues/Documents/test_last.xeml");
		event->accept();
	}

	else{
		std::cerr << "event ignore" << std::endl;
		event->ignore();
		QTimer::singleShot(0,this,SLOT(hide()));
		QTimer::singleShot(5,this,SLOT(show()));

//#if defined(Q_OS_MACX)
//		this->show();
//#endif
		//this->setVisible(true);
	}


}




