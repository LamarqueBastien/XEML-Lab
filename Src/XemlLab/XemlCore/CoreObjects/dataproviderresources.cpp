#include "dataproviderresources.h"

namespace Xeml{

	namespace Document{
		DataProviderResources::DataProviderResources()
		{
			this->compState= Xeml::Document::Untouched;
		}
		QString DataProviderResources::get_uri(){
			return this->uri;
		}

		void DataProviderResources::set_uri(QString _uri){
			this->uri=_uri;
		}

		QString DataProviderResources::get_friendly_name(){
			return this->friendlyName;
		}

		void DataProviderResources::set_friendly_name(QString _name){
			this->friendlyName=_name;
		}

		ItfDataProvider * DataProviderResources::get_data_provider(){
			return this->provider;
		}

		ComponentLoadState DataProviderResources::get_component_state(){
			return this->compState;
		}

		void DataProviderResources::set_component_state(ComponentLoadState _compstate){
			this->compState=_compstate;
		}
		void DataProviderResources::load_component(QString _uri){
			this->uri=_uri;
			if(this->compState!=Xeml::Document::Loaded){
				try{
					if( SampleManager::Get_sampleManager()->get_provider().find(_uri)==SampleManager::Get_sampleManager()->get_provider().end()){
						this->provider = SampleManager::Get_sampleManager()->createProvider(this->uri);
						this->compState=Xeml::Document::Loaded;
					}
					else{
						this->compState=Xeml::Document::UnknownComponent;
					}

				}
				catch(XemlComponentLoadFailedException){
					this->compState=Xeml::Document::Failed;
				}
			}
		}
	}
}
