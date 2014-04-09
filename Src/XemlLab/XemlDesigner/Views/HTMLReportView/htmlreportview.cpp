#include "htmlreportview.h"

HtmlReportView::HtmlReportView(QWidget *parent) :
	QWidget(parent)
{
	HtmlEdit= new QTextBrowser( 0 );
	layout=new QVBoxLayout;
	menubar=new QMenuBar;

	menubar->setWindowTitle("HTML Report");
	obsPointCount=0;
	sampleCount=0;
	layout->addWidget(menubar);
	layout->addWidget(HtmlEdit);


	createActions();
	createMenus();
	this->setMinimumSize(550,700);
	this->setLayout(layout);



}
void HtmlReportView::createMenus(){
	fileMenu = new QMenu("&File", this);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(printAction);
	fileMenu->addAction(printPreviewAction);
	menubar->addMenu(fileMenu);


	//QMainWindow::menuBar()->addMenu(fileMenu);
}
void HtmlReportView::createActions(){

	saveAction = new QAction(QIcon(":/Images/save.png"),tr("&SaveFile"), this);
	saveAction->setShortcut(tr("Ctrl+S"));
	saveAction->setStatusTip(tr("Save file"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

	printAction = new QAction(QIcon(":/Images/print.jpg"),tr("&Print"), this);
	printAction->setShortcut(tr("Ctrl+P"));
	printAction->setStatusTip(tr("Print current file"));
	connect(printAction, SIGNAL(triggered()), this, SLOT(print()));

	printPreviewAction = new QAction(QIcon(":/Images/print_preview.jpg"),tr("& Preview"), this);
	printPreviewAction->setShortcut(tr("Ctrl+Alt+P"));
	printPreviewAction->setStatusTip(tr("Preview before print"));
	connect(printPreviewAction, SIGNAL(triggered()), this, SLOT(filePrintPreview()));
}
void HtmlReportView::print(){

	printer=new QPrinter(QPrinter::HighResolution);
	//printer->setPageSize(QPrinter::A4);
	//printer->setFullPage(true);
	printer->setOrientation(QPrinter::Portrait);
	printer->setPageSize(QPrinter::A3);
	//printer->set
	//printer->setOutputFormat(QPrinter::PdfFormat);
	//printer->setPaperSize(QSizeF(144, 216), QPrinter::Millimeter);
	//printer->setOutputFormat(QPrinter::PdfFormat);
	//printer->setOutputFileName(fileName);
	QPrintDialog *dialog = new QPrintDialog(printer,this);
	dialog->setWindowTitle(tr("Impression du document"));
	if (dialog->exec() != QDialog::Accepted) return;
	doc->print(printer);
}
void HtmlReportView::filePrintPreview()
{
#ifndef QT_NO_PRINTER
	printer=new QPrinter(QPrinter::HighResolution);
	QPrintPreviewDialog preview(printer, this);

	connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(printPreview(QPrinter *)));
	preview.exec();
#endif
}

void HtmlReportView::printPreview(QPrinter *printer)
{
#ifdef QT_NO_PRINTER
	Q_UNUSED(printer);
#else
	doc->print(printer);
#endif
}

void HtmlReportView::save(){

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
		finaltext+=" ";
		if (text=="</html>"){
			return finaltext;
		}
	}

	return finaltext;
}
void HtmlReportView::generate_report(){


	std::cerr << "entering generate html report ( HtmlReportView)" << std::endl;

	// Your HTML code
	QString template_html;
	if (current_doc!=NULL){
		//read the file report_template.html
		QFile html_file(":/XEMLReport.html");
		template_html=load_HTMl_from_file(&html_file);
	}
	QString html;
	html = "<html lang='en' xml:lang='en' xmlns='http://www.w3.org/1999/xhtml'><head>"
		   "<link rel='stylesheet' type='text/css' href='format.css'>"
		   "</head><body >" //class = tuning
		   //"Your HTML code with tags, which have classes or ids. For example "
		   //"<span class='red'>this text is colored red</span>.<br/>"
		   //"And you can also display images: <img src=':/Images/SaveAs.png'><br/>"
		   //"Combine css and images: <span id='bgimage'>foo bar</span><br/>"


		   "<span class= styles>"
		   "$xeml_experiment_name$ - summary report <br />"
		   "<hr>"
		   "<span class= 'blues'>Experimenter : </span><br />"
		   "FirstName : $xeml_experimenter_firstname$ <br />"
		   "LastName : $xeml_experimenter_lastname$ <br />"
		   "Email : $xeml_experimenter_email$ <br />"
		   "Organization : $xeml_experimenter_organisation$ <br />"
		   "<hr>"
		   "<span class= 'blues'>Experiment : </span><br />"
		   "$xeml_experiment_name$ are started at $xeml_experiment_date$ and finished at $xeml_experiment_enddate$ <br />"
		   "<hr>"
		   "<span class= 'blues'>Description : </span><br />"
		   "$xeml_experiment_description$<br />"
		   "<hr>"
		   "Within this experiment, $xeml_observationpoint_count$ observation point(s) "
		   "and $xeml_sample_count$ samples collected.<br /> "
		   "<hr>"
		   "<span class= 'blues'>For this samples these material are observed</span> "
		   "<hr width = \"100%\">"
		   "$xeml_material_table$.<br /> "
		   "<hr>"
		   "<span class= 'blues'>The following ontologies are referenced by this document:</span> <br/>"
		   "$xeml_ontology_table$ <br/>"
		   "<hr>"
		   "<span class= 'blues'>For the definition of the environmental conditions the following parameters are used:</span><br />"
		   "$xeml_variables_table$<br />"
		   "<hr>"
		   "<span class= 'blues'>From these parameter the following are variables:</span><br />"
		   "$xeml_dynamic_variables_table$<br />"
		   "<span class= 'blues'>ObservationPoint schedule :</span><br />"
		   "$xeml_observationschedule_table$</span><br />"
		   "</body></html>";

	// Your CSS code


	html.replace("$xeml_experimenter_firstname$",current_doc->get_experimentheader()->get_experimenter()->get_firstname());
	html.replace("$xeml_experimenter_lastname$",current_doc->get_experimentheader()->get_experimenter()->get_lastname());
	html.replace("$xeml_experimenter_email$",current_doc->get_experimentheader()->get_experimenter()->get_email());
	html.replace("$xeml_experimenter_description$",current_doc->get_experimentheader()->get_summary());
	html.replace("$xeml_experimenter_organisation$",current_doc->get_experimentheader()->get_experimenter()->get_organization());

	html.replace("$xeml_experiment_name$",current_doc->get_experiment_name());


	html.replace("$xeml_experiment_description$",static_cast<XemlDocument*>(current_doc)->get_experimentheader()->get_summary());
	//ajouter format pour affichage plus complet de l'heure
	html.replace("$xeml_experiment_date$",current_doc->get_startdate().toString("dddd, MMMM dd, yyyy hh:mm:ss AP"));
	html.replace("$xeml_experiment_enddate$",current_doc->get_enddate().toString("dddd, MMMM dd, yyyy hh:mm:ss AP"));

	html.replace("$xeml_ontology_table$",generate_ontology_table());
	html.replace("$xeml_material_table$",generate_material_table());

	html.replace("$xeml_sample_count$",generate_sample_count());
	html.replace("$xeml_observationpoint_count$",generate_obs_count());

	html.replace("$xeml_variables_table$",generate_variable_table());
	html.replace("$xeml_dynamic_variables_table$",generate_dynamic_variable_table());

	html.replace("$xeml_observationschedule_table$",generate_observation_schedule_table());


/*
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
*/
	//std::cerr << "Template :" << html.toStdString() << std::endl;
	QString css;
	QFile * style = new QFile("://StyleSheet/html.css");

		if(!style->open(QIODevice::ReadOnly))
		{
			QMessageBox::warning(this,"Erreur de chargement du style", "La feuille de style par défaut n'a pas pu être chargée correctement, veuillez relancer le logiciel afin que celle-ci prennent effet.");
		}
		else
		{
			QString htmlcss(style->readAll());
			css=htmlcss;


		}
		/*
	css  = "span.red { color:#DE0000; } "
		   "span.blues {color:blue;}"
		   "span.styles { color:black; font-family: Times New Roman; text-align: justify; } "
		   "span#bgimage { background-image: url(':/Images/SaveAs.png'); } "
		   "body.tuning {background-color : white;}";*/
		   //"tr.test {width : 100}"
		   //"th.thtest {width : 100}"
		   //"table.tune {background-color : blue; cellspacing : 50; }";

	// Create a QTextDocument with the defined HTML, CSS and the images
	doc = new QTextDocument;
	QFont font;
	font.setFamily("Arial");
	font.setPointSize(10);
	doc->setDefaultFont(font);

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
	// binds the HTML to the QTextDocument
	doc->setHtml(html ); //replace by template_html if you want to use the default html file.


	/*
	 * This QTextDocument can now set to any QTextBrowser.
	 */

	HtmlEdit->setDocument( doc );
	//HtmlEdit->show();



}

QString HtmlReportView::generate_observation_schedule_table()
{
	// create a table with all informations about observation
	// Date, Time, Duration, #individuals
	QString ontologyTable="";
	ontologyTable ="<table bgcolor = \"white\"  >" //border
			//width=\"100%\"  bordercolor=\"#3399FF\" id=\"contenttable\">\r\n
				   "<tr bgcolor = \"Bisque\">"
				   "<th  height = \"100\">Date</th>"
				   "<th  height = \"100\">Time</th>"
				   "<th  height = \"100\">Duration</th>"
				   "<th  height = \"100\">Individuals #</th>"
				   "</tr>";
	for(std::list<StoryNode*>::iterator it =this->current_doc->get_storyboard()->get_storyBoard()->begin();it!=this->current_doc->get_storyboard()->get_storyBoard()->end();++it){
			StoryNode * tmpnode=static_cast<StoryNode*>((*it));
			StoryBase * tmpstory = static_cast<StoryBase*>(tmpnode->get_story());
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it2=tmpstory->get_obsPointCollection()->begin();it2!=tmpstory->get_obsPointCollection()->end();++it2){
				ObservationPoint * tmpobspoint=static_cast<ObservationPoint*>((*it2).first);
				//for (std::vector<std::pair<Observation*,QDateTime> >::iterator it3=tmpobspoint->get_observationscollection()->begin();it3!=tmpobspoint->get_observationscollection()->end();++it3){
					//Observation * tmpobs=static_cast<Observation*>((*it3).first);
					ontologyTable+="<tr bgcolor = \"LightCyan\">";
					QString msg = QString ("<td height = \"100\">%1</td>").arg(tmpobspoint->get_timepoint().toString("dddd, MMMM dd, yyyy"));
					ontologyTable+=msg;
					msg=QString ("<td height = \"100\">%1</td>").arg(tmpobspoint->get_timepoint().toString("hh:mm:ss"));
					ontologyTable+=msg;
					if(tmpobspoint->count_observations()!=0){
						qint64 duration_in_seconds= translate_DD_HH_MM_SS_in_Msecs(static_cast<Observation*>(static_cast<std::pair<Observation*,QDateTime> >(tmpobspoint->get_observationscollection()->at(0)).first)->get_duration().toString("hh:mm:ss"));
						msg=QString ("<td height = \"100\">%1</td>").arg(translate_second_in_DD_HH_MM_SS(0));
						ontologyTable+=msg;
					}
					else{
						qint64 duration_in_seconds= translate_DD_HH_MM_SS_in_Msecs(static_cast<Observation*>(static_cast<std::pair<Observation*,QDateTime> >(tmpobspoint->get_observationscollection()->at(0)).first)->get_duration().toString("hh:mm:ss"));
						msg=QString ("<td height = \"100\">%1</td>").arg(translate_second_in_DD_HH_MM_SS(duration_in_seconds*tmpobspoint->count_observations()));
						ontologyTable+=msg;
					}
					msg=QString ("<td height = \"100\">%1</td>").arg(tmpobspoint->count_observations());
					ontologyTable+=msg;
					ontologyTable+="</tr>";

			}
	}
	ontologyTable+="</table>";

	return ontologyTable;

}

QString HtmlReportView::generate_material_table()
{
	//create table with all material used during experiment
	QString ontologyTable="";
	ontologyTable ="<table bgcolor = \"white\"   >" //border
			//width=\"100%\"  bordercolor=\"#3399FF\" id=\"contenttable\">\r\n
				   "<tr bgcolor = \"Bisque\">"
				   "<th  height = \"100\">NameSpaceAlias</th>"
				   "<th  height = \"100\">Material</th>"
				   "<th  height = \"100\">TermId</th>"
				   "</tr>";

	QStringList * tmp_list=new QStringList();

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
							if(!tmp_list->contains(tmp_term->get_termId())){
								tmp_list->append(tmp_term->get_termId());
								ontologyTable+="<tr bgcolor = \"LightCyan\">";
								QString msg = QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_namespacealias());
								ontologyTable+=msg;
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_name());
								ontologyTable+=msg;
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_termId());
								ontologyTable+=msg;
								ontologyTable+="</tr>";
							}
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

QString HtmlReportView::generate_dynamic_variable_table(){
	QString ontologyTable="";
	ontologyTable ="<table bgcolor = \"white\"  >" //border
			//width=\"100%\"  bordercolor=\"#3399FF\" id=\"contenttable\">\r\n
				   "<tr bgcolor = \"Bisque\">"
				   "<th  height = \"100\">NameSpaceAlias</th>"
				   "<th  height = \"100\">Name</th>"
				   "<th  height = \"100\">TermId</th>"
				   "<th  height = \"100\">Changed at:</th>"
				   "<th  height = \"100\">Value:</th>"
				   "<th  height = \"100\">Unit:</th>"
				   "</tr>";
	for(std::list<StoryNode*>::iterator it =this->current_doc->get_storyboard()->get_storyBoard()->begin();it!=this->current_doc->get_storyboard()->get_storyBoard()->end();++it){
		StoryNode * tmpnode=static_cast<StoryNode*>((*it));

		StoryBase * tmpstory = static_cast<StoryBase*>(tmpnode->get_story());
		for(std::vector<std::pair<BasicTerm*,QString> >::iterator it2=tmpstory->get_variablesCollection()->begin();it2!=tmpstory->get_variablesCollection()->end();++it2){

			DynamicTerm * tmp_term=static_cast<DynamicTerm*>((*it2).first);


			if (!tmp_term->get_dynamicvaluecollection()->empty()){

				std::cerr << "dynamic_collection is not empty size :" << tmp_term->get_dynamicvaluecollection()->size() << std::endl;
				for (int i=0;i<tmp_term->get_dynamicvaluecollection()->size();i++){

					DynamicValue * tmp_dvalue=static_cast<DynamicValue*>(tmp_term->get_dynamicvaluecollection()->at(i).first);
					std::cerr << "dynamic_value :" << tmp_dvalue->get_context().toStdString()<< std::endl;

					if (tmp_dvalue->get_context()=="Quantity"){

						if (tmp_dvalue->get_unit()!=""){

							int cycle_size=0;
							int cycle_division=0;
							if (tmp_dvalue->get_is_cycle()){

								Cycle * c =static_cast<Cycle*>(tmp_term->get_dynamicvaluecollection()->at(i).first);
								cycle_size=c->get_cycleValues()->size();
								cycle_division=24/cycle_size;

								ontologyTable+="<tr bgcolor = \"LightCyan\">";
								QString msg = QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_namespacealias());
								ontologyTable+=msg;
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_name());
								ontologyTable+=msg;
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_termId());
								ontologyTable+=msg;
								if (tmp_dvalue->get_timepoint()==current_doc->get_startdate()){
									msg=QString ("<td height = \"100\">%1</td>").arg("experiment startpoint");
									ontologyTable+=msg;
								}
								else{
									msg=QString ("<td height = \"100\">%1</td>").arg(tmp_dvalue->get_timepoint().toString("dd/MM/yyyy hh:mm:ss"));
									ontologyTable+=msg;
								}
								QString tmp="";
								for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it3=c->get_cycleValues()->begin();it3!=c->get_cycleValues()->end();++it3){
									tmp.append(static_cast<DynamicValue*>((*it3).first)->get_value());
									tmp.append("/");
								}
								tmp.append(" - ");
								for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it3=c->get_cycleValues()->begin();it3!=c->get_cycleValues()->end();++it3){
									tmp.append(static_cast<DynamicValue*>((*it3).first)->get_timepoint().toString("hh:mm:ss").split(":").at(0));
									tmp.append("/");
								}


								//tmp.append(" - ");
								//tmp.append(QString::number(cycle_division));
								tmp.append(" H cycle");

								msg=QString ("<td height = \"100\">%1</td>").arg(tmp);
								ontologyTable+=msg;
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_dvalue->get_unit());
								ontologyTable+=msg;

								ontologyTable+="</tr>";
							}
							else{
								ontologyTable+="<tr bgcolor = \"LightCyan\">";
								QString msg = QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_namespacealias());
								ontologyTable+=msg;
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_name());
								ontologyTable+=msg;
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_termId());
								ontologyTable+=msg;
								if (tmp_dvalue->get_timepoint()==current_doc->get_startdate()){
									msg=QString ("<td height = \"100\">%1</td>").arg("experiment startpoint");
									ontologyTable+=msg;
								}
								else{
									msg=QString ("<td height = \"100\">%1</td>").arg(tmp_dvalue->get_timepoint().toString("dd/MM/yyyy hh:mm:ss"));
									ontologyTable+=msg;
								}
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_dvalue->get_value());
								ontologyTable+=msg;
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_dvalue->get_unit());
								ontologyTable+=msg;

								ontologyTable+="</tr>";
							}
						}

					}
					if (tmp_dvalue->get_context()=="Context"){
						if (tmp_dvalue->get_is_cycle()){

							Cycle * c =static_cast<Cycle*>(tmp_term->get_dynamicvaluecollection()->at(i).first);
							//cycle_size=c->get_cycleValues()->size();
							//cycle_division=24/cycle_size;

							ontologyTable+="<tr bgcolor = \"LightCyan\">";
							QString msg = QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_namespacealias());
							ontologyTable+=msg;
							msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_name());
							ontologyTable+=msg;
							msg=QString ("<td height = \"100\">%1</td>").arg(tmp_term->get_termId());
							ontologyTable+=msg;
							if (tmp_dvalue->get_timepoint()==current_doc->get_startdate()){
								msg=QString ("<td height = \"100\">%1</td>").arg("experiment startpoint");
								ontologyTable+=msg;
							}
							else{
								msg=QString ("<td height = \"100\">%1</td>").arg(tmp_dvalue->get_timepoint().toString("dd/MM/yyyy hh:mm:ss"));
								ontologyTable+=msg;
							}
							QString tmp="";
							for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it3=c->get_cycleValues()->begin();it3!=c->get_cycleValues()->end();++it3){
								tmp.append(static_cast<DynamicValue*>((*it3).first)->get_value());
								tmp.append("/");
							}
							tmp.append(" - ");
							for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it3=c->get_cycleValues()->begin();it3!=c->get_cycleValues()->end();++it3){
								tmp.append(static_cast<DynamicValue*>((*it3).first)->get_timepoint().toString("hh:mm:ss").split(":").at(0));
								tmp.append("/");
							}


							//tmp.append(" - ");
							//tmp.append(QString::number(cycle_division));
							tmp.append(" H cycle");

							msg=QString ("<td height = \"100\">%1</td>").arg(tmp);
							ontologyTable+=msg;
							msg=QString ("<td height = \"100\">%1</td>").arg(tmp_dvalue->get_unit());
							ontologyTable+=msg;

							ontologyTable+="</tr>";
						}
					}

				}
			}

		}
	}
	ontologyTable+="</table>";


	return ontologyTable;
}

QString HtmlReportView::generate_variable_table()
{
	QString ontologyTable="";
	ontologyTable ="<table bgcolor = \"white\"  >" //border
			//width=\"100%\"  bordercolor=\"#3399FF\" id=\"contenttable\">\r\n
				   "<tr bgcolor = \"Bisque\" height = \"200\">"
				   "<th  height = \"200\">NameSpaceAlias</th>"
				   "<th  height = \"200\">Name</th>"
				   "<th  height = \"200\">TermId</th>"

				   "</tr>";
	QStringList * tmp_list=new QStringList();
	for(std::list<StoryNode*>::iterator it =this->current_doc->get_storyboard()->get_storyBoard()->begin();it!=this->current_doc->get_storyboard()->get_storyBoard()->end();++it){
		StoryNode * tmpnode=static_cast<StoryNode*>((*it));

		StoryBase * tmpstory = static_cast<StoryBase*>(tmpnode->get_story());
		for(std::vector<std::pair<BasicTerm*,QString> >::iterator it2=tmpstory->get_variablesCollection()->begin();it2!=tmpstory->get_variablesCollection()->end();++it2){
			DynamicTerm * tmp_term=static_cast<DynamicTerm*>((*it2).first);
			if(!tmp_list->contains(tmp_term->get_termId())){
				tmp_list->append(tmp_term->get_termId());
				ontologyTable+="<tr bgcolor = \"LightCyan\">";
				QString msg = QString ("<td height = \"200\">%1</td>").arg(tmp_term->get_namespacealias());
				ontologyTable+=msg;
				msg=QString ("<td height = \"200\">%1</td>").arg(tmp_term->get_name());
				ontologyTable+=msg;
				msg=QString ("<td height = \"200\">%1</td>").arg(tmp_term->get_termId());
				ontologyTable+=msg;

				ontologyTable+="</tr>";
			}
		}


	}
	ontologyTable+="</table>";


	return ontologyTable;



}

QString HtmlReportView::generate_ontology_table()
{
	QString ontologyTable="";
	ontologyTable ="<table bgcolor = \"white\" >" //border
			//width=\"100%\"  bordercolor=\"#3399FF\" id=\"contenttable\">\r\n
				   "<tr bgcolor = \"Bisque\">"
				   "<th height = \"100\">Alias</th>"
				   "<th height = \"100\">NameSpace</th>"
				   "<th height = \"100\">Ontology</th>"
				   "</tr>";


	//QString msg = QString ("Loading %1").arg(i);

	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_devHandler()->begin();it!=this->documentResources->get_devHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"LightCyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";

	}


	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_structHandler()->begin();it!=this->documentResources->get_structHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"LightCyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_xeoHandler()->begin();it!=this->documentResources->get_xeoHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"LightCyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_genHandler()->begin();it!=this->documentResources->get_genHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"LightCyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_posHandler()->begin();it!=this->documentResources->get_posHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"LightCyan\">";
		QString msg = QString ("<td>%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_EOHandler()->begin();it!=this->documentResources->get_EOHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"LightCyan\">";
		QString msg = QString ("<td height = \"100\">%1</td>").arg((*it).first);
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_location());
		ontologyTable+=msg;
		msg=QString ("<td height = \"100\">%1</td>").arg((*it).second->get_uri());
		ontologyTable+=msg;
		ontologyTable+="</tr>";


	}
	for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_EnvOHandler()->begin();it!=this->documentResources->get_EnvOHandler()->end();++it){
		ontologyTable+="<tr bgcolor = \"LightCyan\">";
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

