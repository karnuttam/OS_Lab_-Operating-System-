#! /bin/bash

echo "What is your name?"
read Name
echo "Hello, $Name"

name="Uttam"
echo $name
age=21
echo $age;
my_array=("Apple" "banana" "carrot" "pineapple");
echo ${my_array[@]};
echo "First index: ${my_array[0]}";
echo "Second index: ${my_array[1]}";
my_array+=("Orange");
my_array+=("grapes" "kiwi");
echo "${my_array[@]}" #whole array
echo "${my_array[@]:2}"  #Get all elements from index 2 onward
echo "${my_array[@]:1:3}" #Get 3 elements,starting from index 1

