#include<iostream>
#define MAX 10
using namespace std;

int linear_search(int arr[], int n, int key)
{
    int i = 0;
    while(i < n)
    {
        if(arr[i] == key)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int main()
{
    int n, key, idx;
    int arr[MAX];

    cout << "Enter size of array: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }

    cout << "Enter element to be searched: ";
    cin >> key;

    idx = linear_search(arr, n, key);

    if(idx != -1)
    {
        cout << "Element found at index " << idx << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}
