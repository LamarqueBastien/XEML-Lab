#ifndef SIMPLEOBOTERM_H
#define SIMPLEOBOTERM_H
#include<QString>
#include<list>
#include<exception>
#include"itfontologyterm.h"
#include"termattribute.h"
#include"basicterm.h"
using std::make_pair;
using std::pair;
//using Xeml::Document::Term;
using Xeml::Document::TermAttribute;
using Xeml::Document::Contracts::ItfOntologyTerm;
using namespace std;
using namespace Xeml::Document;
using Xeml::Document::BasicTerm;
using namespace Xeml::Document::Contracts;

namespace Xeml{

	namespace Document{

		namespace Ontologies{


			class SimpleOboTerm : public ItfOntologyTerm
			{
				private:

					std::list<std::pair<QString,QString> >         * oboTagValuePair;
					std::list<std::pair<QString,QString> >::iterator it;
					QString                                          name;
					QString                                          nameSpace;
					QString                                          nameSpaceAlias;

				public:
					SimpleOboTerm();
					SimpleOboTerm(QString _termId);
					~SimpleOboTerm();
					const std::list<BasicTerm*>                    & readonlySupervisedObject;
					std::map<QString,TermAttribute*>                 get_termAttributeCollection();
					QString                                          get_termId();
					void                                             set_termId(QString _termId);
					std::list<BasicTerm*>                            get_supervisedObject();
					BasicTerm                                      * get_prototype();
					QString                                          get_definition();
					void                                             set_definition(QString _definition);
					BasicTerm                                      * emit_DefaultObject(bool supervised);
					void                                             supervise(BasicTerm *t);
					void                                             reject_supervision(BasicTerm *t);
					void                                             validate_SupervisedProperties();
					void                                             push_SupervisedProperties();
					std::list<std::pair<QString,QString> >         * get_oboTagValuePair();
					QString                                          get_name();
					void                                             set_name(QString _name);
					QString                                          get_nameSpace();
					void                                             set_nameSpace(QString _nameSpace);
					QString                                          get_nameSpaceAlias();
					void                                             set_nameSpaceAlias(QString _nameSpaceAlias);
					bool                                             contains(QString _id);
					bool                                             contains(BasicTerm * t);
					void                                             display_attributes();
					TermAttribute                                  * get_termAttributesByKey(QString _key);
					void                                             add_termAttribute(TermAttribute * _tA);
					void                                             remove_termAttribute(QString _name);
					void                                             remove(Xeml::Document::BasicTerm * t);

			};
		}
	}
}

#endif // SIMPLEOBOTERM_H
