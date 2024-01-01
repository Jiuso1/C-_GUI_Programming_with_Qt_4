#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &filename);
    bool saveFile(const QString &filename);
    void setCurrentFile(const QString &filename);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);
    Spreadsheet *spreadsheet;
    FindDialog *findDialog;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    inline static QStringList recentFiles = QStringList();//Resuelto con https://stackoverflow.com/questions/16284629/undefined-reference-to-static-variable-c
    QString curFile;

    enum { MaxRecentFiles = 5};
    QAction *recentFileActions[MaxRecentFiles];
    QAction *separatorAction;

    QMenu *fileMenu;
    QMenu *editMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAction;
    QAction *openAction;
    QAction *aboutQtAction;
    QAction *saveAction;
    QAction *saveAsAction;

    QAction *exitAction;
    QAction *selectAllAction;
    QAction *showGridAction;

    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;

    QMenu *selectSubMenu;

    QAction *selectRowAction;
    QAction *selectColumnAction;

    QAction *findAction;
    QAction *goToCellAction;

    QMenu *toolsMenu;

    QAction *calculateAction;
    QAction *sortAction;

    QMenu *optionsMenu;

    QAction *autoRecalcAction;

    QMenu *helpMenu;

    QAction *aboutAction;

    QAction *closeAction;
};

#endif // MAINWINDOW_H
