#include <stdio.h>
#include <string.h>
#include <pthread.h>

int ascii_sum(const char* str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0' ; i++) {
        sum += str[i];
    }
    return sum;
}




void *ascii(void *arg) {
    const char *name = (const char *)arg;
    int sum = ascii_sum(name);
    printf("Thread: ASCII sum for '%s' is %d\n", name, sum);
    return (void *)sum;
}

int main(){
	const char *names[3] ={"Riasat","Ahmed","Riasat"};
	pthread_t threads[3];
	void *results[3];
	for (int i = 0; i < 3; i++) {
        	pthread_create(&threads[i], NULL, ascii, (void *)names[i]);
        	pthread_join(threads[i], &results[i]);
    	}
    	
    	int sum1 = (int)results[0];
    	int sum2 = (int)results[1];
    	int sum3 = (int)results[2];
    	
    	pthread_t compare;
    	pthread_create(&compare, NULL, NULL, NULL); 

    	if (sum1 == sum2 && sum2 == sum3) {
        	printf("Eureka!\n");
    	} else if (sum1 == sum2 || sum1 == sum3 || sum2 == sum3) {
        	printf("Miracle!\n");
    	} else {
        	printf("Hasta la vista!\n");
    	}

    	pthread_join(compare, NULL);
    	return 0;
}
