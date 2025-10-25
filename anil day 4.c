#include <stdio.h>
int main()
{
float m1, m2, m3, m4, m5;
float  attendance,total, percentage;
char grade,remarks[20];
printf("Enter marks in 5 subjects (out of 100): ");
scanf("%f%f%f%f%f",&m1,&m2,&m3,&m4,&m5);
printf("Enter attendance percentage:");
scanf("%f",&attendance);
if ((m1<0 || m1>100) || (m2<0 || m2>100) ||(m3<0 || m3>100) || (m4<0 || m4>100) ||(m5<0 || m5>100) || (attendance<0 || attendance>100))
{
printf("\nError: Invalid input! Marks and attendance must be between 0 and 100.\n");
return 0;
}
total=m1+m2+m3+m4+m5;
percentage=total/5.00;
if (attendance<75)
{
grade='F';
printf(remarks,"Fail");
}
else
{
if (percentage>=45&&percentage<50&&attendance>=90)
{
percentage+=5;
if (percentage>100)
percentage=100;
}
if(percentage>=90)
{
grade='A';
printf(remarks,"Excellent");
printf("\n(Note: A+grade awarded)\n");
}
else if
(percentage>=80)
{
grade='A';
printf(remarks,"Very Good");
}
else if (percentage>=70)
{
grade='B';
printf(remarks,"Good");
}
else if
(percentage>=60)
{
grade='C';
printf(remarks,"Average");
}
else if
(percentage>=50)
{
grade='D';
printf(remarks,"Pass");
}
else
{
grade='F';
printf(remarks,"Fail");
}}
printf("Total Percentage:%.2f%%\n",percentage);
printf("Attendance:%.2f%%\n",attendance);
printf("Final Grade:%c\n",grade);
printf("Remarks:%s\n",remarks);
return 0;
}
