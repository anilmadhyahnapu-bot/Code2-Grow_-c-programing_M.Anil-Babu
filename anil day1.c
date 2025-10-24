#include<stdio.h>
int main()
{
float
hra_percent,da_percent,basic_salary,tax_percent,gross_salary,net_monthly_salary,is_above_50000;
float hra,da,tax;
int x;
printf("enter the hra_percent:");
scanf("%f",&hra_percent);
printf("enter the da_percent:");
scanf("%f",&da_percent);
printf("enter the basic_salary:");
scanf("%f",&basic_salary);
printf("enter the tax_percent:");
scanf("%f",&tax_percent);
tax= basic_salary * (tax_percent / 100);
hra= basic_salary * (hra_percent / 100);
gross_salary = basic_salary + hra_percent+da_percent-tax_percent;
da = basic_salary * (da_percent / 100);
x=(gross_salary>50000);
net_monthly_salary=gross_salary/12;
printf("Net Monthly Salary = %.2f\n", net_monthly_salary);
printf("Gross Salary = %.2f\n", gross_salary);
printf("Is Gross Salary above 50000? %.0f\n", is_above_50000);
printf("tax_percent= %.2f\n", tax_percent);
printf("hra_percent=%.2f\n",hra_percent);
printf("da_percent=%.2f\n",da_percent);
return 0;
}
