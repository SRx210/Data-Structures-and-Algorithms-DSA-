#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<int> v)
{
    for(int i : v)
    {
        cout << i << "\t";
    }
    cout << "\n";
}

int main()
{
    vector<int> vec1 = {2, 4, 6, 8, 10};

    // Size() is used to return the size of the vector
    cout << "Size of the vector = " << vec1.size() << endl;

    // push_back() fn is used to insert element at the rear of the vector
    vec1.push_back(12);
    print_vector(vec1);

    // pop_back() fn is used to delete(pop) the element in last of vector
    vec1.pop_back();
    print_vector(vec1);

    cout << vec1.front() << endl; // Returns the front value of vector
    cout << vec1.back() << endl; // Returns the back value of vector

    //at() is used to access a specific value in a vector
    cout << vec1.at(0);


    return 0;

}
