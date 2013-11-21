#ifndef ITFHIERARCHICALVIEW_H
#define ITFHIERARCHICALVIEW_H
#include"itfontologyterm.h"
using namespace std;
#include<list>
namespace Xeml {

	namespace Document{

		namespace Contracts{



			template <typename T>

			class AttributeRelation
			{
				public :
					AttributeRelation(QString _attribute, T  _relation);
					QString                                    attribute;
					QString                                    get_attribute();
					T                                          relation;
					T                                          get_relation();




				private:
					void                                       set_attribute(QString _attribute);
					void                                       set_relation(T  _relation);
			};


			class TermNode
			{

				public:
					TermNode(ItfOntologyTerm * _t);
					TermNode(QString _label);
					~TermNode();

					bool                                       isContainer;
					ItfOntologyTerm *                          term;
					TermNode*                                  parent;
					QString                                    label;
					bool                                       isRoot;
					QString                                    path;
					bool                                       get_isContainer();
					ItfOntologyTerm *                          get_term();
					std::list<AttributeRelation<TermNode*>*> * get_childs();
					TermNode*                                  get_parent();
					void                                       set_parent();
					QString                                    get_label();
					void                                       set_label(QString _label);
					QString                                    get_path();
					bool                                       get_isRoot();
					static TermNode                          * createContainerNode(QString _label);
					static TermNode                          * createNode(ItfOntologyTerm * _t);
					void                                       addSubNode(TermNode * tn, QString attribute);
					void                                       removeParent();
					void                                       set_isContainer(bool _isContainer);
					//void SortChildren(Comparison<AttributedRelation<TermNode>> comparison)
					//static int CompareAttributedRelationByTermNodeLabel(AttributedRelation<TermNode> x, AttributedRelation<TermNode> y)
					//static int CompareTermNodeByLabel(TermNode x, TermNode y)

				private:
					TermNode();
					//void                                       set_isContainer(bool _isContainer);
					void                                       set_term(ItfOntologyTerm *_term);
					void                                       set_childs(std::list<AttributeRelation<TermNode*>*> * _childs);
					void                                       set_parent(TermNode * _parent);
					std::list<AttributeRelation<TermNode*>*> * childs;
					//static bool                                             isContainer;
					//static ItfOntologyTerm *                                       term;
					//static QString                                                label;
			};

			class ItfHierarchicalView
			{
				public:
					ItfHierarchicalView();
					//std::list<TermNode*>                       Nodes;
					virtual TermNode*                          findNode_by_id(QString termId)=0;
					virtual TermNode*                          findNode(ItfOntologyTerm *t)=0;
					virtual TermNode*                          findNode(QString termId)=0;
					virtual TermNode*                          findNode(TermNode * start,QString termId)=0;
					virtual std::list<TermNode*>             * get_listNodes()=0;
			};


		}
	}
}

#endif // ITFHIERARCHICALVIEW_H
