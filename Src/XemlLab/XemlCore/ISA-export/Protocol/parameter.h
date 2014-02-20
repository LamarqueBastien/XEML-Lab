#ifndef PARAMETER_H
#define PARAMETER_H
#include"ISA-export/Ontology/term.h"

using namespace XemlUtilities::ISA::Ontology;
using namespace std;

namespace XemlUtilities{

	namespace ISA{

		namespace Protocol{

			class Parameter
			{
				public:
					//Parameter();
					QString name;
					XemlUtilities::ISA::Ontology::Term * accesion_number;
					QString value;
			};
		}
	}
}

#endif // PARAMETER_H
