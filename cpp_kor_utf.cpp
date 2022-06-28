/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a = "12aA#&$ㅎ하핥벩할ㅡ";

    int i;
    cout << "한글3*6 =18 + 나머지 7 +공백1 =25"
         << " answer: " << a.size() << endl;

    vector<string> v;
    for (i = 0; i < a.size();)
    {
        if (a[i] < 0)
        {
            v.push_back(a.substr(i, 3));
            i += 3;
        }
        else
        {
            v.push_back(a.substr(i, 1));
            i += 1;
        }
    }

    for (const string &s : v)
    {
        cout << s << " ";
    }
}
