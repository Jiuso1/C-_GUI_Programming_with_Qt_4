#ifndef FINDDIALOG_H
#define FINDDIALOG_H

//#include <QMainWindow>
#include <QDialog>

class QLabel;
class QCheckBox;
class QLineEdit;
class QPushButton;

class finddialog : public QDialog
{
    Q_OBJECT

public:
    finddialog(QWidget *parent = nullptr);

signals:
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void findPrevious(const QString &str,Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};
#endif // FINDDIALOG_H
