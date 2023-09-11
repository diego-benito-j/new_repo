#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Pass-by-value function
void processByValue(vector<int> data) {
                                                        // Nothing is being done!
}

// Pass-by-reference function
void processByReference(vector<int>& data) {
                                                        // Nothing is being done!
}

int main() {
    vector<int> largeData(1e6, 33);  // 1 million integers initialized to 33

    // Timing the pass-by-value function
    auto start = chrono::high_resolution_clock::now();
    processByValue(largeData);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by pass-by-value: " << duration.count() << " microseconds" << endl;


    // Timing the pass-by-reference function
    start = chrono::high_resolution_clock::now();
    processByReference(largeData);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by pass-by-reference: " << duration.count() << " microseconds" << endl;

    return 0;
}

