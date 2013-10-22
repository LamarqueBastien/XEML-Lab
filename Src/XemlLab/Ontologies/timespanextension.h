#ifndef TIMESPANEXTENSION_H
#define TIMESPANEXTENSION_H
#include"timespan.h"
#include<QRegExp>
#include<QStringList>
using namespace std;
using namespace Xeml::Document;




namespace Xeml{

	namespace Utilities{

		typedef enum
		{
			DoubleIsDay,
			DoubleIsHour

		}TimeSpanParseOption;

		typedef enum
		{
			DayToSecond,
			DayToMinute,
			DayToHour,
			HourToSecond,
			HourToMinute,
			Hour,
			Day,
			Invalid

		}TimeSpanSyntax;

		class TimeSpanExtension
		{
			public:

				static TimeSpan     * parse(QString timespanStr);
				static TimeSpan     * parse(QString timespanStr,TimeSpanParseOption opt);
				static TimeSpan     * tryTimeSpanSet(QString _tstring);
				static TimeSpanSyntax evaluate(QString timespanStr,TimeSpanParseOption opt);
				static TimeSpan     * create(QString _timespanStr,TimeSpanSyntax _tss);
				/*
				static QString    validPattern(TimeSpanParseOption opt);
				static QString    optimizedStringRepresentation(QString timespanStr,TimeSpanParseOption opt);
				static TimeSpanSyntax optimizeLevel(QString timespanStr,TimeSpanParseOption opt);
				static QString    readableValueDuration(TimeSpan * ts);
				static QString    readableValuePoint(TimeSpan * ts);
				*/
		};
	}
}

#endif // TIMESPANEXTENSION_H
