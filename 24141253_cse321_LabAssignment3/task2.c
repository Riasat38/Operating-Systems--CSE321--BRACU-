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
struct msg{
	long int type;
	char txt[6];
};

int main(){
	int msg_id;
	struct msg data;
	char buffer[10];
	
	msg_id = msgget((key_t)123,0666|IPC_CREAT);
	printf("Plese enter your workspace name:\n");
	fgets(buffer,sizeof(buffer),stdin);
	if (strncmp(buffer,"cse321",6)!=0){
		printf("Invalid workspace\n");
		exit(0);
	}else{
		data.type = 1;
		strcpy(data.txt,buffer);
		msgsnd(msg_id,(void *)&data,6,0);
		printf("Workspace name sent to OTP generator from log in %s",data.txt);
	}
	pid_t otp;
	otp = fork();
	if (otp == 0){
		int pid =getpid();
		msg_id  = msgget((key_t)123,0666);
		msgrcv(msg_id,(void *)&data,6,1,0);
		printf("OTP generator received workspace name from log in: %s\n",data.txt);
		
		data.type = 2;
		sprintf(data.txt,"%d",pid);
		msgsnd(msg_id,(void *)&data,6,0);
		printf("OTP sent to login from OTP generator: %d\n",pid);
		
		data.type = 3;
		sprintf(data.txt,"%d",pid);
		msgsnd(msg_id,(void *)&data,6,0);
		printf("OTP sent to mail from OTP generator: %d\n",pid);
		
		
		pid_t mail;
		mail = fork();
		if (mail == 0){
			msg_id  = msgget((key_t)123,0666);
			msgrcv(msg_id,(void *)&data,6,2,0);
			printf("Mail received OTP from OTP generator: %s\n",data.txt);
			
			int sent = getpid();
			data.type = 4;
			sprintf(data.txt,"%d",sent);
			msgsnd(msg_id,(void *)&data,6,0);
			printf("OTP sent to login from mail :%s\n",data.txt);
			
		}else{
		wait(NULL);
		}	
	}else{
		wait(NULL);
		msg_id  = msgget((key_t)123,0666);
		long int num =0;
		
		msgrcv(msg_id,(void *)&data,6,-1,0);
		printf("Log in received OTP from OTP generator:%s\n",data.txt);
		msgrcv(msg_id,(void *)&data,6,-2,0);
		printf("Log in received OTP from mail:%s\n",data.txt);
			
	
		printf("OTP verified\n");
	}
	
	
	msgctl(msg_id, IPC_RMID, NULL);
	return 0;
		
}
