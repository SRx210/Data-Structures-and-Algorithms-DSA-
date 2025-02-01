//Vector: Single Number Problem
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 4, 6, 1};

    for(int i = 0; i < vec.size(); i++)
    {
        bool isUnique = true;
        for(int j = 0; j < vec.size(); j++)
        {
            if((vec[i] == vec[j]) && i!=j)
            {
                isUnique = false;
                break;
            }
        }
        if(isUnique)
        {
            cout << vec[i] << endl;
        }
    }

    return 0;
}
