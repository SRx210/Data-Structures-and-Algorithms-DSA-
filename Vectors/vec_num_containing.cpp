#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> vector_str_nos(const vector<string>& v)
{
    vector<string> res;
    for (int i = 0; i < v.size(); i++)
        {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (isdigit(v[i][j]))
            {
                res.push_back(v[i]);
                break;
            }
        }
    }
    return res;
}

int main()
{
    vector<string> colors = {"red", "green23", "1black", "white"};

    vector<string> filtered_vec = vector_str_nos(colors);
    if (filtered_vec.empty())
    {
        cout << "No strings contain numbers." << endl;
    }
    else
    {
        cout << "Strings containing numbers: ";
        for (const string& i : filtered_vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
