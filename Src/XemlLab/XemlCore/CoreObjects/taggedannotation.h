#ifndef TAGGEDANNOTATION_H_
#define TAGGEDANNOTATION_H_
#include<QString>
namespace Xeml {

	namespace Document{
		class TaggedAnnotation {
			private:
				QString _tag;
				QString _annotation;

			public:
				TaggedAnnotation();
				TaggedAnnotation(QString tag);
				TaggedAnnotation(QString tag, QString anno);
				~TaggedAnnotation();
				QString getAnnotation() const;
				void        setAnnotation(QString anno);
				QString getTag() const;
				void        setTag(QString tag);

		};
	}
}

#endif // TAGGEDANNOTATION_H
