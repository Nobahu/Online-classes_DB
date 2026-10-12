project( http )

add_library( http OBJECT
        src/user_handler.cpp
)

target_include_directories( http PUBLIC
        ${CMAKE_SOURCE_DIR}/..
)

target_link_libraries( http PUBLIC
        logic
        entities
        Drogon::Drogon
)