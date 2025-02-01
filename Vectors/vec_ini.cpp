#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec1; //initializes a vector with data type 'int' with name 'vec1' with no values;
    vector<int> vec2 = {1, 2, 3, 4, 5}; //initializes a vector with data type 'int' with name 'vec2' with values;
    vector<int> vec3 (5, 0); //initializes a vector with data type 'int' with name 'vec3' with size 5 and the index values hold '0' value as mentioned;

    //To access a vector we make use of for each loop
    for(int i : vec2) // here 'i' is the iterator which will hold value and not the index number
    {
        cout << i << "\t";
    }

    return 0;

}
