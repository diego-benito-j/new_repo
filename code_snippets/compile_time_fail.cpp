#include <iostream>

int main() {
    char myChar = "a";  // Fails at compile-time
    
    std::cout << myChar << std::endl;

    return 0;
}

