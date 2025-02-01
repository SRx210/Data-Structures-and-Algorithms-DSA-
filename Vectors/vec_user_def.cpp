#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, element;
    vector<int> vec;

    cout << "Enter size of vector: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> element;
        vec.push_back(element);
    }

    for(int i : vec)
    {
        cout << i << "\t";
    }

    return 0;
}
