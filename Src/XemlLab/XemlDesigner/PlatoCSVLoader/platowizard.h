#ifndef PLATOWIZARD_H
#define PLATOWIZARD_H
#include<QtWidgets>
#include"Interface/itfdocument.h"
#include"CoreObjects/documentresources.h"
#include"PlatoCSVLoader/platointropage.h"
#include"PlatoCSVLoader/platodatapage.h"
using namespace Xeml::Document;
using namespace std;

class PlatoWizard : public QWizard
{
		Q_OBJECT
	private:
		QWizardPage * platoIntroPage;
		QWizardPage * platoDataPage;
		ItfDocument * xeml_doc;
		DocumentResources * doc_res;
		//QWizardPage * loaderParamSettingPage;
		//QWizardPage * loaderValidationPage;
		//QWizardPage * loaderConclusionPage;
		static std::vector<std::vector<QString>* > * plantcsvdata;
		static std::vector<std::vector<QString>* > * harvestcsvdata;
		static std::vector<std::vector<QString>* > * samplecsvdata;
	public:
		enum { Page_Intro, Page_Data, Page_ParamSet, Page_Validation,
				   Page_Conclusion };
		PlatoWizard(ItfDocument * _doc,DocumentResources * _resources,QWidget *parent = 0);
		static std::vector<std::vector<QString>* > * get_plant_data();
		static std::vector<std::vector<QString>* > * get_harvest_data();
		static std::vector<std::vector<QString>* > * get_sample_data();

	signals:
	private slots:
};

#endif // PLATOWIZARD_H
