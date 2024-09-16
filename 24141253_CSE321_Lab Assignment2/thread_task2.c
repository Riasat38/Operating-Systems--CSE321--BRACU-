#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
void* printer(void *arg){
	int start,end;
	int c =*(int *)arg ;
	start = (c * 5) +1 ;
	end = start + 4;
	for(int i = start;i<=end;i++){
		printf("Thread %d prints %d\n",c,i);
	}
}


int main()
{
	pthread_t thread [5];
	int threads[5];
	for (int i = 0; i <5; i++){
		threads[i] = i;
		pthread_create(&thread[i], NULL, printer, &threads[i]);
		pthread_join(thread[i], NULL);
	}
	return 0;
}
