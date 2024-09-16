#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Argument eroor %s", argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1],"a+");
	if (file == NULL){
		printf("Error! File does not exist\n");
		return 1;
	}
	
	char str[200];
	while(1){
		printf("Enter String (-1 to stop):");
		fgets(str,200,stdin);
		if (str[0] == '-' && str[1] == '1' && (str[2] == '\n' || str[2] == '\r')) 
		//if (strcmp(str,"-1") == 0){
			break;
		fputs(str,file);
	}
	fclose(file);
	return 0;
} 
