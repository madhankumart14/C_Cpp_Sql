#include "db_core.h"
#include <stdio.h>
#include <sqlite3.h>

int execute_raw_sql(const char* db_name, const char* sql_statement) {
    sqlite3* db;
    char* err_msg = 0;
    
    int rc = sqlite3_open(db_name, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    rc = sqlite3_exec(db, sql_statement, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    
    sqlite3_close(db);
    return 0;
}
