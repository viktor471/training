#! /usr/bin/env bash

function e(){
    echo "$1"
    $1
}

e "ls -l"

