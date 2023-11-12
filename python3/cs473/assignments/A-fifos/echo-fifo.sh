#! /bin/bash

fifo_name="$1"

while true
do
    if read line; then
        echo "$1: $line"
    fi
done <"$fifo_name"

