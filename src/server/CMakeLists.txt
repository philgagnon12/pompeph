
include( CreatePompeph )

add_executable( server server.c )
add_executable( client client.c )

add_executable( insert_ph insert_ph.c )
target_link_libraries( insert_ph SQLite::SQLite3 )

add_executable( show_ph show_ph.c )
target_link_libraries( show_ph SQLite::SQLite3 )

