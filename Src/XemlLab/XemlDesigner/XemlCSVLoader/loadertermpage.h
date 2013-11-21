#ifndef LOADERTERMPAGE_H
#define LOADERTERMPAGE_H
#include<QtWidgets>
#include"Views/parametertreeview.h"
#include"CoreObjects/documentresources.h"

class LoaderTermPage : public QWidget
{
		Q_OBJECT
	public:
		LoaderTermPage(DocumentResources * _xeml_res,QWidget * parent=0);
		ParameterTreeView * onto_trees;
		QStandardItemModel * tree_model;
		QComboBox * unitBox;
		QComboBox * valueBox;
		QComboBox * ontoBox;
		QTextEdit * description;
		QLineEdit * termId;
		QLabel * def_label;
		QLabel * term_label;
		ItfOntologyTerm * current_term;
		DocumentResources * xeml_res;
		QPushButton        * cancelButton;
		QPushButton        * okButton;
		QPushButton        * removeButton;
	private slots:
		void get_Term(ItfOntologyTerm * _term);
		void tree_changed(QString _namespace);
		void finished();
		void removed();
	protected:
		void initializePage();
	signals:
		void send_details_term(ItfOntologyTerm * _term,QString _unit);

};


#endif // LOADERTERMPAGE_H
