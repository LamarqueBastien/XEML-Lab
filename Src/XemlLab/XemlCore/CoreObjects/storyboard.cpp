#include "storyboard.h"
namespace Xeml {

	namespace Document{
		StoryBoard::StoryBoard()
		{
			this->storyBoard =new std::list<StoryNode*>();
		}
		StoryBoard::~StoryBoard(void){

		}

		void StoryBoard::add_Node(StoryNode * _sn){
			this->storyBoard->push_back(_sn);
		}
		void StoryBoard::add_Node(StoryNode * _parent,StoryNode * _son){
			this->storyBoard->push_back(_son);
			if(this->findNode_by_Label(_parent->get_story()->get_label(),_son->get_mainStoryName())!=NULL){
				this->findNode_by_Label(_parent->get_story()->get_label(),_son->get_mainStoryName())->addSubStoryNode(_son);
			}
		}
		/*
		QDateTime   StoryBoard::get_obs_time(){
			return this->observationTime;
		}

		void StoryBoard::set_obs_time(QDateTime  _time){
			this->observationTime= _time;
		}
		*/

		std::list<StoryNode*> * StoryBoard::get_storyBoard(){
			return this->storyBoard;
		}
		void StoryBoard::set_storyBoard(std::list<StoryNode*> * _storyBoard){
			this->storyBoard=_storyBoard;
		}
		StoryNode* StoryBoard::findNode_by_Label(QString _label,QString _mainstoryname){
			for(std::list<StoryNode*>::iterator it =this->storyBoard->begin();it!=this->storyBoard->end();++it){
				if((*it)->get_story()->get_label()==_label&& (*it)->get_mainStoryName()==_mainstoryname){
					std::cerr << "node found :" <<  (*it)->get_story()->get_label().toStdString() << std::endl;
					return (*it);
				}
			}
			return NULL;
		}

		StoryNode* StoryBoard::findNode(StoryBase * _sb){
			return this->findNode(_sb->get_label());
		}

		StoryNode* StoryBoard::findNode(QString _label){
			for(std::list<StoryNode*>::iterator it =this->storyBoard->begin();it!=this->storyBoard->end();++it){
				if(findNode((*it),_label)!=NULL){
					return findNode((*it),_label);
				}
			}
			return NULL;
		}

		StoryNode* StoryBoard::findNode(StoryNode * start,QString _label){
			StoryNode * ret = NULL;
			/*
			if (start==NULL){
				std::cerr << "start is null " << std::endl;
			}
			else{
				std::cerr << "start is not null " <<_label.toStdString()<< std::endl;
			}
			*/
			if(start->get_story()->get_label()==_label){

				ret=start;
			}
			else{
				for(std::list<StoryNode*>::iterator it =start->get_childs()->begin();it!=start->get_childs()->end();++it){
					if(findNode((*it),_label)!=NULL){

						ret=findNode((*it),_label);
					}
				}
			}
			/*
			if(ret==NULL){
				std::cerr << "ret is null" << std::endl;
			}
			*/
			return ret;
		}
	}
}

