#include <stdio.h>
int main()
{
int num,i,subj1,subj2,subj3;
int passed=0,failed=0;
float class_total=0,high_avg=-1,low_avg=101,avg,total;
int choice=0;
int stu=1;
printf("Smart Student Result Management");
printf("Enter number of students: ");
scanf("%d",&num);
i = 1;
while (i <= num)
{
printf("--- Student %d ---", i);
printf("Enter marks for Subject 1: ");
scanf("%d", &subj1);
printf("Enter marks for Subject 2: ");
scanf("%d", &subj2);
printf("Enter marks for Subject 3: ");
scanf("%d", &subj3);
total = subj1 + subj2 + subj3;
avg = total / 3.0;
class_total += avg;
if (avg > high_avg)
high_avg = avg;
if (avg < low_avg)
low_avg = avg;
if (avg >= 50)
passed++;
else
failed++;
i++;
}

stu = 1;
while (choice != 3) {
printf("Menu 1. View All Results 2. View Class Summary 3. Exit Enter your choice: ");
scanf("%d", &choice);
if (choice == 1)
{
stu=1;
i=1;
printf("--- Result Sheet ---");
while (i <= num)
{
printf("Student %d ", i);
printf("Enter marks for Subject 1: ");
scanf("%d", &subj1);
printf("Enter marks for Subject 2: ");
scanf("%d", &subj2);
printf("Enter marks for Subject 3: ");
total = subj1 + subj2 + subj3;
avg = total / 3.0;
printf("Avg %.1f Grade ", avg);
if (avg >= 90)
printf("A+");
else if (avg >= 80)
printf("A");
else if (avg >= 70)
printf("B");
else if (avg >= 60)
printf("C");
else if (avg >= 50)
printf("D");
else
printf("Fail");
i++;
}}
else if (choice == 2)
{
printf("--- Class Summary ---");
printf("Total Students %d", num);
printf("Passed %d", passed);
printf("Failed %d", failed);
printf("Class Average %.1f", class_total / num);
printf("Highest Average %.1f", high_avg);
printf("Lowest Average %.1f", low_avg);
}
else if (choice == 3)
{
printf("Thank you! Exiting system...");
}
else
{
printf("Invalid choice. Try again.");
}}
return 0;
}
