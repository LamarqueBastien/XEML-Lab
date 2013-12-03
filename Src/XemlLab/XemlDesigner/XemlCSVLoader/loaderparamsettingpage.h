#ifndef LOADERPARAMSETTINGPAGE_H
#define LOADERPARAMSETTINGPAGE_H
#include<QtWidgets>
#include<QWizardPage>
#include<QLabel>
#include<QStandardItemModel>
#include"Interface/itfdocument.h"
#include"CoreObjects/documentresources.h"
#include"XemlCSVLoader/loaderwizard.h"
#include"XemlCSVLoader/loaderontologypage.h"
#include"XemlCSVLoader/loaderstorypage.h"
#include"XemlCSVLoader/loaderdatetimepage.h"
#include"DialogWindows/timedialog.h"
using std::pair;
using std::make_pair;

using namespace Xeml::Document;



class LoaderParamSettingPage : public QWizardPage
{
		Q_OBJECT
	private:
		ItfDocument * current_doc;
		DocumentResources * doc_resources;
		QLabel *Filename;
		QLineEdit *FilenameLineEdit2;
		QTableView * table;
		QStandardItemModel * model;
		LoaderOntologyPage * ontologyPage;
		LoaderStoryPage * storyPage;
		LoaderDateTimePage * dateTimePage;
		QModelIndexList * indexlist;
		QStandardItemModel * modeltree;

		std::vector<std::pair<ItfOntologyTerm *,QString> > *  terms;
		std::vector<StoryNode*> * stories;
		QVector<StoryNode*>  stories2;
		QVector<std::pair<ItfOntologyTerm *,QString> >  terms2;
		std::vector<QString> * termHeaderLabel;


		QString time_expression;
		bool IsTimeParameter;



	public:
		LoaderParamSettingPage(QStandardItemModel * _model,ItfDocument * _doc,DocumentResources * _resources,QWidget *parent = 0);
		int nextId() const;
	private:

		qint64 calculate_time(QDateTime _date);

		//const void complete_xeml_doc(std::vector<StoryNode*> * _storynode,QString _date,std::vector<std::pair<ItfOntologyTerm *,QString> > *  _terms);
	protected:
		void initializePage();
	private slots:
		void set_paramater_type(bool _is_time_parameter);
		void store_information_term(int column,int _row,ItfOntologyTerm * _term,QString _unit);
		void store_information_story(int column,int _row,StoryNode * _storynode);
		void store_information_time(int column,int _row,QString _date);
		void store_information_term_and_story(int column,int _row,StoryNode * _storynode,ItfOntologyTerm * _term,QString _unit);



		void on_item_selected(QModelIndex _index);

		void send_data(std::vector<std::vector<QString> *> * _vectorData);

};

#endif // LOADERPARAMSETTINGPAGE_H
