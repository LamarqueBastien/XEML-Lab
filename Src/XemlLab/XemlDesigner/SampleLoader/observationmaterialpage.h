#ifndef OBSERVATIONMATERIALPAGE_H
#define OBSERVATIONMATERIALPAGE_H
#include<QtWidgets>
#include <QWizard>
#include<iostream>
#include"CoreObjects/storynode.h"
#include"CoreObjects/story.h"
#include"Interface/itfhierarchicalview.h"
#include"CoreObjects/observationpoint.h"
#include"Views/Items/parameteritem.h"
#include"CoreObjects/documentresources.h"
#include"Views/parametertreeview.h"
#include"AboutWindows/aboutparameter.h"
class ObservationMaterialPage : public QWizardPage
{
		Q_OBJECT
	public:
		ObservationMaterialPage(DocumentResources * _doc_resources, QWidget *parent = 0);
	private:
		AboutParameter * aboutParameter;
		DocumentResources * doc_resources;
		//QTreeView        * parameterTree;
		ParameterTreeView * structView;
		ParameterTreeView * posView;
		QLineEdit        * structEdit;
		QLabel           * structLabel;
		QLineEdit        * structnameEdit;
		QLabel           * structnameLabel;
		QLineEdit        * nameEdit;
		QLabel           * nameLabel;
		QLineEdit        * UnitEdit;
		QLabel           * UnitLabel;
		QLineEdit        * ValueEdit;
		QLabel           * ValueLabel;
		QLineEdit        * QValueEdit;
		QLabel           * QValueLabel;
		QLineEdit        * idEdit;
		QLabel           * idLabel;
		QSpinBox         * repBox;
		QLabel           * replica;
	protected:
		void initializePage();
	private slots:
		void add_details_about_term(ItfOntologyTerm * _term);
		void get_structTerm(ItfOntologyTerm * _term);
		void get_posTerm(ItfOntologyTerm * _term);
};

#endif // OBSERVATIONMATERIALPAGE_H
