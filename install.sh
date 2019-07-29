#!/bin/bash
red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

echo "Installing Arduino-logger... "

git clone https://github.com/albzn540/Arduino-debug-headers.git
cp Arduino-debug-headers/Logger.cpp include/Logger.cpp

echo "Cleaning up ..."
rm -R Arduino-debug-headers
echo "${green}Done ... ${reset}"