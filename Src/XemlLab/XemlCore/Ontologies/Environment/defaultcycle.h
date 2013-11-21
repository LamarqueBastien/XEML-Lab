#ifndef DEFAULTCYCLE_H
#define DEFAULTCYCLE_H
#include<string>
#include<list>
#include"CoreObjects/timespan.h"
#include<QDateTime>
using std::make_pair;
using std::pair;
using namespace std;
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{
			class DefaultCycle
			{
				private:
					std::list<std::pair<QDateTime,QString> > * vals;
				public:
					DefaultCycle();
					~DefaultCycle();
					void                                           addValue(QDateTime _duration, QString _val);
					std::list<std::pair<QDateTime,QString> > * get_vals();
					void                                           set_vals(std::list<std::pair<QDateTime,QString> > * _vals);
			};
		}
	}
}

#endif // DEFAULTCYCLE_H
