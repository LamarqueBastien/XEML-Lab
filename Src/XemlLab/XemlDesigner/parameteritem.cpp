#include "parameteritem.h"

ParameterItem::ParameterItem(const QString & _text,ItfOntologyTerm * _term){
	this->setText(_text+" ("+_term->get_prototype()->get_termId()+")");
	this->term=_term;

	//problem with setToolTip and XeoPositionning ontology
	//this->setToolTip(this->term->get_definition());
	this->setBackground(QBrush(Qt::white));

}
ParameterItem::ParameterItem(QString _namespace,TermNode * _node,const QString & _text,ItfOntologyTerm * _term,bool _isRoot){
	//std::cerr << "entering parameter item" << std::endl;
	this->term=_term;
	if (_term==NULL || _namespace=="XEO_Positioning"){
		this->setText(_node->get_label());
		//std::cerr << "text : " << _node->get_label().toStdString() << std::endl;
	}
	else{
		this->setToolTip(this->term->get_definition());
		this->setText(_text+" ("+_term->get_prototype()->get_termId()+")");
	}
	//this->term=_term;
	this->isRoot=_isRoot;
	//this->setToolTip(this->term->get_definition());
}

ParameterItem::ParameterItem(TermNode * _node,const QString & _text,bool _isRoot){
	this->setText(_text);
	this->isRoot=_isRoot;
	this->setToolTip(this->text());

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



