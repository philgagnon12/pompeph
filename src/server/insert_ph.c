#include "sqlite3.h"

#include "stdio.h"
#include "string.h"
#include "time.h"


int main( void )
{

    sqlite3* db;
    char* insert_ph_history_format = "INSERT INTO PhHistory ( level, timestamp ) VALUES ( 6.0, %ld );";
    char  insert_ph_history[ 0x0100 ];

    sqlite3_open("pompeph.db", &db );

    if( db == NULL )
    {
        fprintf( stderr, "failed to open pompeph.db\n" );
        return 1;
    }

    memset( insert_ph_history,
            0x00,
            sizeof( insert_ph_history ) );

    snprintf( insert_ph_history,
              sizeof( insert_ph_history ),
              insert_ph_history_format,
              time( NULL ) );

    if( 0 != sqlite3_exec( db,
                           insert_ph_history,
                           NULL,
                           NULL,
                           NULL ) )
    {
        fprintf( stderr, "sqlite3_exec failed!\n" );
        return 1;
    }


    printf("%s\n", insert_ph_history );


    if( 0 != sqlite3_close( db ) )
    {
        fprintf( stderr, "sqlite3_close failed!\n" );
        return 1;
    }

    printf("done\n");
    return 0;
}
