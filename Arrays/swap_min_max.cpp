//WAF to swap the min and max number of array
#include<iostream>
#define MAX 10
using namespace std;

int main()
{
    int n, minn, maxx, min_idx, max_idx;
    int arr[MAX];

    cout << "Enter size of array: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }

    cout << "Before Swapping" << endl;
    cout << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    maxx = arr[0];
    minn = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(maxx < arr[i])
        {
            maxx = arr[i];
            max_idx = i;
        }
        else if(minn > arr[i])
        {
            minn = arr[i];
            min_idx = i;
        }
    }
    swap(arr[max_idx], arr[min_idx]);

    cout << "\nAfter Swapping" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;



}
