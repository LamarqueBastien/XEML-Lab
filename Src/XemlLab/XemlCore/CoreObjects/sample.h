#ifndef SAMPLE_H
#define SAMPLE_H

#include<iostream>
#include<vector>
#include "CoreObjects/observationpoint.h"
#include "CoreObjects/partition.h"

#include<QDateTime>

using namespace Xeml::Document;
using namespace std;

namespace Xeml {
	namespace Document{
		class Sample : public XemlAnnotableObject
		{
			public:
				Sample();
				QDateTime get_time_point();
				void set_timepoint(QDateTime _cached_time);
				int get_id();
				void set_id(int _id);
				std::vector<Partition*> * get_partitions();
				void add_partition(Partition * _part);
				void remove_partition(Partition * _part);
				void clear_partition();
				std::map<TaggedAnnotation*,QString>                  * get_taggedannotation();
				void                                                   add_tagged_annotation(TaggedAnnotation *TA);

			private:
				int id;

				QDateTime cached_time;
				std::vector<Partition*> * partitions;
				std::vector<ObservationPoint*> * owning_ObsPoint;
				void calc_owning_obspoint();



		};
	}
}

#endif // SAMPLE_H
