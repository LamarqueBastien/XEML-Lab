#include "ontologybase.h"
namespace XemlUtilities{

	namespace ISA{

		namespace Ontology{
			//static variable
			std::vector<std::pair<QString,OntologyBase*> > * OntologyBase::ontologies=new std::vector<std::pair<QString,OntologyBase*> >();
			std::vector<OntologyBase::MetaDataStruct> * OntologyBase::ontologyMetadata=new std::vector<OntologyBase::MetaDataStruct>();
			QString OntologyBase::connection_string=QString();


			OntologyBase::OntologyBase()
			{
				this->terms=new std::vector<Term*>();
				this->ontologies=new std::vector<std::pair<QString,OntologyBase*> >();
			}
			OntologyBase::OntologyBase(QString _acronym)
			{
				this->acronym=_acronym;

				this->terms=new std::vector<Term*>();
			}
			QString OntologyBase::get_name(){
				return this->name;
			}

			QString OntologyBase::get_url(){
				return this->url;

			}

			QString OntologyBase::get_ontologyURL(){
				return this->ontologyURL;
			}

			QString OntologyBase::get_acronym(){
				return this->acronym;
			}

			QString OntologyBase::get_version(){
				return this->version;
			}

			void OntologyBase::set_name(QString _name){
				this->name=_name;
			}

			void OntologyBase::set_url(QString _url){
				this->url=_url;
			}

			void OntologyBase::set_ontologyURL(QString _ontologyURL){
				this->ontologyURL=_ontologyURL;
			}

			void OntologyBase::set_acronym(QString _acronym){
				this->acronym=_acronym;
			}

			void OntologyBase::set_version(QString _Version){
				this->version=_Version;
			}
			std::vector<Term*> *  OntologyBase::get_terms(){
				return this->terms;
			}
			void OntologyBase::add_term(Term * _term){
				this->terms->push_back(_term);
			}

			void  OntologyBase::set_terms(std::vector<Term*> * _terms){
				this->terms=_terms;
			}
			bool OntologyBase::ontologies_contains_key(QString _key){
				for (std::vector<std::pair<QString,OntologyBase*> >::iterator it=this->ontologies->begin();it!=this->ontologies->end();++it){
					if (static_cast<OntologyBase*>((*it).second)->get_acronym()==_key){
						return true;
					}
				}
				return false;
			}

			std::vector<std::pair<QString,OntologyBase*> >* OntologyBase::get_ontologies(){
				return ontologies;
			}

			void OntologyBase::set_ontologies(std::vector<std::pair<QString,OntologyBase*> > * _ontologies){
				ontologies=_ontologies;
			}

			std::vector<OntologyBase::MetaDataStruct> * OntologyBase::get_ontology_metadata(){
				return ontologyMetadata;
			}

			void OntologyBase::set_ontology_metadata(std::vector<MetaDataStruct> * _ontologyMetadata){
				ontologyMetadata=_ontologyMetadata;
			}

			QString OntologyBase::get_connection_string(){
				return connection_string;
			}

			void OntologyBase::set_connection_string(QString _connectionString){
				connection_string=_connectionString;
			}

			// has to be called at the end of derived class' constructor

			void OntologyBase::registering(){
				this->fill_missing_data();
				this->ontologies->push_back(make_pair(this->acronym,this));

			}
			void  OntologyBase::fill_missing_data(){

			}

			OntologyBase *  OntologyBase::get_or_create_ontology(QString _acronym){
				//if(this->ontologies-)
			}

			OntologyBase *  OntologyBase::get_or_create_ontology(QString _acronym, QString _termName){

			}

			Term *  OntologyBase::get_or_create_term(QString _ontologyAcronym, QString _termAccessionNumber){

			}

			Term *  OntologyBase::get_or_create_term(QString _ontologyAcronym, QString _termAccessionNumber, QString _termName){

			}

			Term *  OntologyBase::get_or_create_term_name(QString _acronym, QString _termName){

			}

			std::vector<OntologyBase::MetaDataStruct> *  OntologyBase::get_metadata(){
				if (ontologyMetadata!=NULL){
					return ontologyMetadata;
				}
				std::vector<OntologyBase::MetaDataStruct> * res=new std::vector<OntologyBase::MetaDataStruct>();
			}
		}
	}
}
