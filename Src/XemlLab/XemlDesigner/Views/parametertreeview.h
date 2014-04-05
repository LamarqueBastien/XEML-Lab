#ifndef PARAMETERTREEVIEW_H
#define PARAMETERTREEVIEW_H
#include<QPainter>
#include <QtWidgets>
#include<QAbstractScrollArea>
#include<QtGui>
#include<QStandardItemModel>
#include<QTreeView>
#include<QHeaderView>
#include<list>
#include<QTableView>
#include<QStandardItem>
#include<QPushButton>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QHeaderView>
#include"Interface/itfhierarchicalview.h"
#include"Interface/itfontologyterm.h"
#include"filemanager.h"
#include"Interface/itfdocument.h"
#include"Views/Items/parameteritem.h"
#include"CoreObjects/documentresources.h"
#include"AboutWindows/aboutparameter.h"
#include"PanelWindows/ontologypanel.h"
#include"Views/parameterview.h"

using Xeml::Document::Contracts::ItfOntologyTerm;
using namespace Xeml::Document::Contracts;
class ParameterTreeView : public QWidget
{
		Q_OBJECT

	private:
		ParameterView                            * draggableParameterTree;
		QTreeView                                * parameterTree;
		QPushButton                              * parameterInfo;
		QPushButton                              * addParameter;
		QPushButton                              * addOntology;
		QLineEdit                                * search;
		QLabel                                   * searchLabel;
		QStandardItemModel                       * my_treeparameter;
		DocumentResources                        * doc_ressources;
		bool                                       mode;
		bool                                       drag_and_drop_mode;
	public:
		explicit                                   ParameterTreeView(bool _drag_and_drop_mode,DocumentResources * _doc,QWidget *parent = 0);
		bool                                       contains(TermNode * _node,std::list<TermNode*> * _processed_nodes,QString _namespace);
		void                                       buildNodeHierarchy(TermNode * node,std::list<TermNode*> * _processed_nodes, ParameterItem * _tmp_item,QString _namespace);
		void                                       buildNodeHierarchy(TermNode * node,QString _namespace);

		void                                       build_ontology_tree(std::list<TermNode*> * _my_tree,QString _namespace);
		void                                       set_up_Ontologytree(DocumentResources * _doc,QStringList  * _ontologies);
		void                                       clean_tree();
	//protected:
		//void                                       paintEvent(QPaintEvent *);


	signals:
		void                                       onParameterselected(ItfOntologyTerm* _term);

		void                                       ontology_to_load(bool,bool,bool);
	public slots:
	private slots:
		void                                       resize_column(QModelIndex _index);
		void                                       show_help();
		void                                       search_term(QString _term);
		//void                                       display(QModelIndex elementselected);
		void                                       add_parameter();
		void                                       showSelection();
		void                                       add_ontology();
		void                                       send_ontologies(bool _xeoIsChecked,bool _eoIsChecked,bool _envoIsChecked);





};

#endif // PARAMETERTREEVIEW_H
