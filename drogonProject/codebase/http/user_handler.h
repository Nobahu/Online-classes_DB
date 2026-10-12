/// @brief Файл содержит объявление обработчиков для работы с user_data
///
///

#pragma once

#include <drogon/HttpController.h>

namespace http
{

/// @brief Обработчик метода получения данных о пользователе
class GetUser : public drogon::HttpController< GetUser >
{
public:

    METHOD_LIST_BEGIN
    ADD_METHOD_TO( GetUser::operator(), "/logic/GetUser/{1}", drogon::Get );
    METHOD_LIST_END

    void operator()(const drogon::HttpRequestPtr& request,
                     std::function<void (const drogon::HttpResponsePtr &)> &&callback,
                     uint16_t userId) const;

};

/// @brief Обработчик метода добавления данных о пользователе
class SetUser : public drogon::HttpController< SetUser >
{
public:

    METHOD_LIST_BEGIN
    ADD_METHOD_TO( SetUser::operator(), "/logic/SetUser", drogon::Post );
    METHOD_LIST_END

    void operator()(const drogon::HttpRequestPtr& request,
        std::function<void (const drogon::HttpResponsePtr &)> &&callback ) const;
};

} // namespace http