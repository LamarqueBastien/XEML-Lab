#ifndef LOADERONTOLOGYPAGE_H
#define LOADERONTOLOGYPAGE_H
#include<QtWidgets>
#include"documentresources.h"
#include"itfdocument.h"
#include"loadertermpage.h"
#include"loaderstorypage.h"
#include"loaderdatetimepage.h"

using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
class LoaderOntologyPage : public QWidget
{
		Q_OBJECT
	public:
		LoaderOntologyPage(QStandardItemModel * _model,int _column,int _row,ItfDocument * _doc,DocumentResources * _xeml_res, QWidget * parent=0);
	private:
		QTabWidget * contexts;
		QPushButton * finishButton;
		LoaderTermPage * termPage;
		LoaderStoryPage * storypage;
		StoryNode * story;
		QString unit;
		ItfOntologyTerm * term;
		//LoaderDateTimePage * timepage;
		int row;
		int column;
	private slots:
		void get_term(ItfOntologyTerm* _term ,QString _unit);
		//void get_time(int _row ,QString _date);
		void finished();
		void get_story(int _column,int _row ,StoryNode * _story);

	signals:
		void send_term(int _column,int _row,ItfOntologyTerm* _term ,QString _unit);
		void send_story(int _column,int _row,StoryNode *_story);
		void send_term_and_story(int _column,int _row,StoryNode *_story,ItfOntologyTerm* _term ,QString _unit);

		//void send_time(int _row,QString _date);
};

#endif // LOADERONTOLOGYPAGE_H
