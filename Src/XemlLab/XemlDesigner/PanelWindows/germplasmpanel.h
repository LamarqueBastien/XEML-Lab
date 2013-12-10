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
		ItfDocument        * doc;
	public:
		GermPlasmPanel(QWidget * parent=0);
		void                 clean_model();
		void                 remove_row();
		void                 get_selected_element();
		void                 initialize(ItfDocument * _xemlDoc);
	private slots:
		void                 germplasm_set_label(QString _germplasmlabel);

	signals:
		void                 reset_label(QString _label);
};

#endif // GERMPLASMPANEL_H
