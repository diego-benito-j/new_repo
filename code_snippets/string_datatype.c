#include <stdio.h>

int main() {
    char a[] = "yes";
    int  b[] = {121, 101, 115};
    
    for ( int i = 0; i < 4; i++ ){
        printf( "char a: %c\n", a[i] );
        printf( "char b: %c\n", b[i] );

        printf( "int a: %i\n", a[i] );
        printf( "int b: %i\n", b[i] );
        
        printf("\n");

    }
}

