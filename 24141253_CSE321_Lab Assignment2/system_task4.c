#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include<sys/types.h>


int main(int argc, char* argv[]){
	
	int len = argc -1;
	int arr[len];
	for (int i = 1; i <= len; i++) {
        	arr[i - 1] = atoi(argv[i]);
    	}	
    	pid_t a = fork();
    	if (a == 0) {
        	for (int i=0; i<len;i++){
        		for (int j = i+1;j<=len;j++){
        			if (arr[i]<arr[j]){
        				int temp = arr[i];
        				arr[i] = arr[j];
        				arr[j] = temp;
        			}
        		}
        	}
        	
        	printf("Sorted array: ");
        	for (int i = 0; i < len; i++) {
            		printf("%d ", arr[i]);
        	}
        	printf("\n");
        	return 0;
        }else{
        	wait(NULL);

        	for (int i = 0; i < len; i++) {
            		int num = arr[i];
            		if (num % 2 == 0) {
                		printf("%d is even\n", num);
            		} else {
                		printf("%d is odd\n", num);
            		}
        }
}
}
