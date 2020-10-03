#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "db.h"

// used in sqlite3_exec func
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

    // execute sql command to db
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Record created successfully\n");
    }

    // close connection
    sqlite3_close(db);
}

void db_delete_products(sqlite3 *db, char *name) {
    int rc = sqlite3_open("database.db", &db);

    char sql[64];
    char *err_msg;

    sprintf(sql, "delete from products where name = '%s';", name);

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Record deleted successfully\n");
    }

    sqlite3_close(db);
}

char *db_select_products(sqlite3 *db, char *name) {
    int rc = sqlite3_open("database.db", &db);

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

void db_update_inc_products(sqlite3 *db, char *name, int add) {
    int rc = sqlite3_open("database.db", &db);

    char sql[64];
    char *err_msg;

    sprintf(sql, "update products set stock = stock + %d where name = '%s';",
            add, name);

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error : %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        fprintf(stdout, "Record updated successfully\n");
    }

    sqlite3_close(db);
}

void db_update_dec_products(sqlite3 *db, char *name, int dec) {
    int rc = sqlite3_open("database.db", &db);

    char sql[64];
    char *err_msg;

    sprintf(sql, "update products set stock = stock - %d where name = '%s';",
            dec, name);

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error : %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        fprintf(stdout, "Record updated successfully\n");
    }

    sqlite3_close(db);
}

char **db_select_products_by_category(sqlite3 *db, char *category) {
    int rc = sqlite3_open("database.db", &db);

    sqlite3_stmt* stmt = 0;

    char sql[128];
    sprintf(sql,
            "select name, price, stock \
            from products where category = '%s'", category);

    rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    } else {
        // get number of rows
        int n_rows = 0;
        while (sqlite3_step(stmt) == SQLITE_ROW) n_rows++;

        // initialize string array with n_rows elements
        char **result_list = malloc((n_rows + 1) * sizeof(char *));
        int i = 0;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // get size of result str
            ssize_t needed = snprintf(
                NULL, 0, "%s %s %s",
                sqlite3_column_text(stmt, 0),
                sqlite3_column_text(stmt, 1),
                sqlite3_column_text(stmt, 2)
            ) + 1;

            char *result = malloc(needed);
            sprintf(result,
                "%s %s %s",
                sqlite3_column_text(stmt, 0),
                sqlite3_column_text(stmt, 1),
                sqlite3_column_text(stmt, 2));
            result[needed - 1] = '\0';

            // insert record string into string array
            result_list[i] = malloc(needed);
            strcpy(result_list[i++], result);
        }

        sqlite3_close(db);
        return result_list;
    }

    sqlite3_close(db);
    return NULL;
}

char *db_select_user(sqlite3 *db, char *email, char *phone) {
    int rc = sqlite3_open("database.db", &db);

    sqlite3_stmt* stmt = 0;
    char *result = NULL;

    char sql[128];
    if (phone == NULL) {
        sprintf(sql,
                "select name, balance \
                from users where email = '%s'", email);
    } else {
        sprintf(sql,
                "select name, balance \
                from users where phone_number = '%s'", phone);
    }

    rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    } else {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // get size of result str
            ssize_t needed = snprintf(
                NULL, 0, "%s %s",
                sqlite3_column_text(stmt, 0),
                sqlite3_column_text(stmt, 1)
            );

            result = malloc(needed + 1);
            sprintf(result,
                "%s %s",
                sqlite3_column_text(stmt, 0),
                sqlite3_column_text(stmt, 1));
        }
    }

    sqlite3_close(db);
    return result;
}

void db_update_inc_balance(sqlite3 *db, char *email, char *phone, int add) {
    int rc = sqlite3_open("database.db", &db);

    char sql[256];
    char *err_msg;

    if (phone == NULL) {
        sprintf(sql, "update users \
                set balance = balance + %d where email = '%s';",
                add, email);
    } else {
        sprintf(sql, "update users \
                set balance = balance + %d where phone_number = '%s';",
                add, phone);
    }

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error : %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        fprintf(stdout, "Record updated successfully\n");
    }

    sqlite3_close(db);
}

void db_update_dec_balance(sqlite3 *db, char *email, char *phone, int dec) {
    int rc = sqlite3_open("database.db", &db);

    char sql[256];
    char *err_msg;

    if (phone == NULL) {
        sprintf(sql, "update users \
                set balance = balance - %d where email = '%s';",
                dec, email);
    } else {
        sprintf(sql, "update users \
                set balance = balance - %d where phone_number = '%s';",
                dec, phone);
    }

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error : %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        fprintf(stdout, "Record updated successfully\n");
    }

    sqlite3_close(db);
}

int db_check_user_in_table(sqlite3 *db, char *email, char *phone) {
    int rc = sqlite3_open("database.db", &db);

    sqlite3_stmt* stmt = 0;
    char *result_str = NULL;

    char sql[128];
    if (phone == NULL) {
        sprintf(sql, "select count(*) from users where email = '%s'", email);
    } else {
        sprintf(
            sql,"select count(*) from users where phone_number = '%s'", phone);
    }

    rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    } else {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            ssize_t needed = snprintf(
                NULL, 0, "%s",
                sqlite3_column_text(stmt, 0));

            result_str = malloc(needed + 1);
            sprintf(result_str, "%s", sqlite3_column_text(stmt, 0));
        }
    }

    sqlite3_close(db);
    int result;
    sscanf(result_str, "%d", &result);

    return result;
}

