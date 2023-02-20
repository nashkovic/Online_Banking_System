#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user {
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};
int main(){
	struct user usr;
	FILE *fp;
	char filename[50];
	int opt;

	printf("\nWhat do you want to do?");
	printf("\n\n1. Register an account");
	printf("\n2. Login to an account");

	printf("\n\nYour choice:\t");
	scanf("%d",&opt);

	if(opt == 1){
		system("clear");
		printf("Enter your account no:\t");
		scanf("%s",usr.ac);
		printf("Enter your phone no:\t");
		scanf("%s",usr.phone);
		printf("Enter your new password:\t");
		scanf("%s",usr.password);
		usr.balance = 0;
                strcpy(filename,usr.phone);
		fp = fopen(strcat(filename, ".dat"),"n");
		fwrite(&usr,sizeof(struct user),1,fp);		
	
	}


return 0;
}

