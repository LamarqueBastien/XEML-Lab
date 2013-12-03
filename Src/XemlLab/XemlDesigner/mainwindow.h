#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<map>
#include<string>
#include<iostream>
#include<QMainWindow>
#include<QTableWidget>
#include<QLabel>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QUrl>
#include<QStringList>
#include<QStringListModel>
#include<QListView>
#include<QLineEdit>
#include<QTextEdit>
#include<QVBoxLayout>
#include<QPushButton>
#include<QFormLayout>
#include<QMdiArea>
#include<QMdiSubWindow>
#include<QStandardItemModel>
#include<QTreeView>
#include<QStandardItem>
#include<QSplitter>
#include<QFileDialog>
#include<QTimer>
#include"Views/storyview.h"
//#include"graphicstoryview.h"
#include"Views/genotypeview.h"
#include"filemanager.h"
#include"Interface/itfdocument.h"
#include"Views/Items/parameteritem.h"
#include"CoreObjects/documentresources.h"
#include"Views/parametertreeview.h"
#include"XemlCSVLoader/loaderwizard.h"
#include"XMLValidation/validationwindow.h"
#include"Views/xemlcodeeditor.h"
#include"Views/HTMLReportView/htmlreportview.h"

using namespace std;
using Xeml::Document::DocumentResources;


class QAction;
class QLabel;

namespace Ui {
	class MainWindow;
}


class MainWindow : public QMainWindow
{
		Q_OBJECT

	private:
		Ui::MainWindow                           * ui;
		QTimer                                   * timer;
		QBasicTimer                                m_timer;
		QTime                                      m_firstChange;
		void                                       createActions();
		void                                       createMenus();
		void                                       createToolBars();

		bool                                       okToContinue();
		void                                       updateRecentFileActions();
		QString                                    strippedName(const QString &fullFileName);
		void                                       setCurrentFile(const QString &fileName);
		bool                                       loadFile(const QString &fileName);
		bool                                       saveFile(const QString &fileName);

		static Xeml::Document::DocumentResources * doc_ressources;
		static FileManager                       * fmg;
		LoaderWizard                             * csvLoader;
		QString                                    XemlCode;
		QDir                                       my_dir;
		//QStandardItemModel                       * my_model;
		//QStandardItemModel                       * my_modelstory;

		//my views
		StoryView                                * storyView;
		//GraphicStoryView                         * graphicStoryView;
		GenotypeView                             * genotypeView;
		ParameterTreeView                        * ontologyView;


		QLabel                                   * locationLabel;
		QLabel                                   * formulaLabel;
		//QTreeView                                * ontology_tree;
		//QTreeView                                * story_tree;
		//QStandardItem                            * item1;
		QStringList                                recentFiles;
		QString                                    curFile;

		QSplitter                                * rightSplitter;
		QSplitter                                * mainSplitter;


		//QMenu
		QMenu                                    * fileMenu;
		QMenu                                    * editMenu;
		QMenu                                    * helpMenu;
		QMenu                                    * toolsMenu;

		//QtoolBar
		QToolBar                                 * fileToolBar;
		QToolBar                                 * editToolBar;

		//QActions
		enum { MaxRecentFiles = 5 };
		QAction                                  * recentFileActions[MaxRecentFiles];
		QAction                                  * separatorAction;
		QAction                                  * parameterInfoAction;
		QAction                                  * cutAction;
		QAction                                  * editXemlAction;
		QAction                                  * addParameterAction;
		QAction                                  * loadAction;
		QAction                                  * newAction;
		QAction                                  * viewModeAction;
		QAction                                  * newStoryAction;
		QAction                                  * saveAction;
		QAction                                  * saveAsAction;
		QAction                                  * openAction;
		QAction                                  * aboutQtAction;
		QAction                                  * exitAction;
		QAction                                  * loadCSVAction;
		QAction                                  * ValidationAction;
		QAction                                  * HtmlReportAction;



	protected:

		void                                       closeEvent(QCloseEvent *event);

	public:

		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		static void                                loadResources();
		void                                       set_up_storytree();
		void                                       set_up_onto_tree();
		void                                       set_up_germplasm();
		void                                       refresh_trees();


	signals:


	private slots:

		void                                       newFile();
		void                                       loadCSV();
		void                                       generate_html_report();
		void                                       open();
		void                                       openRecentFile();
		void                                       auto_save();
		bool                                       save(bool _IsValid);
		bool                                       saveAs(bool _IsValid);
		void                                       exit();
		void                                       cut();
		void                                       edit_xeml();
		void                                       set_experimenter(QString _firstnametext,QString _lastnametext,QString _organisationtext,QString _emailtext);
		bool                                       validate_xml_to_save();
		bool                                       validate_xml_to_save_as();
		void                                       refresh_story_tree(StoryView * _storyview);
		void                                       refresh_story_tree(bool _Mode,StoryView * _storyview);
		void                                       refresh_onto_tree(ParameterTreeView * _ontoview);
		void                                       add_ontologies(bool _xeoIsChecked,bool _eoIsChecked,bool _envoIsChecked);


		//void                                       clicSelection();
		//void                                       showSelection();
		//void                                       load();
		//bool                                       saveAs();
		//void                                       find();
		//void                                       sort();
		//void                                       about();



};

#endif // MAINWINDOW_H
