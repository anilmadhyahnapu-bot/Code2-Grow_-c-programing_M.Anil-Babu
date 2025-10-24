#include<stdio.h>
int main()
{
float meal_cost,tax,tip,total_bill,person1,person2,person3;
printf("enter meal cost,tax,tip:");
scanf("%f%f%f",&meal_cost,&tax,&tip);
tax=meal_cost*0.05;
tip=meal_cost*0.10;
total_bill=meal_cost+tax+tip;
person1=total_bill/2.0;
person2=total_bill/2.0;
person3=0.0;
printf("total bill;%.2f\n""each person should pay as follows:\n""you:%.2f\n""friend1:%.2f\n""friend2:%.2f\n",total_bill,person1,person2,person3);
return 0;
}
