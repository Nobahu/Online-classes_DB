/// @brief Файл содержит реализацию обработчиков для работы с user_data
///
///

#include <drogonProject/codebase/logic/user_handler.h>
#include <drogon/drogon.h>

namespace logic
{

std::optional< entities::User > GetUser::operator()( uint16_t userId ) const try
{
    auto db = drogon::app().getDbClient();

    auto sqlQuery = db->execSqlSync(
            "SELECT id, email, password, role FROM user_data WHERE id = $1;",
            static_cast< int >( userId ) );

    if( sqlQuery.empty() )
    {
        return std::nullopt;
    }

    auto row = sqlQuery[ 0 ];
    std::string userPassword = row["password"].as<std::string>();

    entities::User user{
        .id_ = row["id"].as<uint16_t>(),
        .newUser_ {
            .email_ = row["email"].as<std::string>(),
            .password_ = std::vector<uint8_t>(userPassword.begin(), userPassword.end()),
            .role_ = static_cast<entities::UserRole>(row["role"].as<int>())
        }
    };

    return user;
}
catch ( ... )
{
    throw;
}

void SetUser::operator()( const entities::NewUser& user ) const try
{
    auto db = drogon::app().getDbClient();

    std::string password( user.password_.begin(), user.password_.end() );
    auto result = db->execSqlSync(
        "INSERT INTO user_data (email, password, role) VALUES ( $1, $2, $3 ); ",
        user.email_, password, static_cast< int >( user.role_ )
    );
}
catch( ... )
{
    throw;
}

} // namespace logic