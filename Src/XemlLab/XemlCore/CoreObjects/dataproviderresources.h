#ifndef DATAPROVIDERRESOURCES_H
#define DATAPROVIDERRESOURCES_H
#include<iostream>
#include"Interface/itfdataprovider.h"
#include"CoreObjects/componentloadstate.h"
#include"CoreObjects/xemlcomponentloadfailedexception.h"
#include"Manager/samplemanager.h"
using namespace std;
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Sampling::Contracts;
using namespace Xeml::Manager;
//using Xeml::Sampling::Contracts::ItfDataProvider;

namespace Xeml{

	namespace Document{

		class DataProviderResources
		{
			public:
				DataProviderResources();
				QString get_uri();
				void set_uri(QString _uri);
				QString get_friendly_name();
				void set_friendly_name(QString _name);
				ItfDataProvider * get_data_provider();
				ComponentLoadState get_component_state();
				void set_component_state(ComponentLoadState _compstate);
				void load_component(QString _uri);

			private:
				QString friendlyName;
				ItfDataProvider * provider;
				ComponentLoadState compState;
				QString uri;
		};
	}
}

#endif // DATAPROVIDERRESOURCES_H
