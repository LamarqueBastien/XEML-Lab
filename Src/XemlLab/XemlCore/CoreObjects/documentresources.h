#ifndef DOCUMENTRESOURCES_H
#define DOCUMENTRESOURCES_H
#include<map>
#include"ontologyhandlerresources.h"
#include"CoreObjects/dataproviderresources.h"
//#include"itfdocument.h"
using namespace std;
#include<exception>
using namespace Xeml::Document::Contracts;
using Xeml::Document::ComponentLoadState;
using Xeml::Document::Contracts::OntologyType;
using Xeml::Document::Contracts::OntologyLoadState;
//using Xeml::Document::Contracts::ItfDocument;
using Xeml::Document::OntologyHandlerResources;
namespace Xeml{

	namespace Document{

		class DocumentResources
		{

			private:
				//Xeml::Document::Contracts::ItfDocument * xemlDoc;
				std::map<QString,OntologyHandlerResources*>             * developmentalOntologyHandler;
				std::map<QString,OntologyHandlerResources*>             * structuralOntologyHandler;
				std::map<QString,OntologyHandlerResources*>             * xeoOntologyHandler;
				std::map<QString,OntologyHandlerResources*>             * positionOntologyHandler;
				std::map<QString,OntologyHandlerResources*>             * genotypeOntologyHandler;
				std::map<QString,OntologyHandlerResources*>             * EOOntologyHandler;
				std::map<QString,OntologyHandlerResources*>             * EnvOOntologyHandler;
				std::vector<std::pair<DataProviderResources*,QString> > * dataProvider;

				std::map<QString,OntologyHandlerResources*>::iterator  it;
				std::vector<std::pair<DataProviderResources*,QString> >::iterator vec_pair_iterator;




			public:
				DocumentResources();
				~DocumentResources();
				void                                                        remove( OntologyHandlerResources * _ohr);
				OntologyHandlerResources *                                  Add( QString _uri,
																				 QString alias,
																				 QString instanceLocation,
																				 bool loadableOnly);
				bool                                                        provider_contain(QString _uri);
				bool                                                        contains(QString _alias,OntologyType ot);
				bool                                                        containValue(std::map<QString,
																						 OntologyHandlerResources*> * _handler,
																						 QString _alias);
				void                                                        clear_handlers();

				//readonly collection
				const std::map<QString,OntologyHandlerResources*>       get_readonlydevHandler();
				const std::map<QString,OntologyHandlerResources*>       get_readonlystructHandler();
				const std::map<QString,OntologyHandlerResources*>       get_readonlyxeoHandler();
				const std::map<QString,OntologyHandlerResources*>       get_readonlyposHandler();
				const std::map<QString,OntologyHandlerResources*>       get_readonlygenHandler();
				const std::map<QString,OntologyHandlerResources*>       get_readonlyEOHandler();
				const std::map<QString,OntologyHandlerResources*>       get_readonlyEnvOHandler();
				const std::map<QString,OntologyHandlerResources*> &     readonly_developmentalOntologyHandler;
				const std::map<QString,OntologyHandlerResources*> &     readonly_structuralOntologyHandler;
				const std::map<QString,OntologyHandlerResources*> &     readonly_xeoOntologyHandler;
				const std::map<QString,OntologyHandlerResources*> &     readonly_genotypeOntologyHandler;
				const std::map<QString,OntologyHandlerResources*> &     readonly_positionOntologyHandler;
				const std::map<QString,OntologyHandlerResources*> &     readonly_EOOntologyHandler;
				const std::map<QString,OntologyHandlerResources*> &     readonly_EnvOOntologyHandler;


				std::map<QString,OntologyHandlerResources*>             * get_devHandler();
				std::map<QString,OntologyHandlerResources*>             * get_structHandler();
				std::map<QString,OntologyHandlerResources*>             * get_xeoHandler();
				std::map<QString,OntologyHandlerResources*>             * get_posHandler();
				std::map<QString,OntologyHandlerResources*>             * get_genHandler();
				std::map<QString,OntologyHandlerResources*>             * get_EOHandler();
				std::map<QString,OntologyHandlerResources*>             * get_EnvOHandler();
				std::vector<std::pair<DataProviderResources*,QString> > * get_data_provider();
				std::map<QString,OntologyHandlerResources*>::iterator   get_iterator();
				OntologyHandlerResources* get_handler_by_alias(QString _alias,OntologyType _ot);
				//ItfDocument * get_xeml_doc();
				//void set_xeml_doc(ItfDocument * _xemlDoc);
		};
	}
}

#endif // DOCUMENTRESOURCES_H
