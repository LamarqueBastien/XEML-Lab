#ifndef POSITIONINGONTOLOGYHANDLER_H
#define POSITIONINGONTOLOGYHANDLER_H
#include<QXmlReader>
#include<QIODevice>
#include<map>
#include <iostream>
#include<QtXml>
#include<QString>
#include<QTextStream>
#include<QFile>
#include"Interface/itfvariableontologyhandler.h"
#include"Interface/itfhierarchicalview.h"
#include"CoreObjects/basicterm.h"
#include"Interface/itfxemlcomponent.h"
#include"Interface/itfontologyhandler.h"
#include"Interface/itfontologyterm.h"
#include"Ontologies/Environment/typespecificsenum.h"
#include"Manager/downloadmanager.h"
#include"Ontologies/OBO/attributestore.h"
#include"Ontologies/Environment/typespecification.h"
#include"Ontologies/Positioning/posterm.h"
#include<QtDebug>
using namespace Xeml::Document::Ontologies::Positionning;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document::Ontologies;
using namespace Xeml::Document::EnvironmentalOntology;
using namespace Xeml::Document::Manager;

using Xeml::Document::Contracts::OntologyLoadState;
using Xeml::Document::Contracts::OntologyType;
using Xeml::Document::Contracts::OntologyLoadState;
using Xeml::Document::Contracts::OntologyType;
using Xeml::Document::Contracts::ItfXemlComponent;
using Xeml::Document::Contracts::ItfDynamicOntologyTerm;

using Xeml::Document::Contracts::TermNode;
using Xeml::Document::EnvironmentalOntology::Enum;

using Xeml::Document::BasicTerm;
namespace Xeml{

	namespace Document{
		class PositioningOntologyHandler : public ItfVariableOntologyHandler, public ItfHierarchicalView
		{
			private:
				std::map<QString,ItfVariableOntologyTerm*> * terms;
				void                                         buildHierarchy();
				TermNode * findSubNode(TermNode * _tn,QString _label,QString _attribute);
				std::list<TermNode*>                       * Nodes;
				QString                                      alias;
				QString                                      xmlNS;

			public:
				PositioningOntologyHandler();
				~PositioningOntologyHandler();
				QString                                      URI;
				QString                                      FileLocationPrefix;

				//region itfVartiableOntologyHandler
				std::map<QString,ItfVariableOntologyTerm*> * get_terms();
				ItfVariableOntologyTerm                    * findKey(BasicTerm param);
				ItfVariableOntologyTerm                    * findKey(QString termId);
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

				//region itfvalidationsource
				QString                                      get_validation_events();
				//end region

				//region ItfHierarchicalView

				TermNode*                                    findNode_by_id(QString termId);
				TermNode*                                    findNode(ItfOntologyTerm *t);
				TermNode*                                    findNode(QString termId);
				TermNode*                                    findNode(TermNode * start,QString termId);
				std::list<TermNode*>                       * get_listNodes();
				//end region

				//region ItfOntologyHandler
				QString                                      namespaceAlias;
				Xeml::Document::Contracts::OntologyLoadState ontologyLoadState;
				QString                                      ontologyLoadMessage;
				Xeml::Document::Contracts::OntologyType      ontologyType;
				QString                                      nameSpace;
				bool                                         autovalidation;
				DownloadManager                            * downloadManager;
				bool                                         reloadNeeded;
				QString                                      instanceLocation;
				QString                                      get_namespaceAlias();
				void                                         set_namespaceAlias(QString _namespaceAlias);
				QString                                      get_namespace();
				void                                         set_namespace(QString _namespace);
				bool                                         get_autoValidation();
				void                                         set_autoValidation(bool _autovalidation);
				QString                                      get_instanceLocation();
				void                                         set_instanceLocation(QString _instancelocation);
				OntologyLoadState                            get_ontologyLoadState();
				QString                                      get_ontologyLoadMessage();
				OntologyType                                 get_ontologyType();
				void                                         load(QString nameSpaceAlias);
				void                                         load(QString nameSpaceAlias, bool force);

				//region private stuff
				std::map<QString,NamedTypeSpecification*> * globalTypes;
				std::map<QString,UnitSet*> * globalUnits;
				std::map<QString,QString>  *contextCollection;
				bool contain_key_GLbType(QString _name);
				void init(QDomDocument * ontoFile);
				void initContextList(QDomElement  elem);
				void initGlobalType(QDomElement  elem);
				void initGlobalUnit(QDomElement  elem);
				void initUnit(QDomElement  elem,VariableContextSpec *pc);
				void initUnit(QDomElement  elem,UnitSet * us);
				void initTypeDefine(QDomElement  elem,TypeSpecification *td);
				void initTypeDefine(QDomElement  elem,VariableContextSpec * pc);




		};
	}
}

#endif // POSITIONINGONTOLOGYHANDLER_H
