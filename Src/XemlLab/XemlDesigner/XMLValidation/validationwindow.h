#ifndef VALIDATIONWINDOW_H
#define VALIDATIONWINDOW_H

#include <QMainWindow>
#include<iostream>
using namespace std;

#if defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
	#include "ui_schema_mobiles.h"
#else
	#include "ui_schema.h"
#endif

//! [0]
class ValidationWindow : public QMainWindow,
				   private Ui::SchemaMainWindow
{
	Q_OBJECT

public:
	ValidationWindow(bool _load,QString _filename);
	//ValidationWindow(QString _xemlCode);

private Q_SLOTS:
	void schemaSelected(int index);
	void instanceSelected(int index);
	void instanceSelected(QString _XemlCode);
	void validate();
	void textChanged();
	void save();

private:
	QString filename;
	QString xemlCode;
	bool load;
	void moveCursor(int line, int column);

signals:
	void validated(bool _IsValid);
};
//! [0]

#endif // VALIDATIONWINDOW_H
