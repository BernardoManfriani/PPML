#!/bin/bash

rm time*
rm media*

for x in {2..32}
do
    echo "Running with $x threads"
    for i in {1..200}
    do
        ./maze.x $x >> time_$x.csv
    done
    #media dei tempi
    awk -F, '{sum+=$1} END {print sum/NR}' time_$x.csv >> media.csv

done

exit