#ifndef ENVOHANDLER_H
#define ENVOHANDLER_H
#include "contextlesshandler.h"
#include"obohandler.h"
#include"attributestore.h"
using namespace Xeml::Document::Ontologies::OBO;
using namespace Xeml::Document::Contracts;
using namespace Xeml::Document;
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace OBO{
				class EnvOHandler : public ContextLessHandler
				{
					public:
						EnvOHandler();
						~EnvOHandler();
						QString                                      get_publisher();
						QString                                      get_version();
						QString                                      get_componentName();
						QString                                      get_author();
						QString                                      get_description();
						QString                                      get_uri();
						OntologyType                                 get_ontologyType();

						ItfXemlComponent                           * copy();
						void                                         displayVectorContent(std::vector<QString> * vec);
						void                                         doTagTypeAnnotation(std::list<AttributeStore*> * _collection);
						AttributeStore                             * get_attribute_by_tagvalue(QString _tagValue,std::list<AttributeStore*> _collection);
				};
			}
		}
	}
}

#endif // ENVOHANDLER_H
