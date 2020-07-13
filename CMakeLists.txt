cmake_minimum_required( VERSION 3.16 )

project( pompeph )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake )

include( FindSQLite3 )
execute_process( COMMAND sqlite3 --version
    COMMENT "sqlite3 version"
)

add_subdirectory( src/interface_client )
add_subdirectory( src/server )

