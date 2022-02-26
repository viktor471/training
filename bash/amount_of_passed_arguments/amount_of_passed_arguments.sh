#! /usr/bin/env bash

function amount_of_passed_arguments(){
    echo "amount of passed arguments: $#"

    for var in "$@"
    do
        echo "$var"
    done
}

amount_of_passed_arguments $@