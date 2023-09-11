#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Attempting to access an element out of bounds
    std::cout << "Accessing out-of-bounds element: " << myVector[10] << std::endl;

    return 0;
}
