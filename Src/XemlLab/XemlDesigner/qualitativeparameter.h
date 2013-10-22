#ifndef QUALITATIVEPARAMETER_H
#define QUALITATIVEPARAMETER_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<iostream>
#include<QRadioButton>
#include<QComboBox>
#include<QScrollArea>
#include<QDateTimeEdit>
#include"itfontologyterm.h"
#include"xeoterm.h"
#include"variableterm.h"
#include"variablecontextspec.h"
using namespace std;
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document::EnvironmentalOntology;
class QualitativeParameter : public QDialog
{
		Q_OBJECT
	private:
		QLabel      * labelvalue;
		QLabel      * labelunit;
		QLineEdit   * labelEdit;
		QLabel      * title;
		QPushButton * cancelButton;
		QPushButton * okButton;
		QRadioButton   * const_or_cycle;
		QComboBox      * values;
		QComboBox      * unit;
		QString     context;
		ItfOntologyTerm * term;
		BasicTerm * current_term;
		QDateTime dateTime;
		QRadioButton *_value;
		QRadioButton *_cycle;
		QDateTimeEdit * _time;
		QWidget * extension;
		QPushButton *addCycle;
		QPushButton *removeCycle;
		std::vector<QString> * enumeration;
		int counter_row;
		int counter;
	public:
		QualitativeParameter(std::vector<QString> * _enumeration,QDateTime datetime,QWidget *parent = 0);
		QualitativeParameter(QWidget * parent=0);
		void          set_term(BasicTerm * _term);
		void          set_context(QString _context);
		QString       get_context();
		void          set_enum(std::vector<QString> * _enume);
	signals:
		void          send_value(DynamicValue * _v);

	private slots:
		void          inactive_value(bool _CycleMode);
		void          set_dateTime(QDateTime _datetime);
		void          OkClicked();
		void          add_cycle();
		void          remove_cycle();
		void          enabledOkButton(const QString &text);
};

#endif // QUALITATIVEPARAMETER_H
