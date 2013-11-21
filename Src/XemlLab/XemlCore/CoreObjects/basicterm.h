#ifndef BASICTERM_H
#define BASICTERM_H
#include<string>
#include<QString>
#include"xemlannotableobject.h"


namespace Xeml {

	namespace Document{

		class BasicTerm : public XemlAnnotableObject
		{
			private:
				QString                                 nameSpacealias;
				QString                                 nameSpace;
				QString                                 name;
				QString                                 termId;
			public:
				BasicTerm();
				~BasicTerm();
				BasicTerm( QString _termId );
				BasicTerm( QString _termId,QString _namespace,QString _namespacealias );
				BasicTerm( const BasicTerm& term );
				QString                                 get_namespacealias();
				QString                                 get_namespace();
				QString                                 get_name();
				QString                                 get_termId();
				void                                    set_namespacealias(QString _namespacealias);
				void                                    set_namespace(QString _namespace);
				void                                    set_name(QString _name);
				void                                    set_termId(QString _termId);
				std::map<TaggedAnnotation*,QString>  * get_taggedannotation();
				void                                    add_tagged_annotation(TaggedAnnotation *TA);

		};
	}
}


#endif // BASICTERM_H
