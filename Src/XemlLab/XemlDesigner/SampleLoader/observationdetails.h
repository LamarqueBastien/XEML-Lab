#ifndef OBSERVATIONDETAILS_H
#define OBSERVATIONDETAILS_H
#include <QSystemTrayIcon>
#include <QtWidgets>
#include<iostream>
#include"Views/parametertreeview.h"

using namespace std;

class ObservationDetails : public QWidget
{
		Q_OBJECT
	public:
		explicit ObservationDetails(DocumentResources * _doc_resources,StoryNode * _root,std::vector<IndividualsPool*> * _pools, QWidget *parent = 0);
		void add_individuals_pool(QStandardItem * _root,StoryNode * _rootNode);

		void initialize_table(std::vector<IndividualsPool*> * _pools);

	private:
		QCheckBox          * pooling;
		QCheckBox          * destructCheckBox;
		QCheckBox          * use_template_for_all;
		QLabel             * durationInd;
		QLineEdit          * durationEdit;
		QTimeEdit          * timeDurationEdit;
		QPushButton        * add_individual;
		QTreeView          * tree;
		QStandardItemModel * model;
		DocumentResources  * doc_resources;
		QModelIndex          current_index;
		ParameterTreeView  * parameter_tree;
		int                  individuals;
		StoryNode          * root_node;
		QLabel             * germplasm;
		QTableView         * germPlasmTable;
		QStandardItemModel * germPlasmModel;
		std::vector<IndividualsPool*> * pools;




	signals:

	public slots:
	private slots:
		void on_modelCB_clicked();
		void add_details_about_pos_term(ItfOntologyTerm * _term);
		void on_item_double_clicked(QModelIndex index);
		void on_item_checked(QStandardItem* _item);

		void add_parameter_item(ItfOntologyTerm * _term);
		void add_ind();
		void add_ind(int _id,bool _isDestroyed);

};

#endif // OBSERVATIONDETAILS_H
