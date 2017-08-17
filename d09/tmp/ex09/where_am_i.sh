#!/bin/sh

addrs=$(ifconfig | grep "inet" | grep -o -E "[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+" | tr '\n' ' ')

if [[ addrs == false ]]; then
	echo "Je suis perdu!"
else
	echo ${addrs} | tr ' ' '\n'
fi