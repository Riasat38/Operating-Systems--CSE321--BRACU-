#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPerfect(int num){
	int sum = 0;
	for (int i=1;i<num;i++){
		if (num%i == 0) sum+=i;
	}
	if (sum == num && num != 1) {
		return true;
		}
	return false;
}


int main(){
	int start,end;
	printf("Enter Range : ");
	scanf("%d%d",&start,&end);
	
	for (int i = start; i<=end; i++){
		if (isPerfect(i)) {
			printf("%d \n",i);
			}
	}
	return 0;
}
