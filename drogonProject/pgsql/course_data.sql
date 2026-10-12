CREATE TABLE IF NOT EXISTS course_data (
        id SERIAL PRIMARY KEY,
        name VARCHAR NOT NULL UNIQUE,
        teacher_id INTEGER NOT NULL,
        price INTEGER,
        description VARCHAR
)