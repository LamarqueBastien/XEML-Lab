#ifndef STORYITEM_H
#define STORYITEM_H
#include"abstractexperimentitem.h"
#include<QStandardItem>
#include"CoreObjects/termattribute.h"
#include"Interface/itfontologyterm.h"
#include"CoreObjects/basicterm.h"
#include"CoreObjects/story.h"

using Xeml::Document::BasicTerm;
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;




//typedef enum
//  {
//   Parameter = QStandardItem::UserType + 1
//  }Type;
class StoryItem : public AbstractExperimentItem
{
	private:
		StoryBase            * story;
		list<ItfOntologyTerm*> terms;
		bool                   isroot;
		bool                   isStorySplit;

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
		   StoryType = QStandardItem::UserType + 1
		  }Type;

		StoryItem(const QString &,StoryBase * st,bool _isStorySplit,bool _isRoot);
		StoryItem(const QString & _text,bool _isRoot);
		bool                   isRoot();
		int                    type() const { return StoryType; }
		void                   add_term(ItfOntologyTerm* _term);
		ItfOntologyTerm      * get_term(QString _termId);
		StoryBase            * get_story();
		bool                   get_isStorySplit();


};
#endif // STORYITEM_H
