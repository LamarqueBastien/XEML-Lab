#ifndef XEOTERM_H
#define XEOTERM_H

#include<QUrl>
#include<QString>
#include<vector>
#include<map>
#include"Ontologies/Environment/variablecontextspec.h"
#include <sstream>
#include"Interface/itfontologyterm.h"
#include"CoreObjects/basicterm.h"
#include"CoreObjects/dynamicterm.h"
#include"CoreObjects/termattribute.h"
#include"CoreObjects/dynamicvalue.h"
#include"CoreObjects/timespan.h"
#include"CoreObjects/cycle.h"
#include"Ontologies/Environment/typespecificsenum.h"

using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;

using std::make_pair;
using std::pair;
using Xeml::Document::Term;
using Xeml::Document::BasicTerm;
using Xeml::Document::TermAttribute;
using Xeml::Document::Contracts::ItfOntologyTerm;
using Xeml::Document::Contracts::ItfDynamicOntologyTerm;

namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{


			class XeoTerm : public ItfDynamicOntologyTerm
			{
				private:
					QString name;
					int recomLevel;
					QString groupPath;
					QString nameSpace;
					//QString _defintion;
					QUrl uri;
					QString nameSpaceAlias;
					std::map<QString, VariableContextSpec*> * contextCollection;



				public:

					XeoTerm();
					XeoTerm(QString _termId,QString _nameSpace, QString _nameSpaceAlias);
					~XeoTerm();
					QUrl                                               get_url();
					void                                               set_url(QUrl _uri);
					int                                                contextCount();
					std::map<QString, VariableContextSpec*>          * get_contextCollection();
					int                                                get_recomLevel();
					void                                               set_recomLevel(int _recomLevel);
					void                                               set_contextCollection(std::map<QString, VariableContextSpec*> * _contextCollection);
					QString                                            get_nameSpace();
					void                                               set_nameSpace(QString _nameSpace);
					QString                                            get_name();
					void                                               set_name(QString _name);
					QString                                            get_groupPath();
					void                                               set_groupPath(QString _groupPath);


					//region ItfontologyTerm

					const std::list<BasicTerm*>                      & readonlySupervisedObject;
					QString                                            get_termId();
					std::list<BasicTerm*>                              get_supervisedObject();
					BasicTerm                                        * get_prototype();
					QString                                            get_definition();
					void                                               set_definition(QString _definition);
					bool                                               contains(QString _id);
					bool                                               contain(QString _context);
					void                                               display_attributes();
					TermAttribute                                    * get_termAttributesByKey(QString _key);
					void                                               add_termAttribute(TermAttribute * _tA);
					void                                               remove_termAttribute(QString _name);
					std::map<QString,TermAttribute*>                   get_termAttributeCollection();
					BasicTerm                                        * emit_DefaultObject(bool supervised);
					void                                               supervise(BasicTerm *t);
					void                                               reject_supervision(BasicTerm *t);
					void                                               validate_SupervisedProperties();
					void                                               push_SupervisedProperties();
					//end region

					//region itfVariableOntologyTerm

					bool                                               hasDefaultValue(QString context);
					bool                                               hasDefaultUnit(QString _context);
					QString                                        defaultUnitName(QString context);
					QString                                        defaultUnitSymbol(QString context);
					VariableDataTypes                                  getDataTypes(QString context);
					std::vector<std::pair<QString,QString> > * listUnits(QString context);
					std::vector<std::pair<QString,QString> > * getEnums(QString context);
					ValueBase                                        * defaultValue(QString context);
					//end region

					//region ItfDynamicOntologyTerm

					bool                                               hasDefaultCycle(QString context);
					Cycle                                            * defaultCycle(QString _context);
					DynamicValue                                     * defaultdynamicValue(QString context, QDateTime _time);
					Cycle                                            * defaultCycle(QString context, QDateTime _time);
					//end region
			};
		}
	}
}

#endif // XEOTERM_H
