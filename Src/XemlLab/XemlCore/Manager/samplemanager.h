#ifndef SAMPLEMANAGER_H
#define SAMPLEMANAGER_H

#include"Interface/itfdataprovider.h"
#include"CoreObjects/xemlcomponentloadfailedexception.h"
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Sampling::Contracts;

namespace Xeml{

	namespace Manager{

		class SampleManager
		{
			private:
				SampleManager(){
					this->providerComponent=std::map<QString,Xeml::Sampling::Contracts::ItfDataProvider *>();
					this->messages=new std::vector<QString>();
					init();
				}
				~SampleManager(){ }
			public:
				static SampleManager * Get_sampleManager()
				{
					if (NULL == Instance)
					{
						Instance =  new SampleManager;
					}
					else
					{
						//std::cerr << "singleton already created!" << std::endl;
					}

					return Instance;
				}
				static void kill ()
				{
					if (NULL != Instance)
					{
						delete Instance;
						Instance = NULL;
					}
				}
				void init(){



				}
				std::map<QString,Xeml::Sampling::Contracts::ItfDataProvider *> get_provider(){
					return this->providerComponent;
				}
				std::vector<QString> * get_messages(){
					return this->messages;
				}
				bool contains(QString _uri){
					if (this->providerComponent.find(_uri) != this->providerComponent.end())
					{
						return true;
					}
					else{
						return false;
					}
				}
				ItfDataProvider * createProvider(QString _uri){
					if(this->contains(_uri)){
						ItfDataProvider * ret =NULL;
						try{
							ret=dynamic_cast<ItfDataProvider*>(this->providerComponent[_uri]->copy());
						}
						catch(exception ex)
						{
							throw new XemlComponentLoadFailedException(_uri,"Provider exists, but loading failed");
						}
						return ret;
					}
					else
						throw new XemlComponentLoadFailedException(_uri, "UnknownSample provider.");
				}


			private:
				//variables membres
				std::map<QString,Xeml::Sampling::Contracts::ItfDataProvider *> providerComponent;
				std::vector<QString> * messages;
				static SampleManager  * Instance;


		};
	}
}

#endif // SAMPLEMANAGER_H
