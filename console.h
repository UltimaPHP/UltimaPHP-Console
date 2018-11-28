#ifndef CONSOLE_H
#define CONSOLE_H

#include "QProcess"

class Console: public QProcess
{
    Q_OBJECT
public:
    Console();


private:
    QString php_exec = "php";
    QProcess *console;
};

#endif // CONSOLE_H
