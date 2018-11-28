#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QProcess>
#include <QTextCursor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QProcess *uphpProcess;    

private slots:
    void StartProcess();
    void StartUPHP();

private:
    Ui::MainWindow *ui;
    QString program = "php";
    QString uphpArg = "/home/mnunes/UltimaPHP/startserver.php";
};

#endif // MAINWINDOW_H
