#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t a;
	printf("Process is starting...\n");
	a =fork();
	
	if (a == 0){

		printf("I am Child ID: %d \n",getpid());
		pid_t c1,c2,c3 ;
		wait(NULL);
		c1 = fork();
		if (c1 == 0){
			printf("I am Grandchild C1 ID: %d \n",getpid());
		}
		c2 = fork();
		if (c2 == 0){
			printf("I am Grandchild C2 ID: %d \n",getpid());
		}
		c3 = fork();
		if (c3 == 0){
			printf("I am Grandchild C3 ID: %d \n",getpid());
		}	
	}
	else{
		printf("I am Parent: %d \n",getpid());
		
	}
	return 0;
}
