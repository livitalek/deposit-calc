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

int main(){
	dep_and_date();
	return 0;
	}
