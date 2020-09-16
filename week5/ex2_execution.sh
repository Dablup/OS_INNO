#!/bin/bash

#Here we are running our script 'ex2.sh' in back and foreground in one moment 10 times without lock file
#in this script the last integer is incremented and pushed into the same file)


#The result of the program is:

# 1
# 2
# 2
# 3
# 4
# 5
# 6
# 7
# 7
# 8
# 9
# 10
# 11
# 12
# 13
# 14
# 15
# 16
# 17


#As we can see the race conditions manifests already on the first iteration.




for ((i = 1; i < 10; i++))
do
    ./ex2.sh &
    ./ex2.sh 
done
