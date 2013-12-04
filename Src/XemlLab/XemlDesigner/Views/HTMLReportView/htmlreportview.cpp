#include "htmlreportview.h"

HtmlReportView::HtmlReportView(QWidget *parent) :
	QWidget(parent)
{
	HtmlEdit= new QTextBrowser( 0 );
	QHBoxLayout * layout=new QHBoxLayout;
	obsPointCount=0;
	sampleCount=0;
	layout->addWidget(HtmlEdit);

	this->setLayout(layout);
	//this->generate_report();

}
void HtmlReportView::extract_report_files(){

	//verifier que le repertoire HtmlReport existe, si non le creer
	//copier tous les ficheirs nécesssaires à l'ouverture du rapport, images, plot,etc...
	//
}

void HtmlReportView::set_up(ItfDocument * _xemldoc,DocumentResources * _documentResources){
	this->current_doc=_xemldoc;
	this->documentResources=_documentResources;
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
		if (text=="</html>"){
			return finaltext;
		}
	}

	return finaltext;
}
void HtmlReportView::generate_report(){


	// Your HTML code
	QString template_html;
	if (current_doc!=NULL){
		//read the file report_template.html
		QFile html_file(":/XEMLReport.html");
		template_html=load_HTMl_from_file(&html_file);
	}
	QString html;
	html = "<html><head>"
		   "<link rel='stylesheet' type='text/css' href='format.css'>"
		   "</head><body class = tuning>"
		   //"Your HTML code with tags, which have classes or ids. For example "
		   //"<span class='red'>this text is colored red</span>.<br/>"
		   //"And you can also display images: <img src=':/Images/SaveAs.png'><br/>"
		   //"Combine css and images: <span id='bgimage'>foo bar</span><br/>"


		   "<span class= styles>"
		   "$xeml_experiment_name$ - summary report <br />"
		   "<hr>"
		   "<span class= 'blue'>Experimenter : </span><br />"
		   "FirstName : $xeml_experimenter_firstname$ <br />"
		   "LastName : $xeml_experimenter_lastname$ <br />"
		   "Email : $xeml_experimenter_email$ <br />"
		   "Organization : $xeml_experimenter_organisation$ <br />"
		   "<hr>"
		   "<span class= 'blue'>Experiment : </span><br />"
		   "$xeml_experiment_name$ are started at $xeml_experiment_date$. <br />"


		   "Within this experiment, $xeml_observationpoint_count$ observation point(s) "
		   "and $xeml_sample_count$ samples collected.<br /> "
		   "<hr>"
		   "For this samples these material "
		   "are observed $xeml_material_table$.<br /> "
		   "<hr>"
		   "The following ontologies are referenced by this document: <br/>"
		   "$xeml_ontology_table$ <br/>"

		   "For the definition of the environmental conditions the following parameters are"
		   "used:<br />"
		   "$xeml_variables_table$<br />"

		   "From these parameter the following are variables:<br />"
		   "$xeml_allparameter_table$</span><br />"
		   "</body></html>";

	// Your CSS code

	/*
	html.replace("$xeml_experimenter_firstname$",current_doc->get_experimentheader()->get_experimenter()->get_firstname());
	html.replace("$xeml_experimenter_lastname$",current_doc->get_experimentheader()->get_experimenter()->get_lastname());
	html.replace("$xeml_experimenter_email$",current_doc->get_experimentheader()->get_experimenter()->get_email());
	html.replace("$xeml_experimenter_description$",current_doc->get_experimentheader()->get_summary());
	html.replace("$xeml_experimenter_organisation$",current_doc->get_experimentheader()->get_experimenter()->get_organization());

	html.replace("$xeml_experiment_name$",current_doc->get_experiment_name());

	//ajouter format pour affichage plus complet de l'heure
	html.replace("$xeml_experiment_date$",current_doc->get_startdate().toString("dddd, MMMM MM, yyyy hh:mm:ss AP"));
	html.replace("$xeml_ontology_table$",generate_ontology_table());
	html.replace("$xeml_material_table$",generate_material_table());

	html.replace("$xeml_sample_count$",generate_sample_count());
	html.replace("$xeml_observationpoint_count$",generate_obs_count());

	html.replace("$xeml_variables_table$",generate_variable_table());
	*/

	template_html.replace("$xeml_experimenter_firstname$",current_doc->get_experimentheader()->get_experimenter()->get_firstname());
	template_html.replace("$xeml_experimenter_lastname$",current_doc->get_experimentheader()->get_experimenter()->get_lastname());
	template_html.replace("$xeml_experimenter_email$",current_doc->get_experimentheader()->get_experimenter()->get_email());
	template_html.replace("$xeml_experimenter_description$",current_doc->get_experimentheader()->get_summary());
	template_html.replace("$xeml_experimenter_organisation$",current_doc->get_experimentheader()->get_experimenter()->get_organization());

	template_html.replace("$xeml_experiment_name$",current_doc->get_experiment_name());

	//ajouter format pour affichage plus complet de l'heure
	template_html.replace("$xeml_experiment_date$",current_doc->get_startdate().toString("dddd, MMMM MM, yyyy hh:mm:ss AP"));
	template_html.replace("$xeml_ontology_table$",generate_ontology_table());
	template_html.replace("$xeml_material_table$",generate_material_table());

	template_html.replace("$xeml_sample_count$",generate_sample_count());
	template_html.replace("$xeml_observationpoint_count$",generate_obs_count());

	template_html.replace("$xeml_variables_table$",generate_variable_table());
	//Template.replace("$xeml_allparameter_table$",generate_variable_table());

	//Template.replace("$xeml_observationschedule_table$",generate_observation_schedule_table());

	//std::cerr << "Template :" << html.toStdString() << std::endl;
	QString css;
	css  = "span.red { color:#DE0000; } "
		   "span.blue {color:blue;}"
		   "span.styles { color:#DE0000; font-family: Georgia; text-align: justify; } "
		   "span#bgimage { background-image: url(':/Images/SaveAs.png'); } "
		   "body.tuning { background-color : white;}";
		   //"tr.test {width : 100}"
		   //"th.thtest {width : 100}"
		   //"table.tune {background-color : blue; cellspacing : 50; }";

	// Create a QTextDocument with the defined HTML, CSS and the images
	QTextDocument *doc = new QTextDocument;

	/*
	 * This shows how to bind the images, where the name for QUrl is the same name
	 * which you use in your HTML and CSS. In QPixmap just use the normal syntax of
	 * the Qt resource system.
	 */
	doc->addResource( QTextDocument::ImageResource, QUrl( ":/Images/SaveAs.png" ), QPixmap( ":myImage" ) );
	doc->addResource( QTextDocument::ImageResource, QUrl( ":/Images/SaveAs.png" ), QPixmap( ":bg" ) );

	/*
	 * And now bind the css, which you have defined in the QString css.
	 */
	doc->addResource( QTextDocument::StyleSheetResource, QUrl( "format.css" ), css );
	doc->setHtml( template_html ); // binds the HTML to the QTextDocument

	/*
	 * This QTextDocument can now set to any QTextBrowser.
	 */

	HtmlEdit->setDocument( doc );
	//HtmlEdit->show();








	std::cerr << "entering generate html report ( HtmlReportView)" << std::endl;

	/*
	if (current_doc!=NULL){
		//read the file report_template.html
		QFile html_file(":/XEMLReport.html");
		//current_text->addResource(QTextDocument::toHtml(),":/XEMLReport.html");
		QString Template=load_HTMl_from_file(&html_file);
		//QString::toHtmlEscaped();
		std::cerr << "Template :" << Template.toStdString() << std::endl;
		//HtmlEdit->insertHtml("<b>Hello</b> <i>Qt!</i>" );
		html_text->setHtml(Template);
		//HtmlEdit->setHtml();
		//HtmlEdit->insertHtml(current_text->toPlainText());
		HtmlEdit->setText(current_text->toPlainText());
		//HtmlEdit->insertHtml("Template");

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

	//}
}

QString HtmlReportView::generate_observation_schedule_table()
{
	// create a table with all informations about observation
	// Date, Time, Duration, #individuals
}

QString HtmlReportView::generate_material_table()
{
	//create table with all material used during experiment
	QString ontologyTable="";
	ontologyTable ="<table bgcolor = \"white\" border width = \"1250\" >" //width=\"100%\"  bordercolor=\"#3399FF\" id=\"contenttable\">\r\n
				   "<tr bgcolor = \"orange\">"
				   "<th width = \"150\" height = \"100\">NameSpaceAlias</th>"
				   "<th width = \"800\" height = \"100\">Material</th>"
				   "<th width = \"300\" height = \"100\">TermId</th>"
				   "</tr>";

	for(std::list<StoryNode*>::iterator it =this->current_doc->get_storyboard()->get_storyBoard()->begin();it!=this->current_doc->get_storyboard()->get_storyBoard()->end();++it){
			StoryNode * tmpnode=static_cast<StoryNode*>((*it));
			StoryBase * tmpstory = static_cast<StoryBase*>(tmpnode->get_story());
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it2=tmpstory->get_obsPointCollection()->begin();it2!=tmpstory->get_obsPointCollection()->end();++it2){
				ObservationPoint * tmpobspoint=static_cast<ObservationPoint*>((*it2).first);
				obsPointCount++;
				for (std::vector<std::pair<Observation*,QDateTime> >::iterator it3=tmpobspoint->get_observationscollection()->begin();it3!=tmpobspoint->get_observationscollection()->end();++it3){
					Observation * tmpobs=static_cast<Observation*>((*it3).first);

					sampleCount++;
					for (std::map<Partition*,int>::iterator it4=tmpobs->get_partitionCollection()->begin();it4!=tmpobs->get_partitionCollection()->end();++it4){

						Partition * tmp_part=static_cast<Partition*>((*it4).first);


						for (std::map<BasicTerm*,QString>::iterator it5=tmp_part->get_materialCollection()->begin();it5!=tmp_part->get_materialCollection()->end();++it5){
							BasicTerm * tmp_term= static_cast<BasicTerm*>((*it5).first);
							//VariableTerm * tmp_variable_term=static_cast<VariableTerm*>(tmp_term);
							ontologyTable+="<tr bgcolor = \"cyan\">";
							QString msg = QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_namespacealias());
							ontologyTable+=msg;
							msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_name());
							ontologyTable+=msg;
							msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_termId());
							ontologyTable+=msg;
							ontologyTable+="</tr>";
						}

						//for ()
					}
				}
			}


		//for ()
	}
	ontologyTable+="</table>";


	return ontologyTable;

}

QString HtmlReportView::generate_sample_count()
{
	return QString::number(sampleCount);
}

QString HtmlReportView::generate_obs_count()
{
	return QString::number(obsPointCount);
}

QString HtmlReportView::generate_variable_table()
{
	QString ontologyTable="";
	ontologyTable ="<table bgcolor = \"white\" border width = \"1250\" >" //width=\"100%\"  bordercolor=\"#3399FF\" id=\"contenttable\">\r\n
				   "<tr bgcolor = \"orange\">"
				   "<th width = \"150\" height = \"100\">NameSpaceAlias</th>"
				   "<th width = \"800\" height = \"100\">Name</th>"
				   "<th width = \"300\" height = \"100\">TErmID</th>"

				   "</tr>";
	for(std::list<StoryNode*>::iterator it =this->current_doc->get_storyboard()->get_storyBoard()->begin();it!=this->current_doc->get_storyboard()->get_storyBoard()->end();++it){
		StoryNode * tmpnode=static_cast<StoryNode*>((*it));

		StoryBase * tmpstory = static_cast<StoryBase*>(tmpnode->get_story());
		for(std::vector<std::pair<BasicTerm*,QString> >::iterator it2=tmpstory->get_variablesCollection()->begin();it2!=tmpstory->get_variablesCollection()->end();++it2){
			DynamicTerm * tmp_term=static_cast<DynamicTerm*>((*it2).first);
			ontologyTable+="<tr bgcolor = \"cyan\">";
			QString msg = QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_namespacealias());
			ontologyTable+=msg;
			msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_name());
			ontologyTable+=msg;
			msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_termId());
			ontologyTable+=msg;

			ontologyTable+="</tr>";
		}


	}
	ontologyTable+="</table>";


	return ontologyTable;



}

QString HtmlReportView::generate_ontology_table()
{
	QString ontologyTable="";
	ontologyTable ="<table bgcolor = \"white\" border width = \"1250\" >" //width=\"100%\"  bordercolor=\"#3399FF\" id=\"contenttable\">\r\n
				   "<tr bgcolor = \"orange\">"
				   "<th width = \"150\" height = \"100\">Alias</th>"
				   "<th width = \"800\" height = \"100\">NameSpace</th>"
				   "<th width = \"300\" height = \"100\">Ontology</th>"
				   "</tr>";


	//QString msg = QString ("Loading %1").arg(i);

	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_devHandler()->begin();it!=this->documentResources->get_devHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"cyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";

	}


	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_structHandler()->begin();it!=this->documentResources->get_structHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"cyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_xeoHandler()->begin();it!=this->documentResources->get_xeoHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"cyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_genHandler()->begin();it!=this->documentResources->get_genHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"cyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_posHandler()->begin();it!=this->documentResources->get_posHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"cyan\">";
		QString msg = QString ("<td>%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_EOHandler()->begin();it!=this->documentResources->get_EOHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"cyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_EnvOHandler()->begin();it!=this->documentResources->get_EnvOHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"cyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	ontologyTable+="</table>";


	return ontologyTable;

}

