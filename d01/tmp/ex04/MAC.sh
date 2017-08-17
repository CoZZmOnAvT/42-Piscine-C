#!/bin/sh

exec ifconfig -a | grep "^\tether" | cut -d ' ' -f 2