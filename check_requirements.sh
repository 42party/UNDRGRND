#!/bin/bash

declare -a packages=("xorg" "libxext-dev" "libbsd-dev")
declare -a commands=("gcc" "make")

for package in "${packages[@]}"
do
    if ! dpkg -s "$package" &> /dev/null; then
        echo "$package is not installed. Installing..."
        sudo apt-get update
        sudo apt-get install -y "$package"
    else
        echo "$package is already installed."
    fi
done

for command in "${commands[@]}"
do
    if ! command -v "$command" &> /dev/null; then
        echo "$command is not installed.  Installing..."
		sudo apt-get update
        sudo apt-get install -y "$command"
    else
        echo "$command is already installed."
    fi
done
