#/bin/bash
neededValue=0

#We take the last integer in the file and then increment it by 1.
neededValue=$(tail -n 1 < file.txt)
((neededValue++))
echo $neededValue >> file.txt


