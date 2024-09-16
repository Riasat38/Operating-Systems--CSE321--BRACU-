#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>


int var = 0;
void* counter(void* arg)
{
	var++;
}

int main()
{
	pthread_t thread [5];
	for (int i = 1; i <= 5; i++)
	{
		pthread_create(&thread[i], NULL, counter, NULL);
		pthread_join(thread[i], NULL);
		printf("Thread- %d  running.\n", i);
		printf("Thread- %d closed\n", i);
	}
	return 0;

}
