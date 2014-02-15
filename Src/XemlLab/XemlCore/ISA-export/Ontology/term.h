#ifndef TERM_H
#define TERM_H
#include<QString>



class Term
{
	public:
		Term();
		QString get_name();
		QString get_accession_number();
		void set_name(QString _name);
		void set_accession_number(QString _accession_number);
	private:
		QString name;
		QString accession_number;
};

#endif // TERM_H
