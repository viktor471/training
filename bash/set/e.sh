#!/bin/bash
#Read a non-existing file without setting set -e
cat myfile.txt
echo "Reading a file..."
#Set the set command with -e option
# set -e
# #Read a non-existing file after setting set -e
# cat myfile.txt
# echo "Reading a file..."
