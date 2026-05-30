//Name: Russell Sullivan
//Unix Systems Programming - CS4350 - Section 1
//Assignment Number: 4
//Due Date: 10/16/2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Prototypes
void genUntilGoal(int,int);
int* gen();

int main(){
	printf("\nPracticing C Programming Language\n\n");
	printf("The purpose of this program is to generate");
	printf(" 2 random numbers\nbetween 5 and 50 inclusive.");
	printf(" A sum will be calculated by adding\nthe generated");
	printf(" numbers. Then, the program will find the number of\n");
	printf("times it takes for the sum to be reproduced again.\n");
//label for goto so the user can retry the entered choice
retry_label:
	printf("\nSelect One of the Following\n");
	printf("\t1 - Generate Numbers\n");
	printf("\t9 - Exit The Program\t---- >\t\t");
	int ch = 0;    //Contains the choice selected by the user
		       // 1 = Generate Numbers
		       // 9 = Exit Program
		       // All else: invalid

	scanf("%d",&ch);
	if( ch != 1 && ch != 9 ){
		printf("\n**  Invalid Selection  **\n");
		//clear buffer
		int c;   // trash variable used to clear buffer
		while ((c = getchar()) != '\n' && c != EOF);
		goto retry_label;	
	}

	int* arr = gen();   //dynamic array containing first 2 generated ints
	int sum = arr[0] + arr[1]; //sum of first 2 generated ints

	switch (ch){
		case 1: printf("\n\nFirst Generated Number:   : %i", arr[0]);
			printf("\nSecond Generated Number : %i", arr[1]);
			printf("\nFirst Number + Second Number =\t%i", sum);
			printf("\n\nProcessing  . . . . . . .\n\n");
			genUntilGoal(arr[0], arr[1]);
			goto retry_label;
			break;

		case 9: printf("\n\nProgram is Terminated\n");
			printf("\nImplemented By Russell Sullivan\n");
			printf("\n10 - 16 - 2023\n\n");
			free(arr);
			return 0;
			break;

		default:
			printf("\n**  Invalid Selection  **\n");
			//goto beginning of case statement
			goto retry_label;
			
	}
	
        free(arr);

	
	return 0;
}

/*accepts the generated numbers and calculates the number
of times the numbers are generated to get the desired sum
the generated numbers and the sum are displayed each time
until the desired sum is generated*/
void genUntilGoal(int a, int b){
	bool flag = true;
	int sum0 = a + b;    //sum of initial two generated ints
	int sum1;	     //sum of next two generated ints
	int num0;	     //contains the first generated int
	int num1;	     //contains the second generated int
	int count = 1;	     //accumulator tracking attempts until goal is met
	//generate two random numbers and calculate the sum
	sleep(1); //sleep to allow the seed to change
   while(flag){
	num0 = (rand() % (50 - 5 + 1)) + 5;
	num1 = (rand() % (50 - 5 + 1)) + 5;
	sleep(1);//pause 1 seconds to allow the seed to change
	printf("Generating First Number \t=\t%i", num0);
	printf("\nGenerating Second Number\t=\t%i", num1);
	sum1 = num0 + num1;
	printf("\nThe sum of the generated numbers  is  : %i\n\n", sum1);
	   if( sum0 == sum1 ){
		flag = false;
		printf("\n\nNumber of Times the Numbers were Generated\n");
		printf("Before the Desired sum was reached  =  %i\n\n", count);
			return;
	   }
	count++;	
   }

}


//gen() generates the two random numbers
//returns the two numbers back to the main program
//as an dynamically allocated array
int* gen(){
    int* arr = (int*)malloc(2*sizeof(int));  //contains initial two random ints
    if( arr == NULL ){
	printf("gen() dynamic allocation failed.");
	exit(1);
    }

    //seed
    srand(time(NULL));

    //generate two numbers between 5 and 50
    arr[0] = (rand() % (50 - 5 + 1)) + 5;
    arr[1] = (rand() % (50 - 5 + 1)) + 5;

    return arr;    
}
