#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "db.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   for(int i = 0; i < argc; i++) {
     printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");
   return 0;
}


void db_insert_products(
    sqlite3 *db, char *name, char *category, int price, int stock) {

    int rc = sqlite3_open("database.db", &db);

    char sql[128];
    char *err_msg;

    sprintf(sql,
        "insert into products (name, category, price, stock) \
        values ('%s', '%s', %d, %d);",
        name, category, price, stock);

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    sqlite3_close(db);
}

void db_delete_products(sqlite3 *db, char *name) {
    int rc = sqlite3_open("database.db", &db);

    char sql[128];
    char *err_msg;

    sprintf(sql, "delete from products where name = '%s';", name);

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    sqlite3_close(db);

}






