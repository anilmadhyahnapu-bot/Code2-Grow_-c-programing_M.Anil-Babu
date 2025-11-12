#include <stdio.h>
int main(){
int prices[5] = {50, 30, 80, 120, 60};
char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
int quantities[5] = {0, 0, 0, 0, 0};
int num_customers;
int total_revenue = 0;
int total_items_sold = 0;
printf("Cafe Order Management System");
printf("Menu:");
for (int i = 0; i < 5; i++)
{
printf("%d. %s - %d", i + 1, items[i], prices[i]);
}
printf("Enter total number of customers (max 10): ");
scanf("%d", &num_customers);
if (num_customers > 10)
num_customers = 10;
for (int c = 0; c < num_customers; c++)
{
int customer_total = 0;
int order_items, item_no, qty;
printf("--- Customer %d ---", c + 1);
printf("Enter number of items: ");
scanf("%d", &order_items);
for (int j = 0; j < order_items; j++) {
printf("Enter item number and quantity: ");
scanf("%d%d", &item_no, &qty);
if (item_no < 1 || item_no > 5 || qty < 1)
{
printf("Invalid input. Skipping this entry.");
continue;
}
customer_total += prices[item_no - 1] * qty;
quantities[item_no - 1] += qty;
total_items_sold += qty;
}
printf("Total Bill for Customer %d: %d", c + 1, customer_total);
total_revenue += customer_total;
}
int max_index = 0, min_index = 0;
for (int i = 1; i < 5; i++)
{
if (quantities[i] > quantities[max_index])
max_index = i;
if ((quantities[i] < quantities[min_index] && quantities[i] != 0) || quantities[min_index] == 0)
min_index = i;
}
printf("Cafe Summary");
printf("Total Revenue: %d", total_revenue);
printf("Total Items Sold: %d", total_items_sold);
printf("Most Ordered Item: %s", items[max_index]);
printf("Least Ordered Item: %s", items[min_index]);
return 0;
}

