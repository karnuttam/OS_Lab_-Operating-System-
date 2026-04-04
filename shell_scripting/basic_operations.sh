#! /bin/bash

#Addition
a=10;
b=20;
sum=`expr $a + $b`;
echo "The sum of two given number is $sum";

#Subtraction
a=10;
b=63;
sub=`expr $a - $b`;
echo "The subraction of the two given number is $sub";

#Multiplication
x=25;
y=36;
multiplication=`expr $x \* $y`;
echo "The multiplication of the two given number is $multiplication";

#Division
x=8;
y=4;
division=`expr $x / $y`;
echo "The division of the two given number is $division";

#Remainder
x=58;
y=69;
remainder=`expr $x % $y`;
echo "The remainder is $remainder";

#Assignment Operator
a=56;
y=$a;
echo $y;

#Equality operator
a=45;
b=69;
if [ $a -eq $b ]
then
echo "Both numbers are equal"
else
echo "Both numbers are not equal"
fi


#Not equality operator
a=56;
b=56;
if [ $a -ne $b ]
then
echo "Both numbers are not equal"
else
echo "Both numbers are equal"
fi
