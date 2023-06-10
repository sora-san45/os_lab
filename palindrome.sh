#!/bin/sh
echo "Enter a number:"
read num
rev=0
org=$num

while [ $num -gt 0 ]
do
    digit=$((num%10))
    rev=$((rev*10+digit))
    num=$((num/10))
done

if [ $rev -eq $org ]
then
    echo "$org is a palindrome."
else
    echo "$org is not palindrome."
fi

