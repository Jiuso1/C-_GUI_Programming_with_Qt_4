/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *primaryGroupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *primaryColumnCombo;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *primaryOrderCombo;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *secondaryGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QComboBox *secondaryColumnCombo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QComboBox *secondaryOrderCombo;
    QGroupBox *tertiaryGroupBox;
    QGridLayout *gridLayout_2;
    QComboBox *tertiaryColumnCombo;
    QComboBox *tertiaryOrderCombo;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName("SortDialog");
        SortDialog->resize(340, 320);
        gridLayout_4 = new QGridLayout(SortDialog);
        gridLayout_4->setObjectName("gridLayout_4");
        primaryGroupBox = new QGroupBox(SortDialog);
        primaryGroupBox->setObjectName("primaryGroupBox");
        gridLayout = new QGridLayout(primaryGroupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(primaryGroupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        primaryColumnCombo = new QComboBox(primaryGroupBox);
        primaryColumnCombo->addItem(QString());
        primaryColumnCombo->setObjectName("primaryColumnCombo");

        gridLayout->addWidget(primaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(primaryGroupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        primaryOrderCombo = new QComboBox(primaryGroupBox);
        primaryOrderCombo->addItem(QString());
        primaryOrderCombo->addItem(QString());
        primaryOrderCombo->setObjectName("primaryOrderCombo");

        gridLayout->addWidget(primaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(primaryGroupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        okButton = new QPushButton(SortDialog);
        okButton->setObjectName("okButton");

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(SortDialog);
        cancelButton->setObjectName("cancelButton");

        verticalLayout->addWidget(cancelButton);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moreButton = new QPushButton(SortDialog);
        moreButton->setObjectName("moreButton");
        moreButton->setCheckable(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        secondaryGroupBox = new QGroupBox(SortDialog);
        secondaryGroupBox->setObjectName("secondaryGroupBox");
        gridLayout_3 = new QGridLayout(secondaryGroupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        label_5 = new QLabel(secondaryGroupBox);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        secondaryColumnCombo = new QComboBox(secondaryGroupBox);
        secondaryColumnCombo->addItem(QString());
        secondaryColumnCombo->setObjectName("secondaryColumnCombo");

        gridLayout_3->addWidget(secondaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_6 = new QLabel(secondaryGroupBox);
        label_6->setObjectName("label_6");

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        secondaryOrderCombo = new QComboBox(secondaryGroupBox);
        secondaryOrderCombo->addItem(QString());
        secondaryOrderCombo->addItem(QString());
        secondaryOrderCombo->setObjectName("secondaryOrderCombo");

        gridLayout_3->addWidget(secondaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(secondaryGroupBox, 2, 0, 1, 1);

        tertiaryGroupBox = new QGroupBox(SortDialog);
        tertiaryGroupBox->setObjectName("tertiaryGroupBox");
        gridLayout_2 = new QGridLayout(tertiaryGroupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        tertiaryColumnCombo = new QComboBox(tertiaryGroupBox);
        tertiaryColumnCombo->addItem(QString());
        tertiaryColumnCombo->setObjectName("tertiaryColumnCombo");

        gridLayout_2->addWidget(tertiaryColumnCombo, 0, 1, 1, 1);

        tertiaryOrderCombo = new QComboBox(tertiaryGroupBox);
        tertiaryOrderCombo->addItem(QString());
        tertiaryOrderCombo->addItem(QString());
        tertiaryOrderCombo->setObjectName("tertiaryOrderCombo");

        gridLayout_2->addWidget(tertiaryOrderCombo, 1, 1, 1, 2);

        label_4 = new QLabel(tertiaryGroupBox);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_3 = new QLabel(tertiaryGroupBox);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(tertiaryGroupBox, 3, 0, 1, 1);


        retranslateUi(SortDialog);
        QObject::connect(okButton, &QPushButton::clicked, SortDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelButton, &QPushButton::clicked, SortDialog, qOverload<>(&QDialog::reject));
        QObject::connect(moreButton, &QPushButton::toggled, secondaryGroupBox, &QGroupBox::setVisible);
        QObject::connect(moreButton, &QPushButton::toggled, tertiaryGroupBox, &QGroupBox::setVisible);

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QCoreApplication::translate("SortDialog", "Sort", nullptr));
        primaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Primary Key", nullptr));
        label->setText(QCoreApplication::translate("SortDialog", "Column:", nullptr));
        primaryColumnCombo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        label_2->setText(QCoreApplication::translate("SortDialog", "Order:", nullptr));
        primaryOrderCombo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        primaryOrderCombo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

        okButton->setText(QCoreApplication::translate("SortDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("SortDialog", "Cancel", nullptr));
        moreButton->setText(QCoreApplication::translate("SortDialog", "&More", nullptr));
        secondaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Secondary Key", nullptr));
        label_5->setText(QCoreApplication::translate("SortDialog", "Column:", nullptr));
        secondaryColumnCombo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        label_6->setText(QCoreApplication::translate("SortDialog", "Order:", nullptr));
        secondaryOrderCombo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        secondaryOrderCombo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

        tertiaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Tertiary Key", nullptr));
        tertiaryColumnCombo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        tertiaryOrderCombo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        tertiaryOrderCombo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

        label_4->setText(QCoreApplication::translate("SortDialog", "Order:", nullptr));
        label_3->setText(QCoreApplication::translate("SortDialog", "Column:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
