//============================================================================
// Name        : main.cpp
// Author      : Li Feng
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <pthread.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define NUM_THREADS     5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t=0; t<NUM_THREADS; t++){
	  printf("In main: creating thread %ld\n", t);
	  rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
	  if (rc){
		 printf("ERROR; return code from pthread_create() is %d\n", rc);
		 return 0;
	  }
	}

	/* Last thing that main() should do */
	pthread_exit(NULL);

	return 1;
}
