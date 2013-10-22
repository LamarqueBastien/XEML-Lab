#ifndef OBSERVATIONPOINT_H
#define OBSERVATIONPOINT_H
#include<QString>
#include<map>
#include<vector>
#include<iostream>
#include<string>
#include"xemlannotableobject.h"
#include"itftimeobject.h"
#include"observation.h"
#include "timespan.h"
#include<QDateTime>


using std::make_pair;
using std::pair;
using namespace Xeml::Document::Contracts;
namespace Xeml{

	namespace Document{
		class ObservationPoint : public XemlAnnotableObject, public ItfTimeObject
		{
			private:
				int                                        id;
				QDateTime                                  timepoint;
				std::vector<pair<Observation*,QDateTime> >         * observationscollection;
				std::vector<pair<Observation*,QDateTime> >::iterator it;
			public:
				ObservationPoint();
				~ObservationPoint();
				ObservationPoint(QDateTime _timepoint);
				QDateTime                                  get_timepoint();
				void                                       set_timepoint(QDateTime _timepoint);
				void                                       add_observation(Observation * _observation);
				int                                        count_observations();
				void                                       display_all_observations();

				std::vector<pair<Observation*,QDateTime> >         * get_observationscollection();
				std::vector<pair<Observation*,QDateTime> >::iterator get_iterator();

				std::map<TaggedAnnotation*,QString>   * get_taggedannotation();
				void                                        add_tagged_annotation(TaggedAnnotation *TA);
				int                                         get_id();
				void                                        set_id(int _id);
		};
	}
}

#endif // OBSERVATIONPOINT_H
