#include <QtGui>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDebug>
#include <QDialogButtonBox>
#include <QPushButton>
#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegularExpressionValidator(regExp,this));

    //Solución eficaz aunque no óptima:
    /*connect(buttonBox->button(QDialogButtonBox::Ok),SIGNAL(clicked()),this,SLOT(accept()));
    connect(buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),this,SLOT(reject()));*/

    connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged(){
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}

