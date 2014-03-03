#ifndef UUIDDIALOG_H
#define UUIDDIALOG_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<QCheckBox>
#include<iostream>
using namespace std;

class UuidDialog : public QDialog
{
		Q_OBJECT
	public:
		UuidDialog(QWidget *parent = 0);
	private:
		QLabel      * label;
		QLineEdit   * labelEdit;
		QPushButton * cancelButton;
		QPushButton * okButton;
	signals:
		void          new_uuid(QString _text);
	private slots:
		void          OkClicked();
		void          enabledOkButton(const QString &text);
};

#endif // UUIDDIALOG_H
