#include "xemlcodeeditor.h"
#include "xmlsyntaxhighlighter.h"
XemlCodeEditor::XemlCodeEditor(QString _xemlcode,QWidget *parent):
	QWidget(parent)
{
	this->xemlCode=_xemlcode;
	instanceEdit = new QTextEdit(this);
	instanceEdit->setObjectName(QStringLiteral("instanceEdit"));
	new XmlSyntaxHighlighter(instanceEdit->document());
	//QFile instanceFile(this->filename);
	//instanceFile.open(QIODevice::ReadOnly);
	const QString instanceText(this->xemlCode);
	this->setFixedSize(1200,600);
	instanceEdit->setPlainText(instanceText);
	QVBoxLayout * mainlayout =new QVBoxLayout;
	mainlayout->addWidget(this->instanceEdit);
	setLayout(mainlayout);

}
