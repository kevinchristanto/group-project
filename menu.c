#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
void clear_screen()
{
    system("clear");
}
void main_menu()
{
    clear_screen();
    printf("WELCOME\n");
    printf("-------------\n");
    printf("Log in as?\n");
    printf("1. Admin\n");
    printf("2. Buyer\n");
    printf("9. Exit\n");
    printf("Option : ");
}
void admin_menu()
{
    clear_screen();
    printf("ADMIN MENU:\n");
    printf("-----------------\n");
    printf("1. log-in\n");
    printf("2. input stock\n");
    printf("3. view stock\n");
    printf("4. view history\n");
    printf("9. back\n");
}
void buyer_menu()
{
    clear_screen();
    printf("BUYER MENU:\n");
    printf("-----------------\n");
    printf("1. View profile \n");
    printf("2. Add to cart\n");
    printf("3. View cart\n");
    printf("9. Back\n");
}