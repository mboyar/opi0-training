#ifndef OPIUART_H
#define OPIUART_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>

class opiUart : public QObject
{
    Q_OBJECT
public:
    explicit opiUart(QObject *parent = 0);
    ~opiUart();
    void start();

private:
    void listAllUarts();
    QTimer *tmr;
    QSerialPort *sport;
    int counter;

signals:

public slots:

private slots:
    void sender();

};

#endif // OPIUART_H
