#ifndef DATABASE_H
#define DATABASE_H

void db_insert_products(
    sqlite3 *db, char *name, char *category, int price, int stock);
void db_delete_products(sqlite3 *db, char *name);
char *db_select_products(sqlite3 *db, char *name);
void db_update_inc_products(sqlite3 *db, char *name, int add);
void db_update_dec_products(sqlite3 *db, char *name, int dec);

#endif
