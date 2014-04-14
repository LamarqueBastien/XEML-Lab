#ifndef ONTOLOGYMANAGER_H
#define ONTOLOGYMANAGER_H
#include<map>
#include<string>
#include"Interface/itfontologyhandler.h"
#include"Ontologies/DevelopmentalStage/developmentalontologyhandler.h"
#include"Ontologies/PlantStructure/plantstructureontologyhandler.h"
#include"Ontologies/Positioning/positioningontologyhandler.h"
#include"Interface/itfdynamicontologyhandler.h"
#include"Ontologies/OBO/peohandler.h"
#include"Ontologies/OBO/xeohandler.h"
#include"Ontologies/OBO/envohandler.h"
#include"CoreObjects/xemlcomponentloadfailedexception.h"
#include<exception>

using namespace std;
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document::Ontologies::OBO;
using namespace Xeml::Document::PlantStructure;
using Xeml::Document::PlantStructure::PlantStructureOntologyHandler;
using Xeml::Document::DevelopmentalOntologyHandler;
using Xeml::Document::Ontologies::OBO::XeoHandler;
using Xeml::Document::Ontologies::OBO::PEOHandler;
using Xeml::Document::Contracts::ItfOntologyHandler;


namespace Xeml{

	namespace Manager{

		class OntologyManager
		{
			private:
				OntologyManager()
				{
					this->ontologyHandler=new std::map<QString,Xeml::Document::Contracts::ItfOntologyHandler *>();
					init();
				}
				//OntologyManager(const OntologyManager&);
				//OntologyManager& operator=(const OntologyManager&);
				~OntologyManager(){ }

			public:
				static OntologyManager * Get_ontologyManager()
				{
					if (NULL == Instance)
					{
						Instance =  new OntologyManager;
					}
					else
					{
						//std::cerr << "singleton already created!" << std::endl;
					}

					return Instance;
				}
				static void kill ()
				{
					if (NULL != Instance)
					{
						delete Instance;
						Instance = NULL;
					}
				}
				void init(){

					Xeml::Document::DevelopmentalOntologyHandler  * doh=new Xeml::Document::DevelopmentalOntologyHandler();
					Xeml::Document::PlantStructure::PlantStructureOntologyHandler * soh = new Xeml::Document::PlantStructure::PlantStructureOntologyHandler();
					Xeml::Document::Ontologies::OBO::XeoHandler * xoh = new Xeml::Document::Ontologies::OBO::XeoHandler();
					Xeml::Document::PositioningOntologyHandler * poh = new Xeml::Document::PositioningOntologyHandler();
					Xeml::Document::Ontologies::OBO::PEOHandler * peoh = new Xeml::Document::Ontologies::OBO::PEOHandler();
					Xeml::Document::Ontologies::OBO::EnvOHandler * envoh = new Xeml::Document::Ontologies::OBO::EnvOHandler();
					(*this->ontologyHandler)[doh->get_uri()]=doh;
					(*this->ontologyHandler)[soh->get_uri()]=soh;
					(*this->ontologyHandler)[xoh->get_uri()]=xoh;
					(*this->ontologyHandler)[poh->get_uri()]=poh;
					(*this->ontologyHandler)[peoh->get_uri()]=peoh;
					(*this->ontologyHandler)[envoh->get_uri()]=envoh;

				}
				std::map<QString,Xeml::Document::Contracts::ItfOntologyHandler *>  * get_handler(){
					return this->ontologyHandler;
				}

				bool contains(QString _uri){
					if (this->ontologyHandler->find(_uri) != this->ontologyHandler->end())
					{
						return true;
					}
					else{
						return false;
					}
				}

				ItfOntologyHandler * createHandler(QString _uri){
					if(this->contains(_uri)){
						ItfOntologyHandler * ret =NULL;
						try{
							ret=dynamic_cast<ItfOntologyHandler*>((*this->ontologyHandler)[_uri]->copy());
						}
						catch(exception ex)
						{
							throw new XemlComponentLoadFailedException(_uri,"Handler exists, but loading failed");
						}
						return ret;
					}
					else
						throw new XemlComponentLoadFailedException(_uri, "UnknownSample ontology handler.");
				}

			private:
				//variables membres
				std::map<QString,Xeml::Document::Contracts::ItfOntologyHandler *>  * ontologyHandler ;
				static OntologyManager  * Instance;


		};
	}
}


#endif // ONTOLOGYMANAGER_H




