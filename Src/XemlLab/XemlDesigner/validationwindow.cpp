/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <QtXmlPatterns>

#include "validationwindow.h"
#include "xmlsyntaxhighlighter.h"

//! [4]
class MessageHandler : public QAbstractMessageHandler
{
public:
	MessageHandler()
		: QAbstractMessageHandler(0)
	{
	}

	QString statusMessage() const
	{
		return m_description;
	}

	int line() const
	{
		return m_sourceLocation.line();
	}

	int column() const
	{
		return m_sourceLocation.column();
	}

protected:
	virtual void handleMessage(QtMsgType type, const QString &description,
							   const QUrl &identifier, const QSourceLocation &sourceLocation)
	{
		Q_UNUSED(type);
		Q_UNUSED(identifier);

		m_messageType = type;
		m_description = description;
		m_sourceLocation = sourceLocation;
	}

private:
	QtMsgType m_messageType;
	QString m_description;
	QSourceLocation m_sourceLocation;
};
//! [4]

//! [0]
ValidationWindow::ValidationWindow(bool _load,QString _filename)
{
	setupUi(this);
	this->setFixedSize(1200,600);
	this->filename=_filename;
	this->load=_load;
	new XmlSyntaxHighlighter(schemaView->document());
	new XmlSyntaxHighlighter(instanceEdit->document());

	//schemaSelection->addItem(tr("Contact Schema"));
	//schemaSelection->addItem(tr("Recipe Schema"));
	//schemaSelection->addItem(tr("Order Schema"));

	//instanceSelection->addItem(tr("Valid Contact Instance"));
	//instanceSelection->addItem(tr("Invalid Contact Instance"));

	//connect(schemaSelection, SIGNAL(currentIndexChanged(int)), SLOT(schemaSelected(int)));
	//connect(instanceSelection, SIGNAL(currentIndexChanged(int)), SLOT(instanceSelected(int)));
	this->validateButton->setText("Save");
	connect(validateButton, SIGNAL(clicked()), SLOT(save()));
	connect(instanceEdit, SIGNAL(textChanged()), SLOT(textChanged()));

	validationStatus->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

	schemaSelected(0);
	if (this->load){
		instanceSelected(0);
	}
	else{
		instanceSelected(this->filename);
	}


}

//! [0]

//! [1]
void ValidationWindow::save(){
	emit validated(true);
}

void ValidationWindow::schemaSelected(int index)
{
	/*instanceSelection->clear();
	if (index == 0) {
		instanceSelection->addItem(tr("Valid Contact Instance"));
		instanceSelection->addItem(tr("Invalid Contact Instance"));
	} else if (index == 1) {
		instanceSelection->addItem(tr("Valid Recipe Instance"));
		instanceSelection->addItem(tr("Invalid Recipe Instance"));
	} else if (index == 2) {
		instanceSelection->addItem(tr("Valid Order Instance"));
		instanceSelection->addItem(tr("Invalid Order Instance"));
	}
	textChanged();
	*/

	QFile schemaFile(":/XEMLSchema_V1.1.xsd");
	schemaFile.open(QIODevice::ReadOnly);
	const QString schemaText(QString::fromUtf8(schemaFile.readAll()));
	schemaView->setPlainText(schemaText);

	validate();
}
//! [1]

//! [2]
void ValidationWindow::instanceSelected(int index)
{
	QFile instanceFile(this->filename);
	instanceFile.open(QIODevice::ReadOnly);
	const QString instanceText(QString::fromUtf8(instanceFile.readAll()));
	instanceEdit->setPlainText(instanceText);

	validate();
}
void ValidationWindow::instanceSelected(QString _XemlCode)
{
	//QFile instanceFile(this->filename);
	//instanceFile.open(QIODevice::ReadOnly);
	//const QString instanceText(QString::fromUtf8(instanceFile.readAll()));
	instanceEdit->setPlainText(_XemlCode);

	validate();
}
//! [2]

//! [3]
void ValidationWindow::validate()
{
	const QByteArray schemaData = schemaView->toPlainText().toUtf8();
	const QByteArray instanceData = instanceEdit->toPlainText().toUtf8();

	MessageHandler messageHandler;

	QXmlSchema schema;
	schema.setMessageHandler(&messageHandler);

	schema.load(schemaData);

	bool errorOccurred = false;
	if (!schema.isValid()) {
		errorOccurred = true;
	} else {
		QXmlSchemaValidator validator(schema);
		if (!validator.validate(instanceData))
			errorOccurred = true;
	}

	if (errorOccurred) {
		validationStatus->setText(messageHandler.statusMessage());
		moveCursor(messageHandler.line(), messageHandler.column());
	} else {
		validationStatus->setText(tr("validation successful"));
		//emit validated(true);
	}

	const QString styleSheet = QString("QLabel {background: %1; padding: 3px}")
									  .arg(errorOccurred ? QColor(Qt::red).lighter(160).name() :
														   QColor(Qt::green).lighter(160).name());
	validationStatus->setStyleSheet(styleSheet);
	this->close();
}
//! [3]

void ValidationWindow::textChanged()
{
	instanceEdit->setExtraSelections(QList<QTextEdit::ExtraSelection>());
}

void ValidationWindow::moveCursor(int line, int column)
{
	instanceEdit->moveCursor(QTextCursor::Start);
	for (int i = 1; i < line; ++i)
		instanceEdit->moveCursor(QTextCursor::Down);

	for (int i = 1; i < column; ++i)
		instanceEdit->moveCursor(QTextCursor::Right);

	QList<QTextEdit::ExtraSelection> extraSelections;
	QTextEdit::ExtraSelection selection;

	const QColor lineColor = QColor(Qt::red).lighter(160);
	selection.format.setBackground(lineColor);
	selection.format.setProperty(QTextFormat::FullWidthSelection, true);
	selection.cursor = instanceEdit->textCursor();
	selection.cursor.clearSelection();
	extraSelections.append(selection);

	instanceEdit->setExtraSelections(extraSelections);

	instanceEdit->setFocus();
}
