/// @brief Файл содержит модели для работы с user_data
///
///

#include <drogonProject/codebase/entities/user.h>

namespace entities
{

static std::string RoleToString(const UserRole& role)
{
    switch (role) {
        case UserRole::Administrator: return "administrator";
        case UserRole::Teacher: return "teacher";
        case UserRole::User:   return "user";
    }
    return "unknown";
}

static UserRole StringToRole(const std::string& role)
{

    if( role == "administrator" )
    {
        return UserRole::Administrator;
    }
    if( role == "teacher" )
    {
        return UserRole::Teacher;
    }
    if( role == "user" )
    {
        return UserRole::User;
    }
    throw std::runtime_error( "Invalid role" );
}

void ReadJson( const Json::Value& jsonValue, NewUser& value )
{
    if( jsonValue.isMember( "email" ) && jsonValue[ "email" ].isString() )
    {
        value.email_ = jsonValue[ "email" ].asString();
    }
    if( jsonValue.isMember( "password" ) && jsonValue[ "password" ].isString() )
    {
        std::string passStr = jsonValue[ "password" ].asString();
        value.password_ = std::vector<uint8_t>( passStr.begin(), passStr.end() );
    }
    if ( jsonValue.isMember( "role" ) && jsonValue[ "role" ].isInt() )
    {
        value.role_ = static_cast< UserRole >( jsonValue[ "role" ].asInt() );
    }
}
void WriteJson( const NewUser& value, Json::Value& jsonValue )
{
    jsonValue[ "email" ] = value.email_;
    jsonValue[ "password" ] = std::string( value.password_.begin(), value.password_.end() );
    jsonValue[ "role" ] = RoleToString( value.role_ );
}

void ReadJson( const Json::Value& jsonValue, User& value )
{
    if( jsonValue.isMember( "id" ) && jsonValue[ "id" ].isInt() )
    {
        value.id_ = jsonValue[ "id" ].asInt();
    }
    ReadJson( jsonValue, value.newUser_ );
}
void WriteJson( const User& value, Json::Value& jsonValue )
{
    jsonValue[ "id" ] = value.id_;
    WriteJson( value.newUser_, jsonValue );
}

} // namespace entities