#ifndef ISATABLE_H
#define ISATABLE_H
#include<QAbstractTableModel>
#include"Interface/itfdocument.h"


using namespace Xeml::Document;

class IsaTable : public QAbstractTableModel
{
	public:
		IsaTable(QObject *parent = 0);
		QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
		int columnCount(const QModelIndex & parent = QModelIndex()) const;
		int rowCount(const QModelIndex & parent = QModelIndex()) const;
		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	private:
		const QString * TermSourceREF;
		const QString * TermAccessionNumber;
		const QString * Unit;
		const QString * ProtocolREF;
};

#endif // ISATABLE_H
