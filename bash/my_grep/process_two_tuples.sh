#! /usr/bin/env bash
OLDIFS=$IFS


function are_there_args(){

if [ -z "$1" ]; then
    return 1
else
    return 0
fi

}


function swap_ifs(){

if are_there_args $@; then
    export IFS="$1"
else
    export IFS="$OLDIFS"
fi

}



function my_grep(){
    extensions=$1
    patterns=$2

    swap_ifs ","

    include_extensions=()

    for i in $extensions; 
    do
        include_extensions+="--include '*.$i' "
    done;

    new_patterns=()
    for i in $patterns;
    do
        new_patterns+="-e $i "
    done;

    swap_ifs

    grep_command="grep -Irn $include_extensions $new_patterns --color ."

    echo $grep_command
    echo ""
    eval $grep_command
}

process_two_tuples $@


