/********************************************************************************
** Form generated from reading UI file 'gotocelldialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOCELLDIALOG_H
#define UI_GOTOCELLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoToCellDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GoToCellDialog)
    {
        if (GoToCellDialog->objectName().isEmpty())
            GoToCellDialog->setObjectName("GoToCellDialog");
        GoToCellDialog->resize(182, 62);
        widget = new QWidget(GoToCellDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(6, 6, 166, 48));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        label->setBuddy(lineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(GoToCellDialog);

        QMetaObject::connectSlotsByName(GoToCellDialog);
    } // setupUi

    void retranslateUi(QDialog *GoToCellDialog)
    {
        GoToCellDialog->setWindowTitle(QCoreApplication::translate("GoToCellDialog", "GoToCellDialog", nullptr));
        label->setText(QCoreApplication::translate("GoToCellDialog", "&Cell Location:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoToCellDialog: public Ui_GoToCellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOCELLDIALOG_H
