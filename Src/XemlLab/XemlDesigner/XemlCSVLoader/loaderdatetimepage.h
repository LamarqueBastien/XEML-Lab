#ifndef LOADERDATETIMEPAGE_H
#define LOADERDATETIMEPAGE_H
#include<QtWidgets>
#include <iostream>
using namespace std;
class LoaderDateTimePage  : public QWidget
{
		Q_OBJECT
	public:
		LoaderDateTimePage(int _column,int _row,QWidget * parent=0);
		QPushButton        * cancelButton;
		QPushButton        * okButton;
		QPushButton        * add_new_expression;
		int       row;
		int column;
		QLineEdit * year;
		QLineEdit * month;
		QLineEdit * day;
		QLineEdit * hour;
		QLineEdit * minute;
		QLineEdit * second;
		QLabel * yearLabel;
		QLabel * monthLabel;
		QLabel * dayLabel;
		QLabel * hourLabel;
		QLabel * minuteLabel;
		QLabel * secondLabel;
		QLabel *dateTimeDelimiter;
		QComboBox * selectDateTimeDelimiter;
	protected:
		void dragEnterEvent(QDragEnterEvent *event);
		void dropEvent(QDropEvent *event);
		void mousePressEvent(QMouseEvent *event);
	signals:
		void delimitered_dateTime(int _column,int _row,QString _time);
	private slots:
		void show_help();
		void set_up_finished();
		void on_new_expression_added();

};

#endif // LOADERDATETIMEPAGE_H
