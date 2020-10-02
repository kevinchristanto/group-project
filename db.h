#ifndef DATABASE_H
#define DATABASE_H

// database schema
// (column name) (data type)
//
// products table     |   users table            |   sales table
// * id integer       |   * id integer           |   * id integer
// * name text        |   * name text            |   * user_id integer
// * category text    |   * email text           |   * product_id integer
// * int price        |   * phone_number text    |   * date_time text
// * int stock        |   * password text        |   * quantity integer   
//                    |   * balance integer      |

// insert record into products table 
void db_insert_products(
    sqlite3 *db, char *name, char *category, int price, int stock);

// delete record in products table by 'name' variable which is passed as
// an argument to this function
void db_delete_products(sqlite3 *db, char *name);

// selects record from products table by name and returns a string in
// the format "{name} {category} {price} {stock}". returns null if product
// is not found.
char *db_select_products(sqlite3 *db, char *name);

// increase stock of product in products table by 'add' variable passed as
// argument to this function
void db_update_inc_products(sqlite3 *db, char *name, int add);

// same as the db_update_inc_products, but instead of increasing stock,
// decreases it
void db_update_dec_products(sqlite3 *db, char *name, int dec);

// select record from products table by category, returns all rows that
// match as a string array in the format "{name} {price} {stock}".
char **db_select_products_by_category(sqlite3 *db, char *category);

#endif
