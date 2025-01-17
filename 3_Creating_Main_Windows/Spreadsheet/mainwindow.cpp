#include "mainwindow.h"
#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
#include "spreadsheet.h"
#include <QtGui>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
{
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    findDialog = nullptr;

    setWindowIcon(QIcon("/images/icon.png"));
    setCurrentFile("");

    setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::createActions(){
    newAction = new QAction(tr("&New"),this);
    //newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a spreadsheet file"));
    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));

    openAction = new QAction(tr("&Open"),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a spreadsheet file"));
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));

    saveAction = new QAction(tr("Sa&ve"),this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the current spreadsheet file"));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

    saveAsAction = new QAction(tr("Sav&e as"),this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save the current spreadsheet file in a specified file"));
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAs()));

    for(int i = 0;i < MaxRecentFiles;i++){
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i],SIGNAL(triggered()),
                this,SLOT(openRecentFile()));
    }

    selectAllAction = new QAction(tr("&All"),this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
    connect(selectAllAction,SIGNAL(triggered()),spreadsheet,SLOT(selectAll()));

    showGridAction = new QAction(tr("&Show grid"));
    showGridAction->setCheckable(true);
    showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
    connect(showGridAction,SIGNAL(toggled(bool)),spreadsheet,SLOT(setShowGrid(bool)));

    aboutQtAction = new QAction(tr("About &Qt"));
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));

    aboutAction = new QAction(tr("&About"));
    aboutQtAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));

    closeAction = new QAction(tr("&Close"),this);
    closeAction->setShortcut(QKeySequence::Close);
    closeAction->setStatusTip(tr("Close this window"));
    connect(closeAction,SIGNAL(triggered()),this,SLOT(close()));

    exitAction = new QAction(tr("E&xit"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction,SIGNAL(triggered()),qApp,SLOT(closeAllWindows()));

    cutAction = new QAction(tr("Cut"),this);
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut the selected cells"));
    connect(cutAction,SIGNAL(triggered()),spreadsheet,SLOT(cut()));

    copyAction = new QAction(tr("Copy"),this);
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the selected cells"));
    connect(copyAction,SIGNAL(triggered()),spreadsheet,SLOT(copy()));

    pasteAction = new QAction(tr("Paste"),this);
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard contents"));
    connect(pasteAction,SIGNAL(triggered()),spreadsheet,SLOT(paste()));

    deleteAction = new QAction(tr("Delete"),this);
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("Delete the selected cells"));
    connect(deleteAction,SIGNAL(triggered()),spreadsheet,SLOT(del()));

    selectRowAction = new QAction(tr("Select row"),this);
    connect(selectRowAction,SIGNAL(triggered()),spreadsheet,SLOT(selectCurrentRow()));

    selectColumnAction = new QAction(tr("Select column"),this);
    connect(selectColumnAction,SIGNAL(triggered()),spreadsheet,SLOT(selectCurrentColumn()));

    findAction = new QAction(tr("Find"),this);
    findAction->setShortcut(QKeySequence::Find);
    findAction->setStatusTip(tr("Open the find dialog"));
    connect(findAction,SIGNAL(triggered()),this,SLOT(find()));

    goToCellAction = new QAction(tr("Go to cell"),this);
    goToCellAction->setShortcut(tr("Ctrl+G"));
    goToCellAction->setStatusTip(tr("Open the go to cell dialog"));
    connect(goToCellAction,SIGNAL(triggered()),this,SLOT(goToCell()));

    calculateAction = new QAction(tr("Calculate"),this);
    calculateAction->setStatusTip(tr("Recalculate the necessary cells"));
    connect(calculateAction,SIGNAL(triggered()),spreadsheet,SLOT(recalculate()));

    sortAction = new QAction(tr("Sort"),this);
    sortAction->setStatusTip(tr("Sort the cells"));
    connect(sortAction,SIGNAL(triggered()),this,SLOT(sort()));

    autoRecalcAction = new QAction(tr("AutoRecalc"));
    autoRecalcAction->setCheckable(true);
    autoRecalcAction->setChecked(spreadsheet->autoRecalculate());//Por implementar.
    autoRecalcAction->setStatusTip(tr("Autorecalc or not the spreadsheet's cells"));
    connect(autoRecalcAction,SIGNAL(toggled(bool)),spreadsheet,SLOT(setAutoRecalculate(bool)));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);

    separatorAction = fileMenu->addSeparator();
    for(int i = 0;i < MaxRecentFiles;i++){
        fileMenu->addAction(recentFileActions[i]);
    }
    fileMenu->addSeparator();

    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);

    selectSubMenu = editMenu->addMenu(tr("&Select"));
    selectSubMenu->addAction(selectRowAction);
    selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectAllAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(goToCellAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(calculateAction);
    toolsMenu->addAction(sortAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    optionsMenu->addAction(autoRecalcAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu(){
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars(){
    fileToolBar = addToolBar("&File");
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(goToCellAction);
}

void MainWindow::createStatusBar(){
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel,1);

    connect(spreadsheet,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(updateStatusBar()));
    connect(spreadsheet,SIGNAL(modified()),this,SLOT(spreadsheetModified()));

    updateStatusBar();
}

void MainWindow::updateStatusBar(){
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::spreadsheetModified(){
    setWindowModified(true);
    updateStatusBar();
}

bool MainWindow::okToContinue(){
    if(isWindowModified()){
        int r = QMessageBox::warning(this,tr("Spreadsheet"),
                                     tr("The document has been modified.\n Do you want to save your changes?"),
                                     QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
        if(r == QMessageBox::Yes){
            return save();
        }else if(r == QMessageBox::Cancel){
            return false;
        }
    }
    return true;
}

void MainWindow::open(){
    if(okToContinue()){
        QString fileName = QFileDialog::getOpenFileName(this,tr("Open Spreadsheet"),".",tr("Spreadsheet files (*.sp)"));
        if(!fileName.isEmpty()){
            loadFile(fileName);
        }
    }
}

bool MainWindow::loadFile(const QString &fileName){
    if(!spreadsheet->readFile(fileName)){
        statusBar()->showMessage(tr("Loading canceled"),2000);
        return false;
    }else{
        setCurrentFile(fileName);
        statusBar()->showMessage(tr("File loaded"),2000);
        return true;
    }
}

bool MainWindow::save(){
    if(curFile.isEmpty()){
        return saveAs();
    }else{
        return saveFile(curFile);
    }
}

bool MainWindow::saveFile(const QString &fileName){
    if(!spreadsheet->writeFile(fileName)){
        statusBar()->showMessage(tr("Saving canceled"),2000);
        return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"),2000);
    return true;
}

bool MainWindow::saveAs(){
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Spreadsheet"),".",tr("Spreadsheet files (*.sp)"));
    if(fileName.isEmpty()){
        return false;
    }
    return saveFile(fileName);
}

void MainWindow::closeEvent(QCloseEvent *event){
    if(okToContinue()){
        writeSettings();
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::setCurrentFile(const QString &fileName){
    curFile = fileName;
    setWindowModified(false);
    QString shownName = tr("Untitled");
    if(!curFile.isEmpty()){
        shownName = strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);
        foreach(QWidget *win,QApplication::topLevelWidgets()){
            if(MainWindow *mainWin = qobject_cast<MainWindow *>(win)){
                mainWin->updateRecentFileActions();
            }
        }
    }
    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Spreadsheet")));
}

QString MainWindow::strippedName(const QString &fullFileName){
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateRecentFileActions(){
    QMutableStringListIterator i(recentFiles);
    while(i.hasNext()){
        if(!QFile::exists(i.next())){
            i.remove();
        }
    }
    for(int j = 0;j < MaxRecentFiles;j++){
        if(j < recentFiles.count()){
            QString text = tr("&%1 %2").arg(j+1).arg(strippedName(recentFiles[j]));
            recentFileActions[j]->setText(text);
            recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);
        }else{
            recentFileActions[j]->setVisible(false);
        }
    }
    separatorAction->setVisible(!recentFiles.isEmpty());
}

void MainWindow::openRecentFile(){
    if(okToContinue()){
        QAction *action = qobject_cast<QAction *>(sender());
        if(action){
            loadFile(action->data().toString());
        }
    }
}

void MainWindow::find(){
    if(!findDialog){
        findDialog = new FindDialog(this);
        connect(findDialog,SIGNAL(findNext(const QString &,Qt::CaseSensitivity)),spreadsheet,SLOT(findNext(const QString &,Qt::CaseSensitivity)));
        connect(findDialog,SIGNAL(findPrevious(const QString &,Qt::CaseSensitivity)),spreadsheet,SLOT(findPrevious(const QString &,Qt::CaseSensitivity)));
    }
    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();
}

void MainWindow::goToCell(){
    GoToCellDialog *dialog = new GoToCellDialog(this);
    if(dialog->exec()){
        QString str = dialog->lineEdit->text().toUpper();
        spreadsheet->setCurrentCell(str.mid(1).toInt() - 1,str[0].unicode() - 'A');
    }
    delete dialog;
}

void MainWindow::sort(){
    SortDialog dialog(this);
    QTableWidgetSelectionRange range = spreadsheet->selectedRange();
    QChar firstLetter = 'A';
    int firstLetterLeftInt = firstLetter.unicode() + range.leftColumn();
    int firstLetterRightInt = firstLetter.unicode() + range.rightColumn();
    dialog.setColumnRange(QChar(firstLetterLeftInt), QChar(firstLetterRightInt));
    if(dialog.exec()){
        SpreadsheetCompare compare;

        compare.keys[0] = dialog.primaryColumnCombo->currentIndex();
        compare.keys[1] = dialog.secondaryColumnCombo->currentIndex();
        compare.keys[2] = dialog.tertiaryColumnCombo->currentIndex();

        compare.ascending[0] = (dialog.primaryOrderCombo->currentIndex() == 0);
        compare.ascending[1] = (dialog.secondaryOrderCombo->currentIndex() == 0);
        compare.ascending[2] = (dialog.tertiaryOrderCombo->currentIndex() == 0);

        spreadsheet->sort(compare);
    }
}

void MainWindow::about(){
    QMessageBox::about(this,tr("About Spreadsheet"),tr("<h2>Spreadsheet 1.1</h2>"
                                                         "<p>Copyright &copy; 2008 Software Inc."
                                                         "<p>Spreadsheet is a small application that "
                                                         "demonstrates QAction, QMainWindow, QMenuBar, "
                                                         "QStatusBar, QTableWidget, QToolBar, and many other "
                                                         "Qt classes."));
}

void MainWindow::writeSettings(){
    QSettings settings("Software Inc.","Spreadsheet");

    settings.setValue("geometry",saveGeometry());
    settings.setValue("recentFiles",recentFiles);
    settings.setValue("showGrid",showGridAction->isChecked());
    settings.setValue("autoRecalc",autoRecalcAction->isChecked());
}

void MainWindow::readSettings(){
    QSettings settings("Software Inc.","Spreadsheet");

    restoreGeometry(settings.value("geometry").toByteArray());

    recentFiles = settings.value("recentFiles").toStringList();

    foreach(QWidget *win,QApplication::topLevelWidgets()){
        if(MainWindow *mainWin = qobject_cast<MainWindow *>(win)){
            mainWin->updateRecentFileActions();
        }
    }

    bool showGrid = settings.value("showGrid",true).toBool();
    showGridAction->setChecked(showGrid);

    bool autoRecalc = settings.value("autoRecalc",true).toBool();
    autoRecalcAction->setChecked(autoRecalc);
}

void MainWindow::newFile(){
    MainWindow *mainWin = new MainWindow;
    mainWin->show();
}
