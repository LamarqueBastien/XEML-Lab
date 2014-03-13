#ifndef EXPERIMENTTABLEVIEW_H
#define EXPERIMENTTABLEVIEW_H
#include<QPainter>
#include <QtWidgets>
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
#include"Views/tableview.h"


#include"Interface/itfdocument.h"
using namespace Xeml::Document;

class ExperimentTableView : public QWidget
{
		Q_OBJECT
	public:
		ExperimentTableView(ItfDocument * _xemlDoc, QWidget * parent = 0);

	private:
		void init();
		void init_variable_table();
		void init_event_table();
		TableView * experiment_view;
		QTreeView * sampleView;
		QTreeView * variableView;
		QTreeView * eventView;
		QStandardItemModel * sampleModel;
		QStandardItemModel * variableModel;
		QStandardItemModel * eventModel;


		ItfDocument  * xemlDoc;
	private slots:


};

#endif // EXPERIMENTTABLEVIEW_H