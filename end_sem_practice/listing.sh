#!/bin/bash
#check argument is passed or not
if [ $# -ne 1 ]
then
echo "Usage: $0 <directory_path>"
exit 1
fi
dir=$1

#check the passed directory is valid or not
if [ ! -d "$dir" ]
then
echo "Invalid Directory"
exit 1
fi

echo "======Files with read, write, and execute permissions ======"
find "$dir" -type f -perm -rwx
echo ""
echo "===All regular files===="
find "$dir" -type f
echo ""
echo "================Files smaller than 10KB ============="
find "$dir" -type f -size -10k
