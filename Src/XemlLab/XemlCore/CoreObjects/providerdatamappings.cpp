#include "providerdatamappings.h"
namespace Xeml {
	namespace Document{
		ProviderDataMappings::ProviderDataMappings()
		{
			this->provider=new std::vector< std::pair<QString,std::vector<std::pair<SampleIdMapping*,int> > *> >();
		}
		void ProviderDataMappings::add(QString _key, std::vector<std::pair<SampleIdMapping*,int> > * _dm){

			this->provider->push_back(make_pair( _key,_dm));
		}
		void ProviderDataMappings::clear(){
			this->provider->clear();

		}
		bool ProviderDataMappings::contain_sid(SampleIdMapping * _sid,std::vector<std::pair<SampleIdMapping*,int> > * _sidvector,QString _provider){
			for (std::vector< std::pair<QString,std::vector<std::pair<SampleIdMapping*,int> > *> >::iterator it=this->provider->begin();it!=this->provider->end();++it){
				if(_provider==(*it).first){
					for (std::vector< std::pair<SampleIdMapping*,int> >::iterator it2=(*it).second->begin();it2!=(*it).second->end();++it2){
						if((*it2).second==_sid->get_sampleId()){
							return true;
						}


					}
					return false;
				}
			}
			return false;
		}

		bool ProviderDataMappings::contain_key(QString _key){
			for (std::vector< std::pair<QString,std::vector<std::pair<SampleIdMapping*,int> > *> >::iterator it=this->provider->begin();it!=this->provider->end();++it){
				if(_key==(*it).first){

					return true;
				}
			}
				return false;
		}

		int ProviderDataMappings::count(){
			int counter=0;
			for (std::vector< std::pair<QString,std::vector<std::pair<SampleIdMapping*,int> > *> >::iterator it=this->provider->begin();it!=this->provider->end();++it){
				counter++;
			}
			return counter;
		}
		std::vector< std::pair<QString,std::vector<std::pair<SampleIdMapping*,int> > *> > * ProviderDataMappings::get_provider(){
			return this->provider;
		}
		std::vector<std::pair<SampleIdMapping*,int> > * ProviderDataMappings::get_sample_id_mapping_by_provider(QString _provider){
			for (std::vector< std::pair<QString,std::vector<std::pair<SampleIdMapping*,int> > *> >::iterator it=this->provider->begin();it!=this->provider->end();++it){
				if(_provider==(*it).first){
					return (*it).second;
				}

			}
			return NULL;
		}



		void ProviderDataMappings::remove(QString  _key){

		}
	}
}

