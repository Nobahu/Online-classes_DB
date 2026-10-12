/// @brief Файл содержит реализацию обработчиков для работы с user_data
///
///

#include <drogonProject/codebase/logic/user_handler.h>
#include <drogonProject/codebase/http/user_handler.h>

namespace http
{

void GetUser::operator()(const drogon::HttpRequestPtr& request,
        std::function<void ( const drogon::HttpResponsePtr &)> &&callback, uint16_t userId ) const try
{
    logic::GetUser handler;
    auto userInfo = handler( userId );

    if( !userInfo.has_value() )
    {
            auto response = drogon::HttpResponse::newHttpResponse();
            response->setStatusCode( drogon::k404NotFound );
            callback( response );
            return;
    }

    Json::Value jsonValue;
    entities::WriteJson( userInfo.value(), jsonValue );

    auto response = drogon::HttpResponse::newHttpJsonResponse( jsonValue );
    response->setStatusCode( drogon::k200OK );
    callback( response );
}
catch( ... )
{
    auto response = drogon::HttpResponse::newHttpResponse();
    response->setStatusCode( drogon::k409Conflict );
    callback( response );
}

void SetUser::operator()(const drogon::HttpRequestPtr& request,
    std::function<void (const drogon::HttpResponsePtr &)> &&callback ) const try
{
    auto json = request->getJsonObject();
    if( !json or json->empty() )
    {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode( drogon::k400BadRequest );
        resp->setBody( "Invalid JSON body" );
        callback( resp );
        return;
    }

    entities::NewUser userInfo;
    entities::ReadJson( *json, userInfo );
    logic::SetUser handler;
    handler( userInfo );

    auto response = drogon::HttpResponse::newHttpJsonResponse( *json );
    response->setStatusCode( drogon::k201Created );
    callback( response );

}
catch( ... )
{
    auto response = drogon::HttpResponse::newHttpResponse();
    response->setStatusCode( drogon::k409Conflict );
    callback( response );
}

} // namespace http
