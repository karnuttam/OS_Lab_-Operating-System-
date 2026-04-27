# !/bin/bash
# check if argument is given
if [ $# -ne 1 ]
then
	echo "Usage $0 <directory_path>"
	exit 1
fi
dir=$1

# check if directory exists
if [ ! -d "$dir" ]
then
	echo "Invalid directory"
	exit 1
fi

# list regular files with permission
 find "$dir" -type f -exec ls -l {} \;
