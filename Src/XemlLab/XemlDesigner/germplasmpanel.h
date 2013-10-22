#ifndef GERMPLASMPANEL_H
#define GERMPLASMPANEL_H
#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QHeaderView>
#include<QStandardItemModel>
#include"genotypeitem.h"
#include"storybase.h"
#include"story.h"
#include"storysplit.h"
#include"itfdocument.h"
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document;
class GermPlasmPanel : public QWidget
{
		Q_OBJECT
	private:
		QTableView         * view;
		QStandardItemModel * model;
	public:
		GermPlasmPanel(QWidget * parent=0);
		void                 clean_model();
		void                 initialize(ItfDocument * _xemlDoc);
};

#endif // GERMPLASMPANEL_H
