#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "bank_data.txt"
#define BANK_NAME "SBI"
#define IFSC_CODE "SBIN0007507"
typedef struct Account
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
    struct Account *next;
} Account;
Account *head = NULL;
void load_data_from_file()
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    Account account;
    while (fread(&account, sizeof(Account), 1, fp))
    {
        Account *new_account = malloc(sizeof(Account));
        if (new_account == NULL)
        {
            printf("Memory allocation error.\n");
            fclose(fp);
            return;
        }
        memcpy(new_account, &account, sizeof(Account));
        new_account->next = head;
        head = new_account;
    }
    fclose(fp);
}
void save_data_to_file()
{
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    Account *current = head;
    while (current != NULL)
    {
        fwrite(current, sizeof(Account), 1, fp);
        current = current->next;
    }
    fclose(fp);
}
int accountNumber()
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return 0;
    }
    int accNo = 0;
    Account account;
    while (fread(&account, sizeof(Account), 1, fp))
    {
        accNo = account.account_no;
    }
    fclose(fp);
    if (accNo == 0)
    {
        return 1;
    }
    else
    {
        accNo++;
        return accNo;
    }
}
void create_account()
{
    int type;
    Account *new_account = malloc(sizeof(Account));

    if (new_account == NULL)
    {
        printf("Memory allocation error.\n");
        return;
    }
    new_account->next = NULL;
    new_account->account_no = accountNumber();
    printf("\n\n\t\t\tEnter name: ");
    scanf(" %[^\n]", new_account->name);
    printf("\n\t\t\tEnter email: ");
    scanf("%s", new_account->email);
    printf("\n\t\t\tEnter phone: ");
    scanf("%s", new_account->phone);
    do
    {
        printf("\n\t\t\tEnter account type \n\t\t\t1.Savings\n\t\t\t2.Current :");
        scanf("%d", &type);

        if (type == 1)
        {
            strcpy(new_account->account_type, "Savings");
            break;
        }
        else if (type == 2)
        {
            strcpy(new_account->account_type, "Current");
            break;
        }
        else
        {
            printf("Invalid!!");
        }
    } while (type == 1 || type == 2);
    printf("\n\t\t\tEnter address: ");
    scanf(" %[^\n]", new_account->address);
    printf("\n\t\t\tEnter date of birth (dd/mm/yyyy): ");
    scanf("%s", new_account->dob);
    printf("\n\t\t\tEnter Aadhar number: ");
    scanf("%s", new_account->aadhar_no);
    printf("\n\t\t\tEnter PAN number: ");
    scanf("%s", new_account->pan_no);
    new_account->balance = 0;
    if (head == NULL)
    {
        head = new_account;
    }
    else
    {
        new_account->next = head;
        head = new_account;
    }
    FILE *fp = fopen(FILE_NAME, "ab+");
    if (fp == NULL)
    {
        printf("\n\n\t\t\tError in opening file!");
        return;
    }
    fwrite(new_account, sizeof(Account), 1, fp);
    fclose(fp);
    printf("\n\n\t\t\tAccount created successfully!");
    printf("\n\t\t\tAccount number: %d", new_account->account_no);
}
void update_account()
{
    int type;
    int account_no, choice;
    printf("\n\n\t\t\tEnter account number: ");
    scanf("%d", &account_no);
    Account *current = head;
    while (current != NULL)
    {
        if (current->account_no == account_no)
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
                scanf(" %[^\n]", current->name);
                break;
            case 2:
                printf("\n\n\t\t\tEnter new email: ");
                scanf("%s", current->email);
                break;
            case 3:
                printf("\n\n\t\t\tEnter new phone: ");
                scanf("%s", current->phone);
                break;
            case 4:
                do
                {
                    printf("\n\t\t\tEnter account type \n\t\t\t1.Savings\n\t\t\t2.Current :");
                    scanf("%d", &type);
                    if (type == 1)
                    {
                        strcpy(current->account_type, "Savings");
                        break;
                    }
                    else if (type == 2)
                    {
                        strcpy(current->account_type, "Current");
                        break;
                    }
                    else
                    {
                        printf("Invalid!!");
                    }
                } while (type == 1 || type == 2);
                break;
            case 5:
                printf("\n\n\t\t\tEnter new address: ");
                scanf(" %[^\n]", current->address);
                break;
            case 6:
                printf("\n\n\t\t\tEnter new date of birth (dd/mm/yyyy): ");
                scanf("%s", current->dob);
                break;
            case 7:
                printf("\n\n\t\t\tEnter new Aadhar number: ");
                scanf("%s", current->aadhar_no);
                break;
            case 8:
                printf("\n\n\t\t\tEnter new PAN number: ");
                scanf("%s", current->pan_no);
                break;
            default:
                printf("\n\n\t\t\tInvalid choice! Please try again.");
            }
            FILE *fp = fopen(FILE_NAME, "rb+");
            if (fp == NULL)
            {
                printf("\n\n\t\t\tError in opening file!");
                return;
            }
            while (fread(current, sizeof(Account), 1, fp))
            {
                if (current->account_no == account_no)
                {
                    fseek(fp, -sizeof(Account), SEEK_CUR);
                    fwrite(current, sizeof(Account), 1, fp);
                    fclose(fp);
                    printf("\n\n\t\t\tAccount updated successfully!");
                    return;
                }
            }
            fclose(fp);
            return;
        }

        current = current->next;
    }
    printf("\n\n\t\t\tAccount not found!");
}
void transaction()
{
    int account_no, choice;
    float amount;
    printf("\n\n\t\t\tEnter account number: ");
    scanf("%d", &account_no);
    Account *current = head;
    while (current != NULL)
    {
        if (current->account_no == account_no)
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
                current->balance += amount;
                break;
            case 2:
                printf("\n\n\t\t\tEnter amount to withdraw: ");
                scanf("%f", &amount);

                if (current->balance < amount)
                {
                    printf("\n\n\t\t\tInsufficient balance!");
                    return;
                }
                current->balance -= amount;
                break;
            default:
                printf("\n\n\t\t\tInvalid choice! Please try again.");
            }
            FILE *fp = fopen(FILE_NAME, "rb+");
            if (fp == NULL)
            {
                printf("\n\n\t\t\tError in opening file!");
                return;
            }
            while (fread(current, sizeof(Account), 1, fp))
            {
                if (current->account_no == account_no)
                {
                    fseek(fp, -sizeof(Account), SEEK_CUR);
                    fwrite(current, sizeof(Account), 1, fp);
                    fclose(fp);
                    printf("\n\n\t\t\tTransaction completed successfully!");
                    printf("\n\t\t\tCurrent balance: %.2f", current->balance);
                    return;
                }
            }
            fclose(fp);
            return;
        }
        current = current->next;
    }
    printf("\n\n\t\t\tAccount not found!");
}
void check_account_details()
{
    int account_no;
    printf("\n\n\t\t\tEnter account number: ");
    scanf("%d", &account_no);
    Account *current = head;
    while (current != NULL)
    {
        if (current->account_no == account_no)
        {
            printf("\n\n\t\t\tAccount details:");
            printf("\n\t\t\tName: %s", current->name);
            printf("\n\t\t\tEmail: %s", current->email);
            printf("\n\t\t\tPhone: %s", current->phone);
            printf("\n\t\t\tAccount type: %s", current->account_type);
            printf("\n\t\t\tAddress: %s", current->address);
            printf("\n\t\t\tDate of birth: %s", current->dob);
            printf("\n\t\t\tAadhar number: %s", current->aadhar_no);
            printf("\n\t\t\tPAN number: %s", current->pan_no);
            printf("\n\t\t\tAccount number: %d", current->account_no);
            printf("\n\t\t\tCurrent balance: %.2f", current->balance);
            return;
        }
        current = current->next;
    }
    printf("\n\n\t\t\tAccount not found!");
}
void remove_account()
{
    int account_no;
    printf("\n\n\t\t\tEnter account number: ");
    scanf("%d", &account_no);
    Account *current = head;
    Account *prev = NULL;
    while (current != NULL)
    {
        if (current->account_no == account_no)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            free(current);
            FILE *fp = fopen(FILE_NAME, "rb");
            FILE *temp_fp = fopen("temp.txt", "wb");
            if (fp == NULL || temp_fp == NULL)
            {
                printf("\n\n\t\t\tError in opening file!");
                fclose(fp);
                fclose(temp_fp);
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
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("\n\n\t\t\tAccount not found!");
}
void view_customer_list()
{
    Account *current = head;
    if (current == NULL)
    {
        printf("\n\n\t\t\tNo customers found!\n");
        return;
    }
    printf("\n\n\t\t\tCustomer list:");
    printf("\n\t\t\tName\t\tAccount No.\t\tBalance");
    while (current != NULL)
    {
        printf("\n\t\t\t%s\t\t%d\t\t%.2f", current->name, current->account_no, current->balance);
        current = current->next;
    }
}
int main()
{
    int choice;
    load_data_from_file(); // Load existing data from file
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
            save_data_to_file(); // Save data to file before exiting
            printf("\n\n\t\t\tThank you!");
            exit(0);
        default:
            printf("\n\n\t\t\tInvalid choice! Please try again.");
        }
    } while (1);
    return 0;
}
