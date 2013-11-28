#include "storynode.h"
namespace Xeml {

	namespace Document{
		StoryNode::StoryNode()
		{
			this->childs = new std::list<StoryNode*>();
			this->parent=NULL;
			this->label="";
		}
		void StoryNode::set_label(QString _label){
			this->label=_label;
		}

		StoryNode::StoryNode(StoryBase * st,bool _isStorySplit,QString _mainstoryname){
			this->childs = new std::list<StoryNode*>();
			this->isContainer =false;
			this->isStorySplit=_isStorySplit;
			this->mainStoryName=_mainstoryname;
			this->label = st->get_label();
			this->story=st;
			this->parent=NULL;

		}
		StoryNode::~StoryNode(void){
			std::cerr << "delete story node" << std::endl;
			if(this->isStorySplit){
				delete static_cast<StorySplit*>(this->story);
			}
			else{
				delete static_cast<Story*>(this->story);
			}
			//if(isContainer){
				//for (std::list<StoryNode*>::iterator it=this->childs->begin();it!=this->childs->end();++it){
				//	delete (*it);
				//}
			//}
			this->childs->clear();

		}

		QString                 StoryNode::get_mainStoryName(){
			return this->mainStoryName;
		}

		StoryNode::StoryNode(QString _label){
			this->label=_label;
		}
		QString StoryNode::get_label(){
			return this->label;
		}

		bool StoryNode::get_isContainer(){
			return this->isContainer;
		}

		StoryBase * StoryNode::get_story(){
			return this->story;
		}
		void StoryNode::set_story(StoryBase * _sb){
			this->story=_sb;
		}
		StoryNode * StoryNode::get_parent(){

			if(this->parent!=NULL){
				return this->parent;
			}
			else{
				return NULL;
			}
		}
		void StoryNode::set_parent(StoryNode * _parent){
			this->parent=_parent;
		}

		std::list<StoryNode*> * StoryNode::get_childs(){

			return this->childs;
		}
		void StoryNode::set_childs(std::list<StoryNode *> * _childs){
			this->childs=_childs;
		}

		StoryNode * StoryNode::createContainerStoryNode(QString _label){
			StoryNode * sn = new StoryNode();
			sn->isContainer = true;
			sn->label=_label;
			return sn;
		}

		StoryNode * StoryNode::createStoryNode(StoryBase * st){
			StoryNode * sn = new StoryNode();
			sn->isContainer =false;
			sn->label=st->get_label();
			sn->story=st;
			return sn;
		}

		void StoryNode::addSubStoryNode(StoryNode * st){
			this->childs->push_back(st);
			this->isContainer=true;
			st->parent=this;

		}

		void StoryNode::remove_parent(){
			this->parent=NULL;
		}

		void StoryNode::set_isContainer(bool _isContainer){
			this->isContainer=_isContainer;
		}
		bool StoryNode::get_isRoot(){
			return this->parent==NULL;
		}
		QString StoryNode::get_path(){
			if (this->isRoot){
				return this->label;
			}
			else{
				//maybe use get_path() for the parent to have some recursive search
				return this->parent->get_path()+"."+this->label;
			}
		}
		bool StoryNode::get_isStorySplit(){
			return this->isStorySplit;
		}

		void StoryNode::set_isStorySplit(bool _isStorySplit){
			this->isStorySplit=_isStorySplit;
		}
	}
}




