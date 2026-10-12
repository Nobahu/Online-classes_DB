CREATE TABLE IF NOT EXISTS user_data (
                                        id  SERIAL PRIMARY KEY,
                                        email VARCHAR NOT NULL UNIQUE,
                                        password VARCHAR NOT NULL,
                                        role INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS course_data (
                                       id SERIAL PRIMARY KEY,
                                       name VARCHAR NOT NULL UNIQUE,
                                       teacher_id INTEGER NOT NULL,
                                       price INTEGER,
                                       description VARCHAR
);

CREATE TABLE IF NOT EXISTS lessons (
                                       id SERIAL PRIMARY KEY,
                                       name VARCHAR NOT NULL UNIQUE,
                                       course_id INTEGER NOT NULL,
                                       http_link VARCHAR NOT NULL UNIQUE,
                                       lesson_duration INTEGER
)