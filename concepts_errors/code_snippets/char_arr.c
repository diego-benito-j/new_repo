#include <stdio.h>

int main() {
    char j[2] = "jjj" ;

        printf( j );
        printf("\n");

        for ( int i = 0; i < 6; i++ ){
            printf( "%i \n", j[i] );
        }
        printf("\n");

    char b[3] = "bbb";

        printf( b );
        printf("\n");

        for ( int i = 0; i < 6; i++ ){
            printf( "%i\n", j[i] );
        }
        printf("\n");

    j[3] = 'j'; // <-- THIS SHOULD NOT BE MODIFYING B
        
        printf( b );
        printf("\n");
        printf( j );
        printf("\n");

        for ( int i = 0; i < 6; i++ ){
            printf( "%i\n", j[i] );
        }
        printf("\n");
}
