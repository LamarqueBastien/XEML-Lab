#ifndef ITFXEMLCOMPONENT_H
#define ITFXEMLCOMPONENT_H
#include<QString>
namespace Xeml {

	namespace Document{

		namespace Contracts{
			class ItfXemlComponent
			{
				public:
					ItfXemlComponent();
					virtual ~ItfXemlComponent();
					virtual QString            get_publisher()=0;
					virtual QString            get_version()=0;
					virtual QString            get_componentName()=0;
					virtual QString            get_author()=0;
					virtual QString            get_description()=0;
					virtual QString            get_uri()=0;
					virtual ItfXemlComponent * copy()=0;
			};
		}
	}
}

#endif // ITFXEMLCOMPONENT_H
