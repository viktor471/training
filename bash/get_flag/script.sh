#! /bin/bash
args=("a" "b" "c" "--file pytests -m smoketest")
options=$(getopt -o "f::" "-f pytests -m smoketest")

echo ${options[@]}

for arg in "${optins[@]}"
do
    case $arg in
        -f|--folder) echo "hello" ;;
        *)           echo "not found";;
    esac
done

# options=$(getopt -l "help,version:,verbose,rebuild,dryrun" -o "hv:Vrd" -a -- "$@")
#print_usage() {
#  printf "Usage: ..."
#  }
#
#  while getopts 'abf:v' flag; do
#    case "${flag}" in
#        a) a_flag='true' ;;
#        b) b_flag='true' ;;
#        f) files="${OPTARG}" ;;
#        v) verbose='true' ;;
#        *) print_usage
#        exit 1 ;;
#    esac
#  done
