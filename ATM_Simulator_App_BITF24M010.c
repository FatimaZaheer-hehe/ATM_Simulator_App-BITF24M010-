#include<stdio.h>
#include<conio.h>

float balance = 1000.0;
int attempt = 0;
int Max_Attempts = 3;
int pin = 1234;

void WelcomeScreen();
int  Login();
void MainMenu();
void CheckBalance();
void WithdrawMoney();
void DepositMoney();
void ViewHistory();
void LogTransaction(const char*type,float amount);

void WelcomeScreen()
{
    printf("=====================================\n");
    printf("            ATM SIMULATOR APP        \n");
    printf("=====================================\n");
    printf("           Created by Fatima Zaheer,Fatima Khalid,Eshaal Zahra   \n");
    printf("=====================================\n\n");
}

int Login()
{
    int enteredPin;
    while (attempt < Max_Attempts) 
    {
        printf(" Enter your 4-digit PIN:");
        scanf("%d",&enteredPin);

        if (enteredPin == pin)
         {
            printf("Login Successful!\n");
            return 1;
        }
         else
          {
            attempt++;
            printf(" Incorrect PIN!\n Attempts left: %d\n", Max_Attempts-attempt);
        }
    }
    return 0;
}

void MainMenu()
{
    int choice;
    do {
        printf("\n========== Main Menu ==========\n");
        printf("1.  Check Balance  \n");
        printf("2.  Withdraw Money \n");
        printf("3.  Deposit Money  \n");
        printf("4.  View Transaction History  \n");
        printf("5.  Exit   \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
         {
            case 1: 
                   CheckBalance(); 
                   break;
            case 2:
                    WithdrawMoney(); 
                    break;
            case 3:
                    DepositMoney();
                     break;
            case 4:
                    ViewHistory();  
                    break;
            case 5:
                    printf("Thank you for using the ATM Simulator <3.\n"); 
                    break;
            default: 
                    printf("Invalid choice.Try again.\n");
        }
    } while (choice != 5);
}

void CheckBalance() 
{
    printf("\nYour current balance is: Rs. %.2f\n",balance);
}

void WithdrawMoney()
 {
    float amount;
    printf("\n Enter amount to withdraw: Rs. ");
    scanf("%f",&amount);
    if (amount <= 0) 
    {
        printf("Invalid amount.\n");
    } 
    else if (amount > balance) 
    {
        printf("Insufficient balance.\n");
    } 
    else 
    {
        balance = balance-amount;
        printf(" Withdrawal successful. New balance: Rs. %.2f\n",balance);
        LogTransaction("Withdrawal",amount);
    }
}

void DepositMoney()
 {
    float amount;
    printf("\nEnter amount to deposit: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0)
     {
        printf("Invalid amount\n");
    } else {
        balance = balance+amount;
        printf("Deposit successful.\n New balance: Rs. %.2f\n", balance);
        LogTransaction("Deposit", amount);
    }
}
void ViewHistory() 
{
    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL)
     {
        printf("No transactions found.\n");
        return;
    }
    char ch;
    printf("\nTransaction History:\n");
    printf("-----------------------------------------------\n");

    while((ch=fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    fclose(file);
}

void LogTransaction(const char*type, float amount)
{
    FILE *file = fopen("transactions.txt", "a");

    if (file == NULL)
     {
        printf(" Error saving transaction.\n");
        return;
    }
    fprintf(file, "%s: Rs. %.2f | Balance: Rs. %.2f\n", type, amount, balance);
    fclose(file);
}

int main() 
{
    WelcomeScreen();

    if (!Login())
     {
        printf("\n Too many incorrect attempts\n Exiting...\n");
        return 0;
    }
    MainMenu();
    return 0;
}