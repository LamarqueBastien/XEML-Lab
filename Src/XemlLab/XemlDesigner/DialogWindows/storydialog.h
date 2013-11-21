#ifndef STORYDIALOG_H
#define STORYDIALOG_H

#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<iostream>
using namespace std;

//class QCheckBox;
//class QLabel;
//class QLineEdit;
//class QPushButton;

class StoryDialog : public QDialog
{
	Q_OBJECT
	private:
		QLabel      * label;
		QLineEdit   * labelEdit;
		QPushButton * cancelButton;
		QPushButton * okButton;
	public:
		StoryDialog(QWidget *parent = 0);
	signals:
		void          mon_signal(QString _text);

	private slots:

		void          OkClicked();
		void          enabledOkButton(const QString &text);


};

#endif // STORYDIALOG_H
