#!/bin/bash

echo "Starting Dynamic IP ..."

localuuid=$(LC_ALL=C nmcli -f UUID,DEVICE connection show | grep eth0 | awk '{print $1}')

nmcli con mod $localuuid ipv4.method auto

nmcli con down $localuuid
sleep 2
nmcli con up $localuuid

echo "Dynamic IP Done."
