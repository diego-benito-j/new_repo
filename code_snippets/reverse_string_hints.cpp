#include <algorithm>
#include <iostream>
#include <string>
                                        // missing something

using namespace std; 

string reverse( string & input_seq );    // <-- function overloading with std::reverse 

int main(){
    string seq; 
    string reversed_seq; 

    cout << "Input DNA seq\n" ;
    cin >> seq;
    //seq = "AAAAAAAA";
    reversed_seq = reverse( seq );
    cout << "The reverse complemnt is " << reversed_seq << endl     // <-- missing something

}

string reverse( string input_seq ) { 		// <-- pass by ref or pass by value? 
    map< char , char > complement;
    
    complement[ "A" ] = "T";    //  <-- map should be from char to char
    complement[ "T" ] = "A";    //  <-- map should be from char to char
    complement[ "C" ] = "G";    //  <-- map should be from char to char
    complement[ "G" ] = "C";    //  <-- map should be from char to char

    string reverseStr;
    
    for (int i = 0, i < input_seq.length(), i++){       // <-- incorrect separator for `init` `condition` `increment`
        reverseStr += complement[ input_seq[ i ] ];
    }
    
    reverse( reverseStr.begin(), reverseStr.end() ); 

    return( reverseStr ); 
}
