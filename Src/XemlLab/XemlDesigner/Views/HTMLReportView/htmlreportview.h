#ifndef HTMLREPORTVIEW_H
#define HTMLREPORTVIEW_H

#include <QWidget>
#include<QTextEdit>
#include<QHBoxLayout>
#include"Interface/itfdocument.h"
using namespace Xeml::Document;

class HtmlReportView : public QWidget
{
		Q_OBJECT
	public:
		explicit HtmlReportView(QWidget *parent = 0);
		void     extract_report_files();
		void     set_up(ItfDocument * _xemldoc);
		QString  load_HTMl_from_file(QFile * _html_doc);
		void     generate_report();
		QString  generate_observation_schedule_table();
		QString  generate_material_table();
		QString  generate_sample_count();
		QString  generate_obs_count();
		QString  generate_variable_table();
		QString  generate_ontology_table();

	private:
		ItfDocument * current_doc;
		QTextEdit * HtmlEdit;


	signals:

	public slots:

};

#endif // HTMLREPORTVIEW_H
