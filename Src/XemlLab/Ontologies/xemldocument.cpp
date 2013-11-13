#include "xemldocument.h"

namespace Xeml {

	namespace Document{

		//region constructors
							  XemlDocument::XemlDocument()
		{

			std::cerr << "new xeml document" << std::endl;
			this->experimentheader=new ExperimentHeader();
			this->documentResources= new DocumentResources();
			this->storyBoard = new StoryBoard();
			this->uri="http://www.mpimp-golm.mpg.de/2009/XEML/XemlDocument";
			this->xmlNameSpace= "http://www.mpimp-golm.mpg.de/2009/XEML";
			this->XemlVersion= "1.1.0";
			NewId();
			this->experiment_name= "";//New experiment
			//this->storyBoard->set_obs_time(QDateTime::fromString("28.00:00:00","dd.hh:mm:ss"));//new TimeSpan(100,0,0,0));
			this->asTemplate=false;
			this->observationPointsCounter=0;
			this->partition_counter=0;
			//this->startDate=time(NULL);
			//this->startDate)=new QDateTime();



		}
		XemlDocument::XemlDocument(QString filename){

			this->Load(filename,false);
		}
		XemlDocument::~XemlDocument(void){

		}

		void                  XemlDocument::Load(QString xemlCode,bool _asTemplate){
			QFile Xeml_doc(xemlCode.toStdString().c_str());
			this->asTemplate=_asTemplate;
			QDomDocument * Xeml_dom = new QDomDocument("template_xeml");

			if(!Xeml_doc.open(QIODevice::ReadOnly))
			{
				std::cerr << "Erreur à l'ouverture du document XML" << std::endl;
			}
			if (!Xeml_dom->setContent(&Xeml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
			{
				Xeml_doc.close();
				std::cerr << "Erreur à l'association du document DOM au fichier XML" << std::endl;
			}
			Init(Xeml_dom);
			std::cerr << "end Init" << std::endl;
			//std::cerr << this->documentResources->get_xeoHandler()->size() << std::endl;
		}
		void                  XemlDocument::Save(QString path){
			this->generate_xml(path);
		}

		//region write xeml

		int                   XemlDocument::generate_xml(const QString &fileName){
			const int Indent = 4;
			//string name=":/"+filename;
			if (QFile::exists(fileName)) {

				//std::cerr << "file already exist" << std::endl;
				QFile::remove(fileName);
				this->doc.clear();

			}
			this->doc.clear();
			QFile file(fileName);
			if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
				return 0;


			QDomElement root = this->doc.createElement("xeml:XEMLDocument");
			root.setAttribute("xmlns:xeml",this->xmlNameSpace);
			root.setAttribute("XemlVersion","1.1.0");
			this->doc.appendChild(root);
			write_resources();
			QDomElement experiment = this->doc.createElement("xeml:Experiment");
			root.appendChild(experiment);
			//std::cerr << "-------------1"<< put_date_in_string(this->startDate) << std::endl;
			//string mot=put_date_in_string(this->startDate);

			//QString date;
			//QString date2=date.fromStdString(mot);
			//std:cerr << date2.toStdString() << std::endl;
			experiment.setAttribute("Id",this->Id.toString());
			experiment.setAttribute("Name",this->experiment_name);
			//std::cerr << "observation time" << this->storyBoard->get_obs_time().toString("dd.hh:mm:ss").toStdString() << std::endl;
			//QString obsTime=translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->startDate,this->endDate));
			experiment.setAttribute("ObservationTime",translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->startDate,this->endDate)));
			experiment.setAttribute("StartDate",this->startDate.toString("yyyy-MM-ddThh:mm:ss"));
			write_header();
			for(std::list<StoryNode*>::iterator it = this->storyBoard->get_storyBoard()->begin();it!=this->get_storyboard()->get_storyBoard()->end();++it){
				if((*it)->get_parent()==NULL){
					//std::cerr << "root node name : " << (*it)->get_story()->get_label().toStdString() << std::endl;
					write_stories((*it),(*it)->get_parent());

				}
			}
			QTextStream out(&file);
			out.setCodec("UTF-8");
			QDomNode xmlNode = this->doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
			this->doc.insertBefore(xmlNode, this->doc.firstChild());
			this->doc.save(out, Indent);
			return 0;
		}
		QString                   XemlDocument::generate_string_xml(){
			const int Indent = 4;
			//string name=":/"+filename;
			//if (QFile::exists(fileName)) {

			//	std::cerr << "file already exist" << std::endl;
			//	QFile::remove(fileName);
			//	this->doc.clear();

			//}
			this->doc.clear();
			//QFile file(fileName);
			//if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
			//	return 0;


			QDomElement root = this->doc.createElement("xeml:XEMLDocument");
			root.setAttribute("xmlns:xeml",this->xmlNameSpace);
			root.setAttribute("XemlVersion","1.1.0");
			this->doc.appendChild(root);
			write_resources();
			QDomElement experiment = this->doc.createElement("xeml:Experiment");
			root.appendChild(experiment);
			//std::cerr << "-------------1"<< put_date_in_string(this->startDate) << std::endl;
			//string mot=put_date_in_string(this->startDate);

			//QString date;
			//QString date2=date.fromStdString(mot);
			//std:cerr << date2.toStdString() << std::endl;
			experiment.setAttribute("Id",this->Id.toString());
			experiment.setAttribute("Name",this->experiment_name);
			//std::cerr << "observation time" << this->storyBoard->get_obs_time().toString("dd.hh:mm:ss").toStdString() << std::endl;
			experiment.setAttribute("ObservationTime",translate_second_in_DD_HH_MM_SS(get_seconds_from_date(this->startDate,this->endDate)));

			//experiment.setAttribute("ObservationTime",this->storyBoard->get_obs_time().toString("dd.hh:mm:ss"));
			experiment.setAttribute("StartDate",this->startDate.toString("yyyy-MM-ddThh:mm:ss"));
			write_header();
			for(std::list<StoryNode*>::iterator it = this->storyBoard->get_storyBoard()->begin();it!=this->get_storyboard()->get_storyBoard()->end();++it){
				if((*it)->get_parent()==NULL){
					//std::cerr << "root node name : " << (*it)->get_story()->get_label().toStdString() << std::endl;
					write_stories((*it),(*it)->get_parent());

				}
			}
			QString xemlCode;
			QTextStream out(&xemlCode);
			out.setCodec("UTF-8");
			QDomNode xmlNode = this->doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
			this->doc.insertBefore(xmlNode, this->doc.firstChild());
			this->doc.save(out, Indent);
			return xemlCode;
		}
		void                  XemlDocument::write_header(){

			QDomElement experimentHeader = this->doc.createElement("xeml:Header");


			if(!this->experimentheader->get_experimenter()->is_empty()){
				QDomElement experimenter = this->doc.createElement("xeml:Experimenter");
				experimenter.setAttribute("Organisation",this->experimentheader->get_experimenter()->get_organization());
				experimenter.setAttribute("Email",this->experimentheader->get_experimenter()->get_email());
				experimenter.setAttribute("LastName",this->experimentheader->get_experimenter()->get_lastname());
				experimenter.setAttribute("FirstName",this->experimentheader->get_experimenter()->get_firstname());
				experimentHeader.appendChild(experimenter);
			}

			if (!this->experimentheader->get_summary().isEmpty()){
				QDomElement description = this->doc.createElement("xeml:Description");
				QDomText descriptionText = this->doc.createTextNode(this->experimentheader->get_summary());
				description.appendChild(descriptionText);
				experimentHeader.appendChild(description);
			}

			if(!this->experimentheader->get_keywords()->empty()){
				std::list<Keyword*>::iterator iter;
				for(iter=this->experimentheader->get_keywords()->begin();iter!=this->experimentheader->get_keywords()->end();iter++){
					QDomElement keyword =this->doc.createElement("xeml:Keyword");
					QDomText keywordText = this->doc.createTextNode((*iter)->get_value());
					keyword.appendChild(keywordText);
					experimentHeader.appendChild(keyword);
				}
			}
			this->doc.firstChildElement("xeml:XEMLDocument").firstChildElement("xeml:Experiment").appendChild(experimentHeader);

		}
		void                  XemlDocument::write_resources()
		{
			QDomElement resources = this->doc.createElement("xeml:Resources");
			for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_devHandler()->begin();it!=this->documentResources->get_devHandler()->end();++it){
				QDomElement environmentalOntology=this->doc.createElement("xeml:DevelopmentalOntology");
				resources.appendChild(environmentalOntology);
				environmentalOntology.setAttribute("NS",(*it).first);
				environmentalOntology.setAttribute("InstanceLocation",(*it).second->get_location());
				environmentalOntology.setAttribute("HandlerUri",(*it).second->get_uri());


			}
			for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_structHandler()->begin();it!=this->documentResources->get_structHandler()->end();++it){
				QDomElement environmentalOntology=this->doc.createElement("xeml:OrganismStructureOntology");
				resources.appendChild(environmentalOntology);
				environmentalOntology.setAttribute("NS",(*it).first);
				environmentalOntology.setAttribute("InstanceLocation",(*it).second->get_location());
				environmentalOntology.setAttribute("HandlerUri",(*it).second->get_uri());


			}
			for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_xeoHandler()->begin();it!=this->documentResources->get_xeoHandler()->end();++it){
				QDomElement environmentalOntology=this->doc.createElement("xeml:EnvironmentalOntology");
				resources.appendChild(environmentalOntology);
				environmentalOntology.setAttribute("NS",(*it).first);
				environmentalOntology.setAttribute("InstanceLocation",(*it).second->get_location());
				environmentalOntology.setAttribute("HandlerUri",(*it).second->get_uri());


			}
			for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_genHandler()->begin();it!=this->documentResources->get_genHandler()->end();++it){
				QDomElement environmentalOntology=this->doc.createElement("xeml:GenotypeOntology");
				resources.appendChild(environmentalOntology);
				environmentalOntology.setAttribute("NS",(*it).first);
				environmentalOntology.setAttribute("InstanceLocation",(*it).second->get_location());
				environmentalOntology.setAttribute("HandlerUri",(*it).second->get_uri());


			}
			for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_posHandler()->begin();it!=this->documentResources->get_posHandler()->end();++it){
				QDomElement environmentalOntology=this->doc.createElement("xeml:PositioningOntology");
				resources.appendChild(environmentalOntology);
				environmentalOntology.setAttribute("NS",(*it).first);
				environmentalOntology.setAttribute("InstanceLocation",(*it).second->get_location());
				environmentalOntology.setAttribute("HandlerUri",(*it).second->get_uri());


			}
			for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_EOHandler()->begin();it!=this->documentResources->get_EOHandler()->end();++it){
				QDomElement environmentalOntology=this->doc.createElement("xeml:EnvironmentalOntology");
				resources.appendChild(environmentalOntology);
				environmentalOntology.setAttribute("NS",(*it).first);
				environmentalOntology.setAttribute("InstanceLocation",(*it).second->get_location());
				environmentalOntology.setAttribute("HandlerUri",(*it).second->get_uri());


			}
			for(std::map<QString,OntologyHandlerResources*>::iterator it= this->documentResources->get_EnvOHandler()->begin();it!=this->documentResources->get_EnvOHandler()->end();++it){
				QDomElement environmentalOntology=this->doc.createElement("xeml:EnvironmentalOntology");
				resources.appendChild(environmentalOntology);
				environmentalOntology.setAttribute("NS",(*it).first);
				environmentalOntology.setAttribute("InstanceLocation",(*it).second->get_location());
				environmentalOntology.setAttribute("HandlerUri",(*it).second->get_uri());


			}
			this->doc.firstChildElement("xeml:XEMLDocument").appendChild(resources);
		}
		void                  XemlDocument::write_stories(StoryNode * _node,StoryNode *_parent){
			std::cerr << "entering write stories (xemldocument)" << std::endl;
			if(_parent==NULL){
				QDomElement story=this->doc.createElement("xeml:Story");
				story.setAttribute("Label",_node->get_story()->get_label());
				this->doc.firstChildElement("xeml:XEMLDocument").firstChildElement("xeml:Experiment").appendChild(story);
				write_annotation(&story,_node->get_story());
				write_individuals(&story,static_cast<Story*>(_node->get_story()));
				write_paramater(&story,_node);
				write_observationPoint(&story,_node);
				write_event(&story,_node);
				QDomElement storysplit;
				if((_node->get_childs()!=NULL) && (_node->get_childs()->size()!=0)){
					std::cerr << "childs exist : " << _node->get_childs()->size() << std::endl;
					for(std::list<StoryNode*>::iterator it = _node->get_childs()->begin();it!= _node->get_childs()->end();++it){
						std::cerr << "childs" << std::endl;
						storysplit=this->doc.createElement("xeml:StorySplit");
						storysplit.setAttribute("Label",(*it)->get_story()->get_label());
						qint64 milliseconds_ellapsed=get_seconds_from_date(this->startDate,static_cast<StorySplit*>((*it)->get_story())->get_timepoint());
						storysplit.setAttribute("TimePoint",translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed));

						//storysplit.setAttribute("TimePoint",static_cast<StorySplit*>((*it)->get_story())->get_timepoint().toString("dd.hh:mm:ss"));
						write_annotation(&storysplit,(*it)->get_story());
						write_paramater(&storysplit,(*it));
						write_observationPoint(&storysplit,(*it));
						write_event(&storysplit,(*it));
						story.appendChild(storysplit);
						if(!(*it)->get_childs()->empty()){
							write_substories(&storysplit,(*it));
						}
					}
				}
				else{
					//std::cerr << "lone parent no childs" << std::endl;
				}
			}
		}
		void                  XemlDocument::write_substories(QDomElement * _elem,StoryNode * _node){
			for(std::list<StoryNode*>::iterator it = _node->get_childs()->begin();it!= _node->get_childs()->end();++it){
				QDomElement storysplit=this->doc.createElement("xeml:StorySplit");
				storysplit.setAttribute("Label",(*it)->get_story()->get_label());
				qint64 milliseconds_ellapsed=get_seconds_from_date(this->startDate,static_cast<StorySplit*>((*it)->get_story())->get_timepoint());
				storysplit.setAttribute("TimePoint",translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed));
				//storysplit.setAttribute("TimePoint",static_cast<StorySplit*>((*it)->get_story())->get_timepoint().toString("dd.hh:mm:ss"));
				write_annotation(&storysplit,(*it)->get_story());
				write_paramater(&storysplit,(*it));
				write_observationPoint(&storysplit,(*it));
				write_event(&storysplit,(*it));
				_elem->appendChild(storysplit);
				if((*it)->get_childs()!=NULL){
					write_substories(&storysplit,(*it));
				}
			}

		}
		void                  XemlDocument::write_annotation(QDomElement * _elem,XemlAnnotableObject * _xo){
			for(std::map<TaggedAnnotation*,QString>::iterator it= _xo->get_taggedannotation()->begin();it!=_xo->get_taggedannotation()->end();++it){
				QDomElement tagAnnot=this->doc.createElement("xeml:Annotation");
				tagAnnot.setAttribute("Tag",(*it).first->getTag());
				QDomText t = doc.createTextNode((*it).first->getAnnotation());
				tagAnnot.appendChild(t);
				_elem->appendChild(tagAnnot);
			}
		}
		void                  XemlDocument::write_individuals(QDomElement * _elem,Story* _story){
			for(std::map<IndividualsPool*,QString>::iterator it=_story->get_individualspoolcollection()->begin();it!=_story->get_individualspoolcollection()->end();++it){
				QDomElement indpool=this->doc.createElement("xeml:IndividualsPool");
				indpool.setAttribute("NS",(*it).first->get_ns());
				indpool.setAttribute("GermPlasm",(*it).first->get_germplasm());
				write_annotation(&indpool,(*it).first);
				_elem->appendChild(indpool);
				for(std::map<Individual*,int>::iterator it2=(*it).first->get_individualscollection()->begin();it2!=(*it).first->get_individualscollection()->end();++it2){
					QDomElement ind=this->doc.createElement("xeml:Individual");
					ind.setAttribute("Id",QString::number((*it2).second));
					indpool.appendChild(ind);
				}
			}
		}
		void                  XemlDocument::write_paramater(QDomElement * _elem,StoryNode * _node){
			std::cerr << "entering write parameters " << std::endl;
			DynamicTerm * _term;
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=_node->get_story()->get_variablesCollection()->begin();it!=_node->get_story()->get_variablesCollection()->end();++it){

				_term=static_cast<DynamicTerm*>((*it).first);
				QDomElement var=this->doc.createElement("xeml:Variable");
				var.setAttribute("NS",_term->get_namespacealias());
				var.setAttribute("TermId",_term->get_termId());
				var.setAttribute("Name",_term->get_name());
				write_annotation(&var,_term);

				QDomElement Vs=this->doc.createElement("xeml:ValueSet");
				QDateTime current_datetime;
				QDateTime previous_datetime;
				for(std::vector<pair<DynamicValueBase*,QDateTime> >::iterator it2=_term->get_dynamicvaluecollection()->begin();it2!=_term->get_dynamicvaluecollection()->end();++it2){

					std::cerr << "datetime in write param : " << static_cast<QDateTime>((*it2).second).toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;
					if (it2==_term->get_dynamicvaluecollection()->begin()){
						current_datetime=(*it2).second;
					}
					else{
						previous_datetime=current_datetime;
						current_datetime=(*it2).second;
					}
					if(previous_datetime!=current_datetime){
						std::cerr << "prev datetime != cur time  " << std::endl;

						std::cerr << "prev datetime in write param : " << previous_datetime.toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;
						std::cerr << "current datetime in write param : " << current_datetime.toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;


						Vs=this->doc.createElement("xeml:ValueSet");
						//current_datetime=(*it2).second;

						//std::cerr << "write timepoint" << (*it2).second.toString("dd-MM-yyyyThh:mm:ss").toStdString()<< std::endl;
						//qint64 milliseconds_ellapsed=get_seconds_from_date(this->startDate,(*it2).second);
						//Vs.setAttribute("TimePoint",translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed));
						//Vs.setAttribute("TimePoint",(*it2).second.toString("dd.hh:mm:ss"));
						//var.appendChild(Vs);
						//write_values(&Vs,static_cast<ValueBase*>((*it2).first));
					}

					//QDomElement Vs=this->doc.createElement("xeml:ValueSet");
					//std::cerr << "month = " << static_cast<QDateTime>((*it2).second).date().month() << std::endl;
					//std::cerr << "day = " << static_cast<QDateTime>((*it2).second).date().day() << std::endl;
					//std::cerr << "year = " << static_cast<QDateTime>((*it2).second).date().year() << std::endl;
					std::cerr << "write timepoint" << (*it2).second.toString("dd-MM-yyyyThh:mm:ss").toStdString()<< std::endl;
					qint64 milliseconds_ellapsed=get_seconds_from_date(this->startDate,(*it2).second);
					Vs.setAttribute("TimePoint",translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed));
					//Vs.setAttribute("TimePoint",(*it2).second.toString("dd.hh:mm:ss"));
					var.appendChild(Vs);
					write_values(&Vs,static_cast<ValueBase*>((*it2).first));
				}
				_elem->appendChild(var);
			}
		}
		void                  XemlDocument::write_values(QDomElement * _elem,ValueBase* _vb){
			std::cerr << "entering write values" << std::endl;
			QDomElement val;
			if(!_vb->get_is_cycle()){
				val=this->doc.createElement("xeml:Value");;
				DynamicValue * v = static_cast<DynamicValue*>(_vb);
				if(v->get_context()!=""){
					val.setAttribute("Context",v->get_context());
				}
				if(v->get_unit()!=""){
					val.setAttribute("Unit",v->get_unit());
				}
				if(v->get_label()!=""){
					val.setAttribute("Label",v->get_label());
				}
				if(v->get_is_cyclevalue()){
					std::cerr << "Duration : " << v->get_timepoint().toString("hh:mm:ss").toStdString() << std::endl;
					val.setAttribute("Duration",v->get_timepoint().toString("hh:mm:ss"));
				}

				QDomText t = this->doc.createTextNode(v->get_value());
				val.appendChild(t);
				_elem->appendChild(val);



			}
			else if(_vb->get_is_cycle()){
				std::cerr << "entering cycle values" << std::endl;
				val=this->doc.createElement("xeml:Cycle");
				Cycle * c = static_cast<Cycle*>(_vb);
				if(c->get_context()!=""){
					val.setAttribute("Context",c->get_context());
				}
				if(c->get_unit()!=""){
					val.setAttribute("Unit",c->get_unit());
				}
				if(c->get_label()!=""){
					val.setAttribute("Label",c->get_label());
				}
				for(std::vector<std::pair<DynamicValueBase*,QDateTime> >::iterator it=c->get_cycleValues()->begin();it!=c->get_cycleValues()->end();++it){
					write_values(&val,static_cast<ValueBase*>((*it).first));
				}
				_elem->appendChild(val);

			}
		}
		void                  XemlDocument::write_observationPoint(QDomElement * _elem,StoryNode * _node){
			std::cerr << "entering write observation Point (xemlDocument)" << std::endl;

			Observation * ob;
			//ObservationPoint * test_debug;
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=_node->get_story()->get_obsPointCollection()->begin();it!=_node->get_story()->get_obsPointCollection()->end();++it){
				QDomElement obspoint=this->doc.createElement("xeml:ObservationPoint");

				obspoint.setAttribute("Id",QString::number((*it).first->get_id()));
				//obspoint.setAttribute("TargetTime",(*it).second->get_timespan_Qstr_format());
				qint64 milliseconds_ellapsed=get_seconds_from_date(this->startDate,(*it).first->get_timepoint());
				std::cerr << "ObsPoint Id : " << (*it).first->get_id() << " Msecs : " << milliseconds_ellapsed << std::endl;
				//test_debug=(*it).first;

				obspoint.setAttribute("TargetTime",translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed));
				//obspoint.setAttribute("TargetTime",(*it).second.toString("dd.hh:mm:ss"));
				write_annotation(&obspoint,(*it).first);
				for(std::vector<pair<Observation*,QDateTime> >::iterator it2=(*it).first->get_observationscollection()->begin();it2!=(*it).first->get_observationscollection()->end();++it2){
					ob=(*it2).first;
					QDomElement obs;
					if(ob->get_destructiveinfo()){
						obs=this->doc.createElement("xeml:DestructiveObservation");
					}
					else{
						obs=this->doc.createElement("xeml:Observation");
						if(ob->get_individualInfluence()){
							obs.setAttribute("IndividualInfluence","true");
						}
					}
					write_annotation(&obs,ob);
					if(ob->get_ind()!=NULL){
						obs.setAttribute("individual",QString::number(ob->get_ind()->get_id()));
					}
					if(ob->get_pool()!=NULL){
						obs.setAttribute("poolNS",ob->get_pool()->get_ns());
						obs.setAttribute("poolGermPlasm",ob->get_pool()->get_germplasm());
						//std::cerr << "duration obs :" << ob->get_duration().toString("hh:mm:ss").toStdString() << std::endl;
						obs.setAttribute("Duration",ob->get_duration().toString("hh:mm:ss"));
					}
					Partition * p;
					for(std::map<Partition*,int>::iterator it3=ob->get_partitionCollection()->begin();it3!=ob->get_partitionCollection()->end();++it3){
						p=(*it3).first;
						QDomElement part=this->doc.createElement("xeml:Partition");
						part.setAttribute("Id",QString::number(p->get_id()));
						write_annotation(&part,p);
						for(std::map<BasicTerm*,QString>::iterator it4=p->get_materialCollection()->begin();it4!=p->get_materialCollection()->end();++it4){
							QDomElement term=this->doc.createElement("xeml:Material");
							term.setAttribute("NS",(*it4).first->get_namespacealias());
							term.setAttribute("TermId",(*it4).first->get_termId());
							term.setAttribute("term",(*it4).first->get_name());
							write_annotation(&term,(*it4).first);
							part.appendChild(term);

						}
						for(std::map<BasicTerm*,QString>::iterator it5=p->get_positionCollection()->begin();it5!=p->get_positionCollection()->end();++it5){
							QDomElement term=this->doc.createElement("xeml:Position");
							term.setAttribute("NS",(*it5).first->get_namespacealias());
							term.setAttribute("TermId",(*it5).first->get_termId());
							term.setAttribute("term",(*it5).first->get_name());
							write_annotation(&term,(*it5).first);
							for(std::map<ValueBase*,QString>::iterator it6=static_cast<VariableTerm*>((*it5).first)->get_valuecollection()->begin();it6!=static_cast<VariableTerm*>((*it5).first)->get_valuecollection()->end();++it6 ){
								QDomElement value=this->doc.createElement("xeml:Value");
								value.setAttribute("Context",static_cast<Value*>((*it6).first)->get_context());
								if(static_cast<Value*>((*it6).first)->get_context()=="Quantity"){
									value.setAttribute("Unit",static_cast<Value*>((*it6).first)->get_unit());
								}

								//value.setAttribute("Label",static_cast<Value*>((*it6).first)->get_label());
								QDomText t = this->doc.createTextNode(static_cast<Value*>((*it6).first)->get_val());
								value.appendChild(t);
								term.appendChild(value);
							}
							part.appendChild(term);

						}
						obs.appendChild(part);
					}
					BasicTerm * t;
					for(std::map<BasicTerm *,QString>::iterator it6=ob->get_stageCollection()->begin();it6!=ob->get_stageCollection()->end();++it6){
						t = (*it6).first;
						QDomElement ds=this->doc.createElement("xeml:DevelopmentalStage");
						ds.setAttribute("NS",t->get_namespacealias());
						ds.setAttribute("TermId",t->get_termId());
						ds.setAttribute("term",t->get_name());
						write_annotation(&ds,t);
						obs.appendChild(ds);

					}

					obspoint.appendChild(obs);

				}
				_elem->appendChild(obspoint);

			}

		}
		void XemlDocument::write_event(QDomElement * _elem,StoryNode * _node){
			for(std::map<Event*,QDateTime>::iterator it=_node->get_story()->get_eventcollection()->begin();it!=_node->get_story()->get_eventcollection()->end();++it){
				QDomElement event=this->doc.createElement("xeml:Event");
				//QDateTime timepoint=(*it).second;
				qint64 milliseconds_ellapsed=get_seconds_from_date(this->startDate,(*it).first->get_timepoint());
				event.setAttribute("TimePoint",translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed));
				//event.setAttribute("TimePoint",static_cast<QDateTime>((*it).first->get_timepoint()).toString("dd.hh:mm:ss"));
				event.setAttribute("Label",(*it).first->get_label());
				write_annotation(&event,(*it).first);
				_elem->appendChild(event);
			}


		}

		//region purge
		void                  XemlDocument::purge_story(StoryNode * _node){
			if(_node->get_parent()==NULL){
				std::cerr << "parent null" << _node->get_label().toStdString() << std::endl;
				delete _node;
				//purge_stories(_node);//,(*it)->get_parent());
			}
			else{
				for (std::list<StoryNode*>::iterator it=_node->get_parent()->get_childs()->begin();it!=_node->get_parent()->get_childs()->end();++it){

					if((*it)->get_label()==_node->get_label()){
						std::cerr << (*it)->get_label().toStdString() << std::endl;
						//_node->get_parent()->get_childs()->;
						_node->get_parent()->get_childs()->erase(it);
						std::cerr << "problem" << std::endl;
					}
				}
				if(!_node->get_childs()->empty()){
					std::cerr << "childs is not empty"  << std::endl;
					for (std::list<StoryNode*>::iterator it=_node->get_childs()->begin();it!=_node->get_childs()->end();++it){
						purge_substory((*it));
					}
				}
				else{
					for(std::list<StoryNode*>::iterator it = this->storyBoard->get_storyBoard()->begin();it!=this->get_storyboard()->get_storyBoard()->end();++it){
						if((*it)->get_label()==_node->get_label()){
							this->storyBoard->get_storyBoard()->erase(it);
						}
					}

				}


				//_node->get_parent()=NULL;
				//purge_stories(_node);
			}
			//std::cerr << "node null" << std::endl;
			if(_node==NULL){
				std::cerr << "node null" << std::endl;
			}
			//purge_stories(_node);
			std::cerr << "story and his substories were purged" << std::endl;

			this->storyBoard->get_storyBoard()->remove(_node);
			std::cerr << "node has been removed" << std::endl;
		}
		void                  XemlDocument::purge_substory(StoryNode * _substory){
			if(!(_substory->get_childs()->empty())){
				for (std::list<StoryNode*>::iterator it=_substory->get_childs()->begin();it!=_substory->get_childs()->end();++it){
					purge_substory((*it));
				}


			}

			for(std::list<StoryNode*>::iterator it = this->storyBoard->get_storyBoard()->begin();it!=this->get_storyboard()->get_storyBoard()->end();++it){
				if((*it)->get_label()==_substory->get_label()){
					this->storyBoard->get_storyBoard()->erase(it);
				}
			}
		}

		void                  XemlDocument::purge(){
			for(std::list<StoryNode*>::iterator it = this->storyBoard->get_storyBoard()->begin();it!=this->get_storyboard()->get_storyBoard()->end();++it){
				//if((*it)->get_parent()==NULL){
					//purge_stories((*it));//,(*it)->get_parent());
				//}
				delete (*it);
			}
			this->storyBoard->get_storyBoard()->clear();
		}
		void                  XemlDocument::purge_stories(StoryNode * _node){//,StoryNode *_parent){
			//modification car toujours parent ==NULL (fonction ci-dessus)
			//if(_parent==NULL){
			purge_individuals(static_cast<Story*>(_node->get_story()));
			purge_variable(_node);
			purge_observationPoint(_node);
			if(_node->get_childs()!=NULL){
				for(std::list<StoryNode*>::iterator it = _node->get_childs()->begin();it!= _node->get_childs()->end();++it){
					purge_variable((*it));
					purge_observationPoint(*it);
					if((*it)->get_childs()!=NULL){
						purge_substories((*it));
					}
				}
			}
			//delete _node;
			//}
		}
		void                  XemlDocument::purge_substories(StoryNode * _node){
			for(std::list<StoryNode*>::iterator it = _node->get_childs()->begin();it!= _node->get_childs()->end();++it){
				purge_variable((*it));
				purge_observationPoint((*it));
				if((*it)->get_childs()!=NULL){
					purge_substories((*it));
				}
			}
		}
		void                  XemlDocument::purge_individuals(Story * _st){

			for(std::map<IndividualsPool*,QString>::iterator it = _st->get_individualspoolcollection()->begin();it!=_st->get_individualspoolcollection()->end();++it){
				delete (*it).first;

			}
			//(*it).first->get_individualscollection()->clear();
		}
		void                  XemlDocument::purge_variable(StoryNode *_node){
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=_node->get_story()->get_variablesCollection()->begin();it!=_node->get_story()->get_variablesCollection()->end();++it){
				static_cast<DynamicTerm*>((*it).first)->get_dynamicvaluecollection()->clear();
			}
			_node->get_story()->get_variablesCollection()->clear();
		}
		void                  XemlDocument::purge_observationPoint(StoryNode *_node){
			for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it=_node->get_story()->get_obsPointCollection()->begin();it!=_node->get_story()->get_obsPointCollection()->end();++it){
				for(std::vector<pair<Observation*,QDateTime> >::iterator it2 = (*it).first->get_observationscollection()->begin();it2!=(*it).first->get_observationscollection()->end();++it2){
					(*it2).first->get_pool()->get_individualscollection()->clear();
					for(std::map<Partition*,int>::iterator it3=(*it2).first->get_partitionCollection()->begin();it3!=(*it2).first->get_partitionCollection()->end();++it3){
						(*it3).first->get_materialCollection()->clear();
						for(std::map<BasicTerm*,QString>::iterator it4 = (*it3).first->get_positionCollection()->begin();it4!=(*it3).first->get_positionCollection()->end();++it4){
							static_cast<VariableTerm*>((*it4).first)->get_valuecollection()->clear();
						}
					}
					(*it2).first->get_partitionCollection()->clear();
					(*it2).first->get_stageCollection()->clear();
				}
				(*it).first->get_observationscollection()->clear();
			}
		}

		//region read Xeml
		void                  XemlDocument::Init(QDomDocument * dom){
			this->experimentheader->get_keywords()->clear();
			this->experimentheader->get_experimenter()->clear();
			this->get_doc_resources()->clear_handlers();
			QDomElement dom_element = dom->documentElement();
			QDomNode noeud = dom_element.firstChild();

			while(!noeud.isNull())// Tant que le nœud n'est pas vide.
			{
				if(!dom_element.isNull())
				{
					if(noeud.toElement().tagName().toStdString()=="xeml:Resources"){
						InitRessources(noeud.toElement());

					}
					if(noeud.toElement().tagName().toStdString()=="xeml:Experiment"){
						this->set_experiment_name(noeud.toElement().attributeNode("Name").value());
						QString x = noeud.toElement().attributeNode("Id").value();
						try{


							this->Id=(*new QUuid(x));
						}
						catch(exception ex)
						{
							std::cerr << "Id format is not correct";
						}

						//this->storyBoard->set_obs_time(QDateTime::fromString(noeud.toElement().attributeNode("ObservationTime").value(),"dd.hh:mm:ss"));
						QString tmp=noeud.toElement().attributeNode("ObservationTime").value();
						//std::cerr << "observation time" << QDateTime::fromString(tmp,"dd.hh:mm:ss").toString("dd.hh:mm:ss").toStdString() << std::endl;
						QString start_Date=noeud.toElement().attributeNode("StartDate").value();
						//std::cerr << "--------------------------------+++" << start_Date.toStdString() << std::endl;

						// give the local time if it's a new document
						// or if user load a document, convert the
						// time string into QDateTime.

						if(this->asTemplate){
							this->startDate=QDateTime::currentDateTime();
						}
						else{
							this->startDate=QDateTime::fromString(noeud.toElement().attributeNode("StartDate").value(),"yyyy-MM-ddThh:mm:ss");

						}
						this->observationTime=noeud.toElement().attributeNode("ObservationTime").value();
						this->endDate=get_date(this->startDate,translate_DD_HH_MM_SS_in_Msecs(noeud.toElement().attributeNode("ObservationTime").value()));
						//QDateTime good= startDates.fromString(start_Date,"yyyy-MM-ddThh:mm:ss");
						//QString test=startDates->toString("yyyy-MM-ddThh:mm:ss");
						//std::cerr << "--------------------------------+++" << this->startDate.toString("yyyy-MM-ddThh:mm:ss").toStdString() << std::endl;
						//this->startDate=start_Date.
						QDomNodeList QNL=noeud.toElement().childNodes();
						for (int i = 0; i < QNL.length(); i++) {
							if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Header"){
								QDomNodeList QNL1=QNL.item(i).toElement().childNodes();
								for (int i = 0; i < QNL1.length(); i++) {
									if(QNL1.item(i).toElement().tagName().toStdString()=="xeml:Experimenter"){
										this->experimentheader->get_experimenter()->set_firstname(QNL1.item(i).toElement().attributeNode("FirstName").value());
										this->experimentheader->get_experimenter()->set_lastname(QNL1.item(i).toElement().attributeNode("LastName").value());
										this->experimentheader->get_experimenter()->set_email(QNL1.item(i).toElement().attributeNode("Email").value());
										this->experimentheader->get_experimenter()->set_organization(QNL1.item(i).toElement().attributeNode("Organisation").value());
									}
									else if(QNL1.item(i).toElement().tagName().toStdString()=="xeml:Description"){
										this->experimentheader->set_summary(QNL1.item(i).toElement().text());
									}
									else if(QNL1.item(i).toElement().tagName().toStdString()=="xeml:Keyword"){
										this->experimentheader->add_keyword(new Keyword(QNL1.item(i).toElement().text()));
									}
								}
							}
							if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Story"){
								InitStory(QNL.item(i).toElement(),NULL,"");
								//std::cerr <<"storyboard size : " << this->storyBoard->get_storyBoard()->size() << std::endl;


							}
						}
					}
					noeud = noeud.toElement().nextSibling();
				}
				else{
					std::cout << "problem null element" << std::endl;
				}
			}
		}
		void                  XemlDocument::InitRessources(QDomElement  elem){
			QDomNodeList QNL=elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {


				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:DevelopmentalOntology"){
					QString alias=QNL.item(i).toElement().attributeNode("NS").value();
					QString location=QNL.item(i).toElement().attributeNode("InstanceLocation").value();
					QString uri=QNL.item(i).toElement().attributeNode("HandlerUri").value();
					if (this->documentResources->contains(alias,Xeml::Document::Contracts::Developmental)){
						std::cerr << "developmental ontology double entry. Resource was rejected!" << std::endl;
					}
					else{
						this->documentResources->Add(uri,alias,location,false);
					}

				}
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:OrganismStructureOntology"){
					QString alias=QNL.item(i).toElement().attributeNode("NS").value();
					QString location=QNL.item(i).toElement().attributeNode("InstanceLocation").value();
					QString uri=QNL.item(i).toElement().attributeNode("HandlerUri").value();
					if (this->documentResources->contains(alias,Xeml::Document::Contracts::OrganismStructure)){
						std::cerr << "structural ontology double entry. Resource was rejected!" << std::endl;
					}
					else{
						this->documentResources->Add(uri,alias,location,false);
					}

				}
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:EnvironmentalOntology"){
					QString alias=QNL.item(i).toElement().attributeNode("NS").value();
					QString location=QNL.item(i).toElement().attributeNode("InstanceLocation").value();
					QString uri=QNL.item(i).toElement().attributeNode("HandlerUri").value();
					if (this->documentResources->contains(alias,Xeml::Document::Contracts::Environment)){
						std::cerr << "environment ontology double entry. Resource was rejected!" << std::endl;
					}
					else{
						this->documentResources->Add(uri,alias,location,false);
					}

				}
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:PositioningOntology"){
					QString alias=QNL.item(i).toElement().attributeNode("NS").value();
					QString location=QNL.item(i).toElement().attributeNode("InstanceLocation").value();
					QString uri=QNL.item(i).toElement().attributeNode("HandlerUri").value();
					if (this->documentResources->contains(alias,Xeml::Document::Contracts::Positioning)){
						std::cerr << "environment ontology double entry. Resource was rejected!" << std::endl;
					}
					else{
						this->documentResources->Add(uri,alias,location,false);
					}

				}

			}
		}
		void                  XemlDocument::InitStory(QDomElement  _elem, StoryNode * _node,QString _storyname){
			std::cerr << "entering init story " << std::endl;
			StoryNode * sns=NULL;
			QString storyname=_storyname;
			if(_elem.tagName()=="xeml:Story"){
				std::cerr << "entering  story " << std::endl;
				Story  * s = new Story();
				QDomNodeList QNL=_elem.childNodes();
				InitAnnotations(_elem,s);
				storyname=_elem.attributeNode("Label").value();
				s->set_label(_elem.attributeNode("Label").value());
				sns=new StoryNode(s,false,storyname);
				this->storyBoard->add_Node(sns);
				for (int i = 0; i < QNL.length(); i++) {
					if(QNL.item(i).toElement().tagName()=="xeml:IndividualsPool"){
						std::cerr << "found indivi" << std::endl;
						InitPools(QNL.item(i).toElement(),s);
					}
					/*
					else if(QNL.item(i).toElement().tagName()=="xeml:StorySplit"){
						StorySplit * s = new StorySplit();
						InitAnnotations(QNL.item(i).toElement(),s);
						s->set_label(QNL.item(i).toElement().attributeNode("Label").value());//+" ("+storyname+")");
						//QDateTime date=get_date(this->startDate,translate_DD_HH_MM_SS_in_Msecs(_elem.attributeNode("TimePoint").value()));
						//std::cerr << date.toString("dd-MM-yyyyThh:mm:ss.").toStdString() << std::endl;
						std::cerr << "before set timepoint" <<QNL.item(i).toElement().attributeNode("TimePoint").value().toStdString() << std::endl;
						s->set_timepoint(get_date(this->startDate,translate_DD_HH_MM_SS_in_Msecs(QNL.item(i).toElement().attributeNode("TimePoint").value())));

						//s->set_timepoint(QDateTime::fromString(_elem.attributeNode("TimePoint").value(),"dd.hh:mm:ss"));
						sns=new StoryNode(s,true,storyname);
						this->storyBoard->add_Node(_node,sns);

					}
					*/

				}
			}
			else if(_elem.tagName()=="xeml:StorySplit"){
				StorySplit * s = new StorySplit();
				InitAnnotations(_elem,s);
				s->set_label(_elem.attributeNode("Label").value());//+" ("+storyname+")");
				//QDateTime date=get_date(this->startDate,translate_DD_HH_MM_SS_in_Msecs(_elem.attributeNode("TimePoint").value()));
				//std::cerr << date.toString("dd-MM-yyyyThh:mm:ss.").toStdString() << std::endl;
				std::cerr << "before set timepoint" << _elem.attributeNode("TimePoint").value().toStdString() << std::endl;
				s->set_timepoint(get_date(this->startDate,translate_DD_HH_MM_SS_in_Msecs(_elem.attributeNode("TimePoint").value())));

				//s->set_timepoint(QDateTime::fromString(_elem.attributeNode("TimePoint").value(),"dd.hh:mm:ss"));
				sns=new StoryNode(s,true,storyname);
				this->storyBoard->add_Node(_node,sns);

			}
			QDomNodeList QNL=_elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Variable"){
					InitVariable(QNL.item(i).toElement(),sns->get_isStorySplit(),sns->get_story());
				}
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:ObservationPoint"){
					InitObserverPoint(QNL.item(i).toElement(),sns->get_isStorySplit(),sns->get_story());
				}
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Sample"){
					//InitSample(QNL.item(i).toElement(),sns->get_isStorySplit());
				}
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Event"){
					InitEvent(QNL.item(i).toElement(),sns->get_isStorySplit(),sns->get_story());
				}
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:StorySplit"){
					InitStory(QNL.item(i).toElement(),sns,storyname);
				}
			}

		}
		void                  XemlDocument::InitAnnotations(QDomElement _elem, XemlAnnotableObject * _xo){
			QDomNodeList QNL=_elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Annotation"){
					QString tag= QNL.item(i).toElement().attributeNode("Tag").value();
					QString val= QNL.item(i).toElement().text();
					if(!_xo->contain(tag)){
						_xo->add_tagged_annotation(new TaggedAnnotation(tag,val));
					}
					else{
						std::cerr << "Double annotation tag entry. Skip annotation!" << std::endl;
					}
				}

			}

		}
		void                  XemlDocument::InitPools(QDomElement _elem, XemlAnnotableObject * _xo){
			std::cerr << "entering individual pool" << std::endl;
			IndividualsPool * ip = new IndividualsPool();
			InitAnnotations(_elem,ip);
			ip->set_ns(_elem.attributeNode("NS").value());
			ip->set_germplasm(_elem.attributeNode("GermPlasm").value());
			QDomNodeList QNL=_elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Individual"){
					Individual * ind = new Individual();
					InitAnnotations(QNL.item(i).toElement(),ind);
					ind->set_id(QNL.item(i).toElement().attributeNode("Id").value().toUInt());
					ip->add_Individual(ind);
				}

			}
			static_cast<Story*>(_xo)->add_individualspool(ip);
		}
		void                  XemlDocument::InitVariable(QDomElement _elem,bool _isStorysplit,StoryBase * _storyBase){
			std::cerr << "entering  variable " << std::endl;
			QString termId =_elem.attributeNode("TermId").value();
			DynamicTerm * p = new DynamicTerm(termId);
			InitAnnotations(_elem,p);
			p->set_name(_elem.attributeNode("Name").value());
			p->set_namespacealias(_elem.attributeNode("NS").value());
			if(p->get_namespacealias()!="none" && !this->documentResources->contains(p->get_namespacealias(),Xeml::Document::Contracts::Environment)){
				std::cerr << "namespace resource not found" << std::endl;
			}
			else if(_storyBase->contain_variable(p)){
				std::cerr << "variable double entry" << std::endl;
			}
			else{
				_storyBase->add_variable(p);
			}
			QDomNodeList QNL=_elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:ValueSet"){
					//TimeSpan * ts = new TimeSpan(35,0,0,0);
					std::cerr << QNL.item(i).toElement().attributeNode("TimePoint").value().toStdString() << std::endl;
					std::cerr << "before getDate " << std::endl;

					//QDateTime ts=get_date(this->startDate,translate_DD_HH_MM_SS_in_Msecs(_elem.attributeNode("TimePoint").value()));
					std::cerr << "after getDate " << std::endl;

					//QDateTime ts=QDateTime::fromString(QNL.item(i).toElement().attributeNode("TimePoint").value(),"dd.hh:mm:ss");
					qint64 seconds=translate_DD_HH_MM_SS_in_Msecs(QNL.item(i).toElement().attributeNode("TimePoint").value());
					std::cerr << "after translate : " << seconds << std::endl;
					InitValues(QNL.item(i).toElement(),_isStorysplit,p,get_date(this->startDate,seconds),_storyBase);

				}
			}
		}
		void                  XemlDocument::InitValues(QDomElement _elem,bool _isStorySplit,DynamicTerm * _term,QDateTime _timepoint,StoryBase * _storyBase){
			QDomNodeList QNL=_elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Value"){
					DynamicValue * v = new DynamicValue();
					v->set_is_cyclevalue(false);
					std::cerr << "set timepoint" << _timepoint.toString("dd.hh:mm:ss").toStdString();
					v->set_timepoint(_timepoint);
					v->set_context(QNL.item(i).toElement().attributeNode("Context").value());
					v->set_unit(QNL.item(i).toElement().attributeNode("Unit").value());
					v->set_label(QNL.item(i).toElement().attributeNode("Label").value());
					v->set_value(QNL.item(i).toElement().text());
					if(_term->find(v)){
						std::cerr << "Value double entry. The value will be overriden" << std::endl;
					}
					if(_isStorySplit){
						if(static_cast<StorySplit*>(_storyBase)->get_timepoint()<=v->get_timepoint()){
							_term->add_dynamicvalue(v);//,_timepoint);
						}
						else{
							std::cerr << "Values time is lesser than the split time. Values rejected." << std::endl;
						}
					}
					else{
						_term->add_dynamicvalue(v);//,_timepoint);
					}
				}
				else if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Cycle"){
					Cycle * c =new Cycle();
					c->set_timepoint(_timepoint);
					c->set_context(QNL.item(i).toElement().attributeNode("Context").value());
					c->set_unit(QNL.item(i).toElement().attributeNode("Unit").value());
					c->set_label(QNL.item(i).toElement().attributeNode("Label").value());
					QDomNodeList QNLcycle=QNL.item(i).toElement().childNodes();
					for (int i = 0; i < QNLcycle.length(); i++) {
						if(QNLcycle.item(i).toElement().tagName().toStdString()=="xeml:Value"){
							DynamicValue * v = new DynamicValue();
							v->set_is_cyclevalue(true);
							v->set_value(QNLcycle.item(i).toElement().text());
							v->set_timepoint(QDateTime::fromString(QNLcycle.item(i).toElement().attributeNode("Duration").value(),"hh:mm:ss"));

							//need to parse timespan to push in the map
							c->add_cycleValue(make_pair(v,v->get_timepoint()));
						}
					}
					if(_term->find(c)){
						std::cerr << "Value double entry. The value will be overriden" << std::endl;
						//_term->
					}
					if(_isStorySplit){
						if(static_cast<StorySplit*>(_storyBase)->get_timepoint()<=c->get_timepoint()){
							_term->add_dynamicvalue(c);
						}
						else{
							std::cerr << "Values time is lesser than the split time. Values rejected." << std::endl;
						}
					}
					else{
						_term->add_dynamicvalue(c);
					}
				}
			}
		}
		void                  XemlDocument::InitEvent(QDomElement _elem,bool _isStorySplit,StoryBase * _storyBase){
			Q_UNUSED(_isStorySplit);
			Event * e = new Event();
			InitAnnotations(_elem,e);
			e->set_timepoint(get_date(this->startDate,translate_DD_HH_MM_SS_in_Msecs(_elem.attributeNode("TimePoint").value())));

			//e->set_timepoint(QDateTime::fromString(_elem.attributeNode("TimePoint").value(),"dd.hh:mm:ss"));
			e->set_label(_elem.attributeNode("Label").value());
			_storyBase->add_event(e);
		}
		void                  XemlDocument::InitObserverPoint(QDomElement _elem,bool _isStorySplit, StoryBase * _storyBase){
			Q_UNUSED(_isStorySplit);
			//std::cerr << "entering add observerPoint" << std::cerr;
			ObservationPoint * op = new ObservationPoint();
			this->observationPointsCounter++;

			InitAnnotations(_elem,op);

			op->set_id(_elem.attributeNode("Id").value().toInt());
			op->set_timepoint(get_date(this->startDate,translate_DD_HH_MM_SS_in_Msecs(_elem.attributeNode("TargetTime").value())));

			//op->set_timepoint(QDateTime::fromString(_elem.attributeNode("TargetTime").value(),"dd.hh:mm:ss"));

			QDomNodeList QNL=_elem.childNodes();

			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Observation"){

					Observation * ob = new Observation();

					InitAnnotations(QNL.item(i).toElement(),ob);
					ob->set_destructiveinfo(false);
					ob->set_duration(QDateTime::fromString(QNL.item(i).toElement().attributeNode("Duration").value(),"hh:mm:ss"));//TimeSpanExtension::tryTimeSpanSet(QNL.item(i).toElement().attributeNode("Duration").value()));
					int indId =-1;
					QString indIDstr=QNL.item(i).toElement().attributeNode("Individual").value();
					if ((!indIDstr.isEmpty()) && (!indIDstr.isNull())){
						indId=indIDstr.toInt();
					}
					QString nsStr = QNL.item(i).toElement().attributeNode("poolNS").value();
					QString germplasmStr =QNL.item(i).toElement().attributeNode("poolGermPlasm").value();
					QString fqName;
					if (((!nsStr.isEmpty()) && (!nsStr.isNull()))&& !(nsStr=="none")){
						fqName = nsStr+":"+germplasmStr;
					}
					else{
						fqName =germplasmStr;
					}
					StoryNode * node=this->storyBoard->findNode(_storyBase);// = _storyBase.
					while(node->get_isStorySplit()){
						node=node->get_parent();
					}
					Individual * ind;
					IndividualsPool * ip = static_cast<Story*>(_storyBase)->find(fqName);
					if(ip!=NULL){
						ob->set_pool(ip);
						ind=ip->find(indId);
						if(ind!=NULL){
							ob->set_ind(ind);
						}
						else if(indId<=0){
							std::cerr << "Individual not found" << std::endl;
						}
					}
					else{
						std::cerr << "Individuals pool not found" << std::endl;
					}
					InitPartitions(QNL.item(i).toElement(),ob);
					InitDevelopmentalStage(QNL.item(i).toElement(),ob);
					op->add_observation(ob);
				}
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:DestructiveObservation"){
					Observation * ob = new Observation();

					InitAnnotations(QNL.item(i).toElement(),ob);

					ob->set_destructiveinfo(true);

					//ob->set_duration(TimeSpanExtension::tryTimeSpanSet(QNL.item(i).toElement().attributeNode("Duration").value()));
					ob->set_duration(QDateTime::fromString(QNL.item(i).toElement().attributeNode("Duration").value(),"hh:mm:ss"));

					ob->set_individualInfluence(true);
					int indId =-1;

					QString indIDstr=QNL.item(i).toElement().attributeNode("individual").value();

					if ((!indIDstr.isEmpty()) && (!indIDstr.isNull())){
						indId=indIDstr.toInt();

					}
					QString nsStr = QNL.item(i).toElement().attributeNode("poolNS").value();
					QString germplasmStr =QNL.item(i).toElement().attributeNode("poolGermPlasm").value();
					QString fqName;
					if (((!nsStr.isEmpty()) && (!nsStr.isNull())) && !(nsStr=="none")){

						fqName = nsStr+":"+germplasmStr;

					}
					else{
						fqName =germplasmStr;
					}
					StoryNode * node=this->storyBoard->findNode(_storyBase);// = _storyBase.
					while(node->get_isStorySplit()){
						node=node->get_parent();
					}

					Individual * ind;
					IndividualsPool * ip = static_cast<Story*>(node->get_story())->find(fqName);
					if(ip!=NULL){
						ob->set_pool(ip);
						ind=ip->find(indId);
						if(ind!=NULL){
							ob->set_ind(ind);
						}
						else if(indId<=0){
							std::cerr << "Individual not found" << std::endl;
						}
					}
					else{
						std::cerr << "Individuals pool not found" << std::endl;
					}

					InitPartitions(QNL.item(i).toElement(),ob);
					InitDevelopmentalStage(QNL.item(i).toElement(),ob);
					op->add_observation(ob);
				}
			}
			if(_storyBase->contain_obsPoint(op)){
				std::cerr << "ObservationPoint double entry. ObservationPoint was rejected!" << std::endl;
			}
			else{
				_storyBase->add_obsPoint(op);
			}

		}
		void                  XemlDocument::InitPartitions(QDomElement _elem,Observation * _ob){
			QDomNodeList QNL=_elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:Partition"){
					Partition * part = new Partition();
					InitAnnotations(QNL.item(i).toElement(),part);
					part->set_id(QNL.item(i).toElement().attributeNode("Id").value().toInt());
					this->partition_counter++;
					QDomNodeList QNL2=QNL.item(i).toElement().childNodes();
					for (int j = 0; j < QNL2.length(); j++) {
						if(QNL2.item(j).toElement().tagName().toStdString()=="xeml:Material"){
							QString id= QNL2.item(j).toElement().attributeNode("TermId").value();
							BasicTerm * mat = new BasicTerm(id);
							InitAnnotations(QNL2.item(j).toElement(),mat);
							mat->set_namespacealias(QNL2.item(j).toElement().attributeNode("NS").value());
							mat->set_name(QNL2.item(j).toElement().attributeNode("term").value());
							part->addMaterialTerm(mat);

						}
						if(QNL2.item(j).toElement().tagName().toStdString()=="xeml:Position"){
							QString id=QNL2.item(j).toElement().attributeNode("TermId").value();
							VariableTerm * pos =new VariableTerm(id);
							InitAnnotations(QNL2.item(j).toElement(),pos);
							pos->set_namespacealias(QNL2.item(j).toElement().attributeNode("NS").value());
							pos->set_name(QNL2.item(j).toElement().attributeNode("term").value());
							part->addPositionTerm(pos);
							QDomNodeList QNL3=QNL2.item(j).toElement().childNodes();
							for (int k = 0; k < QNL3.length(); k++) {
								if(QNL3.item(k).toElement().tagName().toStdString()=="xeml:Value"){
									Value * v =new Value();
									v->set_context(QNL3.item(k).toElement().attributeNode("Context").value());
									v->set_unit(QNL3.item(k).toElement().attributeNode("Unit").value());
									v->set_label(QNL3.item(k).toElement().attributeNode("Label").value());
									v->set_value(QNL3.item(k).toElement().text());
									pos->add_value(v);
								}

							}

						}
					}
					if(!(_ob->contain_partition(part))){
						_ob->add_partition(part);
					}
					else{
						std::cerr << "Double entry for partition. Partition will be skipped." << std::endl;
					}
				}
			}
		}
		void                  XemlDocument::InitDevelopmentalStage(QDomElement _elem,Observation * _ob){
			QDomNodeList QNL=_elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="xeml:DevelopmentalStage"){
					QString nsAlias=QNL.item(i).toElement().attributeNode("NS").value();
					QString id= QNL.item(i).toElement().attributeNode("TermId").value();
					QString term= QNL.item(i).toElement().attributeNode("term").value();
					QString val= QNL.item(i).toElement().text();
					BasicTerm * ds = new BasicTerm(id);
					ds->set_namespacealias(nsAlias);
					ds->set_name(term);
					if(!(_ob->contain_stages(id))){
						_ob->add_stage(ds);
						InitAnnotations(QNL.item(i).toElement(),ds);
					}
					else{
						std::cerr << "Double annotation tag entry. Skip annotation!" << std::endl;
					}

				}
			}
		}

		QUuid                 XemlDocument::get_id(){
			return this->Id;
		}
		QDateTime             XemlDocument::get_startdate(){
			return this->startDate;
		}
		void                  XemlDocument::set_startdate(QDateTime  _t){

			//std::cerr << "-------------2--"<< put_date_in_string(_t) << std::endl;

			this->startDate=_t;
			//std::cerr << "--------------------------------+++" << this->startDate.toString("yyyy-MM-ddThh:mm:ss").toStdString() << std::endl;

			//std::cerr << "-------------2--"<< put_date_in_string(this->startDate) << std::endl;

		}
		QString             XemlDocument::get_obs_time(){
			return this->observationTime;
		}

		void                XemlDocument::set_obs_time(QString _time){
			this->observationTime=_time;
		}

		QDateTime             XemlDocument::get_enddate(){
			return this->endDate;
		}
		void                  XemlDocument::set_enddate(QDateTime  _t){

			//std::cerr << "-------------2--"<< put_date_in_string(_t) << std::endl;

			this->endDate=_t;
			//std::cerr << "--------------------------------+++" << this->startDate.toString("yyyy-MM-ddThh:mm:ss").toStdString() << std::endl;

			//std::cerr << "-------------2--"<< put_date_in_string(this->startDate) << std::endl;

		}

		QString               XemlDocument::get_experiment_name(){
			return this->experiment_name;
		}
		QString               XemlDocument::get_xemlcode(){
			return this->xeml;
		}
		StoryBoard        *   XemlDocument::get_storyboard(){
			return this->storyBoard;
		}
		ExperimentHeader  *   XemlDocument::get_experimentheader(){
			return this->experimentheader;
		}
		DocumentResources *   XemlDocument::get_doc_resources(){
			return this->documentResources;
		}
		void                  XemlDocument::set_experiment_name(QString _name){
			this->experiment_name=_name;
		}
		void                  XemlDocument::set_xemlcode(QString _xeml){
			this->xeml=_xeml;
		}
		void                  XemlDocument::NewId(){
			this->Id=Id.createUuid();
		}
		void                  XemlDocument::RefreshXeml(){

		}
		void                  XemlDocument::LoadFile(QString path){

		}
		void                  XemlDocument::DoXmlValidation(){

		}
		void                  XemlDocument::DoXmlValidation(QString xemlCode){

		}

		//region helper

		QString                XemlDocument::put_date_in_string(time_t _startdate){

			//char *_date;
			QString date;
			struct tm * timeinfo;
			char buffer [80];

			time ( &_startdate );
			timeinfo = localtime ( &_startdate );
			strftime(buffer,80,"%Y-%m-%dT%H:%M:%S",timeinfo);
			//m_stream.write(buffer, 19);
			 //m_stream << buffer << " - " << line << endl;
			for(int i=0;i<19;i++){
				date+=buffer[i];
				//std::cerr << buffer[i]<< std::endl;
			}
			//_date = ctime(&_startdate);
			return date;
		}

		QString               XemlDocument::put_id_in_Qstring(QUuid _id){
			return _id.toString();
		}
		QString           XemlDocument::put_id_in_string(QUuid _id){
			return _id.toString();
		}
	}
}