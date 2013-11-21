#ifndef OBOHANDLER_H
#define OBOHANDLER_H
#include<string>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<iostream>
#include<fstream>
#include <list>
#include <cctype>
#include"CoreObjects/basicterm.h"
#include"Ontologies/OBO/attributestore.h"
#include"Interface/itfhierarchicalview.h"
#include"Interface/itfxemlcomponent.h"
#include"Interface/itfontologyhandler.h"
#include"Interface/itfontologyterm.h"
#include"Interface/itfdynamicontologyhandler.h"
#include"Interface/itfplainontologyhandler.h"
#include"Manager/downloadmanager.h"
#include"Ontologies/Environment/xeoterm.h"
#include"Ontologies/Environment/typespecificsenum.h"
#include"CoreObjects/term.h"
#include"Ontologies/OBO/oboreader.h"
using namespace std;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document::Manager;
using namespace Xeml::Document;
using namespace Mpi::Common;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document::Ontologies;
using namespace Xeml::Document::EnvironmentalOntology;
using Xeml::Document::Contracts::OntologyLoadState;
using Xeml::Document::Contracts::OntologyType;
using Xeml::Document::Contracts::ItfXemlComponent;
using Xeml::Document::Contracts::ItfDynamicOntologyTerm;
using Xeml::Document::EnvironmentalOntology::XeoTerm;
using Xeml::Document::Contracts::TermNode;
using Xeml::Document::EnvironmentalOntology::Enum;
using Xeml::Document::Term;
using Xeml::Document::BasicTerm;
using Mpi::Common::OboReader;



namespace Xeml {

	namespace Document{

		namespace Ontologies{

			namespace OBO{

				class OboHandler : public ItfHierarchicalView, public ItfDynamicOntologyHandler

				{
					private:
						QString                                             ontologyLoadMessage;
						bool                                                reloadNeeded;
						QString                                             instanceLocation;
						QString                                             nameSpaceAlias;
						void                                                sortNodes(std::list<TermNode*> * _collection);
						void                                                build_isa_hierarchy(std::list<AttributeStore*> * _collection);
						void                                                deleteHeaderNodes();
						void                                                addInheritedContext(std::list<AttributeStore*> * _collection);
						void                                                addInheritedContext(std::list<AttributeStore*> * _collection,XeoTerm * _targetXeoTerm,QString _currentId);
						void                                                addEnum(std::list<AttributeStore*> * _collection,VariableContextSpec * _context,QString _instanceId);
						void                                                defineContextDataType(std::list<AttributeStore*> * _collection,VariableContextSpec * _context,QString _contextId);
						DownloadManager                                   * downloadManager;

					protected:
						OboHandler();
						QString                                             URI;
						QString                                             FileLocationPrefix;
						virtual void                                        doTagTypeAnnotation(std::list<AttributeStore*> * _collection)=0;
						virtual void                                        buildContexts(std::list<AttributeStore*> * _collection)=0;
						VariableContextSpec                               * createContext(std::list<AttributeStore*> * _collection,AttributeStore * _currentXeoTermWithContext,QString contextId,QString contextName);
						void                                                createContextUnitSet(std::list<AttributeStore*> * _collection,VariableContextSpec  * _context,QString _contextId);
						void                                                createContextEnumeration(std::list<AttributeStore*> *_collection,VariableContextSpec * _context,QString _contextId);
						std::map<QString,ItfDynamicOntologyTerm*>           terms;
						//std::list<ItfDynamicOntologyTerm*> terms;
						std::list<TermNode*>                              * nodes;

					public:
						//OboHandler();

						QString                                         componentName;
						bool                                                contain(QString _TermId);
						void                                                process_line(const QString &);

						//region ItfDynamicOntologyHandler
						std::map<QString,ItfDynamicOntologyTerm*>           get_terms();
						Xeml::Document::Contracts::ItfDynamicOntologyTerm * findKey(Xeml::Document::BasicTerm _param);
						Xeml::Document::Contracts::ItfDynamicOntologyTerm * findKey(QString _termId);

						//end region

						//region IhierarchicalView
						TermNode*                                           findNode_by_id(QString termId);
						TermNode*                                           findNode(ItfOntologyTerm *t);
						TermNode*                                           findNode(QString termId);
						TermNode*                                           findNode(TermNode * start,QString termId);
						std::list<TermNode*>                              * get_listNodes();

						//end region

						//region ItfOntologyHandler





						Xeml::Document::Contracts::OntologyLoadState ontologyLoadState;
						Xeml::Document::Contracts::OntologyType      ontologyType;
						QString                         nameSpace;
						bool                            autovalidation;
						Mpi::Common::OboReader        * oboreader;
						QString                         get_validation_events();
						QString                         get_namespaceAlias();
						void                            set_namespaceAlias(QString _namespaceAlias);
						QString                         get_namespace();
						void                            set_namespace(QString _namespace);
						bool                            get_autoValidation();
						void                            set_autoValidation(bool _autovalidation);
						QString                         get_instanceLocation();
						void                            set_instanceLocation(QString _instancelocation);
						OntologyLoadState               get_ontologyLoadState();
						QString                         get_ontologyLoadMessage();
						OntologyType                    get_ontologyType();
						void                            load(QString nameSpaceAlias);
						void                            load(QString nameSpaceAlias, bool force);

				};
			}
		}
	}
}

#endif // OBOHANDLER_H
