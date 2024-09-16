#include<stdio.h>
#include<string.h>
void remove_space(char *str){
	int j = 0;
	for (int i = 0; str[i] !='\0';i++){
		if (str[i]!= ' ' || (str[i] == ' ' && str[i - 1] != ' ')){
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	
}

int main (){

	char str[50];
	printf("Enter Sentence : \n");
	scanf("%[^\n]s",str);
	getchar();
	remove_space(str);
	printf("Sentence without space : %s \n",str);
	return 0;
	
}
