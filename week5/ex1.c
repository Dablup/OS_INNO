/*

Output of the programm before we used pthread_join

Thread number 0 was created
Hello it is  0 thread
Thread number 1 was created
Hello it is  1 thread
Hello it is  2 thread
Thread number 2 was created
Thread number 3 was created
Hello it is  3 thread
Thread number 4 was created

-----------------------------------------------------

Output of the program after we used pthread_join

Thread number 0 was created
Hello it is  0 thread
Thread number 0 was closed
Thread number 1 was created
Hello it is  1 thread
Thread number 1 was closed
Thread number 2 was created
Hello it is  2 thread
Thread number 2 was closed
Thread number 3 was created
Hello it is  3 thread
Thread number 3 was closed
Thread number 4 was created
Hello it is  4 thread
Thread number 4 was closed

We got this result because 'pthread_join' wait untill the thread will finish and only then we go to the another iteration of the loop and create next thread.
*/


#include <pthread.h>
#include <stdio.h>



void *threadPrint(void *numberOfThread){

    printf("Hello it is  %d thread\n", (int) numberOfThread);
}

int main(){
    int N = 5;
    pthread_t thread[N];
    for (int i = 0; i<5;i++){
        pthread_create(thread+i,NULL,threadPrint,(void *)i);
        printf("Thread number %d was created\n",i);
	pthread_join(*(thread+i),NULL);
	printf("Thread number %d was closed\n",i);
    }
}
