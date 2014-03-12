#ifndef INDIVIDUALIMPORTFILEPAGE_H
#define INDIVIDUALIMPORTFILEPAGE_H
#include<QtWidgets>
#include<QMetaType>
#include<QLabel>
#include<vector>
#include"individualwizard.h"

//Q_DECLARE_METATYPE(QItemSelectionModel*)

class IndividualImportFilePage : public QWizardPage
{
		Q_OBJECT
		//Q_PROPERTY(QItemSelectionModel* selectionModel READ selectionModel)

	public:
		IndividualImportFilePage(QWidget *parent = 0);
		int nextId() const;
		//bool validatePage();
		bool checkForDelimiters(int _count_line,QString &word, QString _dataDelimiter,QString _textDelimiter,QChar character = 0);
		void process_line(const QString &);
		//QItemSelectionModel * selectionModel(void)
		//{
		//	return headerviews->selectionModel();
		//}


	private:
		QStandardItemModel * model;
		QTableView  * headerviews;
		QPushButton * browseButton;
		QPushButton * loadButton;
		QString fileName;
		QLabel *Filename;
		QLineEdit *FilenameLineEdit;
		QLabel *dataDelimiter;
		QComboBox * selectDataDelimiter;
		QLabel *textDelimiter;
		QComboBox * selectTextDelimiter;
		std::vector<std::vector<QString> *> * tmpvec;

	signals:
		//void data_loaded(std::vector<std::vector<QString> *> * _vectorData);
	private slots:
		void load_file();
		void open_file();

};

#endif // INDIVIDUALIMPORTFILEPAGE_H
