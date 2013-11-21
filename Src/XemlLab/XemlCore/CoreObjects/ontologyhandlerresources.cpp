#include "ontologyhandlerresources.h"
namespace Xeml{

	namespace Document{
		OntologyHandlerResources::OntologyHandlerResources(QString _uri)
		{
			this->uri=_uri;
			this->calCount=0;
			this->compstate=Xeml::Document::Untouched;
		}
		OntologyHandlerResources::~OntologyHandlerResources(void){
			delete this->handler;

		}

		QString OntologyHandlerResources::get_uri(){
			return this->uri;
		}

		Xeml::Document::Contracts::ItfOntologyHandler * OntologyHandlerResources::get_handler(){
			return this->handler;
		}

		ComponentLoadState OntologyHandlerResources::get_component_state(){
			return this->compstate;
		}

		void OntologyHandlerResources::set_component_state(ComponentLoadState _value){
			this->compstate=_value;
		}

		QString OntologyHandlerResources::get_namespace(){
			return this->nameSpace;
		}

		void OntologyHandlerResources::set_namespace(QString _namespace){
			this->nameSpace=_namespace;
		}

		QString OntologyHandlerResources::get_location()
		{
			return this->location;
		}

		void OntologyHandlerResources::set_location(QString _location)
		{
			this->location=_location;
		}

		void OntologyHandlerResources::loadOntology()
		{

			if ( this->compstate==Xeml::Document::Loaded ){
				std::cerr << "début du chargement de l'ontologie : " << this->nameSpace.toStdString() << std::endl;
				this->handler->load(this->nameSpace);
				std::cerr << "fin du chargement de l'ontologie" << std::endl;
			}
		}

		void OntologyHandlerResources::loadComponent(){
			if (this->compstate!=Xeml::Document::Loaded)
			{
				try
				{
					//creation ontologymanager !!!!
					if ( OntologyManager::Get_ontologyManager()->contains(this->uri))
					{
						this->handler =  OntologyManager::Get_ontologyManager()->createHandler(this->uri);
						this->handler->get_instanceLocation()=this->location;
						this->compstate=Xeml::Document::Loaded;
					}
					else
					{
						this->compstate=Xeml::Document::UnknownComponent;
					}
				}
				catch(std::exception)// créer XemlComponentLoadFailedException
				{
					this->compstate=Xeml::Document::Failed;
				}
			}

		}
	}
}
