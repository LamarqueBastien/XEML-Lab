#ifndef CONTEXTLESSHANDLER_H
#define CONTEXTLESSHANDLER_H
#include"obohandler.h"
#include"itfdynamicontologyhandler.h"
#include"itfontologyterm.h"
#include"itfxemlcomponent.h"
#include"itfontologyhandler.h"
#include<QString>
using namespace std;
using namespace Xeml::Document::Ontologies::OBO;
using namespace Xeml::Document::Contracts;

namespace Xeml{

	namespace Document{

		namespace Ontologies{

			namespace OBO{
				class ContextLessHandler : public OboHandler
				{
					public:
						ContextLessHandler();
						~ContextLessHandler();
						void buildContexts(std::list<AttributeStore*> *_collection);
						VariableContextSpec * createQuantityContext(QString _contextName);
						VariableContextSpec * createResponseRangeContext(QString _contextName);
						VariableContextSpec * createFreeTextContext();

				};
			}
		}
	}
}

#endif // CONTEXTLESSHANDLER_H
