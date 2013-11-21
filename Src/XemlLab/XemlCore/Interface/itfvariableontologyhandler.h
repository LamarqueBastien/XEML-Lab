#ifndef ITFVARIABLEONTOLOGYHANDLER_H
#define ITFVARIABLEONTOLOGYHANDLER_H
#include<map>
#include"CoreObjects/basicterm.h"
#include"Interface/itfontologyterm.h"
#include"Interface/itfontologyhandler.h"
//using Xeml::Document::Term;
using Xeml::Document::BasicTerm;

namespace Xeml {

	namespace Document{

		namespace Contracts{

			class ItfVariableOntologyHandler : public ItfOntologyHandler
			{
				public:
					ItfVariableOntologyHandler();
					virtual std::map<QString,ItfVariableOntologyTerm*> * get_terms()=0;
					virtual ItfVariableOntologyTerm                  * findKey(BasicTerm param)=0;
					virtual ItfVariableOntologyTerm                  * findKey(QString termId)=0;
			};
		}
	}
}

#endif // ITFVARIABLEONTOLOGYHANDLER_H
