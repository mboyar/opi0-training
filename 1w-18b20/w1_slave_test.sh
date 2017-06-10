#!/bin/bash

#author: mboyar@enbia
#date: 12/2016
#title: 1-wire DS18B20 test

dmesg | grep W1; echo

while((1));
do
	more /sys/bus/w1/devices/28-03146ab7e8ff/w1_slave >> ~/Projects/opi-cold-storage/opi-cold-storage/w1_slave_$(date +%d%m%Y).log;
done
