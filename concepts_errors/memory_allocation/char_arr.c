#include <stdio.h>

int main() {
    char a[2] = "jjj" ;
    for ( int i = 0; i < 6; i++ ){
        printf( "%i\n", a[i] );
    }

    printf("\n");

    char b[3] = "aaa";
    for ( int i = 0; i < 6; i++ ){
        printf( "%i\n", a[i] );
    }
    printf( "%li\n", sizeof(a) );

}
