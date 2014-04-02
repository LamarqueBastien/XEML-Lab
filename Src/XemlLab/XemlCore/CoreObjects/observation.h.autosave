#ifndef OBSERVATION_H
#define OBSERVATION_H
#include"xemlannotableobject.h"
#include"timespan.h"
#include<QDateTime>
#include"individualspool.h"
#include"partition.h"
#include"variableterm.h"
#include<ctime>

namespace Xeml {

	namespace Document{

		class Observation : public XemlAnnotableObject
		{
			private:
				//int                                       id;
				//QDateTime                                * timepoint;
				QDateTime                                 duration;
				bool                                      destructive;
				bool                                      individualInfluence;
				std::map<Partition*,int>                * partitions;
				std::map<BasicTerm*,QString>            * devStage;
				IndividualsPool                         * individualsPool;
				Individual                              * individual;
			public:
				Observation();
				~Observation();
				int                                       get_id();
				void                                      set_id(int _id);
				bool                                      get_individualInfluence();
				void                                      set_individualInfluence(bool iI);
				bool                                      get_destructiveinfo();
				void                                      set_destructiveinfo(bool info);
				QDateTime                                 get_duration();
				void                                      set_duration(QDateTime  tv);
				IndividualsPool                         * get_pool();
				void                                      set_pool(IndividualsPool * ip);
				Individual                              * get_ind();
				void                                      set_ind(Individual * i);
				bool                                      contain_partition(Partition * _p);
				bool                                      contain_stages(QString _id);
				std::map<BasicTerm*,QString>            * get_stageCollection();
				void                                      add_stage(BasicTerm * _term);
				std::map<Partition*,int>                * get_partitionCollection();
				void                                      add_partition(Partition * _p);
				std::map<TaggedAnnotation*,QString> * get_taggedannotation();
				void                                      add_tagged_annotation(TaggedAnnotation *TA);



		};
	}
}

#endif // OBSERVATION_H

