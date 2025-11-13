#include <stdio.h>
#include <string.h>
int main()
{
char name[50], regno[20], section[10];
int salaries[10], n, i, choice, total = 0;
float average = 0.0;
int highest, lowest, aboveAvg = 0, belowAvg = 0, temp, j;
printf("Employee Salary Analysis System");
printf("Enter Student Name: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "")] = 0;
printf("Enter Registration Number: ");
fgets(regno, sizeof(regno), stdin);
regno[strcspn(regno, "")] = 0;
printf("Enter Section: ");
fgets(section, sizeof(section), stdin);
section[strcspn(section, "")] = 0;
do
{
printf("Enter number of employees (max 10): ");
scanf("%d", &n);
}
while (n < 1 || n > 10);
for (i = 0; i < n; i++)
{
printf("Enter salary %d: ", i + 1);
scanf("%d", &salaries[i]);
}
do
{
printf("Menu");
printf("1. Display All Salaries");
printf("2. Display Total and Average Salary");
printf("3. Display Highest and Lowest Salary");
printf("4. Count Employees Above and Below Average");
printf("5. Display Sorted Salaries Ascending");
printf("6. Exit");
printf("Enter your choice: ");
scanf("%d", &choice);
printf("Submitted by %s Reg No %s Section %s", name, regno, section);
printf("Challenge Day 17 Code2Grow");
if (choice == 1)
{
printf("Salaries: ");
for (i = 0; i < n; i++)
printf("%d ", salaries[i]);
printf("");
}
else if (choice == 2)
{
total = 0;
for (i = 0; i < n; i++)
total += salaries[i];
average = ((float)total) / n;
printf("Total Salary: %d", total);
printf("Average Salary: %.2f", average);
}
else if (choice == 3)
{
highest = salaries[0];
lowest = salaries[0];
for (i = 1; i < n; i++) {
if (salaries[i] > highest) highest = salaries[i];
if (salaries[i] < lowest) lowest = salaries[i];
}
printf("Highest Salary: %d", highest);
printf("Lowest Salary: %d", lowest);
}
else if (choice == 4) {
total = 0;
for (i = 0; i < n; i++)
total += salaries[i];
average = ((float)total) / n;
aboveAvg = 0;
belowAvg = 0;
for (i = 0; i < n; i++) {
if (salaries[i] > average) aboveAvg++;
else if (salaries[i] < average) belowAvg++;
}
printf("Employees Above Average: %d", aboveAvg);
printf("Employees Below Average: %d", belowAvg);
}
else if (choice == 5) {
for (i = 0; i < n-1; i++) {
for (j = 0; j < n-i-1; j++) {
if (salaries[j] > salaries[j+1]) {
temp = salaries[j];
salaries[j] = salaries[j+1];
salaries[j+1] = temp;
}}}
printf("Salaries in Ascending Order: ");
for (i = 0; i < n; i++)
printf("%d ", salaries[i]);
printf("");
}
else if (choice != 6) {
printf("Invalid choice. Please try again.");
}}
while (choice != 6);
printf("End of Program");
printf("Submitted by %s Reg No %s Section %s", name, regno, section);
printf("Challenge Day 17 Code2Grow");
return 0;
}

