#ifndef INDIVIDUALSPOOL_H
#define INDIVIDUALSPOOL_H
#include<QString>
#include<map>
#include<iostream>
#include<string>
#include"individual.h"
#include"xemlannotableobject.h"
#include<QStringList>
namespace Xeml {

	namespace Document{
		class IndividualsPool : public XemlAnnotableObject
		{
			private:
				QString                                   ns;
				QString                                   germplasm;
				QString                                   FqName;
				std::map<Individual*,int> *               individualscollection;
				std::map<Individual*,int>::iterator       it;
			public:
				IndividualsPool();
				~IndividualsPool();
				void                                      add_Individual(Individual * _individual);
				void                                      remove_Individual(int _individualId);
				void                                      display_all_individuals();
				int                                       count_individuals();
				std::map<Individual*,int> *               get_individualscollection();
				std::map<Individual*,int>::iterator       get_iterator();
				QString                                   get_ns();
				void									  set_ns(QString _nameSpace);
				QString                                   get_germplasm();
				void									  set_germplasm(QString _germplasm);
				std::map<TaggedAnnotation*,QString> * get_taggedannotation();
				void                                      add_tagged_annotation(TaggedAnnotation *TA);
				QString								      getFqName();
				void									  setFqName(QString _fqName);
				QString									  buildFqName(QString _namespace,QString name);
				Individual *                              find(int _Id);
		};
	}
}

#endif // INDIVIDUALSPOOL_H
