#include "storyitem.h"

#include "parameteritem.h"

StoryItem::StoryItem(const QString & _text,StoryBase * st,bool _isStorySplit,bool _isRoot)
	:AbstractExperimentItem(_text){

	this->isStorySplit=_isStorySplit;
	this->isroot=_isRoot;
	this->story=st;
}

StoryItem::StoryItem(const QString & _text,bool _isRoot)
:AbstractExperimentItem(_text){

	this->isroot=_isRoot;
	this->story=NULL;

}
bool StoryItem::isRoot(){
	return this->isroot;
}

void StoryItem::add_term(ItfOntologyTerm* _term){
	this->terms.push_back(_term);
}

ItfOntologyTerm* StoryItem::get_term(QString _termId){
	for(std::list<ItfOntologyTerm*>::iterator it = this->terms.begin();it!=this->terms.end();++it){
		if((*it)->get_termId()==_termId){
			return (*it);
		}
	}
	return NULL;
}
StoryBase * StoryItem::get_story(){
	return this->story;
}
bool StoryItem::get_isStorySplit(){
	return this->isStorySplit;
}

//ItfOntologyTerm * StoryItem::get_term(){
//	return this->term;
//}

//void ParameterItem::set_term(ItfOntologyTerm * _term){
//	this->term=_term;
//}
