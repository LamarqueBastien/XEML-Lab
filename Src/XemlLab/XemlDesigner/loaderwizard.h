#ifndef LOADERWIZARD_H
#define LOADERWIZARD_H
#include<QWizard>
#include<QWizardPage>
#include<QtWidgets>
#include<QSpinBox>
#include<QStandardItemModel>
#include"itfdocument.h"
#include"documentresources.h"
#include"loaderintropage.h"
#include"loaderdatafilepage.h"
#include"loaderparamsettingpage.h"
#include"loadervalidationpage.h"
#include"loaderconclusionpage.h"
using namespace Xeml::Document;
using namespace std;

class LoaderWizard : public QWizard
{
		Q_OBJECT
	private:

		//ItfDocument * current_doc;
		//DocumentResources * doc_resources;
		QWizardPage * loaderIntroPage;
		QWizardPage * loaderDataFilePage;
		QWizardPage * loaderParamSettingPage;
		QWizardPage * loaderValidationPage;
		QWizardPage * loaderConclusionPage;
		static std::vector<std::vector<QString>* > * csvdata;

	public:
		enum { Page_Intro, Page_DataFile, Page_ParamSet, Page_Validation,
				   Page_Conclusion };
		LoaderWizard(QStandardItemModel * _model,ItfDocument * _doc,DocumentResources * _resources,QWidget *parent = 0);
		static std::vector<std::vector<QString>* > * get_CSV_data();


	signals:
	private slots:
		void showHelp();
		void parseCSVfiles(QString _filename);
};

#endif // LOADERWIZARD_H
