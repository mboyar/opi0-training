#ifndef OPIUART_H
#define OPIUART_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class opiUart : public QObject
{
    Q_OBJECT
public:
    explicit opiUart(QObject *parent = 0);

signals:

public slots:
};

#endif // OPIUART_H
