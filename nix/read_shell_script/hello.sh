#! /bin/bash

# echo "hello viktor ${x}"

# set -o xtrace


# var="hello"
# echo $var


# if [ -n "$var" ]; then
#     echo "one more time hello"
# fi

# function get_string() {
#     echo "hello"
# }

# var=$(get_string)

# echo "$var $var"
arr=('a' 'b' 'c d')

func() {
    echo $1
    echo $2
    echo $3
    echo $4
    echo $5
}

func "hello world" "${arr[@]}"


func() {
    arr=("a" "b c")
    echo "${arr[@]}"
}

echo $(func)