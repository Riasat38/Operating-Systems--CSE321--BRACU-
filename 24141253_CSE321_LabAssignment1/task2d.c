#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
	char email[50];
	
	printf("Enter email : ");
	scanf("%s",email);
	printf(email,strlen(email));
	
	if (strstr(email, "@sheba.xyz") != NULL) {
        	printf("Email address is okay\n");
    	} else {
        	printf("Email address is outdated\n");
    	}
    	return 0;
}
