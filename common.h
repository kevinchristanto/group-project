#ifndef COMMON_H
#define COMMON_H

enum LoginResult {ADMIN, BUYER, EXIT, MAX_TRIES};

// name change for system("clear")
void clear_screen(void);

// print prompt and get input from user, returns input string
char *get_input(char *prompt);

#endif
