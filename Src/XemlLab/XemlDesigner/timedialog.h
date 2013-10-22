#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H
#include<QDialog>
#include<QRadioButton>
#include<QPushButton>
#include<QBoxLayout>

class TimeDialog : public QDialog
{
		Q_OBJECT
	public:

		TimeDialog(QWidget *parent=0);
	private:
		QRadioButton * evaluate_time;
		QRadioButton * register_term_and_story;
		QPushButton * okButton;
		QPushButton * cancelButton;
	private slots:
		void validate();
	signals:
		void is_time(bool _time);
};

#endif // TIMEDIALOG_H
