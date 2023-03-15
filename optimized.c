#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

        // Open file with user's phone number as filename
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "wb");
        if (fp == NULL) {
            printf("Error: Could not create account file.\n");
            return 1;
        }

        // Write user data to file
        fwrite(&usr, sizeof(struct user), 1, fp);
        fclose(fp);

        printf("Account created successfully!\n");
    } else if (opt == 2) {
        system("clear");
        printf("Enter your phone no:\t");
        scanf("%s", usr.phone);
        printf("Enter your password:\t");
        scanf("%s", usr.password);

        // Open file with user's phone number as filename
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "rb");
        if (fp == NULL) {
            printf("Error: Account not found.\n");
            return 1;
        }

        // Read user data from file
        fread(&usr, sizeof(struct user), 1, fp);
        fclose(fp);

        // Check if password is correct
        if (strcmp(usr.password, password) == 0) {
            printf("Welcome, %s!\n", usr.ac);
            printf("Your current balance is %.2f\n", usr.balance);
        } else {
            printf("Error: Incorrect password.\n");
        }
    } else {
        printf("Error: Invalid option.\n");
    }

    return 0;
}
