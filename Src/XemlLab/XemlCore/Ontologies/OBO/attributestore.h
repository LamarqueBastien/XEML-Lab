#ifndef ATTRIBUTESTORE_H
#define ATTRIBUTESTORE_H
#include"Ontologies/OBO/OboHeaderTypes.h"
#include"Ontologies/OBO/OboTermClass.h"
#include"Ontologies/OBO/OboTags.h"
#include"Ontologies/Environment/variablecontextspec.h"
#include"Ontologies/Environment/xeoterm.h"
#include<vector>
#include<QString>
#include<QStringList>
#include<QRegExp>
using namespace std;
using std::pair;
using std::make_pair;
using namespace Xeml::Document::Ontologies::OBO;
using namespace Xeml::Document::EnvironmentalOntology;
namespace Xeml {

	namespace Document{

		namespace Ontologies{

			namespace OBO{
				class AttributeStore
				{
					protected:

						AttributeStore();

					public:

						AttributeStore(QStringList _termList);
						~AttributeStore();
						OboHeaderTypes  headerType;
						OboTermClass								   headerClass;
						std::vector<std::pair<OboTags,QString> > * Obolist;
						std::vector<VariableContextSpec*>            * contextCollection;
						XeoTerm *                                      term;
						std::vector<std::pair<OboTags,QString> > * get_obo_list();
						void                                           clear();
						bool                                           contain_header_type(OboHeaderTypes _oht);
						XeoTerm *                                      get_term(QString _nameSpace,QString _nameSpaceAlias);
						QString                                    get_id();
						QString                                    get_name();
						bool                                           isTerm();
						bool                                           isInstance();
						bool                                           isTypeDef();
						bool                                           isEnvironmentVariableTerm();
						bool                                           isContextTerm();
						bool                                           isDataTypeTerm();
						bool                                           isNoneTerm();
						bool                                           contain_N_compare(Xeml::Document::Ontologies::OBO::OboTags _tag,QString _value);
						bool                                           contain(Xeml::Document::Ontologies::OBO::OboTags);
						QString                                    get_value(OboTags _tag);
						OboTermClass                                   get_termClass(QString _classname);
						std::pair<OboTags,QString>               * get_pair(OboTags _tag);

					private:

						void                                           add(OboTags _key,QString _value);
						QRegExp                                      * rxOboTagHeaders;
						QRegExp                                      * rxOboKeyWords;
						QRegExp                                      * regexStanza;
						QRegExp                                      * regexTagValPair;


				};
			}
		}
	}
}

#endif // ATTRIBUTESTORE_H
