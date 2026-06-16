#ifndef DB_CORE_H
#define DB_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

// Executes raw SQL strings against an SQLite database file
int execute_raw_sql(const char* db_name, const char* sql_statement);

#ifdef __cplusplus
}
#endif

#endif // DB_CORE_H
