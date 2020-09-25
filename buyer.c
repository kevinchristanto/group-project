#include <stdio.h>
#include "buyer.h"
#include "common.h"

void buyer_menu(void)
{
    while (1)
    {
        print_buyer_menu();
        // TODO: implement logic

    }
}

void print_buyer_menu(void)
{
    clear_screen();
    printf("BUYER MENU:\n");
    printf("-----------------\n");
    printf("1. View profile \n");
    printf("2. Add to cart\n");
    printf("3. View cart\n");
    printf("9. Back\n");
}



