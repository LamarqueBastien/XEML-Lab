#include "observationwizard.h"
#include"observationintropage.h"
#include"observationgenotypepage.h"
#include"observationdetailspage.h"
#include"observationmaterialpage.h"

ObservationWizard::ObservationWizard(StoryNode * _root,ObservationPoint * _obs,DocumentResources * _doc_resources,ItfDocument * _doc, QWidget *parent)
	: QWizard(parent)
{
	this->setMinimumHeight(700);
	this->setMinimumWidth(1100);
	std::cerr << "entering ObservationWizard" << std::endl;
	this->doc_resources = _doc_resources;
	this->storyRoot=_root;
	this->obspoint = _obs;
	this->xeml_doc=_doc;


	addPage(new ObservationIntroPage);
	std::cerr << "add intro page" << std::endl;

	addPage(new ObservationGenotypePage(this->storyRoot));
	std::cerr << "add geno page" << std::endl;
	addPage(new ObservationDetailsPage(this->doc_resources));
	std::cerr << "add detai page" << std::endl;
	addPage(new ObservationMaterialPage(this->doc_resources));


	//addPage(createMaterialPage());
	//addPage(createConclusionPage());

	setWindowTitle("defines sampling strategy for genotype ");

}
void ObservationWizard::accept(){
	//we retrieve all the necessaries info like:
	//-number of individuals and related pool name
	//-development term id
	//-structure term id
	//-position term Id
	/*
	QString structTermName=field("structName").toString();
	QString devTermName=field("DevName").toString();
	QString Germplasm=field("GermPlasm").toString();
	QString DevTermId=field("DevTermId").toString();
	int numInd=field("Individuals").toInt();
	QString nameEdit=field("PosTermName").toString();
	QString Duration=field("Duration").toString();
	QString structTermId=field("StructTermID").toString();
	QString posTermId=field("PosTermId").toString();
	QString unit=field("Unit").toString();
	QString value=field("Value").toString();
	QString qvalue=field("QValue").toString();
	*/
	int replica=field("Replica").toInt();
	for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->end();++it){
		if((*it).second==field("GermPlasm").toString()){
			for(int i = 0; i<field("Individuals").toInt();i++){
				Individual * ind = new Individual(1+ rand() % 1000000000);
				static_cast<IndividualsPool*>((*it).first)->add_Individual(ind);
				Observation * ob = new Observation();
				std::cerr <<  field("Duration").toString().toStdString() << std::endl;
				std::cerr << QDateTime::fromString(field("Duration").toString(),"yyyy-MM-ddThh:mm:ss").toString("hh:mm:ss").toStdString() << std::endl;
				//QDateTime::fromString(QDateTime::fromString(field("Duration").toString(),"yyyy-MM-ddThh:mm:ss").toString("hh:mm:ss"));
				QString test=QDateTime::fromString(field("Duration").toString(),"yyyy-MM-ddThh:mm:ss").toString("hh:mm:ss");
				std::cerr << "test string" << test.toStdString() << std::endl;
				ob->set_duration(QDateTime::fromString(test,"hh:mm:ss"));
				//ob->set_duration(QDateTime::fromString(QDateTime::fromString(field("Duration").toString(),"yyyy-MM-ddThh:mm:ss").toString("hh:mm:ss")));
				//ob->set_duration(TimeSpanExtension::tryTimeSpanSet(field("Duration").toString()));
				std::cerr << "duration obs :" << ob->get_duration().toString("hh:mm:ss").toStdString() << std::endl;

				ob->set_destructiveinfo(true);
				ob->set_ind(ind);
				ob->set_pool((*it).first);
				Partition * p = new Partition();
				static_cast<XemlDocument*>(this->xeml_doc)->partition_counter+=1;
				p->set_id(static_cast<XemlDocument*>(this->xeml_doc)->partition_counter);
				BasicTerm * devTerm= new BasicTerm(field("DevTermId").toString());
				devTerm->set_name(field("DevName").toString());
				devTerm->set_namespacealias("PO_Development");
				BasicTerm * structTerm =new BasicTerm(field("StructTermID").toString());
				structTerm->set_namespacealias("PO_Structure");
				structTerm->set_name(field("structName").toString());
				VariableTerm * posTerm=new VariableTerm(field("PosTermId").toString());
				posTerm->set_namespacealias("XEO_Positioning");
				posTerm->set_name(field("PosTermName").toString());
				Value * quantityContext= new Value();
				quantityContext->set_context("Quantity");
				quantityContext->set_unit(field("Unit").toString());
				quantityContext->set_value(field("QValue").toString());
				posTerm->add_value(quantityContext);

				Value * qualityContext =new Value();
				qualityContext->set_context("Quality");
				qualityContext->set_value(field("Value").toString());
				posTerm->add_value(qualityContext);

				p->addPositionTerm(posTerm);
				p->addMaterialTerm(structTerm);
				if(!(ob->contain_stages(field("DevTermId").toString()))){
					ob->add_stage(devTerm);
				}
				if(!(ob->contain_partition(p))){
					ob->add_partition(p);
				}
				ob->set_individualInfluence(false);
				this->obspoint->add_observation(ob);
			}
		}

	}



	/*
	  std::cerr << "germplasm : " << Germplasm.toStdString() << "\n"
				<< "devtermId : " << DevTermId.toStdString() << "\n"
				<< "numInd : " << numInd << "\n"
				<< "Duration : " << Duration.toStdString() << "\n"
				<< "structTermId : " << structTermId.toStdString() << "\n"
				<< "posTermId : " << posTermId.toStdString() << " "
				<< nameEdit.toStdString()<<" :" << qvalue.toStdString()<< unit.toStdString() << "\n"
				<< "Quality : " << value.toStdString()<< "\n"
				<< "replica : " << replica << std::endl;
				*/

	QDialog::accept();
 }






















/*
QWizardPage * ObservationWizard::createIntroPage(){
	QWizardPage *page = new QWizardPage;
	page->setTitle("Introduction");

	QLabel * label = new QLabel("This wizard will help you register your observation "
							   "point.");
	label->setWordWrap(true);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(label);
	page->setLayout(layout);

	return page;
}

QWizardPage * ObservationWizard::createRegistrationPage(){
	QWizardPage * Regpage = new QWizardPage;
	Regpage->setTitle("GermPlasm");
	Regpage->setSubTitle("Please fill both fields.");

	QLabel *nameLabel = new QLabel("Name:");
	QLineEdit *nameLineEdit = new QLineEdit;
	//Regpage->registerField("LabelName*", nameLineEdit);

	QLabel *emailLabel = new QLabel("Email address:");
	QLineEdit *emailLineEdit = new QLineEdit;

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(nameLabel, 0, 0);
	layout->addWidget(nameLineEdit, 0, 1);
	layout->addWidget(emailLabel, 1, 0);
	layout->addWidget(emailLineEdit, 1, 1);
	Regpage->setLayout(layout);

	return Regpage;
}
QWizardPage * ObservationWizard::createMaterialPage(){
	QWizardPage *page = new QWizardPage;

	page->setTitle("Material");
	page->setSubTitle("Please fill both fields.");

	QLabel *nameLabel = new QLabel("Name:");
	QLineEdit *nameLineEdit = new QLineEdit;


	QLabel *emailLabel = new QLabel("Email address:");
	QLineEdit *emailLineEdit = new QLineEdit;

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(nameLabel, 0, 0);
	layout->addWidget(nameLineEdit, 0, 1);
	layout->addWidget(emailLabel, 1, 0);
	layout->addWidget(emailLineEdit, 1, 1);
	page->setLayout(layout);

	return page;
}


QWizardPage * ObservationWizard::createConclusionPage(){
	//le signal de retour sera émis à partir de cette fonction
	//qui renverra toutes les données collectées
	QWizardPage *page = new QWizardPage;
	page->setTitle("Conclusion");

	QLabel *label = new QLabel("You are now successfully registered. Have a "
							   "nice day!");
	label->setWordWrap(true);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(label);
	page->setLayout(layout);

	return page;
}

QWizard * ObservationWizard::get_wizard(){
	return this->wizard;
}
*/
