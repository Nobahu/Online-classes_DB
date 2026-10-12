/// @brief Файл содержит модели для работы с user_data
///
///

#pragma once

#include <json/json.h>

namespace entities
{

/// @brief Роль пользователя сервиса
enum class UserRole
{
    Administrator = 0,
    Teacher,
    User
};

/// @brief Данные о пользователе
struct NewUser
{
    std::string email_;
    std::vector< uint8_t > password_;
    UserRole role_;
};

void ReadJson( const Json::Value& jsonValue, NewUser& value );
void WriteJson( const NewUser& value, Json::Value& jsonValue );

/// @brief Данные о пользователе с учетом id в БД
struct User
{
    uint16_t id_;
    NewUser newUser_;
};

void ReadJson( const Json::Value& jsonValue, User& value );
void WriteJson( const User& value, Json::Value& jsonValue );

} // namespace entities