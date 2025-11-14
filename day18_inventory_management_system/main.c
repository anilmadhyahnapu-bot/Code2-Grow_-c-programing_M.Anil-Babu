#include <stdio.h>
#define MAX_PRODUCTS 10
int main() {
int productID[MAX_PRODUCTS];
char productName[MAX_PRODUCTS][50];
int quantity[MAX_PRODUCTS];
float price[MAX_PRODUCTS];
int productCount = 0;
int choice;
do
{
printf("\n*** Inventory Management System ***\n");
printf("1. Input Product Details\n");
printf("2. Display All Products\n");
printf("3. Calculate Inventory Statistics\n");
printf("4. Search Product by ID\n");
printf("5. Exit\n");
printf("Enter your choice: ");
if (scanf("%d", &choice) != 1) {
printf("Invalid input. Please enter a number.\n");
while (getchar() != '\n');
continue;
}
switch (choice) {
case 1:
printf("\n--- Input Product Details ---\n");
if (productCount >= MAX_PRODUCTS) {
printf("Maximum number of products (%d) reached.\n", MAX_PRODUCTS);
break;
}
printf("Enter Product ID (integer): ");
scanf("%d", &productID[productCount]);
printf("Enter Product Name (no spaces): ");
while (getchar() != ' ');
fgets(productName[productCount], 50, stdin);
productName[productCount][strcspn(productName[productCount], " ")] = '';
printf("Enter Quantity in stock (integer): ");
scanf("%d", &quantity[productCount]);
printf("Enter Price per item (float): ");
scanf("%f", &price[productCount]);
productCount++;
printf("Product added successfully! Current product count: %d/%d\n", productCount, MAX_PRODUCTS);
break;
case 2:
printf("\n--- Product List ---\n");
if (productCount == 0) {
printf("No products have been entered yet.\n");
break;
}
printf("---------------------------------------------\n");
printf("| ID   | Name         | Quantity | Price  |\n");
printf("------------------------------------------\n");
for (int i = 0; i < productCount; i++) {
printf("| %-4d | %-35s | %-8d | %-8.2f |\n",
productID[i], productName[i], quantity[i], price[i]);
}
printf("--------------------------------\n");
break;
case 3:
printf("\n--- Inventory Statistics ---\n");
if (productCount == 0) {
printf("No products to analyze.\n");
break;
}
float totalInventoryValue = 0.0;
float maxProductValue = -1.0;
int maxProductIndex = -1;
float minProductValue = -1.0;
int minProductIndex = -1;
for (int i = 0; i < productCount; i++)
{
float currentProductValue = quantity[i] * price[i];
totalInventoryValue += currentProductValue;
if (i == 0)
{
maxProductValue = currentProductValue;
maxProductIndex = i;
minProductValue = currentProductValue;
minProductIndex = i;
}
else
{
if (currentProductValue > maxProductValue)
{
maxProductValue = currentProductValue;
maxProductIndex = i;
}
if (currentProductValue < minProductValue) {
minProductValue = currentProductValue;
minProductIndex = i;
}}}
printf("Total Inventory Value: $%.2f\n", totalInventoryValue);
if (maxProductIndex != -1) {
printf("\nProduct with the Highest Stock Value ($%.2f):\n", maxProductValue);
printf("  ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
productID[maxProductIndex], productName[maxProductIndex],
quantity[maxProductIndex], price[maxProductIndex]);
}
if (minProductIndex != -1) {
printf("\nProduct with the Lowest Stock Value ($%.2f):\n", minProductValue);
printf("  ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
productID[minProductIndex], productName[minProductIndex],
quantity[minProductIndex], price[minProductIndex]);
}
break;
case 4:
printf("\n--- Search Product by ID ---\n");
if (productCount == 0) {
printf("No products to search.\n");
break;
}
int searchID;
int found = 0;
printf("Enter Product ID to search: ");
scanf("%d", &searchID);
for (int j = 0; j < 1; j++) {
for (int i = 0; i < productCount; i++) {
if (productID[i] == searchID) {
printf("\nProduct Found:\n");
printf("  ID: %d\n", productID[i]);
printf("  Name: %s\n", productName[i]);
printf("  Quantity in stock: %d\n", quantity[i]);
printf("  Price per item: $%.2f\n", price[i]);
printf("  Total Stock Value: $%.2f\n", quantity[i] * price[i]);
found = 1;
break;
}}}
if (!found) {
printf("Product with ID %d not found.\n", searchID);
}
break;
case 5:
printf("\nExiting the Inventory Management System. Goodbye!\n");
break;
default:
printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
}}
while (choice != 5);
return 0;
}
