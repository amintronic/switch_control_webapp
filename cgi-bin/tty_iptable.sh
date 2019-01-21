#!/bin/bash

if [ $1 == "block" ]
then
    if [ $2 == "s2" ]
    then
        iptables -A INPUT -p tcp --dport 4441 -j DROP
        iptables -A OUTPUT -p tcp --dport 4441 -j DROP
    else
        iptables -A INPUT -p tcp --dport 4442 -j DROP
        iptables -A OUTPUT -p tcp --dport 4442 -j DROP
    fi;
else
    if [ $2 == "s2" ]
    then
        iptables -D INPUT -p tcp --dport 4441 -j DROP
        iptables -D OUTPUT -p tcp --dport 4441 -j DROP
    else
        iptables -D INPUT -p tcp --dport 4442 -j DROP
        iptables -D OUTPUT -p tcp --dport 4442 -j DROP
    fi;
fi;
