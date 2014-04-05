#ifndef OBSERVATIONDETAILS_H
#define OBSERVATIONDETAILS_H
#include <QSystemTrayIcon>
#include <QtWidgets>
#include<iostream>
#include"Views/parametertreeview.h"

using namespace std;

class ObservationDetails : public QDialog
{
		Q_OBJECT
	typedef enum
	{
	OneForAll,
	All
	}ModelOrNotModel;


	public:
		explicit ObservationDetails(DocumentResources * _doc_resources,StoryNode * _root,std::vector<IndividualsPool*> * _pools, QWidget *parent = 0);
		void add_individuals_pool(QStandardItem * _root,StoryNode * _rootNode);

		void initialize_table(std::vector<IndividualsPool*> * _pools);
		QCheckBox * get_pooling_check_box();
		QCheckBox * get_destruct_check_box();
		QCheckBox * get_template_check_box();
		QTimeEdit * get_time();

		QTreeView * get_tree();
		QStandardItemModel * get_model();



	private:

		void set_model_tree(ModelOrNotModel displayMode);


		QDialogButtonBox   * buttonBox;
		QCheckBox          * pooling;
		QCheckBox          * destructCheckBox;
		QCheckBox          * use_template_for_all;
		QLabel             * durationInd;
		QLineEdit          * durationEdit;
		QTimeEdit          * timeDurationEdit;
		QPushButton        * add_individual;
		QPushButton        * remove_variable;
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
		void show_help();
		void on_remove_item_clicked();

		void on_modelCB_clicked();
		void add_details_about_pos_term(ItfOntologyTerm * _term);
		void on_item_double_clicked(QModelIndex index);
		void on_item_checked(QStandardItem* _item);

		void add_parameter_item(ItfOntologyTerm * _term);
		void add_ind();
		void add_ind(int _id,bool _isDestroyed,int _count,int _row,QString _germplasm);

};

#endif // OBSERVATIONDETAILS_H
