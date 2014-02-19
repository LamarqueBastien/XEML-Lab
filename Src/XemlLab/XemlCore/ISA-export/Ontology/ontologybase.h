#ifndef ONTOLOGYBASE_H
#define ONTOLOGYBASE_H
#include"ISA-export/Ontology/term.h"
#include<vector>
#include<pair.h>

using namespace std;

namespace XemlUtilities{

	namespace ISA{

		namespace Ontology{

			class OntologyBase
			{
				public:
					OntologyBase();
					OntologyBase(QString _acronym);
					//static OntologyBase(){
						//this->ontologies=new std::vector<std::pair<QString,OntologyBase*> >();
					//}

					QString get_name();
					QString get_url();
					QString get_ontologyURL();
					QString get_acronym();
					QString get_version();
					void set_name(QString _name);
					void set_url(QString _url);
					void set_ontologyURL(QString _ontologyURL);
					void set_acronym(QString _acronym);
					void set_version(QString _Version);
					virtual std::vector<Term*> * get_terms();
					virtual void add_term(Term * _term);
					void set_terms(std::vector<Term*> * _terms);
					bool ontologies_contains_key(QString _key);

					static std::vector<std::pair<QString,OntologyBase*> >* get_ontologies();
					static void set_ontologies(std::vector<std::pair<QString,OntologyBase*> > * _ontologies);

					static QString get_connection_string();
					static void set_connection_string(QString _connectionString);


					struct MetaDataStruct{
							QString name;
							int bioPortalId;
							QString version;
							QString url;
							QString ontologyURL;
							QString acronym;

					};
					static std::vector<MetaDataStruct> * get_ontology_metadata();
					static void set_ontology_metadata(std::vector<MetaDataStruct> * _ontologyMetadata);
					void registering();
					void fill_missing_data();
					static OntologyBase * get_or_create_ontology(QString _acronym);
					static OntologyBase * get_or_create_ontology(QString _acronym, QString _termName);
					static Term * get_or_create_term(QString _ontologyAcronym, QString _termAccessionNumber);
					static Term * get_or_create_term(QString _ontologyAcronym, QString _termAccessionNumber, QString _termName);
					static Term * get_or_create_term_name(QString _acronym, QString _termName);





				private:
					static std::vector<MetaDataStruct> * get_metadata();

					static std::vector<MetaDataStruct> * ontologyMetadata;
					static std::vector<std::pair<QString,OntologyBase*> >* ontologies;
					static QString connection_string;
					std::vector<Term*> * terms;
					QString name;
					QString url;
					QString ontologyURL;
					QString acronym;
					QString version;
			};
		}
	}
}


#endif // ONTOLOGYBASE_H
