#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include<vector>
#include<QString>
#include<QStringList>
#include<QDateTime>
using namespace std;
namespace Xeml{

	namespace Utilities{

		template<typename T>
		inline std::string to_string( const T & Value )
		{
			// utiliser un flux de sortie pour créer la chaîne
			std::ostringstream oss;
			// écrire la valeur dans le flux
			oss << Value;
			// renvoyer une string
			return oss.str();
		}
		inline double String_to_double( const std::string & s )
		{
			std::istringstream i(s);
			double x;
			if (!(i >> x))
				return 0;
			return x;
		}
		inline bool to_bool(std::string str) {
			std::transform(str.begin(), str.end(), str.begin(), ::tolower);
			std::istringstream is(str);
			bool b;
			is >> std::boolalpha >> b;
			return b;
		}
		inline QString toStringdoublenumber(bool _IsDay,qint64 _value){
			std::ostringstream oss;
			oss << _value;
			std::string ret;
			if(_IsDay){
				ret=oss.str();
				return QString(ret.c_str());
			}
			else{
				if (_value >=0 && _value <=9){
					ret="0"+oss.str();
					return QString(ret.c_str());
				}

				else{
					ret=oss.str();
					return QString(ret.c_str());
				}
			}

		}
		inline qint64 calculate_time(QDateTime _startDate,QDateTime _endDate){
			qint64 ellapsed_second_target=_startDate.toMSecsSinceEpoch();
			qint64 ellapsed_second_query=_endDate.toMSecsSinceEpoch();
			qint64 difference=ellapsed_second_target -ellapsed_second_query;
			//QDateTime my_final=QDateTime::fromMSecsSinceEpoch(difference);
			return difference;
		}
		inline qint64 get_seconds_from_date(QDateTime startDate,QDateTime _currentdate){
			qint64 second_since_start=startDate.toMSecsSinceEpoch();
			//std::cerr << startDate.toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;
			qint64 second_from_now=_currentdate.toMSecsSinceEpoch();
			//std::cerr << _currentdate.toString("dd-MM-yyyyThh:mm:ss").toStdString() << std::endl;

			qint64 diff=second_from_now-second_since_start;
			//std::cerr << "diff in getSecondFromDate : " << diff << std::endl;
			return diff;
		}
		inline QDateTime get_date(QDateTime startDate,qint64 milliseconds_to_add){
			//std::cerr << "get date" << std::endl;
			qint64 total_milliseconds=startDate.toMSecsSinceEpoch()+milliseconds_to_add;
			QDateTime date=QDateTime::fromMSecsSinceEpoch(total_milliseconds);
			//std::cerr << "get date" << std::endl;
			return date;
			//std::cerr << "get date" << std::endl;
		}

		inline qint64 translate_DD_HH_MM_SS_in_Msecs(QString _timepoint){
			//std::cerr << "entering translate in Msecs" << std::endl;
			//std::cerr << "timepoint " << _timepoint.toStdString() << std::endl;
			QStringList list1=_timepoint.split(".");

			//std::cerr << "entering translate in Msecs" << std::endl;

			QString daystring;
			QString hourstring;
			QString minutestring;
			QString secondstring;

			qint64 days=0;
			qint64 hours=0;
			qint64 minutes=0;
			qint64 seconds=0;

			qint64 total_milliseconds;

			if(list1.size()==2){
				//std::cerr << "list==2" << std::endl;
				daystring=list1.at(0);
				QStringList list2=list1.at(1).split(":");
				hourstring=list2.at(0);
				minutestring=list2.at(1);
				secondstring=list2.at(2);
				days=daystring.toInt();
				hours=hourstring.toInt();
				//std::cerr << "hour : " << hours << std::endl;

				minutes=minutestring.toInt();
				seconds=secondstring.toInt();
				total_milliseconds=days*86400000+hours*3600000+minutes*60000+seconds*1000;
			}
			else{
				list1.clear();
				//std::cerr << "list!=2" << std::endl;
				list1=_timepoint.split(":");
				hourstring=list1.at(0);
				minutestring=list1.at(1);
				secondstring=list1.at(2);
				//std::cerr << "before hour in int : " << std::endl;
				hours=hourstring.toInt();
				//std::cerr << "hour : " << hours << std::endl;
				minutes=minutestring.toInt();
				seconds=secondstring.toInt();
				total_milliseconds=hours*3600000+minutes*60000+seconds*1000;
			}
			//std::cerr << "total milliseconds : " << total_milliseconds << std::endl;

			return total_milliseconds;
		}

		inline QString translate_second_in_DD_HH_MM_SS(qint64 _milliseconds){
			qint64 n;		/* n : durée donnée en secondes */
			qint64 r;		/* r : le reste du modulo */
			//bool isNull=false;

			qint64 days=0;
			qint64 hours=0;
			qint64 minutes=0;
			qint64 seconds=0;/* a : la quantité de jours, heures, minutes ou secondes */
			//std::vector<int> * tab=new std::vector<int>();

			n=_milliseconds;
			if (n>=0){
				/* 1 jour = 24*60*60 = 86400 secondes */
				r=n%86400000;		/* on calcul le reste */
				days=(n-r)/86400000;
				//std::cerr << "days = " << days << std::endl;
				//tab->push_back(days);
				n=r;			/* on ne retient que les secondes restantes */
				r=n%3600000;		/* on calcul le reste */
				hours=(n-r)/3600000;
				if(days>=30){
					//hours--;
				}
				//std::cerr << "hours = " << hours << std::endl;
				//tab->push_back(hours);
				n=r;		/* on ne retient que les secondes restantes */
				r=n%60000;		/* on calcul le reste */
				minutes=(n-r)/60000;
				//std::cerr << "minutes = " << minutes << std::endl;
				//tab->push_back(minutes);
				seconds=r/1000;
				//std::cerr << "seconds = " << seconds << std::endl;

				//tab->push_back(seconds);

			}
			/*
			else if(n==0){
				isNull=true;
			}
			*/
			else{
				std::cerr << "erreur : nombre négatif !!!!!\n" << std::endl;
			}
			QString current_time;
			if(days==0){
				current_time=toStringdoublenumber(false,hours)+":"+toStringdoublenumber(false,minutes)+":"+toStringdoublenumber(false,seconds);

			}

			/*
			else if(isNull){
				current_time="00:00:00";
			}
			*/
			else{
				current_time=toStringdoublenumber(true,days)+"."+toStringdoublenumber(false,hours)+":"+toStringdoublenumber(false,minutes)+":"+toStringdoublenumber(false,seconds);
			}
				return current_time;
		}
		inline int translate_second_in_distance(qint64 _milliseconds){
			qint64 n;		/* n : durée donnée en secondes */
			qint64 r;		/* r : le reste du modulo */
			//bool isNull=false;

			qint64 days=0;
			qint64 hours=0;
			qint64 minutes=0;
			qint64 seconds=0;/* a : la quantité de jours, heures, minutes ou secondes */
			//std::vector<int> * tab=new std::vector<int>();

			n=_milliseconds;
			if (n>=0){
				/* 1 jour = 24*60*60 = 86400 secondes */
				r=n%86400000;		/* on calcul le reste */
				days=(n-r)/86400000;
				//std::cerr << "days = " << days << std::endl;
				//tab->push_back(days);
				n=r;			/* on ne retient que les secondes restantes */
				r=n%3600000;		/* on calcul le reste */
				hours=(n-r)/3600000;
				if(days>=30){
					//hours--;
				}
				//std::cerr << "hours = " << hours << std::endl;
				//tab->push_back(hours);
				n=r;		/* on ne retient que les secondes restantes */
				r=n%60000;		/* on calcul le reste */
				minutes=(n-r)/60000;
				//std::cerr << "minutes = " << minutes << std::endl;
				//tab->push_back(minutes);
				seconds=r/1000;
				//std::cerr << "seconds = " << seconds << std::endl;

				//tab->push_back(seconds);

			}

			/*
			else if(n==0){
				isNull=true;
			}
			*/
			else{
				std::cerr << "erreur : nombre négatif !!!!!\n" << std::endl;
			}
			//QString current_time;
			int distance=days*24+hours+minutes/60+seconds/3600;
			/*
			if(days==0){
				current_time=toStringdoublenumber(false,hours)+":"+toStringdoublenumber(false,minutes)+":"+toStringdoublenumber(false,seconds);

			}
			*/
			/*
			else if(isNull){
				current_time="00:00:00";
			}
			*/
			/*
			else{
				current_time=toStringdoublenumber(true,days)+"."+toStringdoublenumber(false,hours)+":"+toStringdoublenumber(false,minutes)+":"+toStringdoublenumber(false,seconds);
			}
			*/
				return distance;
		}
		inline qreal translate_second_in_real_distance(qint64 _milliseconds){

			qint64 n;
			/*

			qint64 r;


			qint64 days=0;
			qint64 hours=0;
			qint64 minutes=0;
			qint64 seconds=0;


			*/
			n=_milliseconds;

			if (n>=0){

				/*
				r=n%86400000;
				days=(n-r)/86400000;

				n=r;
				r=n%3600000;
				hours=(n-r)/3600000;
				if(days>=30){

				}

				n=r;
				r=n%60000;
				minutes=(n-r)/60000;

				seconds=r/1000;
				*/


			}

			/*
			else if(n==0){
				isNull=true;
			}
			*/
			else{
				std::cerr << "erreur : nombre négatif !!!!!\n" << std::endl;
			}
			//QString current_time;
			//RETURN TIME IN MINUTES
			qreal distance=_milliseconds/60000;
			//double distance=days*24+hours+minutes/60+seconds/3600;
			/*
			if(days==0){
				current_time=toStringdoublenumber(false,hours)+":"+toStringdoublenumber(false,minutes)+":"+toStringdoublenumber(false,seconds);

			}
			*/
			/*
			else if(isNull){
				current_time="00:00:00";
			}
			*/
			/*
			else{
				current_time=toStringdoublenumber(true,days)+"."+toStringdoublenumber(false,hours)+":"+toStringdoublenumber(false,minutes)+":"+toStringdoublenumber(false,seconds);
			}
			*/
				return distance;
		}
		inline qint64 translate_Distance_in_Msecs(qint64 pixel){
			//qint64 total_milliseconds=;
			//std::cerr << "translate distance" << std::endl;
			return pixel*3600000;
			//std::cerr << "translate distance" << std::endl;
		}



	}
}
#endif // UTILITIES_H
