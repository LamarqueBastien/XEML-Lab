#ifndef ANNOTATIONDIALOG_H
#define ANNOTATIONDIALOG_H
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QLineEdit>
#include<QTextEdit>
class AnnotationDialog : public QDialog
{
		Q_OBJECT
	public:
		AnnotationDialog(QWidget *parent = 0);
		AnnotationDialog(QString _tag,QWidget * parent=0);
	private:
		QLabel * tag_label;
		QLabel * annotation_label;
		QLineEdit * tag_edit;
		QTextEdit * annotation_edit;
		QPushButton  * okButton;
		QPushButton  * cancelButton;
	signals:
		void send_annotation_tag(QString tag,QString annotation);
	private slots:

		void receive_annotation_tag();
		void enabling_ok_button();
};

#endif // ANNOTATIONDIALOG_H
