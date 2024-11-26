#!/bin/bash
#NAME : Russell Sullivan
#CS 4350 : Unix Systems Programming
#Section Number: 001
#Assignment Number : 2
#Due Date : 9/18/2023 no later than 5:15 pm.
v1=null
v2=null
v3=null
echo "This Script is Designed and Implemented by Russell Sullivan
The Function of This script is to:
1. Display the integer arguments that are entered.
2. Display the smallest of the integer arguments
3. Display the largest of the integer arguments
4. Sum of the 3 integer arguments.
5. Product of the 3 integer arguments.
6. Average of the 3 integer arguments.
7. Square of each integer argument.
8. Determine that each integer argument is positive, negative or
zero.
9. Determine that each integer argument is odd, or even
10. Find all even numbers between 1 and the first integer
argument.
11. Find all even numbers between 1 and the third integer
argument.
12. Find the factorial of the last integer argument.
13. Determine whether the second integer argument is a prime
number.
14. Calculating Distinct Sequence"    
read -p "Enter 3 integer Values ----> " v1 v2 v3
if [[ $v1 -eq  null || $v2 -eq null || $v3 -eq null ]]
then
	echo "**** Error - Must input 3 integer values"
	echo "End of script"
	echo "Russell Sullivan - 9 - 18 - 2023"
	exit 1
fi
echo "You Entered $v1 $v2 $v3"

#print smallest
if [ $v1 -lt $v2 ] 
then
   smallest=$v1
elif [ $v2 -lt $v1 ]
then
   smallest=$v2
fi

if [ $smallest -gt $v3 ]
then
   smallest=$v3
fi

echo "The Smallest integer is $smallest"

#print largest

if [ $v1 -gt $v2 ]
then
   largest=$v1
elif [ $v2 -gt $v1 ]
then
   largest=$v2
fi

if [ $v3 -gt $largest ]
then
   largest=$v3
fi

echo "The Largest integer is $largest"

#print sum
echo -n "$v1 + $v2 + $v3 = "
echo $(( v1 + v2 + v3 ))

#print product
echo -n "$v1 * $v2 * $v3 = "
echo $((v1 * v2 * v3 ))

#print average
echo -n "($v1 + $v2 + $v3)/3 = "
num=$((v1 + v2 + v3))
num=$((num / 3))
echo $num

#print squares
echo -n "$v1*$v1 = "
echo -n $(( v1 * v1 ))
echo -n " , "

echo -n "$v2*$v2 = "
echo -n $(( v2 * v2 ))
echo -n " , "

echo -n "$v3*$v3 = "
echo $(( v3 * v3 ))

#print if each variable is positive or negative
if [ $v1 -lt 0 ]
then
	echo -n "$v1 is negative, "
elif [ $v1 -gt 0 ]
then
	echo -n "$v1 is positive, "
elif [ $v1 -eq 0 ]
then
	echo -n "$v1 is zero, "
fi

if [ $v2 -lt 0 ]
then
	echo -n "$v2 is negative, "
elif [ $v2 -gt 0 ]
then
	echo -n "$v2 is positive, "
elif [ $v2 -eq 0 ]
then
	echo -n "$v2 is zero, "
fi

if [ $v3 -lt 0 ]
then
	echo "$v3 is negative"
elif [ $v3 -gt 0 ]
then
	echo "$v3 is positive"
elif [ $v3 -eq 0 ]
then
	echo "$v3 is zero"
fi

#determine if each variable is odd or even
rem=$(( v1 % 2 ))
if [ $rem -eq 0 ]
then
	echo -n "$v1 is even, "
else
	echo -n "$v1 is odd, "
fi

rem=$(( v2 % 2 ))
if [ $rem -eq 0  ]
then
	echo -n "$v2 is even, "
else
	echo -n "$v2 is odd, "
fi

rem=$(( v3 % 2 ))
if [ $rem -eq 0 ]
then
	echo "$v3 is even"
else
	echo "$v3 is odd"
fi

#print even numbers between 1 and v1
index=1;
if [ $v1 -gt 0 ]
then
   echo -n "All even numbers between 1 and $v1 are: "
   while [ $index -lt $v1 ] #positive case
   do
      rem=$(( $index % 2 ))
      if [ $rem -eq 0 ]
      then
         echo -n "$index "
      fi
   index=$(($index+1))
   done
echo ""
elif [ $v1 -lt 0 ]      #negative case
then
   echo -n "All even numbers between $v1 and 1 are: "
   v1cpy=$((v1+1))
   index=1
   while [ $v1cpy -lt $index ]
   do
      rem=$(( $v1cpy % 2 ))
      if [ $rem -eq 0 ]
      then
         echo -n "$v1cpy "   
      fi
   v1cpy=$(($v1cpy+1))
   done
echo ""
fi

#print odd numbers between 1 and v3
index=1;
if [ $v3 -gt 0 ]
then
   echo -n "All odd numbers between 1 and $v3 are: "
   while [ $index -lt $v3 ] #positive case
   do
      rem=$(( $index % 2 ))
      if [[ $rem -ne 0 && $index -ne 1 ]]
      then
	if [ $index -ne $v3 ]
	then
           echo -n "$index "
	fi
      fi
   index=$(($index+1))
   done
echo ""
elif [ $v3 -lt 0 ]      #negative case
then
   echo "All odd numbers between $v3 and 1 are: "
   v3cpy=$((v3+1))
   index=1
   while [ $v3cpy -lt $index ]
   do
      rem=$(( $v3cpy % 2 ))
      if [[ $rem -ne 0 && $v3cpy -ne 1 ]]
      then
         if [ $v3cpy -ne $v3 ]
	 then 
            echo -n "$v3cpy "
	 fi   
      fi
   v3cpy=$(($v3cpy+1))
   done
echo ""
fi
#find the factorial of the last integer argument
if [ $v3 -lt 1 ]
then
   echo "Error finding factorial: third arg is less than 1."
else
   count=$v3
   fact=1
   while [ $count -gt 1 ]
   do
      fact=$((fact * count))
      count=$((count-1))
   done
   echo "Factorial of $v3 is: $fact"
fi

#determine whether or not the second arg is a prime number
if [ $v2 -lt 1 ]
then
	echo "Error finding prime number: second arg is less than 1."
else
	flag=0
	count=2
	while [ $count -lt $v2 ]
	do
		rem=$((v2%count))
		if [ $rem -eq 0 ]
		then
			flag=1
		fi
	count=$((count+1))
	done

	if [ $flag -eq 1 ]
	then
		echo "$v2 is not prime"
	else
		echo "$v2 is prime"
	fi
fi

#calculate the distinct sequence of the second integer
num=$v2
echo -n "Distinct sequence for the integer $v2 is : "
echo -n "$num "
while [ $num -ne 1 ]
do
	rem=$((num%2))
	if [ $rem -eq 0 ] #even case
	then
		num=$((num / 2))
	elif [ $rem -ne 0 ]
	then
		num=$((num * 3 + 1))
	fi
	echo -n "$num "
done

echo ""
echo "End of script"
echo "Russell Sullivan - 9 - 18 - 2023"

exit 0

