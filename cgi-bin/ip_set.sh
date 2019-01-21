#!/bin/bash

if [ $1 == "dhcp" ]
then
    echo "Starting Dynamic IP (DHCP) ..."
    nmcli connection delete uuid $(LC_ALL=C nmcli -f UUID,DEVICE connection show | grep eth0 | awk '{print $1}') >/dev/null 2>&1
    nmcli con add con-name "Armbian ethernet" type ethernet ifname eth0 >/dev/null 2>&1
    nmcli con up "Armbian ethernet" >/dev/null 2>&1
    echo "Dynamic IP (DHCP) Done."
else
    echo "Starting Static IP ..."

    localuuid=$(LC_ALL=C nmcli -f UUID,DEVICE connection show | grep eth0 | awk '{print $1}')

    nmcli con mod $localuuid ipv4.method manual ipv4.addresses "$2/$3" >/dev/null 2>&1
    nmcli con mod $localuuid ipv4.method manual ipv4.gateway "$4" >/dev/null 2>&1
    nmcli con mod $localuuid ipv4.dns "8.8.8.8,$4" >/dev/null 2>&1

    nmcli con down $localuuid
    sleep 2
    nmcli con up $localuuid

    echo "Static IP Done."
fi;

