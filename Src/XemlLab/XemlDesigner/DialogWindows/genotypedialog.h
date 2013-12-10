#ifndef GENOTYPEDIALOG_H
#define GENOTYPEDIALOG_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<QTextEdit>
#include<iostream>
#include<QStringList>
#include"CoreObjects/individualspool.h"
#include"DialogWindows/annotationdialog.h"

using namespace Xeml::Document;
class GenotypeDialog : public QDialog
{
		Q_OBJECT
	private:
		QLabel      * id_label;
		QLineEdit   * idEdit;
		QLabel      * species_label;
		QLineEdit   * speciesEdit;
		QLabel      * taxon_label;
		QLineEdit   * taxonEdit;
		QLabel      * accession_label;
		QLineEdit   * accessionEdit;
		QLabel      * mutant_label;
		QLineEdit   * mutantEdit;
		QLabel      * transgenic_label;
		QLineEdit   * transgenicEdit;
		QLabel      * free_annot_label;
		QTextEdit   * free_annotEdit;
		QPushButton * annotation_id;
		QPushButton * annotation_species;
		QPushButton * annotation_accession;
		QPushButton * annotation_mutant;
		QPushButton * annotation_transgenic;
		AnnotationDialog * annot_dialog;


		IndividualsPool * pool;
		QPushButton * cancelButton;
		QPushButton * okButton;
		QStringList * list_id_label;
		QString table[4];
	public:
		GenotypeDialog(QWidget *parent = 0);

	signals:

		void          genotype_added(IndividualsPool * _pool, QString _idtext,QString _freetext,QString _taxontext);

	private slots:

		void          OkClicked();
		void          add_species_label(const QString &text);
		void          add_accession_label(const QString &text);
		void          add_mutant_label(const QString &text);
		void          add_transgenic_label(const QString &text);
		void          add_tagged_annotation(QString _tag,QString _annot);

		void          add_tag_id();
		void          add_tag_species();
		void          add_tag_accession();
		void          add_tag_mutant();
		void          add_tag_transgenic();

		void          enabledOkButton(const QString &text);
};

#endif // GENOTYPEDIALOG_H
