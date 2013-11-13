#ifndef STORY_H
#define STORY_H
#include<string>
#include<map>
#include"storybase.h"
#include"individualspool.h"

namespace Xeml {

	namespace Document{


		class Story : public StoryBase
		{
			private:
				std::map<IndividualsPool*,QString> *         individualspoolcollection;
				std::map<IndividualsPool*,QString>::iterator iter;


			public:
				Story();
				Story(QString _label);
				~Story();
				QString                                      get_label();
				void											 set_label(QString _label);
				void                                             add_individualspool(IndividualsPool * _individualspool);
				void                                             display_all_individualspools();
				std::map<IndividualsPool*,QString> *         get_individualspoolcollection();
				IndividualsPool *								 find(QString _fullname);

		};
	}
}

#endif // STORY_H