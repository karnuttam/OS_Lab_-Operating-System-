#!/bin/bash
echo "Username : Home Directory"
cut -d: -f1,6 /etc/passwd | while IFS=: read user home
do
	echo "$user : $home"
done

