#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include<strings.h>
#include<stdlib.h>

#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse

sem_t empty;
sem_t full;

int in = 0;
int out = 0;

char crops[warehouseSize]={'R','W','P','S','M'}; //indicating room for different crops
char warehouse[warehouseSize]={'N','N','N','N','N'}; //initially all the room is empty
pthread_mutex_t mutex;


void *Farmer(void *far){
	
	for (int i = 0; i<MaxCrops; i++){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		warehouse[in] = crops[i];
		printf("farmer %d: Insserts crops %c at %d\n",*(int *)far,crops[i],in);
		in = (in +1)%warehouseSize;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
	printf("Farmer%d: ", *(int *)far); 
    
    	for (int j = 0; j < warehouseSize; j++){
        	printf("%c", warehouse[j]);
    	}
    	printf("\n");
	pthread_exit(NULL);
}


void *ShopOwner(void *sho){
	for (int i = 0; i<MaxCrops;i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		char crop = warehouse[out];
		warehouse[out] = 'N';
		printf("Shop owner %d: Remove crops %c from %d\n", *(int *)sho, crop, out);
		out = (out + 1) % warehouseSize; 
        	pthread_mutex_unlock(&mutex);
        	sem_post(&empty);
	}
	printf("ShopOwner%d: ", *(int *)sho);
    	for (int j = 0; j < warehouseSize; j++) {
        	printf("%c", warehouse[j]);
    	}
    	printf("\n");

    	pthread_exit(NULL);
}


int main()
{   
    
    pthread_t Far[5],Sho[5];
    pthread_mutex_init(&mutex, NULL);
    
    sem_init(&empty,0,warehouseSize);//when the warehouse is full thread will wait 
    sem_init(&full,0,0);//when the warehouse is empty thread will wait

    int a[5] = {1,2,3,4,5}; 

    for (int i = 0; i<5; i++){
    	pthread_create(&Far[i],NULL,Farmer,&a[i]);
    	pthread_create(&Sho[i],NULL,ShopOwner,&a[i]);
    }
    for (int i = 0; i<5; i++){
    	pthread_join(Far[i],NULL);
    	pthread_join(Sho[i],NULL);
    }
    //  Closing or destroying mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    

    return 0;
    
}

