#ifndef PARTITION_H
#define PARTITION_H
#include<map>
#include"basicterm.h"
#include"xemlannotableobject.h"
#include"variableterm.h"
using namespace std;
namespace Xeml{

	namespace Document{
		class Partition : public XemlAnnotableObject
		{
			private:
				int                                       id;
				std::map<BasicTerm*,QString>        * materialCollection;
				std::map<BasicTerm*,QString>        * positionCollection;

			public:
				Partition();
				~Partition();
				Partition(Partition & p);
				void                                      addMaterialTerm(BasicTerm * _term);
				void                                      addPositionTerm(BasicTerm * _term);
				int                                       get_id();
				void                                      set_id(int _id);
				std::map<BasicTerm*,QString>        * get_materialCollection();
				std::map<BasicTerm*,QString>        * get_positionCollection();
				std::map<TaggedAnnotation*,QString> * get_taggedannotation();
				void                                      add_tagged_annotation(TaggedAnnotation *TA);

		};
	}
}

#endif // PARTITION_H
