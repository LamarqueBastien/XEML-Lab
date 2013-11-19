#include "xemlcodeeditor.h"
#include "xmlsyntaxhighlighter.h"
XemlCodeEditor::XemlCodeEditor(QString _xemlcode,QWidget *parent):
	QWidget(parent)
{
	this->xemlCode=_xemlcode;
	const QString instanceText(this->xemlCode);
	instanceEdit = new QTextEdit(this);
	instanceEdit->setObjectName(QStringLiteral("instanceEdit"));
	new XmlSyntaxHighlighter(instanceEdit->document());

	this->setFixedSize(1200,600);
	instanceEdit->setPlainText(instanceText);

	QVBoxLayout * mainlayout =new QVBoxLayout;
	mainlayout->addWidget(this->instanceEdit);
	setLayout(mainlayout);

}
