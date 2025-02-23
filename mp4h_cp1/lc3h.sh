#!/bin/bash

# May need to change
cd lc3tools
if [ $? -ne 0 ]; then
    echo "Failed to change directory to lc3 tools folder."
    exit 1
fi

lc3tools_dir=$(pwd)

make clean > /dev/null 2>&1

file1=lc3as
if [ -f "$file1" ]; then
    rm "$file1"
fi

file2=lc3convert
if [ -f "$file2" ]; then
    rm "$file2"
fi

file3=lc3sim
if [ -f "$file3" ]; then
    rm "$file3"
fi

file4=lc3sim-tk
if [ -f "$file4" ]; then
    rm "$file4"
fi

./configure > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Failed to run configure.sh script."
    exit 1
fi

make > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Failed to run make command."
    exit 1
fi

echo "lc3htools made"


name='lc3has'
lc3has_command="alias $name='$lc3tools_dir/lc3as'"
if grep -q "$lc3has_command" ~/.bashrc; then
    echo "$name set."
else
    echo "$lc3has_command" >> ~/.bashrc
    echo "$name set."
fi

name='lc3hconvert'
lc3hconvert_command="alias $name='$lc3tools_dir/lc3convert'"
if grep -q "$lc3hconvert_command" ~/.bashrc; then
    echo "$name set."
else
    echo "$lc3hconvert_command" >> ~/.bashrc
    echo "$name set."
fi

name='lc3hsim'
lc3hsim_command="alias $name='$lc3tools_dir/lc3sim'"
if grep -q "$lc3hsim_command" ~/.bashrc; then
    echo "$name set."
else
    echo "$lc3hsim_command" >> ~/.bashrc
    echo "$name set."
fi

name='lc3hsim-tk'
lc3hsimtk_command="alias $name='$lc3tools_dir/lc3sim-tk'"
if grep -q "$lc3hsimtk_command" ~/.bashrc; then
    echo "$name set."
else
    echo "$lc3hsimtk_command" >> ~/.bashrc
    echo "$name set."
fi