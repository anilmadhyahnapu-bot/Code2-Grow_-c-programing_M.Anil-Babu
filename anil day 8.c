#include <stdio.h>
int main()
{
int num_customers,customer,num_items,item;
float price,subtotal,final_bill,total_revenue=0,highest_bill=0;
int quantity,feedback;
float total_feedback=0;
printf("Enter number of customers:");
scanf("%d",&num_customers);
for (customer=1;customer<=num_customers;customer++)
{
subtotal=0.0;
printf("Customer%d",customer);
printf("Enter number of items:");
scanf("%d",&num_items);
for (item=1;item<=num_items;item++)
{
printf("Enter price of item%d:",item);
scanf("%f",&price);
printf("Enter quantity:");
scanf("%d",&quantity);
subtotal+=price*quantity;
}
final_bill=subtotal+(subtotal*5/100);
printf("Customer%d Bill%.2f",customer,final_bill);
do
{
printf("Enter feedback (1 to 5):");
scanf("%d",&feedback);
if (feedback<1||feedback>5)
{
printf("Invalid feedback,enter a value between 1and5.");
}}
while (feedback<1||feedback>5);
total_feedback+=feedback;
total_revenue+=final_bill;
if (final_bill>highest_bill)
{
highest_bill=final_bill;
}}
printf("Total Revenue Today:%.2fAverage Feedback Rating:%.2fHighest Bill Amount:%.2f",total_revenue,total_feedback/num_customers,highest_bill);
return 0;
}
