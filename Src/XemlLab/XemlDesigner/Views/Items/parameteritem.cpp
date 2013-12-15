#include "parameteritem.h"

ParameterItem::ParameterItem(const QString & _text,ItfOntologyTerm * _term){
	this->setText(_text+" ("+_term->get_prototype()->get_termId()+")");
	this->term=_term;
	this->setBackground(QBrush(Qt::white));
	this->setDragEnabled(true);
	this->setDropEnabled(true);

}
ParameterItem::ParameterItem(QString _namespace,TermNode * _node,const QString & _text,ItfOntologyTerm * _term,bool _isRoot){
	this->term=_term;
	if (_term==NULL || _namespace=="XEO_Positioning"){
		this->setText(_node->get_label());
	}
	else{
		this->setToolTip(this->term->get_definition());
		this->setText(_text+" ("+_term->get_prototype()->get_termId()+")");
	}
	this->isRoot=_isRoot;
	this->setDragEnabled(true);
	this->setDropEnabled(true);
}

ParameterItem::ParameterItem(TermNode * _node,const QString & _text,bool _isRoot){
	this->setText(_text);
	this->isRoot=_isRoot;
	this->setToolTip(this->text());
	this->setDragEnabled(true);
	this->setDropEnabled(true);

}
void ParameterItem::set_isRoot(bool _isRoot){
	this->isRoot=_isRoot;
}

ItfOntologyTerm * ParameterItem::get_term(){
	return this->term;
}

void ParameterItem::set_term(ItfOntologyTerm * _term){
	this->term=_term;
}



