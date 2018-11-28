#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTextCursor"
#include "QDebug"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);   

    this->StartUPHP();
    connect(uphpProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(StartProcess()));
}

void MainWindow::StartProcess()
{
    QString recProcess = uphpProcess->readAllStandardOutput();

    recProcess.remove(QRegExp("\\n"));
    //recProcess.remove(QRegExp("\\t"));
    //recProcess.remove(QRegExp("\\r"));

    ui->textEdit->append(recProcess);

}

void MainWindow::StartUPHP()
{
    if(uphpProcess->state() == 0 )
    {
        uphpProcess = new QProcess(this);
        uphpProcess->start(program, QStringList() << uphpArg);
    }
    else{
        QMessageBox::warning(this, tr("Ultima PHP "),
                                       tr("O UltimaPHP já está sendo executado.\n"),
                                       QMessageBox::Ok);
    }
}

MainWindow::~MainWindow()
{
    uphpProcess->kill();
    delete ui;
}

