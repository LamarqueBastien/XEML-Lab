#ifndef ABOUTPARAMETER_H
#define ABOUTPARAMETER_H
#include<QSplitter>
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<iostream>
#include<QListWidget>
#include<QDateTime>
#include<QStackedLayout>
#include"itfontologyterm.h"
#include"dynamicterm.h"
#include"xeoterm.h"
#include"qualitativeparameter.h"
#include"responserangeparameter.h"
#include"freetextparameter.h"
#include"quantitativeparameter.h"
#include"itfdocument.h"
#include"xemldocument.h"
#include"posterm.h"
#include"storynode.h"
#include"storyitem.h"
using namespace Xeml::Document::Ontologies::Positionning;
using namespace Xeml::Document;
using namespace Xeml::Document::EnvironmentalOntology;
using namespace Xeml::Document::Contracts;

class AboutParameter : public QDialog
{
	Q_OBJECT
	private:
		ItfOntologyTerm * term;
	public:
		AboutParameter(ItfDocument * _xemldoc,StoryNode * _story,QWidget * parent=0);
		AboutParameter(QWidget * parent=0);
		bool             usemode;
		ItfDocument    * current_doc;
		QWidget        * param_window;
		QListWidget    * listWidget;
		QFrame         * line1;
		QFrame         * line2;
		QFrame         * line3;
		StoryNode      * story;
		QLabel         * timelabel;
		//QDateTimeEdit  * daytimeedit;
		//StoryItem      * storyitem;
		QStackedLayout * stackLayout;
		QVBoxLayout    * mainlayout;
		QHBoxLayout    * paramLayout;
		QPushButton    * cancelButton;
		QPushButton    * okButton;
		QDateTimeEdit  * daytimeedit;
		QPushButton    * finishButton;
		QualitativeParameter * quality;
		QSplitter      * splitter;
		ResponseRangeParameter * responseRange;
		FreeTextParameter * freeText;
		QuantitativeParameter * quantity;
		void set_term(ItfOntologyTerm * _term);
		ItfOntologyTerm * get_term();
		BasicTerm      * newTerm;
		void          initialize();


	signals:
		//void             value_initialized(QString _text);
		void             set_up_finished(ItfOntologyTerm * _term);
		void             set_up_finished(StoryNode * _story,BasicTerm * _term);

	private slots:
		void             on_setup_finished();


		void             set_up_qualitativeValue(DynamicValue * _v);
		void             set_up_responseRangeValue(DynamicValue * _v);
		void             set_up_quantitativeValue(DynamicValue * _v);
		void             set_up_freeTextValue(DynamicValue * _v);
};

#endif // ABOUTPARAMETER_H
