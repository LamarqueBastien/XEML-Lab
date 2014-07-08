#ifndef PLATODATAPAGE_H
#define PLATODATAPAGE_H
#include<QtWidgets>
#include<QMetaType>
#include"platowizard.h"
#include"Views/xemlcodeeditor.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"

using namespace Xeml::Document;


//Q_DECLARE_METATYPE(QItemSelectionModel*)

class PlatoDataPage : public QWizardPage
{
		Q_OBJECT
		Q_PROPERTY(QItemSelectionModel* selectionModel READ selectionModel)

	public:
		PlatoDataPage(ItfDocument * _xeml_doc,QWidget *parent = 0);
		int nextId() const;
		bool checkForDelimiters(int _count_line,QString &word, QString _dataDelimiter,QString _textDelimiter,QChar character = 0);
		void process_line(const QString &);
		QItemSelectionModel * selectionModel(void)
		{
			return headerview->selectionModel();
		}
	private:

		ItfDocument * xeml_doc;
		QStandardItemModel * model;
		QTableView  * headerview;
		QPushButton * browseButton;
		QPushButton * loadButton;
		QPushButton * ShowXemlButton;
		QString fileName;
		QLabel *Filename;
		QLineEdit *FilenameLineEdit;
		QLabel *dataDelimiter;
		QComboBox * selectDataDelimiter;
		QLabel *textDelimiter;
		QComboBox * selectTextDelimiter;
		std::vector<std::vector<QString> *> * tmpvec;
	private slots:
		void load_file();
		void open_file();
		void show_xeml_code();
};

#endif // PLATODATAPAGE_H
