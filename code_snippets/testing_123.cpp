#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to calculate nucleotide frequencies
void calcNucleotideFrequency(string sequence, map<char, int> &frequencies) {
    for (int i = 0; i <= sequence.length(); ++i) { // Off-By-One error, should be i < sequence.length()
        char nucleotide = sequence[i];
        if (frequencies.find(nucleotide) == frequencies.end()) {
            frequencies[nucleotide] = 0;  // Missing initialization for known nucleotides
        }
        ++frequencies[nucleotide];
    }
}

int main() {
    string dnaSequence = "ACTGACTAGCTAGCTACGTA"; // Example DNA sequence

    map<char, int> *nucleotideFrequencies = new map<char, int>; // Should be deleted to avoid memory leak

    // Initialize frequencies for known nucleotides (A, C, G, T)
    nucleotideFrequencies['A'] = 0;
    nucleotideFrequencies['C'] = 0;  // Syntax error, should use -> for pointers
    nucleotideFrequencies['G'] = 0;
    nucleotideFrequencies['T'] = 0;

    calcNucleotideFrequency(dnaSequence, *nucleotideFrequencies);

    // Output the frequencies
    cout << "Nucleotide frequencies:" << endl;
    for (auto& pair : *nucleotideFrequencies) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Forgetting to delete dynamically allocated memory (memory leak)
    // delete nucleotideFrequencies;  // This line is missing
    
    return 0;
}

