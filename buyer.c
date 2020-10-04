#include <stdio.h>
#include "buyer.h"
#include "common.h"

void buyer_menu(void)
{
    while (1)
    {
        print_buyer_menu();
        // TODO: implement logic
        char *input = get_input(">> ");
        if (*input == '1')
        {
            //view_profile();DATABASE
        }
        else if (*input == '2')
        {
            //shop(); DATABASE
        }
        else if (*input == '3')
        {
            //view_cart(); DATABASE
        }
        else if (*input == '4')
        {
            //top_up(); DATABASE
        }
        else if (*input == '9')
        {
            return;
        }
    }
}

void print_buyer_menu(void)
{
    clear_screen();
    printf("BUYER MENU:\n");
    printf("-----------------\n");
    printf("1. View profile \n");
    printf("2. Shop\n");
    printf("3. View cart\n");
    printf("4. Top-up\n");
    printf("9. Back\n");
}
