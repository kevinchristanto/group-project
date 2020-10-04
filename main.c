#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "login.h"
#include "admin.h"
#include "buyer.h"

int main()
{
    while (1)
    {
        int login_result = main_menu();
        switch (login_result)
        {
        case ADMIN:
            admin_menu();
            break;
        case BUYER:
            buyer_menu();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
