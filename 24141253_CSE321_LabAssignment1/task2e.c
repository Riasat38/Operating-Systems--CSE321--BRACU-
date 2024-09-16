#include<stdio.h>
#include<string.h>
int main(){
	char word[50];
	scanf("%s",word);
	printf("%s, %ld",word,strlen(word));
	int front = 0;
	int back = strlen(word)-1;
	while (front < back) 
	{
	if (word[front] == word[back]){
		front++;
		back--;
	}else{
		printf("Not a Paliindrome");
		return 0;
	}
	}
	printf("Palindrome");
	return 0;
}
