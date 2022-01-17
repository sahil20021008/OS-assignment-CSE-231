#!/bin/bash
# assignment 3 question 2
operation=$1
a=$#
i=3
sum=$2
while [ $i -le $a ]; do
        if [ "$operation" == "add" ]
        then
            sum=$((sum + $3))
        fi
        if [ "$operation" == "sub" ]
        then
            sum=$((sum - $3))
        fi
        if [ "$operation" == "mul" ]
        then
            sum=$((sum * $3))
        fi
        if [ "$operation" == "div" ]
        then
            sum=$((sum / $3))
        fi
        if [ "$operation" == "exp" ]
        then
            sum=$((sum ** $3))
        fi
        i=$((i+1))
        shift 1
done
echo "the final result is: $sum"