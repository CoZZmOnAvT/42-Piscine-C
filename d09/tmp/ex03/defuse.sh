#!/bin/sh

bombtimestamp=$(stat -s bomb.txt | grep -o -E "st_atime=[0-9]+" | grep -o -E "[0-9]+")

echo $(expr ${bombtimestamp} - 1)