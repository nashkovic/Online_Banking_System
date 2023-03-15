#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user {
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

// Function to register a new user
void registerUser() {
    struct user usr;
    FILE *fp;
    char filename[50];

    printf("\nEnter your account no:\t");
    scanf("%s",usr.ac);
    printf("Enter your phone no:\t");
    scanf("%s",usr.phone);
    printf("Enter your new password:\t");
    scanf("%s",usr.password);
    usr.balance = 0;

    // Open file for writing
    strcpy(filename,usr.phone);
    fp = fopen(strcat(filename, ".dat"),"wb");

    // Write user data to file
    if(fp != NULL) {
        fwrite(&usr,sizeof(struct user),1,fp);
        printf("\nAccount created successfully!\n");
        fclose(fp);
    } else {
        printf("\nError: Unable to create account.\n");
    }
}

// Function to login to an existing user account
void login() {
    struct user usr;
    FILE *fp;
    char filename[50];
    char phone[50], password[50];

    printf("\nEnter your phone no:\t");
    scanf("%s",phone);
    printf("Enter your password:\t");
    scanf("%s",password);

    // Open file for reading
    strcpy(filename,phone);
    fp = fopen(strcat(filename, ".dat"),"rb");

    // Check if file exists and read user data
    if(fp != NULL) {
        fread(&usr,sizeof(struct user),1,fp);
        if(strcmp(usr.password, password) == 0) {
            printf("\nLogin successful!\n");
            // Call function for user account operations
            // e.g. deposit, withdraw, transfer
        } else {
            printf("\nError: Invalid password.\n");
        }
        fclose(fp);
    } else {
        printf("\nError: Account not found.\n");
    }
}

int main() {
    int opt;

    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);

    if(opt == 1) {
        system("clear");
        registerUser();
    } else if(opt == 2) {
        system("clear");
        login();
    } else {
        printf("\nError: Invalid option.\n");
    }

    return 0;
}

