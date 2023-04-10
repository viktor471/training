#! /bin/bash

while ! systemctl is-active "$1" --quiet; do
    echo "wait for $1 service"
    sleep 0.1
done

