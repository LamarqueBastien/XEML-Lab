#ifndef ONTOLOGYHANDLERRESOURCES_H
#define ONTOLOGYHANDLERRESOURCES_H
#include<string>
#include"Interface/itfontologyhandler.h"
#include"CoreObjects/componentloadstate.h"
#include"Manager/ontologymanager.h"
#include<exception>
#include<QString>
using Xeml::Manager::OntologyManager;
using Xeml::Document::Contracts::ItfOntologyHandler;
using namespace Xeml::Manager;
using namespace std;

namespace Xeml{

	namespace Document{

		class OntologyHandlerResources
		{
			private:
				//region fields
				QString                                     nameSpace;
				QString                                     location;
				QString                                     uri;
				int                                             calCount;
				Xeml::Document::Contracts::ItfOntologyHandler * handler;
				Xeml::Document::ComponentLoadState              compstate;

			public:
				//region constructors
				OntologyHandlerResources(QString _uri);
				~OntologyHandlerResources();

				//region properties
				QString get_uri();
				Xeml::Document::Contracts::ItfOntologyHandler * get_handler();
				ComponentLoadState                              get_component_state();
				void                                            set_component_state( ComponentLoadState _value );
				QString                                         get_namespace();
				void                                            set_namespace( QString _namespace );
				QString                                         get_location();
				void                                            set_location( QString _location );
				//region methods
				void                                            loadOntology();
				void                                            loadComponent();

		};
	}
}

#endif // ONTOLOGYHANDLERRESOURCES_H
