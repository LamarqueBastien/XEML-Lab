#ifndef STORYDIALOG_H
#define STORYDIALOG_H

#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<QCheckBox>
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
		QCheckBox   * is_split;
	public:
		StoryDialog(QWidget *parent = 0);
	signals:
		void          new_story(QString _text);
		void          new_story_split(QString _text);

	private slots:

		void          OkClicked();
		void          enabledOkButton(const QString &text);


};

#endif // STORYDIALOG_H
