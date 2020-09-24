#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "db.h"

// open database and do error checking
static int open_database(sqlite3 *db) {
    int rc = sqlite3_open("database.db", &db);
    if (rc) {
        fprintf(stderr, "error opening database: %s\n", sqlite3_errmsg(db));
        exit(1);
    }
    return rc;
}

// used in sqlite3_exec func
static int callback(int argc, char **argv, char **azColName) {
   for(int i = 0; i < argc; i++) {
     printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");
   return 0;
}

// insert row into products table of database
void db_insert_products(
    sqlite3 *db, char *name, char *category, int price, int stock) {
    int rc = open_database(db);

    char sql[128];
    char *err_msg;

    sprintf(sql,
        "insert into products (name, category, price, stock) \
        values ('%s', '%s', %d, %d);",
        name, category, price, stock);

    // execute sql command to db
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    // close connection
    sqlite3_close(db);
}

// delete record in products table where name = name
void db_delete_products(sqlite3 *db, char *name) {
    int rc = open_database(db);

    char sql[64];
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

// return string containing all columns of record from products table
// where name = name. returns null if name not in table
char *db_select_products(sqlite3 *db, char *name) {
    int rc = open_database(db);
    sqlite3_stmt* stmt = 0;
    char *result = NULL;

    char sql[128];
    sprintf(sql,
            "select name, category, price, stock \
            from products where name = '%s'", name);

    // convert sql text to prepared statement object and returns a pointer
    // to it. the sqlite3_step runs the object code to get result
    // full explanation at https://sqlite.org/cintro.html
    rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    } else {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // get size of result str
            ssize_t needed = snprintf(
                NULL, 0, "%s %s %s %s",
                sqlite3_column_text(stmt, 0),
                sqlite3_column_text(stmt, 1),
                sqlite3_column_text(stmt, 2),
                sqlite3_column_text(stmt, 3)
            );

            result = malloc(needed + 1);
            sprintf(result,
                "%s %s %s %s",
                sqlite3_column_text(stmt, 0),
                sqlite3_column_text(stmt, 1),
                sqlite3_column_text(stmt, 2),
                sqlite3_column_text(stmt, 3));
        }
    }

    sqlite3_close(db);
    return result;
}

void db_update_products(sqlite3 *db, char *name, int add){
    int rc = open_database(db);

    char sql[64];
    char *err_msg;

    sprintf(sql, "update products set stock = stock + %d where name = %s;", add, name);

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error : %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        fprintf(stdout, "Records updated successfully\n");
    }

    sqlite3_close(db);
}