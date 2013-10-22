#include "timespanextension.h"

namespace Xeml{

	namespace Utilities{

		TimeSpan * TimeSpanExtension::parse(QString timespanStr){

			return TimeSpanExtension::parse(timespanStr,Xeml::Utilities::DoubleIsDay);

		}
		TimeSpan * TimeSpanExtension::tryTimeSpanSet(QString _tstring){

			if(evaluate(_tstring,Xeml::Utilities::DoubleIsDay) == Xeml::Utilities::Invalid){
				std::cerr << "Invalid TimeFormat : " << _tstring.toStdString() << std::endl;
			}
			return parse(_tstring);
		}
		TimeSpan * TimeSpanExtension::parse(QString _timespanStr,TimeSpanParseOption opt){
			TimeSpan * ret;// = new TimeSpan(0,0,0,0);
			TimeSpanSyntax tss = TimeSpanExtension::evaluate(_timespanStr,opt);
			ret=TimeSpanExtension::create(_timespanStr,tss);

			return ret;

		}
		TimeSpan * TimeSpanExtension::create(QString _timespanStr,TimeSpanSyntax _tss){

			QString time = _timespanStr;
			QStringList list;
			TimeSpan * ret;
			switch (_tss)
			{
				case Xeml::Utilities::DayToSecond:
				{

					list = time.split(".");
					QString day=list.at(0);
					QString hours= list.at(1).split(":").at(0);
					QString minutes =list.at(1).split(":").at(1);
					QString seconds= list.at(1).split(":").at(2);
					ret = new TimeSpan(day.toInt(),hours.toInt(),minutes.toInt(),seconds.toInt());
					break;

				}
				case Xeml::Utilities::DayToMinute:
				{
					list = time.split(".");
					QString day=list.at(0);
					QString hours= list.at(1).split(":").at(0);
					QString minutes =list.at(1).split(":").at(1);
					ret = new TimeSpan(day.toInt(),hours.toInt(),minutes.toInt());
				}
				case Xeml::Utilities::HourToSecond:
				{

					list = time.split(":");

					QString hours= list.at(0);
					QString minutes =list.at(1);
					QString seconds =list.at(2);
					ret = new TimeSpan(hours.toInt(),minutes.toInt(),seconds.toInt());
				}
			}
			return ret;


		}

		TimeSpanSyntax TimeSpanExtension::evaluate(QString timespanStr,TimeSpanParseOption opt){
			QRegExp * DtS = new QRegExp("^([0-9][0-9]*\\.){1}(([0-1][0-9])|([2][0-3])){1}(:[0-5][0-9]){2}");
			QRegExp * DtM = new QRegExp("^([0-9][0-9]*\\.){1}(([0-1][0-9])|([2][0-3])){1}(:[0-5][0-9]){1}");
			QRegExp * DtH = new QRegExp("^([0-9][0-9]*\\.){1}(([0-1][0-9])|([2][0-3])){1}");
			QRegExp * HtS = new QRegExp("^(([0-1][0-9])|([2][0-3])){1}(:[0-5][0-9]){2}");
			QRegExp * HtM = new QRegExp("^(([0-1][0-9])|([2][0-3])){1}(:[0-5][0-9]){1}");
			QRegExp * tmp;
			//QRegExp * H = new QRegExp("^(([2][0-3])|([0-1]{0,1}[0-9]))");
			//QRegExp * D = new QRegExp("^([0-9][0-9]*)");

			if(DtS->exactMatch(timespanStr)){
				return Xeml::Utilities::DayToSecond;
			}
			if(DtM->exactMatch(timespanStr)){

				return Xeml::Utilities::DayToMinute;
			}
			if(DtH->exactMatch(timespanStr)){
				return Xeml::Utilities::DayToHour;
			}
			if(HtS->exactMatch(timespanStr)){
				return Xeml::Utilities::HourToSecond;
			}
			if(HtM->exactMatch(timespanStr)){
				return Xeml::Utilities::HourToMinute;
			}
			//QRegExp * tmp;
			if(opt == Xeml::Utilities::DoubleIsHour){
				tmp = new QRegExp("^(([2][0-3])|([0-1]{0,1}[0-9]))");
			}
			else{
				tmp = new QRegExp("^([0-9][0-9]*)");
			}
			if(tmp->exactMatch(timespanStr)){
				if(opt == Xeml::Utilities::DoubleIsHour){
					return Xeml::Utilities::Hour;
				}
				else{
					return Xeml::Utilities::Day;
				}
			}
			return Xeml::Utilities::Invalid;



		}
/*
		QString TimeSpanExtension::validPattern(TimeSpanParseOption opt){

		}

		QString TimeSpanExtension::optimizedStringRepresentation(QString timespanStr,TimeSpanParseOption opt){

		}

		TimeSpanSyntax TimeSpanExtension::optimizeLevel(QString timespanStr,TimeSpanParseOption opt){

		}

		QString TimeSpanExtension::readableValueDuration(TimeSpan * ts){

		}

		QString TimeSpanExtension::readableValuePoint(TimeSpan * ts){

		}
		*/
	}
}
