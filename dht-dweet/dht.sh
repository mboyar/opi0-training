#!/bin/bash

#title: dht22 push to api
#author: mboyar@enbia
#date: 07/03/17 14:31:26
#contact: muratboyar(at)gmail.com

BASE_DIR="/home/enbia/opi0-training/dht-dweet"
DEV_CODE_FILE="/home/opi/DeviceCode.txt"
JSON_FILE="/tmp/dht.json"

if [[ -e $DEV_CODE_FILE ]]; then

	DEV_CODE=$(cat $DEV_CODE_FILE)
else
	DEV_CODE="null"
fi

while((1)); do
	sensorOut=$(sudo $BASE_DIR/dht)
	humid=$(echo $sensorOut | awk -F "|" '{print $1}' | awk -F ":" '{print $2}')
	temp=$(echo $sensorOut | awk -F "|" '{print $2}' | awk -F ":" '{print $2}')

	dateTime=$(date "+%d.%m.%Y %H:%M:%S")

	echo temp:$temp hum:$humid

	echo "\
	{ \
		\"DevID\": \"$DEV_CODE\", \
		\"Temperature\": \"$temp\", \
		\"Humidity\": \"$humid\", \
		\"Date\": \"$dateTime\" \
	} \
	     " >$JSON_FILE

	curl -H "Content-Type: application/json" \
		-X POST \
		-d @$JSON_FILE \
		 https://dweet.io:443/dweet/for/enbia-opi0-dht \
		>/dev/null
	sleep 1;
done

#		https://dweet.io:443/dweet/for/sersa_csem2 \

