#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "login.h"
#include "common.h"

int main_menu(void)
{
    while (1)
    {
        print_main_menu();
        char *input = get_input(">>");
        if (*input == '1')
        {
            return admin_log_in();
        }
        else if (*input == '2')
        {
            return BUYER;
        }
        else
        {
            return EXIT;
        }
        break;
    }
    return EXIT;
}

void print_main_menu(void)
{
    clear_screen();
    printf("WELCOME\n");
    printf("-------------\n");
    printf("Log in as?\n");
    printf("1. Admin\n");
    printf("2. Buyer\n");
    printf("9. Exit\n");
}

int admin_log_in(void)
{
    clear_screen();
    printf("Enter password:\n");
    // hardcoded password for admin
    char password[] = "qwerty123";

    // get password as input
    char *input = get_input("Enter your password: ");

    // validate password
    int counter = 0;
    while (strcmp(password, input) != 0)
    {
        counter++;
        if (counter == 5)
        {
            puts("Maximum invalid tries reached! Please wait 30 seconds");
            sleep(30);
            counter = 0;

            // prompt try again, if yes repeat, no go back to main menu
            char *try_again = get_input("try again?(Y/n) ");
            char c = try_again[0];
            if (tolower(c) == 'y')
            {
                continue;
            }
            else
            {
                return MAX_TRIES;
            }
        }

        printf("Incorrect password!\n");
        free(input);
        input = get_input("Enter your password again: ");
    }
    //TODO :
    return ADMIN;
}

// struct customer
// {
// char username[1000];
// char password[100];
// char phone_number[20];
// double money;
// };

int buyer_log_in(void)
{
    clear_screen();

    // give user choice to login/signup
    while (1)
    {
        printf("1. Sign up\n 2. Log in\n");
        char *sign_up_or_in = get_input("select your choice: ");
        char c = sign_up_or_in[0];

        if (c == '1')
        {
            // TODO: implement logic
            // get buyer username/email and password,
            // get password of username/email from database
            // validate password
            // after validation, if correct return BUYER
        }
        else if (c == '2')
        {
            // TODO: implement logic
            // user enter credentials
            // validate username/email and password
            // insert new record into database
            // after insert, if correct return BUYER
        }
        else
        {
            // TODO: if max tries reach, print prompt like admin_log_in func
            continue;
        }
    }
}

/*
void buyer_log_in() // login to
{
    clear_screen();
    char username[1000];
    char password[100];
    char phone_number[20];

    // 3 baris dibawah ini buat error nanti. username, password & phone_number
    // utk skarang masih kosong, jadi 3 variable dibawah nilainya 0.
    // skali sampai username[username_len - 4], array index error
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
        // ini username/email?
        printf("Enter your username (with .com) : ");
        scanf("%[^\n]*s", username);

        // kalo check kayak ini, sebelum dicheck, pastikan setelah ".com"
        // gada spasi (' ')
        while (username[username_len - 4] == '.'
               && username[username_len - 3] == 'c'
               && username[username_len - 2] == 'o'
               && username[username_len - 1] == 'm')
        {
            printf("Enter a valid username (with .com) : ");
            scanf("%[^\n]*s", username);
        }
    }
    else if (log_in_choice == 2)
    {
        printf("Enter your phone number (starting with 08...): ");
        scanf("%s", phone_number);

        // 0 sama 8 nya lupa di quote ''
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

    // ini infinite loop, setelah scan password ga di check pake forloop
    // diatas. forloopnya masukin ke whileloop ini biar dicheck, klo ga
    // symbols/numbers/uppercase/lowercase ga tambah2. diakhir loop
    // semuanya harus reset 0 lagi.
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
    {
        printf("Invalid input! Please enter again: ");
        scanf("%c", &forgot);
    }
    if (forgot == 'F' || forgot == 'f')
    {
        change_password();
    }
}
*/

// dibawah ini pindah ke buyers.c

/*
void top_up() // add money
{
    int money_to_add;
    printf("Enter amount of money you want to add: ");
    scanf("%lf", &money_to_add);
    buyer.money += money_to_add;
}*/

/*
void profile(char username[], char password[], char phone_number[])
{
    clear_screen();
    struct customer buyer;
    char greetings[100] = "Morning";
    [>
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
    }

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
}*/

/*
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

    [>while (strcmp(new_password, confirm_new_password) != 0)
    {
        printf("Confirmation is invalid! Please enter again: \n");
    }

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
        [>strcpy(password, new_password);<]
        printf("Your password is saved!");
    }
}
*/
