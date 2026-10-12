/// @brief Файл содержит объявление обработчиков для работы с user_data
///
///

#pragma once

#include <drogonProject/codebase/entities/user.h>
#include <optional>
#include <drogon/HttpRequest.h>

namespace logic
{

/// @brief Обработчик метода получения данных о пользователе
class GetUser
{
public:

    /// @brief Конструктор по умолчанию
    explicit GetUser() = default;

    /// @brief Получить данные о пользователе
    /// @param userId Идентификатор пользователя
    /// @return Данные о пользователе, если они есть. nullopt - если нет
    std::optional< entities::User > operator()( uint16_t userId ) const;

};

/// @brief Обработчик метода добавления данных о пользователе
class SetUser
{
public:

    /// @brief Конструктор по умолчанию
    explicit SetUser() = default;

    /// @brief Добавить данные о пользователе
    /// @param user Данные о пользователе
    void operator()( const entities::NewUser& user ) const;

};

/// @brief Обработчик метода добавления данных о пользователе
class DeleteUser
{
public:

    /// @brief Конструктор по умолчанию
    explicit DeleteUser() = default;

    /// @brief Удалить данные о пользователе
    /// @param userId Идентификатор пользователя
    void operator()( const uint16_t userId ) const;
};

} // namespace logic
