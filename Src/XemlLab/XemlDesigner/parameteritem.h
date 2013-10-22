#ifndef PARAMETERITEM_H
#define PARAMETERITEM_H
#include<QStandardItem>
#include"termattribute.h"
#include"itfontologyterm.h"
#include"basicterm.h"
#include "itfhierarchicalview.h"

using Xeml::Document::BasicTerm;
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;


#include"term.h"

typedef enum
  {
   Parameter = QStandardItem::UserType + 1
  }Type;
class ParameterItem : public QStandardItem
{
	private:
		ItfOntologyTerm * term;
	public:

		typedef enum
		  {
			NameRole = Qt::UserRole+1,
			PathRole,
			HashRole,
			SizeRole,
			SizeTextRole,
			SubdirRole,
			SubdirTextRole
		  }Roles;

		typedef enum
		  {
		   Parameter = QStandardItem::UserType + 1
		  }Type;


		ParameterItem(const QString &,ItfOntologyTerm * _term);
		ParameterItem(QString _namespace,TermNode * _node,const QString &,ItfOntologyTerm * _term,bool _isRoot);
		explicit ParameterItem(TermNode * _node,const QString & _text,bool _isRoot);
		ItfOntologyTerm * get_term();
		void              set_term(ItfOntologyTerm * _term);
		void              set_isRoot(bool _isRoot);
		bool              isRoot;
		int               type() const { return Parameter; }



};

#endif // PARAMETERITEM_H
