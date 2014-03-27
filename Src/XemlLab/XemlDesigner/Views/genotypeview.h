#ifndef GENOTYPEVIEW_H
#define GENOTYPEVIEW_H
#include<QPainter>
#include<QtWidgets>
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
#include"PanelWindows/germplasmpanel.h"
#include"Interface/itfdocument.h"
#include"DialogWindows/genotypedialog.h"
using namespace Xeml::Document::Contracts;
class GenotypeView : public QWidget
{
		Q_OBJECT

	private:
		ItfDocument        * currentDoc;
		QPushButton * addGenotype;
		QPushButton * removeGenotype;
		QPushButton * Edit;
		GermPlasmPanel * gpp;
		GenotypeDialog * new_genotype;

	public:
		GenotypeView(QWidget *parent = 0);

		void initialize(ItfDocument * _xemlDoc);
		void clean_view();

	signals:
		void on_new_genotype(IndividualsPool * _pool);
	private slots:
		void show_help();

		void refresh_view(ItfDocument * _xemldoc);
		void genotype_to_add(IndividualsPool * _pool);
		void add_genotype();
		void remove_genotype();
		void edit_genotype();
};

#endif // GENOTYPEVIEW_H
