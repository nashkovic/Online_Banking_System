#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct user {
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main() {
    struct user usr;
    FILE *fp;
    char filename[50];
    int opt;

    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);

    if (opt == 1) {
        system("clear");
        printf("Enter your account no:\t");
        scanf("%s", usr.ac);
        printf("Enter your phone no:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance = 0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "wb");
        fwrite(&usr, sizeof(struct user), 1, fp);
        fclose(fp);
        printf("\nAccount created successfully!\n");
    } else if (opt == 2) {
        system("clear");
        printf("Enter your phone no:\t");
        scanf("%s", usr.phone);
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "rb+");
        if (fp == NULL) {
            printf("\nError: Account not found!\n");
            exit(1);
        }
        printf("Enter your password:\t");
        scanf("%s", usr.password);
        fread(&usr, sizeof(struct user), 1, fp);
        if (strcmp(usr.password, password) != 0) {
            printf("\nError: Incorrect password!\n");
            exit(1);
        }
        bool loggedIn = true;
        while (loggedIn) {
            system("clear");
            printf("\n\n1. Deposit");
            printf("\n2. Withdraw");
            printf("\n3. Check Balance");
            printf("\n4. Logout");

            printf("\n\nYour choice:\t");
            scanf("%d", &opt);

            switch (opt) {
                case 1:
                    printf("\nEnter amount to deposit:\t");
                    float deposit;
                    scanf("%f", &deposit);
                    usr.balance += deposit;
                    fseek(fp, -sizeof(struct user), SEEK_CUR);
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    printf("\nDeposit successful!\n");
                    break;
                case 2:
                    printf("\nEnter amount to withdraw:\t");
                    float withdraw;
                    scanf("%f", &withdraw);
                    if (withdraw > usr.balance) {
                        printf("\nError: Insufficient balance!\n");
                    } else {
                        usr.balance -= withdraw;
                        fseek(fp, -sizeof(struct user), SEEK_CUR);
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        printf("\nWithdrawal successful!\n");
                    }
                    break;
                case 3:
                    printf("\nYour account balance is: $%.2f\n", usr.balance);
                    break;
                case 4:
                    loggedIn = false;
                    printf("\nYou have been logged out!\n");
                    break;
                default:
                    printf("\nError: Invalid choice!\n");
            }
            printf("\nPress enter to continue...");
            getchar();
            getchar();
        }
        fclose(fp);
    } else {
        printf("\nError: Invalid choice!\n");
    }

    return 0;
}
