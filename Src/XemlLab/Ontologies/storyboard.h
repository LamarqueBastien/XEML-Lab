#ifndef STORYBOARD_H
#define STORYBOARD_H
#include"storynode.h"
#include"timespan.h"
#include<QDateTime>
//#include"itfdocument.h"
//using namespace Xeml::Document::Contracts;
//using Xeml::Document::Contracts::ItfDocument;

namespace Xeml {

	namespace Document{

		class StoryBoard
		{
			public:
				StoryBoard();
				~StoryBoard();

				void                    add_Node(StoryNode * _sn);
				void                    add_Node(StoryNode * _parent,StoryNode * _son);
				//QDateTime               get_obs_time();
				//void                    set_obs_time(QDateTime   _time);
				std::list<StoryNode*> * get_storyBoard();

				StoryNode             * findNode_by_Label(QString _label,QString _mainstoryname);
				StoryNode             * findNode(StoryBase * _sb);
				StoryNode             * findNode(QString _label);
				StoryNode             * findNode(StoryNode * start,QString _label);

			private:

				std::list<StoryNode*> * storyBoard;
				void                    set_storyBoard(std::list<StoryNode*> * storyBoard);
				//QDateTime               observationTime;

		};
	}
}

#endif // STORYBOARD_H
