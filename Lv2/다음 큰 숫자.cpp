#include <bits/stdc++.h>

using namespace std;

int solution(int n)
{
    int answer = 0;

    const string conv = bitset<16>(n).to_string();
    const int cnt = count(conv.begin(), conv.end(), '1');

    for (int i = n + 1; i <= INT_MAX; i++)
    {
        const string tmp = bitset<16>(i).to_string();
        if (cnt == count(tmp.begin(), tmp.end(), '1'))
        {
            answer = i;
            break;
        }
    }

    return answer;
}