#ifndef STORYBASE_H
#define STORYBASE_H
#include<iostream>
#include<string>
#include<map>
#include<vector>
//#include<ctime>
#include"CoreObjects/xemlannotableobject.h"
#include"CoreObjects/event.h"
#include"CoreObjects/basicterm.h"
//#include"eventcollection.h"
//#include "individualspool.h"
#include"CoreObjects/observationpoint.h"
//#include "variablecollection.h"
//#include"storyboard.h"
#include "CoreObjects/timespan.h"
#include<QDateTime>
using std::pair;
using std::make_pair;
//using namespace std;
namespace Xeml {

	namespace Document{


		class StoryBase : public XemlAnnotableObject
		{
			protected:

				QString                                                label;
				std::map<Event*,QDateTime>                           * eventcollection;
				std::map<Event*,QDateTime>::iterator                   iter;
				bool                                                   IsStorySplit;
				std::vector<std::pair<BasicTerm*,QString> >          * variablesCollection;
				std::vector<std::pair<ObservationPoint*,QDateTime> > * observationPointcollection;



			public:

				StoryBase();
				~StoryBase();
				virtual QString                                        get_label()=0;
				virtual void                                           set_label(QString _label)=0;
				std::vector<std::pair<ObservationPoint*,QDateTime> > * get_obsPointCollection();
				void                                                   set_obsPointCollection(std::vector<std::pair<ObservationPoint*,QDateTime> > * _opc);
				std::map<TaggedAnnotation*,QString>                  * get_taggedannotation();
				void                                                   add_tagged_annotation(TaggedAnnotation *TA);
				void                                                   add_event(Event * _event);
				void                                                   rm_event(QString _labelEvent);
				void									               add_variable(BasicTerm * t);
				BasicTerm *                                            get_variable(QString _termId);
				void                                                   display_all_events();
				void                                                   display_specific_timepoint(Event* _event);
				bool                                                   contain_event(Event* event);
				bool                                                   contain_variable(BasicTerm * t);
				bool                                                   contain_variableId(QString _termId);
				bool                                                   contain_obsPoint(ObservationPoint * _op);
				void									               add_obsPoint(ObservationPoint* _op);
				std::list<int> *									   rm_obsPoint(int _id);
				int                                                    count_variables();
				void                                                   rm_variable(QString _termId);
				int                                                    count_event();
				std::map<Event*,QDateTime>                           * get_eventcollection();
				std::vector<std::pair<BasicTerm*,QString> >          * get_variablesCollection();
				ObservationPoint                                     * get_obsPoint(int _id);
				bool                                                   get_IsStorySplit();
				void                                                   set_IsStorySplit(bool _IsStorySplit);


		};
	}
}

#endif // STORYBASE_H
