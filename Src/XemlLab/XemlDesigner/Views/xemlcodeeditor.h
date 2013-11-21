#ifndef XEMLCODEEDITOR_H
#define XEMLCODEEDITOR_H
#include<QtWidgets>

class XemlCodeEditor : public QWidget
{
		Q_OBJECT
	public:
		XemlCodeEditor(QString _xemlCode,QWidget *parent =0);
	private:
		QString xemlCode;
		QTextEdit  * instanceEdit;
};

#endif // XEMLCODEEDITOR_H
