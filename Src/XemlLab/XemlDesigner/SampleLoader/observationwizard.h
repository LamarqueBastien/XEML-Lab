#ifndef OBSERVATIONWIZARD_H
#define OBSERVATIONWIZARD_H
#include<QWizard>
#include<QWizardPage>
#include<QtWidgets>
#include<QModelIndexList>
#include<QStandardItemModel>
#include"CoreObjects/storybase.h"
#include"CoreObjects/storyboard.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/documentresources.h"
#include"CoreObjects/timespanextension.h"

using namespace Xeml::Document::Contracts;
using namespace Xeml::Document;

class ObservationWizard : public QWizard
{
		Q_OBJECT

	private:

		DocumentResources * doc_resources;
		QModelIndexList   * indexlist;
		StoryNode        * storyRoot;
		ObservationPoint * obspoint;
		ItfDocument      * xeml_doc;
		StoryNode        * current_storynode;
		//QWizardPage      * IntroPage;
		//QWizardPage      * GenotypePage;
		//QWizardPage      * ObservationPage;
		//QWizardPage      * MaterialPage;
		//QWizardPage      * ReplicationPage;
		//QWizardPage      * ConclusionPage;

	public:

		//enum { Page_Intro, Page_DataFile, Page_ParamSet, Page_Validation,
				   //Page_Conclusion };
		ObservationWizard(StoryNode * _current,StoryNode * _root,ObservationPoint * _obs,DocumentResources  * _doc_resources,ItfDocument * _doc,  QWidget *parent = 0);


		//this function retrieve all informations collected
		//during the wizard and fill the Xeml document accordingly.
		void accept();




};

#endif // OBSERVATIONWIZARD_H
