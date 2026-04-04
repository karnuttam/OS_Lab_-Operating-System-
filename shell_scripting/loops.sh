#1 /bin/bash
a=0;

while [ $a -lt 10 ] #Runs while condition is TRUE
do
  #Print the value of a
  echo "$a";
  #Increment the value by 1
  a=`expr $a + 1`
done 

#for loop
for x in 1 2 3 4 5 6 8
do
if [ $x == 5 ]
then
    break;
fi
echo "Iteration number $x";
done

#until loop
y=0;
until [ $y -ge 10 ] #Runs while condition is FALSE
do
  echo $y;
  y=`expr $y + 1`;
done
