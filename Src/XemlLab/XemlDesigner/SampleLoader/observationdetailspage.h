#ifndef OBSERVATIONDETAILSPAGE_H
#define OBSERVATIONDETAILSPAGE_H
#include<QtWidgets>
#include <QWizard>
#include<iostream>
#include<QTimeEdit>
#include"CoreObjects/storynode.h"
#include"CoreObjects/story.h"
#include"Interface/itfhierarchicalview.h"
#include"CoreObjects/observationpoint.h"
#include"Views/Items/parameteritem.h"
#include"CoreObjects/documentresources.h"
#include"Views/parametertreeview.h"
#include"observationdetails.h"
#include"observationwizard.h"
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document;

class ObservationDetailsPage : public QWizardPage
{
		Q_OBJECT
	public:
		ObservationDetailsPage(DocumentResources * _doc_resources, StoryNode * _root, QWidget *parent = 0);
		//void build_dev_tree(std::list<TermNode*> * _my_tree,QString _namespace);
		//void buildNodeHierarchy(TermNode * node,std::list<TermNode*> * _processed_nodes, ParameterItem * _tmp_item,QString _namespace);
		//bool contains(TermNode * _node,std::list<TermNode*> * _processed_nodes,QString _namespace);

	private:
		DocumentResources * doc_resources;
		//QTreeView        * parameterTree;
		ParameterTreeView * my_treeView;
		//QStandardItemModel  * my_treeparameter;
		QTabWidget       * tabs;
		QCheckBox        * new_individuals_box;
		QCheckBox        * existing_individuals;
		QCheckBox        * pool;
		QLabel           * germplasm;
		QLineEdit        * germplasmEdit;
		QLabel           * germLabel;
		QLabel           * destructiveInfo;
		QCheckBox        * destructCheckBox;
		QTimeEdit        * timeDurationEdit;
		QLabel           * durationInd;
		QLineEdit        * durationEdit;
		QLabel           * termLabel;
		QLineEdit        * termEdit;
		QLabel           * nameLabel;
		QLineEdit        * nameEdit;
		QLabel           * Individuals;
		QSpinBox         * IndBox;
		QPushButton      * showTree;
		QPushButton      * add_observation;
		QTreeView        * DevStageView;
		int                obs_counter;
		StoryNode        * root_node;
		std::vector<IndividualsPool*> * pools;
		std::vector<ObservationDetails*> * observations_tmp;
	protected:
		void initializePage();
	private slots:
		void get_term(ItfOntologyTerm * _term);
		void add_obs();
};

#endif // OBSERVATIONDETAILSPAGE_H
