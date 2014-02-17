#include "sampleidentification.h"
namespace Xeml {

	namespace Document{

		//region SampleIdMapping

		SampleIdMapping::SampleIdMapping(int _sampleId)
		{
			this->sampleId=_sampleId;
			this->FkeyMap=new ForeignKeyMap();
		}
		void SampleIdMapping::set_sampleId(int _sampleId){
			this->sampleId=_sampleId;
		}

		int SampleIdMapping::get_sampleId(){
			return this->sampleId;
		}

		void SampleIdMapping::set_foreignKeyMap(ForeignKeyMap * _fkm){
			this->FkeyMap=_fkm;
		}

		ForeignKeyMap * SampleIdMapping::get_foreignKeyMap(){
			return this->FkeyMap;
		}

		int SampleIdMapping::get_hash_code(){

		}
		std::map<TaggedAnnotation*,QString> * SampleIdMapping::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void SampleIdMapping::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}

		//region ForeignKeyMap

		ForeignKeyMap::ForeignKeyMap(){
			this->innerList=new std::vector<ForeignKeyValue*>();
		}

		int ForeignKeyMap::count(){
			return this->innerList->size();
		}

		void ForeignKeyMap::add(QString _key,QString _val){
			add(_key,_val,false);
		}

		std::vector<ForeignKeyValue*> * ForeignKeyMap::get_inner_list(){
			return this->innerList;
		}

		void ForeignKeyMap::add(QString _key, QString _val,bool _overwriteIfExist){
			if (_key.isNull() || _key.isEmpty()){
				std::cerr << " throw exception null argument" << std::endl;
			}
			if (contains_key(_key)){
				if(_overwriteIfExist){

					findForeignKeyValue(_key)->set_val(_val);
				}
				else{
					std::cerr << "foreign key already exists" << std::endl;
				}
			}
			else{
				std::cerr << "new Foreign Key value created" << std::endl;
				ForeignKeyValue * fkv=new ForeignKeyValue(_key,_val);
				this->innerList->push_back(fkv);

			}

		}

		void ForeignKeyMap::remove(QString _key){
			ForeignKeyValue * toremove=findForeignKeyValue(_key);
			if (toremove != NULL){
				std::vector<ForeignKeyValue*>::iterator it_to_erase;
				for (std::vector<ForeignKeyValue*>::iterator it=this->innerList->begin();it!=this->innerList->end();++it){
					if (static_cast<ForeignKeyValue*>((*it))->get_key()==_key){
						it_to_erase=it;

					}
				}
				this->innerList->erase(it_to_erase);

			}
		}

		void ForeignKeyMap::clear(){
			this->innerList->clear();

		}

		bool ForeignKeyMap::contains_key(QString _key){
			for (std::vector<ForeignKeyValue*>::iterator it=this->innerList->begin();it!=this->innerList->end();++it){
				if (static_cast<ForeignKeyValue*>((*it))->get_key()==_key){
					return true;
				}
			}
			return false;

		}

		QString ForeignKeyMap::convert_to_QString(ForeignKeyMap * _fkm){

		}

		ForeignKeyMap * ForeignKeyMap::convert_from_QString(QString _fkmString){

		}
		ForeignKeyValue * ForeignKeyMap::findForeignKeyValue(QString _key){
			for (std::vector<ForeignKeyValue*>::iterator it=this->innerList->begin();it!=this->innerList->end();++it){
				if (static_cast<ForeignKeyValue*>((*it))->get_key()==_key){
					return (*it);
				}
			}
			return NULL;

		}


		//region ForeignKeyValue

		ForeignKeyValue::ForeignKeyValue(){

		}

		ForeignKeyValue::ForeignKeyValue(QString _key,QString _val){
			this->key=_key;
			this->val=_val;
		}

		void ForeignKeyValue::set_val(QString _val){
			this->val=_val;
		}

		void ForeignKeyValue::set_key(QString _key){
			this->key=_key;
		}

		QString ForeignKeyValue::get_val(){
			return this->val;
		}

		QString ForeignKeyValue::get_key(){
			return this->key;
		}
	}
}
