#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include"xemlannotableobject.h"
namespace Xeml {

	namespace Document{

		class Individual : public XemlAnnotableObject
		{
			private:
				int                                       id;
			public:
				Individual();
				~Individual();
				Individual(int id);
				int                                       get_id();
				void                                      set_id(int _id);
				std::map<TaggedAnnotation*,QString> * get_taggedannotation();
				void                                      add_tagged_annotation(TaggedAnnotation *TA);
		};
	}
}

#endif // INDIVIDUAL_H
