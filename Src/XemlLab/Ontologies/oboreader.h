#ifndef OBOREADER_H
#define OBOREADER_H
#include<iostream>
#include<fstream>
#include<QFile>
#include<QTextStream>
#include<QRegExp>
#include<string>
#include<QString>
#include<QStringList>
#include<map>



using namespace std;


namespace Xeml {

	namespace Document {

		namespace Contracts {

			class ItfOntologyHandler;
			class ItfOntologyTerm;
		}

		namespace Ontologies {
			class SimpleOboTerm;
		}

	}
}

namespace XemlContracts  = Xeml::Document::Contracts;
namespace XemlOntologies = Xeml::Document::Ontologies;

namespace Mpi {

	namespace Common{




		typedef enum
			{
			Term,
			TypeDef,
			Unknown
			}StanzaType;


		class OboReader
		{
			private:
				XemlContracts::ItfOntologyHandler * handler;
				XemlOntologies::SimpleOboTerm     * currentStanza;
				StanzaType                          stanzaType;
				QRegExp                           * regexStanza;
				QRegExp                           * regexTerm;
				QRegExp                           * regexTypedef;
				QRegExp                           * regexTagValPair;
				std::map<QString,StanzaType>  * stanzaToString;

			public:
				OboReader();
				OboReader( XemlContracts::ItfOntologyHandler * _handler );
				~OboReader();
				void                                read( QString filename, std::map< QString, XemlContracts::ItfOntologyTerm * > * _terms );
				static void                         process_line( const QString & );
				bool                                checkForNewStanza( QString _line,int _lineNumber,
																	   std::map<QString,
																	   XemlContracts::ItfOntologyTerm *> * _terms);

				bool                                checkForTagValuePair( std::list<QString> * filter,
																		  int _lineNumber, QString _line,
																		  std::map<QString, XemlContracts::ItfOntologyTerm *> * _terms);
				StanzaType                          get_stanzaType();
				void                                set_stanzaType(StanzaType _stanzaType);
				void                                OnNewStanza( QString _stanzaType,
																 QString _name,
																 int _lineNumber,
																 std::map<QString, XemlContracts::ItfOntologyTerm *> * _terms);

				void                                OnNewTagValuePair( QString _attribute,
																	   QString _attributeValue,
																	   int _lineNumber,std::map<QString,
																	   XemlContracts::ItfOntologyTerm *> * _terms);
				StanzaType                          get_stanza_from_string(QString stanzaString);

		};
	}
}

#endif // OBOREADER_H
