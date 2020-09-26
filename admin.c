#include <stdio.h>
#include "admin.h"
#include "common.h"

void admin_menu(void)
{
    while (1)
    {
        print_admin_menu();
        // TODO: implement logic
    }
}

void print_admin_menu(void)
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

