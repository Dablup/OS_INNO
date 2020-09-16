#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Global variables to check whether the producer or consumer is sleeping
int isConsSleep = 0;
int isProdSleep = 0;
struct{
  int capacityOfBuffer;
  int count;
} buffer;


//Function to wakeup the consumer or producer 
//Here 1 is a consumer and 0 is a producer
void wakeup(int i){
  if (i == 1){
      isConsSleep = 0;
  }
  if (i == 0){
    isProdSleep = 0;
  }
}

//Function to put to sleep the consumer or producer 
//Here 1 is a consumer and 0 is a producer
void ourSleep(int i){
  if (i == 1){
    isConsSleep = 1;
  }
  if (i == 0){
    isProdSleep = 1;
  }
}

void* consumer(void* arg){
  int i = 0;
  while(1){
    //If we dont have items in the buffer then consumer should sleep
    //And wait untill producer produces at least 1 item
    while (buffer.count == 0){
      ourSleep(1);
      if (isConsSleep == 0){
        break;
      }
    }

    //If consumer removes data from empty buffer then it is fatal error
    if (buffer.count < 0){
      printf("%d\n",buffer.count);
      printf("ERROR! CONSUMER TRIED TO REMOVE DATA FROM EMPTY BUFFER\n");
      exit(1);
    }

    //Removing the element from buffer
    buffer.count--;

    //If now we have not full buffer then we need to wakeup our producer
    if (buffer.count == buffer.capacityOfBuffer - 1){
      wakeup(0);
    }
  }
}

void* producer(void* arg){
  int i = 0;
  while(1){
    //To not affect the race conditions we need to print only 1 time in a while
    i++;
    if (i % 10000000 == 0){
      printf("Producer: %d\n",buffer.count);
    }

    //If we the buffer is full then producer should sleep
    //And wait untill consumer removes at least 1 item
    while(buffer.count == buffer.capacityOfBuffer){
        ourSleep(0);
        if (isProdSleep == 0){
          break;
        }
    }

    //If producer adds data to the full buffer then it is fatal error
    if (buffer.count > buffer.capacityOfBuffer){
      printf("%d",buffer.count);
      printf("ERROR! PRODUCER TRIED TO ADD DATA TO THE FULL BUFFER");
      exit(1);
    }

    //Adding the element to the buffer
    buffer.count++;

    //If now we have 1 element in the buffer then we need to wakeup our consumer
    if (buffer.count == 1){
      wakeup(1);
    }
  }
}

int main(){
  buffer.capacityOfBuffer = 10;
  buffer.count = 0;
  pthread_t producerThread;
  pthread_t consumerThread;

  pthread_create(&producerThread, NULL, producer, NULL);
  pthread_create(&consumerThread, NULL, consumer, NULL);
  pthread_join(producerThread, NULL);
	pthread_join(consumerThread, NULL);
  return 0;
}
