# !/bin/bash
Name="Rohit"
Age=49
echo $Name
echo $Age
my_array=("apple" "banana" "cherry")
my_array[3]="Blue Berries"
my_array[4]="Pineapple"
my_array[5]="mango"
echo "First Index: ${my_array[0]}"
echo "Fifth Index: ${my_array[5]}"
echo "Reverse index: ${my_array[-1]}"
echo "Array: $my_array"
my_array+=("orange")
my_array+=("grape" "kiwi")
echo "${my_array[@]}"
echo "${my_array[@]: 2}"
echo "${my_array[@]: 1: 3}"
val="expr 2 + 2"
val=`expr 2 + 2`
echo "Total value : $val"
