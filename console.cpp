#include "console.h"

Console::Console()
{

}

QString Console::getPhp_exec() const
{
    return php_exec;
}

QProcess *Console::getConsole() const
{
    return console;
}
