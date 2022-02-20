#!/usr/bin/env sh

function func()
{
	local msg=$1
	local log=$2

  echo "msg: $msg"
  echo "log: $log"
}

func "hello" "friend"

func $1 $2

