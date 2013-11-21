#ifndef ITFVALIDATIONSOURCE_H
#define ITFVALIDATIONSOURCE_H
#include<QString>
namespace Xeml {

	namespace Document{

		namespace Contracts{
			class ItfValidationSource
			{
				public:
					ItfValidationSource();
					virtual QString get_validation_events()=0;
			};
		}
	}
}

#endif // ITFVALIDATIONSOURCE_H
