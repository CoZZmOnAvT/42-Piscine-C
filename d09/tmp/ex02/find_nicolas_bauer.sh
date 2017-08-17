#!/bin/sh

exec cat $1 | grep "nicolas\tbauer\|bauer\tnicolas" -i  | grep -o -E '([0-9]+-[0-9]+)|([0-9]{5})'