#ifndef PROTOCOLBASE_H
#define PROTOCOLBASE_H
#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"
#include"ISA-export/Ontology/term.h"
#include"ISA-export/Protocol/parameter.h"

#include<QUuid>
using namespace std;
using namespace Xeml::Document;
using namespace XemlUtilities::ISA::Ontology;


namespace XemlUtilities{

	namespace ISA{

		namespace Protocol{

			class ProtocolBase
			{
					static std::vector<std::pair<QString,ProtocolBase*> > * protocols;
				public:
					ProtocolBase();
					static void init(ItfDocument * _xemldoc,QUuid * _xemlId, QString _connectionString);
					QString get_name();
					void set_name(QString _name);
					QString get_type();
					void set_type(QString _type);
					QString get_description();
					void set_description(QString _description);
					XemlUtilities::ISA::Ontology::Term * get_accession_number();
					void set_accession_number(XemlUtilities::ISA::Ontology::Term * _accesion_number);
					std::vector<Parameter*> * get_parameters;




				private:
					ItfDocument * xemlDoc;
					QUuid * xemlId;
					QString connectionString;
					std::vector<Parameter*> * parameters;
			};
		}
	}
}

#endif // PROTOCOLBASE_H
