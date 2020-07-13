
add_custom_target( create_db
    COMMAND sqlite3  ${CMAKE_CURRENT_BINARY_DIR}/pompeph.db < ${CMAKE_SOURCE_DIR}/sql/CreatePompeph.sql
    COMMENT "Created ${CMAKE_CURRENT_BINARY_DIR}/pompeph.db"
)
