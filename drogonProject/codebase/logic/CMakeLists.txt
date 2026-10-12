project( logic )

add_library( logic STATIC
        src/user_handler.cpp
)

target_include_directories( logic PUBLIC
        ${CMAKE_SOURCE_DIR}/..
)

target_link_libraries( logic PUBLIC
        entities
        Drogon::Drogon
)