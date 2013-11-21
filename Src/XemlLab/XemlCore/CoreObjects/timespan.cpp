#include "timespan.h"
namespace Xeml{

	namespace Document{

		TimeSpan::TimeSpan(){

		}
		TimeSpan::TimeSpan(int _hours, int _minutes,int _seconds){

			this->days=0;
			this->duration=true;
			this->hours=_hours;
			this->minutes=_minutes;
			this->seconds=_seconds;
			this->ticks=86400*this->days+3600*this->hours+60*this->minutes+this->seconds;

		}
		TimeSpan::TimeSpan(int _days, int _hours, int _minutes, int _seconds){
			this->duration=false;
			this->days=_days;
			this->hours=_hours;
			this->minutes=_minutes;
			this->seconds=_seconds;
			this->ticks=86400*this->days+3600*this->hours+60*this->minutes+this->seconds;

		}
		TimeSpan::TimeSpan(const TimeSpan &t){

			this->days = t.days;
			this->hours=t.hours;
			this->minutes=t.minutes;
			this->seconds=t.seconds;
			this->ticks=86400*this->days+3600*this->hours+60*this->minutes+this->seconds;

		}
		TimeSpan::~TimeSpan(void){

		}
		void TimeSpan::add(TimeSpan *_timespan){
			this->days+=_timespan->days;
			this->hours+=_timespan->hours;
			this->minutes+=_timespan->minutes;
			this->seconds+=_timespan->seconds;
		}

		void TimeSpan::subtract(TimeSpan *_timespan){
			this->days-=_timespan->days;
			this->hours-=_timespan->hours;
			this->minutes-=_timespan->minutes;
			this->seconds-=_timespan->seconds;
		}

		std::string TimeSpan::toString(int value){
			std::ostringstream oss;
			oss << value;
			return oss.str();
		}
		std::string TimeSpan::toStringnotfordays(int value){
			std::ostringstream oss;
			oss << value;
			if (value == 0){
				return "0"+oss.str();
			}
			else if (value == 1){
				return "0"+oss.str();
			}
			else if (value == 2){
				return "0"+oss.str();
			}
			else if (value == 3){
				return "0"+oss.str();
			}
			else if (value == 4){
				return "0"+oss.str();
			}
			else if (value == 5){
				return "0"+oss.str();
			}
			else if (value == 6){
				return "0"+oss.str();
			}
			else if (value == 7){
				return "0"+oss.str();
			}
			else if (value == 8){
				return "0"+oss.str();
			}
			else if (value == 9){
				return "0"+oss.str();
			}
			else{
				return oss.str();
			}

		}
		bool TimeSpan::isEqual(TimeSpan const& b) const
		{

			if (this->days==b.days && this->hours == b.hours && this->minutes == b.minutes && this->seconds == b.seconds)
				return true;
			else
				return false;
		}


		TimeSpan& TimeSpan::operator+=(const TimeSpan &timespan)
		{
			// 1 : ajout des secondes
			this->seconds += timespan.seconds; // Exceptionnellement autorisÈ car mÍme classe
			// Si le nombre de secondes dÈpasse 60, on rajoute des minutes et on met un nombre de secondes infÈrieur ‡ 60
			this->minutes += this->seconds / 60;
			this->seconds %= 60;

			// 2 : ajout des minutes
			this->minutes += timespan.minutes;
			// Si le nombre de minutes dÈpasse 60, on rajoute des heures et on met un nombre de minutes infÈrieur ‡ 60
			this->hours += this->minutes / 60;
			this->minutes %= 60;

			// 3 : ajout des heures
			this->hours += timespan.hours;
			// Si le nombre d'e minutes'heure dÈpasse 24, on rajoute des jours et on met un nombre de heures infÈrieur à 24
			this->days+=this->hours / 24;
			this->hours %=24;

			// 3 : ajout des jours
			this->days += timespan.days;


			return *this;
		}



		std::string TimeSpan::get_timespan_str_format(){
			std::ostringstream oss;

			return toStringnotfordays(this->days)+"."+toStringnotfordays(this->hours)+":"+toStringnotfordays(this->minutes)+":"+toStringnotfordays(this->seconds);
			//return mot;
		}

		QString TimeSpan::get_timespan_Qstr_format(){
			//std::ostringstream oss;
			std::string mot;
			QString tmp;//=this->days+"."+this->hours+":"+this->minutes+":"+this->seconds;
			// vérifier les différents cas
			if(this->duration){
				mot=toStringnotfordays(this->hours)+":"+toStringnotfordays(this->minutes)+":"+toStringnotfordays(this->seconds);

			}
			else{
				mot=toStringnotfordays(this->days)+"."+toStringnotfordays(this->hours)+":"+toStringnotfordays(this->minutes)+":"+toStringnotfordays(this->seconds);
			}
			return tmp.fromStdString(mot);
		}


		bool TimeSpan::isLessOrEqual(TimeSpan const& b) const
		{
			if (this->days < b.days)
				return true;
			else if (this->days == b.days && this->hours < b.hours)
				return true;
			else if (this->days == b.days && this->hours == b.hours && this->minutes < b.minutes)
				return true;
			else if (this->days == b.days && this->hours == b.hours  && this->minutes == b.minutes && this->seconds < b.seconds)
				return true;
			else if (this->days == b.days && this->hours == b.hours  && this->minutes == b.minutes && this->seconds == b.seconds)
				return true;
			else
				return false;
		}
		//OPERATEURS
		//##################
		bool operator==(TimeSpan const& a, TimeSpan const& b){
			return a.isEqual(b);
		}
		TimeSpan operator+(TimeSpan const& a, TimeSpan const& b)
		{
			TimeSpan copie(a);
			copie += b;
			return copie;
		}
		bool operator<=(TimeSpan const &a, TimeSpan const& b)
		{
			if(a.isLessOrEqual(b))
				return true;
			else
				return false;
		}
	}
}
