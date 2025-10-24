#include <stdio.h>
int main()
{
int units;
float bill,meter_charge=50;
printf("Enter total units:");
scanf("%d",&units);
if (units<=100)
{
bill=units*3.0;
}
else if (units<=200)
{
bill=units*4.5;
}
else if (units<=300)
{
bill=units*6.0;
}
else
{
bill=units*8.0;
}
bill+=meter_charge;
printf("Electricity Bill Summary");
printf("Units Consumed:%d",units);
printf("Total Bill including metercharge:%2f",bill);
return 0;
}
