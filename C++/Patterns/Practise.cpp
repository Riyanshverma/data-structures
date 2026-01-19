#include <iostream>
using namespace std;

// filepath: C++/Patterns/Practise.cpp
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int minDist = min(min(i, j), min(size - 1 - i, size - 1 - j));
            cout << n - minDist << " ";
        }
        cout << endl;
    }
    return 0;
}