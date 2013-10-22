#ifndef EXPERIMENTHEADER_H
#define EXPERIMENTHEADER_H
#include"experimenter.h"
#include"keyword.h"
#include<QString>
#include<string>
#include<list>
namespace Xeml {

	namespace Document{
		class ExperimentHeader
		{
			private:
				Experimenter                  * experimenter;
				QString                         summary;
				std::list<Keyword*>::iterator   iter;
				std::list<Keyword*>           * keywords ;


			public:
				ExperimentHeader();
				~ExperimentHeader();
				Experimenter                  * get_experimenter();
				QString                         get_summary();
				std::list<Keyword*>::iterator   get_iterator();
				void add_keyword(Keyword      * _keyword);
				void                            set_summary(QString _summary);
				std::list<Keyword*>           * get_keywords();
		};
	}
}

#endif // EXPERIMENTHEADER_H
