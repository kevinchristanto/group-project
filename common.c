#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "common.h"

void clear_screen(void)
{
    system("clear");
}

char *get_input(char *prompt)
{
    printf("%s", prompt);
    char *input = malloc(32);
    fgets(input, 32, stdin);
    int len = strlen(input);
    input[len - 1] = '\0';
    return input;
}
