#ifndef QUANTITATIVEPARAMETER_H
#define QUANTITATIVEPARAMETER_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QRadioButton>
#include<QBoxLayout>
#include<QTextEdit>
#include<QSpinBox>
#include<QComboBox>
#include<QDateTimeEdit>
#include"Interface/itfontologyterm.h"
#include"Ontologies/Environment/xeoterm.h"
#include"CoreObjects/variableterm.h"
#include"CoreObjects/value.h"
#include"Div/windowtitlebar.h"
#include<vector>
using namespace std;
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document::EnvironmentalOntology;
class QuantitativeParameter : public QDialog
{
		Q_OBJECT
	private:
		QLabel      * label;
		QLabel      * labelUnit;
		QLabel      * title;
		std::vector<QString> * enume;
		QSpinBox   * valueBox;
		QComboBox  * unitBox;
		QPushButton * cancelButton;
		QPushButton * okButton;
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
		int counter_row;
		int counter;

	public:
		QuantitativeParameter(QDateTime datetime,QWidget *parent = 0);
		QuantitativeParameter(QWidget *parent = 0);

		void          set_term(BasicTerm * _term);
		void          set_context(QString _context);
		QString       get_context();
		//void          setWindowTitle(const QString &title);
		void          set_enumUnit(std::vector<QString> * _enume);

	private slots:

		void          OkClicked();
		void          reset();
		void          enabledOkButton(int _tmp);
		void          set_dateTime(QDateTime _datetime);
		void          inactive_value(bool _CycleMode);
		void          add_cycle();
		void          remove_cycle();

};

#endif // QUANTITATIVEPARAMETER_H
