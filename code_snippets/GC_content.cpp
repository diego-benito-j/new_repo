#include <iostream>
#include <string>

using namespace std;

float calculate_gc_content(string& sequence) {
    int gc_count = 0;
    int total_sequence = 0;

    for ( int i = 0; i < sequence.length(); i++) {
        if (sequence[i] == 'G' || sequence[i] == 'C') {
            gc_count++;
        }

        if (sequence[i] == 'G' || sequence[i] == 'C' || sequence[i] == 'A' || sequence[i] == 'T') {
            total_sequence++;
        }
    }

    // G's and C's present, prevent truncation by casting as float
    if (gc_count != 0) {
        return (float) gc_count / total_sequence; 
    }
    
    // G's and C's not present (gc_count = 0), no need to prevent truncation
    return gc_count / total_sequence;
}


int main() {
    string dna_sequence = "AATGCGGG";
    float gc_content = calculate_gc_content(dna_sequence);
    cout << "GC content: " << gc_content << endl;
    return 0;
}
