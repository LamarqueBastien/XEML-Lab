#ifndef PARAMETERTREEVIEW_H
#define PARAMETERTREEVIEW_H
#include<QPainter>
#include <QWidget>
#include<QAbstractScrollArea>
#include<QtGui>
#include<QStandardItemModel>
#include<QTreeView>
#include<list>
#include<QTableView>
#include<QStandardItem>
#include<QPushButton>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QHeaderView>
#include"itfhierarchicalview.h"
#include"itfontologyterm.h"
#include"filemanager.h"
#include"itfdocument.h"
#include"parameteritem.h"
#include"documentresources.h"
#include"aboutparameter.h"
#include"ontologypanel.h"

using Xeml::Document::Contracts::ItfOntologyTerm;
using namespace Xeml::Document::Contracts;
class ParameterTreeView : public QWidget
{
		Q_OBJECT

	private:
		QTreeView                                * parameterTree;
		QPushButton                              * parameterInfo;
		QPushButton                              * addParameter;
		QPushButton                              * addOntology;
		QLineEdit                                * search;
		QLabel                                   * searchLabel;
		QStandardItemModel                       * my_treeparameter;
		DocumentResources                        * doc_ressources;
		bool                                       mode;
	public:
		explicit                                   ParameterTreeView(DocumentResources * _doc,QWidget *parent = 0);
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
		void                                       search_term(QString _term);
		//void                                       display(QModelIndex elementselected);
		void                                       add_parameter();
		void                                       showSelection();
		void                                       add_ontology();
		void                                       send_ontologies(bool _xeoIsChecked,bool _eoIsChecked,bool _envoIsChecked);





};

#endif // PARAMETERTREEVIEW_H
