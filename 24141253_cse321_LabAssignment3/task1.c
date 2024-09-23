#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/shm.h>
#include<sys/stat.h>
#include<sys/wait.h>

struct shared{
	char sel[100];
	int b;
};

int main(){
	
	pid_t c;
	
	struct shared acc;
	
	int shm_id;
	void *share;
		
	shm_id =  shmget(IPC_PRIVATE,2048,IPC_CREAT|0666);
	share = shmat(shm_id,NULL,0);
	
	char select[100];
	printf("1.Type a to Add Money \n");
	printf("2. Type w to Withdraw Money \n");
	printf("3. Type c to Check Balance \n");
		
	fgets(select,sizeof(select),stdin);
	strcpy((char *)share,select);
	strcpy(acc.sel,select);
      	printf("Your Selection %s\n",acc.sel);
	acc.b = 1000;
	
	c = fork ();
	
	if (c == 0){
		
		int amount;
		char val = *(char *)share;
		if ( val =='a'){
			printf("Enter Amount: ");
			//fgets(amount,sizeof(amount),stdin);
			scanf("%d",&amount);
			if (amount <= 0){
				printf("Adding Failed!! Invalid Amount!!\n");
			}else{
				acc.b += amount;
				printf("Successful Addition ! New Balance : %d \n",acc.b);
			}
		}
		else if ( val =='w'){
			printf("Enter Amount :");
			scanf("%d",&amount);
			if ( amount > 0 && amount < acc.b){
				acc.b -= amount;
				printf("Successful Withdawal \n");
				printf("New Balance:%d \n",acc.b);
			}else{
				printf("Withdrawal Failed!\n");
			}
			
		}
		else if( val == 'c'){
			printf("Balance : %d",acc.b);
		}
		else{
			printf("Invalid Selection.");
		}
		
	}else{
		wait(NULL);
		printf("Thank you for using.");
	}
	shmctl(shm_id, IPC_RMID, NULL);
	return 0;
}
