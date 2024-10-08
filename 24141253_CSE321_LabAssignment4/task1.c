#include <pthread.h>   
#include <stdio.h>
#include <string.h>
#include<unistd.h>

#define MAX 10 //producers and consumers can produce and consume upto MAX
#define BUFLEN 6
#define NUMTHREAD 2      /* number of threads */

void * consumer(int *id);
void * producer(int *id);

char buffer[BUFLEN];
char source[BUFLEN]; //from this array producer will store it's production into buffer
int pCount = 0;
int cCount = 0;
int buflen;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty  = PTHREAD_COND_INITIALIZER;
pthread_cond_t full  = PTHREAD_COND_INITIALIZER;

int thread_id[NUMTHREAD]  = {0,1};
int i = 0; 
int j = 0;

int main()
{
    int i;
    
    pthread_t thread[NUMTHREAD];

    strcpy(source,"abcdef");
    buflen = strlen(source);
    
    pthread_create(&thread[0],NULL,(void *)producer,&thread_id[0]);
    pthread_create(&thread[1],NULL,(void *)consumer,&thread_id[1]);
    
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    return 0;
}

void *producer(int *id){
	for (int i = 0; i<MAX;i++ ){
	
		pthread_mutex_lock(&count_mutex);
		
            	
            	buffer[pCount] = source[i%BUFLEN];
            	printf("%d produced %c by Thread %d\n", i, buffer[pCount], *id);
        	pCount++;
        
        	pthread_mutex_unlock(&count_mutex); 
        	
        	sleep(20/60);
        	 
	}
	return NULL;
}

void *consumer(int *id){
	for (int i = 0; i<MAX; i++){
		pthread_mutex_lock(&count_mutex);
		
		printf("%d consumed %c by Thread %d\n", i, buffer[0], *id); 
        
        	for (int j = 0; j < pCount - 1; j++){
            		buffer[j] = buffer[j + 1]; 
        	}
        	pCount--; 
        	
        	pthread_mutex_unlock(&count_mutex); 
        	
       		sleep(20/60);
	}
	return NULL;
}
    
   



 
    



