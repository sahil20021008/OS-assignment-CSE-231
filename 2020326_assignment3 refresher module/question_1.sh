#!/bin/bash
#assignment 3 question 1
echo "you have entered date as $1/$2/$3"
if [ "$(date -d "$2/$1/$3")" ]
then
    cal "$2" "$3"
fi