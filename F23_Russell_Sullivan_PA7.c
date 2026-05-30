//NAME: Russell Sullivan
//Course Number / Name: CS.4350.001 Unix Systems Programming
//Assignment Number: 7
//Due Date: 11/27/2023
//Instructor: Husain Gholoom
//Program Description: The program will access process arrival time,
//	duration, and priority values for a list of 10 processes.
//	The list will be used three times to run through three
//	synchronized threads for CPU scheduling in the following
//	order: First Come, First Served
//	       Shortest Job First
//	       Priority Queue
//	At the end of each scheduling type, the program will display
//	the total duration/time it took for all processes to complete.
#include <stdio.h>
#include <pthread.h>
#include <time.h>

//global mutex to lock and unlock threads
pthread_mutex_t lock;

//Global Array 1: Stores Arrival Time
int arrivals[10] = {5,11,238,254,330,637,1042,1163,1364,1404};
//Global Array 2: Stores Duration
int durations[10] = {100,20,80,20,140,220,360,120,170,110};
//Global Array 3: Stores Process Priority
int priorities[10] = {1,10,3,5,7,2,8,4,9,6};
//Global Array 4: Holds Process Numbers
int processes[10] = {1,2,3,4,5,6,7,8,9,10};
//Global long double will hold the duration in MS for each function
long double cpu_time_used;

//Function Prototypes
void* firstComeFirstServe();
void* shortestJobFirst();
void* priorityQueue();

int main(){
	//print intoduction message
	printf("\nWelcome to Russell Sullivan’s Thread Program\n\n");
	printf("This program will simulate the CPU scheduling Algorithms ");
	printf("in the following order:\n\n");
	printf("	• First Come, First Served\n\n");
	printf("	• Shortest Job First\n\n");
	printf("	• Priority Queue\n\n\n");


	pthread_t thread_id0; //thread handle for firstComeFirstServe()
	pthread_t thread_id1; //thread handle for shortestJobFirst()
	pthread_t thread_id2; //thread handle for priorityQueue()


	//create thread for firstComeFirstServe() and print if failed
	if( pthread_create(&thread_id0,NULL,&firstComeFirstServe,NULL) )
		printf("\nError creating firstComeFirstServe() thread!\n");

	//create thread for shortestJobFirst() and print if failed
	if( pthread_create(&thread_id1,NULL,&shortestJobFirst,NULL) )
		printf("\nError creating shortestJobFirst() thread!\n");

	//create thread for priorityQueue() and print if failed
	if( pthread_create(&thread_id2,NULL,&priorityQueue,NULL) )
		printf("\nError creating priorityQueue() thread!\n");


	pthread_join(thread_id0, NULL);		//join thread 0
	pthread_join(thread_id1, NULL);		//join thread 1
	pthread_join(thread_id2, NULL);		//join thread 2
	pthread_mutex_destroy(&lock);		//destroy mutex lock


	printf("\n\n\n\nProgrammed by Russell Sullivan\n11 - 27 - 2023\n\n");
	return 0;
}


//Function: firstComeFirstServe
void* firstComeFirstServe(){
    clock_t start = clock();	//start clock time   	
    pthread_mutex_lock(&lock);	//lock thread in with mutex

    printf("First Come, First Served Simulation\n\n");
    printf("Process#\tProcess\tID\tDuration\tPriority\n");
    printf("--------------------------------------------------------\n\n\n");

    //print all array data
    for( int i = 0; i < 10; i++ ){
       printf("P%d\t\t%d\t\t%d\t\t%d\n",processes[i],arrivals[i],durations[i],priorities[i]);
    }

    pthread_mutex_unlock(&lock);	//unlock thread with mutex

    clock_t end = clock();		//end clock time
    cpu_time_used = ((long double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTotal Duration: %lf\n\n\n", cpu_time_used);

    pthread_exit(0);			//exit thread and function
}


//Function: shortestJobFirst
void* shortestJobFirst(){
    clock_t start = clock(); 	//start clock time 
    pthread_mutex_lock(&lock);	//lock thread in with mutex
 

     // BubbleSort processes based on duration
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (durations[j] > durations[j + 1]) {
                // Swap durations
                int temp = durations[j];
                durations[j] = durations[j + 1];
                durations[j + 1] = temp;

                // Swap arrival times
                temp = arrivals[j];
                arrivals[j] = arrivals[j + 1];
                arrivals[j + 1] = temp;

                // Swap priorities
                temp = priorities[j];
                priorities[j] = priorities[j + 1];
                priorities[j + 1] = temp;

		// Swap process numbers
		temp = processes[j];
		processes[j] = processes[j + 1];
		processes[j + 1] = temp;
            }
        }
    }

    printf("Shortest Job First Simulation\n\n");
    printf("Process#\tProcess\tID\tDuration\tPriority\n");
    printf("--------------------------------------------------------\n\n\n");

    //print all array data
    for( int i = 0; i < 10; i++ ){
       printf("P%d\t\t%d\t\t%d\t\t%d\n",processes[i],arrivals[i],durations[i],priorities[i]);
    }

    pthread_mutex_unlock(&lock);	//unlock thread with mutex

    clock_t end = clock();		//end clock time
    cpu_time_used = ((long double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTotal Duration: %lf\n\n\n", cpu_time_used);

    pthread_exit(0);			//exit thread and function
}


//Function: priorityQueue
void* priorityQueue(){
    clock_t start = clock();	//start clock time
    pthread_mutex_lock(&lock);	//lock thread in with mutex


    // BubbleSort processes based on priority
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (priorities[j] < priorities[j + 1]) {
                // Swap durations
                int temp = durations[j];
                durations[j] = durations[j + 1];
                durations[j + 1] = temp;

                // Swap arrival times
                temp = arrivals[j];
                arrivals[j] = arrivals[j + 1];
                arrivals[j + 1] = temp;

                // Swap priorities
                temp = priorities[j];
                priorities[j] = priorities[j + 1];
                priorities[j + 1] = temp;
	
		// Swap process numbers
		temp = processes[j];
		processes[j] = processes[j + 1];
		processes[j + 1] = temp;
            }
        }
    }

    printf("Priority Queue Simulation\n\n");
    printf("Process#\tProcess\tID\tDuration\tPriority\n");
    printf("--------------------------------------------------------\n\n\n");

    //print all array data
    for( int i = 0; i < 10; i++ ){
       printf("P%d\t\t%d\t\t%d\t\t%d\n",processes[i],arrivals[i],durations[i],priorities[i]);
    }

    pthread_mutex_unlock(&lock);	//unlock thread with mutex

    clock_t end = clock();		//end clock time
    cpu_time_used = ((long double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTotal Duration: %lf\n\n\n", cpu_time_used);

    pthread_exit(0);			//exit thread and function
}
