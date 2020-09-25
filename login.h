#ifndef LOGIN_H
#define LOGIN_H

// menu used to login, returns LoginResult enum as int
int main_menu(void);

// prints menu for main_menu function
void print_main_menu(void);

// login screen for admins, returns LoginResult enum from menu.h
int admin_log_in(void);

// login screen for buyers, returns LoginResult enum from menu.h
int buyer_log_in(void);

#endif
