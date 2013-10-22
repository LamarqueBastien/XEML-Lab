#ifndef FREETEXTPARAMETER_H
#define FREETEXTPARAMETER_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QRadioButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<QDateTimeEdit>
#include<QScrollArea>
#include"itfontologyterm.h"
#include"xeoterm.h"
using namespace std;
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document::EnvironmentalOntology;
class FreeTextParameter : public QDialog
{
		Q_OBJECT
	private:
		QLabel      * label;
		//QLabel      * timelabel;
		QLineEdit   * textEdit;
		//QDateTimeEdit * daytimeedit;
		QLabel      * title;
		QPushButton * cancelButton;
		QPushButton * okButton;
		QString     context;
		QWidget * extension;
		ItfOntologyTerm * term;
		BasicTerm * current_term;
		QRadioButton *_value;
		QRadioButton *_cycle;
		QPushButton *addCycle;
		QPushButton *removeCycle;
		QDateTimeEdit * _time;
		QDateTime dateTime;
		int counter_row;
		int counter;

	public:
		FreeTextParameter(QDateTime datetime,QWidget *parent = 0);
		void          set_term(BasicTerm * _term);
		void          set_context(QString _context);
		QString   get_context();
	private slots:
		void          inactive_value(bool _CycleMode);
		void          set_dateTime(QDateTime _datetime);
		void          OkClicked();
		void          add_cycle();
		void          remove_cycle();
		void          enabledOkButton(QString _text);
};

#endif // FREETEXTPARAMETER_H
