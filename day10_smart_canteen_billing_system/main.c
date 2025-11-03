#include <stdio.h>
int main()
{
int customers,i,j;
int totalRevenue=0;
printf("Enter total number of customers:");
scanf("%d",&customers);
for (i=1;i<=customers;i++)
{
int items,code,qty,total=0,discount=0;
printf("--- Customer %d ---",i);
printf("Menu:1. Sandwich 80 2. Burger 120 3. Pizza Slice 150 4. Coffee 60 5. Juice 50");
printf("Enter number of items: ");
scanf("%d", &items);
for (j=1;j<=items;j++)
{
printf("Enter item code: ");
scanf("%d", &code);
printf("Enter quantity: ");
scanf("%d", &qty);
int price = 0;
if (code == 1) price = 80;
else if (code == 2) price = 120;
else if (code == 3) price = 150;
else if (code == 4) price = 60;
else if (code == 5) price = 50;

printf("Item %d Bill: %d x %d = %d", code, price, qty, price * qty);
total += price * qty;
}
if (total > 500)
{
discount = total * 0.10;
}
printf("Total: %d", total);
printf("Discount: %d", discount);
printf("Final Bill: %d", total - discount);
totalRevenue += (total - discount);
}
printf("Canteen Summary:Total Customers Served: %dTotal Revenue: %d", customers, totalRevenue);
return 0;
}

