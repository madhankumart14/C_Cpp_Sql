-- Create users table
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    email TEXT NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Seed initial records
INSERT OR IGNORE INTO users (username, email) VALUES ('alice_dev', 'alice@example.com');
INSERT OR IGNORE INTO users (username, email) VALUES ('bob_coder', 'bob@example.com');
