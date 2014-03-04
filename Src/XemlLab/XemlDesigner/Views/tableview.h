#ifndef TABLEVIEW_H
#define TABLEVIEW_H
#include<QTableView>
#include<QStandardItemModel>
#include"Interface/itfdocument.h"
#include<QHeaderView>

using namespace Xeml::Document;

class TableView : public QTableView
{
		Q_OBJECT
	public:
		explicit TableView(ItfDocument * _xemlDoc, QTableView *parent = 0);
		void populate_table();
	private:
		void init();
		QStandardItemModel * modelTable;
		ItfDocument  * xemlDoc;

	signals:

	private slots:
		void sample_item_checked(QStandardItem * _selected_item);
		void variable_item_checked(QStandardItem * _selected_item);
		void event_item_checked(QStandardItem * _selected_item);

};

#endif // TABLEVIEW_H
