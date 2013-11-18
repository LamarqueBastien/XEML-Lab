#include "itfhierarchicalview.h"
namespace Xeml {

	namespace Document{

		namespace Contracts{
			ItfHierarchicalView::ItfHierarchicalView()
			{}
			//region termNode

			TermNode::TermNode(){
				childs=new std::list<AttributeRelation<TermNode*>*>();
				this->parent=NULL;
				this->isContainer = false;
				this->term=NULL;
			}
			TermNode::TermNode(ItfOntologyTerm * _t){
				childs=new std::list<AttributeRelation<TermNode*>*>();
				this->isContainer = false;
				this->label = _t->get_prototype()->get_name();
				this->term = _t;
			}
			TermNode::TermNode(QString _label){
				Q_UNUSED(_label);
				//childs=new std::list<AttributeRelation<TermNode> >();
			}
			TermNode::~TermNode(void){

			}

			bool TermNode::get_isContainer(){
				return this->isContainer;
			}
			void TermNode::set_isContainer(bool _isContainer){
				this->isContainer=_isContainer;
			}
			ItfOntologyTerm * TermNode::get_term(){
				//if(this->term==NULL){
					//std::cerr << "term NULL"<< std::endl;
				//}
				return this->term;
			}
			void TermNode::set_term(ItfOntologyTerm *_term){
				this->term=_term;
			}
			std::list<AttributeRelation<TermNode*>*> * TermNode::get_childs(){
				return this->childs;
			}
			void TermNode::set_childs(std::list<AttributeRelation<TermNode*>*> * _childs){
				this->childs=_childs;
			}
			TermNode* TermNode::get_parent(){
				return this->parent;
			}
			void TermNode::set_parent(TermNode * _parent){
				this->parent=_parent;
			}
			QString TermNode::get_label(){
				return this->label;
			}
			void TermNode::set_label(QString _label){
				this->label=_label;
			}
			QString TermNode::get_path(){
				if (this->isRoot){
					return this->label;
				}
				else{
					//maybe use get_path() for the parent to have some recursive search
					return this->parent->path+"."+this->label;
				}
			}
			bool TermNode::get_isRoot(){
				return this->parent==NULL;
			}

			TermNode * TermNode::createContainerNode(QString _label)
			{
				TermNode * ret = new TermNode();
				ret->isContainer=true;
				ret->label = _label;
				ret->parent=NULL;
				return ret;
			}
			TermNode * TermNode::createNode(ItfOntologyTerm * _t)
			{
				//std::cerr << "entering create node" << std::endl;
				TermNode *ret = new TermNode(_t);
				ret->isContainer = false;
				//std::cerr << "before get_prototype" << std::endl;
				//std::cerr << "prototype name : " << _t->get_prototype()->get_name().toStdString()<<std::endl;
				ret->label = _t->get_prototype()->get_name();
				//std::cerr << "after get_prototype" << std::endl;
				if (_t==NULL){
					std::cerr << "term null in create node" << std::endl;
				}
				//ret->term = _t;
				ret->parent=NULL;
				return ret;
			}
			void TermNode::addSubNode(TermNode * tn, QString attribute)
			{
				//std::cerr << "entering addsubnode : " << tn->get_term()->get_termId().toStdString() << std::endl;
				//std::cerr << "entering addsubnode term label: " << tn->get_label().toStdString() << std::endl;
				AttributeRelation<TermNode*>  * tmprel=new AttributeRelation<TermNode*>(attribute, tn);
				//std::cerr << (*tmprel->get_relation())->get_label().toStdString() << std::endl;
				this->childs->push_back(tmprel);
				tn->parent = this;
			}
			void TermNode::removeParent()
			{
				this->parent = NULL;
			}
			//end region termNode

			//Region Attribute relation

			template <typename T> AttributeRelation<T>::AttributeRelation(QString _attribute, T  _relation){
				//std::cerr << "new attribute relation" << std::endl;
				this->attribute=_attribute;
				this->relation=_relation;
			}
			template <typename T>QString AttributeRelation<T>::get_attribute(){
				return this->attribute;
			}

			template <typename T> T  AttributeRelation<T>::get_relation(){
				return this->relation;
			}

			template <typename T> void AttributeRelation<T>::set_attribute(QString _attribute){
				this->attribute=_attribute;
			}

			template <typename T> void AttributeRelation<T>::set_relation(T  _relation){
				this->relation=_relation;
			}
		}
	}
}




