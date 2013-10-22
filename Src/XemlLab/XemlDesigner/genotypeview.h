#ifndef GENOTYPEVIEW_H
#define GENOTYPEVIEW_H
#include<QPainter>
#include<QWidget>
#include<QAbstractScrollArea>
#include<QtGui>
#include<QStandardItemModel>
#include<QTreeView>
#include<QTableView>
#include<QStandardItem>
#include<QPushButton>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QHeaderView>
#include"germplasmpanel.h"
#include"itfdocument.h"
#include"genotypedialog.h"
using namespace Xeml::Document::Contracts;
class GenotypeView : public QWidget
{
		Q_OBJECT

	private:
		ItfDocument        * currentDoc;
		QPushButton * addGenotype;
		GermPlasmPanel * gpp;
		GenotypeDialog * new_genotype;

	public:
		GenotypeView(QWidget *parent = 0);

		void initialize(ItfDocument * _xemlDoc);
		void clean_view();

	signals:
		void on_new_genotype(QString _idtext,QString _freetext,QString _taxontext);
	private slots:
		void refresh_view(ItfDocument * _xemldoc);
		void genotype_to_add(QString _idtext,QString _freetext,QString _taxontext);
		void add_genotype();
};

#endif // GENOTYPEVIEW_H
