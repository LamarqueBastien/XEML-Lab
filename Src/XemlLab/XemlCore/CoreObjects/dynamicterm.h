#ifndef DYNAMICTERM_H
#define DYNAMICTERM_H
#include"term.h"
#include"basicterm.h"
#include"dynamicvaluebase.h"
#include"timespan.h"
#include<vector>

#include<string>
#include<QString>
#include<list>
#include<map>
using namespace std;
using Xeml::Document::BasicTerm;
using std::pair;
using std::make_pair;

namespace Xeml {

	namespace Document{

		class DynamicTerm : public BasicTerm
		{
			private:
				std::vector<pair<DynamicValueBase*,QDateTime> > * dynamicvaluecollection;

			public:
				DynamicTerm();
				~DynamicTerm();
				DynamicTerm(QString _termId);
				DynamicTerm(const DynamicTerm& term);
				std::vector<pair<DynamicValueBase*,QDateTime> > * get_dynamicvaluecollection();
				void                                    add_dynamicvalue(DynamicValueBase* _value);//,QDateTime _timepoint);
				bool                                    contains(QString _context,std::list<QString> * _contextList);
				bool                                    contain(QString _context,std::list<DynamicValueBase*> * _valueList);
				bool                                    find(DynamicValueBase  *vb);
				std::list<QString>                * contextList();
				std::list<DynamicValueBase*>          * valueBy(QString _context);
		};
	}
}

#endif // DYNAMICTERM_H
