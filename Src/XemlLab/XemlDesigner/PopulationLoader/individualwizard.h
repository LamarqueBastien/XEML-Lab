#ifndef INDIVIDUALWIZARD_H
#define INDIVIDUALWIZARD_H
#include<QWizard>
#include<QWizardPage>
#include"CoreObjects/individualspool.h"
#include"CoreObjects/individual.h"
#include"CoreObjects/storybase.h"
#include"CoreObjects/storyboard.h"
#include"PopulationLoader/individualintropage.h"
#include"PopulationLoader/individualimportfilepage.h"
#include"PopulationLoader/individualcreationpage.h"
#include"PopulationLoader/individualconclusionpage.h"

using namespace Xeml::Document;

class IndividualWizard : public QWizard
{
		Q_OBJECT
	public:
		IndividualWizard(IndividualsPool * _pool, QWidget *parent=0);
		void accept();
		enum {
			Page_Intro,
			Page_ImportFile,
			Page_Creation,
			Page_Conclusion
		};
	private:
		IndividualsPool * pool;
		QWizardPage * individualIntroPage;
		QWizardPage * individualImportFilePage;
		QWizardPage * individualCreationPage;
		QWizardPage * individualConclusionPage;

};

#endif // INDIVIDUALWIZARD_H
