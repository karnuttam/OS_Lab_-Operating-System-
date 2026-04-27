#!/bin/bash

echo "Enter the number to find the factorial: "
read num
if [ $num == 0 ]
then
	echo "The factorial of $num is: 1"
elif [ $num -lt 0 ]
then
	echo "Please the positive number."
else
	fact=1
	for (( i=1; i<=num; i++ ))
	do
		
		fact=`expr $fact \* $i`
	done

echo "The factorial of $num is $fact"
fi
		
