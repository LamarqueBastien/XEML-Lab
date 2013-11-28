#ifndef STORYNODE_H
#define STORYNODE_H
#include"storybase.h"
#include"story.h"
#include"storysplit.h"
#include<QString>
#include<list>
using namespace Xeml::Document;
namespace Xeml {

	namespace Document{

		class StoryNode
		{
			public:

				StoryNode(StoryBase * st,bool _isStorySplit,QString _mainstoryname);
				StoryNode(QString _label);
				~StoryNode();
				bool                    isContainer;
				StoryBase             * story;
				StoryNode             * parent;
				QString                 label;
				bool                    isRoot;
				bool                    isStorySplit;
				QString                 mainStoryName;
				QString                 path;
				QString                 get_mainStoryName();
				bool                    get_isStorySplit();
				bool                    get_isRoot();
				bool                    get_isContainer();
				QString                 get_label();
				void                    set_label(QString _label);
				StoryBase             * get_story();
				StoryNode             * get_parent();
				std::list<StoryNode*> * get_childs();
				static StoryNode      * createContainerStoryNode(QString _label);
				static StoryNode      * createStoryNode(StoryBase * st);
				void                    addSubStoryNode(StoryNode * st);
				void                    remove_parent();
				QString                 get_path();

			private:

				StoryNode();

				void                    set_isStorySplit(bool _isStorySplit);
				void                    set_isContainer(bool _isContainer);
				void                    set_story(StoryBase * sb);
				void                    set_childs(std::list<StoryNode *> * _childs);
				void                    set_parent(StoryNode * _parent);
				std::list<StoryNode*> * childs;





		};
	}
}

#endif // STORYNODE_H
