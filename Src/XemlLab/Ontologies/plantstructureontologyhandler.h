#ifndef PLANTSTRUCTUREONTOLOGYHANDLER_H
#define PLANTSTRUCTUREONTOLOGYHANDLER_H
#include"itfplainontologyhandler.h"
#include"itfhierarchicalview.h"
#include"itfontologyterm.h"
#include"itfxemlcomponent.h"
#include"itfontologyhandler.h"
#include"oboreader.h"
#include"downloadmanager.h"
#include"simpleoboterm.h"
#include"termattribute.h"
#include"basicterm.h"
#include<QString>
#include<map>
#include<list>
#include<exception>

using namespace std;
using namespace Mpi::Common;
using namespace Xeml::Document::Manager;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document::Ontologies;
using Mpi::Common::OboReader;
using Xeml::Document::BasicTerm;
using Xeml::Document::Contracts::OntologyLoadState;
using Xeml::Document::Contracts::ItfXemlComponent;
using Xeml::Document::Ontologies::SimpleOboTerm;


namespace Xeml {

	namespace Document{

		namespace PlantStructure{


			class PlantStructureOntologyHandler : public ItfPlainOntologyHandler , public ItfHierarchicalView
			{
				public:
					PlantStructureOntologyHandler();
					~PlantStructureOntologyHandler();
					QString                                      URI;
					QString                                      FileLocationPrefix;
					//region ItfPlainOntologyHandler
					std::map<QString,ItfOntologyTerm*>           terms;
					std::map<QString,ItfOntologyTerm*>           get_terms();

					bool                                         contain(BasicTerm param);
					ItfOntologyTerm                            * findKey(BasicTerm param);
					ItfOntologyTerm                            * findKey(QString termId);
					//end region

					//region ItfHierarchicalView
					std::list<TermNode*>                       * Nodes;
					TermNode*                                    findNode_by_id(QString termId);
					TermNode*                                    findNode(ItfOntologyTerm *t);
					TermNode*                                    findNode(QString termId);
					TermNode*                                    findNode(TermNode * start,QString termId);
					std::list<TermNode*>                       * get_listNodes();
					//end region

					//region XEmlComponent
					QString                                      get_publisher();
					QString                                      get_version();
					QString                                      get_componentName();
					QString                                      get_author();
					QString                                      get_description();
					QString                                      get_uri();
					ItfXemlComponent                           * copy();
					//end region

					//region ItfvalidationSource
					QString get_validation_events();
					//end region

					//region ItfOntologyHandler
					//SimpleOboTerm                                currentStanza;
					QString                                      name_space;
					bool                                         autovalid;
					QString                                      instanceLocation;
					bool                                         reloadNeeded;
					QString                                      ontologyLoadMessage;
					Xeml::Document::Contracts::OntologyLoadState ontologyLoadState;
					Xeml::Document::Contracts::OntologyType      ontologyType;
					QString                                      namespaceAlias;
					Mpi::Common::OboReader                     * oboreader;
					DownloadManager                            * downloadManager;
					QString                                      get_namespaceAlias();
					void                                         set_namespaceAlias(QString _namespaceAlias);
					QString                                      get_namespace();
					void                                         set_namespace(QString _namespace);
					bool                                         get_autoValidation();
					void                                         set_autoValidation(bool _autovalidation);
					QString                                      get_instanceLocation();
					void                                         set_instanceLocation(QString _instancelocation);
					QString                                      get_ontologyLoadMessage();
					OntologyLoadState                            get_ontologyLoadState();
					OntologyType                                 get_ontologyType();
					void                                         load(QString _nameSpaceAlias);
					void                                         load(QString _nameSpaceAlias, bool _force);
					void                                         buildHierarchy();
				private:
					void                                         reportError(exception _ex);
			};
		}
	}
}


#endif // PLANTSTRUCTUREONTOLOGYHANDLER_H