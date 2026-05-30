#!/bin/bash
#NAME: Russell Sullivan  CS 4350 - Unix Systems Programming
#Serial Number: 7
#Assignment Number: 3
#Due Date: 9/29/2023   No Later than 10:00am

# 1. Create a File zNew.txt
echo "1. Creating a new File zNew.txt"
touch zNew.txt
echo ""

# 2. Add text to the created file
echo "Fall 2023" >> zNew.txt
echo "CS4350" >> zNew.txt
echo "Section #" >> zNew.txt
echo "001" >> zNew.txt
echo "scripts and shell programming using" >> zNew.txt
echo "zeus ide" >> zNew.txt
echo "@ TEXAS STATE UNIVERSITY" >> zNew.txt

# 3. Display the content of the created file.
echo "2. The content of the created file is :"
cat zNew.txt
echo ""

# 4. Display all lines with alphabet numbers
file="zNew.txt"
echo "3. All lines with alphabet characters: "
grep [A-Za-z] zNew.txt
echo ""

#5.
echo "4. All lines with digits :"
grep [0-9] zNew.txt
echo ""

#6. 
echo "5. All lines with lowercase characters :"
grep [a-z] zNew.txt
echo ""

#7
echo "6. All lines with uppercase characters :"
grep [A-Z] zNew.txt
echo ""

#8
echo "7. All lines with alphanumeric characters :"
grep [[:alpha:]] zNew.txt
echo ""

#9
echo "8. All lines with punctuation characters :"
grep [[:punct:]] zNew.txt
echo ""

#10
echo "9. All lines with the letter s followed by space :"
grep [s\s] zNew.txt
echo ""

#11
echo "10. All lines with the word zeus followed by space :"
grep 'zeus'$'\s' zNew.txt
echo ""

#12
echo "11. All the line that word programming appears at the end of the line :"
grep 'programming'+$ zNew.txt
echo ""

#13
echo "12. All the lines that the word Fall appears at the beginning of the sentence :"
grep ^'Fall' zNew.txt
echo ""

#14
echo "13. All lines that has a word that starts with C and ends with 0 :"
grep ^[C].*0$ zNew.txt
echo ""

#15
echo "14. All the lines that contain a word that starts with s and ends with l :"
awk '/^s|l$/' zNew.txt
echo ""

#16
echo "15. Deleting the existing File zNew.txt"
rm zNew.txt
echo ""

#17
echo "16. Display the content of zNew.txt :"
cat zNew.txt
echo ""

echo "Prepared by Russell Sullivan"
echo "9-29-2023"


