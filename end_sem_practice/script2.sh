# !/bin/bash
a=10
b=20
add=`expr $a + $b`
echo "Addition: $add"
echo "Subtraction"
sub=`expr $a - $b`
echo "Subtraction: $sub"
echo "Multiplication"
multiply=`expr $a \* $b`
echo "Multiplication: $multiply"
echo "Division"
divide=`expr $b / $a`
echo "Division: $divide"
