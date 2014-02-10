#ifndef SAMPLEIDENTIFICATION_H
#define SAMPLEIDENTIFICATION_H
#include "CoreObjects/partition.h"
#include<iostream>
#include<vector>
using namespace Xeml::Document;
using namespace std;

//class Xeml::Document::ForeignKeyMap;
//class Xeml::Document::ForeignKeyValue;

namespace Xeml {

	namespace Document{

		class ForeignKeyValue
		{
			public:
				ForeignKeyValue();
				ForeignKeyValue(QString _key,QString _val);
				void set_val(QString _val);
				void set_key(QString _key);
				QString get_val();
				QString get_key();

			private:
				QString key;
				QString val;
		};
		class ForeignKeyMap
		{
			public:
				ForeignKeyMap();
				int count();
				void add(QString _key,QString _val);
				void add(QString _key, QString _val,bool _overwriteIfExist);
				void remove(QString _key);
				void clear();
				bool contains_key(QString _key);


				QString convert_to_QString(ForeignKeyMap * _fkm);
				ForeignKeyMap * convert_from_QString(QString _fkmString);
			private:
				std::vector<ForeignKeyValue*> * innerList;
				ForeignKeyValue * findForeignKeyValue(QString _key);
		};
		class SampleIdMapping : public XemlAnnotableObject
		{
			public:
				SampleIdMapping(int _sampleId);
				void set_sampleId(int _sampleId);
				int get_sampleId();
				void set_foreignKeyMap(ForeignKeyMap * _fkm);
				ForeignKeyMap * get_foreignKeyMap();
				int get_hash_code();
				std::map<TaggedAnnotation*,QString> * get_taggedannotation();
				void add_tagged_annotation(TaggedAnnotation *TA);


			private:
				int sampleId;
				ForeignKeyMap * FkeyMap;
				std::vector<std::pair< SampleIdMapping*,int> > * dataMappingCollection;

		};


	}
}

#endif // SAMPLEIDENTIFICATION_H
