# File listing based on conditions
#! /bin/bash

#Ask user for directory path

read -p "Enter directory path: " dir

# Check if directory exists
if [ ! -d "$dir" ]; 
then
echo "Directory does not exist!"
exit 1
fi

echo "-------------------------------------------"
echo "1. Files with read(r), write(w), execute(x) permissions: "
find "$dir" -type f -perm 777
echo "2. All regular files: "
find "$dir"-type f
echo "3.All files smaller than 10KB:"
find "$dir" -type f -size -10k
echo "======================================"
