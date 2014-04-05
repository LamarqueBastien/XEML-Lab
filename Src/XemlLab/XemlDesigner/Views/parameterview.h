#ifndef PARAMETERVIEW_H
#define PARAMETERVIEW_H
#include<QTableView>
#include<QTreeView>
#include<QDragEnterEvent>
#include<QDropEvent>
#include<QDragMoveEvent>
#include<QMouseEvent>
#include<iostream>
#include<QLabel>
#include<QMimeData>
#include<QDrag>
#include<QPainter>
#include"Views/Items/parameteritem.h"
using namespace std;

class ParameterView :public QTreeView
{
		Q_OBJECT
	public:
		ParameterView(QTreeView * parent = 0);
	protected:
		void dragEnterEvent(QDragEnterEvent *event);
		void dragMoveEvent(QDragMoveEvent *event);
		//void dropEvent(QDropEvent *event);
		void mousePressEvent(QMouseEvent *event);
		int sizeHintForColumn(int column);


};

#endif // PARAMETERVIEW_H
