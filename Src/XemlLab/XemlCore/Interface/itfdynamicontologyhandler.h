#ifndef ITFDYNAMICONTOLOGYHANDLER_H
#define ITFDYNAMICONTOLOGYHANDLER_H
//#include<list>
#include<map>
#include"CoreObjects/basicterm.h"
#include"Interface/itfontologyterm.h"
#include"Interface/itfontologyhandler.h"
using Xeml::Document::BasicTerm;
//using Xeml::Document::Term;
using namespace std;
namespace Xeml {

	namespace Document{

		namespace Contracts{

			class ItfDynamicOntologyHandler : public ItfOntologyHandler
			{
					//private:
					//std::map<ItfOntologyTerm*,QString> terms;
				public:
					ItfDynamicOntologyHandler();
					virtual std::map<QString,ItfDynamicOntologyTerm*> get_terms()=0;
					//virtual std::list<ItfDynamicOntologyTerm*> get_terms()=0;
					//virtual bool contain(Term param)=0;
					virtual ItfDynamicOntologyTerm                  * findKey(BasicTerm param)=0;
					virtual ItfDynamicOntologyTerm                  * findKey(QString termId)=0;
			};
		}
	}
}



#endif // ITFDYNAMICONTOLOGYHANDLER_H
