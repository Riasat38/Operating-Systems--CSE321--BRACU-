#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t a,b,c;
	int total_process;
	a =fork();
	b = fork();
	c = fork();
	if (a > 0){
		if (a%2 !=0 ){
			pid_t x;
			x = fork();
			total_process++;
		}
		wait(NULL);
		total_process++;
	}
	if (b > 0){
		if (b%2 !=0 ){
			pid_t y;
			y = fork();
			total_process++;
		}
		wait(NULL);
		total_process++;
	}
	if (c > 0){
		if (c%2 !=0 ){
			pid_t z;
			z = fork();
			total_process++;
		}
		wait(NULL);
		total_process++;
	}
	wait(NULL);
	printf("Total Process count : %d \n",total_process);
	return 0;
}		
