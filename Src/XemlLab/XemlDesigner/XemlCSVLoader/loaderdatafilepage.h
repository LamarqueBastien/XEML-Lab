#ifndef LOADERDATAFILEPAGE_H
#define LOADERDATAFILEPAGE_H
#include<QtWidgets>
#include<QWizardPage>
#include<QLabel>
#include<vector>
#include"loaderwizard.h"
#include<QMetaType>
Q_DECLARE_METATYPE(QItemSelectionModel*)
class LoaderDataFilePage : public QWizardPage
{
		Q_OBJECT
		Q_PROPERTY(QItemSelectionModel* selectionModel READ selectionModel)

	public:
		LoaderDataFilePage(QWidget *parent = 0);
		int nextId() const;
		//bool validatePage();
		bool checkForDelimiters(int _count_line,QString &word, QString _dataDelimiter,QString _textDelimiter,QChar character = 0);
		void process_line(const QString &);
		QItemSelectionModel * selectionModel(void)
		{
			return headerview->selectionModel();
		}


	private:
		QStandardItemModel * model;
		QTableView  * headerview;
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


#endif // LOADERDATAFILEPAGE_H


