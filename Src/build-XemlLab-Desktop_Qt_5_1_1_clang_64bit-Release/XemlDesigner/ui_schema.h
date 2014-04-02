/********************************************************************************
** Form generated from reading UI file 'schema.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEMA_H
#define UI_SCHEMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SchemaMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *schemaLabel;
    QTextBrowser *schemaView;
    QLabel *instanceLabel;
    QTextEdit *instanceEdit;
    QLabel *label;
    QLabel *validationStatus;
    QPushButton *validateButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SchemaMainWindow)
    {
        if (SchemaMainWindow->objectName().isEmpty())
            SchemaMainWindow->setObjectName(QStringLiteral("SchemaMainWindow"));
        SchemaMainWindow->resize(417, 594);
        centralwidget = new QWidget(SchemaMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        schemaLabel = new QLabel(centralwidget);
        schemaLabel->setObjectName(QStringLiteral("schemaLabel"));

        gridLayout->addWidget(schemaLabel, 0, 0, 1, 2);

        schemaView = new QTextBrowser(centralwidget);
        schemaView->setObjectName(QStringLiteral("schemaView"));

        gridLayout->addWidget(schemaView, 1, 0, 1, 4);

        instanceLabel = new QLabel(centralwidget);
        instanceLabel->setObjectName(QStringLiteral("instanceLabel"));

        gridLayout->addWidget(instanceLabel, 2, 0, 1, 2);

        instanceEdit = new QTextEdit(centralwidget);
        instanceEdit->setObjectName(QStringLiteral("instanceEdit"));

        gridLayout->addWidget(instanceEdit, 3, 0, 1, 4);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        validationStatus = new QLabel(centralwidget);
        validationStatus->setObjectName(QStringLiteral("validationStatus"));

        gridLayout->addWidget(validationStatus, 4, 1, 1, 2);

        validateButton = new QPushButton(centralwidget);
        validateButton->setObjectName(QStringLiteral("validateButton"));

        gridLayout->addWidget(validateButton, 4, 3, 1, 1);

        SchemaMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SchemaMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SchemaMainWindow->setStatusBar(statusbar);

        retranslateUi(SchemaMainWindow);

        QMetaObject::connectSlotsByName(SchemaMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SchemaMainWindow)
    {
        SchemaMainWindow->setWindowTitle(QApplication::translate("SchemaMainWindow", "XML Schema Validation", 0));
        schemaLabel->setText(QApplication::translate("SchemaMainWindow", "XML Schema Document:", 0));
        instanceLabel->setText(QApplication::translate("SchemaMainWindow", "XEML Instance Document:", 0));
        label->setText(QApplication::translate("SchemaMainWindow", "Status:", 0));
        validationStatus->setText(QApplication::translate("SchemaMainWindow", "not validated", 0));
        validateButton->setText(QApplication::translate("SchemaMainWindow", "Validate", 0));
    } // retranslateUi

};

namespace Ui {
    class SchemaMainWindow: public Ui_SchemaMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEMA_H
