#ifndef DATABASE_H
#define DATABASE_H

void db_insert_products(
    sqlite3 *db, char *name, char *category, int price, int stock);
void db_delete_products(sqlite3 *db, char *name);
void db_print_all(sqlite3 **db);

#endif
