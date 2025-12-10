#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define  MAX_TRANSACTION 100

struct Transaction{
        char type[20];
        float  amount;
};
void   write_tranfer_history(struct Transaction *Transaction, int num_transaction){
    FILE * fp = fopen("Tranfer history.txt","w");
    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }
    fprintf(fp,"TranferHistory\n");
    fprintf(fp,"----------------------\n");
    fprintf(fp,"Type\t\t Amount\n");
    for(int i = 0 ;i<num_transaction;i++){

        fprintf(fp,"%s\t\t%.2f\n",Transaction[i].type,Transaction[i].amount);
    }
    fclose(fp);
    }

int main() {
    bool login = false;
    int choose;
    float balance = 0;
    char name[20], password[20], phone[20];
    struct  Transaction  Transaction[MAX_TRANSACTION ];
    int  num_transaction;
    printf("---------------------------------\n");
    printf(" --------Welcome to bank--------\n");
    printf("---------------------------------\n");

    while (!login) {
        printf("[1] Create\n");
        printf("[2] Login\n");
        printf("[3] Forget Password\n");
        printf("----------------\n");
        printf("Choose an option: ");
        scanf("%d", &choose);

        if (choose == 1) {
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter your phone: ");
            scanf("%s", phone);
            printf("Create your password: ");
            scanf("%s", password);
            printf("Successful Create Account\n");
        } else if (choose == 2) {
            char Myname[20], Mypassword[20];
            printf("Name : ");
            scanf("%s", Myname);
            printf("Password : ");
            scanf("%s", Mypassword);
            if (strcmp(name, Myname) == 0 && strcmp(password, Mypassword) == 0) {
                login = true;
                printf("Login successful!!\n");
            } else {
                printf("Incorrect name or password, please try again\n");
            }
        } else if (choose == 3) {
            char gotname[20], gotphone[20];
            printf("Enter your name: ");
            scanf("%s", gotname);
            printf("Enter your phone: ");
            scanf("%s", gotphone);
            if (strcmp(name, gotname) == 0 && strcmp(phone, gotphone) == 0) {
                printf("Enter your new password: ");
                scanf("%s", password);
                printf("Password changed successfully\n");
            } else {
                printf("Name or phone number doesn't match\n");
            }
        } else {
            printf("Invalid choice\n");
        }
    }

    if (login) {
        bool option = false;
        int service;

        while (!option) {
            printf("-----Options-----\n");
            printf("[1] Withdraw\n");
            printf("[2] Deposit\n");
            printf("[3] Check Balance\n");
            printf("[4] Transfer Funds\n");
            printf("[5] Account Details\n");
            printf("[6] Change Phone Number\n");
            printf("[7] Transfer History\n");
            printf("[8] Exit\n");
            printf("-----------------\n");
            printf("Choose an option: ");
            scanf("%d", &service);

            switch(service) {
                case 1:
                    printf("-----Withdraw----\n");
                    printf("Amount : ");
                    float towithdraw;
                    scanf("%f", &towithdraw);
                    if (towithdraw > balance) {
                        printf("You can't withdraw because your balance is less than the withdrawal amount\n");
                    } else {
                        balance -= towithdraw;
                        printf("Successful Withdraw\n");
                        printf("%.2f\n", balance);
                        strcpy(Transaction[num_transaction].type,"withdraw 1");
                        Transaction[num_transaction].amount =  towithdraw;
                        num_transaction ++;
                    }
                    break;
                case 2 :
                    printf("-------Deposit-------\n");
                    printf("Amount : ");
                    float todeposit;
                    scanf("%f", &todeposit);
                    if (todeposit <= 0) {
                        printf("You can't deposit, please enter an amount more than 0\n");
                    } else {
                        balance += todeposit;
                        printf("%.2f\n", balance);
                        printf("Successful Deposit\n");
                        strcpy(Transaction[num_transaction].type,"Deposit 1");
                        Transaction[num_transaction] .amount = todeposit;
                        num_transaction++;
                    }
                    break;
                case 3 :
                    printf("Balance is %.2f\n", balance);
                    break;
                case 4:
                    printf("----------Transfer Funds--------\n");
                    printf("Enter receiver name : ");
                    char receiver[50];
                     scanf("%s", receiver);
                    printf("Enter amount of Transfer : ");
                    float amount;
                    scanf("%f", &amount);
                    if (amount > balance) {
                        printf("You can't transfer, please enter an amount less than or equal to your balance\n");
                    } else {
                        balance -= amount;
                        printf("Transfer successfully %.2f to %s\n", amount, receiver);
                        printf("Your balance is  %f\n",balance);
                        strcpy(Transaction[num_transaction].type,"Transfer1");
                        Transaction[num_transaction].amount = amount;
                        num_transaction++;
                    }

                    break;
                case 5 :
                    printf("----------Account Details---------\n");
                    printf("Your name is %s\n", name);
                    printf("Your password is %s\n", password);
                    printf("Your phone is %s\n", phone);
                    printf("Your balance is %.2f\n", balance);
                    break;
                case 6 :
                    printf("-------------Change Phone Number-------------\n");
                    printf("Enter you new phone number\n");
                    scanf("%s",phone);
                    printf("You new phone number is %s \n",phone);
                    break;
                case 7 :
                    printf("-----------------Transfer History---------------\n");
                    printf("type \t \t amount\n");
                    for (int i  = 0 ; i< num_transaction; i++){
                        printf("%s \t \t%.2f\n",Transaction[i].type,Transaction[i].amount);

                    }
                    break;

                case 8 :
                    option = true;
                    printf("Thank you. Bye bye\n");
                    break;
                default:
                    printf("Invalid option\n");
            }
        }
    }

    return 0;
}
