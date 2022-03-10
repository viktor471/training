#! /bin/bash

for arg in "$@"
do
	if [ "$arg" == "--help" ] || [ "$arg" == "-h" ]
	then
		echo "help"
	fi
done
