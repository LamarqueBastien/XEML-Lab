#include "htmlreportview.h"

HtmlReportView::HtmlReportView(QWidget *parent) :
	QWidget(parent)
{
	HtmlEdit= new QTextEdit();
	QHBoxLayout * layout=new QHBoxLayout;
	layout->addWidget(HtmlEdit);

	this->setLayout(layout);
	//this->generate_report();

}
void HtmlReportView::extract_report_files(){

	//verifier que le repertoire HtmlReport existe, si non le creer
	//copier tous les ficheirs nécesssaires à l'ouverture du rapport, images, plot,etc...
	//
}

void HtmlReportView::set_up(ItfDocument * _xemldoc){
	this->current_doc=_xemldoc;
}
QString HtmlReportView::load_HTMl_from_file(QFile * _html_doc){
	_html_doc->open(QIODevice::ReadOnly);
	QTextStream MonFichier(_html_doc);
	QString text="";
	QString finaltext="";
	while(!MonFichier.atEnd())
	{

		MonFichier >> text;
		std::cerr << "text : " << text.toStdString() << std::endl;
		finaltext+=text;
	}

	return finaltext;
}
void HtmlReportView::generate_report(){
	std::cerr << "entering generate html report ( HtmlReportView)" << std::endl;

	if (current_doc!=NULL){
		//read the file report_template.html
		QFile html_file(":/XEMLReport.html");
		QString Template=load_HTMl_from_file(&html_file);
		std::cerr << "Template :" << Template.toStdString() << std::endl;
		//HtmlEdit->insertHtml("<b>Hello</b> <i>Qt!</i>" );
		HtmlEdit->insertHtml(Template);
		//HtmlEdit->insertHtml("Template");
		/*
		Template.replace("$xeml_experimenter_firstname$",current_doc->get_experimentheader()->get_experimenter()->get_firstname());
		Template.replace("$xeml_experimenter_lastname$",current_doc->get_experimentheader()->get_experimenter()->get_lastname());
		Template.replace("$xeml_experimenter_email$",current_doc->get_experimentheader()->get_experimenter()->get_email());
		Template.replace("$xeml_experimenter_description$",current_doc->get_experimentheader()->get_summary());
		Template.replace("$xeml_experimenter_organisation$",current_doc->get_experimentheader()->get_experimenter()->get_organization());

		Template.replace("$xeml_experiment_name$",current_doc->get_experiment_name());
		//ajouter format pour affichage plus complet de l'heure
		Template.replace("$xeml_experiment_date$",current_doc->get_startdate().toString("dd-MM-yyyyThh:mm:ss"));
		Template.replace("$xeml_ontology_table$",generate_ontology_table());
		Template.replace("$xeml_sample_count$",generate_sample_count());
		Template.replace("$xeml_observationpoint_count$",generate_obs_count());

		Template.replace("$xeml_allparameter_table$",generate_variable_table());
		Template.replace("$xeml_variables_table$",generate_variable_table());
		Template.replace("$xeml_material_table$",generate_material_table());
		Template.replace("$xeml_observationschedule_table$",generate_observation_schedule_table());

		*/
		//regenerer le document à partir


		//remplacer chaque valeur
	}
}

QString HtmlReportView::generate_observation_schedule_table()
{
	// create a table with all informations about observation
	// Date, Time, Duration, #individuals
}

QString HtmlReportView::generate_material_table()
{
	//create table with all material used during experiment

}

QString HtmlReportView::generate_sample_count()
{

}

QString HtmlReportView::generate_obs_count()
{

}

QString HtmlReportView::generate_variable_table()
{

}

QString HtmlReportView::generate_ontology_table()
{

}

