#!/bin/bash

if [ $(nmcli | grep servers | awk '{print $2}') == 8.8.8.8 ]; then echo 'static'; else echo 'DHCP'; fi;
