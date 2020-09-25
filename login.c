#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
void change_password();
struct customer
{
    char username[1000];
    char password[100];
    char phone_number[20];
    double money;
};
void clear_screen()
{
    system("clear");
}

static char *get_input()  
{
    char *input = malloc(32);
    fgets(input, 32, stdin);
    return input;
}

void admin_log_in()
{
    clear_screen();
    char password[] = "qwerty123"; 
    printf("Enter your password: ");
    char *input = get_input();
    int counter = 0;
    while (strcmp(password, input) != 0) 
    {
        counter++;
        if (counter == 5)
        {
            puts("Maximum invalid tries reached! Please wait 30 seconds");
            sleep(30); 
            counter = 0; 
        }
        printf("Incorrect password!");
        printf("Enter your password again: ");
        free(input); 
        input = get_input(); 
    }
    
    puts("Password successfully set");
}

void user_log_in() // login to
{
    clear_screen();
    char username[1000];
    char password[100];
    char phone_number[20];
    int username_len = strlen(username);
    int password_len = strlen(password);
    int phone_number_len = strlen(phone_number);

    int log_in_choice;
    printf("Log in with?");
    printf("1. Email");
    printf("2. Phone Number");
    scanf("%d", &log_in_choice);
    getchar();

    if (log_in_choice == 1)
    {
        printf("Enter your username (with .com) : ");
        scanf("%[^\n]*s", username);
        while (username[username_len - 4] == '.' && username[username_len - 3] == 'c' &&
               username[username_len - 2] == 'o' && username[username_len - 1] == 'm')
        {
            printf("Enter a valid username (with .com) : ");
            scanf("%[^\n]*s", username);
        }
    }
    else if (log_in_choice == 2)
    {
        printf("Enter your phone number (starting with 08...): ");
        scanf("%s", phone_number);
        while (phone_number[0] != 0 && phone_number[1] != 8)
        {
            printf("Invalid phone number! Please enter again: ");
            scanf("%s", phone_number);
        }
    }
    else
    {
        while (log_in_choice != 1 && log_in_choice != 2)
        {
            printf("Invalid choice! Plase enter again : ");
            scanf("%d", &log_in_choice);
        }
    }

    printf("Please enter a strong password (with symbols, numbers, uppercase and lowercase letters)\n");
    printf("Enter your password : \n");
    scanf("%[^\n]*s", password);

    int symbols = 0, numbers = 0, uppercase = 0, lowercase = 0;
    for (int i = 0; i < password_len; i++)
    {
        if (password[i] >= 32 && password[i] <= 47)
            symbols += 1;
        else if (password[i] >= '0' && password[i] <= '9')
            numbers += 1;
        else if (password[i] >= 'a' && password[i] <= 'z')
            lowercase += 1;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            uppercase += 1;
    }

    while (symbols < 1 || numbers < 1 || uppercase < 1 || lowercase < 1)
    {
        printf("Your password is not strong enough! Please create a new one: ");
        scanf("%s", password);
    }
    if (symbols >= 1 && numbers >= 1 && uppercase >= 1 && lowercase >= 1)
    {
        printf("Your password is saved!");
    }

    char forgot;
    printf("Forgot password? Press 'F' to continue\n");
    scanf("%c", &forgot);
    getchar();
    while (forgot != 'F' || forgot != 'f')
        ;
    {
        printf("Invalid input! Please enter again: ");
        scanf("%c", &forgot);
    }
    if (forgot == 'F' || forgot == 'f')
    {
        change_password();
    }
}

/*
void top_up() // add money
{
    int money_to_add;
    printf("Enter amount of money you want to add: ");
    scanf("%lf", &money_to_add);
    buyer.money += money_to_add;
}*/

void profile(char username[], char password[], char phone_number[])
{
    clear_screen();
    struct customer buyer;
    char greetings[100] = "Morning";
    /*
        kalau jam sekian - sekian good %s
    if ()
    {
        strcpy(greetings, "Day");
    }
    else if ()
    {
        strcpy(greetings, "Afternoon");
    }
    else if ()
    {
        strcpy(greetings, "Evening");
    }*/

    printf("Hello and Good %s, %s\n", greetings, username);
    printf("Your password : %s\n", password);
    printf("Your phone number : %s", phone_number);
    // printf("Your amount of money : %lf\n", );

    char change_pass;
    printf("Change password? Enter 'C' : ");
    scanf("%c", &change_pass);
    while (change_pass != 'C' && change_pass != 'c')
    {
        printf("Invalid input! Please enter again: ");
        scanf("%c", &change_pass);
    }
    if (change_pass == 'C' || change_pass == 'c')
    {
        change_password(password);
    }

    char add_money;
    printf("Press '+' to add money: ");
    scanf("%c", &add_money);
    while (add_money != '+')
    {
        printf("Invalid input! Please enter again : ");
        scanf("%c", &add_money);
    }
    if (add_money == '+')
    {
    }
}
void change_password()
{
    char new_password[100];
    char confirm_new_password[100];
    printf("Please enter a strong password (with symbols and numbers)\n");
    printf("Enter your new password: ");
    scanf("%s", new_password);
    printf("Confirm new password: ");
    scanf("%s", confirm_new_password);
    int password_len = strlen(new_password);

    /*while (strcmp(new_password, confirm_new_password) != 0)
    {
        printf("Confirmation is invalid! Please enter again: \n");
    }*/

    int symbols = 0, numbers = 0, lowercase = 0, uppercase = 0;
    for (int i = 0; i < password_len; i++)
    {
        if (new_password[i] >= 32 && new_password[i] <= 47)
            symbols += 1;
        else if (new_password[i] >= '0' && new_password[i] <= '9')
            numbers += 1;
        else if (new_password[i] >= 'a' && new_password[i] <= 'z')
            lowercase += 1;
        else if (new_password[i] >= 'A' && new_password[i] <= 'Z')
            uppercase += 1;
    }

    while (symbols < 1 || numbers < 1 || uppercase < 1 || lowercase < 1)
    {
        printf("Your password is not strong enough! Please create a new one: ");
        scanf("%s", new_password);
    }
    if (symbols >= 1 && numbers >= 1 && uppercase >= 1 && lowercase >= 1)
    {
        /*strcpy(password, new_password);*/
        printf("Your password is saved!");
    }
}
