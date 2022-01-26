#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

void print(vector<int> v)
{
    for (const int &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> solution(vector<int> array, vector<vector<int> > commands)
{
    vector<int> answer;

    for (const vector<int> command : commands)
    {
        int start = command[0];
        int end = command[1];
        int k = command[2];
        vector<int> tmp;
        tmp.assign(array.begin() + (start - 1), array.begin() + (end));
        // print(tmp);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k - 1]);
    }

    return answer;
}