#include<iostream>
#define MAX 10
using namespace std;

int main()
{
    int arr[7] = {4, 2, 7, 8, 1, 2, 5};
    int start = 0;
    int endd = 6;

    while(start != endd && start < endd)
    {
        swap(arr[start], arr[endd]);
        start++;
        endd--;
    }

    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] << "\t";
    }
}
