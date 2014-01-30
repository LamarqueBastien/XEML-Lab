#include "sampleidentification.h"
namespace Xeml {

	namespace Document{

		//region SampleIdMapping

		SampleIdMapping::SampleIdMapping(int _sampleId)
		{

		}
		void SampleIdMapping::set_sampleId(int _sampleId){

		}

		int SampleIdMapping::get_sampleId(){

		}

		void SampleIdMapping::set_foreignKeyMap(ForeignKeyMap * _fkm){

		}

		ForeignKeyMap * SampleIdMapping::get_foreignKeyMap(){

		}

		int SampleIdMapping::get_hash_code(){

		}

		//region ForeignKeyMap

		ForeignKeyMap::ForeignKeyMap(){

		}

		int ForeignKeyMap::count(){

		}

		void ForeignKeyMap::add(QString _key,QString _val){

		}

		void ForeignKeyMap::add(QString _key, QString _val,bool _overwriteIfExist){

		}

		void ForeignKeyMap::remove(QString _key){

		}

		void ForeignKeyMap::clear(){

		}

		bool ForeignKeyMap::contains_key(QString _key){

		}

		QString ForeignKeyMap::convert_to_QString(ForeignKeyMap * _fkm){

		}

		ForeignKeyMap * ForeignKeyMap::convert_from_QString(QString _fkmString){

		}


		//region ForeignKeyValue

		void ForeignKeyValue::set_val(QString _val){

		}

		void ForeignKeyValue::set_key(QString _key){

		}

		QString ForeignKeyValue::get_val(){

		}

		QString ForeignKeyValue::get_key(){

		}
	}
}
