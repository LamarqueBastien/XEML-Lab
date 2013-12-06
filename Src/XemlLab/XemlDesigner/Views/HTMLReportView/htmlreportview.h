#ifndef HTMLREPORTVIEW_H
#define HTMLREPORTVIEW_H

#include <QWidget>
#include<QTextBrowser>
#include<QTextDocument>
#include<QHBoxLayout>
#include<QMenu>
#include<QAction>
#include<QMainWindow>
#include<QMenuBar>
#include<QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewDialog>
#include"Interface/itfdocument.h"
#include"CoreObjects/documentresources.h"
#include"CoreObjects/xemldocument.h"

using namespace Xeml::Document;

class HtmlReportView : public QWidget
{
		Q_OBJECT
	public:
		explicit HtmlReportView(QWidget *parent = 0);
		void  createMenus();
		void  createActions();

		void     extract_report_files();
		void     set_up(ItfDocument * _xemldoc,DocumentResources * _documentResources);
		QString  load_HTMl_from_file(QFile * _html_doc);
		void     generate_report();
		QString  generate_observation_schedule_table();
		QString  generate_material_table();
		QString  generate_sample_count();
		QString  generate_obs_count();
		QString  generate_variable_table();
		QString  generate_dynamic_variable_table();
		QString  generate_ontology_table();


	private:
		ItfDocument       * current_doc;
		DocumentResources * documentResources;
		QTextDocument     * doc;
		QTextBrowser      * HtmlEdit;
		QVBoxLayout       * layout;
		QMenuBar          * menubar;
		int                 obsPointCount;
		int                 sampleCount;
		QMenu             * fileMenu;
		QAction           * saveAction;
		QAction           * printAction;
		QAction           * printPreviewAction;
		QPrinter          * printer;
		//QPrintPreviewDialog preview;


	signals:

	public slots:
	private slots:

		void save();
		void print();
		void printPreview(QPrinter *printer);
		void filePrintPreview();

};

#endif // HTMLREPORTVIEW_H
