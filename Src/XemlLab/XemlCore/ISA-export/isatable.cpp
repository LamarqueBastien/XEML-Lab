#include "isatable.h"

IsaTable::IsaTable(QObject *parent) : QAbstractTableModel(parent)
{
	TermSourceREF = new QString("Term Source REF");
	TermAccessionNumber = new QString("Term Accession Number");
	Unit =  new QString("Unit");
	ProtocolREF =  new QString("Protocol REF");

}
QVariant IsaTable::data(const QModelIndex & index, int role) const{

}
int IsaTable::columnCount(const QModelIndex & parent) const{

}
int IsaTable::rowCount(const QModelIndex & parent) const{

}

QVariant IsaTable::headerData(int section, Qt::Orientation orientation, int role) const{

}

