#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "db_core.h"

// Helper function to read .sql files into strings
std::string read_sql_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open SQL file: " + file_path);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    const std::string db_name = "app_data.db";
    const std::string schema_file = "schema.sql";
    
    std::cout << "--- Initializing Application Database ---" << std::endl;
    
    try {
        // Read script from the SQL file
        std::string sql_script = read_sql_file(schema_file);
        
        // Call low-level C function to run schema deployment
        int result = execute_raw_sql(db_name.c_str(), sql_script.c_str());
        
        if (result == 0) {
            std::cout << "Database synchronized successfully with C/C++/SQL layers!" << std::endl;
        } else {
            std::cerr << "Database synchronization failed." << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
