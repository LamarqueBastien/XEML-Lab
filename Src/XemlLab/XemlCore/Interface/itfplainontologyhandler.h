#ifndef ITFPLAINONTOLOGYHANDLER_H
#define ITFPLAINONTOLOGYHANDLER_H
//#include<list>
#include<map>
#include"CoreObjects/basicterm.h"
#include"Interface/itfontologyterm.h"
#include"Interface/itfontologyhandler.h"
//using Xeml::Document::Term;
using Xeml::Document::BasicTerm;
using namespace std;
namespace Xeml {

	namespace Document{

		namespace Contracts{

			class ItfPlainOntologyHandler : public ItfOntologyHandler
			{

				public:
					ItfPlainOntologyHandler();
					virtual std::map<QString,ItfOntologyTerm*> get_terms()=0;
					//virtual bool contain(Term param)=0;
					virtual ItfOntologyTerm                  * findKey(BasicTerm param)=0;
					virtual ItfOntologyTerm                  * findKey(QString termId)=0;
			};
		}
	}
}

#endif // ITFPLAINONTOLOGYHANDLER_H
