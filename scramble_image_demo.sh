#!/bin/bash
for N in 0 1 2 3 4 5 6 7 8 9 10
do  
    P=$(echo "$N/10" | bc -l)
    echo -e "creating image$N.ppm with P=$P"
    head -n 3 image.ppm > image$N.ppm
    tail +4 image.ppm | ./scramble $P >> image$N.ppm
done
