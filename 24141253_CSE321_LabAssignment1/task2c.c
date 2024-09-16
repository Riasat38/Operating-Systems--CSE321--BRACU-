#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
int main(){
	char password[100];
	printf("Enter Value : ");
	scanf("%s",password);
	//printf("length : %ld",strlen(password));
	
	bool lower, upper, digit, special_char = false;
	int i;
	for (i=0; i<strlen(password);i++){
		if (isupper(password[i])){
			upper = true;
		}else if(islower(password[i])){
			lower = true;
		}else if (isdigit(password[i])){
			digit = true;
		}else if ((password[i] == '_' || password[i] == ',' || password[i] == '$' || password[i] == '#' || password[i] == '@')){
			special_char = true;
		};
	}
	
	if (lower == false){
		 printf("Lowercase character missing  ");
	}if (upper == false){
		printf("Uppercase character missing  ");
	}if (digit == false){
		printf("Digit missing  ");
	}if (special_char == false){
		printf("Special character missing  ");
	}else{
		printf("OK");
	}
	return 0;
}
