#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "bank_data.txt"
#define BANK_NAME "SBI"
#define IFSC_CODE "SBIN0007507"
typedef struct
{
    char name[50];
    char email[50];
    char phone[15];
    char account_type[10];
    char address[100];
    char dob[11];
    char aadhar_no[13];
    char pan_no[11];
    int account_no;
    float balance;
} Account;
void create_account();
void update_account();
void transaction();
void check_account_details();
void remove_account();
void view_customer_list();
int main()
{
    int choice;
    do
    {
        printf("\n\n\t\t\tBank Management System\n");
        printf("\n\t\t\t1. Create new account");
        printf("\n\t\t\t2. Update information of existing account");
        printf("\n\t\t\t3. For transactions");
        printf("\n\t\t\t4. Check the details of existing account");
        printf("\n\t\t\t5. Remove existing account");
        printf("\n\t\t\t6. View customer's list");
        printf("\n\t\t\t7. Exit");
        printf("\n\n\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            update_account();
            break;
        case 3:
            transaction();
            break;
        case 4:
            check_account_details();
            break;
        case 5:
            remove_account();
            break;
        case 6:
            view_customer_list();
            break;
        case 7:
            printf("\n\n\t\t\tThank you!");
            exit(0);
        default:
            printf("\n\n\t\t\tInvalid choice! Please try again.");
        }
    } while (1);
    return 0;
}
void create_account()
{
    Account account;
    FILE *fp;
    fp = fopen(FILE_NAME, "ab+");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    fseek(fp, 0, SEEK_END);
    int total_accounts = ftell(fp) / sizeof(Account);
    account.account_no = total_accounts + 1;
    printf("\n\n\t\t\tEnter name: ");
    scanf("%s", account.name);
    printf("\n\t\t\tEnter email: ");
    scanf("%s", account.email);
    printf("\n\t\t\tEnter phone: ");
    scanf("%s", account.phone);
    printf("\n\t\t\tEnter account type (Savings/Current): ");
    scanf("%s", account.account_type);
    printf("\n\t\t\tEnter address: ");
    scanf("%s", account.address);
    printf("\n\t\t\tEnter date of birth (dd/mm/yyyy): ");
    scanf("%s", account.dob);
    printf("\n\t\t\tEnter Aadhar number: ");
    scanf("%s", account.aadhar_no);
    printf("\n\t\t\tEnter PAN number: ");
    scanf("%s", account.pan_no);
    account.balance = 0;
    fwrite(&account, sizeof(Account), 1, fp);
    fclose(fp);
    printf("\n\n\t\t\tAccount created successfully!");
    printf("\n\t\t\tAccount number: %d", account.account_no);
}
void update_account()
{
    int account_no, choice;
    printf("\n\n\t\t\tEnter account number: ");
    scanf("%d", &account_no);
    FILE *fp;
    fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    Account account;
    while (fread(&account, sizeof(Account), 1, fp))
    {
        if (account.account_no == account_no)
        {
            printf("\n\n\t\t\t1. Update name");
            printf("\n\t\t\t2. Update email");
            printf("\n\t\t\t3. Update phone");
            printf("\n\t\t\t4. Update account type");
            printf("\n\t\t\t5. Update address");
            printf("\n\t\t\t6. Update date-of-birth");
            printf("\n\t\t\t7. Update Aadhar number");
            printf("\n\t\t\t8. Update PAN number");
            printf("\n\n\t\t\tEnter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\n\n\t\t\tEnter new name: ");
                scanf("%s", account.name);
                break;
            case 2:
                printf("\n\n\t\t\tEnter new email: ");
                scanf("%s", account.email);
                break;
            case 3:
                printf("\n\n\t\t\tEnter new phone: ");
                scanf("%s", account.phone);
                break;
            case 4:
                printf("\n\n\t\t\tEnter new account type (Savings/Current): ");
                scanf("%s", account.account_type);
                break;
            case 5:
                printf("\n\n\t\t\tEnter new address: ");
                scanf("%s", account.address);
                break;
            case 6:
                printf("\n\n\t\t\tEnter new date of birth (dd/mm/yyyy): ");
                scanf("%s", account.dob);
                break;
            case 7:
                printf("\n\n\t\t\tEnter new Aadhar number: ");
                scanf("%s", account.aadhar_no);
                break;
            case 8:
                printf("\n\n\t\t\tEnter new PAN number: ");
                scanf("%s", account.pan_no);
                break;
            default:
                printf("\n\n\t\t\tInvalid choice! Please try again.");
            }
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&account, sizeof(Account), 1, fp);
            fclose(fp);
            printf("\n\n\t\t\tAccount updated successfully!");
            return;
        }
    }
    printf("\n\n\t\t\tAccount not found!");
    fclose(fp);
}
void transaction()
{
    int account_no, choice;
    float amount;
    printf("\n\n\t\t\tEnter account number: ");
    scanf("%d", &account_no);
    FILE *fp;
    fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    Account account;
    while (fread(&account, sizeof(Account), 1, fp))
    {
        if (account.account_no == account_no)
        {
            printf("\n\n\t\t\t1. Deposit");
            printf("\n\t\t\t2. Withdraw");
            printf("\n\n\t\t\tEnter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\n\n\t\t\tEnter amount to deposit: ");
                scanf("%f", &amount);
                account.balance += amount;
                break;
            case 2:
                printf("\n\n\t\t\tEnter amount to withdraw: ");
                scanf("%f", &amount);
                if (account.balance < amount)
                {
                    printf("\n\n\t\t\tInsufficient balance!");
                    fclose(fp);
                    return;
                }
                account.balance -= amount;
                break;
            default:
                printf("\n\n\t\t\tInvalid choice! Please try again.");
            }
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&account, sizeof(Account), 1, fp);
            fclose(fp);
            printf("\n\n\t\t\tTransaction completed successfully!");
            printf("\n\t\t\tCurrent balance: %.2f", account.balance);
            return;
        }
    }
    printf("\n\n\t\t\tAccount not found!");
    fclose(fp);
}
void check_account_details()
{
    int account_no;
    printf("\n\n\t\t\tEnter account number: ");
    scanf("%d", &account_no);
    FILE *fp;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    Account account;
    while (fread(&account, sizeof(Account), 1, fp))
    {
        if (account.account_no == account_no)
        {
            printf("\n\n\t\t\tAccount details:");
            printf("\n\t\t\tName: %s", account.name);
            printf("\n\t\t\tEmail: %s", account.email);
            printf("\n\t\t\tPhone: %s", account.phone);
            printf("\n\t\t\tAccount type: %s", account.account_type);
            printf("\n\t\t\tAddress: %s", account.address);
            printf("\n\t\t\tDate of birth: %s", account.dob);
            printf("\n\t\t\tAadhar number: %s", account.aadhar_no);
            printf("\n\t\t\tPAN number: %s", account.pan_no);
            printf("\n\t\t\tAccount number: %d", account.account_no);
            printf("\n\t\t\tCurrent balance: %.2f", account.balance);
            fclose(fp);
            return;
        }
    }
    printf("\n\n\t\t\tAccount not found!");
    fclose(fp);
}
void remove_account()
{
    int account_no;
    printf("\n\n\t\t\tEnter account number: ");
    scanf("%d", &account_no);
    FILE *fp, *temp_fp;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    temp_fp = fopen("temp.txt", "wb");
    if (temp_fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        fclose(fp);
        return;
    }
    Account account;
    while (fread(&account, sizeof(Account), 1, fp))
    {
        if (account.account_no != account_no)
        {
            fwrite(&account, sizeof(Account), 1, temp_fp);
        }
    }
    fclose(fp);
    fclose(temp_fp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    printf("\n\n\t\t\tAccount removed successfully!");
}
void view_customer_list()
{
    FILE *fp;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    Account account;
    printf("\n\n\t\t\tCustomer list:");
    printf("\n\t\t\tName\t\tAccount No.\t\tBalance");
    while (fread(&account, sizeof(Account), 1, fp))
    {
        printf("\n\t\t\t%s\t\t%d\t\t%.2f", account.name, account.account_no, account.balance);
    }
    fclose(fp);
}