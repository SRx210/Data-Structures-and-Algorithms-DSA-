//WAF to print unique values in array
#include<iostream>
#define MAX 10
using namespace std;

int main()
{
    int n, i = 0, j = 1;
    int arr[MAX];

    cout << "Enter size of array: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }

    cout << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << "\n";
    for(int i = 0; i < n ; i++)
    {
        bool isUnique = true;
        for(int j = 0; j < n; j++)
        {
            if(i != j && arr[i] == arr[j])
            {
                isUnique = false;
                break;
            }
        }
        if(isUnique)
        cout << arr[i] << "\t";
    }

    return 0;
}
