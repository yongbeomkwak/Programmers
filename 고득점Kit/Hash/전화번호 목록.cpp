#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phones)
{
    bool answer = true;

    unordered_map<string, int> um;

    for (const string &s : phones)
    {
        um[s] = 1; //맵에 모두 담아놓고
    }

    for (const string &s : phones)
    {
        for (int i = 1; i < s.length(); i++) //해당 문자열을 마지막 문자 전까지 부분문자열 하여 맵에 존재하는 지 탐색
        {
            if (um.find(s.substr(0, i)) != um.end())
            {
                answer = false;
                break;
            }
        }
        if (!answer)
            break;
    }

    return answer;
}