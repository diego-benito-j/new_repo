#include <iostream>

using namespace std;

int main() {
    int distance1 = 1;
    int distance2 = 100;
    float ratio;

    // Incorrect calculation: integer division truncates result to zero
    ratio = distance1 / distance2;
    cout << "Incorrect ratio: " << ratio << endl;       // <-- prints 0

    // Correct calculation: type casting before division
    ratio = (float) distance1  / distance2;
    cout << "Correct ratio: " << ratio << endl;         // <-- print 0.01

    return 0;
}
