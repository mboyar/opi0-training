#include "opiuart.h"

opiUart::opiUart(QObject *parent) : QObject(parent), counter(0)
{
    sport = new QSerialPort(this);
    tmr = new QTimer(this);
    connect(tmr, SIGNAL(timeout()), this, SLOT(sender()));
}

opiUart::~opiUart(){
    sport->close();
}

void opiUart::start(){

    listAllUarts();

    sport->setBaudRate(QSerialPort::Baud115200);
    sport->setPortName("/dev/ttyS1");

    if (!sport->open(QIODevice::ReadWrite)) {
        qDebug() << QObject::tr("Failed to open port %1, error: %2").arg(sport->portName()).arg(sport->errorString()) << endl;
        return;
    }

    tmr->start(500);
}

void opiUart::listAllUarts(){

    QList<QSerialPortInfo> listSport = QSerialPortInfo::availablePorts();

    for(int i = 0; i < listSport.count(); ++i){
        qDebug() << "/////////////////////////////";
        qDebug() << "description" << listSport.at(i).description();
        qDebug() << "hasProductIdentifier" << listSport.at(i).hasProductIdentifier();
        qDebug() << "hasVendorIdentifier" << listSport.at(i).hasVendorIdentifier();
        qDebug() << "isBusy" << listSport.at(i).isBusy();
        qDebug() << "isNull" << listSport.at(i).isNull();
        qDebug() << "isValid" << listSport.at(i).isValid();
        qDebug() << "manufacturer" << listSport.at(i).manufacturer();
        qDebug() << "portName" << listSport.at(i).portName();
        qDebug() << "productIdentifier" << listSport.at(i).productIdentifier();
        qDebug() << "serialNumber" << listSport.at(i).serialNumber();
        qDebug() << "systemLocation" << listSport.at(i).systemLocation();
        qDebug() << "vendorIdentifier" << listSport.at(i).vendorIdentifier();
    }
}

void opiUart::sender(){

    sport->write(QString("test_" + QString::number(counter++) + "\r\n").toStdString().c_str());
    qDebug() << "Yazilmasi beklenen - once: " << sport->bytesToWrite() << " byte";
    qDebug() << "Yazmayi bekle: " << sport->waitForBytesWritten(100);
    qDebug() << "Yazilmasi beklenen - sonra: " << sport->bytesToWrite() << " byte";
}
