# C_Cpp_Sql
Sample Application Code with C Cpp Sql

This application showcases how to connect a modern C++ application layer to a SQLite backend database via a native structural C driver layer.

## Requirements
* GCC / G++ compiler
* SQLite3 development libraries (`libsqlite3-dev`)

## Compiling & Running (Linux/macOS)
```bash
# Compile the C and C++ components together, linking sqlite3
g++ -o sample_app app_logic.cpp db_core.c -lsqlite3

# Execute the binary
./sample_app
```
