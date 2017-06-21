#include <QCoreApplication>
#include <opiuart.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    opiUart myInstance;
    myInstance.start();

    return a.exec();
}

