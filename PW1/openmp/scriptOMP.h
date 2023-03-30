#!/bin/bash

time=[]

for x in {2..8}
do
    echo "Running with $x threads"
    ./maze.x $x

done



exit