#ifndef UUIDDIALOG_H
#define UUIDDIALOG_H
#include<QtWidgets>
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<QCheckBox>
#include<QDialogButtonBox>
#include<QMessageBox>
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
		QDialogButtonBox * buttonBox;
	signals:
		void          new_uuid(QString _text);
	private slots:
		void          OkClicked();
		void          show_help();
		void          enabledOkButton(const QString &text);
		void          ResetClicked();
};

#endif // UUIDDIALOG_H
