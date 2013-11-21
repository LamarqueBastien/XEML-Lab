#ifndef XEMLANNOTABLEOBJECT_H
#define XEMLANNOTABLEOBJECT_H
#include<map>
#include<iostream>
#include<QString>
#include"taggedannotation.h"
namespace Xeml {

	namespace Document{

		class XemlAnnotableObject
		{
			protected:
				std::map<TaggedAnnotation*,QString> *         TaggedannotationCollection;
				std::map<TaggedAnnotation*,QString>::iterator it;
			public:

				XemlAnnotableObject();
				virtual ~XemlAnnotableObject();
				//XemlAnnotableObject(const XemlAnnotableObject &xao);
				virtual std::map<TaggedAnnotation*,QString> * get_taggedannotation()=0;
				virtual void                                      add_tagged_annotation(TaggedAnnotation *TA)=0;
				void                                              display_all_tags();
				void                                              display_specific_tag(TaggedAnnotation* TA);
				bool                                              contains(TaggedAnnotation* TA);
				bool											  contain(QString _tag);
		};
	}
}

#endif // XEMLANNOTABLEOBJECT_H
