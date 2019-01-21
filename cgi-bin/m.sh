#!/bin/bash

cd exe/
make 
cp -f cgicc ../cgicc.cgi
chmod +x ../cgicc.cgi

echo "Done."

