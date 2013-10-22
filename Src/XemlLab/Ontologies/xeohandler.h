#ifndef XEOHANDLER_H
#define XEOHANDLER_H
#include"obohandler.h"
#include"itfdynamicontologyhandler.h"
#include"itfontologyterm.h"
#include"itfxemlcomponent.h"
#include"itfontologyhandler.h"
#include<QString>
#include<map>
#include<list>
#include<exception>
#include<algorithm>
using namespace Xeml::Document::Ontologies::OBO;
using namespace Xeml::Document::Contracts;
namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace OBO{

				class XeoHandler : public OboHandler
				{
					public:
						XeoHandler();
						~XeoHandler();
						QString                                      get_publisher();
						QString                                      get_version();
						QString                                      get_componentName();
						QString                                      get_author();
						QString                                      get_description();
						QString                                      get_uri();
						ItfXemlComponent                           * copy();
						void                                         doTagTypeAnnotation(std::list<AttributeStore*> * _collection);
						void                                         buildContexts(std::list<AttributeStore*> *_collection);
						void                                         displayVectorContent(std::vector<QString> * vec);
						AttributeStore                             * get_attribute_by_tagvalue(QString _tagValue,std::list<AttributeStore*> * _collection);

				};
			}
		}
	}
}

#endif // XEOHANDLER_H
