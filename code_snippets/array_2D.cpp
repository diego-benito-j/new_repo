#include <iostream>

using namespace std;

int main(){
    int two_d_array[3][5] = {{1, 2, 3, 4, 5}, {2, 2, 3, 4, 5}, {1, 2, 3, 4, 5} };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << two_d_array[i, j] << endl;
        }
    }

    return 0;
}
