#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> um;

    for (const string &name : participant)
    {
        um[name]++;
    }
    for (const string &name : completion)
    {
        um[name]--;
    }

    for (auto it = um.begin(); it != um.end(); it++)
    {
        if ((*it).second != 0)
        {
            answer = (*it).first;
        }
    }

    return answer;
}