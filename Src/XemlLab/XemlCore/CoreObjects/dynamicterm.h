#ifndef DYNAMICTERM_H
#define DYNAMICTERM_H

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
				bool IsMeasuredVariable;

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
				void                                    set_measured_variable(bool _IsMeasured);
				bool                                    get_measured_variable();
		};
	}
}

#endif // DYNAMICTERM_H
