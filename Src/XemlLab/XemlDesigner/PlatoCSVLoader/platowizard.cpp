#include "platowizard.h"

std::vector<std::vector<QString> * > * PlatoWizard::plantcsvdata = new std::vector<std::vector<QString> *>();
std::vector<std::vector<QString> * > * PlatoWizard::harvestcsvdata = new std::vector<std::vector<QString> *>();
std::vector<std::vector<QString> * > * PlatoWizard::samplecsvdata = new std::vector<std::vector<QString> *>();


PlatoWizard::PlatoWizard(ItfDocument * _doc,DocumentResources * _resources,QWidget *parent)
		: QWizard(parent)
{

	xeml_doc=_doc;
	doc_res=_resources;
	platoIntroPage=new PlatoIntroPage();
	QPixmap watermark("://Images/csv_text.png");
	platoIntroPage->setPixmap(QWizard::WatermarkPixmap,watermark);
	setPage(Page_Intro, platoIntroPage);

	platoDataPage=new PlatoDataPage(xeml_doc);
	setPage(Page_Data, platoDataPage);
}

std::vector<std::vector<QString> *> * PlatoWizard::get_plant_data(){
	return plantcsvdata;
}
std::vector<std::vector<QString> *> * PlatoWizard::get_harvest_data(){
	return harvestcsvdata;
}
std::vector<std::vector<QString> *> * PlatoWizard::get_sample_data(){
	return samplecsvdata;
}
