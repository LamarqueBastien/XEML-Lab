#ifndef SAMPLEMANAGER_H
#define SAMPLEMANAGER_H

#include"Interface/itfdataprovider.h"
#include"CoreObjects/xemlcomponentloadfailedexception.h"
#include"SQLDataProvider/platodataprovider.h"
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Sampling::Contracts;
using namespace XemlDataProvider;

namespace Xeml{

	namespace Manager{

		class SampleManager
		{
			private:
				SampleManager(){
					this->providerComponent=new std::map<QString,Xeml::Sampling::Contracts::ItfDataProvider *>();
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
					XemlDataProvider::PlatoDataProvider * pdp= new PlatoDataProvider();
					(*this->providerComponent)[pdp->get_uri()]=pdp;




				}
				std::map<QString,ItfDataProvider *>  * get_provider(){
					return this->providerComponent;
				}
				std::vector<QString> * get_messages(){
					return this->messages;
				}
				bool contains(QString _uri){
					if (this->providerComponent->find(_uri) != this->providerComponent->end())
					{
						return true;
					}
					else{
						return false;
					}
				}

				ItfDataProvider * createProvider(QString _uri){
					if(this->contains(_uri)){
						std::cerr << "uri is contained is this dataproviderresources " << std::endl;
						ItfDataProvider * ret =NULL;
						try{
							ret=dynamic_cast<ItfDataProvider*>((*this->providerComponent)[_uri]->copy());
						}
						catch(exception ex)
						{
							throw new XemlComponentLoadFailedException(_uri,"Provider exists, but loading failed");
						}
						return ret;
					}
					else
						std::cerr << "UnknownSample provider - not contained is this dataproviderresources " << std::endl;

						//throw new XemlComponentLoadFailedException(_uri, "UnknownSample provider.");
					return NULL;
				}



			private:
				//variables membres
				std::map<QString,Xeml::Sampling::Contracts::ItfDataProvider *> * providerComponent;
				std::vector<QString> * messages;
				static SampleManager  * Instance;


		};
	}
}

#endif // SAMPLEMANAGER_H
