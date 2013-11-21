#ifndef POSTERM_H
#define POSTERM_H
#include"Interface/itfontologyterm.h"
#include<QUrl>
#include"Ontologies/Environment/variablecontextspec.h"
#include"CoreObjects/variableterm.h"
#include"CoreObjects/basicterm.h"
#include"CoreObjects/Utilities.h"
#include<QStringList>
using namespace Xeml::Document;
using namespace Xeml::Document::EnvironmentalOntology;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Utilities;
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace Positionning{

				class PosTerm : public ItfVariableOntologyTerm
				{
					private:
						QUrl uri;
						QString name;
						//int recomLevel;
						QString groupPath;
						//QString _definition;
						QString nameSpace;
						QString nameSpaceAlias;
						std::map<QString, VariableContextSpec*> * contextCollection;
					public:
						PosTerm();
						PosTerm(QString _termId,QString _nameSpace,QString _nameSpaceAlias);
						~PosTerm();
						QStringList                                      * GroupLevels();
						QUrl                                               get_url();
						void                                               set_url(QUrl _uri);
						int                                                contextCount();
						std::map<QString, VariableContextSpec*>      * get_contextCollection();
						int                                                get_recomLevel();
						void                                               set_recomLevel(int _recomLevel);
						void                                               set_contextCollection(std::map<QString, VariableContextSpec*> * _contextCollection);
						QString                                        get_nameSpace();
						void                                               set_nameSpace(QString _nameSpace);
						QString                                        get_name();
						void                                               set_name(QString _name);
						QString                                        get_groupPath();
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
				};
			}
		}
	}
}

#endif // POSTERM_H
