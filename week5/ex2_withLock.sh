file="file.txt"
lock="${file}.lock"
neededValue=0

while [ -f $lock ]
do
     :
done

ln -s $file $lock



#Find the last integer in the file
neededValue=$(tail -n 1 < file.txt)

#Increment this integer
((neededValue++))


echo $neededValue >> $file

rm $lock
