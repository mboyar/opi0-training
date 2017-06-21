#include "opiuart.h"

opiUart::opiUart(QObject *parent) : QObject(parent)
{

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

