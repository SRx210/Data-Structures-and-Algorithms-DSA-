// Write a C++ program that returns the elements in a vector that are strictly smaller than their adjacent left and right neighbours.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 5, 0, 3, 1, 7};

    cout << "Elements smaller than their adjacent neighbors:\n";

    for(int i = 1; i < vec.size() - 1; i++)
    {
        if((vec[i] < vec[i - 1]) && (vec[i] < vec[i + 1]))
        {
            cout << vec[i] << endl;
        }
    }

    return 0;
}
