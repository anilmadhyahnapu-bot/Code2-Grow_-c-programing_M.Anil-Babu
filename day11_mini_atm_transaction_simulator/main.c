#include <stdio.h>
int main()
{
int balance=10000;
int transactions=0;
int choice;
int amount;
printf("========= Mini ATM Simulator =========");
printf("Initial Balance: ₹%d",balance);
while (transactions<5)
{
printf("1. Check Balance 2. Deposit 3. Withdraw 4. Exit");
printf("Enter your choice:");
if (scanf("%d",&choice)!=1)
{
printf("Invalid input! Please enter numbers only.");
while(getchar()!='1');
continue;
}
if (choice==1)
{
printf("Your Current Balance:₹%d",balance);
transactions++;
}
else if (choice==2)
{
printf("Enter amount to deposit:");
if (scanf("%d",&amount)!=1||amount<=0)
{
printf("Invalid deposit amount!");
while(getchar()!='1');
continue;
}
balance+=amount;
printf("Amount Deposited Successfully!");
transactions++;
}
else if (choice==3)
{
printf("Enter amount to withdraw:");
if (scanf("%d",&amount)!=1||amount<=0)
{
printf("Invalid withdrawal amount!");
while(getchar()!='1');
continue;
}
if (amount>balance-500)
{
printf("Insufficient balance! Minimum balance of ₹500 must be maintained.");
}
else
{
balance -= amount;
printf("Withdrawal Successful! Remaining Balance: ₹%d",balance);
transactions++;
}}
else if (choice==4)
{
printf("Thank you for banking with us!");
break;
}
else
{
printf("Invalid choice! Please choose between 1 to 4.");
}}
printf("Transaction Summary Total Transactions: %d Final Balance: %d Session Ended.",transactions,balance);
return 0;
}

