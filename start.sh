#!/bin/bash
mkdir $1
ls
cd $1
touch 2023_$1.c
SESSION=$(cat ../.env | grep SESSION | cut -d '=' -f2)
aoc -d $1 -y 2023
curl https://adventofcode.com/2023/day/$1/input --cookie "session=$SESSION" > input.txt
