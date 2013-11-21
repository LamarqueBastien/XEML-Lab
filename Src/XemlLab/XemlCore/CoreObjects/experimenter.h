#ifndef EXPERIMENTER_H
#define EXPERIMENTER_H
#include<string>
#include <iostream>
#include<QString>
namespace Xeml {

	namespace Document{

		class Experimenter
		{
			private:
				QString firstname;
				QString lastname;
				QString email;
				QString organization;

			public:
				Experimenter();

				Experimenter(QString _firstname,
							 QString _lastname,
							 QString _email,
							 QString _organization);
				~Experimenter();
				QString get_firstname();
				QString get_lastname();
				QString get_email();
				QString get_organization();
				void    set_firstname(QString _firstname);
				void    set_lastname(QString _lastname);
				void    set_email(QString _email);
				void    set_organization(QString _organization);
				void    clear();
				bool    is_null_or_empty(QString value);
				bool    is_empty();


		};
	}
}

#endif // EXPERIMENTER_H
