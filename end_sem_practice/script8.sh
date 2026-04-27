# !/bin/bash
a=0
while [ $a -lt 10 ]
do
	#print the values
	echo $a
	#increment the value
	a=`expr $a + 1`
done

