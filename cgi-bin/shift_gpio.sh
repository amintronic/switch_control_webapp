#!/bin/bash

t=0.01

if [ $1 == "left" ]
then
    OE=11
    SRclk=27
    data=31
    Rclk=26
else
    OE=15
    SRclk=4
    data=5
    Rclk=6
fi;

gpio write $OE 0

n=$2

# for (( n=$1 ; n>0 ; n >>= 1 )); do  bit="$(( n&1 ))$bit"; done
# printf "%s\n" "$bit"

# counter=0
# for (( n=$2 ; n>0 ; n >>= 1 )); do 
#     counter=$((counter+1))
#     bit="$(( n&1 ))"
#     if [ $bit = "0" ]
#     then
#         echo "ZERO"
#         gpio write $data 0
#         sleep $t
#         gpio write $SRclk 1
#         sleep $t
#         gpio write $SRclk 0
#     else
#         echo "ONE"
#         gpio write $data 1
#         sleep $t
#         gpio write $SRclk 1
#         sleep $t
#         gpio write $SRclk 0
#     fi;
# done

# let "counter=8-counter"

# for (( i=0 ; i<$counter ; i += 1 )); do 
#     echo "ZERO"
#     gpio write $data 0
#     sleep $t
#     gpio write $SRclk 1
#     sleep $t
#     gpio write $SRclk 0
# done

gpio write $data "$(( (n>>6)&1 ))"
sleep $t
gpio write $SRclk 1
sleep $t
gpio write $SRclk 0

gpio write $data "$(( (n>>5)&1 ))"
sleep $t
gpio write $SRclk 1
sleep $t
gpio write $SRclk 0

gpio write $data "$(( (n>>4)&1 ))"
sleep $t
gpio write $SRclk 1
sleep $t
gpio write $SRclk 0

gpio write $data "$(( (n>>3)&1 ))"
sleep $t
gpio write $SRclk 1
sleep $t
gpio write $SRclk 0

gpio write $data "$(( (n>>2)&1 ))"
sleep $t
gpio write $SRclk 1
sleep $t
gpio write $SRclk 0

gpio write $data "$(( (n>>1)&1 ))"
sleep $t
gpio write $SRclk 1
sleep $t
gpio write $SRclk 0

gpio write $data "$(( (n>>7)&1 ))"
sleep $t
gpio write $SRclk 1
sleep $t
gpio write $SRclk 0

gpio write $data "$(( (n>>0)&1 ))"
sleep $t
gpio write $SRclk 1
sleep $t
gpio write $SRclk 0

gpio write $Rclk 1
sleep $t
gpio write $Rclk 0

echo "$(( (n>>0)&1 ))"
echo "$(( (n>>1)&1 ))"
echo "$(( (n>>2)&1 ))"
echo "$(( (n>>3)&1 ))"
echo "$(( (n>>4)&1 ))"
echo "$(( (n>>5)&1 ))"
echo "$(( (n>>6)&1 ))"
echo "$(( (n>>7)&1 ))"

# gpio write $OE 0

sleep $t

gpio write $data 0
gpio write $Rclk 0
gpio write $SRclk 0
# gpio write $OE 1
