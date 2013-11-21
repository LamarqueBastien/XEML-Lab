#ifndef GERMPLASMPANEL_H
#define GERMPLASMPANEL_H
#include<QtWidgets>
#include<QTableView>
#include<QBoxLayout>
#include<QHeaderView>
#include<QStandardItemModel>
#include"Views/Items/genotypeitem.h"
#include"CoreObjects/storybase.h"
#include"CoreObjects/story.h"
#include"CoreObjects/storysplit.h"
#include"Interface/itfdocument.h"
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
