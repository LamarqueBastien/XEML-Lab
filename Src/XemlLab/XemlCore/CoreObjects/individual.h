#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include"xemlannotableobject.h"

#include"CoreObjects/xemlannotableobject.h"
#include"Interface/itftimeobject.h"

namespace Xeml {

	namespace Document{

		class Individual : public XemlAnnotableObject
		{
			private:
				int                                       id;
				bool                                      IsDestroyed;
				QDateTime                                 harvest_datetime;
			public:
				Individual();
				~Individual();
				Individual(int id);
				void                                      set_harvest_datetime(QDateTime _harvest_datetime);
				QDateTime                                 get_harvest_datetime();
				bool                                      is_destroyed();
				void                                      set_is_destroyed(bool _IsDestroyed);

				int                                       get_id();
				void                                      set_id(int _id);
				std::map<TaggedAnnotation*,QString> * get_taggedannotation();
				void                                      add_tagged_annotation(TaggedAnnotation *TA);
		};
	}
}

#endif // INDIVIDUAL_H
