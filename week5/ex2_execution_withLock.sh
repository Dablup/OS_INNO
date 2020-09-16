#!/bin/bash

#Here we are running our script 'ex2_withLock.sh' in back and foreground in one moment 10 times with lock file
#in this script the last integer is incremented and pushed into the same file)


#The result of the program is:

# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
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
# 18





#As we can see modifying the scipt adding lock file, we prevent the race conditons.




for ((i = 1; i < 10; i++))
do
    ./ex2_withLock.sh &
    ./ex2_withLock.sh
done
