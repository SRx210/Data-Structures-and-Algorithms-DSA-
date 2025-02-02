// Write a C++ program to capitalize the first character of each element of a given string vector. Return the new vector.
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    vector<string> colors = {"red", "green", "black", "white", "Pink"};

    for(int i = 0; i < colors.size(); i++)
    {
        for(int j = 0; j < colors[i].size(); j++)
        {
            if(j == 0)
            {
                colors[i][j] = toupper(colors[i][j]); // first letter of each string
            }
            else
            {
                colors[i][j] = tolower(colors[i][j]);
            }
        }
    }

    for(string i : colors)
    {
        cout << i << " ";
    }
}
