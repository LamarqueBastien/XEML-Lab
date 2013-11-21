#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <QString>
#include<iostream>
#include<sstream>


namespace Xeml{

	namespace Document{
		class TimeSpan
		{
			private:
				int         days;
				int         hours;
				int         minutes;
				int         seconds;
				int         ticks;
				bool duration;

			public:
				TimeSpan();

				TimeSpan( int _hours,
						  int _minutes,
						  int _seconds);

				TimeSpan( int _days,
						  int _hours,
						  int _minutes,
						  int _seconds );

				TimeSpan(const TimeSpan & ts);
				//static TimeSpan * parse(std::string _TSStr);
				TimeSpan &  operator+=(const TimeSpan &timespan);
				~TimeSpan();
				void        add(TimeSpan *_timespan);
				void        subtract(TimeSpan *_timespan);
				bool        isEqual(TimeSpan const& b) const;
				bool        isLessOrEqual(TimeSpan const& b) const;
				std::string toString(int value);
				std::string toStringnotfordays(int value);
				std::string get_timespan_str_format();
				QString     get_timespan_Qstr_format();

		};
		TimeSpan            operator+(TimeSpan const& a, TimeSpan const& b);
		bool                operator==(TimeSpan const& a, TimeSpan const& b);
		bool                operator<=(TimeSpan const& a, TimeSpan const& b);
	}
}

#endif // TIMESPAN_H
