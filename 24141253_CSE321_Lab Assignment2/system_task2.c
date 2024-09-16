#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t a;
	printf("Process is starting...\n");
	a =fork();
	
	if (a == 0){
		pid_t a1 ;
		a1 = fork();
		if (a1 == 0){
			printf("I am Grandchild \n");
		}
		else{
			wait(NULL);
			printf("I am Child \n");
		}
		
	}
	else{
		wait(NULL);
		printf("I am Parent \n");
		
	}
}
