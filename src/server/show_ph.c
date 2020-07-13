#include "sqlite3.h"

#include "stdio.h"
#include "string.h"
#include "time.h"

int main( void )
{

    sqlite3* db;
    char* select_ph_history_format          = "SELECT * FROM PhHistory;";
    sqlite3_stmt* select_ph_history_stmt    = NULL;


    int     id          = 0;
    double  level       = 0.0;
    time_t  timestamp   = 0;

    char    timestamp_buffer[ 0x0100 ];

    sqlite3_open("pompeph.db", &db );

    if( db == NULL )
    {
        fprintf( stderr, "failed to open pompeph.db\n" );
        return 1;
    }


    if( 0 != sqlite3_prepare( db,
                              select_ph_history_format,
                              strnlen( select_ph_history_format, 0x0100 ),
                              &select_ph_history_stmt,
                              NULL ) )
    {
        fprintf( stderr, "sqlite3_prepare failed!\n" );
        return 1;
    }

    while( SQLITE_DONE != sqlite3_step( select_ph_history_stmt ) )
    {
        id          = sqlite3_column_int( select_ph_history_stmt, 0 );
        level       = sqlite3_column_double( select_ph_history_stmt, 1 );
        timestamp   = sqlite3_column_int( select_ph_history_stmt, 2 );

        memset( timestamp_buffer,
                0x00,
                sizeof( timestamp_buffer ) );

        strftime( timestamp_buffer,
                  sizeof( timestamp_buffer ),
                  "%Y-%m-%d %H:%M:%S",
                  localtime( &timestamp ) );

        printf("id %d, level %f, timestamp %s\n", id, level, timestamp_buffer );

    }

    if( 0 != sqlite3_finalize( select_ph_history_stmt ) )
    {
        fprintf( stderr, "sqlite3_finalize failed!\n" );
        return 1;
    }

    if( 0 != sqlite3_close( db ) )
    {
        fprintf( stderr, "sqlite3_close failed!\n" );
        return 1;
    }

    printf("done\n");
    return 0;
}
