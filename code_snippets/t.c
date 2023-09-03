#include <stdio.h>

void yes_sir(){
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

void basic_int(){
    int a;
    printf( "%i", a );
}

void raw_yes_sir(){
    unsigned char a[] = {'y', 'e', 's'};
    fwrite(a, 1, sizeof(a), stdout);
}

int main() {
    // yes_sir();
    raw_yes_sir();
    // basic_int();
}
