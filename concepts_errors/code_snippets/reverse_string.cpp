#include <algorithm>
#include <iostream>
#include <string>

using namespace std; 

string reverse( string & input_seq );    

int main(){
    string seq; 
    string reversed_seq; 

    cout << "Input DNA seq\n" ;
    cin >> seq;
    //seq = "AAAAAAAA";
    reversed_seq = reverse( seq );
    cout << "The reverse complemnt is \"" << reversed_seq << "\""     

}

string reverse( string input_seq ) { 		
    map< char , char > complement;
    
    complement[ "A" ] = "T";    
    complement[ "T" ] = "A";    
    complement[ "C" ] = "G";    
    complement[ "G" ] = "C";    

    string reverseStr;
    
    for (int i = 0, i < input_seq.length(), i++){       
        reverseStr += complement[ input_seq[ i ] ];
    }
    
    reverse( reverseStr.begin(), reverseStr.end() ); 

    return( reverseStr ); 
}
