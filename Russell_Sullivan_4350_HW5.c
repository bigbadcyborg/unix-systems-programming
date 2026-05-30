#include <stdio.h>
#include <math.h>

//prototypes
int isPrime(int);
void printPrimes(int);
void printSquarePairs(int);
int isPerfectSquare(int);


int main(){
    int flag = 1;    //loop control variable
    int ch;          //user's integer input
    char foo;        //users character input

       do{
    	printf("\nEnter A Positive Integer ---- >  : ");
    	scanf("%i", &ch);
	if( ch < 0 ){
		printf("\nInvalid Number, Number must be positive.\n");
		goto retry_label;
	} else if( ch > 1000 || ch < 1 ){
		printf("\nInvalid Number, Number must be between 1 and 1000\n\n");
		goto retry_label;
	}

    	//print if user input is prime or not
    	if( isPrime(ch) ){
		printf("\n%d  is  Prime\n\n", ch);
        } else if( !isPrime(ch) ){
		printf("\n%d  is  Not Prime\n\n", ch);
   	} 

 	 //print range of primes
   	 printf("All Prime Numbers between 2 and %d are:\n\n", ch);
   	 printPrimes(ch);

   	 //print square pair numbers up to ch
   	 printSquarePairs(ch);

retry_label:     //label for user to retry input in case of error
	 //clear input buffer
	 int c;    //loop control variable to clear the buffer
	 while ((c = getchar()) != '\n' && c != EOF );

	 printf("\nWould you like to repeat the process for another number?\n\n");
	 printf("Enter Y ,y or N ,n -------->\t");
	 scanf("%c", &foo);

	 if( foo == 'y' || foo == 'Y' ){
		flag = 1;
	 } else if( foo == 'n' || foo == 'N' ){
		flag = 0;
	 } else if( foo >= 0 && foo <= 127 ){
		printf("\nInvalid choice, must enter Y,y or N ,n\n");
		goto retry_label;
		flag = 1;
	 } 
    }while(flag);

    printf("\nMathematics and Computer Programming\n");
    printf("Prepared by Russell Sullivan\n");
    printf("10 -25- 2023\n");
 	
    return 0;
}


//isPrime
//recieves integer
//returns 1 if num is prime
//returns 0 if num is not prime
int isPrime(int num){
    if( num <= 1 ){
        return 0;
    }
    
    //2 and 3 are prime
    if( num == 2 || num == 3){
	return 1;
    }

    //numbers that can be divided by 2 or 3 are !prime
    if( num % 2 == 0 || num % 3 == 0 ){
	return 0;
    }

    //if n is divisible by any number then it is not prime
    for( int i = 5; i * i <=num; i += 6 ){
	if( num % i == 0 || num % (i + 2) == 0 ){
	return 0;
	}
    }

    return 1;
}


//printPrimes
//revieces integer
//prints all prime numbers from 2 up to "num"
void printPrimes(int num){
	//print first num
	printf("2");
	//print rest of primes
	for( int i = 3; i < num; i++ ){
	    if( isPrime(i) == 1){
	        printf(", %i", i);
	    }
	}
	printf(".\n");
}


//printSquarePairs
//revieves integfer
//prints all square pair numbers
void printSquarePairs(int num){
    printf("\n\nThe square pair numbers are:-\n");
    printf("\n\tN\tP\tN + P\tP - N\n");         
    printf("-------------------------------------\n\n");

    for( int i = 1; i <= num; i++ ){
	for( int j = 1; j <= num; j++ ){
		int squaresSum = i + j;
		int squaresDiff = j - i;
		if( isPerfectSquare(squaresSum) && (squaresDiff > 0) )
		   if(isPerfectSquare(squaresDiff)){
			printf("\t%d\t%d\t%d\t%d\n",i,j,squaresSum,squaresDiff);
		}
	}
    }
}


//isPerfectSquare
//recieves the integer to be tested
//descriptiion: takes the square root of num
//   then squares it and tests if the product is = num
//returns num if pefect square
int isPerfectSquare(int num){
	int foo = 0;
	while( foo * foo < num ){
		foo++;
	}
	return (foo * foo == num);
}
