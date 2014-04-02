/********************************************************************************
** Form generated from reading UI file 'schema_mobiles.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEMA_MOBILES_H
#define UI_SCHEMA_MOBILES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SchemaMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QComboBox *schemaSelection;
    QTextBrowser *schemaView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QComboBox *instanceSelection;
    QTextBrowser *instanceEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *validationStatus;
    QPushButton *validateButton;

    void setupUi(QMainWindow *SchemaMainWindow)
    {
        if (SchemaMainWindow->objectName().isEmpty())
            SchemaMainWindow->setObjectName(QStringLiteral("SchemaMainWindow"));
        SchemaMainWindow->resize(187, 179);
        centralwidget = new QWidget(SchemaMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        schemaSelection = new QComboBox(tab);
        schemaSelection->setObjectName(QStringLiteral("schemaSelection"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(schemaSelection->sizePolicy().hasHeightForWidth());
        schemaSelection->setSizePolicy(sizePolicy);
        schemaSelection->setMaxVisibleItems(3);

        verticalLayout_2->addWidget(schemaSelection);

        schemaView = new QTextBrowser(tab);
        schemaView->setObjectName(QStringLiteral("schemaView"));

        verticalLayout_2->addWidget(schemaView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        instanceSelection = new QComboBox(tab_2);
        instanceSelection->setObjectName(QStringLiteral("instanceSelection"));
        sizePolicy.setHeightForWidth(instanceSelection->sizePolicy().hasHeightForWidth());
        instanceSelection->setSizePolicy(sizePolicy);
        instanceSelection->setMaxVisibleItems(3);

        verticalLayout->addWidget(instanceSelection);

        instanceEdit = new QTextBrowser(tab_2);
        instanceEdit->setObjectName(QStringLiteral("instanceEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(instanceEdit->sizePolicy().hasHeightForWidth());
        instanceEdit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(8);
        instanceEdit->setFont(font);
        instanceEdit->setReadOnly(false);

        verticalLayout->addWidget(instanceEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        validationStatus = new QLabel(tab_2);
        validationStatus->setObjectName(QStringLiteral("validationStatus"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(validationStatus->sizePolicy().hasHeightForWidth());
        validationStatus->setSizePolicy(sizePolicy2);
        validationStatus->setWordWrap(true);

        horizontalLayout_2->addWidget(validationStatus);

        validateButton = new QPushButton(tab_2);
        validateButton->setObjectName(QStringLiteral("validateButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(validateButton->sizePolicy().hasHeightForWidth());
        validateButton->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(validateButton);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);

        SchemaMainWindow->setCentralWidget(centralwidget);

        retranslateUi(SchemaMainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SchemaMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SchemaMainWindow)
    {
        SchemaMainWindow->setWindowTitle(QApplication::translate("SchemaMainWindow", "XML Schema Validation", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SchemaMainWindow", "XML Schema", 0));
        validationStatus->setText(QApplication::translate("SchemaMainWindow", "Not validated", 0));
        validateButton->setText(QApplication::translate("SchemaMainWindow", "Validate", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SchemaMainWindow", "XML Instance", 0));
    } // retranslateUi

};

namespace Ui {
    class SchemaMainWindow: public Ui_SchemaMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEMA_MOBILES_H
