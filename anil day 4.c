#include <stdio.h>
int main()
{
int marks[5];
int i;
float attendance,total=0,percentage;
char grade;
char remarks[20];
printf("Enter marks in 5 subjects:");
for (i=0;i<5;i++)
{
scanf("%d",&marks[i]);
if (marks[i]<0||marks[i]>100)
{
printf("Invalid marks entered Exiting.");
return 1;
}
total+=marks[i];
}
printf("Enter attendance percentage:");
scanf("%f",&attendance);
percentage=total/5.0;
if (attendance<75)
{
grade='F';
printf(remarks,"Fail");
}
else
{
if (percentage>=45&&percentage<=49&&attendance>=90)
{
percentage+=5;
}

if (percentage>=90)
{
grade='A';
printf(remarks,"Excellent");
}
else if (percentage>=80)
{
grade='A';
printf(remarks,"Very Good");
}
else if (percentage>=70)
{
grade='B';
printf(remarks,"Good");
}
else if (percentage>=60)
{
grade='C';
printf(remarks,"Average");
}
else if (percentage>=50)
{
grade='D';
printf(remarks,"Pass");
}
else
{
grade='F';
printf(remarks,"Fail");
}
}
printf("Total Percentage:%.2f",percentage);
printf("Attendance:%.2f",attendance);
printf("Final Grade:%c",grade);
printf("Remarks:%s",remarks);
return 0;
}
