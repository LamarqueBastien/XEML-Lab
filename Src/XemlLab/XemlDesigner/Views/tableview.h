#ifndef TABLEVIEW_H
#define TABLEVIEW_H
#include<QTableView>
#include<QStandardItemModel>
#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"
#include<QHeaderView>

using namespace Xeml::Document;

class TableView : public QTableView
{
		Q_OBJECT
	public:
		explicit TableView(ItfDocument * _xemlDoc, QTableView *parent = 0);
		void populate_table();
		//void add_variable_columns(QStandardItemModel * _variableModel);
		void write_variable_context(DynamicTerm * _term,ValueBase* _vb,qint64 _milliseconds_ellapsed, int _sample_counter,int _story_counter);
		void write_variable_value(StoryNode * _node,ItfDocument * _xemlDoc, int _sample_counter,int _story_counter,QString _header,int _column);

	private:
		void init();
		QStandardItemModel * modelTable;
		ItfDocument  * xemlDoc;
		int column_count;

	signals:

	private slots:
		void sample_item_checked(QStandardItem * _selected_item);
		void variable_item_checked(QStandardItem * _selected_item);
		void event_item_checked(QStandardItem * _selected_item);

};

#endif // TABLEVIEW_H
