#include<stdio.h>
struct{
	int quantity;
	int price;
}paratha,vegetables,water;

int main(){
	int people;
	float total,per_person;
	
	printf("Enter Paratha :");
	scanf("%d",&paratha.quantity);
	printf("\nParatha Price :");
	scanf("%d",&paratha.price);
	
	printf("\nEnter Vegetables :");
	scanf("%d",&vegetables.quantity);
	printf("\nVegetables Price :");
	scanf("%d",&vegetables.price);
	
	printf("\nEnter Water :");
	scanf("%d",&water.quantity);
	printf("\nWater Price :");
	scanf("%d",&water.price);
	
	printf("Enter Number of people :");
	scanf("%d",&people);
	printf("\n%d",people);
	
	total = (paratha.quantity * paratha.price) + (vegetables.quantity * vegetables.price) + (water.quantity * 		water.price);
	per_person = total / people;
	
	printf("\n Total Bill : %f tk",total);
	printf("\n Individual Share : %f tk",per_person);
	
	
	return 0;
	
}

