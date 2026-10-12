CREATE TABLE IF NOT EXISTS user_data (
        id  SERIAL PRIMARY KEY,
        email VARCHAR NOT NULL UNIQUE,
        password VARCHAR NOT NULL,
        role INTEGER NOT NULL
)