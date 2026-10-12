CREATE TABLE IF NOT EXISTS lessons (
        id SERIAL PRIMARY KEY,
        name VARCHAR NOT NULL UNIQUE,
        course_id INTEGER NOT NULL,
        http_link VARCHAR NOT NULL UNIQUE,
        lesson_duration INTEGER
)