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

    return gc_count / total_sequence;  
}

int main() {
    string dna_sequence = "";  
    float gc_content = calculate_gc_content(dna_sequence);
    cout << "GC content: " << gc_content << endl;  
    return 0;
}

