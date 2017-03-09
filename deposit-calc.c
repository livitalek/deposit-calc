#include <stdlib.h>
#include <stdio.h>

void dep_and_date(){
	int date, sum;
	printf("Enter the due date and amount of the deposit");
	scanf("%d %d", &date, &sum);
	if(date<=365&&sum>=10000)
		if(sum<=100000) deposit_calc_v1(date,sum);
			else deposit_calc_v2(date,sum);
		else{
			printf ("You entered the input or date incorrectly. Please enter values from the conditions.\n");
			return dep_and_date();
		}
}

int deposit_calc_v1(int date, int sum){
	double income;
	if(date<=30) income=sum*(-0.1);
	if(date>30&&date<=120) income=sum*0.02;
	if(date>120&&date<=240) income=sum*0.06;
	if(date>240&&date<=365) income=sum*0.12;
	printf("Your profit is %.2f RUB.",income);
	return income;
}
int deposit_calc_v2(int date, int sum){
	double income;
	if(date<=30) income=sum*(-0.1);
	if(date>30&&date<=120) income=sum*0.03;
	if(date>120&&date<=240) income=sum*0.08;
	if(date>240&&date<=365) income=sum*0.15;
	printf("Your profit is %.2f RUB.",income);
	return income;
}


int main(){
	dep_and_date();
	return 0;
}
