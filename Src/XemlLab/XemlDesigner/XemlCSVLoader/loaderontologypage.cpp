#include "loaderontologypage.h"

LoaderOntologyPage::LoaderOntologyPage(QStandardItemModel * _model,int _column,int _row,ItfDocument * _doc,DocumentResources * _xeml_res,QWidget * parent)
	:QWidget(parent)
{
	this->row=_row;
	this->column=_column;
	std::cerr << "create onto page "<< std::endl;
	this->termPage=new LoaderTermPage(_xeml_res);
	this->storypage=new LoaderStoryPage(_model,_column,_row,_doc);
	this->storypage->createExperiment(_doc);
	//this->timepage=new LoaderDateTimePage(_row);

	this->finishButton=new QPushButton("Finish");
	connect(this->termPage,SIGNAL(send_details_term(ItfOntologyTerm*,QString)),this,SLOT(get_term(ItfOntologyTerm*,QString)));
	connect(this->storypage,SIGNAL(send_details_story(int,int,StoryNode*)),this,SLOT(get_story(int,int,StoryNode*)));
	connect(this->finishButton,SIGNAL(clicked()),this,SLOT(finished()));
	//connect(this->timepage,SIGNAL(delimitered_dateTime(int,QString)),this,SLOT(get_time(int,QString)));



	this->contexts=new QTabWidget;
	this->contexts->addTab(this->termPage,"Header/term Pairing");
	this->contexts->addTab(this->storypage,"Stories");
	//this->contexts->addTab(this->timepage,"time representation");


	QVBoxLayout * leftlayout= new QVBoxLayout;
	leftlayout->addWidget(this->contexts);
	leftlayout->addWidget(this->finishButton);
	setLayout(leftlayout);
	setWindowFlags(Qt::WindowStaysOnTopHint);



}
void LoaderOntologyPage::finished(){
	emit send_term_and_story(this->column,this->row,this->story,this->term,this->unit);
	this->close();
}

void LoaderOntologyPage::get_term(ItfOntologyTerm* _term ,QString _unit){
	//emit send_term(this->column,this->row,_term ,_unit);
	this->term=_term;
	this->unit=_unit;
	//this->close();
}
//void LoaderOntologyPage::get_time(int _row ,QString _date){
//	emit send_time(this->row,_date);
//	this->close();
//}
void LoaderOntologyPage::get_story(int _column,int _row ,StoryNode * _story){
	//emit send_story(this->column,this->row+1,_story);
	this->story=_story;
	//this->close();
}
