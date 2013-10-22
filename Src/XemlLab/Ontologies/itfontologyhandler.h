#ifndef ITFONTOLOGYHANDLER_H
#define ITFONTOLOGYHANDLER_H
#include"itfvalidationsource.h"
#include"itfxemlcomponent.h"
namespace Xeml {

	namespace Document{

		namespace Contracts{

			typedef enum
				{
				Unloaded,
				Loaded,
				LoadFailed,
				ReloadNeeded
				}OntologyLoadState;

			typedef enum
				{
				Environment,
				EO,
				EnvO,
				OrganismStructure,
				Developmental,
				Positioning,
				Genotype
				}OntologyType;


			class ItfOntologyHandler : public ItfValidationSource, public ItfXemlComponent
			{
				public:
					virtual QString                         get_namespaceAlias()=0;
					virtual void                            set_namespaceAlias(QString _namespaceAlias)=0;
					virtual QString                         get_namespace()=0;
					virtual void                            set_namespace(QString _namespace)=0;
					virtual bool                            get_autoValidation()=0;
					virtual void                            set_autoValidation(bool _autovalidation)=0;
					virtual QString                         get_instanceLocation()=0;
					virtual void                            set_instanceLocation(QString _instancelocation)=0;
					virtual OntologyLoadState               get_ontologyLoadState()=0;
					virtual QString                         get_ontologyLoadMessage()=0;
					virtual OntologyType                    get_ontologyType()=0;
					virtual void                            load(QString nameSpaceAlias)=0;
					virtual void                            load(QString nameSpaceAlias, bool force)=0;
					//virtual ItfXemlComponent *                               copy()=0;

					ItfOntologyHandler();
			};


		}
	}
}

#endif // ITFONTOLOGYHANDLER_H
