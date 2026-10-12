#!/bin/bash
set -e

DB_NAME="my_db"
DB_PASSWRD="11111111"
DB_USER="postgres"
DB_HOST="localhost"
DB_PORT="5432"
SQL_DIR="./pgsql"

export PGPASSWORD="$DB_PASSWRD"

echo "Создание БД $DB_NAME"
psql -h $DB_HOST -p $DB_PORT -U $DB_USER -d postgres -c "CREATE DATABASE $DB_NAME;" 2>/dev/null

echo "📦 Выполняем SQL файлы из $SQL_DIR..."

for file in $(ls $SQL_DIR/*.sql | sort -V); do
 psql -h $DB_HOST -p $DB_PORT -U $DB_USER -d $DB_NAME -f "$file"
done

unset PGPASSWORD

echo "БД создана"