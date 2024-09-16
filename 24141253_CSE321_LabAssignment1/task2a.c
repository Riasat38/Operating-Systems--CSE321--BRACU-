#include<stdio.h>
int main(){
	int num1,num2,result;
	printf("Enter the first number");
	scanf("%d",&num1);
	
	printf("Enter the second number");
	scanf("%d",&num2);
	
	if (num1>num2){
		result = (num1 - num2);
	}else if (num1<num2){
		result = (num1 + num2);
	}else if(num1 == num2){
		result = (num1 * num2);
	}
	printf("The result is : %d",result);
	return 0;
}
