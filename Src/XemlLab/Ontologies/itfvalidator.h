#ifndef ITFVALIDATOR_H
#define ITFVALIDATOR_H
#include"itfvalidationsource.h"
#include"itfxemlcomponent.h"
#include"itfdocument.h"

namespace Xeml {

	namespace Document{

		namespace Contracts{
			class ItfValidator : ItfValidationSource, ItfXemlComponent
			{
				public:
					ItfValidator();
                    void Validate(ItfDocument * xemlDoc);
			};
		}
	}
}

#endif // ITFVALIDATOR_H
