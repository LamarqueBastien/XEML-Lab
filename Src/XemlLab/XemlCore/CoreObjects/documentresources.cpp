#include "documentresources.h"
namespace Xeml{

	namespace Document{

		DocumentResources::DocumentResources()
			: readonly_developmentalOntologyHandler((*developmentalOntologyHandler)),
			  readonly_structuralOntologyHandler((*structuralOntologyHandler)),
			  readonly_xeoOntologyHandler((*xeoOntologyHandler)),
			  readonly_genotypeOntologyHandler((*genotypeOntologyHandler)),
			  readonly_positionOntologyHandler((*positionOntologyHandler)),
			  readonly_EOOntologyHandler((*EOOntologyHandler)),
			  readonly_EnvOOntologyHandler((*EnvOOntologyHandler))
		{

			this->developmentalOntologyHandler= new std::map<QString,OntologyHandlerResources*>();
			this->structuralOntologyHandler= new std::map<QString,OntologyHandlerResources*>();
			this->xeoOntologyHandler= new std::map<QString,OntologyHandlerResources*>();
			this->genotypeOntologyHandler= new std::map<QString,OntologyHandlerResources*>();
			this->positionOntologyHandler= new std::map<QString,OntologyHandlerResources*>();
			this->EOOntologyHandler= new std::map<QString,OntologyHandlerResources*>();
			this->EnvOOntologyHandler= new std::map<QString,OntologyHandlerResources*>();
			this->dataProvider=new std::vector<std::pair<DataProviderResources*,QString> >();
		}
		DocumentResources::~DocumentResources(void){

		}

		const std::map<QString,OntologyHandlerResources*>       DocumentResources::get_readonlystructHandler(){
			return this->readonly_structuralOntologyHandler;
		}

		const std::map<QString,OntologyHandlerResources*>     DocumentResources::get_readonlydevHandler(){
			return this->readonly_developmentalOntologyHandler;
		}
		const std::map<QString,OntologyHandlerResources*>       DocumentResources::get_readonlygenHandler(){
			return this->readonly_genotypeOntologyHandler;
		}
		const std::map<QString,OntologyHandlerResources*>       DocumentResources::get_readonlyposHandler(){
			return this->readonly_positionOntologyHandler;

		}

		const std::map<QString,OntologyHandlerResources*>     DocumentResources::get_readonlyxeoHandler(){
			return this->readonly_xeoOntologyHandler;
		}
		const std::map<QString,OntologyHandlerResources*>     DocumentResources::get_readonlyEOHandler(){
			return this->readonly_EOOntologyHandler;
		}
		const std::map<QString,OntologyHandlerResources*>     DocumentResources::get_readonlyEnvOHandler(){
			return this->readonly_EnvOOntologyHandler;
		}
		std::map<QString,OntologyHandlerResources*> *          DocumentResources::get_devHandler(){
			return this->developmentalOntologyHandler;
		}
		std::map<QString,OntologyHandlerResources*> *            DocumentResources::get_structHandler(){
			return this->structuralOntologyHandler;
		}
		std::map<QString,OntologyHandlerResources*> *            DocumentResources::get_xeoHandler(){
			return this->xeoOntologyHandler;
		}
		std::map<QString,OntologyHandlerResources*>  *           DocumentResources::get_posHandler(){
			return this->positionOntologyHandler;
		}
		std::map<QString,OntologyHandlerResources*> *            DocumentResources::get_genHandler(){
			return this->genotypeOntologyHandler;
		}
		std::map<QString,OntologyHandlerResources*> *            DocumentResources::get_EOHandler(){
			return this->EOOntologyHandler;
		}
		std::map<QString,OntologyHandlerResources*> *            DocumentResources::get_EnvOHandler(){
			return this->EnvOOntologyHandler;
		}

		std::map<QString,OntologyHandlerResources*>::iterator DocumentResources::get_iterator(){
			return this->it;
		}

		void DocumentResources::remove(OntologyHandlerResources * ohr){
			ohr->loadComponent();
			if(ohr->get_component_state()==Xeml::Document::Loaded){
				switch (ohr->get_handler()->get_ontologyType())
				{
					case Xeml::Document::Contracts::Developmental:
					{
						for (std::map<QString,OntologyHandlerResources*>::iterator it=this->developmentalOntologyHandler->begin();it!=this->developmentalOntologyHandler->end();it++){
							if (it->first==ohr->get_namespace()){
								delete it->second;
								this->developmentalOntologyHandler->erase(it);
							}
						}
						break;
					}
					case Xeml::Document::Contracts::OrganismStructure:
					{
						for (std::map<QString,OntologyHandlerResources*>::iterator it=this->structuralOntologyHandler->begin();it!=this->structuralOntologyHandler->end();it++){
							if (it->first==ohr->get_namespace()){
								delete it->second;
								this->structuralOntologyHandler->erase(it);
							}
						}
						break;
					}
					case Xeml::Document::Contracts::Environment:
					{
						//std::cerr << "remove EnvironmentalOntology" << std::endl;
						for (std::map<QString,OntologyHandlerResources*>::iterator it=this->xeoOntologyHandler->begin();it!=this->xeoOntologyHandler->end();it++){
							if (it->first==ohr->get_namespace()){
								delete it->second;
								this->xeoOntologyHandler->erase(it);
							}
						}
						break;
					}
					case Xeml::Document::Contracts::Genotype:
					{
						for (std::map<QString,OntologyHandlerResources*>::iterator it=this->genotypeOntologyHandler->begin();it!=this->genotypeOntologyHandler->end();it++){
							if (it->first==ohr->get_namespace()){
								delete it->second;
								this->genotypeOntologyHandler->erase(it);
							}
						}
						break;
					}
					case Xeml::Document::Contracts::Positioning:
					{
						for (std::map<QString,OntologyHandlerResources*>::iterator it=this->positionOntologyHandler->begin();it!=this->positionOntologyHandler->end();it++){
							if (it->first==ohr->get_namespace()){
								delete it->second;
								this->positionOntologyHandler->erase(it);
							}
						}
						break;

					}
					case Xeml::Document::Contracts::EO:
					{

						for (std::map<QString,OntologyHandlerResources*>::iterator it=this->EOOntologyHandler->begin();it!=this->EOOntologyHandler->end();it++){
							if (it->first==ohr->get_namespace()){
								delete it->second;
								this->EOOntologyHandler->erase(it);
							}
						}
						break;

					}
					case Xeml::Document::Contracts::EnvO:
					{
						for (std::map<QString,OntologyHandlerResources*>::iterator it=this->EnvOOntologyHandler->begin();it!=this->EnvOOntologyHandler->end();it++){
							if (it->first==ohr->get_namespace()){
								delete it->second;
								this->EnvOOntologyHandler->erase(it);
							}
						}
						break;

					}
					default:
						break;
				}
			}
			else{
				if(this->developmentalOntologyHandler->find(ohr->get_namespace())!=this->developmentalOntologyHandler->end()){
					this->developmentalOntologyHandler->erase(this->developmentalOntologyHandler->find(ohr->get_namespace()));
				}
				if(this->structuralOntologyHandler->find(ohr->get_namespace())!=this->structuralOntologyHandler->end()){
					this->structuralOntologyHandler->erase(this->structuralOntologyHandler->find(ohr->get_namespace()));
				}
				if(this->xeoOntologyHandler->find(ohr->get_namespace())!=this->xeoOntologyHandler->end()){
					this->xeoOntologyHandler->erase(this->xeoOntologyHandler->find(ohr->get_namespace()));
				}
				if(this->positionOntologyHandler->find(ohr->get_namespace())!=this->positionOntologyHandler->end()){
					this->positionOntologyHandler->erase(this->positionOntologyHandler->find(ohr->get_namespace()));
				}
				if(this->genotypeOntologyHandler->find(ohr->get_namespace())!=this->genotypeOntologyHandler->end()){
					this->genotypeOntologyHandler->erase(this->genotypeOntologyHandler->find(ohr->get_namespace()));
				}
				if(this->EOOntologyHandler->find(ohr->get_namespace())!=this->EOOntologyHandler->end()){
					this->EOOntologyHandler->erase(this->EOOntologyHandler->find(ohr->get_namespace()));
				}
				if(this->EnvOOntologyHandler->find(ohr->get_namespace())!=this->EnvOOntologyHandler->end()){
					this->EnvOOntologyHandler->erase(this->EnvOOntologyHandler->find(ohr->get_namespace()));
				}

			}
		}
		OntologyHandlerResources * DocumentResources::Add(QString _uri,
														  QString alias,
														  QString instanceLocation,
														  bool loadableOnly){
			//std::cerr << "entering add onto (document resources)" << std::endl;
			if( OntologyManager::Get_ontologyManager()->get_handler().find(_uri)==OntologyManager::Get_ontologyManager()->get_handler().end()){
				throw new exception();//
				std::cerr << "Ontology handler does not exist." << std::endl;
			}
			OntologyType ot= OntologyManager::Get_ontologyManager()->get_handler()[_uri]->get_ontologyType();
			//std::cerr << "ot : " << ot << std::endl;
			if( contains(alias, ot)){
				throw new exception();//
				std::cerr << "An ontology handler with the same type and alias already exist." << std::endl;
			}
			OntologyHandlerResources *ohr =new OntologyHandlerResources(_uri);

			ohr->set_namespace(alias);
			ohr->set_location(instanceLocation);
			ohr->loadComponent();

			if (ohr->get_component_state() == Xeml::Document::Loaded || !loadableOnly)
			{
				switch (ot)
				{
					case Xeml::Document::Contracts::Developmental:
					{
						(*this->developmentalOntologyHandler)[ohr->get_namespace()]=ohr;
						std::cerr << "ontologyhandlerresources added to devhandler : " << ohr->get_namespace().toStdString()<< std::endl;
						break;
					}
					case Xeml::Document::Contracts::OrganismStructure:
					{
						(*this->structuralOntologyHandler)[ohr->get_namespace()]=ohr;
						std::cerr << "ontologyhandlerresources added to structhandler : " << ohr->get_namespace().toStdString()<< std::endl;
						break;
					}
					case Xeml::Document::Contracts::Environment:
					{
						(*this->xeoOntologyHandler)[ohr->get_namespace()]=ohr;
						std::cerr << "ontologyhandlerresources added to xeohandler : " << ohr->get_namespace().toStdString()<< std::endl;
						break;
					}
					case Xeml::Document::Contracts::Genotype:
					{
						(*this->genotypeOntologyHandler)[ohr->get_namespace()]=ohr;
						std::cerr << "ontologyhandlerresources added to genotypehandler : " << ohr->get_namespace().toStdString()<< std::endl;
						break;
					}
					case Xeml::Document::Contracts::Positioning:
					{
						(*this->positionOntologyHandler)[ohr->get_namespace()]=ohr;
						std::cerr << "ontologyhandlerresources added to position handler : " << ohr->get_namespace().toStdString()<< std::endl;
						break;
					}
					case Xeml::Document::Contracts::EO:
					{
						(*this->EOOntologyHandler)[ohr->get_namespace()]=ohr;
						std::cerr << "ontologyhandlerresources added to EO handler : " << ohr->get_namespace().toStdString()<< std::endl;
						break;
					}
					case Xeml::Document::Contracts::EnvO:
					{
						(*this->EnvOOntologyHandler)[ohr->get_namespace()]=ohr;
						std::cerr << "ontologyhandlerresources added to EnvO handler : " << ohr->get_namespace().toStdString()<< std::endl;
						break;
					}
					default:
						break;
				}
			}
			return ohr;
		}


		bool DocumentResources::containValue(std::map<QString,OntologyHandlerResources*> * _handler,QString _alias){
			for (std::map<QString,OntologyHandlerResources*>::iterator it=_handler->begin();it!=_handler->end();it++){
				if (it->first==_alias){
					return true;
				}

			}
			return false;
		}

		bool DocumentResources::contains(QString _alias,OntologyType ot){
			switch(ot)
			{
				case Xeml::Document::Contracts::Developmental:
				{
					return this->containValue(this->developmentalOntologyHandler,_alias);
					break;
				}
				case Xeml::Document::Contracts::Environment:
				{
					return this->containValue(this->xeoOntologyHandler,_alias);
					//std::cerr << " XEO found" << std::endl;

					break;
				}
				case Xeml::Document::Contracts::OrganismStructure:
				{
					return this->containValue(this->structuralOntologyHandler,_alias);
					break;
				}
				case Xeml::Document::Contracts::Genotype:
				{
					return this->containValue(this->genotypeOntologyHandler,_alias);
					break;
				}
				case Xeml::Document::Contracts::Positioning:
				{
					return this->containValue(this->positionOntologyHandler,_alias);
					break;
				}
				case Xeml::Document::Contracts::EO:
				{
					return this->containValue(this->EOOntologyHandler,_alias);
					break;
				}
				case Xeml::Document::Contracts::EnvO:
				{
					return this->containValue(this->EnvOOntologyHandler,_alias);
					break;
				}

				default:
				{
					return false;
				}
			}
		}
		std::vector<std::pair<DataProviderResources*,QString> > * DocumentResources::get_data_provider(){
			return this->dataProvider;
		}
		bool                                                      DocumentResources::provider_contain(QString _uri){
			std::cerr << _uri.toStdString() << std::endl;
			std::cerr << "vector size : " << this->dataProvider->size() << std::endl;
			std::cerr << "-------" << std::endl;
			for (vec_pair_iterator =this->dataProvider->begin();vec_pair_iterator!=this->dataProvider->end();++vec_pair_iterator){

			}
			for (std::vector<std::pair<DataProviderResources*,QString> >::iterator ite=this->dataProvider->begin();ite!=this->dataProvider->end();++ite){
				std::cerr << "in da loop" << std::endl;

				if(static_cast<DataProviderResources*>((*ite).first)->get_uri()==_uri){
					return true;
				}
			}
			return false;

		}

		OntologyHandlerResources* DocumentResources::get_handler_by_alias(QString _alias,OntologyType _ot){
			//std::cerr << "entering get handler by alias for alias :" << _alias.toStdString() << std::endl;
			switch (_ot)
			{
				case Xeml::Document::Contracts::Developmental:
				{
					//std::cerr << "developmental : " << std::endl;
					for (std::map<QString,OntologyHandlerResources*>::iterator it=this->developmentalOntologyHandler->begin();it!=this->developmentalOntologyHandler->end();it++){
						if (static_cast<OntologyHandlerResources*>(it->second)->get_namespace()==_alias){
							return static_cast<OntologyHandlerResources*>(it->second);

						}
					}
					break;
				}
				case Xeml::Document::Contracts::OrganismStructure:
				{
					//std::cerr << "Organism structure : " << std::endl;
					for (std::map<QString,OntologyHandlerResources*>::iterator it=this->structuralOntologyHandler->begin();it!=this->structuralOntologyHandler->end();it++){
						if (it->second->get_namespace()==_alias){
							return static_cast<OntologyHandlerResources*>(it->second);
						}
					}
					break;
				}
				case Xeml::Document::Contracts::Environment:
				{
					//std::cerr << "environment : " << std::endl;
					for (std::map<QString,OntologyHandlerResources*>::iterator it=this->xeoOntologyHandler->begin();it!=this->xeoOntologyHandler->end();it++){
						//std::cerr << " namespace " << static_cast<OntologyHandlerResources*>(it->second)->get_namespace().toStdString() << std::endl;
						if (static_cast<OntologyHandlerResources*>(it->second)->get_namespace()==_alias){
							//std::cerr << "equal : " << std::endl;
							return static_cast<OntologyHandlerResources*>(it->second);

						}
					}
					break;
				}

				case Xeml::Document::Contracts::Genotype:
				{
					//std::cerr << "genotype : " << std::endl;
					for (std::map<QString,OntologyHandlerResources*>::iterator it=this->genotypeOntologyHandler->begin();it!=this->genotypeOntologyHandler->end();it++){
						if (it->second->get_namespace()==_alias){
							return static_cast<OntologyHandlerResources*>(it->second);
						}
					}
					break;
				}
				case Xeml::Document::Contracts::Positioning:
				{
					//std::cerr << "positioning : " << std::endl;
					for (std::map<QString,OntologyHandlerResources*>::iterator it=this->positionOntologyHandler->begin();it!=this->positionOntologyHandler->end();it++){
						if (it->second->get_namespace()==_alias){
							return static_cast<OntologyHandlerResources*>(it->second);
						}
					}
					break;

				}
				case Xeml::Document::Contracts::EO:
				{
					for (std::map<QString,OntologyHandlerResources*>::iterator it=this->EOOntologyHandler->begin();it!=this->EOOntologyHandler->end();it++){
						if (it->second->get_namespace()==_alias){
							return static_cast<OntologyHandlerResources*>(it->second);
						}
					}
					break;

				}
				case Xeml::Document::Contracts::EnvO:
				{
					for (std::map<QString,OntologyHandlerResources*>::iterator it=this->EnvOOntologyHandler->begin();it!=this->EnvOOntologyHandler->end();it++){
						if (it->second->get_namespace()==_alias){
							return it->second;
						}
					}
					break;

				}
				default:
					return NULL;
					break;
			}

			//std::cerr << "outing get handler by alias for alias :" << _alias.toStdString() << std::endl;



		}

		void DocumentResources::clear_handlers(){
			this->developmentalOntologyHandler->clear();
			this->structuralOntologyHandler->clear();
			this->genotypeOntologyHandler->clear();
			this->positionOntologyHandler->clear();
			this->xeoOntologyHandler->clear();
			this->EOOntologyHandler->clear();
			this->EnvOOntologyHandler->clear();
			//add other ontologies
		}


	}
}
