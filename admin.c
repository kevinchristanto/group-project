#include <stdio.h>
#include "admin.h"
#include "common.h"
#include "login.h"

void admin_menu(void)
{
    while (1)
    {
        print_admin_menu();
        // TODO: implement logic
        char *input = get_input(">> ");
        if (*input == '1')
        {
            //input_stock();
        }
        else if (*input == '2')
        {
            //view_stock();
        }
        else if (*input == '3')
        {
            //view_history();
        }
        else if (*input == '9')
        {
            return;
        }
    }
}

void print_admin_menu(void)
{
    clear_screen();
    printf("ADMIN MENU:\n");
    printf("-----------------\n");
    printf("1. input stock\n");
    printf("2. view stock\n");
    printf("3. view history\n");
    printf("9. back\n");
}
