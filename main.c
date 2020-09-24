#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "login.c"

struct data
{
    int qty;
    int code;
    double price;
    char item_name[10000];
};
struct itemDatabase
{
    struct data item[10000];
    int index;
};

char *get_input()
{
    char *input = malloc(32);
    fgets(input, 32, stdin);
    return input;
}
/*
void add_item(struct itemDatabase *db)
{
    clear_screen();
    printf("Adding new items:\n");
    printf("------------------\n");
    printf("enter item code:\n");
    scanf("%d", &db->item[db->index].code);
    printf("enter item quantity:\n");
    scanf("%d", &db->item[db->index].qty);
    printf("enter item price:\n");
    scanf("%lf", &db->item[db->index].price);
    printf("enter item name:\n");
    scanf("%[^\n]*s", db->item[db->index].item_name);
    db->index++;
}

void view_stock(struct itemDatabase *db)
{
    clear_screen();
    printf("View stock\n");
    printf("------------------------------------------\n");
    printf("| code |      name      |  price |  qty  |\n");
    printf("------------------------------------------\n");
    if (db->index == 0)
    {
        printf("------------------------------------------\n");
        printf("           Inventory is empty!            \n");
        printf("------------------------------------------\n");
    }
    else
    {
        for (int i = 0; i < db->index; i++)
        {
            printf("|%6d|%16s|%8lf|%7d|\n", db->item[i].code, db->item[i].item_name, db->item[i].price, db->item[i].qty);
            i++;
        }
        printf("------------------------------------------\n");
    }
}*/

int main() //MAIN
{
    while (1)
    {
        main_menu();
        char *opt = get_input();
        switch (opt[0])
        {
        case '1':
            admin_menu();
            break;
        case '2':
            buyer_menu();
            break;
        default:
            printf("Enter valid choice!\n");
            break;
        }
        free(opt);
    }
    return 0;
}