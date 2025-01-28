#include<iostream>
#define MAX 10
using namespace std;

int main()
{
    int n, j = 0;
    int arr[MAX], temp[MAX];

    cout << "Enter size of array: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }

    for(int i = n-1; i >= 0; i--)
    {
        temp[j++] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << temp[i] << "\t";
    }
}
