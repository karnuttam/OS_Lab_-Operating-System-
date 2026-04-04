#Find the factorial of the number

echo "Factorial: ";
echo "Enter the number to find the factorial: ";
read number;

if [ $number -lt 0 ]
then
   echo "The factorial of negative number is not applicable";
   exit 1;
fi
fact=1;
for ((i=1; i <= number; i++));
do
fact=$((i * fact));

done
echo "The factorial of the number $number is: $fact";
