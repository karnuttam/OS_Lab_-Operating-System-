# Write  a shell script to display all the usernames and home directories

#! /bin/bash
echo "Username : Home directory"
echo "--------------------------";
cut -d: -f1,6 /etc/passwd | while IFS=: read username homedir
do
 echo "$username : $homedir" ;
 done;
 
 
 #cut helps you pick required data from a file and ignore the rest.
